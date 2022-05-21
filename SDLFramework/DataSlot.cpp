/*****************************************************************************
* Project: Donkey Kong
* File   : DataSlot.h
* Date   : 15.01.2019
* Author : Niklas Englmeier (NE)
*
* Die Klasse DataSlot repr�sentiert einen Slot im Highscore Speicher.
* Dabei steht name f�r den Namen des Spielers und Score f�r seine erreichte
* Punktzahl.
*
* History:
*	15.01.19	NE	Created
******************************************************************************/
#include "DataSlot.h"

DataSlot::DataSlot(string _name, int _score)
{
	m_szName = _name;
	m_iScore = _score;
}
