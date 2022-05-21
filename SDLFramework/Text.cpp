/*****************************************************************************
* Project: Donkey Kong
* File   : Text.h
* Date   : 15.02.2020
* Author : Niklas Englmeier (NE)
*
* DIe Textklasse repräsentiert einen TTF Text. Man kann über die public
* Methoden den Text, die Farbe und die Position ändern.
*
* History:
*	15.02.20	NE	Created
******************************************************************************/
#include "Text.h"

/*****************************************************************************/
Text::Text()
{
}

/*****************************************************************************/
int Text::Initialize(string _fontFile,
					 int _fontRes,
					 int _fontSize,
					 SDL_Rect _position,
					 string _text, 
					 SDL_Color _color)
{
	m_pFont = TTF_OpenFont(_fontFile.c_str(), _fontRes);
	m_iFontSize = _fontSize;
	m_rect = _position;
	m_szText = _text;
	m_color = _color;

	return I_SUCCESS;
}

/*****************************************************************************/
int Text::Initialize(string _fontFile, int _fontRes, int _fontSize)
{
	m_pFont = TTF_OpenFont(_fontFile.c_str(), _fontRes);
	m_iFontSize = _fontSize;

	return I_SUCCESS;
}

/*****************************************************************************/
void Text::Finalize()
{
	if (m_pTexture != nullptr)
	{
		SDL_DestroyTexture(m_pTexture);
		m_pTexture = nullptr;
	}
	if (m_pSurface != nullptr)
	{
		SDL_FreeSurface(m_pSurface);
		m_pSurface = nullptr;
	}
	if (m_pFont != nullptr)
	{
		TTF_CloseFont(m_pFont);
		m_pFont = nullptr;
	}	
}

/*****************************************************************************/
void Text::Render()
{
	//Lokale Surface Variable ...
	SDL_Surface* surface = 
		TTF_RenderText_Solid(m_pFont, m_szText.c_str(), m_color);
	//... und lokale Texture Variable für ein Text Update
	SDL_Texture* texture = 
		SDL_CreateTextureFromSurface(CEngine::GetRenderer(), surface);
	//Render
	SDL_RenderCopy(CEngine::GetRenderer(), texture, NULL, &m_rect);
	//Löschen und freigeben lokaler Pointer
	SDL_DestroyTexture(texture);
	texture = nullptr;
	SDL_FreeSurface(surface);
	surface = nullptr;
}

/*****************************************************************************/
void Text::SetPosition(int _x, int _y) {
	m_rect.x = _x;
	m_rect.y = _y;
}

/*****************************************************************************/
void Text::SetColor(SDL_Color _newColor) {
	m_color = _newColor;
}

void Text::SetTextSize(int _newSize)
{
	//Setzt eine neue Textgröße und passt das Rect darauf an
	m_iFontSize = _newSize;
	m_rect.w = m_szText.length() * m_iFontSize;
	m_rect.h = m_iFontSize;
}

/*****************************************************************************/
void Text::SetText(string _text)
{
	m_szText = _text;
	//Passe Breite und Höhe an Anzahl der Buchstaben an.
	//Das funktioniert, da der Font ein Unicode Font ist.
	m_rect.w = m_szText.length() * m_iFontSize;
	m_rect.h = m_iFontSize;
}