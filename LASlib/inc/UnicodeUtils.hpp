/*
===============================================================================

  FILE:  UnicodeUtils.hpp
    
===============================================================================
*/
#pragma once

//#define LAS_TOOLS_VERSION 170805
//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//
//#include "mydefs.hpp"
//#include "laszip.hpp"
//#include "laspoint.hpp"

#ifdef _WIN32
#include <string>
#include <windows.h>
#endif

#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable:4267)
#endif

class UnicodeUtils
{
public:
#ifdef _WIN32
	// Convert a wide Unicode string to an UTF8 string
	static std::string utf8_encode(const std::wstring &wstr)
	{
		if (wstr.empty()) return std::string();
		int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
		std::string strTo(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
		return strTo;
	}

	static std::wstring towstring(const CHAR* s)
	{
		std::string str(s);
		if (str.size() > 250)
		{
			for (auto& c : str)
			{
				if (c == '/')
				{
					c = '\\';
				}
			}

			str.insert(0, "\\\\?\\");
		}

		int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
		std::wstring wstrTo(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);

		return wstrTo;
	}
#endif

	static int strcmp(const CHAR* str, const CHAR* ext)
	{
#ifdef _WIN32
		return wcscmp(towstring(str).c_str(), towstring(ext).c_str());
#else
		return strstr(str, ext);
#endif

	}

	static bool strstr(const CHAR* str, const CHAR* ext)
	{
#ifdef _WIN32
		return wcsstr(towstring(str).c_str(), towstring(ext).c_str()) != nullptr;
#else
		return strstr(str, ext) != nullptr;
#endif
	
	}

	static FILE* open(const CHAR* filename, const CHAR* mode)
	{
		// open input file
#ifdef _WIN32
		return _wfopen(towstring(filename).c_str(), towstring(mode).c_str());// wstrMode.c_str());
#else
		return fopen(filename, mode);
#endif
	}
};

#ifdef _MSC_VER
#  pragma warning(pop)
#endif

