/*****************************************************************************
* Project: SDLFramework
* File   : Ladder.h
* Date   : 14.01.2019
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	14.01.20	MS	Created
*	06.02.20	MS	Konstruktor vereinfacht
*	10.02.20	MS	von CSprite als Childclass gelöst,
*					m_pSprite erstellt,
*					Engine-Methoden erstellt
*					Getter von CLevel ausgelagert,
*					zu Childclass von CGameObject gemacht,
*					Getter/Setter, Engine-Methoden und Attribute nach
*					CTile ausgelagert
*	26.02.20	MS	Initialize, Finalize, Update, Render hinzugefügt
*	01.03.20	MS	Konstruktor/Destruktor erstellt, Literale zu Variablen
******************************************************************************/
#pragma once
#include "Tile.h"
#include "Sprite.h"


class CLadder :
	public CTile
{
public:
	/*************************************************************************/
	// Konstruktor/Destruktor
	/*************************************************************************/
	CLadder( float _x, float _y );
	~CLadder();
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
	const int		  M_I_LOCAL_WIDTH    = 16;

	const int		  M_I_LOCAL_HEIGHT   = 16;

	const std::string M_SZ_CTOR_FILENAME = 
										"Assets\\Tiles\\Ladder_16x16_f1.bmp";

	const std::string M_SZ_DTOR_FILENAME = "";
	/*************************************************************************/
};