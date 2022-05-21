/*****************************************************************************
* Project: SDLFramework
* File   : Collider.h
* Date   : 15.01.2019
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	15.01.20	MS	Created
*	24.01.20	MS	Parameter von Ralf Hüwes IsColliding-Methode aus Sprite.h
*					für IsCircColl übernommen, 
*					Ralf Hüwes m_Collision aus Sprite.h übernommen.
*					Initialize aus Sprite.h vorläufig ausgelagert
*	30.01.20	MS	Kreis-Box-Kollisions-Methode hinzugefügt,
*					ebenso Überladung
*	04.02.20	MS	Schwerkraftmethoden als Funktionen von Level unabhängig 
*					gemacht
*	05.02.20	MS	BoxBox-Kollision erstellt, 
*					Schwerkraft in Box und Kreis aufgeteilt
*					Leiterkollision für intakte Leitern realisiert
*					Leiterkollision für Fässer realisiert
*					Leiterkollision für alle Leitern/Flammen realisiert
*	10.02.20	MS	Funkionen Standardparameter zugewiesen,
*					Schwerkraftfunktionen in Bools umgewandelt
*					Kollisionsfunktionen nach "CCollision" ausgelagert
*					Position nach Ralf Hüwes Art in CSprite erstellt
*	11.02.20	MS	SetPosition/SetSize
*	12.02.20	MS	Initialize/Update Parameter _x, _y, _w und _h hinzugefügt
*	25.02.20	MS	Klasse von CTransform abgeleitet
*	26.02.20	MS	Methoden abstrakt gemacht
*	01.03.20	MS	Finalize hinzugefügt
*	04.03.20	MS	Setter hinzugefügt
******************************************************************************/
#pragma once
#include "Transform.h"
#include "Engine.h"
#include "Utils.h"


class CCollider :
	public CTransform  //abstrakte Klasse
{
public:
	/*************************************************************************/
	//Setter
	/*************************************************************************/
	inline float SetCollX( float _x ) { return m_CollPosition.x = _x; }
	inline float SetCollY( float _y ) { return m_CollPosition.y = _y; }
	inline void SetCollPos( float _x, float _y )
	{
		m_CollPosition = { _x, _y };
	}
	/*************************************************************************/

	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	virtual int Initialize( float _x, float _y, int _w, int _h ) = 0;
	virtual int Update( float _x, float _y, int _w, int _h ) = 0;
	virtual void Finalize() = 0;
	/*************************************************************************/
private:
	Vector			m_CollPosition = { F_DEFAULT_POS, F_DEFAULT_POS };
};