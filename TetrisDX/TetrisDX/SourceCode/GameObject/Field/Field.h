#pragma once

#include "..\GameObject.h"
#include "..\Tetrimino\Tetrimino.h"
#include "..\NextMino\NextMino.h"

#include <string>

// ブロック番号.
enum class enBlockNo
{
	None,	// 何もない状態.
	Wall,	// 壁.
	Plant,	// 置かれたブロック.
	Future,	// 予測用のブロック.

	Max,

} typedef EBlockNo;

// ブロックの色.
struct stBlockInfo
{
	EBlockNo	BlockNo;	// ブロック番号.
	EColor		Color;		// ブロックの色.
	std::string	String;		// 文字.

	stBlockInfo()
		: BlockNo	( EBlockNo::None )
		, Color		( EColor::L_BLACK )
		, String	( "　" )
	{}
} typedef SBlockInfo;

// フィールド.
using field = std::vector<std::vector<SBlockInfo>>;

/*************************************
*	フィールドクラス.
**/
class CField : public CGameObject
{
public:
	CField();
	virtual ~CField();

	// 更新関数.
	virtual void Update() override;
	// 描画関数.
	virtual void Draw() override;

private:
	field						m_Field;
	std::unique_ptr<CNextMino>	m_NextMino;
	std::shared_ptr<CTetrimino>	m_pMino;
};