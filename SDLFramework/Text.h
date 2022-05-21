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
#pragma once
#include <string>
#include <SDL_ttf.h>
#include "Engine.h"
#include "Defines.h"
#include "LevelConfig.h"

class Text
{
public:
	Text();

	int Initialize(string _fontFile,
				   int _fontRes, 
				   int _fontSize,
				   SDL_Rect _position,
				   string _text,
				   SDL_Color _color);

	int Initialize(string _fontFile,
				   int _fontRes,
				   int _fontSize);

	void Finalize();

	//Kein Update, da nicht nötig

	void Render();

	void SetPosition(int _x, int _y);

	void SetColor(SDL_Color _newColor);

	void SetTextSize(int _newSize);

	void SetText(string _text = "");

	//Getter für Positionsabhängigkeit von anderen Texten
	int GetWidth() {
		return m_rect.w;
	}

	int GetHeight() {
		return m_rect.h;
	}

	int GetPositionX() {
		return m_rect.x;
	}

	int GetPositionY() {
		return m_rect.y;
	}

	string GetText() {
		return m_szText;
	}

	void IncYPosition(int _delta) {
		m_rect.y += _delta;
	}

private:
	TTF_Font* m_pFont = nullptr;
	int m_iFontSize = 0;

	//Standard Farbe Weiß
	SDL_Color	 m_color = {255, 255, 255};
	SDL_Surface* m_pSurface = nullptr;
	SDL_Texture* m_pTexture = nullptr;

	//x, y, w, h
	SDL_Rect	 m_rect = {0, 0, 0, 0};
	
	std::string m_szText = "";
};