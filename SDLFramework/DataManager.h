/*****************************************************************************
* Project: Donkey Kong
* File   : DataManager.h
* Date   : 13.01.2019
* Author : Niklas Englmeier (NE)
*
* Die Datamanager Klasse verwaltet das Speichersystem des Spiels. Mit der
* Methode read liest das Programm die Datei in die FileContent Liste ein.
* Die Methode insertHighscore fügt automatisch einen neuen DataSlot zur 
* Highscore Liste hinzu, sortiert in nach der Punktzahl absteigend und löscht
* den schlechtesten Score. Die save Methode speichert alle Daten im
* Speicherstand "savegame.txt".
*
* History:
*	13.01.19	NE	Created
******************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include "DataSlot.h"
#include "Defines.h"
#pragma once

using namespace std;

const int I_START_SCORE = 0;
const int I_FILE_LENGTH = 10;

const string SZ_DEFAULT_NAME;

const int I_SLOT_SIZE = 5;

const int I_ADVANCE_VALUE = 1;

const string SZ_ZERO = "0";


class DataManager
{
public:
	DataManager();
	~DataManager();

	void insertHighscore(string _name, int _value);
	void save();
	void read();

	bool isNewHighscore();

	int GetHighscore();
	DataSlot* GetSlot(int _index);
	
	void SetPlayerHasWon() { IncScore(m_iFinalBonusScore); }
	void SetBonus(int _bonus) { m_iFinalBonusScore = _bonus; }

	int GetScore() { return m_iScore; }
	void IncScore(int _delta) { m_iScore += _delta; }
	void ResetScore() { m_iScore = 0; }

	int GetLivesLeft() { return m_iLifesLeft; }
	void DecLifesLeft() { m_iLifesLeft--; }

private:
	int m_iHighscore[5] = {};

	//Filestreams
	fstream m_filestream;
	ifstream m_infile;
	ofstream m_ofilestream;

	//Anzahl Gesamtzeilen
	int m_iLines = 0;

	//Inhalt aktuelle Zeile
	string m_szLine = "";

	//File Liste
	list<string> m_fileContent = {};

	//Highscore Liste
	list<DataSlot*> m_slots = {};

	int m_iFinalBonusScore = 0;
	//Aktuelle Punktzahl
	int m_iScore = 0;
	//Anzahl Leben übrig
	int m_iLifesLeft = 3;
};