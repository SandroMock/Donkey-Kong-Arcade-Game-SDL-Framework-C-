/*****************************************************************************
* Project: SDLFramework
* File   : GamestateLogo.h
* Date   : 26.02.2020
* Author : Stephan Weber (SW)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	26.02.2020	SW	Created
******************************************************************************/
#pragma once
#include "Gamestate.h"
#include "StartAnimation.h"
#include "Game.h"
#include "Utils.h"
#include "UIPanel.h"

class CGamestateStartAnimation : public CGamestate
{
public:
	CGamestateStartAnimation() { m_sName = "startAnimation"; }

	int Initialize();
	void Finalize();
	int Update();
	void Render();

private:

	CStartAnimation* m_pStartAnimation = nullptr;

	CUIPanel* m_pUIPanel = nullptr;
};

