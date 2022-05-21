/*****************************************************************************
* Project: SDLFramework
* File   : Game.h
* Date   : 18.12.2019
* Author : Ralf Hüwe (RH)
*		   Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	18.12.19	RH	Created
*	13.01.20	MS	Platforms+
*	14.01.20	MS	Platforms to Level
******************************************************************************/
#include <iostream>
#include "Engine.h"
#include "GamestateManager.h"
#include "GamestateMenu.h"
#include "GamestateStartAnimation.h"
#include "GamestatePlay.h"
#include "GamestateHighscore.h"
#include "GamestateControls.h"
#include "GamestateHowHeight.h"
#include "GamestateLogo.h"
#include "Game.h"

/*****************************************************************************/
int CGame::Initialize()
{
	int result = CEngine::Initialize(SCREENWIDTH, SCREENHEIGHT);
	if (result != 0) return result;

	/*
	CGamestateManager::AddGamestate( new CGamestateCredits() );
	*/
	CGamestateManager::AddGamestate( new CGamestateLogo() );
	CGamestateManager::AddGamestate( new CGamestateMenu() );
	CGamestateManager::AddGamestate( new CGamestateStartAnimation() );
	CGamestateManager::AddGamestate( new CGamestatePlay() );
	CGamestateManager::AddGamestate( new CGamestateHighscore());
	CGamestateManager::AddGamestate( new CGamestateControls());
	CGamestateManager::AddGamestate( new CGamestateHowHeight());

	CGamestateManager::ChangeGamestate( "logo" );

	//CGamestateManager::GetActiveGamestate().Initialize();

	m_bRunning = true;

	return result;
}

/*****************************************************************************/
int CGame::Run()
{
	// Gameloop
	int result = -1;
	while( m_bRunning && CEngine::IsRunning() )
	{
		result = Update();
		Render();

		CEngine::SwapBackbuffer();
	}

	return 0;
}

/*****************************************************************************/
void CGame::Finalize()
{
	CGamestateManager::GetActiveGamestate().Finalize();

	CEngine::Finalize();
}

/*****************************************************************************/
int CGame::Update()
{
	int result = CEngine::Update();
	if( result != 0 ) return result;

	CGamestateManager::GetActiveGamestate().Update();

	return result;
}

/*****************************************************************************/
void CGame::Render()
{
//?	SDL_SetRenderDrawColor( CEngine::GetRenderer(), 0, 0, 0, 255 );
	CEngine::Render();

	CGamestateManager::GetActiveGamestate().Render();
}
