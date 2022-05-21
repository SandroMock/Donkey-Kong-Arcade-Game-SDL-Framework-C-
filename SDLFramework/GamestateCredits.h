/*****************************************************************************
* Project: SDLFramework
* File   : GamestateCredits.h
* Date   : 22.01.2020
* Author : Ralf H�we (RH)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	22.01.20	RH	Created
******************************************************************************/
#pragma once
#include "Sprite.h"
#include "Gamestate.h"

class CGamestateCredits : public CGamestate
{
public:
	CGamestateCredits() { m_sName = "credits"; }

	int Initialize();
	void Finalize();

	int Update();
	void Render();

private:
	CSprite*	m_pBackground = nullptr;
	CSprite*	m_pCredits = nullptr;
};

