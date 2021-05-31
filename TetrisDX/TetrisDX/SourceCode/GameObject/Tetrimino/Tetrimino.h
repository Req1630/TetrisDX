#pragma once

#include "..\GameObject.h"

#include <vector>

//-------------------------.
// テトリミノ情報.
//-------------------------.
struct stTetrimino
{
	std::vector<IntVec2D>	m_Positions;	// 各ブロックの座標.
	EColor					m_Color;		// 各ブロックの色.
	bool					m_IsRotation;	// 回転するか.
} typedef STetrimino ;

/********************************
*	ブロック(テトリミノ)クラス.
**/
class CTetrimino : public CGameObject
{
public:
	CTetrimino();
	CTetrimino( 
		const std::vector<IntVec2D>& pos,
		const EColor& color,
		const bool& isRot );
	virtual ~CTetrimino();

	// 更新関数.
	virtual void Update() override;
	// 描画関数.
	virtual void Draw() override;

	// 左回転.
	void LeftRotation();
	// 右回転.
	void RightRotation();

	// ミノ座標の取得.
	std::vector<IntVec2D> GetMinoPos(){ return m_NowPositions; }

private:
	static constexpr int	BROCK_NUM_MAX = 4;	// ブロックの最大数.

private:
	std::vector<IntVec2D>	m_NowPositions;	// 各ブロックの座標.
	std::vector<IntVec2D>	m_OldPositions;	// 各ブロックの座標.
	EColor					m_Color;		// 各ブロックの色.
	bool					m_IsRotation;	// 回転するか.
};