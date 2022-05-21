/*****************************************************************************
* Project: SDLFramework
* File   : Player.h
* Date   : 24.01.2020
* Author : Stephan Weber (SW)
*
* Die Player Klasse steuert das komplette Verhalten der Spielfigur.
*
* History:
*	24.01.2020	SW	Created
*					Walking Added
*	31.01.2020	SW	Jumping Added
*	03.02.2020	SW	ArrowKeys and Hammertime Added
*	13.02.2020	SW	Gravitation Using Added
*					Jumping Updated because of Gravitation
*	14.02.2020	SW	Hammertime Updated
*	17.02.2020	SW	Player is able to walk uphill
*	20.02.2020	SW	Tried to Complete the Climbing
*	02.03.2020	SW	Climbing Changed
*	25.02.2020	SW	removed all literal
*					Player dies after Jumping down
*	05.03.2020	SW	HammerColliderPosition korrigiert
******************************************************************************/
#include <iostream>
#include "Player.h"
#include "Engine.h"
#include "Defines.h"
#include <Windows.h>
#include "GamestateManager.h"
#include "GamestatePlay.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

int CPlayer::Initialize()
{
	m_iActualStage = 7;

	m_pPlayer = new CSprite();
	m_pPlayer->Initialize(m_sDefaultLR_32x32_f1, 1);
	m_pPlayer->SetPosition(M_V_PLAYER_START_POS);
	m_pPlayer->SetDefaultDelay(M_F_DEFAULT_DEFAULT_DELAY);
	CEngine::m_pDataManager->DecLifesLeft();

	CCircCollObject::Initialize(
		M_V_PLAYER_START_POS.x, M_V_PLAYER_START_POS.y, 
		m_pPlayer->GetWidth(), m_pPlayer->GetHeight());

	m_pHammerCollider = new CCircleCollider();
	m_pHammerCollider->Initialize(
		GetPositionX(), GetPositionY(), 
		M_I_HAMMER_COLLIDER_DIAMETER, M_I_HAMMER_COLLIDER_DIAMETER);

	return 0;
}

void CPlayer::Finalize()
{
	CCircCollObject::Finalize();
	FINALIZE_DELETE(m_pPlayer);
	FINALIZE_DELETE(m_pHammerCollider);
}

void CPlayer::ResetToWalkAnimation()
{
	m_vNowPosition = GetPosition();
	m_pPlayer->Finalize();
	if (m_bIsLookingRight)
	{
		m_pPlayer->Initialize(m_sDefaultLR_32x32_f1);
	}
	else
	{
		m_pPlayer->Initialize(m_sDefaultLR_32x32_f1);
	}
	SetPosition(m_vNowPosition);
}

void CPlayer::PlayDeath()
{
	if (m_bFirstFrameInDeath)
	{
		//Spritesheet initializieren
		m_vNowPosition = GetPosition();
		m_pPlayer->Finalize();
		m_pPlayer->Initialize(m_sDeathAnimation_448x32_f14, 14);
		m_pPlayer->SetPosition(m_vNowPosition);

		//Einstellungen Setzten
		m_bShouldUseGravity = false;
		m_bFirstFrameInDeath = false;
		m_pPlayer->SetDefaultDelay(M_F_DEATH_DEFAULT_DELAY);
	}

	m_fDeathTimer -= CEngine::GetDeltaTime2();

	if (m_fDeathTimer <= M_F_END_OF_TIMER)
	{
		//Pausiert das Spiel 
		CEngine::PauseGame();
		//m_pPlayer->Update() abh‰ngig von der realen Deltatime
		m_pPlayer->Update(2);
	}

	if (m_fDeathTimer <= M_F_END_OF_DEATH)
	{
		CEngine::m_pDataManager->DecLifesLeft();
		m_iLivesLeft = CEngine::m_pDataManager->GetLivesLeft();
		//Neuen gamestate Laden
		CEngine::PauseGame(false);
		if (m_iLivesLeft <= 0)
		{
			if (CEngine::m_pDataManager->isNewHighscore())
			{
				CGamestatePlay* play = dynamic_cast<CGamestatePlay*>(&CGamestateManager::GetActiveGamestate());
				play->ChangeGamestate("highscore");
				CEngine::PauseGame(false);
				return;
			}
			else
			{
				CGamestatePlay* play = dynamic_cast<CGamestatePlay*>(&CGamestateManager::GetActiveGamestate());
				play->ChangeGamestate("menu");
				CEngine::PauseGame(false);
				return;
			}
		}
		else
		{
			CGamestatePlay* play = dynamic_cast<CGamestatePlay*>(&CGamestateManager::GetActiveGamestate());
			play->ChangeGamestate("howHeigh");
			CEngine::StopMusic();
			CEngine::PauseGame(false);
			return;
		}
	}
}

void CPlayer::FallDamage()
{
	//Der Spieler soll sterben, wenn er zuweit runter f‰llt
	if (!m_bPlayerCollidesWithPlatform && !m_bFallDamagePositionIsSet)
	{
		m_fFallDamagePosition = GetPositionY();
		m_bFallDamagePositionIsSet = true;
	}

	if ((GetPositionY() > m_fFallDamagePosition + m_fDiePosition) && m_bFallDamagePositionIsSet)
	{
		m_bIsDeath = true;
		m_fFallDamagePosition = 0;
		m_bFallDamagePositionIsSet = false;
	}
}

void CPlayer::Jump()
{
	if (m_bFirstFrameInAction)
	{
		CEngine::PlaySFX(-1, SFX_JUMP);

		m_bShouldUseGravity = false;

		//Feststellen in welche Richtung gesprungen werden soll
		if (CEngine::IsKeyPressed(M_C_A_KEY) || CEngine::IsKeyPressed(VK_LEFT))
		{
			m_iJumpDirection = -M_I_DEFAULT_JUMP_DIRECTION;
		}
		else if (CEngine::IsKeyPressed(M_C_D_KEY) || CEngine::IsKeyPressed(VK_RIGHT))
		{
			m_iJumpDirection = +M_I_DEFAULT_JUMP_DIRECTION;
		}
		else
		{
			m_iJumpDirection = M_I_DEFAULT_JUMP_DIRECTION - M_I_DEFAULT_JUMP_DIRECTION;
		}

		m_bFirstFrameInAction =	false;
		m_bIsJumping =			true;
		m_bIsAbleToClimb = false;

		//aktuelle Position speichern
		//Je nach dem in welche Richtung er schaut, den Richtigen sprite laden
		//Position berichtigen
		m_vNowPosition = GetPosition();
		m_pPlayer->Finalize();
		if (m_bIsLookingRight)
		{
			m_pPlayer->Initialize(m_sJumpLR_32x32_f1);
		}
		else
		{
			m_pPlayer->Initialize(m_sJumpLL_32x32_f1);
		}
		SetPosition(m_vNowPosition);
	}

	//bewegung zur seite
	IncPositionX(m_iJumpDirection * M_F_MOVESPEED * CEngine::GetDeltaTime());

	if (m_fNowJumpHeight < M_F_MAX_JUMP_HEIGHT && !m_bPlayerGoingDown)
	{
		//bewegung nach oben
		IncPositionY(-M_F_MOVESPEED * CEngine::GetDeltaTime());
		m_fNowJumpHeight += M_F_MOVESPEED * CEngine::GetDeltaTime();
	}
	else
	{
		//bewegung nach unten
		m_bPlayerGoingDown = true;
		IncPositionY(M_F_MOVESPEED * CEngine::GetDeltaTime());
		m_fNowJumpHeight -= M_F_MOVESPEED * CEngine::GetDeltaTime();
	}

	//nach dem springen
	if (m_fNowJumpHeight <= 0)
	{
		m_bShouldUseGravity = true;
		m_bIsAbleToClimb = true;
		m_bFirstFrameInAction = true;
		m_bPlayerGoingDown = false;
		m_bIsJumping = false;

		m_bWalkDirektionHasChanged = true;

		ResetToWalkAnimation();
	}
}

void CPlayer::JumpAway()
{
	//von der Unsichtabren Wand wieder Weg springen
	m_bIsLookingRight = !m_bIsLookingRight;
	m_bPlayerGoingDown = false;
}

void CPlayer::Walk(int _direction)
{
	IncPositionX(M_F_MOVESPEED * CEngine::GetDeltaTime() * _direction);
	m_bIsWalking = true;
	m_pPlayer->Update();

	if (m_bIsWithHammer)
	{
		//Usehammer() ausf¸hren, wenn er mit dem hammer unteweges ist
		UseHammer();
		return;
	}

	if (m_bWalkDirektionHasChanged)
	{
		//um den player zu drehen
		InitializeWalkAnimation();
	}

	PlayWalkSound();
}

//Initialisiert den richtigen Spritsheet f¸rs gehen
void CPlayer::InitializeWalkAnimation()
{
	//Position speichern
	m_vNowPosition = GetPosition();
	m_pPlayer->Finalize();
	if (m_bIsLookingRight)
	{
		m_pPlayer->Initialize(m_sWalkAnimationLR_128x32_f4, 4);
	}
	else
	{
		m_pPlayer->Initialize(m_sWalkAnimationLL_128x32_f4, 4);
	}
	//position setzten
	m_pPlayer->SetPosition(m_vNowPosition);
	m_bWalkDirektionHasChanged = false;
}

void CPlayer::PlayWalkSound()
{
	//jede Sekunde wird der Ton abgespielt

	m_fStepTimer -= CEngine::GetDeltaTime();

	if (m_fStepTimer <= M_F_END_OF_TIMER)
	{
		CEngine::PlaySFX(-1, SFX_WALKING);
		m_fStepTimer = M_F_DEFAULT_STEP_TIMER;
	}
}

/*****************************************************************************/
// ab hier der Aufbau und Groﬂer Teil der Umsetztung von Marcus Schaal

//Abfragen, mit was die Spielfigur Collidiert und ein paar vorkehrungen treffen
void CPlayer::CollidesWithLadder()
{
	//jeweils die StartPosition speichern und 
	//die Endposition auf einen Wert setzten, bei welcher sie nicht stˆrt,
	//sowie 2 bools setzten

	//kleine Leiter unten
	if (m_bPlayerCollidesWithSmallLadderDown && !m_bClimbSmallLadderUp)
	{
		if (CEngine::IsKeyPressed(M_C_W_KEY) || CEngine::IsKeyPressed(VK_UP))
		{
			m_fStartPosY = GetPositionY();
			m_fEndPosY = 0;
			m_pPlayer->SetDefaultDelay(m_fDefaultClimbDelay);
			InitializeClimbAnimation(M_B_STARTED_CLIMBING_DOWN);
			m_bLadderIsLarge = false;
			m_bClimbSmallLadderUp = true;
		}
	}

	//kleine Leiter oben
	if (m_bPlayerCollidesWithSmallLadderUp && !m_bClimbSmallLadderDown)
	{
		if (CEngine::IsKeyPressed(M_C_S_KEY) || CEngine::IsKeyPressed(VK_DOWN))
		{
			m_fStartPosY = GetPositionY();
			m_fEndPosY = 10000;
			m_pPlayer->SetDefaultDelay(m_fDefaultClimbDelay);
			InitializeClimbAnimation(M_B_STARTED_CLIMBING_TOP);
			m_bLadderIsLarge = false;
			m_bClimbSmallLadderDown = true;
		}
	}

	//groﬂe Leiter unten
	if (m_bPlayerCollidesWithLargeLadderDown && !m_bClimbLargeLadderUp)
	{
		if (CEngine::IsKeyPressed(M_C_W_KEY) || CEngine::IsKeyPressed(VK_UP))
		{
			m_fStartPosY = GetPositionY();
			m_fEndPosY = 0;
			m_pPlayer->SetDefaultDelay(m_fDefaultClimbDelay);
			InitializeClimbAnimation(M_B_STARTED_CLIMBING_DOWN);
			m_bLadderIsLarge = true;
			m_bClimbLargeLadderUp = true;
		}
	}

	//groﬂe Leiter oben
	if (m_bPlayerCollidesWithLargeLadderUp && !m_bClimbLargeLadderDown)
	{
		if (CEngine::IsKeyPressed(M_C_S_KEY) || CEngine::IsKeyPressed(VK_DOWN))
		{
			m_fStartPosY = GetPositionY();
			m_fEndPosY = 10000;
			m_pPlayer->SetDefaultDelay(m_fDefaultClimbDelay);
			InitializeClimbAnimation(M_B_STARTED_CLIMBING_TOP);
			m_bLadderIsLarge = true;
			m_bClimbLargeLadderDown = true;
		}
	}
}

//kleine Leiter hoch klettern
void CPlayer::ClimbingSmallLadderUp()
{
	if (!m_bClimbSmallLadderUp) return;

	//bei erster Kollision die EndPos festlegen
	if (!m_bIsEndPosSet && m_bPlayerCollidesWithSmallLadderUp)
	{
		m_fEndPosY = GetPositionY() - M_I_END_OF_CLIMBOFFSET_UP;
		m_bIsEndPosSet = true;
	}

	//ganz am anfang
	if (GetPositionY() == m_fStartPosY)
	{
		m_climbdir = CLIMB_UP;
		m_bIsWalking = true;
		m_bShouldUseGravity = false;
		m_bIsAbleToJump = true;
		m_bIsClimbing = true;
	}
	//in der mitte
	if (GetPositionY() < m_fStartPosY)
	{
		m_climbdir = CLIMB_UP_DOWN;
		m_bIsWalking = false;
		m_bShouldUseGravity = false;
		m_bIsAbleToJump = false;
		m_bIsClimbing = true;
	}
	//nach dem klettern
	if (GetPositionY() <= m_fEndPosY)
	{
		m_climbdir = CLIMB_NONE;
		m_bClimbSmallLadderUp = false;
		m_bShouldUseGravity = true;
		m_bIsAbleToJump = true;
		m_bIsClimbing = false;
		m_bIsWalking = true;
		m_iActualStage--;

		m_fEndPosY = 0; //SW
		m_fStartPosY = 0; //SW
		m_bIsEndPosSet = false; //SW
		m_bIsStartPosSet = false; //SW
		SetActualStage(m_iActualStage);
		m_pPlayer->SetActualDelay(M_F_DEFAULT_DEFAULT_DELAY);
		m_pPlayer->SetDefaultDelay(M_F_DEFAULT_DEFAULT_DELAY);
		InitializeWalkAnimation(); //SW
	}

}

//kleine Leiter runter klettern
void CPlayer::ClimbingSmallLadderDown()
{
	if (!m_bClimbSmallLadderDown) return;

	//bei erster Kollision die EndPos festlegen
	if (!m_bIsEndPosSet && m_bPlayerCollidesWithSmallLadderDown)
	{
		m_fEndPosY = GetPositionY() + M_I_END_OF_CLIMBOFFSET_DOWN;
		m_bIsEndPosSet = true;
	}

	//ganz am anfang
	if (GetPositionY() == m_fStartPosY)
	{
		m_climbdir = CLIMB_DOWN;
		m_bIsWalking = true;
		m_bShouldUseGravity = false;
		m_bIsAbleToJump = true;
		m_bIsClimbing = true;
	}
	//in der mitte
	if (GetPositionY() > m_fStartPosY)
	{
		m_climbdir = CLIMB_UP_DOWN;
		m_bIsWalking = false;
		m_bShouldUseGravity = false;
		m_bIsAbleToJump = false;
		m_bIsClimbing = true;
	}
	//nach dem klettern
	if (GetPositionY() >= m_fEndPosY)
	{
		m_climbdir = CLIMB_NONE;
		m_bClimbSmallLadderDown = false;
		m_bShouldUseGravity = true;
		m_bIsAbleToJump = true;
		m_bIsClimbing = false;
		m_bIsWalking = true;
		m_iActualStage++;

		m_fEndPosY = 0; //SW
		m_fStartPosY = 0; //SW
		m_bIsEndPosSet = false; //SW
		m_bIsStartPosSet = false; //SW
		SetActualStage(m_iActualStage);
		m_pPlayer->SetActualDelay(M_F_DEFAULT_DEFAULT_DELAY);
		m_pPlayer->SetDefaultDelay(M_F_DEFAULT_DEFAULT_DELAY);
		InitializeWalkAnimation(); //SW
	}
}

//groﬂe leiter hoch klettern
void CPlayer::ClimbingLargeLadderUp()
{
	if (!m_bClimbLargeLadderUp) return;

	//bei erster Kollision die EndPos festlegen
	if (!m_bIsEndPosSet && m_bPlayerCollidesWithLargeLadderUp)
	{
		m_fEndPosY = GetPositionY() - M_I_END_OF_CLIMBOFFSET_UP;
		m_bIsEndPosSet = true;
	}

	//ganz am anfang
	if (GetPositionY() == m_fStartPosY)
	{
		m_climbdir = CLIMB_UP;
		m_bIsWalking = true;
		m_bShouldUseGravity = false;
		m_bIsAbleToJump = true;
		m_bIsClimbing = true;
	}
	//in der mitte
	if (GetPositionY() < m_fStartPosY)
	{
		m_climbdir = CLIMB_UP_DOWN;
		m_bIsWalking = false;
		m_bShouldUseGravity = false;
		m_bIsAbleToJump = false;
		m_bIsClimbing = true;
	}
	//nach dem klettern
	if (GetPositionY() <= m_fEndPosY)
	{
		m_climbdir = CLIMB_NONE;
		m_bClimbLargeLadderUp = false;
		m_bShouldUseGravity = true;
		m_bIsAbleToJump = true;
		m_bIsClimbing = false;
		m_bIsWalking = true;
		m_iActualStage--;

		m_fEndPosY = 0; //SW
		m_fStartPosY = 0; //SW
		m_bIsEndPosSet = false; //SW
		m_bIsStartPosSet = false; //SW
		SetActualStage(m_iActualStage);
		m_pPlayer->SetActualDelay(M_F_DEFAULT_DEFAULT_DELAY);
		m_pPlayer->SetDefaultDelay(M_F_DEFAULT_DEFAULT_DELAY);
		InitializeWalkAnimation(); //SW
	}
}

//groﬂeLeiter runter klettern
void CPlayer::ClimbingLargeLadderDown()
{
	if (!m_bClimbLargeLadderDown) return;

	//bei erster Kollision die EndPos festlegen
	if (!m_bIsEndPosSet && m_bPlayerCollidesWithLargeLadderDown)
	{
		m_fEndPosY = GetPositionY();
		m_bIsEndPosSet = true;
	}

	//ganz am anfang
	if (GetPositionY() == m_fStartPosY)
	{
		m_climbdir = CLIMB_DOWN;
		m_bIsWalking = true;
		m_bShouldUseGravity = true;
		m_bIsAbleToJump = true;
		m_bIsClimbing = false;
	}
	//in der mitte
	else if (GetPositionY() > m_fStartPosY)
	{
		m_climbdir = CLIMB_UP_DOWN;
		m_bIsWalking = false;
		m_bShouldUseGravity = false;
		m_bIsAbleToJump = false;
		m_bIsClimbing = true;
	}
	//nach dem klettern
	if (GetPositionY() >= m_fEndPosY)
	{
		m_climbdir = CLIMB_NONE;
		m_bClimbLargeLadderDown = false;
		m_bShouldUseGravity = true;
		m_bIsAbleToJump = true;
		m_bIsClimbing = false;
		m_bIsWalking = true;
		m_iActualStage++;

		m_fEndPosY = 0; //SW
		m_fStartPosY = 0; //SW
		m_bIsEndPosSet = false; //SW
		m_bIsStartPosSet = false; //SW
		SetActualStage(m_iActualStage);
		m_pPlayer->SetActualDelay(M_F_DEFAULT_DEFAULT_DELAY);
		m_pPlayer->SetDefaultDelay(M_F_DEFAULT_DEFAULT_DELAY);
		InitializeWalkAnimation(); //SW
	}
}

//Die Kletter bewegung
void CPlayer::ClimbsToDirection()
{
	if (!m_bIsClimbing) return;
	switch (m_climbdir)
	{
	case CLIMB_UP:
		if (CEngine::IsKeyPressed(M_C_W_KEY) || CEngine::IsKeyPressed(VK_UP))
		{
			IncPositionY(-M_F_CLIMB_SPEED * CEngine::GetDeltaTime());
		}
		break;
	case CLIMB_DOWN:
		if (CEngine::IsKeyPressed(M_C_S_KEY) || CEngine::IsKeyPressed(VK_DOWN))
		{
			IncPositionY(M_F_CLIMB_SPEED * CEngine::GetDeltaTime());
		}
		break;
	case CLIMB_UP_DOWN:
		if (CEngine::IsKeyPressed(M_C_W_KEY) || CEngine::IsKeyPressed(VK_UP))
		{
			IncPositionY(-M_F_CLIMB_SPEED * CEngine::GetDeltaTime());
		}
		if (CEngine::IsKeyPressed(M_C_S_KEY) || CEngine::IsKeyPressed(VK_DOWN))
		{
			IncPositionY(M_F_CLIMB_SPEED * CEngine::GetDeltaTime());
		}
		break;
	}
}

//setzt die GravityStage auf die, welche es sein soll
void CPlayer::SetActualStage(int _stage)
{
	switch (_stage)
	{
	case 1:
		m_stage = STAGE_ELEM_ONE;
		break;
	case 2:
		m_stage = STAGE_ELEM_TWO;
		break;
	case 3:
		m_stage = STAGE_ELEM_THREE;
		break;
	case 4:
		m_stage = STAGE_ELEM_FOUR;
		break;
	case 5:
		m_stage = STAGE_ELEM_FIVE;
		break;
	case 6:
		m_stage = STAGE_ELEM_SIX;
		break;
	case 7:
		m_stage = STAGE_ELEM_SEVEN;
		break;
	default:
		m_stage = STAGE_DEFAULT_ELEM;
	}
}
// bis hier der Aufbau und Groﬂer Teil der Umsetztung von Marcus Schaal
/*****************************************************************************/

//Passt den Frame vom Spritesheet den Gedr¸ckten Tasten an
void CPlayer::UpdateClimbAnimation()
{
	if (m_bIsClimbing) { m_pPlayer->SetActualDelay(M_F_DEFAULT_DEFAULT_DELAY); }
	else { return; }

	m_fClimbFrameTimer -= CEngine::GetDeltaTime();

	if (m_fClimbFrameTimer <= M_F_END_OF_TIMER)
	{
		//die Animation fortf¸hren und den timer zur¸cksetzten
		if (CEngine::IsKeyPressed(M_C_W_KEY) || CEngine::IsKeyPressed(VK_UP))
		{
			m_pPlayer->SetActualFrame(m_pPlayer->GetActualFrame() + M_I_NEXT_FRAME);
			m_fClimbFrameTimer = m_fDafaultClimbFrameTimer;
		}
		else if(CEngine::IsKeyPressed(M_C_S_KEY) || CEngine::IsKeyPressed(VK_DOWN))
		{
			m_pPlayer->SetActualFrame(m_pPlayer->GetActualFrame() + M_I_NEXT_FRAME);
			m_fClimbFrameTimer = m_fDafaultClimbFrameTimer;
		}
	}
}

void CPlayer::PlayClimbingSound()
{
	//nach einer bestimmten zeit, wird der Ton abgespielt

	if (m_bClimbSmallLadderUp || m_bClimbSmallLadderDown ||
		m_bClimbLargeLadderUp || m_bClimbLargeLadderDown)
	{
		m_fClimbSoundTimer -= CEngine::GetDeltaTime();
		if (m_fClimbSoundTimer < M_F_END_OF_TIMER)
		{
			CEngine::PlaySFX(-1, SFX_WALKING);
			m_fClimbSoundTimer = M_F_DEFAULT_CLIMB_SOUND_TIMER;
		}
	}
}

//Initialisiert den richtigen Spritesheet
void CPlayer::InitializeClimbAnimation(bool _startDown)
{
	//position speichern
	m_vNowPosition = GetPosition();
	m_pPlayer->Finalize();
	//Animation von unten
	if (_startDown)
	{
		//Spritesheet abh‰ngig von der leitergrˆﬂe Initialisieren
		m_pPlayer->Initialize(
			m_bLadderIsLarge ? 
				m_sClimbingAnimationLong_288x32_f9 : 
				m_sClimbingAnimationShort_224x32_f7, 
			m_bLadderIsLarge ? 9 : 7);

	}
	//Animation von oben
	else
	{
		//Spritesheet abh‰ngig von der leitergrˆﬂe Initialisieren
		m_pPlayer->Initialize(
			m_bLadderIsLarge ?
			m_sClimbingAnimationLongDownwards_288x32_f9 :
			m_sClimbingAnimationShortDownwards_224x32_f7,
			m_bLadderIsLarge ? 9 : 7);
	}
	//Position Setzten
	SetPosition(m_vNowPosition);
}

//wird aufgerufen, wenn die Spielfigur den Hammer in der Hand hat
void CPlayer::UseHammer()
{
	if (m_bFirstFrameInAction)
	{
		CEngine::PlayMusic(BGM_HAMMER);
		InitializeHammerAnimation();
		m_bFirstFrameInAction = false;
		m_bIsWithHammer = true;
		m_pPlayer->SetDefaultDelay(M_F_HAMMER_DEFAULT_DELAY);
	}

	SetHammerColliderOffset();

	m_fLeftTime -= (float)(CEngine::GetDeltaTime() * M_F_HALF);

	if (m_fLeftTime <= 4.0f && !m_bHammerIsFlasching)
	{
		m_bHammerIsFlasching = true;
		InitializeHammerAnimation();
	}

	if (m_bWalkDirektionHasChanged)
	{
		//um den Spieler zu drehen
		InitializeHammerAnimation();
		m_bWalkDirektionHasChanged = false;
	}

	//Wenn der Hammer weg ist
	if (m_fLeftTime <= M_F_END_OF_TIMER)
	{
		m_fLeftTime = M_F_DEFAULT_LEFT_TIME;
		m_bHammerIsFlasching = false;
		m_bFirstFrameInAction = true;
		m_bIsWithHammer = false;
		m_pPlayer->SetDefaultDelay(M_F_DEFAULT_DEFAULT_DELAY);
		CEngine::StopMusic();
		CEngine::PlayMusic(BGM_LEVEL);
		
		ResetToWalkAnimation();

		//SAFE_DELETE(m_pHammerCollider);
	}
}

void CPlayer::InitializeHammerAnimation()
{
	//Position Speichern
	m_vNowPosition = GetPosition();
	m_fNowDelay = m_pPlayer->GetActualDelay();
	m_iActualFrameInSpritesheet = m_pPlayer->GetActualFrame();
	m_pPlayer->Finalize();
	if (m_bHammerIsFlasching)
	{
		//den Goldenen Hammer initilisieren
		if (m_bIsLookingRight)
		{
			m_pPlayer->Initialize(m_sHammerRedGoldLR_384x52_f6, 6);
		}
		else
		{
			m_pPlayer->Initialize(m_sHammerRedGoldLL_384x52_f6, 6);
		}
	}
	else 
	{
		//den Roten Hammer initilisieren
		if (m_bIsLookingRight)
		{
			m_pPlayer->Initialize(m_sHammerRedLR_384x52_f6,6);
		}
		else
		{
			m_pPlayer->Initialize(m_sHammerRedLL_384x52_f6, 6);
		}
	}
	//Position Setzten
	m_pPlayer->SetActualFrame(m_iActualFrameInSpritesheet);
	m_pPlayer->SetActualDelay(m_fNowDelay);
	SetPosition(m_vNowPosition);
}

void CPlayer::SetGravityColliderWhileHammertime()
{
	//Den Player ColliderOffset setzten
	if (m_bIsLookingRight) { m_vColliderOffsetForGravity.x = -16; }
	else { m_vColliderOffsetForGravity.x = 16; }
}

void CPlayer::SetHammerColliderOffset()
{
	//den Offset vom HammerCollider Setzten
	m_iActualFrameInSpritesheet = m_pPlayer->GetActualFrame();
	if (m_iActualFrameInSpritesheet == 1 || 
		m_iActualFrameInSpritesheet == 3 || 
		m_iActualFrameInSpritesheet == 5)
	{
		if (m_bIsLookingRight) { m_vHammerColliderOffset = { -8,-16 }; }
		else { m_vHammerColliderOffset = { 8,-16 }; }
	}
	else if (m_iActualFrameInSpritesheet == 2 || 
			 m_iActualFrameInSpritesheet == 4 || 
			 m_iActualFrameInSpritesheet == 6)
	{
		if (m_bIsLookingRight) { m_vHammerColliderOffset = { 16,-16 }; }
		else { m_vHammerColliderOffset = { -16,-16 }; }
	}
}

/*****************************************************************************/
/**********************************Update*************************************/
/*****************************************************************************/

int CPlayer::Update()
{
	if (m_bPlayerHasWon) { m_pPlayer->SetActualFrame(0); return 0; }

	if (m_bPlayerCollidesWithEnemy) { m_bIsDeath = true; }

	if (m_bIsDeath) { PlayDeath(); return I_SUCCESS; }

	if (m_bPlayCollidesWithBorder) { JumpAway(); }

	/*
		Wen die Spielfigur den hammer in der Hand h‰lt, 
		dann soll der HammerColliderauf den hammer geschiben werden, 
		ansonsten soll der Mittelpunkt auf 0,0 sein
	*/
	if (m_bIsWithHammer)
	{
		m_pHammerCollider->Update(
			GetPositionX() + m_vHammerColliderOffset.x, GetPositionY() + m_vHammerColliderOffset.y,
			M_I_HAMMER_COLLIDER_DIAMETER, M_I_HAMMER_COLLIDER_DIAMETER);
	}
	else
	{
		m_pHammerCollider->Update(m_vZeroPoint.x, m_vZeroPoint.y, M_I_HAMMER_COLLIDER_DIAMETER, M_I_HAMMER_COLLIDER_DIAMETER);
	}

	CCircCollObject::Update();
	m_pPlayer->SetPosition(GetPosition()); //MS
	SetSize(m_pPlayer->GetWidth(), m_pPlayer->GetHeight());
	CCircCollObject::SetCenter((int)m_vColliderOffsetForGravity.x, (int)m_vColliderOffsetForGravity.y);
	CCircCollObject::SetRadius(16);


	//klettern

	if (m_bIsAbleToClimb)
	{
		CollidesWithLadder();		//MS
		ClimbingSmallLadderUp();	//MS
		ClimbingSmallLadderDown();	//SW
		ClimbingLargeLadderUp();	//SW
		ClimbingLargeLadderDown();	//SW
		ClimbsToDirection();		//MS
		UpdateClimbAnimation();		//SW
		PlayClimbingSound();		//SW
	}
	//klettern ende


	if (m_bPlayerCollidesWithEnemy) { m_bIsDeath = true; }

	if (m_bPlayerCollidesWithPlattform) { m_bIsAbleToJump = false; }

	FallDamage();

	if (m_bPlayerCollidesWithHammer) { m_bIsWithHammer = true; }

	//springen
	if (CEngine::IsKeyPressed(M_C_SPACE_KEY)	&&
		!m_bIsClimbing				&&
		!m_bIsJumping				&&
		!m_bIsWithHammer			)
	{
		m_pPlayer->Update();
		Jump();
	}
	else
	{
		if (m_bIsJumping) Jump();
	}

	//nach links gehen
	if ((CEngine::IsKeyPressed(M_C_A_KEY)||CEngine::IsKeyPressed(VK_LEFT)) &&
		!m_bIsJumping &&
		!m_bIsClimbing )
	{
		if (m_bIsLookingRight)
		{
			m_bWalkDirektionHasChanged = true;
		}
		m_bIsLookingRight = false;

		Walk(M_I_WALKING_LEFT);
	}
	else
	{
		if (m_bIsWithHammer) Walk();
	}

	//nach rechts gehen
	if (!CEngine::IsKeyPressed(M_C_A_KEY) || !CEngine::IsKeyPressed(VK_LEFT))
	{
		if ((CEngine::IsKeyPressed(M_C_D_KEY)||CEngine::IsKeyPressed(VK_RIGHT))&&
			!m_bIsJumping &&
			!m_bIsClimbing )
		{
			if (!m_bIsLookingRight)
			{
				m_bWalkDirektionHasChanged = true;
			}
			m_bIsLookingRight = true;

			Walk(M_I_WALKING_RIGHT);
		}
		else
		{
			if (m_bIsWithHammer) Walk();
		}
	}

	return I_SUCCESS;
}

void CPlayer::Render()
{
	m_pPlayer->Render();
}
