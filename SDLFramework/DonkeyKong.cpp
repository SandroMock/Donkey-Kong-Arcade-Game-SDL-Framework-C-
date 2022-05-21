/*****************************************************************************
* Project: SDLFramework
* File   : DonkeyKong.cpp
* Date   : 20.01.2020
* Author : Sandro Mock (SM)
*
* In dieser Klasse wird Donkey Kong behandelt. Er wird animiert, es werden
* durch einen Timer Faesser gerollt und das Spiel wird angehalten falls der
* Spieler mit deinem Fass kollidiert oder der Spieler die oberste Plattform
* erreicht hat.
*
* History:
*	20.01.20	SM	Created
*	21.01.20	SM	+Donkey Kong Animation
*	10.02.20	SM	+RollBarrels Methode
*	17.02.20	SM	+RollBarrels und Update Parameter
*	19.02.20	SM	-CBarrel Array
*	20.02.20	SM	Initialize erweitert
*	28.02.20	SM	+SetIsWinActive, SetIsPlayerDead Methoden
******************************************************************************/
#include <iostream>
#include "Engine.h"
#include "DonkeyKong.h"
#include "Collider.h"
#include <array>

/*****************************************************************************/


void CDonkeyKong::RollBarrels(CBarrel* _barrel[40], CFlame* _flame[5])
{
	m_fBarrelTimer -= CEngine::GetDeltaTime();
	//Erstes Fass
	if (m_fBarrelTimer <= 100.5f) _barrel[0]->SetActive(true, _flame, m_bOnPlayerDeath);
	/**********************************************************/
	if (m_fBarrelTimer <= 98.5f) _barrel[1]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 96.0f) _barrel[2]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 93.5f) _barrel[3]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 91.0f) _barrel[4]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 88.5f) _barrel[5]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 86.0f) _barrel[6]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 83.4f) _barrel[7]->SetActive(true, _flame, m_bOnPlayerDeath);
	//Blaues Fass
	if (m_fBarrelTimer <= 81.0f)
	{
		_barrel[36]->SetActive(true, _flame, m_bOnPlayerDeath);
		if (_barrel[36]->GetPositionX() <= M_F_OIL_POS_X &&
			_barrel[36]->GetPositionY() >= M_F_OIL_POS_Y)
		{
			_flame[1]->SetActive(true, m_bOnPlayerDeath);
		}
	}				  
	/**********************************************************/
	if (m_fBarrelTimer <= 78.4f) _barrel[8]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 75.9f) _barrel[9]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 73.4f) _barrel[10]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 70.9f) _barrel[11]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 68.4f) _barrel[12]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 65.9f) _barrel[13]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 63.4f) _barrel[14]->SetActive(true, _flame, m_bOnPlayerDeath);
	//Blaues Fass
	if (m_fBarrelTimer <= 61.0f)
	{
		_barrel[37]->SetActive(true, _flame, m_bOnPlayerDeath);
		if (_barrel[37]->GetPositionX() <= M_F_OIL_POS_X &&	
			_barrel[37]->GetPositionY() >= M_F_OIL_POS_Y)
		{
			_flame[2]->SetActive(true, m_bOnPlayerDeath);
		}
	}
	/**********************************************************/
	if (m_fBarrelTimer <= 58.4f) _barrel[15]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 55.8f) _barrel[16]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 53.4f) _barrel[17]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 50.8f) _barrel[18]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 48.3f) _barrel[19]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 45.9f) _barrel[20]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 43.3f) _barrel[21]->SetActive(true, _flame, m_bOnPlayerDeath);
	//Blaues Fass
	if (m_fBarrelTimer <= 41.0f)
	{
		_barrel[38]->SetActive(true, _flame, m_bOnPlayerDeath);
		if (_barrel[38]->GetPositionX() <= M_F_OIL_POS_X &&
			_barrel[38]->GetPositionY() >= M_F_OIL_POS_Y)
		{
			_flame[3]->SetActive(true, m_bOnPlayerDeath);
		}
	}
	/**********************************************************/
	if (m_fBarrelTimer <= 38.3f) _barrel[22]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 35.8f) _barrel[23]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 33.3f) _barrel[24]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 30.8f) _barrel[25]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 28.2f) _barrel[26]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 25.6f) _barrel[27]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 23.2f) _barrel[28]->SetActive(true, _flame, m_bOnPlayerDeath);
	//Blaues Fass
	if (m_fBarrelTimer <= 21.0f)
	{
		_barrel[39]->SetActive(true, _flame, m_bOnPlayerDeath);
		if (_barrel[39]->GetPositionX() <= M_F_OIL_POS_X &&
			_barrel[39]->GetPositionY() >= M_F_OIL_POS_Y)
		{
			_flame[4]->SetActive(true, m_bOnPlayerDeath);
		}
	}
	/**********************************************************/
	if (m_fBarrelTimer <= 18.1f) _barrel[29]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 15.6f) _barrel[30]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 13.2f) _barrel[31]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 10.6) _barrel[32]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 8.1f) _barrel[33]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 5.3f) _barrel[34]->SetActive(true, _flame, m_bOnPlayerDeath);

	if (m_fBarrelTimer <= 3.0f) _barrel[35]->SetActive(true, _flame, m_bOnPlayerDeath);
	//Blaues Fass
	if (m_fBarrelTimer <= 2.0f) _barrel[40]->SetActive(true, _flame, m_bOnPlayerDeath);
	/**********************************************************/
}

int CDonkeyKong::Initialize(CBarrel* _barrel[40])
{
	CBoxCollObject::Initialize(340.0f, 228.0f, 192, 96);
	if (_barrel == nullptr) { return false; }
	// Feste Gegenstaende
	m_pBarrelStack = new CSprite();
	m_pBarrelStack->Initialize(M_S_BARREL_STACK);
	m_pBarrelStack->SetPosition(M_V_BARREL_STACK_POS.x, M_V_BARREL_STACK_POS.y);

	//Donkey Kong
	// DK1 = Erstes blaues Fass welches geworfen wird
	m_pDK1 = new CSprite();
	m_pDK1->Initialize(M_S_FIRST_BARREL, 3);
	m_pDK1->SetPosition(M_V_DK_POS.x, M_V_DK_POS.y);
	m_pDK1->SetActive(true);

	// DK2 = Donkey Kong mit braunem Fass
	m_pDK2 = new CSprite();
	m_pDK2->Initialize(M_S_BROWN_BARREL, 5);
	m_pDK2->SetPosition(M_V_DK_POS.x, M_V_DK_POS.y);
	m_pDK2->SetActive(false);

	// DK3 = Donkey Kong mit blauem Fass
	m_pDK3 = new CSprite();
	m_pDK3->Initialize(M_S_BLUE_BARREL, 5);
	m_pDK3->SetPosition(M_V_DK_POS.x, M_V_DK_POS.y);
	m_pDK3->SetActive(false);

	// Donkey Kong Jubel Animation
	m_pDKJubel = new CSprite();
	m_pDKJubel->Initialize(M_S_DK_JUBEL, 5);
	m_pDKJubel->SetPosition(M_V_DK_POS.x, M_V_DK_POS.y);
	m_pDKJubel->SetActive(false);

	std::cout << m_fTimer << std::endl;
	return 0;
}

void CDonkeyKong::Finalize()
{
	FINALIZE_DELETE(m_pBarrelStack);
	FINALIZE_DELETE(m_pDK1);
	FINALIZE_DELETE(m_pDK2);
	FINALIZE_DELETE(m_pDK3);
	FINALIZE_DELETE(m_pDKJubel);
	CBoxCollObject::Finalize();
}

int CDonkeyKong::Update(CBarrel* _barrel[40], CFlame* _flame[5])
{
	RollBarrels(_barrel, _flame);
	for (int k = 1; k < 40; k++)
	{
		_barrel[k]->SetGravity(true);
		// Anhalten der Faesser bei Spieler tot oder win
		if (_barrel[k]->OnPlayerDeath() == true || _barrel[k]->GetIsWinActive() == true)
		{
			m_fDieAnimationTimer -= CEngine::GetDeltaTime2();
			if (m_fDieAnimationTimer < 0)
			{
				m_bOnPlayerDeath = true;
			}
		}
	}
	for (int f = 0; f < 5; f++)
	{
		// Anhalten der Flammen bei Spieler tot oder win
		if (_flame[f]->OnPlayerDeath() == true || _flame[f]->GetIsWinActive() == true)
		{
			m_fDieAnimationTimer -= CEngine::GetDeltaTime2();
			if (m_fDieAnimationTimer < 0)
			{
				m_bOnPlayerDeath = true;
			}
		}
	}

	m_pDK1->Update();
	m_pDK2->Update();
	m_pDK3->Update();
	m_pDKJubel->Update();

	// Donkey Kong Animation
	m_fTimer -= CEngine::GetDeltaTime();
	switch (m_animation)
	{
	case START:
		if (m_fTimer <= 0.0f)
		{
			m_pDK1->SetActive(false);
			m_pDK2->SetActive(true);
			m_fTimer = m_fDK1Timer;
			m_animation = BROWN;
		}
		break;
	case BROWN:
		if (m_fTimer <= 12.5f)
		{
			m_pDK2->SetActive(false);
			m_pDKJubel->SetActive(true);
		}
		if (m_fTimer <= 10.0f)
		{
			m_pDKJubel->SetActive(false);
			m_pDK2->SetActive(true);
		}
		if (m_fTimer <= 5.0f)
		{
			m_pDK2->SetActive(false);
			m_pDKJubel->SetActive(true);
		}
		if (m_fTimer <= 2.5f)
		{
			m_pDKJubel->SetActive(false);
			m_pDK2->SetActive(true);
		}
		if (m_fTimer <= 0.0f)
		{
			m_pDK2->SetActive(false);
			m_pDK3->SetActive(true);
			m_fTimer = m_fDK2Timer;
			m_animation = BLUE;
		}
		break;
	case BLUE:
		if (m_fTimer <= 0.0f)
		{
			m_pDK3->SetActive(false);
			m_pDK2->SetActive(true);
			m_fTimer = m_fDK1Timer;
			m_animation = BROWN;
		}
		break;
	default:
		std::cout << "Animation Error" << std::endl;
		break;
	}


	return 0;
}

void CDonkeyKong::Render()
{
	m_pBarrelStack->Render();
	m_pDK1->Render();
	m_pDK2->Render();
	m_pDK3->Render();
	m_pDKJubel->Render();
}
