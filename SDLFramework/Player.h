/*****************************************************************************
* Project: SDLFramework
* File   : Player.h
* Date   : 24.01.2020
* Author : Stephan Weber (SW)
*		   Marcus Schaal (MS)
*
* Die Player Klasse steuert das komplette Verhalten der Spielfigur.
*
* History:
*	23.01.2020	SW	Created
*	18.02.2020	SW	Collider Getter eingefügt
*				SW	Collider Setter eingefügt
*	27.02.2020	MS	Klettern angefangen
*	28.02.2020	SW	Klettern Fortgeführt und das angefangene Verändert
*	02.03.2020	SW	Klettern verändert
******************************************************************************/
#pragma once
#include <string>
#include "Sprite.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include <array>
#include "CircCollObject.h"
#include "LevelConfig.h"

using namespace std;

enum M_F_CLIMB_SPEED { CLIMB_NONE, CLIMB_UP, CLIMB_DOWN, CLIMB_UP_DOWN };

class CPlayer :
	public CCircCollObject
{
public:
	CPlayer();
	~CPlayer();

	int Initialize();
	void Finalize();
	int Update();
	void Render();

	void ActivateHammerTime() { m_bIsWithHammer = true; }

	bool GetIsDeath() { return m_bIsDeath; }

	//Collider Getter und Setter

	//Wichtig für Marcus

	//return true wenn er nach rechts schaut (Zuverlässig)
	bool GetLookDiretion() { return m_bIsLookingRight; } 

	void SetPlayerCollidesWithBorder(bool _bool) { m_bPlayCollidesWithBorder = _bool; }

	bool GetShouldUseGravity() { return m_bShouldUseGravity; }

	CCircleCollider& GetHammerCollider() { return *m_pHammerCollider; }

	void SetPlayerCollidesWithPlatform(bool _bool)
	{
		m_bPlayerCollidesWithPlatform = _bool;
	}

	float GetDeathTimer() { return m_fDeathTimer; }

	void SetPlayerCollidesWithLargeLadder(bool _bool)
	{
		m_bPlayerCollidesWithLargeLadderDown = _bool;
	}

	void SetPlayerCollidesWithSmallLadder(bool _bool)
	{
		m_bPlayerCollidesWithSmallLadderDown = _bool;
	}

	void SetPlayerCollidesWithBarrel(bool _bool)
	{
		m_bPlayerCollidesWithEnemy = _bool;
	}

	void SetPlayerCollidesWithHammer(bool _bool)
	{
		m_bPlayerCollidesWithHammer = _bool;
	}

	void HammerCollidesWithBarrel(bool _bool)
	{
		m_bHammerCollidesWithBarrel = _bool;
	}

	void SetPlayerLadderPlatformLarge(bool _bool)
	{
		m_bPlayerCollidesWithLargeLadderUp = _bool;
	}

	void SetPlayerLadderPlatformSmall(bool _bool)
	{
		m_bPlayerCollidesWithSmallLadderUp = _bool;
	}

	void SetPlayerCollidesWithPlattform(bool _bool)
	{
		m_bPlayerCollidesWithPlattform = _bool;
	}

	STAGE GetStage() { return m_stage; }

	float GetPlayerFallSpeed() { return M_F_GRAVITATION_SPEED; }

	void SetPlayerHasWon(bool _bool) { m_bPlayerHasWon = _bool; }

	void SetGameIsPaused(bool _bool) { m_bGameIsPaused = _bool; }
	//Wichtig Für Marcus Ende

private:

	//Non Sortet
	void ResetToWalkAnimation();
	void FallDamage();
	int m_iUniversalCounter = 0;
	float m_fActualDelay = 0.0f;
	float m_fClimbFrameTimer = 0.0f;
	float m_fDafaultClimbFrameTimer = 0.1725f;
	const float M_F_HALF = 0.5f;
	bool m_bWalkDirektionHasChanged = true;
	bool m_bFirstFrameInAction = true;
	bool m_bPlayerHasWon = false;
	bool m_bGameIsPaused = false;
	bool m_bPlayCollidesWithBorder = false;
	Vector m_vZeroPoint{ 0,0 };
	Vector m_vEndPos{ 0,0 };

	//FallDamage
	bool m_bFallDamagePositionIsSet = false;
	float m_fDiePosition = 45;
	float m_fFallDamagePosition = 0;


	//Delays
	float m_fNowDelay = 0.0f;
	const float M_F_DEFAULT_DEFAULT_DELAY = 0.15f;
	float m_fDefaultClimbDelay = 100.0f;

	//Positionen
	const Vector M_V_PLAYER_START_POS{ 350, 608 };
	Vector m_vNowPosition = { -1,-1 };

	//Colisions
	bool m_bPlayerCollidesWithPlattform = true;
	bool m_bPlayerCollidesWithEnemy = false;

	//Death
	void PlayDeath();
	float m_fDeathTimer = 1.0f;
	const float M_F_DEATH_DEFAULT_DELAY = 0.214f;
	const float M_F_END_OF_DEATH = -3.0f;
	bool m_bIsDeath = false;
	bool m_bFirstFrameInDeath = true;

	//Gravity
	const float M_F_GRAVITATION_SPEED = 150.0f;
	bool m_bShouldUseGravity = true;
	bool m_bPlayerCollidesWithPlatform = true;

	//Stages
	STAGE m_stage = STAGE_ELEM_SEVEN;

	//Walking
	void Walk(int _direction = 0);
	void InitializeWalkAnimation();
	void PlayWalkSound();
	float m_fStepTimer = -1.0f;
	const int M_I_WALKING_LEFT = -1;
	const int M_I_WALKING_RIGHT = 1;
	const float M_F_DEFAULT_STEP_TIMER = 0.225f;
	const float M_F_MOVESPEED = 90.0f;
	bool m_bIsWalking = false;
	bool m_bIsLookingRight = true;
	bool m_bStepsoundIsPlaying = false;

	//Climbing
	void CollidesWithLadder(); //MS
	void ClimbsToDirection(); //MS
	void ClimbingSmallLadderUp(); //MS
	void ClimbingSmallLadderDown(); 
	void ClimbingLargeLadderUp(); 
	void ClimbingLargeLadderDown(); 
	void SetActualStage(int _stage); //MS
	void UpdateClimbAnimation();
	void PlayClimbingSound();
	void InitializeClimbAnimation(bool _startDown);

	const int M_I_END_OF_CLIMBOFFSET_UP = 48;
	const int M_I_END_OF_CLIMBOFFSET_DOWN = 3;
	const int M_I_NEXT_FRAME = 1;
	const int M_I_LAST_FRAME = -1;

	float m_fClimbSoundTimer = 0.4f;
	const float M_F_DEFAULT_CLIMB_SOUND_TIMER = 0.4f;

	bool m_bClimbSmallLadderUp = false; //MS
	bool m_bClimbSmallLadderDown = false;
	bool m_bClimbLargeLadderUp = false;
	bool m_bClimbLargeLadderDown = false;
	const bool M_B_STARTED_CLIMBING_DOWN = true;
	const bool M_B_STARTED_CLIMBING_TOP = false;
	bool m_bLadderIsLarge = false;

	float m_fStartPosY = -1; //MS
	float m_fEndPosY = -1; //MS
	bool m_bIsStartPosSet = false; //MS
	bool m_bIsEndPosSet = false; //MS
	M_F_CLIMB_SPEED m_climbdir = CLIMB_NONE; //MS

	int m_iActualStage = -1; //MS

	const float M_F_CLIMB_SPEED = 50.0f;
	bool m_bIsClimbing = false;
	bool m_bPlayerCollidesWithLargeLadderDown = false;
	bool m_bPlayerCollidesWithSmallLadderDown = false;
	bool m_bPlayerCollidesWithLargeLadderUp = false;
	bool m_bPlayerCollidesWithSmallLadderUp = false;
	bool m_bIsAbleToClimb = true;

	//Jumping
	void Jump();
	void JumpAway();
	int m_iJumpDirection = 0;
	const int M_I_DEFAULT_JUMP_DIRECTION = 1;
	float m_fNowJumpHeight = 0.0f;
	const float M_F_MAX_JUMP_HEIGHT = 27.0f;
	bool m_bPlayerGoingDown = false;
	bool m_bIsJumping = false;
	bool m_bIsAbleToJump = true;

	//UseHammer
	void UseHammer();
	void InitializeHammerAnimation();
	int m_iActualFrameInSpritesheet = 0;
	float m_fLeftTime = 9.0f;
	const float M_F_HAMMER_DEFAULT_DELAY = 0.15f;
	const float M_F_DEFAULT_LEFT_TIME = 9.0f;
	bool m_bHammerIsFlasching = false;
	bool m_bIsWithHammer = false;
	bool m_bPlayerCollidesWithHammer = false;
	bool m_bHammerCollidesWithBarrel = false;

	//Sprite Offsets
	const int M_I_VERTICAL_OFFSET = 10;
	const int M_I_HORIZONTAL_OFFSET = 17;

	//HammerCollider
	///verschiebt den Collider für Circle Gravity auf den Player
	void SetGravityColliderWhileHammertime();
	void SetHammerColliderOffset();
	const int M_I_HAMMER_COLLIDER_DIAMETER = 60;
	Vector m_vColliderOffsetForGravity{ 0,16 };
	Vector m_vHammerColliderOffset{ 0,0 };

	const char M_C_W_KEY = 'w';
	const char M_C_A_KEY = 'a';
	const char M_C_S_KEY = 's';
	const char M_C_D_KEY = 'd';
	const char M_C_SPACE_KEY = ' ';

	const float M_F_END_OF_TIMER = 0.0f;

	//Pointer
	CSprite*			m_pPlayer = nullptr;
	CCircleCollider*	m_pHammerCollider = nullptr;

	CBoxCollider*		TestCollider = nullptr;

	int m_iLivesLeft = CEngine::m_pDataManager->GetLivesLeft();

	//Strings für m_pPLayer->Initialize( );
	//									^
	//  								|

	const string m_sDefaultLR_32x32_f1 =
		"Assets\\Jumpman\\DefaultLR_32x32_f1.bmp";
	const string m_sDefaultLL_32x32_f1 =
		"Assets\\Jumpman\\DefaultLL_32x32_f1.bmp";
	const string m_sDeathAnimation_448x32_f14 =
		"Assets\\Jumpman\\DeathAnimation_448x32_f14.bmp";
	const string m_sJumpLR_32x32_f1 =
		"Assets\\Jumpman\\JumpLR_32x32_f1.bmp";
	const string m_sJumpLL_32x32_f1 =
		"Assets\\Jumpman\\JumpLL_32x32_f1.bmp";
	const string m_sWalkAnimationLR_128x32_f4 =
		"Assets\\Jumpman\\WalkAnimationLR_128x32_f4.bmp";
	const string m_sWalkAnimationLL_128x32_f4 =
		"Assets\\Jumpman\\WalkAnimationLL_128x32_f4.bmp";
	const string m_sClimbingAnimationLong_288x32_f9 =
		"Assets\\Jumpman\\ClimbingAnimationLong_288x32_f9.bmp";
	const string m_sClimbingAnimationShort_224x32_f7 =
		"Assets\\Jumpman\\ClimbingAnimationShort_224x32_f7.bmp";
	const string m_sClimbingAnimationLongDownwards_288x32_f9 =
		"Assets\\Jumpman\\ClimbingAnimationLongDownwards_288x32_f9.bmp";
	const string m_sClimbingAnimationShortDownwards_224x32_f7 =
		"Assets\\Jumpman\\ClimbingAnimationShortDownwards_224x32_f7.bmp";
	const string m_sHammerRedGoldLR_384x52_f6 =
		"Assets\\Jumpman\\HammerRedGoldLR_384x52_f6.bmp";
	const string m_sHammerRedGoldLL_384x52_f6 =
		"Assets\\Jumpman\\HammerRedGoldLL_384x52_f6.bmp";
	const string m_sHammerRedLR_384x52_f6 =
		"Assets\\Jumpman\\HammerRedLR_384x52_f6.bmp";
	const string m_sHammerRedLL_384x52_f6 =
		"Assets\\Jumpman\\HammerRedLL_384x52_f6.bmp";

};

