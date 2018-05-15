//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

#pragma once

#if !defined(__UTILS_H__)
#define __UTILS_H__

// Library Includes
#include <Windows.h>
#include <strstream>
#include <sstream>
#include <string>


// Local Includes

// Types

// Constants

// Prototypes

#define VALIDATE(a) if (!a) return (false)

template<typename T>
std::string ToString(const T& value)
{
	std::strstream theStream;
	theStream << value << std::ends;
	return (theStream.str());
}

template<typename T>
std::wstring ToWideString(const T& value)
{
	std::wstringstream theStream;
	theStream << value << std::ends;
	return (theStream.str());
}

float ReadFromEditBox(HWND hDialog, int resourceID)
{
	wchar_t value[10];
	ZeroMemory(value, 10);
	GetDlgItemText(hDialog, resourceID, value, 10);
	if (value[0] == 0)
	{
		return 0.0f;
	}
	else
	{
		return static_cast<float>(_wtof(value));
	}
}

void WriteToEditBox(HWND hDialog, int resourceID, float value)
{
	std::wstring stringValue = ToWideString(value);
	SetDlgItemText(hDialog, resourceID, stringValue.c_str());
}

#endif    // __UTILS_H__


