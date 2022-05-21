/*****************************************************************************
* Project: SDLFramework
* File   : LadderRecess.cpp
* Date   : 25.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	25.02.20	MS	Created
******************************************************************************/
#include "LadderRecess.h"



CLadderRecess::CLadderRecess()
{
}


CLadderRecess::~CLadderRecess()
{
}

int CLadderRecess::Initialize(float _x, float _y)
{
	int width = 16;
	int height = 16;

	m_pBoxCollider = new CBoxCollider();
	m_pBoxCollider->Initialize(_x, _y, width, height);

	return 0;
}

void CLadderRecess::Finalize()
{
	SAFE_DELETE(m_pBoxCollider);
}
