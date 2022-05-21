/*****************************************************************************
* Project: SDLFramework
* File   : GamestateManager.h
* Date   : 22.01.2020
* Author : Ralf Hüwe (RH)
*		   Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	22.01.20	RH	Created
*	06.03.20	MS	Literale entfernt
******************************************************************************/
#pragma once
#include <list>
#include <string>
#include "Gamestate.h"

const int I_GS_MANAGER_SUCCESS = 0; //MS

class CGamestateManager
{
public:
	static void ChangeGamestate( std::string _which );
	static CGamestate& GetActiveGamestate();
	static void AddGamestate( CGamestate* _pgamestate )
	{
		m_pGamestates.push_back( _pgamestate );
	}
	static int Initialize();
	static void Finalize();
	static int Update();
	static void Render();

private:
	static Gamestates m_pGamestates;
	static CGamestate* m_pActiveGamestate;
};

