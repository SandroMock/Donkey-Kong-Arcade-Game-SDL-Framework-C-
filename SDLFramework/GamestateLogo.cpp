/*****************************************************************************
* Project: SDLFramework
* File   : GamestateLogo.cpp
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
#include "GamestateLogo.h"

/*****************************************************************************/
int CGamestateLogo::Initialize()
{
	m_pLogoPublisher = new CSprite();
	m_pLogoPublisher->Initialize( m_szLogoPublisher );
	m_pLogoPublisher->SetPosition(
		CEngine::GetWindowWidth() / I_HALF, CEngine::GetWindowHeight() / I_HALF);

	m_pLogoStudio = new CSprite();
	m_pLogoStudio->Initialize( m_szLogoStudio );
	m_pLogoStudio->SetPosition(
		CEngine::GetWindowWidth() / I_HALF, CEngine::GetWindowHeight() / I_HALF);
	m_pLogoStudio->SetActive( false );

	m_fActualTimer = m_fPublisherDisplayTime;

	return 0;
}

/*****************************************************************************/
void CGamestateLogo::Finalize()
{
	FINALIZE_DELETE( m_pLogoPublisher );
	FINALIZE_DELETE( m_pLogoStudio );
}

/*****************************************************************************/
int CGamestateLogo::Update()
{
	m_pLogoPublisher->Update();
	m_pLogoStudio->Update();

	// We are not EA, we can cancel logos
	if( CEngine::IsMouseButtonDown() )
	{
		CGamestateManager::ChangeGamestate(m_szMenuGamestate);
		return 0;
	}

	m_fActualTimer -= CEngine::GetDeltaTime();
	switch( m_state )
	{
		case PUBLISHER:
			if( m_fActualTimer < F_TIMER_DEFAULT)
			{
				m_pLogoPublisher->SetActive( false );
				m_pLogoStudio->SetActive( true );
				m_fActualTimer = m_fStudioDisplayTime;
				m_state = STUDIO;
			}
			break;

		case STUDIO:
			if( m_fActualTimer < F_TIMER_DEFAULT )
			{
				m_pLogoStudio->SetActive( false );
				m_pLogoPublisher->SetActive( true );
				m_fActualTimer = m_fPublisherDisplayTime;
				m_state = PUBLISHER;
				CGamestateManager::ChangeGamestate(m_szMenuGamestate);
			}
			break;
	}

	return 0;
}

/*****************************************************************************/
void CGamestateLogo::Render()
{
	m_pLogoPublisher->Render();
	m_pLogoStudio->Render();
}

