/*****************************************************************************
* Project: SDLFramework
* File   : Platform.cpp
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
*	10.02.20	MS	Engine-Methoden erstellt
*					Getter von CLevel ausgelagert
*					m_pSprite in Engine-Methoden
*	26.02.20	MS	Plattform-Methoden aus Tile-Initialize hinzugefügt
*	01.03.20	MS	Literale entfernt, +Konstruktor/Destruktor
******************************************************************************/
#include "Platform.h"
#include "Engine.h"


/*****************************************************************************/
//Konstruktor
/*****************************************************************************/
CPlatform::CPlatform( float _x, float _y )
{
	m_TilePosition.x = _x;
	m_TilePosition.y = _y;
	m_iTileWidth = M_I_LOCAL_WIDTH;
	m_iTileHeight = M_I_LOCAL_HEIGHT;

	m_sTileFilename = M_SZ_CTOR_FILENAME;
}
/*****************************************************************************/

/*****************************************************************************/
//Destruktor
/*****************************************************************************/
CPlatform::~CPlatform()
{
	m_TilePosition.x = NULL;
	m_TilePosition.y = NULL;
	m_iTileWidth = NULL;
	m_iTileHeight = NULL;

	m_sTileFilename = M_SZ_DTOR_FILENAME;
}
/*****************************************************************************/


/*****************************************************************************/
//Initialisierung
/*****************************************************************************/
int CPlatform::Initialize()
{
	CTile::Initialize( m_TilePosition.x, m_TilePosition.y, 
					   m_iTileWidth, m_iTileHeight );

	m_pSprite->Initialize( m_sTileFilename, m_iTileNumFrames );
	m_pSprite->SetPosition( GetPositionX(), GetPositionY() );

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CPlatform::Finalize()
{
	CTile::Finalize();
}
/*****************************************************************************/

/*****************************************************************************/
//Update
/*****************************************************************************/
int CPlatform::Update()
{
	CTile::Update();
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Render
/*****************************************************************************/
void CPlatform::Render()
{
	CTile::Render();
}
/*****************************************************************************/