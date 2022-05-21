/*****************************************************************************
* Project: SDLFramework
* File   : CircCollObject.h
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
******************************************************************************/
#include "CircCollObject.h"



/*****************************************************************************/
//Initialisierung
/*****************************************************************************/
int CCircCollObject::Initialize( float _x, float _y, int _w, int _h )
{
	CGameObject::Initialize();

	SetPosition( _x, _y );
	SetSize( _w, _h );

	m_pCircleCollider = new CCircleCollider();
	m_pCircleCollider->Initialize( GetPositionX(), GetPositionY(), 
								   GetWidth(), GetHeight() );
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Update
/*****************************************************************************/
int CCircCollObject::Update()
{
	m_pCircleCollider->Update( GetPositionX(), GetPositionY(), 
							   GetWidth(), GetHeight() );
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CCircCollObject::Finalize()
{
	FINALIZE_DELETE( m_pCircleCollider );
	CGameObject::Finalize();
}
/*****************************************************************************/