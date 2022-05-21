/*****************************************************************************
* Project: SDLFramework
* File   : GamestateLogo.h
* Date   : 22.01.2020
* Author : Ralf Hüwe (RH)
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
#include "Defines.h"

class CGamestateLogo : public CGamestate
{
public:
	CGamestateLogo() { m_sName = "logo"; }

	int Initialize();
	void Finalize();

	int Update();
	void Render();

private:
	enum STATE { PUBLISHER, STUDIO };
	CSprite*	m_pLogoPublisher = nullptr;
	CSprite*	m_pLogoStudio = nullptr;
	STATE		m_state = PUBLISHER;
	float		m_fActualTimer = -1.0f;
	float		m_fPublisherDisplayTime = 1.0f;
	float		m_fStudioDisplayTime = 2.0f;

	std::string m_szLogoPublisher = "Assets\\Dev\\Publisher_1024x768_f1.bmp";
	std::string m_szLogoStudio = "Assets\\Dev\\Studio_1024x768_f1.bmp";
	std::string m_szMenuGamestate = "controls";
};

