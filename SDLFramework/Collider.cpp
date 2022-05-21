/*****************************************************************************
* Project: SDLFramework
* File   : Collider.cpp
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
*	24.01.20	MS	Inhalt von Ralf Hüwes IsColliding Methode aus Sprite.cpp
*					in IsCircColl eingefügt, ebenso Parameter.
*					Initialize aus Sprite.h vorläufig ausgelagert
*	30.01.20	MS	Kreis-Box-Kollision realisiert
*	04.02.20	MS	UseGravity realisiert
*	10.02.20	MS	Kollisionsfunktionen nach "CCollision" ausgelagert
*	11.02.20	MS	+Initialize-Zeug
*	01.03.20	MS	Literale entfernt
******************************************************************************/
#include "Collider.h"
#include "ComponentConfig.h"


/*****************************************************************************/
//Initialisierung
/*****************************************************************************/
int CCollider::Initialize( float _x, float _y, int _w, int _h )
{
	/*-----------------------------------------------------------------------*/
	//Ab hier wie in Ralf Hüwes Sprite.cpp
	m_iWidth = _w;
	m_iHeight = _h;
	m_center.x = m_iWidth / I_DOUBLE; //MS: Literal entfernt
	m_center.y = m_iHeight / I_DOUBLE; //MS: Literal entfernt

	
	m_Position.x = _x;
	m_Position.y = _y;
	//bis hier wie in Ralf Hüwes Sprite.cpp
	/*-----------------------------------------------------------------------*/
	m_CollPosition = { 0.0f, 0.0f };

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Update
/*****************************************************************************/
int CCollider::Update( float _x, float _y, int _w, int _h )
{
	/*-----------------------------------------------------------------------*/
	//Ab hier wie in Ralf Hüwes Sprite.cpp
	m_iWidth = _w;
	m_iHeight = _h;
	m_center.x = m_iWidth / I_DOUBLE; //MS: Literal entfernt
	m_center.y = m_iHeight / I_DOUBLE; //MS: Literal entfernt


	m_Position.x = _x + m_CollPosition.x; //MS: m_CollPosition hinzugefügt
	m_Position.y = _y + m_CollPosition.y; //MS: m_CollPosition hinzugefügt
	//bis hier wie in Ralf Hüwes Sprite.cpp
	/*-----------------------------------------------------------------------*/

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CCollider::Finalize()
{
	m_iWidth = NULL;
	m_iHeight = NULL;
	m_center.x = NULL;
	m_center.y = NULL;


	m_Position.x = NULL;
	m_Position.y = NULL;
}
/*****************************************************************************/