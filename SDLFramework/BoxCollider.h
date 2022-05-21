/*****************************************************************************
* Project: SDLFramework
* File   : BoxCollider.h
* Date   : 10.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	10.02.20	MS	Created
*	11.02.20	MS	Initialize Parameter
*	12.02.20	MS	Ins Reine geschrieben
*	01.03.20	MS	Finalize hinzugefügt
*	02.03.20	MS	Werte für Vorinitialisierungen
******************************************************************************/
#pragma once
#include "Collider.h"

//Werte für Vorinitialisierung
const int COLL_POS = -1;

class CBoxCollider :
	public CCollider
{
public:
	/*************************************************************************/
	// Getter/Setter
	/*************************************************************************/
	//Getter
	inline int GetTopLeftX() { return m_Collision.topLeft.x; }
	inline int GetBottomRightX() { return m_Collision.bottomRight.x; } 
	inline Point GetTopLeft() { return m_Collision.topLeft; }
	inline Point GetBottomRight() { return m_Collision.bottomRight;	}
	inline Rect GetBoundingBox() { return m_Collision; }


	//Setter
	inline void SetTopLeftX( int _x ) { m_Collision.topLeft.x = _x; }
	inline void SetTopLeftY( int _y ) { m_Collision.topLeft.y = _y; }
	inline void SetBottomRightX( int _x ) { m_Collision.bottomRight.x = _x; }
	inline void SetBottomRightY( int _y ) { m_Collision.bottomRight.y = _y; }

	inline void SetTopLeft( Point _topLeft ) 
	{ 
		m_Collision.topLeft = _topLeft; 
	}

	inline void SetBottomRight( Point _bottomRight ) 
	{ 
		m_Collision.bottomRight = _bottomRight; 
	}

	inline void SetBoundingBox( Rect _boundingBox ) 
	{ 
		m_Collision = _boundingBox; 
	}
	/*************************************************************************/

	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	int Initialize( float _x, float _y, int _w, int _h );
	int Update( float _x, float _y, int _w, int _h );
	void Finalize();
	/*************************************************************************/

private:
	/*************************************************************************/
	//Attribute
	/*************************************************************************/
	Rect m_Collision = { Point{COLL_POS, COLL_POS}, 
						 Point{COLL_POS, COLL_POS} };
	/*************************************************************************/
};