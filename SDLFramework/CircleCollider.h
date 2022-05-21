/*****************************************************************************
* Project: SDLFramework
* File   : CircleCollider.h
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
*	12.02.20	MS	-SetPosition, Parameter in Initialize & Update
*	25.02.20	MS	Von CCollider abgeleitet
*	01.03.20	MS	Finalize hinzugefügt
******************************************************************************/
#pragma once
#include "Collider.h"

//Werte für Vorinitialisierung
const int I_COLL_RADIUS = -1;

class CCircleCollider :
	public CCollider
{
public:
	/*************************************************************************/
	// Getter/Setter
	/*************************************************************************/
	inline float GetRadius() { return m_Collision.radius; }

	inline void SetRadius( float _radius ) { m_Collision.radius = _radius; }
	/*************************************************************************/

	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	int Initialize( float _x, float _y, int _w, int _h );
	void Finalize();
	int Update( float _x, float _y, int _w, int _h );
	/*************************************************************************/

private:

	/*-----------------------------------------------------------------------*/
	//Ab hier wie in Ralf Hüwes Sprite.h
	float			m_fCollisionRadius = I_COLL_RADIUS;
	Circle			m_Collision;
	//Bis hier wie in Ralf Hüwes Sprite.h
	/*-----------------------------------------------------------------------*/
};