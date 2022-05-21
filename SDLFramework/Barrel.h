/*****************************************************************************
* Project: SDLFramework
* File   : Barrel.h
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
*	06.03.20	SM	+Text für Score
******************************************************************************/
#pragma once
#include <iostream>
#include "GamestateManager.h"
#include "Gamestate.h"
#include "Sprite.h"
#include "Level.h"
#include "LevelConfig.h"
#include "BoxCollider.h"
#include "CircCollObject.h"
#include "Flame.h"
#include "Text.h"
#include "Defines.h"

using namespace std;
class CBarrel :
	public CCircCollObject
{
public:
	void SetPlayerJumpOverBarrel(bool _active) { m_bPlayerJumpOverBarrel = _active; }
	bool OnPlayerDeath() { return m_bIsPlayerDead; }
	void SetIsWinActive(bool _win) { m_bIsWinActive = _win; }
	bool GetIsWinActive() { return m_bIsWinActive; }
	void SetDestroyOnHit(bool _hit) {  m_bIsDestroyed = _hit; }
	void SetIsPlayerDead(bool _dead) { m_bIsPlayerDead = _dead; }
	STAGE GetStage() { return m_stage; }
	bool GetGravity() { return m_bBarrelGravity; }
	void SetGravity(bool _gravity) { m_bBarrelGravity = _gravity; }
	void SetActive(bool _active, CFlame* _flame[5], bool _deleteBarrels);
	void SetLadderColl(bool _hit) { m_bHitLadder = _hit; }
	void ChangeStage();
	CBoxCollider& GetScoreColl() { return *m_pScoreColl; }

	CBoxCollider& GetBoxCollider() { return *m_pBColl; }
	int Initialize(int _image, float _x, float _y);
	void Finalize();
	int Update();
	void Render();
private:
	STAGE m_stage = STAGE_TWO;
	int m_iImage = -1;
	int m_iUseLadder = 0;
	int m_iActualBarrelFrame = 0;
	int m_iBarrelSpeed = 120;
	const int M_I_JUMP_OVER_SCORE = 100;
	const int M_I_SCORE_OFFSET = 24;
	const int M_I_BROWN_HAMMER_SCORE = 150;
	const int M_I_BLUE_HAMMER_SCORE = 250;
	const int M_I_GET_Y_POS = 612;
	const int M_I_DIRECTION_CHANGE = -1;
	const int M_I_WIDTH = 31;
	const int M_I_HEIGHT = 20;
	const int M_I_SCORE_HEIGHT = 15;
	const int M_I_SCORE_WIDTH = 1;
	const int M_I_RANDOM = 11;
	const int M_I_RANDOM_RANGE = 15;
	const int M_I_BARREL_RIGHT = 120;
	const int M_I_BARREL_LEFT = -120;
	float m_fHammerTimer = 1.5f;
	float m_fBarrelDelay = 0.0f;
	float m_fBumpTimer = .05f;
	float m_fDieAnimationTimer = 1.0f;
	float m_fTextTimer = 1.0f;
	const float M_F_OIL_POS_X = 305;
	const float M_F_OIL_POS_Y = 600;
	const float M_F_MAX_POS_X = 735.0f;
	const float M_F_MIN_POS_X = 288.0f;
	const float M_F_DEFAULT_TIMER = .05f;
	const float M_F_ROLL_BARREL_DELAY = .08f;
	const float M_F_FIRST_BARREL_DELAY = .05f;
	bool m_bDirectionChange = true;
	bool m_bShouldMove = true;
	bool m_bHitLadder = false;
	bool m_bChangeLadder = false;
	bool m_bBarrelGravity = false;
	bool m_bIsWinActive = false;
	bool m_bIsPlayerDead = false;
	bool m_bPlayerJumpOverBarrel = false;
	bool m_bAddScore = false;
	bool m_bIsDestroyed = false;
	bool m_bFinalizeBrownBarrel = false;
	bool m_bFinalizeBlueBarrel = false;
	bool m_bTextIsVisible = false;

	const Vector M_V_FIRST_STAGE{ 357,358 };
	const Vector M_V_SECOND_STAGE{ 406, 407 };
	const Vector M_V_THIRD_STAGE{ 490, 491 };
	const Vector M_V_FOURTH_STAGE{ 537, 538 };
	const int M_I_LAST_Y_POS = 650;

	Vector m_vActualPos{ 0.0f, 0.0f };

	CSprite* m_pFirstBarrel = nullptr;
	CSprite* m_pBrownBarrel = nullptr;
	CSprite* m_pBlueBarrel = nullptr;
	CSprite* m_pBrownLadderBarrel = nullptr;
	CSprite* m_pOil = nullptr;
	CSprite* m_pBurningOil = nullptr;

	const string M_S_ROLL_BROWN_BARREL = "Assets\\Enemy\\RollBrownBarrel_123x20_f4.bmp";
	const string M_S_BROWN_BARREL_DOWN = "Assets\\Enemy\\BrownBarrelDown_64x20_f2.bmp";
	const string M_S_BLUE_BARREL_DOWN = "Assets\\Enemy\\BlueBarrelDown_64x20_f2.bmp";
	const string M_S_ROLL_BLUE_BARREL = "Assets\\Enemy\\RollBlueBarrel_124x20_f4.bmp";
	const string M_S_OIL = "Assets\\Enemy\\Oil_24x46_f1.bmp";
	const string M_S_BURNING_OIL = "Assets\\Enemy\\BurningOil_48x46_f2.bmp";

	CBoxCollider* m_pBColl = nullptr;
	CBoxCollider* m_pScoreColl = nullptr;

	Text*	m_pGetScore = nullptr;
};

