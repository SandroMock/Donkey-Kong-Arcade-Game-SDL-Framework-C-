/*****************************************************************************
* Project: SDLFramework
* File   : Pauline.h
* Date   : 25.02.2020
* Author : Sandro Mock (SM)
*
* In dieser Klasse wird Pauline behandelt. Sie befindet sich zu Beginn des 
* Spieles auf der obersten Plattform und wird durch einen Timer gelegentlich
* animiert und schreit Hilfe.
*
* History:
*	25.02.20	SM	Created
*	25.02.20	SM	+Animation
*	01.03.20	SM	+DeletPauline Methode
*	03.03.20	SM	+SetIsPlayerDead Methode
******************************************************************************/
#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Engine.h"

using namespace std;

class CPauline : CGameObject
{
public:
	void SetIsPlayerDead(bool _dead) { m_bIsPlayerDead = _dead; }
	void DeletePauline(bool _isActive)
	{
		if (_isActive)
		{
			m_pPauline->Finalize();
			m_pHelp->Finalize();
		}
	}
	int Initialize();
	void Finalize();
	int Update();
	void Render();

	void SetActive(bool _bool) { m_pPauline->SetActive(_bool); }

private:
	float m_fTimer = 0.0f;
	float m_fAnimationTimer = 1.5f;
	float m_fDefaultTimer = 5.0f;
	bool m_bAnimation = false;
	bool m_bIsPlayerDead = false;
	CSprite* m_pPauline = nullptr;
	CSprite* m_pHelp = nullptr;
	const Vector M_V_POS{ 480, 217 };
	const Vector M_V_HELP_POS{ 515, 195 };
};

