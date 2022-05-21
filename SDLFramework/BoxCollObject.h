/*****************************************************************************
* Project: SDLFramework
* File   : BoxCollObject.h
* Date   : 26.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	26.02.20	MS	Created
*	01.03.20	MS	Getter/Setter hinzugefügt
******************************************************************************/
#pragma once
#include "GameObject.h"
#include "BoxCollider.h"

class CBoxCollObject :
	public CGameObject
{
public:
	/*************************************************************************/
	// Getter/Setter
	/*************************************************************************/
	//Getter
	inline int GetTopLeftX() { return m_pBoxCollider->GetTopLeftX(); }
	inline int GetBottomRightX() { return m_pBoxCollider->GetBottomRightX(); }
	inline Point GetTopLeft() { return m_pBoxCollider->GetTopLeft(); }
	inline Point GetBottomRight() { return m_pBoxCollider->GetBottomRight(); }
	inline Rect GetBoundingBox() { return m_pBoxCollider->GetBoundingBox(); }

	inline CBoxCollider& GetCollider() //Collider
	{
		return *m_pBoxCollider;
	}


	//Setter
	inline void SetTopLeftX( int _x ) { m_pBoxCollider->SetTopLeftX( _x ); }
	inline void SetTopLeftY( int _y ) { m_pBoxCollider->SetTopLeftX( _y ); }
	inline void SetBottomRightX( int _x ) 
	{ 
		m_pBoxCollider->SetBottomRightX( _x ); 
	}

	inline void SetBottomRightY( int _y ) 
	{ 
		m_pBoxCollider->SetBottomRightY( _y ); 
	}

	inline void SetTopLeft( Point _topLeft )
	{
		m_pBoxCollider->SetTopLeft( _topLeft );
	}

	inline void SetBottomRight( Point _bottomRight )
	{
		m_pBoxCollider->SetBottomRight( _bottomRight );
	}

	inline void SetBoundingBox( Rect _boundingBox )
	{
		m_pBoxCollider->SetBoundingBox( _boundingBox );
	}
	/*************************************************************************/

	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	int Initialize( float _x, float _y, int _w, int _h );
	void Finalize();
	/*************************************************************************/

private:
	/*************************************************************************/
	//Attribute
	/*************************************************************************/
	//Komponenten
	CBoxCollider* m_pBoxCollider = nullptr;
	/*************************************************************************/
};