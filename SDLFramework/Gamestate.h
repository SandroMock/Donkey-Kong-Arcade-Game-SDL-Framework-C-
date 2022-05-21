/*****************************************************************************
* Project: SDLFramework
* File   : Gamestate.h
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
#include <list>

class CGamestate
{
public:
	CGamestate();
	virtual ~CGamestate();

	// Rein virtuelle Methoden (Pure virtual methods)
	// Sobald eine Klasse eine rein virtuelle Methode hat ist sie automatisch
	// 'abstract'.
	virtual int Initialize() = 0;
	virtual void Finalize() = 0;

	virtual int Update() = 0;
	virtual void Render() = 0;

	std::string GetName() { return m_sName; }

protected:
	std::string	m_sName = "-";
};

// Datentyp deklarieren
typedef std::list<CGamestate*> Gamestates;
typedef Gamestates::iterator GamestatesItr;
