/*****************************************************************************
* Project: SDLFramework
* File   : Game.h
* Date   : 18.12.2019
* Author : Ralf Hüwe (RH)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	18.12.19	RH	Created
*	29.01.20	MS	Fenster auf 1024x768
******************************************************************************/
#pragma once

const int SCREENWIDTH = 1024;
const int SCREENHEIGHT = 768;

class CGame
{
public:
	int Initialize();
	int Run();
	void Finalize();

private:
	int Update();
	void Render();

private:
	bool m_bRunning = false;
};

