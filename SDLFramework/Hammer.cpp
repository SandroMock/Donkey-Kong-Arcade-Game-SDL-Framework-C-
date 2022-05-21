/*****************************************************************************
* Project: SDLFramework
* File   : Hammer.cpp
* Date   : 20.02.2020
* Author : Stephan Weber (SW)
*
* Die Hammer Klasse ist ausschließlich da, um die Kollision zwischen Player und
* Hammer zu erkennen und um den Hammer an zu zeigen.
*
* History:
*	20.02.2020	SW	Created
******************************************************************************/
#include "Hammer.h"
#include "Defines.h"

CHammer::CHammer()
{
}

CHammer::~CHammer()
{
}

int CHammer::Initialize()
{
	m_pSprite = new CSprite();
	m_pSprite->Initialize(Hammer_18x20_f1);

	return 0;
}

void CHammer::Finalize()
{
	CCircCollObject::Finalize();
	FINALIZE_DELETE(m_pSprite);
}

int CHammer::Update()
{

	//nicht mehr anzeigen wenn der Spieler den Sprite berührt
	if (m_bPlayerCollidesWithHammer) { m_pSprite->SetActive(false); }
	return 0;
}

void CHammer::Render()
{
	m_pSprite->Render();
}
