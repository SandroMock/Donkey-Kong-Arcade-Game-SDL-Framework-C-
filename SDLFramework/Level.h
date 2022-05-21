/*****************************************************************************
* Project: SDLFramework
* File   : Level.h
* Date   : 14.01.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	14.01.20	MS	Created, von CScene abgeleitet,
*					CLadder und Child-Classes hinzugefügt
*	15.01.20	MS	DefaultObject hinzugefügt,
*					Update-Methode hinzugefügt
*	16.01.20	MS	7 Leiter-Klassen zu Einer vereinfacht,
*					(Child-Classes entfernt)
*	23.01.20	MS	Schwerkraft-Methode hinzugefügt
*	30.01.20	MS	Schwerkraft-Überladungen hinzugefügt
*					InitLadder-Methode hinzugefügt
*	03.02.20	MS	InitLadder-Überladung hinzugefügt,
*					InitAllLadders-Methode hinzugefügt,
*					InitPlatform-Methoden hinzugefügt,
*	04.02.20	MS	Plattform-Getter hinzugefügt
*	06.02.20	MS	Leitern vereinfacht
*	11.02.20	MS	Collider Getter
*	17.02.20	MS	LevelConfig eingebunden, Array-Size aus LevelConfig
*	21.02.20	MS	Siegbereich & Begrenzungen als Pointer hinzugefügt
*	25.02.20	MS	Leiteraussparungen als Pointer hinzugefügt
*	26.02.20	MS	Tiles-Klassen zu Plattform und Leiter
*	01.03.20	MS	CScene + DefaultObject entgültig entfernt
*	02.03.20	MS	Literale entfernt
*	03.03.20	MS	Getter für Sprite-Bounding-Box von Level-Objekten entfernt
******************************************************************************/
#pragma once
#include "Platform.h"
#include "Ladder.h"
#include "BoxCollObject.h"
#include "LevelConfig.h"


//Nullpunkt im Level ist x = 288 und y = 128
class CLevel 
{
private:
	/*************************************************************************/
	//Initialisierungen
	/*************************************************************************/
	//Leitern
	int InitLadder( float _PosX, float _PosY, int _Elem );
	int InitLadder( float _constX, float _firstY, int _firstElem, 
					int _elemLimit );

	int InitAllLadders();


	//Plattformen
	int InitPlatform( float _firstX, float _constY, int _firstElem, 
					  int _ElemLimit );
	int InitPlatform( float _firstX, float _firstY, int _firstElem,
					  int _ElemLimit, int _step );

	int InitAllPlatforms();
	/*************************************************************************/



public:
	/*************************************************************************/
	// Getter/Setter
	/*************************************************************************/
	//Plattform
	inline CBoxCollider& GetPlatformColl( int _elem )
	{
		return m_pPlatform[_elem]->GetCollider();
	}

	//Leiter
	inline CBoxCollider& GetLadderColl( int _elem )
	{
		return m_pLadder[_elem]->GetCollider();
	}


	
	//Begrenzungen
	inline CBoxCollider& GetLeftBoundColl()
	{
		return m_pLeftBoundary->GetCollider();
	}
	inline CBoxCollider& GetRightBoundColl()
	{
		return m_pRightBoundary->GetCollider();
	}

	//Siegbereich
	inline CBoxCollider& GetWinColl()
	{
		return m_pWinArea->GetCollider();
	}
	/*************************************************************************/

	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	int Initialize();
	void Finalize();
	int Update();
	void Render();
	/*************************************************************************/
private:
	/*************************************************************************/
	//Attribute
	/*************************************************************************/
	const int	M_I_FINALIZE_LIMIT = -1;
	//Leitern werden zur oberen Plattform gehörig gezählt
	CLadder*	m_pLadder[I_LDR_AR_SIZE] = {};

	//Sprites sind von Oben-Links nach Unten-Rechts angeordnet
	CPlatform*	m_pPlatform[I_PL_AR_SIZE] = {};


	CBoxCollObject* m_pLeftBoundary = nullptr;
	CBoxCollObject* m_pRightBoundary = nullptr;

	CBoxCollObject* m_pWinArea = nullptr;
	/*************************************************************************/
};