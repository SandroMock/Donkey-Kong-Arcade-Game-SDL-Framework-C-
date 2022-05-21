/*****************************************************************************
* Project: Donkey Kong
* File   : GamestateHighscore.h
* Date   : 29.02.2020
* Author : Niklas Englmeier (NE)
*
* Über den Gamestate Highscore kann man, falls man mit seiner erreichten
* Punktzahl auf dem Scoreboard steht, sein 3 Buchstaben langes Kürzel eingeben.
* Daraufhin kommt man zurück in das Hauptmenü.
* 
* History:
*	29.02.20	NE	Created
******************************************************************************/
#pragma once
#include "Gamestate.h"
#include "Text.h"
#include "Sprite.h"
#include "Game.h"
#include "DataManager.h"
#include "Utils.h"
#include "GamestateManager.h"
#include "UIPanel.h"
#include "LevelConfig.h"
#include "Defines.h"
#include "GamestateMenuHighscoreConfig.h"

//Maximale Anzahl erlaubter Buchstaben im Highscore Namen
const int I_MAX_NAME_LENGTH = 3;

//Keyboard Keys für Interaktion
const char C_BUTTON_UP = 'w';
const char C_BUTTON_LEFT = 'a';
const char C_BUTTON_DOWN = 's';
const char C_BUTTON_RIGHT = 'd';

//Bezeichnungen für Buttons, die nicht zwischen A und Z liegen
const std::string SZ_BUTTON_RUB = "RUB";
const std::string SZ_BUTTON_END = "END";
const std::string SZ_BUTTON_DOT = ".";
const std::string SZ_BUTTON_MINUS = "-";

//Gamestate Menu Name
const std::string SZ_GAMESTATE_MENU_NAME = "menu";

//Array Größe
const int I_ARRAY_X = 10;
const int I_ARRAY_Y = 3;

//Delta für die Bewegung des Selector Sprites
const int I_SELECTOR_Y_CHANGE = 50;

//Die halbe Bildschirmbreite
const int I_HALF_SCREENWIDTH = SCREENWIDTH / 2;


//const int I_ZERO = 0;
//Char '0' für automatisches Character schreiben
const char C_ZERO = '0';

//Größe der Buchstaben des Input Fields
const int I_LETTERSIZE = 36;

//Selector Start Offset
const int I_SELECTOR_XOFFSET = 233;
//Selector Start Position
const int I_SELECTOR_YPOSITION = 268;
//Selector Sprite Source
const string SZ_SELECTOR_SOURCE = "Assets/selector.bmp";

//Position Name Registration Text
const int I_NAMEREGISTRATION_YPOSITION = 100;
//Name Registration Text
const string SZ_NAMEREGISTRATION_TEXT = "NAME REGISTRATION";

//Position / Wertlänge und Text von Regi Time Text
const int I_REGITIME_YOFFSET = 50;
const int I_REGITIME_VALUE_LENGTH = 2;
const string SZ_REGITIME_TEXT = "REGI TIME  <30>";
const std::string SZ_REGITIME1 = "REGI TIME  <";
const std::string SZ_REGITIME2 = ">";

//Position / Text von Name
const int I_NAME_YPOSITION = 150;
const string SZ_NAME_INPUT_TEXT = "NAME: ___";

//Position von Name Value Text
const int I_NAMEVALUE_XOFFSET = 180;
const int I_NAMEVALUE_YPOSITION = 145;

//Links <-> Rechts
//Werte zur Begrenzung des Selectors
const int I_SELECTOR_GO_UP_ARRAYPOS = 10;
const int I_SELECTOR_GO_DOWN_ARRAYPOS = -1;
const int I_SELECTOR_INPUT_UPPER_BORDER = 268;
const int I_SELECTOR_INPUT_LOWER_BORDER = 368;
const int I_SELECTOR_INPUT_LEFT_BORDER = 217;
const int I_SELECTOR_INPUT_LEFT_OUTER_BORDER = 283;
const int I_SELECTOR_INPUT_RIGHT_BORDER = 233;
const int I_SELECTOR_INPUT_RIGHT_OUTER_BORDER = 267;

//ASCII Character Werte
const int I_CHARACTER_ROW = 65;
const int I_CHARACTER_COLUMN = 10;

//Buchstaben Positionen
const int I_LETTER_YPOSITION = 250;
const int I_LETTER_YOFFSET = 50;
const int I_LETTER_XPOSITION = 250;
const int I_LETTER_XOFFSET_MODULO = 10;
const int I_LETTER_XOFFSET = 50;
const int I_RUB_END_YOFFSET = 10;
const int I_RUB_END_TEXT_SIZE = 12;

const int IDX_INPUTFIELD_LAST_ROW = 2;
const int IDX_DOT_XINDEX = 6;
const int IDX_MINUS_XINDEX = 7;
const int IDX_RUB_XINDEX = 8;
const int IDX_END_XINDEX = 9;

class CGamestateHighscore: public CGamestate
{
public:
	CGamestateHighscore() { m_sName = "highscore"; }

	int Initialize();
	void Finalize();
	int Update();
	void Render();

private:
	CUIPanel* m_pUIPanel = nullptr;

	Text* m_pNameRegistration = nullptr;
	Text* m_pName = nullptr;
	Text* m_pNameValue = nullptr;

	Text* m_pCredit = nullptr;

	Text* m_pRegiTime = nullptr;
	int m_iTimeLeft = 31;
	float m_fTimer = 31.0f;

	CSprite* m_pSelector = nullptr;
	Text* m_pLetter[10][3];

	Text* m_pRanks[5] = {};
	Text* m_pScores[5] = {};
	Text* m_pNames[5] = {};

	struct SelectedCharacter
	{
		int m_iCursorXPosition = 0;
		int m_iCursorYPosition = 0;
	};

	SelectedCharacter m_selectedCharacter = { 0, 0 };

	string m_szText = "";

	int m_iState = 0;
};