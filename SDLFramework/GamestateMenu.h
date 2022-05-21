/*****************************************************************************
* Project: SDLFramework
* File   : GamestateMenu.h
* Date   : 22.01.2020
* Author : Ralf Hüwe (RH)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	22.01.20	RH	Created
*	15.02.20	NE	Added game specific objects
******************************************************************************/
#pragma once
#include "Defines.h"
#include "Button.h"
#include "Gamestate.h"
#include "Engine.h"
#include "Text.h"
#include "Game.h"
#include "Utils.h"
#include "UIPanel.h"
#include "GamestateManager.h"
#include"GamestateMenuHighscoreConfig.h"

const std::string SZ_NEXT_GAMESTATE = "startAnimation";

const float F_CREDIT_TRIGGER = 0.125f;
const int I_CREDIT_MAXVALUE = 10;
const int I_CREDIT_VALUE_LENGTH = 2;

const char C_KEY_CONFIRM = ' ';

const int I_CREDIT_SOUND_REPEAT_COUNT = 5;
const int I_INTRO_SOUND_REPEAT_COUNT = 1;

const int I_INSERT_COIN_FONT_SIZE = 35;

const int I_STATE_ONE = 0;
const int I_STATE_TWO = 1;

const int I_SCORE_XOFFSET = 155;

const float F_SCREENHEIGHT_TABLE_DEPENDENCY = 1.5f;

const string SZ_RANK_TEXT = "RANK";
const string SZ_SCORE_TEXT = "SCORE";
const string SZ_NAME_TEXT = "NAME";

const string SZ_INSERT_COIN = "INSERT COIN";

const int I_MENU_LIVES = 0;
const int I_MENU_LEVEL = 0;

const string SZ_PUSH = "PUSH";
const string SZ_BUTTON = "1 OR 2 PLAYERS BUTTON";

const string SZ_ONE_TEXT = "1";
const string SZ_TWO_TEXT = "2";
const int I_ONETWO_UPPER_YPOSITION = 250;
const int I_ONETWO_LOWER_YPOSITION = 300;
const int I_ONETWO_XPOSITION = 50;
const int I_ONEBLUE_SECOND_YPOSITION = 250;

const string SZ_CREDITS_TEXT = "CREDIT ";
const int I_CREDIT_DIGITS = 2;

const int I_AUDIO_CHANNEL = -1;

class CGamestateMenu : public CGamestate
{
public:
	CGamestateMenu() { m_sName = "menu"; }

	int Initialize();
	void Finalize();

	int Update();
	void Render();
	static void HandleCB( int _id );

private:
	CUIPanel* m_pUIPanel = nullptr;

	Text* m_pRank = nullptr;
	Text* m_pScore = nullptr;
	Text* m_pName = nullptr;
	Text* m_pRanks[5];
	Text* m_pScores[5];
	Text* m_pNames[5];

	Text* m_pInsertCoin = nullptr;
	Text* m_pPlayer = nullptr;
	Text* m_pOneBlue = nullptr;
	Text* m_pTwoBlue = nullptr;
	Text* m_pOneRed = nullptr;
	Text* m_pTwoRed = nullptr;

	Text* m_pCredit = nullptr;

	int m_iCredits = 0;

	int m_iState = 0;

	float m_fCreditTimer = 0.0f;
	float m_fOneUpTimer = 0.0f;
};