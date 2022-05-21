/*****************************************************************************
* Project: SDLFramework
* File   : Flame.h
* Date   : 17.02.2020
* Author : Sandro Mock (SM)
*
* In dieser Klasse wird die Flamme behandelt. Sie wird bewegt, besitzt einen
* Collider der mit dem Spieler und den Leitern kollidiert und besitzt durch Stage
* Aenderungen die Gravitation der jeweiligen Stage auf welcher sie sich befindet.
*
* History:
*	17.02.20	SM	Created
*	17.02.20	SM	+Flame Bewegung
*	18.02.20	SM	+Collider
*	21.02.20	MS	GetPos engefügt
*	26.02.20	SM	+bool fürs Leiter klettern 
*	27.02.20	SM	Random fuesr Leiter klettern
*	27.02.20	SM	+Stages
******************************************************************************/
#pragma once
#include "Sprite.h"
#include "Engine.h"
#include "Level.h"
#include "LevelConfig.h"
#include "CircCollObject.h"

using namespace std;

class CFlame :
	public CCircCollObject
{
public:
	bool OnPlayerDeath() { return m_bIsPlayerDead; }
	void SetIsWinActive(bool _win) { m_bIsWinActive = _win; }
	bool GetIsWinActive() { return m_bIsWinActive; }
	void SetDestroyOnHit(bool _hit) { m_bIsDestroyed = _hit; }
	void SetIsPlayerDead(bool _dead) { m_bIsPlayerDead = _dead; }
	void ChangeStage();
	STAGE GetStage() { return m_stage; }
	bool GetGravity() { return m_bFlameGravity; }
	void SetGravity(bool _gravity) { m_bFlameGravity = _gravity; }
	void SetLadderColl(bool _hit) { m_bHitLadder = _hit; }
	void SetActive(bool _active, bool _deleteFlame);
	int Initialize(float _x, float _y);
	void Finalize();
	int Update();
	void Render();
private:
	STAGE m_stage = STAGE_SEVEN;
	const int M_I_WIDTH = 22;
	const int M_I_HEIGHT = 24;
	const int m_iDirectionChange = -1;
	const int M_I_RANDOM = 17;
	int m_iRandomRange = 20;
	int m_iUseLadder = 0;
	const float M_F_MAX_HEIGHT = 25.0f;
	const float M_F_CLIMB_SPEED = 50.0f;
	const float M_F_MAX_POS_X = 700;
	const float M_F_MIN_POS_X = 320;
	float m_fActualHeight = 0.0f;
	float m_fFlameSpeed = 30.0f;
	float m_fTimeBetweenJumps = 1.0f;
	float m_fDefaultTimeBetweenJumps = .2f;
	float m_fDieAnimationTimer = 1.0f;
	bool m_bChangeFlame = false;
	bool m_bIsjumping = true;
	bool m_bHitLadder = false;
	bool m_bFlameGravity = false;
	bool m_bDirection = false;
	bool m_bIsDestroyed = false;
	bool m_bIsWinActive = false;
	bool m_bIsPlayerDead = false;
	Vector m_vActualPos{ 0.0f, 0.0f };
	CSprite* m_pFlame = nullptr;

	const string M_S_FLAME_RIGHT = "Assets\\Enemy\\FlameRight_45x24_f2.bmp";
	const string M_S_FLAME_LEFT = "Assets\\Enemy\\FlameLeft_45x24_f2.bmp";
};

