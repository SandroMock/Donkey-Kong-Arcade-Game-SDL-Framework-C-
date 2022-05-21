/*****************************************************************************
* Project: SDLFramework
* File   : GameObject.h
* Date   : 15.01.2019
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	15.01.20	MS	Created
*	26.02.20	MS	Transform-Pointer & Initialize/Finalize hinzugefügt
*	01.03.20	MS	Inline hinzugefügt
******************************************************************************/
#pragma once
#include "Transform.h"


class CGameObject
{
public:
	/*************************************************************************/
	// Getter/Setter
	/*************************************************************************/
	/*-----------------------------------------------------------------------*/
	//Ab hier wie in Ralf Hüwes Sprite.h + inline hinzugefügt

	inline void SetPositionX(float _x) { m_pTransform->SetPositionX(_x); }
	inline void SetPositionY(float _y) { m_pTransform->SetPositionY(_y); }
	inline float GetPositionX() { return m_pTransform->GetPositionX(); }
	inline float GetPositionY() { return m_pTransform->GetPositionY(); }

	inline void SetPosition(float _x, float _y)
	{
		m_pTransform->SetPosition(_x, _y);
	}

	inline void SetPosition(Vector _pt) { m_pTransform->SetPosition(_pt); }
	inline Vector GetPosition() { return m_pTransform->GetPosition(); }

	inline void IncPositionX(float _delta) 
	{ 
		m_pTransform->IncPositionX(_delta); 
	}

	inline void IncPositionY(float _delta) 
	{ 
		m_pTransform->IncPositionY(_delta); 
	}

	inline void IncPosition(float _deltax, float _deltay)
	{
		m_pTransform->IncPosition(_deltax, _deltay);
	}

	inline void IncPosition(Vector _delta) 
	{ 
		m_pTransform->IncPosition(_delta); 
	}

	//bis hier wie in Ralf Hüwes Sprite.h
	/*------------------------------------------------------------------------*/

	//Größe  (von Marcus Schaal)
	inline int GetWidth() { return m_pTransform->GetWidth(); }
	inline int GetHeight() { return m_pTransform->GetHeight(); }

	inline void SetWidth( int _w ) { m_pTransform->SetWidth(_w); }
	inline void SetHeight( int _h ) { m_pTransform->SetHeight(_h); }
	inline void SetSize( int _w, int _h )
	{
		m_pTransform->SetSize(_w, _h);
	}

	//Mittelpunkt
	inline int GetCenterX() { return m_pTransform->GetCenterX(); }
	inline int GetCenterY() { return m_pTransform->GetCenterY(); }
	inline SDL_Point GetCenter() { return m_pTransform->GetCenter(); }

	inline void SetCenterX( int _x ) { m_pTransform->SetCenterX(_x); }
	inline void SetCenterY( int _y ) { m_pTransform->SetCenterY(_y); }
	inline void SetCenter( int _x, int _y )
	{
		m_pTransform->SetCenter( _x, _y );
	}
	/*************************************************************************/

	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	int Initialize();
	void Finalize();
	/*************************************************************************/

	/*************************************************************************/
	//Attribute
	/*************************************************************************/
private:
	//Komponenten
	CTransform*	m_pTransform = nullptr;

protected:
	const int	I_SUCCESS = 0;
	/*************************************************************************/
};