/*****************************************************************************
* Project: Donkey Kong
* File   : DataManager.h
* Date   : 13.01.2019
* Author : Niklas Englmeier (NE)
*
* Die Datamanager Klasse verwaltet das Speichersystem des Spiels. Mit der
* Methode read liest das Programm die Datei in die FileContent Liste ein.
* Die Methode insertHighscore f�gt automatisch einen neuen DataSlot zur
* Highscore Liste hinzu, sortiert in nach der Punktzahl absteigend und l�scht
* den schlechtesten Score. Die save Methode speichert alle Daten im
* Speicherstand "savegame.txt".
*
* History:
*	13.01.19	NE	Created
******************************************************************************/
#include "DataManager.h"

DataManager::DataManager()
{
	m_iScore = I_START_SCORE;

	m_fileContent.clear();
	m_slots.clear();
	
	read();
}

//Destruktor Schlie�t Filestreams, falls noch ge�ffnet
DataManager::~DataManager()
{
	//Schlie�e Filestreams, falls ge�ffnet
	if (m_infile.is_open()) {
		m_infile.close();
	}
	if (m_ofilestream.is_open()) {
		m_ofilestream.close();
	}
	if (m_filestream.is_open()) {
		m_filestream.close();
	}
	
	//L�sche alle Eintr�ge der Slots Liste
	for (auto gs : m_slots)
	{
		SAFE_DELETE(gs);
	}

	//L�sche Inhalt der File Content String Liste
	m_fileContent.clear();
}

//Lese aus File und �bertrage in Slot Liste
void DataManager::read() {

	//ifstream infile(filename);
	m_infile.open(SAVEGAME_DIR);

	//Listen Pointer mit Datenslot Pointer als Element

	//Zeilen aus Savegame Datei in Liste einlesen
	while (getline(m_infile, m_szLine))
	{
		m_fileContent.push_back(m_szLine);
		m_iLines++;
	}
	m_infile.close();

	//Falls Datei fehlerhaft (ung�ltige Zeilenzahl)
	if (m_iLines != I_FILE_LENGTH) {
		//�ffne Filestream und l�sche Inhalt
		m_ofilestream.open(SAVEGAME_DIR,	ofstream::in | 
											ofstream::out | 
											ofstream::trunc);

		m_ofilestream.clear();

		//Lade Standard Highscore 5 Mal in die Datei
		for (int i = I_ZERO; i < I_SLOT_SIZE; i++) {
			//Default User (empty line)
			m_ofilestream << SZ_DEFAULT_NAME << endl;
			//Default Score (0)
			m_ofilestream << SZ_ZERO << endl;
		}

		m_ofilestream.close();

		//Lade Datei neu
		m_infile.open(SAVEGAME_DIR);
		m_iLines = I_ZERO;
		m_fileContent.clear();
		while (getline(m_infile, m_szLine))
		{
			m_fileContent.push_back(m_szLine);
			m_iLines++;
		}
	}
	 
	//Lade 5 neue Highscores in Ouput Liste
	for (int i = I_ZERO; i < I_SLOT_SIZE; i++)
	{
		m_slots.push_back(new DataSlot(SZ_DEFAULT_NAME, I_ZERO));
	}

	auto fileIterator = m_fileContent.begin();
	auto slotIterator = m_slots.begin();

	//Lese f�r 5 Datenslots abwechselnd Name und Punktzahl ein
	//F�r jeden Datenslot...
	for (size_t i = I_ZERO; i < m_slots.size(); i++) {
		//... caste die erste Zeile zu einem string und lese in Variable Name 
		//des aktuellen Datenslots
		static_cast<DataSlot*>(*slotIterator)->m_szName = 
			static_cast<string>(*fileIterator);
		//... erh�he zwischen beiden Einlesungen den File Iterator um 1,
		//um in n�chste Zeile zu gelangen
		advance(fileIterator, I_ADVANCE_VALUE);
		//... caste die zweite Zeile zu einem int und lese in Variable Score
		//des aktuellen Datenslots
		static_cast<DataSlot*>(*slotIterator)->m_iScore = 
			stoi(static_cast<string>(*fileIterator));
		//... erh�he F�le und Slot Iterator um 1
		advance(fileIterator, I_ADVANCE_VALUE);
		advance(slotIterator, I_ADVANCE_VALUE);
	}

	m_infile.close();
}

//Hinzuf�gen eines neuen Speicherstands mit Parametern Name und Value
void DataManager::insertHighscore(string _name, int _value) 
{
	//F�ge neuen Wert am Ende hinzu
	m_slots.push_back(new DataSlot(_name, _value));

	//Vergleiche Score Werte der benachbarten Datenslots und 
	//sortiere absteigend
	m_slots.sort([](const DataSlot* a, DataSlot* b) {
		return a->m_iScore > b->m_iScore;
	});

	//L�sche letztes Element
	m_slots.pop_back();

	//Speichern in File
	save();
}

//Speichern von name und value jedes Elements von Highscore in savegame.txt
void DataManager::save() {
	//�ffne Filestream und l�sche gesamten Inhalt der Datei
	m_ofilestream.open(SAVEGAME_DIR,	ofstream::in | 
										ofstream::out | 
										ofstream::trunc);
	auto it = m_slots.begin();
	//F�r jeden gespeicherten Score
	for (size_t i = I_ZERO; i < m_slots.size(); i++) {
		//Schreibe Daten in den Speicherstand
		m_ofilestream << static_cast<DataSlot*>(*it)->m_szName << endl;
		m_ofilestream << static_cast<DataSlot*>(*it)->m_iScore << endl;
		//Iterator erh�hen
		advance(it, I_ADVANCE_VALUE);
	}
	//Schlie�e Filestream
	m_ofilestream.close();
}

//Vergleicht die Highscore Liste mit dem neuen m�glichen Highscore und gibt
//true zur�ck, falls es sich um einen neuen Highscore handelt.
bool DataManager::isNewHighscore() {
	auto it = m_slots.begin();
	//F�r jeden Datenslot
	for (size_t i = I_ZERO; i < m_slots.size(); i++)
	{
		//Pr�fe, ob Score in Datenslot kleiner als neuer Highscore
		//Falls das zutrifft, gebe true zur�ck
		if (static_cast<DataSlot*>(*it)->m_iScore < m_iScore) {
			return true;
		}
		advance(it, I_ADVANCE_VALUE);
	}
	//Schleife wird beendet -> Kein Treffer = Score zu gering
	return false;
}

//Gibt den Speicherstand mit der h�chsten Punktzahl zur�ck
int DataManager::GetHighscore() {
	auto it = m_slots.begin();

	return static_cast<DataSlot*>(*it)->m_iScore;
}

//Gibt den Speicherstand mit Index _index zur�ck
DataSlot* DataManager::GetSlot(int _index) {
	auto it = m_slots.begin();

	advance(it, _index);

	return static_cast<DataSlot*>(*it);
}