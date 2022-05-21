/*****************************************************************************
* Project: SDLFramework
* File   : Button.h
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
#include <string>
#include "Sprite.h"

enum GUIState {
	GUISTATE_NONE,
	GUISTATE_UP,
	GUISTATE_MOUSEOVER,
	GUISTATE_DOWN,
	GUISTATE_INACTIVE
};

// delegate = funktionspointer
typedef void(*ButtonCB)(int);

class CButton
{
public:
	CButton() { m_iID = m_iNextID++; }
	int Initialize(std::string _filename, Vector& _pos);
	void Finalize();
	int Update();
	void Render();
	void RegisterCallback(ButtonCB _proc) { m_pProc = _proc; }

private:
	CSprite*	m_pSprite = nullptr;
	GUIState	m_state = GUISTATE_NONE;
	ButtonCB	m_pProc = nullptr;
	int			m_iID;
	static int	m_iNextID;
};

