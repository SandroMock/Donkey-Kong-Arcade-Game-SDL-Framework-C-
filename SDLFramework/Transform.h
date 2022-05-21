/*****************************************************************************
* Project: SDLFramework
* File   : Transform.h
* Date   : 25.02.2019
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	25.02.20	MS	Created
*	26.02.20	MS	Inline hinzugefügt
******************************************************************************/
#pragma once

/*---------------------------------------------------------------------------*/
//Ab hier wie in Ralf Hüwes Sprite.h 
#include <SDL.h>
#include "types.h"
//Bis hier wie in Ralf Hüwes Sprite.h
/*---------------------------------------------------------------------------*/

const int I_DEFAULT_WIDTH = -1; 
const int I_DEFAULT_HEIGHT = -1;
const int I_DEFAULT_POS = -1;
const float F_DEFAULT_POS = -1.0f;

class CTransform
{
public:
	/*************************************************************************/
	// Getter/Setter
	/*************************************************************************/
	/*-----------------------------------------------------------------------*/
	//Ab hier wie in Ralf Hüwes Sprite.h + inline hinzugefügt

	// Position
	inline void SetPositionX(float _x) { m_Position.x = _x; }
	inline void SetPositionY(float _y) { m_Position.y = _y; }
	inline float GetPositionX() { return m_Position.x; }
	inline float GetPositionY() { return m_Position.y; }
	inline void SetPosition(float _x, float _y)
	{
		m_Position.x = _x;
		m_Position.y = _y;
	}
	inline void SetPosition(Vector _pt) { SetPosition(_pt.x, _pt.y); }
	inline Vector GetPosition() { return m_Position; }
	inline void IncPositionX(float _delta) { m_Position.x += _delta; }
	inline void IncPositionY(float _delta) { m_Position.y += _delta; }
	inline void IncPosition(float _deltax, float _deltay)
	{
		m_Position.x += _deltax;
		m_Position.y += _deltay;
	}
	inline void IncPosition(Vector _delta) { IncPosition(_delta.x, _delta.y); }

	//Bis hier wie in Ralf Hüwes Sprite.h
	/*------------------------------------------------------------------------*/

	//Größe  (von Marcus Schaal)
	inline int GetWidth() { return m_iWidth; }
	inline int GetHeight() { return m_iHeight; }

	inline void SetWidth( int _w ) { m_iWidth = _w; }
	inline void SetHeight( int _h ) { m_iHeight = _h; }
	inline void SetSize( int _w, int _h )
	{
		m_iWidth = _w;
		m_iHeight = _h;
	}

	//Mittelpunkt
	inline int GetCenterX() { return m_center.x; }
	inline int GetCenterY() { return m_center.y; }
	inline SDL_Point GetCenter() { return m_center; }

	inline void SetCenterX( int _x ) { m_center.x = _x; }
	inline void SetCenterY( int _y ) { m_center.y = _y; }
	inline void SetCenter( int _x, int _y )
	{
		m_center.x = _x;
		m_center.y = _y;
	}
	/*************************************************************************/

protected:
	/*************************************************************************/
	//Attribute
	/*************************************************************************/
	/*-----------------------------------------------------------------------*/
	//Ab hier wie in Ralf Hüwes Sprite.h
	int				m_iWidth = I_DEFAULT_WIDTH;
	int				m_iHeight = I_DEFAULT_HEIGHT;
	Vector			m_Position = { F_DEFAULT_POS, F_DEFAULT_POS };
	SDL_Point		m_center = { I_DEFAULT_POS, I_DEFAULT_POS };

	//Bis hier wie in Ralf Hüwes Sprite.h
	/*-----------------------------------------------------------------------*/
	/*************************************************************************/
};