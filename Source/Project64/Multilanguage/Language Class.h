/****************************************************************************
*                                                                           *
* Project 64 - A Nintendo 64 emulator.                                      *
* http://www.pj64-emu.com/                                                  *
* Copyright (C) 2012 Project64. All rights reserved.                        *
*                                                                           *
* License:                                                                  *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                        *
*                                                                           *
****************************************************************************/
#pragma once

#include "..\support.h"

#pragma warning(disable:4786)
#include <string>   //stl string
#include <map>      //stl map
#include <list>     //stl list

typedef std::map<int, stdstr, std::less<int> > LANG_STRINGS;
typedef LANG_STRINGS::value_type               LANG_STR;

typedef struct {
	stdstr Filename;
	stdstr LanguageName;
} LanguageFile;

typedef std::list<LanguageFile>   LanguageList;

class CLanguage
{
public:
	               CLanguage       ( );
	const stdstr & GetString       ( LanguageStringID StringID );
	LanguageList & GetLangList     ( void );
	void           SetLanguage     ( char * LanguageName );
	void           LoadCurrentStrings ( bool ShowSelectDialog );
	bool           IsCurrentLang   ( LanguageFile & File );

private:
	CLanguage(const CLanguage&);				// Disable copy constructor
	CLanguage& operator=(const CLanguage&);		// Disable assignment

	stdstr       m_SelectedLanguage;
	const stdstr m_emptyString;

	LANG_STRINGS m_CurrentStrings, m_DefaultStrings;
	LanguageList m_LanguageList;

	stdstr       GetLangString      ( const char * FileName, LanguageStringID ID );
	LANG_STR     GetNextLangString  ( void * OpenFile );
	void         LoadDefaultStrings ( void );
};

extern CLanguage * _Lang;

inline LPCSTR GS (LanguageStringID StringID)
{
	return _Lang->GetString(StringID).c_str();
}
