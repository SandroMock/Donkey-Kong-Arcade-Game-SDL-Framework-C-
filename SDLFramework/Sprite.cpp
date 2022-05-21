/*****************************************************************************
* Project: SDLFramework
* File   : Sprite.cpp
* Date   : ??.??.20??
* Author : Ralf Hüwe (RH)
*		   Stephan Weber (SW)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	??.??.??	RH	Created
*	03.02.20	SW	Tag in Konstruktor
******************************************************************************/
#include <iostream>
#include "Engine.h"
#include "Utils.h"
#include "Sprite.h"

//IsColliding von Marcus Schaal entfernt

//Konstruktor von Marcus Schaal entfernt

//Destruktor von Marcus Schaal entfernt

/*****************************************************************************/
int CSprite::Initialize( std::string _filename, int _numFrames )
{
	m_pSurface = SDL_LoadBMP( _filename.c_str() );
	if( m_pSurface == nullptr )
	{
		std::cout << SDL_GetError() << std::endl;
		return M_I_INIT_RETURN_STEP1;
	}

	SDL_SetColorKey( m_pSurface, SDL_TRUE,
					 SDL_MapRGB( m_pSurface->format, M_I_COLOR_KEY_R, 
								 M_I_COLOR_KEY_G, M_I_COLOR_KEY_B ) );

	m_pTexture = 
		SDL_CreateTextureFromSurface( CEngine::GetRenderer(), m_pSurface );
	if( m_pTexture == nullptr )
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_FreeSurface( m_pSurface );
		m_pSurface = nullptr;
		return M_I_INIT_RETURN_STEP2;
	}

	// Breite und Höhe der geladenen Grafik ermitteln
	SDL_QueryTexture( m_pTexture, nullptr, nullptr, &m_iWidth, &m_iHeight );
	m_iWidth /= _numFrames;
	m_iNumFrames = _numFrames;
	m_center.x = m_iWidth / I_SPRITE_DOUBLE;
	m_center.y = m_iHeight / I_SPRITE_DOUBLE;
	m_iActualFrame = M_I_ACTUAL_FRAME_INIT;
	m_fActualDelay = m_fDefaultDelay;

	// Position erstmal auf 0 setzen
	m_Position.x = M_F_POS_INIT;
	m_Position.y = M_F_POS_INIT;

	// Kollisionskreis von Marcus Schaal entfernt

	m_bActive = true;

	return M_I_SPRITE_SUCCESS;
}

/*****************************************************************************/
void CSprite::Finalize()
{
	if( m_pTexture != nullptr )
	{
		SDL_DestroyTexture( m_pTexture );
		m_pTexture = nullptr;
	}
	if( m_pSurface != nullptr )
	{
		SDL_FreeSurface( m_pSurface );
		m_pSurface = nullptr;
	}
}

/*****************************************************************************/
int CSprite::Update( int _whichDeltatime )
{
	if( !m_bActive ) return M_I_FAIL_RETURN;
	if( !m_bPlayable ) return M_I_FAIL_RETURN;

	/*-----------------------------------------------------------------------*/
	//ab hier von Stephan Weber
	if( _whichDeltatime == I_DEFAULT_DELTA_TIME )
	{ 
		m_fActualDelay -= CEngine::GetDeltaTime(); //Zeile von Ralf Hüwe
	}

	else 
	{ 
		m_fActualDelay -= CEngine::GetDeltaTime2(); 
	}
	//bis hier von Stephan Weber
	/*-----------------------------------------------------------------------*/
	
	if( m_fActualDelay <= M_F_ACTUAL_DELAY_FAILED )
	{
		m_fActualDelay = m_fDefaultDelay;
		m_iActualFrame++;
		if( m_iActualFrame >= m_iNumFrames )
			m_iActualFrame = M_I_ACTUAL_FRAME_INIT;
	}

	return M_I_SPRITE_SUCCESS;
}

/*****************************************************************************/
void CSprite::Render()
{
	if( !m_bActive ) return;

	SDL_Rect src = { m_iActualFrame * m_iWidth, M_I_SDL_RECT_Y, m_iWidth, 
					 m_iHeight };
	SDL_Rect dest = { 
						static_cast<int>( m_Position.x - m_center.x ), 
						static_cast<int>( m_Position.y - m_center.y ),
						m_iWidth, 
						m_iHeight 
					};
	SDL_RenderCopyEx(
		CEngine::GetRenderer(),
		m_pTexture,
		&src,
		&dest,
		M_F_ROTATION_ANGLE,
		&m_center,
		SDL_FLIP_NONE
	);
}
