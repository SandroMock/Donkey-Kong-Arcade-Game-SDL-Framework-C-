/*****************************************************************************
* Project: Donkey Kong
* File   : DataSlot.h
* Date   : 15.01.2019
* Author : Niklas Englmeier (NE)
*
* Die Klasse DataSlot repräsentiert einen Slot im Highscore Speicher.
* Dabei steht name für den Namen des Spielers und Score für seine erreichte
* Punktzahl.
*
* History:
*	15.01.19	NE	Created
******************************************************************************/

#pragma once
#include <string>

using namespace std;

class DataSlot
{
public:
	DataSlot(string _name, int _score);
	string m_szName;
	int m_iScore;
};