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
*	18.02.20	MS	Überladungen für (selektive) Box-Schwerkraft mit CPlayer,
*					das selbe für Leiterkollision (kleine und große Leitern),
*					Überlappungen
*	19.02.20	MS	Überlappungen(schräge Flächen hochlaufen) funktionsfähig,
*					(selektive) Kreis-Schwerkraft für Spieler realisiert,
*					Überlappungen für Kreis-Collider
*					Spieler-Leiter-Kollisionen für Kreis-Collider
*	20.02.20	MS	Schwerkraft für Fässer
*	21.02.20	MS	Selektive Schwerkraft für Flammen,
*					Schräg hochlaufen für Flammen,
*					Kreis-Kreis-Kollision-Überladung mit Kreis-Collidern,
*					Spieler-Fass-Kollision und Spieler-Flamme-Kollision als
*					Überladung realisiert, 
*					Kollision mit rechter und linker Level-Begrenzung 
*					für Spieler realisiert,
*					Spieler-WinArea-Kollision realisiert,
*					Parameter von Kreis-Box-Kollisionen und 
*					Box-Box-Kollisionen von Pointern zu Referenzen
*	24.02.20	MS	Parameter von Kreis-Kreis-Kollisionen von Pointern zu
*					Parametern, das selbe für Kreis-Box-Überlappungen,
*					Plattform-Array-Funktionen für Fässer bekommen Parameter
*					um TopLeft/BottomRight ihres Colliders zu verändern
*					(+ Vorinitialisierungen),
*					Spieler-Hammer-Kollision
*	25.02.20	MS	Kollisionen mit CSprite als Parameter entfern,
*					+Flamme-Leiter-Kollision, 
*					+PlattformArray-Funkionen für Flammen-Leiter-Kollision,
					Leiteraussparungs-Array-Funktionen hinzugefügt
*	26.02.20	MS	Alle Schwerkraftformen außer selektiver Kreisschwerkraft
*					gelöscht,
*					Schwerkraft nach CGravity ausgelagert
*	27.02.20	MS	Plattform/Leiter-Array-Funktionen bekommen Parameter um
*					TopLeft/BottomRight zu verschieben
*	28.02.20	MS	Überlappungs-Funktionen nach Overlap.h ausgelagert,
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
/*Folgende Funktion (übernächste Zeile) ist aus Ralf Hüwes CSprite übernommen,
* und dem Kreis-Collider angepasst */
bool IsCircColl( CCircleCollider& _1st, CCircleCollider& _2nd ); 

//Kreis-Box-Kollision
bool IsCircRectColl( CCircleCollider& _pCircleColl, Rect _rc);
bool IsCircRectColl( CCircleCollider& _pCircleColl, CBoxCollider& _pBoxColl);
/*****************************************************************************/