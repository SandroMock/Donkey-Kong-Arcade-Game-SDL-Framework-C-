/*****************************************************************************
* Project: SDLFramework
* File   : Pauline.cpp
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
#include "Pauline.h"

int CPauline::Initialize()
{
	m_pPauline = new CSprite();
	m_pPauline->Initialize("Assets\\DefaultPauline_30x44_f1.bmp");
	m_pPauline->SetPosition(M_V_POS);
	m_pPauline->SetDefaultDelay(.15f);
	
	m_pHelp = new CSprite();
	m_pHelp->Initialize("Assets\\Help_39x20_f1.bmp");
	m_pHelp->SetPosition(M_V_HELP_POS);
	m_pHelp->SetActive(false);
	return 0;
}

void CPauline::Finalize()
{
	FINALIZE_DELETE(m_pPauline);
	FINALIZE_DELETE(m_pHelp);
}

int CPauline::Update()
{
	//Pauline Animation
	m_fTimer -= CEngine::GetDeltaTime();
	m_pPauline->Update();
	if (m_fTimer <= 0 && m_bAnimation)
	{
		m_pPauline->Finalize();
		m_pPauline->Initialize("Assets\\Pauline_92x44_f3.bmp", 3);
		m_pPauline->SetPosition(M_V_POS);
		m_pHelp->SetActive(true);
		m_fTimer = m_fAnimationTimer;
		m_bAnimation = false;
	}
	else if (m_fTimer <= 0 && !m_bAnimation)
	{
		m_pPauline->Finalize();
		m_pPauline->Initialize("Assets\\DefaultPauline_30x44_f1.bmp");
		m_pPauline->SetPosition(M_V_POS);
		m_pHelp->SetActive(false);
		m_fTimer = m_fDefaultTimer;
		m_bAnimation = true;
	}
	return 0;
}

void CPauline::Render()
{
	m_pPauline->Render();
	m_pHelp->Render();
}
