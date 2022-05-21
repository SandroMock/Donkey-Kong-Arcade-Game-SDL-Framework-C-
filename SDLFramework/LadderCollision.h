/*****************************************************************************
* Project: SDLFramework
* File   : LadderCollision.h
* Date   : 28.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	28.02.20	MS	Created, auskommentierte Funktionen entfernt
*	29.02.20	MS	Funktion mit CCircCollObject als Parameter erstellt und
*					CBarrel & CFlame-Funktionen entfernt
*	01.03.20	MS	CPlayer-Funktionen entfernt
*	03.03.20	MS  _setCirclePos als Parameter entfernt,
*					Ins Reine geschrieben, 
*					IsBarrelLadderColl nach ebenen aufgeteilt,
*					Spieler-Leiter-Kollisionen nach CPlayerLadderColl 
*					ausgelagert
*					Fass-Leiter-Kollisionen nach CPlayerLadderColl ausgelagert
*					Flammen-Leiter-Kollisionen nach CPlayerLadderColl 
*					ausgelagert
*					Datei von LevelCollision in LadderCollision umbenannt
******************************************************************************/
#pragma once
#include "CircCollObject.h"
#include "Level.h"

const int I_DEFAULT_BOX = 0;

/*****************************************************************************/
//Kollision mit Plattform- und Leiter-Array-Indexen
/*****************************************************************************/
//Plattform
bool IsPlatformIdx( int _arBegin, int _arEnd, CCircCollObject& _gameObj,
				    CLevel& _level );

//linke Hälfte der Plattform
bool IsPlatformIdxLHalf( int _arBegin, int _arEnd, CCircCollObject& _gameObj,
						 CLevel& _level, int _topLeftX = I_DEFAULT_BOX,
						 int _topLeftY = I_DEFAULT_BOX,
						 int _bottomRightX = I_DEFAULT_BOX,
						 int _bottomRightY = I_DEFAULT_BOX);

//rechte Hälfte der Plattform
bool IsPlatformIdxRHalf( int _arBegin, int _arEnd, CCircCollObject& _gameObj,
						 CLevel& _level, int _topLeftX = I_DEFAULT_BOX,
						 int _topLeftY = I_DEFAULT_BOX,
						 int _bottomRightX = I_DEFAULT_BOX,
						 int _bottomRightY = I_DEFAULT_BOX);

//Leiter
bool IsLadderIdx( int _arBegin, int _arEnd, CCircCollObject& _gameObj,
				  CLevel& _level, int _topLeftX = I_DEFAULT_BOX,
				  int _topLeftY = I_DEFAULT_BOX,
				  int _bottomRightX = I_DEFAULT_BOX,
				  int _bottomRightY = I_DEFAULT_BOX);
/*****************************************************************************/