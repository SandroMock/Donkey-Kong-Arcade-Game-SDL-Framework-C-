/*****************************************************************************
* Project: SDLFramework
* File   : UIPanel.cpp
* Date   : 04.03.2020
* Author : Niklas Englmeier (NE)
* 
* Das UI Panel repr�sentiert das gesamte obere UI des Spiels. Darin werden
* der OneUp, Score, Highscore, HighscoreValue, der Bonus und der Level Text,
* sowie die Lebens- und das Bonus-Rahmen Bild gehalten. �ber die jeweiligen
* Methoden kann man die Werte der Texte �ndern.
*
*
* History:
*	04.03.20	NE	Created (from GameUI)
*	05.03.20	NE  Literale
******************************************************************************/
#include "UIPanel.h"

/*****************************************************************************/
int CUIPanel::Initialize()
{
	//Initialisieren Bonus Frame
	m_pBonusFrame = new CSprite();
	m_pBonusFrame->Initialize(SZ_BONUSFRAME_SOURCE);
	m_pBonusFrame->SetPosition(I_BONUSFRAME_XPOSITION, I_BONUSFRAME_YPOSITION);

	//Initialisieren Lebensanzeige
	for (int i = I_ZERO; i < I_LIVESMAX; i++)
	{
		m_pLife[i] = new CSprite();
		m_pLife[i]->Initialize(SZ_LIFE_SOURCE);
		m_pLife[i]->SetPositionX(static_cast<float>(I_LIVES_XPOSITION - 
			( - i + I_LIVES_REVERSE) * I_LIVES_XOFFSET));
		m_pLife[i]->SetPositionY(I_LIVES_YPOSITION);
	}
	m_iLivesLeft = CEngine::m_pDataManager->GetLivesLeft();

	//Initialisieren One Up Text
	m_pOneUp = new Text();
	m_pOneUp->Initialize(	DEFAULT_FONT, 
							DEFAULT_FONT_RESOLUTION, 
							DEFAULT_SMALL_FONT);
	m_pOneUp->SetText(SZ_ONEUP_TEXT);
	m_pOneUp->SetColor(CRED);
	m_pOneUp->SetPosition(I_ONEUP_SCORE_XPOSITION - 
		(m_pOneUp->GetWidth() / I_HALF), I_ONEUP_YPOSITION);

	//Initialisieren Score Text
	m_pScore = new Text();
	m_pScore->Initialize(	DEFAULT_FONT, 
							DEFAULT_FONT_RESOLUTION, 
							DEFAULT_BIG_FONT);
	m_pScore->SetText(FormatToStringWithZeros(
		(CEngine::m_pDataManager->GetScore())));
	m_pScore->SetPosition(I_ONEUP_SCORE_XPOSITION - 
		(m_pScore->GetWidth() / I_HALF),
		m_pOneUp->GetHeight() + m_pOneUp->GetPositionY());

	//Initialisieren Highscore Text
	m_pHighscore = new Text();
	m_pHighscore->Initialize(	DEFAULT_FONT,
								DEFAULT_FONT_RESOLUTION,
								DEFAULT_SMALL_FONT);
	m_pHighscore->SetText(SZ_HIGHSCORE_TEXT);
	m_pHighscore->SetPosition(SCREENWIDTH / I_HALF - 
		m_pHighscore->GetWidth() / I_HALF, I_HIGHSCORE_YPOSITION);
	m_pHighscore->SetColor(CRED);

	//Initialisieren Highscore Value Text
	m_pHighscoreValue = new Text();
	m_pHighscoreValue->Initialize(	DEFAULT_FONT,
									DEFAULT_FONT_RESOLUTION, 
									DEFAULT_BIG_FONT);
	m_pHighscoreValue->SetText(
		FormatToStringWithZeros(CEngine::m_pDataManager->GetHighscore()));
	m_pHighscoreValue->SetPosition(SCREENWIDTH / I_HALF - 
		m_pHighscoreValue->GetWidth() / I_HALF, 
		m_pHighscore->GetHeight() + m_pHighscore->GetPositionY());

	//Initialisieren Level Text
	m_pLevel = new Text();
	m_pLevel->Initialize(DEFAULT_FONT, DEFAULT_FONT_RESOLUTION, I_LEVEL_TEXTSIZE);
	m_pLevel->SetText(SZ_LEVEL2);
	m_pLevel->SetColor(CBLUE);
	m_pLevel->SetPosition(I_LEVEL_XPOSITION, I_LEVEL_YPOSITION);

	//Initialisieren Bonus Text
	m_pBonus = new Text();
	m_pBonus->Initialize(DEFAULT_FONT, DEFAULT_FONT_RESOLUTION, I_BONUS_TEXTSIZE);
	m_pBonus->SetPosition(I_BONUS_XPOSITION, I_BONUS_YPOSITION);
	m_pBonus->SetColor(CTORQUOISE);
	m_pBonus->SetText(std::to_string(m_iBonus));

	return I_SUCCESS;
}

/*****************************************************************************/
void CUIPanel::Finalize()
{
	//Alles finalisieren
	FINALIZE_DELETE(m_pBonus);
	FINALIZE_DELETE(m_pLevel);
	FINALIZE_DELETE(m_pHighscoreValue);
	FINALIZE_DELETE(m_pHighscore);
	FINALIZE_DELETE(m_pScore);
	FINALIZE_DELETE(m_pOneUp);
	for (int i = I_ZERO; i < m_iLivesLeft; i++)
	{
		FINALIZE_DELETE(m_pLife[i]);
	}
	FINALIZE_DELETE(m_pBonusFrame);
}

/*****************************************************************************/
int CUIPanel::Update()
{
	CEngine::m_pDataManager->SetBonus(m_iBonus);
	m_pScore->
		SetText(FormatToStringWithZeros(CEngine::m_pDataManager->GetScore(), 6));
	//Wenn Bonusanzeige aktiv ist
	if (m_bBonusIsActive)
	{
		//Timer hochzählen
		m_fBonusTimer += CEngine::GetDeltaTime();

		//Wenn Timer den Trigger Wert erreicht hat und der Bonus größer 0 ist
		if (m_fBonusTimer > I_BONUSTIMERTRIGGER && m_iBonus > I_ZERO) {
			//Ziehe 100 Punkte ab
			m_iBonus -= I_BONUS_DEC;
			//Aktualisiere Text
			m_pBonus->SetText(std::to_string(m_iBonus));
			//Timer zurücksetzen
			m_fBonusTimer = F_TIMER_DEFAULT;
		}
	}

	//Wenn OneUp Blinken aktiv ist
	if (m_bOneUpActionActive)
	{
		//Timer hochzählen
		m_fOneUpTimer += CEngine::GetDeltaTime();
		//Wenn Timer den Trigger Wert erreicht hat
		if (m_fOneUpTimer > F_ONEUPTIMERTRIGGER) {
			//Toggle die Sichtbarkeit des OneUp Texts
			m_bOneUpIsVisible = !m_bOneUpIsVisible;
			//Timer zurücksetzen
			m_fOneUpTimer = F_TIMER_DEFAULT;
		}
	}

	return I_SUCCESS;
}

/*****************************************************************************/
void CUIPanel::Render()
{
	//Ist OneUp sichtbar
	if (m_bOneUpIsVisible) {
		//Render
		m_pOneUp->Render();
	}

	//Rendere festgelegte Anzahl von Leben
	for (int i = I_ZERO; i < m_iLivesLeft; i++)
	{
		m_pLife[i]->Render();
	}

	m_pLevel->Render();

	m_pScore->Render();
	m_pHighscore->Render();
	m_pHighscoreValue->Render();

	//Ist Bonus Frame aktiv
	if (m_bBonusIsActive) {
		//Rendern von Frame und Text
		m_pBonusFrame->Render();
		m_pBonus->Render();
	}
}

/*****************************************************************************/
void CUIPanel::SetLevel(int _level)
{
	//Setze Level und Leveltext
	m_iLevel = _level;
	m_pLevel->SetText(SZ_LEVEL1 + std::to_string(m_iLevel));
}

/*****************************************************************************/
void CUIPanel::SetLife(int _life)
{
	//Setze Leben und damit Anzahl Iterationen im HUD
	m_iLivesLeft = _life;
}

/*****************************************************************************/
void CUIPanel::SetScore(int _score)
{
	//Setzt den Score Text
	m_iScore = _score;
	m_pScore->SetText(FormatToStringWithZeros(m_iScore));
}

/*****************************************************************************/
void CUIPanel::SetHighscore(int _highscore)
{
	//Setzt den Highscore Text
	m_iHighscore = _highscore;
	m_pHighscoreValue->SetText(FormatToStringWithZeros(m_iHighscore));
}

/*****************************************************************************/
void CUIPanel::SetBonusActive(bool _activeState)
{
	//Ändert den Zustand der Bonusanzeige
	m_bBonusIsActive = _activeState;
}

/*****************************************************************************/
void CUIPanel::SetOneUpActionActive(bool _activeState)
{
	//Ändert den Sichtbarkeitszustand des OneUp Texts
	m_bOneUpActionActive = _activeState;
}

/*****************************************************************************/
int CUIPanel::GetScore()
{
	//Gibt den Score Text zurück
	return m_iScore;
}

/*****************************************************************************/
int CUIPanel::GetBonusScore()
{
	//Gibt den Bonus Score Text zurück
	return m_iBonus;
}