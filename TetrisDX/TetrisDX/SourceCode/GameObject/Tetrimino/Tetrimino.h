#pragma once

#include "..\GameObject.h"

#include <vector>

//-------------------------.
// �e�g���~�m���.
//-------------------------.
struct stTetrimino
{
	std::vector<IntVec2D>	m_Positions;	// �e�u���b�N�̍��W.
	EColor					m_Color;		// �e�u���b�N�̐F.
	bool					m_IsRotation;	// ��]���邩.
} typedef STetrimino ;

/********************************
*	�u���b�N(�e�g���~�m)�N���X.
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

	// �X�V�֐�.
	virtual void Update() override;
	// �`��֐�.
	virtual void Draw() override;

	// ����].
	void LeftRotation();
	// �E��].
	void RightRotation();

	// �~�m���W�̎擾.
	std::vector<IntVec2D> GetMinoPos(){ return m_NowPositions; }

private:
	static constexpr int	BROCK_NUM_MAX = 4;	// �u���b�N�̍ő吔.

private:
	std::vector<IntVec2D>	m_NowPositions;	// �e�u���b�N�̍��W.
	std::vector<IntVec2D>	m_OldPositions;	// �e�u���b�N�̍��W.
	EColor					m_Color;		// �e�u���b�N�̐F.
	bool					m_IsRotation;	// ��]���邩.
};