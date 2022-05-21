/*****************************************************************************
* Project: SDLFramework
* File   : Hammer.h
* Date   : 20.02.2020
* Author : Stephan Weber (SW)
*
* Die Hammer Klasse ist ausschließlich da, um die Kollision zwischen Player und
* Hammer zu erkennen und um den Hammer an zu zeigen.
*
* History:
*	20.02.2020	SW	Created
******************************************************************************/
#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "CircCollObject.h"

using namespace std;

class CHammer : public CCircCollObject
{
public:
	CHammer();
	~CHammer();

	int Initialize();
	void Finalize();
	int Update();
	void Render();

	void SetPosition(Vector _vector) 
	{ 
		m_pSprite->SetPosition(_vector); 
		CCircCollObject::Initialize(
			m_pSprite->GetPositionX(), m_pSprite->GetPositionY(),
			m_pSprite->GetWidth(), m_pSprite->GetHeight());
	}

	void SetPlayerCollidesWithHammer(bool _bool) { m_bPlayerCollidesWithHammer = _bool; }

	Vector GetHammer1Pos() { return m_vHammer1Pos; }
	Vector GetHammer2Pos() { return m_vHammer2Pos; }

private:
	bool m_bPlayerCollidesWithHammer = false;
	
	const Vector m_vHammer1Pos{ 675,525 };
	const Vector m_vHammer2Pos{ 330,340 };

	CSprite*			m_pSprite = nullptr;

	const string Hammer_18x20_f1 = "Assets\\Jumpman\\Hammer_18x20_f1.bmp";
};

