/*****************************************************************************
* Project: SDLFramework
* File   : GameObject.cpp
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
*	26.02.20	MS	Initialize/Finalize für Transform-Pointer
******************************************************************************/
#include "GameObject.h"
#include "Defines.h"


/*****************************************************************************/
//Initialisierung
/*****************************************************************************/
int CGameObject::Initialize()
{
	m_pTransform = new CTransform();
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CGameObject::Finalize()
{
	SAFE_DELETE( m_pTransform );
}
/*****************************************************************************/