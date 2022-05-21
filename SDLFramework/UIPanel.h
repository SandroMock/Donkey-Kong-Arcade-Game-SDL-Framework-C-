/*****************************************************************************
* Project: SDLFramework
* File   : UIPanel.h
* Date   : 04.03.2020
* Author : Niklas Englmeier (NE)
*
* Das UI Panel repräsentiert das gesamte obere UI des Spiels. Darin werden
* der OneUp, Score, Highscore, HighscoreValue, der Bonus und der Level Text,
* sowie die Lebens- und das Bonus-Rahmen Bild gehalten. Über die jeweiligen 
* Methoden kann man die Werte der Texte ändern.
* 
*
* History:
*	04.03.20	NE	Created (from GameUI)
******************************************************************************/

#pragma once
#include <math.h>
#include <SDL_ttf.h>
#include "Sprite.h"
#include "Player.h"
#include "Level.h"
#include "Engine.h"
#include "Text.h"
#include "Game.h"
#include "DataManager.h"

//Sprite Source Bonus Frame
const string SZ_BONUSFRAME_SOURCE = "Assets/bonus3.bmp";
//Sprite Source Leben
const string SZ_LIFE_SOURCE = "Assets/liveIcon.bmp";

//Bonusframe Position
const int I_BONUSFRAME_XPOSITION = 924;
const int I_BONUSFRAME_YPOSITION = 100;

//Lebensanzeige Position
const int I_LIVES_XPOSITION = 8;
const int I_LIVES_XOFFSET = 40;
const int I_LIVES_REVERSE = -1;
const int I_LIVES_YPOSITION = 100;

//Levelanzeige Position
const int I_LEVEL_XPOSITION = SCREENWIDTH - 100;
const int I_LEVEL_YPOSITION = 40;
const int I_LEVEL_TEXTSIZE = 20;

//Highscore Position
const int I_HIGHSCORE_YPOSITION = 10;
const string SZ_HIGHSCORE_TEXT = "HIGH SCORE";

//Standardwert für Score Anzeigen
const string SZ_SCORE_DEFAULT = "000000";

//Position für Bonus Score Text
const int I_BONUS_XPOSITION = 871;
const int I_BONUS_YPOSITION = 94;
const int I_BONUS_TEXTSIZE = 27;

//Level Texte
const string SZ_LEVEL1 = "L=0";
const string SZ_LEVEL2 = "L=00";

//One Up Position und Text
const int I_ONEUP_SCORE_XPOSITION = 106;
const int I_ONEUP_YPOSITION = 10;
const string SZ_ONEUP_TEXT = "1UP";

//Delta des Bonus Scores
const int I_BONUS_DEC = 100;

//Timer Trigger und Default
const float I_BONUSTIMERTRIGGER = 2;
const float F_ONEUPTIMERTRIGGER = 0.25f;

//Maximale Anzahl der Leben
const int I_LIVESMAX = 3;

class CUIPanel
{
public:
	int Initialize();
	void Finalize();

	int Update();
	void Render();

	//Gibt Score zurück
	int GetScore();
	//Gibt Bonus Score zurück
	int GetBonusScore();

	//Setzt das Level
	void SetLevel(int _level);
	//Setzt die Leben
	void SetLife(int _life);
	//Setzt die Punktzahl
	void SetScore(int _score);
	//Setzt den Highscore
	void SetHighscore(int _highscore);
	//Setzt Bonus Active State
	void SetBonusActive(bool _activeState);
	//Setzt One Up Action (Blink) State
	void SetOneUpActionActive(bool _activeState);
private:
	//Leben Sprites
	CSprite* m_pLife[3];
	//Rahmen für Bonus Anzeige
	CSprite* m_pBonusFrame = nullptr;

	//Text 1Up
	Text* m_pOneUp = nullptr;
	//Text Aktuelle Punktzahl
	Text* m_pScore = nullptr;
	//Text Highscore
	Text* m_pHighscore = nullptr;
	//Text Aktueller Highscore
	Text* m_pHighscoreValue = nullptr;
	//Aktuelle Bonus Punktzahl
	Text* m_pBonus = nullptr;
	//Aktuelles Level
	Text* m_pLevel = nullptr;

	//Aktuelles Level
	int m_iLevel = 0;

	//Anzahl Leben
	int m_iLivesLeft = 3;

	//OneUp Text sichtbar
	bool m_bOneUpIsVisible = true;

	//Wert der aktuellen Punktzahl
	int m_iScore = 0;
	//Wert der aktuellen Bonuszahl
	int m_iBonus = 5000;
	//Wert des aktuellen Highscores
	int m_iHighscore = 0;

	//Timer
	float m_fBonusTimer = 0.0f;
	float m_fOneUpTimer = 0.0f;

	//Zustände von Bonus und OneUp Anzeige
	bool m_bBonusIsActive = true;
	bool m_bOneUpActionActive = false;
};