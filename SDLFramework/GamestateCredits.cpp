/*****************************************************************************
* Project: SDLFramework
* File   : GamestateCredits.cpp
* Date   : 22.01.2020
* Author : Ralf Hüwe (RH)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	22.01.20	RH	Created
******************************************************************************/
#include "Engine.h"
#include "GamestateManager.h"
#include "GamestateCredits.h"

/*****************************************************************************/
int CGamestateCredits::Initialize()
{
	m_pBackground = new CSprite();
	m_pBackground->Initialize( "Assets\\Credits\\Background_640x384_f1.bmp" );
	m_pBackground->SetPosition( 
		CEngine::GetWindowWidth() / 2.0f, CEngine::GetWindowHeight() / 2.0f );

	m_pCredits = new CSprite();
	m_pCredits->Initialize( "Assets\\Credits\\credits_220x463_f1.bmp" );
	m_pCredits->SetPosition( 150.0f, CEngine::GetWindowHeight() + 463.0f );

	return 0;
}

/*****************************************************************************/
void CGamestateCredits::Finalize()
{
	FINALIZE_DELETE( m_pCredits );
	FINALIZE_DELETE( m_pBackground );
}

/*****************************************************************************/
int CGamestateCredits::Update()
{
	m_pBackground->Update();
	m_pCredits->IncPositionY( -50 * CEngine::GetDeltaTime() );
	m_pCredits->Update();

	if( CEngine::IsMouseButtonDown() )
		CGamestateManager::ChangeGamestate( "menu" );

	return 0;
}

/*****************************************************************************/
void CGamestateCredits::Render()
{
	m_pBackground->Render();
	m_pCredits->Render();
}
