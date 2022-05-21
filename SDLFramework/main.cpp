/*****************************************************************************
* Project: SDLFramework
* File   : main.cpp
* Date   : 18.12.2019
* Author : Ralf Hüwe (RH)
*		   Marcus Schaal (MS)
*		   Sandro Mock	(SM)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	18.12.19	RH	Created
*	06.03.20	MS	Literale entfernt, Befehlszeilenparameter entfernt
*	06.03.20	SM	Konsole ausgeschalten
******************************************************************************/
#include "Engine.h"
#include "Game.h"
/******************************************************************/
// von Evil_M auf 
// https://www.c-plusplus.net/forum/topic/334492/konsole-deaktivieren 
// am 17.09.2015 erstellt
/******************************************************************/
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
//MS: Kommentar von Ralf Hüwe entfernt
int main() //MS: Parameter entfernt
//MS: Kommentar von Ralf Hüwe entfernt
{
	CGame theGame;

	// Befehlszeilenparameter von Marcus Schaal entfernt

	int result = theGame.Initialize();
	if (result == I_INIT_SUCCESS) //MS: Literal entfernt
	{
 		result = theGame.Run();
		theGame.Finalize();
	}

	return result;
}