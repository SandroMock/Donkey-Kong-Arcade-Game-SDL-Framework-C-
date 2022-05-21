/*****************************************************************************
* Project: SDLFramework
* File   : BoxCollObject.cpp
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
#include "BoxCollObject.h"



/*****************************************************************************/
//Initialisierung
/*****************************************************************************/
int CBoxCollObject::Initialize( float _x, float _y, int _w, int _h )
{
	CGameObject::Initialize();

	SetPosition( _x, _y );
	SetSize( _w, _h );

	m_pBoxCollider = new CBoxCollider();
	m_pBoxCollider->Initialize( GetPositionX(), GetPositionY(), 
								GetWidth(), GetHeight() );
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CBoxCollObject::Finalize()
{
	FINALIZE_DELETE( m_pBoxCollider );
	CGameObject::Finalize();
}
/*****************************************************************************/