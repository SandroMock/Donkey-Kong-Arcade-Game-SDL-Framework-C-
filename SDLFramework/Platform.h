/*****************************************************************************
* Project: SDLFramework
* File   : Platform.h
* Date   : 13.01.2019
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	13.01.20	MS	Created
*	10.02.20	MS	von CSprite als Childclass gelöst,
*					m_pSprite erstellt,
*					Engine-Methoden erstellt
*					Getter von CLevel ausgelagert,
*					zu Childclass von CGameObject gemacht,
*					Getter/Setter, Engine-Methoden und Attribute nach
*					CTile ausgelagert
*	26.02.20	MS	+Engine-Methoden
*	01.03.20	MS	Konstruktor/Destruktor erstellt, Literale zu Variablen
******************************************************************************/
#pragma once
#include "Tile.h"
#include "Sprite.h"

class CPlatform :
	public CTile
{
public:
	/*************************************************************************/
	// Konstruktor/Destruktor
	/*************************************************************************/
	CPlatform( float _x, float _y );
	~CPlatform();
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
	//lokal
	const int		  M_I_LOCAL_WIDTH    = 32;

	const int		  M_I_LOCAL_HEIGHT   = 16;

	const std::string M_SZ_CTOR_FILENAME = 
										"Assets\\Tiles\\Platform_32x16_f1.bmp";

	const std::string M_SZ_DTOR_FILENAME = "";
	/*************************************************************************/
};