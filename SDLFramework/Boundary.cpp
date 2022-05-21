/*****************************************************************************
* Project: SDLFramework
* File   : Boundary.h
* Date   : 21.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	21.02.20	MS	Created
******************************************************************************/
#include "Boundary.h"



CBoundary::CBoundary()
{
}


CBoundary::~CBoundary()
{
}

int CBoundary::Initialize(float _x, float _y)
{
	int width = 288;
	int height = 768;
	
	m_pBoxCollider = new CBoxCollider();
	m_pBoxCollider->Initialize(_x, _y, width, height);

	return 0;
}

void CBoundary::Finalize()
{
	SAFE_DELETE(m_pBoxCollider);
}

//int CBoundary::Update()
//{
//	return 0;
//}
