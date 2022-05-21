/*****************************************************************************
* Project: SDLFramework
* File   : Tile.cpp
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
*	12.02.20	MS	Initialize erweitert,
*					Ins Reine geschrieben
*	26.02.20	MS	Getter-Setter durch GameObject-Methoden ersetzt
*					Plattform und Leiter in eigene Klassen ausgelagert,
*					leitet jetzt von CBoxCollObject ab
*	01.03.20	MS	Literale entfernt
******************************************************************************/
#include "Tile.h"


/*****************************************************************************/
//Konstruktor
/*****************************************************************************/
CTile::CTile()
{
	m_iTileNumFrames = M_I_LOCAL_NUM_FRAMES;
}
/*****************************************************************************/

/*****************************************************************************/
//Destruktor
/*****************************************************************************/
CTile::~CTile()
{
	m_iTileNumFrames = NULL;
}
/*****************************************************************************/


/*****************************************************************************/
// Initialisierung
/*****************************************************************************/
int CTile::Initialize( float _x, float _y, int _w, int _h )
{
	CBoxCollObject::Initialize( _x, _y, _w, _h );
	m_pSprite = new CSprite();
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CTile::Finalize()
{
	FINALIZE_DELETE( m_pSprite );
	CBoxCollObject::Finalize();
}
/*****************************************************************************/

/*****************************************************************************/
//Update
/*****************************************************************************/
int CTile::Update()
{
	m_pSprite->Update();
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Render
/*****************************************************************************/
void CTile::Render()
{
	m_pSprite->Render();
}
/*****************************************************************************/