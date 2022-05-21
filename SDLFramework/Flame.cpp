/*****************************************************************************
* Project: SDLFramework
* File   : Flame.cpp
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
#include "Engine.h"
#include <iostream>
#include "Flame.h"

// Stage wechsel fuer alle Flammen
void CFlame::ChangeStage()
{
	switch (m_stage)
	{
	case STAGE_SEVEN:
		m_stage = STAGE_SIX;
		break;

	case STAGE_SIX:
		m_stage = STAGE_FIVE;
		break;

	case STAGE_FIVE:
		m_stage = STAGE_FOUR;
		break;

	case STAGE_FOUR:
		m_stage = STAGE_THREE;
		break;

	case STAGE_THREE:
		m_stage = STAGE_TWO;
		break;
	}
}


void CFlame::SetActive(bool _active, bool _deleteFlame)
{
	float m_fFlameJumpSpeed = 80.0f * CEngine::GetDeltaTime();

	if (_active)
	{
		//Finalize alle Flammen
		if (_deleteFlame)
		{
			m_pFlame->Finalize();
			return;
		}

		m_pFlame->SetActive(true);

		// Sprung Anweisung und Bewegung fuer die Flamme
		m_fTimeBetweenJumps -= CEngine::GetDeltaTime();
		if (m_fTimeBetweenJumps <= 0) { m_bIsjumping = true; }
		if (m_bIsjumping)
		{
			if (m_fActualHeight < M_F_MAX_HEIGHT && !m_bDirection)
			{
				m_bFlameGravity = true;
				IncPositionY(-m_fFlameJumpSpeed);
				m_fActualHeight += m_fFlameJumpSpeed;
			}
			else
			{
				m_bDirection = true;
				IncPositionY(-20 * CEngine::GetDeltaTime());
				m_fActualHeight -= m_fFlameJumpSpeed;
			}
			if (m_fActualHeight <= 0)
			{
				m_bFlameGravity = true;
				m_bIsjumping = false;
				m_bDirection = false;
				m_fTimeBetweenJumps = m_fDefaultTimeBetweenJumps;
			}
		}
		//Richtung wechsel
		if (GetPositionX() >= M_F_MAX_POS_X)
		{
			m_pFlame->Finalize();
			m_fFlameSpeed *= m_iDirectionChange;
			SetPosition(M_F_MAX_POS_X, GetPositionY());
			m_vActualPos = GetPosition();
			m_pFlame->Initialize(M_S_FLAME_LEFT, 2);
			SetPosition(m_vActualPos);
		}
		else if (GetPositionX() <= M_F_MIN_POS_X)
		{
			m_pFlame->Finalize();
			m_fFlameSpeed *= m_iDirectionChange;
			SetPosition(M_F_MIN_POS_X, GetPositionY());
			m_vActualPos = GetPosition();
			m_pFlame->Initialize(M_S_FLAME_RIGHT, 2);
			SetPosition(m_vActualPos);
			IncPositionX(m_fFlameSpeed * CEngine::GetDeltaTime());
		}

		IncPositionX(m_fFlameSpeed * CEngine::GetDeltaTime());

		//Random fuer Leitern klettern
		if (m_bHitLadder  && m_iUseLadder == 0 && m_bChangeFlame)
		{
			m_iUseLadder = rand() % m_iRandomRange + 1;
			cout << m_iUseLadder << " Flame Rng" << endl;
			if (m_iUseLadder > M_I_RANDOM && m_iUseLadder > 0) { ChangeStage(); }
		}
		if (m_iUseLadder > M_I_RANDOM)
		{
			m_bIsjumping = false;
			m_fTimeBetweenJumps = m_fDefaultTimeBetweenJumps;
			m_bFlameGravity = false;
			IncPositionX(-m_fFlameSpeed);
			IncPositionY(-M_F_CLIMB_SPEED * CEngine::GetDeltaTime());
		}
	}
}

int CFlame::Initialize(float _x, float _y)
{
	CCircCollObject::Initialize(_x, _y, M_I_WIDTH, M_I_HEIGHT);
	m_pFlame = new CSprite();
	m_pFlame->Initialize(M_S_FLAME_RIGHT, 2);
	m_pFlame->SetPosition(GetPositionX(), GetPositionY());
	m_pFlame->SetActive(false);

	return 0;
}

void CFlame::Finalize()
{
	FINALIZE_DELETE(m_pFlame);
	CCircCollObject::Finalize();
}

int CFlame::Update()
{
	if (m_bIsPlayerDead)
	{
		m_fDieAnimationTimer -= CEngine::GetDeltaTime2();
		if (m_fDieAnimationTimer >= 0)
		{
			CEngine::PauseGame();
		}
	}

	//Random fuer Leitern klettern
	if (m_bHitLadder && m_iUseLadder == 0)
	{
		m_bChangeFlame = true;
	}
	else if (m_bHitLadder && m_iUseLadder != 0)
	{
		m_bChangeFlame = false;
	}
	else
	{
		m_bChangeFlame = false;
		m_iUseLadder = 0;
	}

	CCircCollObject::Update();

	m_pFlame->SetPosition(GetPositionX(), GetPositionY());
		m_pFlame->Update();
		return 0;
}

void CFlame::Render()
{
		m_pFlame->Render();
}
