/*****************************************************************************
* Project: SDLFramework
* File   : WinArea.h
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
#pragma once
#include "GameObject.h"
#include "BoxCollider.h"
class CWinArea :
	public CGameObject
{
public:
	CWinArea();
	~CWinArea();

	inline CBoxCollider& GetCollider()
	{
		return *m_pBoxCollider;
	}

	int Initialize(float _x, float _y);
	void Finalize();

private:
	CBoxCollider* m_pBoxCollider = nullptr;
};

