/*****************************************************************************
* Project: SDLFramework
* File   : Button.cpp
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
#include "Utils.h"
#include "Button.h"

int CButton::m_iNextID = 0;

/****************************************************************************/
int CButton::Initialize(std::string _filename, Vector& _pos)
{
	m_pSprite = new CSprite();
	int result = m_pSprite->Initialize( _filename, 3 );
	if( result != 0 ) return result;
	m_pSprite->SetPosition( _pos );
	m_pSprite->SetPlaying( false );

	return result;
}

/****************************************************************************/
void CButton::Finalize()
{
	FINALIZE_DELETE( m_pSprite );
}

/****************************************************************************/
int CButton::Update()
{
	bool isMouseInRect = IsPointInRect( 
		CEngine::GetMousePosition(), m_pSprite->GetBoundingBox() );
	switch( m_state )
	{
		case GUISTATE_INACTIVE: // nobreak;
		case GUISTATE_NONE:
			m_state = GUISTATE_UP; 
			break;

		case GUISTATE_UP:
			if( isMouseInRect )
			{
				m_state = GUISTATE_MOUSEOVER;
			}
			break;

		case GUISTATE_MOUSEOVER:
			if( !isMouseInRect ) m_state = GUISTATE_UP;
			if (CEngine::IsMouseButtonDown()) m_state = GUISTATE_DOWN;
			break;

		case GUISTATE_DOWN:
			if( !isMouseInRect ) m_state = GUISTATE_UP;
			if (CEngine::IsMouseButtonUp())
			{
				m_state = GUISTATE_MOUSEOVER;
				if (m_pProc != nullptr)
					(*m_pProc)(m_iID);
			}
			break;
	}
	m_pSprite->Update();

	return 0;
}

/****************************************************************************/
void CButton::Render()
{
	switch( m_state ) 
	{
		case GUISTATE_NONE:
		case GUISTATE_UP:			m_pSprite->SetActualFrame( 0 ); break;
		case GUISTATE_MOUSEOVER:	m_pSprite->SetActualFrame( 1 ); break;
		case GUISTATE_DOWN:			m_pSprite->SetActualFrame( 2 ); break;
		case GUISTATE_INACTIVE:		m_pSprite->SetActualFrame( 3 ); break;
	}

	m_pSprite->Render();
}
