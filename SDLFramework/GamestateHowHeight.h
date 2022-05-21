#pragma once
#include "Sprite.h"
#include "Gamestate.h"
#include "UIPanel.h"

using namespace std;

class CGamestateHowHeight : public CGamestate
{
public:
	CGamestateHowHeight() { m_sName = "howHeigh"; }

	int Initialize();
	void Finalize();
	int Update();
	void Render();

private:
	CSprite* m_pBackground = nullptr;

	string m_sHowHightCanYouGetScreen_448x512_f1 = "Assets\\HowHightCanYouGetScreen_448x512_f1.bmp";

	CUIPanel*	m_pUIPanel = nullptr;

	Vector m_vStartPos{ 512,384 };

	const float M_F_END_OF_TIMER = 0.0f;
	float m_fTimer = 2.5f;
	const float m_fDefaultTimer = 2.5f;
};

