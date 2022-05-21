/*****************************************************************************
* Project: SDLFramework
* File   : Sprite.h
* Date   : ??.??.20??
* Author : Ralf Hüwe (RH)
*		   Stephan Weber (SW)
*		   Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	??.??.??	RH	Created
*	03.02.20	SW	"string tag" hinzugefügt und in Konstruktor gepackt
*	04.02.20	MS	Getter/Setter für Größe hinzugefügt
*	14.02.20	SW	Getter und Setter für m_fActualDelay hinzugefügt
*					Getter und Setter für m_iActualFrame hinzugefügt
*	25.02.20	MS	Position nach Transform.h ausgelagert
*	06.03.20	MS	Zeug ins Reine geschrieben und Literale entfernt
******************************************************************************/
#pragma once
#include <string> // Standard Template Library (STL)
#include <SDL.h>
#undef main
#include "types.h"
#include "Transform.h" // von Marcus Schaal hinzugefügt

/*---------------------------------------------------------------------------*/
//ab hier von Marcus Schaal
//Vorinitialisierungen
const int I_SPRITE_DOUBLE = 2;
const int I_DEFAULT_NUM_FRAMES = 1;
const int I_DEFAULT_DELTA_TIME = 1;

//bis hier von Marcus Schaal
/*---------------------------------------------------------------------------*/

class CSprite :
	public CTransform
{
public:
	//Konstruktor von Marcus Schaal entfernt
	//Destruktor von Marcus Schaal entfernt

	int Initialize( std::string _filename, 
					int _numFrames = I_DEFAULT_NUM_FRAMES );
	void Finalize();

	int Update( int _whichDeltatime = I_DEFAULT_DELTA_TIME ); //SW
	void Render();

	//Position von Marcus Schaal entfernt

	// Rotation von Marcus Schaal entfernt

	// Active / enabled
	bool IsActive() { return m_bActive; }
	void SetActive( bool _active ) { m_bActive = _active; }

	void SetPlaying( bool _play ) { m_bPlayable = _play; }

	//ab hier von Stephan Weber
	void SetActualFrame( int _frame )
	{
		if( _frame < m_iNumFrames )
		{
			m_iActualFrame = _frame;
		}
	}
	int GetActualFrame() { return m_iActualFrame; }
	void SetDefaultDelay(float _delay) { m_fDefaultDelay = _delay; }
	//ab hier nicht mehr von Stephan Weber

	Rect GetBoundingBox()
	{
		Rect rc;
		rc.topLeft.x = static_cast<int>(  m_Position.x - m_iWidth 
										 / I_SPRITE_DOUBLE );

		rc.topLeft.y = static_cast<int>( m_Position.y - m_iHeight 
										 / I_SPRITE_DOUBLE );

		rc.bottomRight.x = static_cast<int>(  m_Position.x + m_iWidth 
											 / I_SPRITE_DOUBLE);
		rc.bottomRight.y = static_cast<int>(  m_Position.y + m_iHeight 
											 / I_SPRITE_DOUBLE );

		return rc;
	}

	float			m_fCollisionRadius;

	//ab hier von Stephan Weber
	float GetActualDelay() { return m_fActualDelay; }
	void SetActualDelay( float _delay ) { m_fActualDelay = _delay; }
	//ab hier nicht mehr von Stephan Weber

private:
	SDL_Surface*	m_pSurface = nullptr;
	SDL_Texture*	m_pTexture = nullptr;

	std::string		m_sFilename = M_SZ_FILENAME;

	/*-----------------------------------------------------------------------*/
	//ab hier von Marcus Schaal
	// m_iWidth, m_iHeight und m_Position von Marcus Schaal entfernt
	//Konstanten
	const float			M_F_ROTATION_ANGLE = 0.0f; //von RH, von MS zu const
	const std::string	M_SZ_FILENAME  = "";
	const int			M_I_DEFAULT_VALUE  = 0;
	const float			M_F_DEFAULT_DELAY  = 0.5f;
	const float			M_F_ACTUAL_DELAY   = 2.0f;
	const float			M_F_ACTUAL_DELAY_FAILED = 0.0f;

	const int			M_I_SPRITE_SUCCESS = 0;
	const int			M_I_INIT_RETURN_STEP1 = -1;
	const int			M_I_INIT_RETURN_STEP2 = -2;
	const int			M_I_FAIL_RETURN = 0;

	const Uint8			M_I_COLOR_KEY_R = 255;
	const Uint8			M_I_COLOR_KEY_G = 0;
	const Uint8			M_I_COLOR_KEY_B = 255;

	const int			M_I_ACTUAL_FRAME_INIT = 0;
	const float			M_F_POS_INIT = 0;

	const int			M_I_SDL_RECT_Y = 0;
	// m_center von Marcus Schaal entfernt
	//bis hier von Marcus Schaal
	/*-----------------------------------------------------------------------*/
	bool			m_bActive = false;

	// Animation
	bool			m_bPlayable = true;
	int				m_iNumFrames = M_I_DEFAULT_VALUE;
	int				m_iActualFrame = M_I_DEFAULT_VALUE;
	float			m_fDefaultDelay = M_F_DEFAULT_DELAY;//SM&SW Werte angepasst
	float			m_fActualDelay = M_F_ACTUAL_DELAY;//SM&SW Werte angepasst

	//m_Collision von Marcus Schaal entfernt
};

//IsColliding von Marcus Schaal entfernt

