#pragma once

#include "..\Tetrimino\Tetrimino.h"
#include <queue>

/*************************************
*	�l�N�X�g�~�m�N���X(���̃~�m���쐬����N���X).
**/
class CNextMino : public CGameObject
{
public:
	CNextMino();
	virtual ~CNextMino();

	// �X�V�֐�.
	virtual void Update() override;
	// �`��֐�.
	virtual void Draw() override;
	
	// �~�m�̎擾.
	STetrimino GetMino()
	{
		return m_pMinoQueue.front();
	}

private:
	std::queue<STetrimino> m_pMinoQueue;
};