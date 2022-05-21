/*****************************************************************************
* Project: SDLFramework
* File   : Collision.h
* Date   : 10.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	10.02.20	MS	Created,
*				MS	Rect zu CBoxCollider
*	11.02.20	MS	Box-Collider zu Pointer
*	12.02.20	MS	Box-Schwerkraft _setBoxPos entfernt
*	17.02.20	MS	Selektive Box-Schwerkraft, Schwerkraft-Physik,
*					Plattform-STAGE-Enum
*	18.02.20	MS	�berladungen f�r (selektive) Box-Schwerkraft mit CPlayer,
*					das selbe f�r Leiterkollision (kleine und gro�e Leitern),
*					�berlappungen
*	19.02.20	MS	�berlappungen(schr�ge Fl�chen hochlaufen) funktionsf�hig,
*					(selektive) Kreis-Schwerkraft f�r Spieler realisiert,
*					�berlappungen f�r Kreis-Collider
*					Spieler-Leiter-Kollisionen f�r Kreis-Collider
*	20.02.20	MS	Schwerkraft f�r F�sser
*	21.02.20	MS	Selektive Schwerkraft f�r Flammen,
*					Schr�g hochlaufen f�r Flammen,
*					Kreis-Kreis-Kollision-�berladung mit Kreis-Collidern,
*					Spieler-Fass-Kollision und Spieler-Flamme-Kollision als
*					�berladung realisiert, 
*					Kollision mit rechter und linker Level-Begrenzung 
*					f�r Spieler realisiert,
*					Spieler-WinArea-Kollision realisiert,
*					Parameter von Kreis-Box-Kollisionen und 
*					Box-Box-Kollisionen von Pointern zu Referenzen
*	24.02.20	MS	Parameter von Kreis-Kreis-Kollisionen von Pointern zu
*					Parametern, das selbe f�r Kreis-Box-�berlappungen,
*					Plattform-Array-Funktionen f�r F�sser bekommen Parameter
*					um TopLeft/BottomRight ihres Colliders zu ver�ndern
*					(+ Vorinitialisierungen),
*					Spieler-Hammer-Kollision
*	25.02.20	MS	Kollisionen mit CSprite als Parameter entfern,
*					+Flamme-Leiter-Kollision, 
*					+PlattformArray-Funkionen f�r Flammen-Leiter-Kollision,
					Leiteraussparungs-Array-Funktionen hinzugef�gt
*	26.02.20	MS	Alle Schwerkraftformen au�er selektiver Kreisschwerkraft
*					gel�scht,
*					Schwerkraft nach CGravity ausgelagert
*	27.02.20	MS	Plattform/Leiter-Array-Funktionen bekommen Parameter um
*					TopLeft/BottomRight zu verschieben
*	28.02.20	MS	�berlappungs-Funktionen nach Overlap.h ausgelagert,
*					Plattform- und Leiter-Array-Kollisionen nach 
*					LevelCollision.h ausgelagert
*	29.02.20	MS	Funktion mit CCircCollObject als Parameter erstellt und
*					CBarrel & CFlame-Funktionen entfernt
*	01.03.20	MS	CPlayer-Funktionen entfernt
*	02.03.20	MS	Auskommentiertes entfernt, mehr Kommentar, 
*					Literale entfernt
*	03.03.20	MS	Box-Box-Kollider entfernt,
*					_setCirclePos als Parameter entfernt
******************************************************************************/
#pragma once
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "LevelConfig.h"


/*****************************************************************************/
//Kollisionen
/*****************************************************************************/
//Kreis-Kreis-Kollision
/*Folgende Funktion (�bern�chste Zeile) ist aus Ralf H�wes CSprite �bernommen,
* und dem Kreis-Collider angepasst */
bool IsCircColl( CCircleCollider& _1st, CCircleCollider& _2nd ); 

//Kreis-Box-Kollision
bool IsCircRectColl( CCircleCollider& _pCircleColl, Rect _rc);
bool IsCircRectColl( CCircleCollider& _pCircleColl, CBoxCollider& _pBoxColl);
/*****************************************************************************/