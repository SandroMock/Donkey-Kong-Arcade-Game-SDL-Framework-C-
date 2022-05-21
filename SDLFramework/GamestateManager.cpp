/*****************************************************************************
* Project: SDLFramework
* File   : GamestateManager.cpp
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
#include "Defines.h"
#include "GamestateManager.h"

std::list<CGamestate*> CGamestateManager::m_pGamestates;
CGamestate* CGamestateManager::m_pActiveGamestate = nullptr;

/*****************************************************************************/
int CGamestateManager::Initialize()
{
	// Liste der gamestates leeren
	m_pGamestates.clear();

	return I_GS_MANAGER_SUCCESS;
}

/*****************************************************************************/
void CGamestateManager::Finalize()
{
	for( auto gs : m_pGamestates )
	{
		FINALIZE_DELETE( gs );
	}
}

/*****************************************************************************/
int CGamestateManager::Update()
{
	if( m_pActiveGamestate != nullptr )
	{
		return m_pActiveGamestate->Update();
	}
	return I_GS_MANAGER_SUCCESS;
}

/*****************************************************************************/
void CGamestateManager::Render()
{
	if( m_pActiveGamestate != nullptr )
	{
		m_pActiveGamestate->Render();
	}
}

/*****************************************************************************/
void CGamestateManager::ChangeGamestate( std::string _which )
{
	// c++ foreach
	// Syntax:
	//		<Datentyp> <Bezeichner> : <Container>

	for( auto gs : m_pGamestates )
	{
		if( gs->GetName() == _which )
		{
			if( m_pActiveGamestate != nullptr )
			{
				m_pActiveGamestate->Finalize();
			}
			m_pActiveGamestate = gs;
			m_pActiveGamestate->Initialize();
		}
	}
}

/*****************************************************************************/
CGamestate& CGamestateManager::GetActiveGamestate()
{
	return *m_pActiveGamestate;
}
