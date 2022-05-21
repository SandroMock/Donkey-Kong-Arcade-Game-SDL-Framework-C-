/*****************************************************************************
* Project: SDLFramework
* File   : CircleCollider.cpp
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
*	01.03.20	MS	Literale entfernt
******************************************************************************/
#include "CircleCollider.h"
#include "ComponentConfig.h"




/*****************************************************************************/
//Initialisierung
/*****************************************************************************/
int CCircleCollider::Initialize( float _x, float _y, int _w, int _h )
{
	CCollider::Initialize( _x, _y, _w, _h );

	/*-----------------------------------------------------------------------*/
	//Ab hier wie in Ralf Hüwes Sprite.cpp

	// Kollisionskreis
	m_Collision.position = m_Position;
	//MS: Literal in folgender Zeile entfernt
	m_Collision.radius = Lesser(m_iWidth, m_iHeight) / F_DOUBLE;
	m_fCollisionRadius = m_Collision.radius;
	//Bis hier wie in Ralf Hüwes Sprite.cpp
	/*-----------------------------------------------------------------------*/
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CCircleCollider::Finalize()
{
	CCollider::Finalize();

	m_Collision.position.x = NULL;
	m_Collision.position.y = NULL;
	m_Collision.radius = NULL;
	m_fCollisionRadius = NULL;
}
/*****************************************************************************/

/*****************************************************************************/
//Update
/*****************************************************************************/
int CCircleCollider::Update( float _x, float _y, int _w, int _h )
{
	CCollider::Update( _x, _y, _w, _h );

	/*-----------------------------------------------------------------------*/
	//Ab hier wie in Ralf Hüwes Sprite.cpp

	// Kollisionskreis
	m_Collision.position = m_Position;
	//MS: Literal in folgender Zeile entfernt
	m_Collision.radius = Lesser(m_iWidth, m_iHeight) / F_DOUBLE; 
	m_fCollisionRadius = m_Collision.radius;
	//Bis hier wie in Ralf Hüwes Sprite.cpp
	/*-----------------------------------------------------------------------*/
	return I_SUCCESS;
}
/*****************************************************************************/