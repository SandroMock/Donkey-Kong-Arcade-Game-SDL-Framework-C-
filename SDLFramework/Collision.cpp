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
*					Rect durch CBoxCollider ersetzt,
*					CBoxCollider zu Pointer verändert
*	11.02.20	MS	CBoxCollider* ausgearbeitet
*	12.02.20	MS	CBoxCollider-Getter von Level hinzugefügt,
*					Collider-Pointer in Box-BoxKollisionen zu Collider,
*					Zeug ins Reine geschrieben
*	13.02.20	MS	Kreis durch KreisCollider ersetzt
*	17.02.20	MS	LevelConfig eingebunden, Leiter & Plattform const int
*					Selektive Box-Schwerkraft, Schwerkraft-Physik
*	18.02.20	MS	(selektive) Box-Schwerkraft, Leiterkollision für Player,
*					Überlappungen
*	19.02.20	MS	Überlappungen(schräge Flächen hochlaufen) funktionsfähig
*	25.02.20	MS	Spieler-Boden-Kollision in Spieler-Schwerkraft hinzugefügt
*	27.02.20	MS	Kaputte Leitern komplett aus Spieler-Leiter-Kollision
*					entfernt,
*					Ruckeln beim Schräg-Hochlaufen entfernt
*	28.02.20	MS	Spieler-Leiterkollision neugeschriebener Leiter angepasst,
*					Schräg hochgehen finalisiert,
*					Überlappungs-Funktionen nach Overlap.cpp ausgelagert,
*					Spieler-Leiter-Kollision: Kaputte Leitern entfernt,
*					Plattform- und Leiter-Array-Kollisionen nach 
*					LevelCollision.h ausgelagert
******************************************************************************/
#include "Collision.h"
#include "Engine.h"



/*****************************************************************************/
// Kreis-Kollision
/*****************************************************************************/
bool IsCircColl( CCircleCollider& _1st, CCircleCollider& _2nd )
{

	// Circle von Ralf Hüwe entfernt

	// Kommentar von Ralf Hüwe entfernt

	/**************************************************************************/
	// Marcus Schaal: Circle auf CCircleCollider umgeschrieben
	float squaredRadiiSum =
		_1st.GetRadius() * _1st.GetRadius() +
		_2nd.GetRadius() * _2nd.GetRadius();
	float y = _1st.GetPositionY() - _2nd.GetPositionY();
	y *= y; //Zeile bleibt gleich
	float x = _1st.GetPositionX() - _2nd.GetPositionX();
	x *= x; //Zeile bleibt gleich
	/**************************************************************************/

	return squaredRadiiSum >= y + x;
}
/*****************************************************************************/ 


/*****************************************************************************/
//Kreis-Box-Kollision
/*****************************************************************************/
bool IsCircRectColl( CCircleCollider& _pCircleColl, Rect _rc )
{
	if( ( _pCircleColl.GetPositionX() + _pCircleColl.GetRadius() ) 
		< _rc.topLeft.x ) return false;

	if( ( _pCircleColl.GetPositionX() - _pCircleColl.GetRadius() ) 
		> _rc.bottomRight.x ) return false;

	if( ( _pCircleColl.GetPositionY() + _pCircleColl.GetRadius() ) 
		< _rc.topLeft.y ) return false;

	if( ( _pCircleColl.GetPositionY() - _pCircleColl.GetRadius() ) 
		> _rc.bottomRight.y ) return false;

	return true;
}
/*****************************************************************************/

/*****************************************************************************/
//Kreis-Box-Kollision (Überladung für Kreis-Collider & Box-Collider)
/*****************************************************************************/
bool IsCircRectColl( CCircleCollider& _pCircleColl, CBoxCollider& _pBoxColl )
{
	if( ( _pCircleColl.GetPositionX() + _pCircleColl.GetRadius() ) 
		< _pBoxColl.GetTopLeft().x ) return false;

	if( ( _pCircleColl.GetPositionX() - _pCircleColl.GetRadius() ) 
		> _pBoxColl.GetBottomRight().x ) return false;

	if( ( _pCircleColl.GetPositionY() + _pCircleColl.GetRadius() ) 
		< _pBoxColl.GetTopLeft().y ) return false;

	if( ( _pCircleColl.GetPositionY() - _pCircleColl.GetRadius() ) 
		> _pBoxColl.GetBottomRight().y ) return false;

	return true;
}
/*****************************************************************************/