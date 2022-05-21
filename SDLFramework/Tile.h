/*****************************************************************************
* Project: SDLFramework
* File   : Tile.h
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
*	10.02.20	MS	Created
*	12.02.20	MS	Initialize um _x und _y-Parameter erweitert,
*					Ins Reine geschrieben
*	21.02.20	MS	GetCollider von Pointer zu Referenz
*	26.02.20	MS	GetWidth, SetPosition entfernt,
*					IMAGE-enum entfernt, GetCollider entfernt
*					leitet jetzt von CBoxCollObject ab
*	01.03.20	MS	Getter überarbeitet, 
*					Variablen für Literal-Ersetzung hinzugefügt,
*					Konstruktor/Destruktor, 
*					Werte für Vorinitialisierungen
******************************************************************************/
#pragma once
#include "BoxCollObject.h"
#include "Sprite.h"


//Werte für Vorinitialisierung
const int		  I_TILE_SIZE	  = -1;
const float		  F_TILE_POSITION = -1.0f;
const int		  I_TILE_NUM_FRAME  = 0;
const std::string SZ_TILE_FILENAME	  = "";

class CTile :
	public CBoxCollObject
{
public:
	/*************************************************************************/
	// Konstruktor/Destruktor
	/*************************************************************************/
	CTile();
	~CTile();
	/*************************************************************************/


	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	int Initialize( float _x, float _y, int _w, int _h );
	void Finalize();
	int Update();
	void Render();
	/*************************************************************************/

protected:
	/*************************************************************************/
	//Attribute
	/*************************************************************************/
	/*-----------------------------------------------------------------------*/
	//Könnte ab hier im weitesten Sinne Ralf Hüwes Sprite.h entsprechen
	int				m_iTileWidth	 = I_TILE_SIZE;
	int				m_iTileHeight	 = I_TILE_SIZE;
	Vector			m_TilePosition	 = { F_TILE_POSITION, F_TILE_POSITION };

	int				m_iTileNumFrames = I_TILE_NUM_FRAME;
	std::string		m_sTileFilename  = SZ_TILE_FILENAME;
	//Könnte bis hier im weitesten Sinne Ralf Hüwes Sprite.h entsprechen
	/*-----------------------------------------------------------------------*/
	
	//lokal
	const int		M_I_LOCAL_NUM_FRAMES = 1;

	//Komponenten
	CSprite*		m_pSprite = nullptr;
	/*************************************************************************/
};