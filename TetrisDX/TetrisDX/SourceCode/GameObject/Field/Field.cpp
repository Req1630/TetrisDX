#include "Field.h"

namespace
{
	constexpr int FIELD_HEIGHT	= 25;
	constexpr int FIELD_WIDTH	= 12;
	constexpr int HIGH_COLOR_ADD = 8;
};

CField::CField()
	: m_Field		( FIELD_HEIGHT, std::vector<SBlockInfo>( FIELD_WIDTH, SBlockInfo() ) )
	, m_NextMino	( std::make_unique<CNextMino>() )
	, m_pMino		( nullptr )
{
	for( int y = 0; y < FIELD_HEIGHT; y++ ){
		for( int x = 0; x < FIELD_WIDTH; x++ ){
			SBlockInfo& block = m_Field[y][x];
			if( x == 0 || x == FIELD_WIDTH-1 || y == FIELD_HEIGHT-1 ){
				block.BlockNo	= EBlockNo::Wall;
				block.Color		= EColor::L_WHITE;
				block.String	= "Å°";
			}

		}
	}
	m_pMino = m_NextMino->GetMino();
}

CField::~CField()
{
}

// çXêVä÷êî.
void CField::Update()
{
}

// ï`âÊä÷êî.
void CField::Draw()
{
	for( int y = 0; y < FIELD_HEIGHT; y++ ){
		for( int x = 0; x < FIELD_WIDTH; x++ ){
			const SBlockInfo block = m_Field[y][x];
			if( block.BlockNo == EBlockNo::None ) continue;

			const int lowColor = static_cast<int>(block.Color);
			const int highColor = HIGH_COLOR_ADD+lowColor;

			CConsole::SetColor( highColor, lowColor );
			CConsole::Draw( x*2, y, block.String );
		}
	}

	if( m_pMino != nullptr ) m_pMino->Draw();

	m_NextMino->Draw();
}