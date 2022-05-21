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
#include "GamestateHighscore.h"

/*****************************************************************************/
int CGamestateHighscore::Initialize()
{
	//Initialisieren UI Panel
	m_pUIPanel = new CUIPanel();
	m_pUIPanel->Initialize();
	m_pUIPanel->SetBonusActive(false);
	m_pUIPanel->SetOneUpActionActive(true);
	m_pUIPanel->SetLife(I_LIFES_IN_LEVEL);

	//Initialisieren Tabelle mit 5 Zeilen
	for (int i = I_ZERO; i < I_ROW_COUNT; i++) {
		//Initialisieren Ranks i ...
		m_pRanks[i] = new Text();
		m_pRanks[i]->Initialize(DEFAULT_FONT, 
								DEFAULT_FONT_RESOLUTION, 
								DEFAULT_BIG_FONT);
		//... an fester Position I_RANKS_X_POSITION
		m_pRanks[i]->SetPosition(I_RANKS_XPOSITION, 
			(int)(SCREENHEIGHT / F_ROW_SCREENHEIGHT_DEPENDENCE + 
			(i + I_INCREASE) * I_ROW_YOFFSET));

		//Initialisieren Scores i ...
		m_pScores[i] = new Text();
		m_pScores[i]->Initialize(DEFAULT_FONT, 
								 DEFAULT_FONT_RESOLUTION, 
								 DEFAULT_BIG_FONT);
		//... an fester Position I_SCORES_XPOSITION ...
		m_pScores[i]->SetPosition(I_SCORES_XPOSITION + m_pScores[i]->GetWidth(),
			(int)(SCREENHEIGHT / F_ROW_SCREENHEIGHT_DEPENDENCE + 
			(i + I_INCREASE) * I_ROW_YOFFSET));
		//... mit Text als formattierter Score aus Data Manager
		m_pScores[i]->SetText(
			FormatToStringWithZeros(CEngine::m_pDataManager->GetSlot(i)->m_iScore,
				I_SCORE_DIGITS));

		//Initialisieren Names i ...
		m_pNames[i] = new Text();
		m_pNames[i]->Initialize(DEFAULT_FONT, 
								DEFAULT_FONT_RESOLUTION, 
								DEFAULT_BIG_FONT);
		//... mit fester Position I_NAMES_XPOSITION
		m_pNames[i]->SetPosition(I_NAMES_XPOSITION,
			(int)(SCREENHEIGHT / F_ROW_SCREENHEIGHT_DEPENDENCE + 
			(i + I_INCREASE) * I_ROW_YOFFSET));
		//... mit Text Name aus Data Manager
		m_pNames[i]->SetText(CEngine::m_pDataManager->GetSlot(i)->m_szName);

		if (i < I_AMOUNT_RED_ROW) {
			//Farbe der oberen 3 Ränge
			m_pRanks[i]->SetColor(CRED);
			m_pScores[i]->SetColor(CRED);
			m_pNames[i]->SetColor(CRED);
		}
		else
		{
			//Farbe der unteren 2 Ränge
			m_pRanks[i]->SetColor(CYELLOW);
			m_pScores[i]->SetColor(CYELLOW);
			m_pNames[i]->SetColor(CYELLOW);
		}
	}

	//Ranglisten Texte
	m_pRanks[IDX_FIRST]->SetText(SZ_FIRST);
	m_pRanks[IDX_SECOND]->SetText(SZ_SECOND);
	m_pRanks[IDX_THIRD]->SetText(SZ_THIRD);
	m_pRanks[IDX_FOURTH]->SetText(SZ_FOURTH);
	m_pRanks[IDX_FIFTH]->SetText(SZ_FIFTH);

	//Initialisieren Nächstes Zeichen
	char nextLetter = C_ZERO;

	//Für gesamten zweidimensionalen Array
	for (int i = I_ZERO; i < I_ARRAY_X; i++) {
		for (int j = I_ZERO; j < I_ARRAY_Y; j++) {
			//Initialisiere Letter i j
			m_pLetter[i][j] = new Text();
			m_pLetter[i][j]->Initialize(DEFAULT_FONT, 
										DEFAULT_FONT_RESOLUTION, 
										I_LETTERSIZE);
			//Text in Abhängigkeit der ASCII Tabelle
			m_pLetter[i][j]->SetText(string(1, 
				(char)(i + I_CHARACTER_ROW + I_CHARACTER_COLUMN * j)));

			//Setze Position X und Y für Letter i j
			int x = SCREENWIDTH / I_HALF - I_LETTER_XPOSITION + 
				i % I_LETTER_XOFFSET_MODULO * I_LETTER_XOFFSET;

			int y = I_LETTER_YPOSITION + j * I_LETTER_YOFFSET;
			m_pLetter[i][j]->SetPosition(x, y);
			//Farbe für Letter i j = Grün
			m_pLetter[i][j]->SetColor(CGREEN);
			//Nächster Buchstabe
			nextLetter++;
		}
	}

	//Ändere Text der letzten vier Eingabefelder
	m_pLetter[IDX_DOT_XINDEX][IDX_INPUTFIELD_LAST_ROW]->SetText(SZ_BUTTON_DOT);
	m_pLetter[IDX_MINUS_XINDEX][IDX_INPUTFIELD_LAST_ROW]->SetText(SZ_BUTTON_MINUS);
	m_pLetter[IDX_RUB_XINDEX][IDX_INPUTFIELD_LAST_ROW]->SetText(SZ_BUTTON_RUB);
	m_pLetter[IDX_END_XINDEX][IDX_INPUTFIELD_LAST_ROW]->SetText(SZ_BUTTON_END);

	//TODO Funktion überprüfen
	m_pLetter[IDX_RUB_XINDEX][IDX_INPUTFIELD_LAST_ROW]->
		SetTextSize(I_RUB_END_YOFFSET);
	m_pLetter[IDX_RUB_XINDEX][IDX_INPUTFIELD_LAST_ROW]->
		IncYPosition(I_RUB_END_TEXT_SIZE);
	m_pLetter[IDX_END_XINDEX][IDX_INPUTFIELD_LAST_ROW]->
		SetTextSize(I_RUB_END_YOFFSET);
	m_pLetter[IDX_END_XINDEX][IDX_INPUTFIELD_LAST_ROW]->
		IncYPosition(I_RUB_END_TEXT_SIZE);

	//Initialisiere Selector
	m_pSelector = new CSprite();
	m_pSelector->Initialize(SZ_SELECTOR_SOURCE);
	m_pSelector->SetPosition(SCREENWIDTH / I_HALF - 
		I_SELECTOR_XOFFSET, I_SELECTOR_YPOSITION);
	
	//Initialisiere RegiTime
	m_pRegiTime = new Text();
	m_pRegiTime->Initialize(DEFAULT_FONT, 
							DEFAULT_FONT_RESOLUTION, 
							DEFAULT_BIG_FONT);
	m_pRegiTime->SetText(SZ_REGITIME_TEXT);
	m_pRegiTime->SetColor(CTORQUOISE);
	m_pRegiTime->SetPosition(SCREENWIDTH / I_HALF - 
		m_pRegiTime->GetWidth() / I_HALF, 
		SCREENHEIGHT / I_HALF + I_REGITIME_YOFFSET);

	//Initialisiere NameRegistration
	m_pNameRegistration = new Text();
	m_pNameRegistration->Initialize(DEFAULT_FONT, 
									DEFAULT_FONT_RESOLUTION, 
									DEFAULT_BIG_FONT);
	m_pNameRegistration->SetText(SZ_NAMEREGISTRATION_TEXT);
	m_pNameRegistration->SetColor(CRED);
	m_pNameRegistration->SetPosition(SCREENWIDTH / I_HALF - 
		m_pNameRegistration->GetWidth() / I_HALF, 
		I_NAMEREGISTRATION_YPOSITION);

	//Initialisiere Name
	m_pName = new Text();
	m_pName->Initialize(DEFAULT_FONT, 
						DEFAULT_FONT_RESOLUTION, 
						DEFAULT_BIG_FONT);
	m_pName->SetText(SZ_NAME_INPUT_TEXT);
	m_pName->SetColor(CTORQUOISE);
	m_pName->SetPosition(SCREENWIDTH / I_HALF - 
		m_pName->GetWidth() / I_HALF, I_NAME_YPOSITION);

	//Initialisiere NameValue
	m_pNameValue = new Text();
	m_pNameValue->Initialize(DEFAULT_FONT, 
							 DEFAULT_FONT_RESOLUTION, 
							 DEFAULT_BIG_FONT);
	m_pNameValue->SetColor(CTORQUOISE);
	m_pNameValue->SetPosition(SCREENWIDTH / I_HALF - 
		m_pName->GetWidth() / I_HALF + I_NAMEVALUE_XOFFSET,
		I_NAMEVALUE_YPOSITION);

	//Initialisiere Credit
	m_pCredit = new Text();
	m_pCredit->Initialize(DEFAULT_FONT, 
						  DEFAULT_FONT_RESOLUTION, 
						  DEFAULT_BIG_FONT);
	m_pCredit->SetText(SZ_CREDIT_TEXT);
	m_pCredit->SetColor(CGREEN);
	m_pCredit->SetPosition(SCREENWIDTH - m_pCredit->GetWidth(),
		SCREENHEIGHT - m_pCredit->GetHeight());

	return I_ZERO;
}

/*****************************************************************************/
void CGamestateHighscore::Finalize()
{
	//Finalisieren aller Pointer

	for (int i = I_ZERO; i < I_ARRAY_X; i++) {
		for (int j = I_ZERO; j < I_ARRAY_Y; j++) {
			FINALIZE_DELETE(m_pLetter[i][j]);
		}
	}

	for (int i = I_ZERO; i < I_ROW_COUNT; i++) {
		FINALIZE_DELETE(m_pNames[i]);
		FINALIZE_DELETE(m_pScores[i]);
		FINALIZE_DELETE(m_pRanks[i]);
	}

	FINALIZE_DELETE(m_pUIPanel);
	FINALIZE_DELETE(m_pSelector);
	FINALIZE_DELETE(m_pCredit);
	FINALIZE_DELETE(m_pRegiTime);
	FINALIZE_DELETE(m_pNameRegistration);
	FINALIZE_DELETE(m_pName);
	FINALIZE_DELETE(m_pNameValue);
}

/*****************************************************************************/
int CGamestateHighscore::Update()
{
	m_pUIPanel->Update();

	//Timer herunterzählen von 30.0
	m_fTimer -= CEngine::GetDeltaTime();
	//Runden des Timers auf eine ganze Zahl
	m_iTimeLeft = (int) m_fTimer;
	
	//Aktualisieren der Regi Time mit ganzer Zahl Time Left
	m_pRegiTime->SetText(SZ_REGITIME1 + 
		FormatToStringWithZeros(m_iTimeLeft, 
								I_REGITIME_VALUE_LENGTH) + SZ_REGITIME2);
	
	//Key Actions
	//Button Up (=W)
	if (CEngine::HasKeyBeenPressed(C_BUTTON_UP))
	{
		if (m_pSelector->GetPositionY() > I_SELECTOR_INPUT_UPPER_BORDER) {
			m_selectedCharacter.m_iCursorYPosition--;
			m_pSelector->IncPositionY(-I_SELECTOR_Y_CHANGE);
		}
	}

	//Button Left (=A)
	if (CEngine::HasKeyBeenPressed(C_BUTTON_LEFT))
	{
		//Selector an der linken Seite und nicht in der obersten Reihe
		if (m_pSelector->GetPositionX() == 
			SCREENWIDTH / I_HALF - I_SELECTOR_INPUT_RIGHT_BORDER &&

			!(m_pSelector->GetPositionY() == I_SELECTOR_INPUT_UPPER_BORDER)) {
			//Gehe Reihe nach oben und ganz nach rechts
			m_selectedCharacter.m_iCursorXPosition = I_SELECTOR_GO_UP_ARRAYPOS;
			m_selectedCharacter.m_iCursorYPosition--;
			m_pSelector->IncPositionY(-I_SELECTOR_Y_CHANGE);
			m_pSelector->SetPositionX(SCREENWIDTH / I_HALF + 
				I_SELECTOR_INPUT_RIGHT_OUTER_BORDER);
		}
		//Gehe nach links
		if (m_pSelector->GetPositionX() > 
			SCREENWIDTH / I_HALF - I_SELECTOR_INPUT_RIGHT_BORDER) {
			m_selectedCharacter.m_iCursorXPosition--;
			m_pSelector->IncPositionX(-I_SELECTOR_Y_CHANGE);
		}
	}

	//Button Down (=S)
	if (CEngine::HasKeyBeenPressed(C_BUTTON_DOWN))
	{
		if (m_pSelector->GetPositionY() < I_SELECTOR_INPUT_LOWER_BORDER) {
			m_selectedCharacter.m_iCursorYPosition++;
			m_pSelector->IncPositionY(I_SELECTOR_Y_CHANGE);
		}
	}

	//Button Right (=D)
	if (CEngine::HasKeyBeenPressed(C_BUTTON_RIGHT))
	{
		//Selector an der rechten Seite und nicht in der untersten Reihe
		if (m_pSelector->GetPositionX() == 
			(float) SCREENWIDTH / I_HALF + I_SELECTOR_INPUT_LEFT_BORDER &&

			!(m_pSelector->GetPositionY() == I_SELECTOR_INPUT_LOWER_BORDER)) {
			//Gehe Reihe nach unten und ganz nach links
			m_selectedCharacter.m_iCursorYPosition++;
			m_selectedCharacter.m_iCursorXPosition = I_SELECTOR_GO_DOWN_ARRAYPOS;
			m_pSelector->IncPositionY(I_SELECTOR_Y_CHANGE);
			m_pSelector->SetPositionX(SCREENWIDTH / I_HALF - 
				I_SELECTOR_INPUT_LEFT_OUTER_BORDER);
		}
		//Selector nach rechts bewegen
		if (m_pSelector->GetPositionX() < 
			SCREENWIDTH / I_HALF + I_SELECTOR_INPUT_LEFT_BORDER) {

			m_selectedCharacter.m_iCursorXPosition++;
			m_pSelector->IncPositionX(I_SELECTOR_Y_CHANGE);
		}
	}

	//Button Confirm (=Leertaste)
	if (CEngine::HasKeyBeenPressed(C_BUTTON_CONFIRM)) {
		//Bei beliebig gedrückter Taste, die nicht RUB oder END ist
		if (m_pLetter[m_selectedCharacter.m_iCursorXPosition]
			[m_selectedCharacter.m_iCursorYPosition]->GetText() != SZ_BUTTON_RUB &&

			m_pLetter[m_selectedCharacter.m_iCursorXPosition]
			[m_selectedCharacter.m_iCursorYPosition]->GetText() != SZ_BUTTON_END) {
			if (m_szText.length() < I_MAX_NAME_LENGTH) {
				//Füge zugehörigen Buchstaben dem Name String hinzu
				m_szText += m_pLetter[m_selectedCharacter.m_iCursorXPosition]
					[m_selectedCharacter.m_iCursorYPosition]->GetText();
			}
		}

		//Wenn gedrückte Taste = RUB
		if (m_pLetter[m_selectedCharacter.m_iCursorXPosition]
			[m_selectedCharacter.m_iCursorYPosition]->GetText() == SZ_BUTTON_RUB) {
			//Ziehe letzten Buchstaben vom Name String ab
			m_szText.erase(m_szText.length() - 1);
		}

		//Aktualisiere Name Text mit Name String
		m_pNameValue->SetText(m_szText);

		//Wenn gedrückte Taste = END
		if (m_pLetter[m_selectedCharacter.m_iCursorXPosition]
			[m_selectedCharacter.m_iCursorYPosition]->GetText() == SZ_BUTTON_END) {
			//Speichern eines neuen Highscores mit eingegebenen Namen und Punktzahl aus Data Manager
			CEngine::m_pDataManager->
				insertHighscore(m_szText, CEngine::m_pDataManager->GetScore());
			//Kehre zurück zu Gamestate "Menu"
			CGamestateManager::ChangeGamestate(SZ_GAMESTATE_MENU_NAME);
		}
	}

	//Wenn Registrierungstimer abgelaufen
	if (m_iTimeLeft == I_ZERO) {
		//Kehre zurück zum Hauptmenü
		CGamestateManager::ChangeGamestate(SZ_GAMESTATE_MENU_NAME);
	}

	return I_SUCCESS;
}

/*****************************************************************************/
void CGamestateHighscore::Render()
{
	//Rendern des gesamten Arrays
	for (int i = I_ZERO; i < I_ARRAY_X; i++) {
		for (int j = I_ZERO; j < I_ARRAY_Y; j++)
		{
			m_pLetter[i][j]->Render();
		}
	}

	//Rendern aller Zeilen der Tabelle
	for (int i = I_ZERO; i < I_ROW_COUNT; i++) {
		m_pRanks[i]->Render();
		m_pScores[i]->Render();
		m_pNames[i]->Render();
	}

	m_pUIPanel->Render();

	m_pSelector->Render();

	m_pCredit->Render();

	m_pRegiTime->Render();

	m_pNameRegistration->Render();
	m_pName->Render();
	m_pNameValue->Render();
}