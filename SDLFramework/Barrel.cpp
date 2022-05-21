/*****************************************************************************
* Project: SDLFramework
* File   : Barrel.cpp
* Date   : 10.02.2020
* Author : Sandro Mock (SM)
*
* In dieser Klasse werden die Faesser behandelt. Sie werden bewegt, fallen nach
* unten und übernehmen dadurch die Gravitation der Stage, rollen durch einen
* Randomgenerator gelegentlich die Leitern herunter und haben einen Collider
* um den Spieler zu töten.
*
* History:
*	10.02.20	SM	Created
*	12.02.20	SM	+SetActive Methode
*	14.02.20	SM	+Oil & BurningOil
*	18.02.20	SM	+CCircelCollider & CBoxCollider
*	01.03.20	SM	+OnPlayerDeath, SetIsWinActive, GetIsWinActive,
*					SetDestroyOnHit, SetIsPlayerDead, SetPlayerJumpOverBarrel
*					Methoden
*	01.03.20	SM	+ScoreCollider
*	05.03.20	SM	+Score erhoehung beim springen ueber ein Fass
*	06.03.20	SM	+Score wird angezeit beim springen ueber ein Fass
******************************************************************************/
#include "Barrel.h"
#include "Engine.h"
#include"GamestatePlay.h"


void CBarrel::SetActive(bool _active, CFlame* _flame[5], bool _deleteBarrels)
{
	switch (m_iImage)
	{
	//Erstes Blaues Fass
	case 0:
		m_pFirstBarrel->SetActive(_active);
		if (_active)
		{
			//Runter fallen des ersten Blauen Fasses
			if (GetPositionY() <= M_I_GET_Y_POS)
			{
				m_pFirstBarrel->Finalize();
				IncPositionY(m_iBarrelSpeed * CEngine::GetDeltaTime());
				m_vActualPos = GetPosition(); 
				m_fBarrelDelay = m_pFirstBarrel->GetActualDelay();
				m_iActualBarrelFrame = m_pFirstBarrel->GetActualFrame();
				m_pFirstBarrel->Initialize(M_S_BLUE_BARREL_DOWN, 2);
				m_pFirstBarrel->SetActualFrame(m_iActualBarrelFrame);
				m_pFirstBarrel->SetActualDelay(m_fBarrelDelay);
				m_pFirstBarrel->SetPosition(m_vActualPos);
				//Bumpen auf den verschiedenen Stages
				if (((GetPositionY() >= M_V_FIRST_STAGE.x &&
					GetPositionY() <= M_V_FIRST_STAGE.y) ||
					(GetPositionY() >= M_V_SECOND_STAGE.x &&
						GetPositionY() <= M_V_SECOND_STAGE.y) ||
					(GetPositionY() >= M_V_THIRD_STAGE.x &&
						GetPositionY() <= M_V_THIRD_STAGE.y) ||
					(GetPositionY() >= M_V_FOURTH_STAGE.x &&
						GetPositionY() <= M_V_FOURTH_STAGE.y) ||
					GetPositionY() >= M_I_LAST_Y_POS) &&
					m_fBumpTimer > 0)
				{
					IncPositionY(-m_iBarrelSpeed * CEngine::GetDeltaTime());
					m_fBumpTimer -= CEngine::GetDeltaTime();
				}
				else
				{
					m_fBumpTimer = M_F_DEFAULT_TIMER;
				}
			}
			//Rollen ins Oelfass
			if (GetPositionY() >= M_I_GET_Y_POS)
			{
				m_pFirstBarrel->Finalize();
				IncPositionX(-m_iBarrelSpeed * CEngine::GetDeltaTime());
				m_vActualPos = GetPosition();
				m_fBarrelDelay = m_pFirstBarrel->GetActualDelay();
				m_iActualBarrelFrame = m_pFirstBarrel->GetActualFrame();
				m_pFirstBarrel->Initialize(M_S_ROLL_BLUE_BARREL, 4);
				m_pFirstBarrel->SetActualFrame(m_iActualBarrelFrame);
				m_pFirstBarrel->SetActualDelay(m_fBarrelDelay);
				m_pFirstBarrel->SetPosition(m_vActualPos);
			}

			if (GetPositionX() <= M_F_OIL_POS_X)
			{
				m_pFirstBarrel->Finalize();
				m_pOil->Finalize();
				m_pBurningOil->SetActive(true);
				_flame[0]->SetActive(true, _deleteBarrels);
			}
		}
		break;
	//Braunes Fass
	//Bewegung und Gravitation und Score fuer Braunes Fass
	case 1:
		m_pBrownBarrel->SetActive(_active);
		if (m_bShouldMove && _active)
		{
			if (m_bIsDestroyed)
			{
				m_bFinalizeBrownBarrel = true;
			}
			//Finalize aller Braunen Faesser wenn der Spieler stirbt
			//oder gewinnt
			if (_deleteBarrels)
			{
				m_pBrownBarrel->Finalize();
				return;
			}
			//Punkte bekommen wenn man ueber ein Fass springt
			if (m_bPlayerJumpOverBarrel && !m_bAddScore)
			{
				m_bTextIsVisible = true;
				m_pGetScore->SetPosition(m_pBrownBarrel->GetPositionX(),
					m_pBrownBarrel->GetPositionY());
				m_pGetScore->SetText(to_string(M_I_JUMP_OVER_SCORE));
				CEngine::m_pDataManager->IncScore(M_I_JUMP_OVER_SCORE);
				m_bAddScore = true;
				CGamestatePlay* a;
				a = dynamic_cast<CGamestatePlay*>(
					&CGamestateManager::GetActiveGamestate());
				a->GetUIPanel()->SetScore(CEngine::m_pDataManager->GetScore());
			}
			else if(!m_bPlayerJumpOverBarrel)
			{
				m_bAddScore = false;
			}

			//Fass mit Hammer zerstoeren und Punkte bekommen
			if (m_bIsDestroyed || m_bFinalizeBrownBarrel)
			{
				if (m_bIsDestroyed && !m_bAddScore)
				{
					m_bTextIsVisible = true;
					m_pGetScore->SetPosition(m_pBrownBarrel->GetPositionX(),
						m_pBrownBarrel->GetPositionY());
					m_pGetScore->SetText(to_string(M_I_BROWN_HAMMER_SCORE));
					CEngine::m_pDataManager->IncScore(M_I_BROWN_HAMMER_SCORE);
					CGamestatePlay* a;
					a = dynamic_cast<CGamestatePlay*>(
						&CGamestateManager::GetActiveGamestate());
					a->GetUIPanel()->SetScore(CEngine::m_pDataManager->GetScore());
					m_bAddScore = true;
				}
				else if (!m_bIsDestroyed)
				{
					m_bAddScore = false;
				}
				m_fHammerTimer -= CEngine::GetDeltaTime2();
				if (m_fHammerTimer > 0)
				{
					m_bFinalizeBrownBarrel = true;
					CEngine::PauseGame();
				}
				else
				{
					m_pBrownBarrel->Finalize();
					CEngine::PauseGame(false);
				}
			}
			if (m_bFinalizeBrownBarrel)
			{
				SetPosition(-100.0f, -100.0f);
				SetWidth(0);
				SetHeight(0);
				break;
			}

			//Bewegung auf den Stages
			if (m_stage == STAGE_TWO || m_stage == STAGE_FOUR ||
				m_stage == STAGE_SIX)
			{
				m_pBrownBarrel->Finalize();
				m_vActualPos = GetPosition();
				m_fBarrelDelay = m_pBrownBarrel->GetActualDelay();
				m_iActualBarrelFrame = m_pBrownBarrel->GetActualFrame();
				m_pBrownBarrel->Initialize(M_S_ROLL_BROWN_BARREL, 4);
				m_pBrownBarrel->SetActualFrame(m_iActualBarrelFrame);
				m_pBrownBarrel->SetActualDelay(m_fBarrelDelay);
				m_pBrownBarrel->SetPosition(m_vActualPos);
				m_iBarrelSpeed = M_I_BARREL_RIGHT;
			}
			else
			{
				m_pBrownBarrel->Finalize();
				m_vActualPos = GetPosition();
				m_fBarrelDelay = m_pBrownBarrel->GetActualDelay();
				m_iActualBarrelFrame = m_pBrownBarrel->GetActualFrame();
				m_pBrownBarrel->Initialize(M_S_ROLL_BROWN_BARREL, 4);
				m_pBrownBarrel->SetActualFrame(m_iActualBarrelFrame);
				m_pBrownBarrel->SetActualDelay(m_fBarrelDelay);
				m_pBrownBarrel->SetPosition(m_vActualPos);
				m_iBarrelSpeed = M_I_BARREL_LEFT;
			}

			IncPositionX(
				m_iBarrelSpeed * CEngine::GetDeltaTime());
			//Randomgenerator
			if (m_bHitLadder  && m_iUseLadder == 0 && m_bChangeLadder)
			{
				m_iUseLadder = std::rand() % M_I_RANDOM_RANGE + 1;
				cout << m_iUseLadder << endl;
				if (m_iUseLadder > M_I_RANDOM && m_iUseLadder > 0){ChangeStage();}
			}
			if (m_iUseLadder > M_I_RANDOM && m_iUseLadder > 0)
			{
				m_pBrownBarrel->Finalize();
				IncPositionX(
					-m_iBarrelSpeed * CEngine::GetDeltaTime());
				m_vActualPos = GetPosition();
				m_fBarrelDelay = m_pBrownBarrel->GetActualDelay();
				m_iActualBarrelFrame = m_pBrownBarrel->GetActualFrame();
				m_pBrownBarrel->Initialize(M_S_BROWN_BARREL_DOWN, 2);
				m_pBrownBarrel->SetActualFrame(m_iActualBarrelFrame);
				m_pBrownBarrel->SetActualDelay(m_fBarrelDelay);
				m_pBrownBarrel->SetPosition(m_vActualPos);
			}
			//Richtungswechsel
			if (GetPositionX() >= M_F_MAX_POS_X)
			{
				ChangeStage();
				m_iBarrelSpeed *= M_I_DIRECTION_CHANGE;
				IncPositionX(m_iBarrelSpeed * CEngine::GetDeltaTime());
			}
			else if (GetPositionX() <= M_F_MIN_POS_X)
			{
				ChangeStage();
				m_iBarrelSpeed *= M_I_DIRECTION_CHANGE;
				IncPositionX(m_iBarrelSpeed * CEngine::GetDeltaTime());
			}
		}
		
		if (GetPositionX() <= M_F_OIL_POS_X &&
			GetPositionY() >= M_F_OIL_POS_Y)
		{
			m_pBrownBarrel->Finalize();
		}
		
		break;
	//Blaues Fass
	//Bewegung und Gravitation und Score fuer Blaues Fass
	case 2:
		m_pBlueBarrel->SetActive(_active);
		if (m_bShouldMove && _active)
		{
			//Finalize aller Blauen Faesser wenn der Spieler stirbt
			//oder gewinnt
			if (_deleteBarrels)
			{
				m_pBlueBarrel->Finalize();
				return;
			}
			//Punkte bekommen wenn man ueber ein Fass springt
			if (m_bPlayerJumpOverBarrel && !m_bAddScore)
			{
				m_bTextIsVisible = true;
				m_pGetScore->SetPosition(m_pBlueBarrel->GetPositionX(),
					m_pBlueBarrel->GetPositionY());
				CEngine::m_pDataManager->IncScore(M_I_JUMP_OVER_SCORE);
				m_bAddScore = true;
				CGamestatePlay* a;
				a = dynamic_cast<CGamestatePlay*>(
					&CGamestateManager::GetActiveGamestate());
				a->GetUIPanel()->SetScore(CEngine::m_pDataManager->GetScore());
			}
			else if (!m_bPlayerJumpOverBarrel)
			{
				m_bAddScore = false;
			}

			//Fass mit Hammer zerstoeren und Punkte bekommen
			if (m_bIsDestroyed || m_bFinalizeBlueBarrel)
			{
				m_fHammerTimer -= CEngine::GetDeltaTime2();
				if (m_fHammerTimer > 0)
				{
					CEngine::PauseGame();
					cout << "   //////////////" << endl;
					m_bFinalizeBlueBarrel = true;
				}
				else
				{
					m_pBlueBarrel->Finalize();
					CEngine::PauseGame(false);
					cout << "////////////////" << endl;
				}
				if (m_bIsDestroyed && !m_bAddScore)
				{
					if (m_bFinalizeBlueBarrel)
					{
						break;
					}
					m_bTextIsVisible = true;
					m_pGetScore->SetPosition(m_pBlueBarrel->GetPositionX(),
						m_pBlueBarrel->GetPositionY());
					m_pGetScore->SetText(to_string(M_I_BLUE_HAMMER_SCORE));
					CEngine::m_pDataManager->IncScore(M_I_BLUE_HAMMER_SCORE);
					m_bAddScore = true;
					CGamestatePlay* a;
					a = dynamic_cast<CGamestatePlay*>(
						&CGamestateManager::GetActiveGamestate());
					a->GetUIPanel()->SetScore(CEngine::m_pDataManager->GetScore());
				}
				else if (!m_bIsDestroyed)
				{
					m_bAddScore = false;
				}
			}
			if (m_bFinalizeBlueBarrel)
			{
				SetPosition(0.0f, 0.0f);
				SetWidth(0);
				SetHeight(0);
				break;
			}

			//Bewegung auf den Stages
			if (m_stage == STAGE_TWO || m_stage == STAGE_FOUR ||
				m_stage == STAGE_SIX)
			{
				m_pBlueBarrel->Finalize();
				m_vActualPos = GetPosition();
				m_fBarrelDelay = m_pBlueBarrel->GetActualDelay();
				m_iActualBarrelFrame = m_pBlueBarrel->GetActualFrame();
				m_pBlueBarrel->Initialize(M_S_ROLL_BLUE_BARREL, 4);
				m_pBlueBarrel->SetActualFrame(m_iActualBarrelFrame);
				m_pBlueBarrel->SetActualDelay(m_fBarrelDelay);
				m_pBlueBarrel->SetPosition(m_vActualPos);
				m_iBarrelSpeed = M_I_BARREL_RIGHT;
			}
			else
			{
				m_pBlueBarrel->Finalize();
				m_vActualPos = GetPosition();
				m_fBarrelDelay = m_pBlueBarrel->GetActualDelay();
				m_iActualBarrelFrame = m_pBlueBarrel->GetActualFrame();
				m_pBlueBarrel->Initialize(M_S_ROLL_BLUE_BARREL, 4);
				m_pBlueBarrel->SetActualFrame(m_iActualBarrelFrame);
				m_pBlueBarrel->SetActualDelay(m_fBarrelDelay);
				m_pBlueBarrel->SetPosition(m_vActualPos); 
				m_iBarrelSpeed = M_I_BARREL_LEFT;
			}

			IncPositionX(m_iBarrelSpeed * CEngine::GetDeltaTime());
			//Randomgenerator
			if (m_bHitLadder && m_iUseLadder == 0 && m_bChangeLadder)
			{
				m_iUseLadder = std::rand() % M_I_RANDOM_RANGE + 1;
				if (m_iUseLadder > M_I_RANDOM && m_iUseLadder > 0){ ChangeStage();}
			}
			if (m_iUseLadder > M_I_RANDOM)
			{
				m_pBlueBarrel->Finalize();
				IncPositionX(
					-m_iBarrelSpeed * CEngine::GetDeltaTime());
				m_vActualPos = GetPosition();
				m_fBarrelDelay = m_pBlueBarrel->GetActualDelay();
				m_iActualBarrelFrame = m_pBlueBarrel->GetActualFrame();
				m_pBlueBarrel->Initialize(M_S_BLUE_BARREL_DOWN, 2);
				m_pBlueBarrel->SetActualFrame(m_iActualBarrelFrame);
				m_pBlueBarrel->SetActualDelay(m_fBarrelDelay);
				m_pBlueBarrel->SetPosition(m_vActualPos);
			}

			//Richtungswechsel
			if (GetPositionX() >= M_F_MAX_POS_X)
			{
				ChangeStage();
				m_iBarrelSpeed *= M_I_DIRECTION_CHANGE;
				IncPositionX(m_iBarrelSpeed * CEngine::GetDeltaTime());
			}
			else if (GetPositionX() <= M_F_MIN_POS_X)
			{
				ChangeStage();
				m_iBarrelSpeed *= M_I_DIRECTION_CHANGE;
				IncPositionX(m_iBarrelSpeed * CEngine::GetDeltaTime());
			}
		}
		if (GetPositionX() <= M_F_OIL_POS_X &&
			GetPositionY() >= M_F_OIL_POS_Y)
		{
			m_pBlueBarrel->Finalize();
		}
		break;
	}
}
//Stage wechsel fuer alle Faesser                                                                              
void CBarrel::ChangeStage()
{
	switch (m_stage)
	{
	case STAGE_SIX:
		m_stage = STAGE_SEVEN;
		break;

	case STAGE_FIVE:
		m_stage = STAGE_SIX;
		break;

	case STAGE_FOUR:
		m_stage = STAGE_FIVE;
		break;

	case STAGE_THREE:
		m_stage = STAGE_FOUR;
		break;

	case STAGE_TWO:
		m_stage = STAGE_THREE;
		break;
	}
}

int CBarrel::Initialize(int _image, float _x, float _y)
{
	m_pGetScore = new Text();
	m_pGetScore->Initialize(DEFAULT_FONT, DEFAULT_FONT_RESOLUTION, 15);


	CCircCollObject::Initialize(_x, _y, M_I_WIDTH, M_I_HEIGHT);
	m_pOil = new CSprite();
	m_pOil->Initialize(M_S_OIL);
	m_pOil->SetPosition(M_F_OIL_POS_X, M_F_OIL_POS_Y);
	m_pOil->SetActive(true);

	m_pBurningOil = new CSprite();
	m_pBurningOil->Initialize(M_S_BURNING_OIL, 2);
	m_pBurningOil->SetPosition(M_F_OIL_POS_X, M_F_OIL_POS_Y);
	m_pBurningOil->SetActive(false);

	switch (_image)
	{
	case 0:
		m_pFirstBarrel = new CSprite();
		m_pFirstBarrel->SetDefaultDelay(M_F_FIRST_BARREL_DELAY);
		m_pFirstBarrel->Initialize(M_S_BLUE_BARREL_DOWN, 2);
		m_pFirstBarrel->SetPosition(GetPositionX(), GetPositionY());
		m_pBColl = new CBoxCollider();
		m_pBColl->Initialize(
			GetPositionX(), GetPositionY(), GetWidth(), GetHeight());
		break;
	case 1:
		m_pBrownBarrel = new CSprite();
		m_pBrownBarrel->SetDefaultDelay(M_F_ROLL_BARREL_DELAY);
		m_pBrownBarrel->Initialize(M_S_ROLL_BROWN_BARREL, 4);
		m_pBrownBarrel->SetPosition(GetPositionX(), GetPositionY());
		m_pScoreColl = new CBoxCollider();
		m_pScoreColl->Initialize(
			GetPositionX(), GetPositionY(), M_I_SCORE_WIDTH, M_I_SCORE_HEIGHT);
		break;
	case 2:
		m_pBlueBarrel = new CSprite();
		m_pBlueBarrel->SetDefaultDelay(M_F_ROLL_BARREL_DELAY);
		m_pBlueBarrel->Initialize(M_S_ROLL_BLUE_BARREL, 4);
		m_pBlueBarrel->SetPosition(GetPositionX(), GetPositionY());
		m_pScoreColl = new CBoxCollider();
		m_pScoreColl->Initialize(
			GetPositionX(), GetPositionY(), GetWidth(), M_I_SCORE_HEIGHT);
		break;
	}
	m_iImage = _image;

	return 0;
}

void CBarrel::Finalize()
{
	FINALIZE_DELETE(m_pBurningOil);
	FINALIZE_DELETE(m_pOil);
	switch (m_iImage)
	{
	case 0:
		SAFE_DELETE(m_pBColl);
		FINALIZE_DELETE(m_pFirstBarrel);
		break;
	case 1:
		SAFE_DELETE(m_pScoreColl);
		FINALIZE_DELETE(m_pBrownBarrel);
		break;
	case 2:
		SAFE_DELETE(m_pScoreColl);
		FINALIZE_DELETE(m_pBlueBarrel);
		break;
	}
	CCircCollObject::Finalize();
}

int CBarrel::Update()
{
	if (m_bTextIsVisible)
	{
		m_fTextTimer -= CEngine::GetDeltaTime();
		if (m_fTextTimer <= 0)
		{
			m_bTextIsVisible = false;
		}
	}
	if (m_bFinalizeBrownBarrel)
	{
		m_pBrownBarrel->Finalize();
	}
	if (m_bIsPlayerDead)
	{
		m_fDieAnimationTimer -= CEngine::GetDeltaTime2();
		if (m_fDieAnimationTimer >= 0)
		{
			CEngine::PauseGame();
		}
	}

	m_pBurningOil->Update();

	// Random Leitern klettern
	if (m_bHitLadder && m_iUseLadder == 0)
	{
		m_bChangeLadder = true;
	}
	else if (m_bHitLadder && m_iUseLadder != 0)
	{
		m_bChangeLadder = false;
	}
	else
	{
		m_bChangeLadder = false;
		m_iUseLadder = 0;
	}

	CCircCollObject::Update();
	switch (m_iImage)
	{
	case 0:
		m_pFirstBarrel->SetPosition(GetPositionX(), GetPositionY());
		m_pFirstBarrel->Update();
		m_pBColl->Update(m_pFirstBarrel->GetPositionX(),
			m_pFirstBarrel->GetPositionY(), M_I_WIDTH, M_I_HEIGHT);
		break;
	case 1:
		m_pBrownBarrel->SetPosition(GetPositionX(), GetPositionY());
		m_pBrownBarrel->Update();
		m_pScoreColl->Update(GetPositionX(),
			GetPositionY() - 24, GetWidth(), M_I_SCORE_HEIGHT);
		break;
	case 2:
		m_pBlueBarrel->SetPosition(GetPositionX(), GetPositionY());
		m_pBlueBarrel->Update();
		m_pScoreColl->Update(GetPositionX(),
			GetPositionY(), GetWidth(), M_I_SCORE_HEIGHT);
		break;
	}

	return 0;
}

void CBarrel::Render()
{
	if (m_bTextIsVisible)
	{
		m_pGetScore->Render();
	}
	m_pOil->Render();
	m_pBurningOil->Render();
	switch (m_iImage)
	{
	case 0:
		m_pFirstBarrel->Render();
		break;
	case 1:
		m_pBrownBarrel->Render();
		break;
	case 2:
		m_pBlueBarrel->Render();
		break;
	}
}
