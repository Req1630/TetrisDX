#include "Tetrimino.h"

namespace
{
	constexpr int HIGH_COLOR_ADD = 8;
}

CTetrimino::CTetrimino()
	: CTetrimino(
		std::vector<IntVec2D>( BROCK_NUM_MAX, IntVec2D() ),
		EColor::L_BLACK,
		true )
{
}

CTetrimino::CTetrimino( 
		const std::vector<IntVec2D>& pos, 
		const EColor& color,
		const bool& isRot )
	: m_NowPositions( pos )
	, m_OldPositions( pos )
	, m_Color		( color )
	, m_IsRotation	( isRot )
{
}


CTetrimino::~CTetrimino()
{
}

// 更新関数.
void CTetrimino::Update()
{
}

// 描画関数.
void CTetrimino::Draw()
{
	const IntVec2D fildPos = { 6, 6 };

	auto oldPos = m_OldPositions.begin();
	for( auto& nowPos : m_NowPositions ){
		// 前回の座標を計算する.
		const int old_x = fildPos.x +(oldPos->x*2);// 全角分座標をずらす.
		const int old_y = fildPos.y + oldPos->y;

		// 現在の座標を計算する.
		const int now_x = fildPos.x +(nowPos.x*2);// 全角分座標をずらす.
		const int now_y = fildPos.y + nowPos.y;
		const int lowColor = static_cast<int>(m_Color);
		const int highColor = HIGH_COLOR_ADD+lowColor;
		
		// 前回と座標が違っていたら前回の座標の文字を消す.
		if( old_x != now_x || old_y != now_y )
			CConsole::Clear( old_x, old_y,"　" );

		CConsole::SetColor( highColor, lowColor );
		CConsole::Draw( now_x, now_y, "■");

		oldPos++;
	}
	// 現在の座標を記憶する.
	m_OldPositions = m_NowPositions;
}

// 左回転.
void CTetrimino::LeftRotation()
{
	for( auto& p : m_NowPositions ){
		p = { p.y, -p.x };
	}
}

// 右回転.
void CTetrimino::RightRotation()
{
	for( auto& p : m_NowPositions ){
		p = { -p.y, p.x };
	}
}