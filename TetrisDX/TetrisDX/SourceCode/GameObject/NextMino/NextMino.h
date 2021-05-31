#pragma once

#include "..\Tetrimino\Tetrimino.h"
#include <queue>

/*************************************
*	ネクストミノクラス(次のミノを作成するクラス).
**/
class CNextMino : public CGameObject
{
public:
	CNextMino();
	virtual ~CNextMino();

	// 更新関数.
	virtual void Update() override;
	// 描画関数.
	virtual void Draw() override;
	
	// ミノの取得.
	STetrimino GetMino()
	{
		return m_pMinoQueue.front();
	}

private:
	std::queue<STetrimino> m_pMinoQueue;
};