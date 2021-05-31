#pragma once

#include "..\GameObject.h"
#include "..\Tetrimino\Tetrimino.h"
#include "..\NextMino\NextMino.h"

#include <string>

// �u���b�N�ԍ�.
enum class enBlockNo
{
	None,	// �����Ȃ����.
	Wall,	// ��.
	Plant,	// �u���ꂽ�u���b�N.
	Future,	// �\���p�̃u���b�N.

	Max,

} typedef EBlockNo;

// �u���b�N�̐F.
struct stBlockInfo
{
	EBlockNo	BlockNo;	// �u���b�N�ԍ�.
	EColor		Color;		// �u���b�N�̐F.
	std::string	String;		// ����.

	stBlockInfo()
		: BlockNo	( EBlockNo::None )
		, Color		( EColor::L_BLACK )
		, String	( "�@" )
	{}
} typedef SBlockInfo;

// �t�B�[���h.
using field = std::vector<std::vector<SBlockInfo>>;

/*************************************
*	�t�B�[���h�N���X.
**/
class CField : public CGameObject
{
public:
	CField();
	virtual ~CField();

	// �X�V�֐�.
	virtual void Update() override;
	// �`��֐�.
	virtual void Draw() override;

private:
	field						m_Field;
	std::unique_ptr<CNextMino>	m_NextMino;
	std::shared_ptr<CTetrimino>	m_pMino;
};