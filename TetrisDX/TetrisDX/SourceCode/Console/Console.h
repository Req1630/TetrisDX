#ifndef CONSOLE_H
#define CONSOLE_H

#include "..\SingletonBase\SingletonBase.h"

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum class enColor
{
	L_BLACK,	// ��P�x�E���F
	L_BLUE,		// ��P�x�E�F
	L_GREEN,	// ��P�x�E�ΐF
	L_CYAN,		// ��P�x�E���F
	L_RED,		// ��P�x�E�ԐF
	L_PURPLE,	// ��P�x�E���F
	L_YELLOW,	// ��P�x�E���F
	L_WHITE,	// ��P�x�E���F

	H_BLACK,	// ���P�x�E���F
	H_BLUE,		// ���P�x�E�F
	H_GREEN,	// ���P�x�E�ΐF
	H_CYAN,		// ���P�x�E���F
	H_RED,		// ���P�x�E�ԐF
	H_PURPLE,	// ���P�x�E���F
	H_YELLOW,	// ���P�x�E���F
	H_WHITE,	// ���P�x�E���F
} typedef EColor;

class CConsole : public CSingletonBase<CConsole>
{
public:
	CConsole();
	~CConsole();

	static HRESULT Init();
	static HRESULT Release();

	template<class... T1>
	static void Draw( int x, int y, const T1&... t1 )
	{
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition( GetInstance()->m_hConStdOut, coord );

		std::string out = GetInstance()->initstring( t1... );
		cout << out;
	}

	static void SetColor( int fore, int back );

	static void Clear( int x, int y, const char *c, enColor f = enColor::L_WHITE, enColor b = enColor::L_BLACK );

	HANDLE GetHandle();

private:
	template <class T>
	std::string to_std_string( const T& x )
	{
		std::stringstream ss;
		ss << x;
		return ss.str();
	}
	template<class T1, class... T2>
	std::string initstring( const T1& t1, const T2&... t2 )
	{
		std::string s = to_std_string( t1 );
		return s + initstring( t2... );
	}
	template<class T1>
	std::string initstring( const T1& t1 )
	{
		std::string s = to_std_string( t1 );
		return s;
	}

private:
	HANDLE m_hConStdOut;
};

#endif // #ifndef CONSOLE_H.