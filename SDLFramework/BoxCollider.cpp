/*****************************************************************************
* Project: SDLFramework
* File   : BoxCollider.cpp
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
*	11.02.20	MS	Initialize bearbeitet
*	12.02.20	MS	Ins Reine geschrieben
*	01.03.20	MS	Literale entfernt
******************************************************************************/
#include "BoxCollider.h"
#include "Engine.h"
#include "ComponentConfig.h"


/*****************************************************************************/
//Initialisierung
/*****************************************************************************/
int CBoxCollider::Initialize( float _x, float _y, int _w, int _h )
{
	CCollider::Initialize( _x, _y, _w, _h );

	//Kollisionsbox
	m_Collision.topLeft.x = 
		static_cast<int>( m_Position.x - m_iWidth / I_DOUBLE );
	m_Collision.topLeft.y = 
		static_cast<int>( m_Position.y - m_iHeight / I_DOUBLE );
	m_Collision.bottomRight.x = 
		static_cast<int>( m_Position.x + m_iWidth / I_DOUBLE );
	m_Collision.bottomRight.y = 
		static_cast<int>( m_Position.y + m_iHeight / I_DOUBLE );

	return I_SUCCESS;
}
/*****************************************************************************/


/*****************************************************************************/
//Update
/*****************************************************************************/
int CBoxCollider::Update( float _x, float _y, int _w, int _h )
{
	CCollider::Update( _x, _y, _w, _h );

	//Kollisionsbox
	m_Collision.topLeft.x = 
		static_cast<int>( m_Position.x - m_iWidth / I_DOUBLE );
	m_Collision.topLeft.y = 
		static_cast<int>( m_Position.y - m_iHeight / I_DOUBLE );
	m_Collision.bottomRight.x = 
		static_cast<int>( m_Position.x + m_iWidth / I_DOUBLE );
	m_Collision.bottomRight.y = 
		static_cast<int>( m_Position.y + m_iHeight / I_DOUBLE );

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CBoxCollider::Finalize()
{
	CCollider::Finalize();
	m_Collision.topLeft.x = NULL;
	m_Collision.topLeft.y = NULL;
	m_Collision.bottomRight.x = NULL;
	m_Collision.bottomRight.y = NULL;
}
/*****************************************************************************/