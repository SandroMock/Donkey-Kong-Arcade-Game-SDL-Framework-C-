#pragma once
#include "Gamestate.h"
#include "Sprite.h"

using namespace std;

class CGamestateControls : public CGamestate
{
public:
	CGamestateControls() { m_sName = "controls"; }

	int Initialize();
	void Finalize();
	int Update();
	void Render();

private:
	CSprite* m_pControls = nullptr;
	Vector m_vStartPos{ 512,384 };

	const char m_cSpaceKey = ' ';

	const string Controls_2048x768_f2 = "Assets\\Controls_2048x768_f2.bmp";
};

