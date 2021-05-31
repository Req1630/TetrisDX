/**
* @file FrameRate.h.
* @brief �Q�[�����[�v�̃t���[�����[�g���v�Z����N���X.
* @author ���c���.
*/
#ifndef FRAME_RATE_H
#define FRAME_RATE_H

#include <Windows.h>

/********************************************
*	�t���[�����[�g�̌v���N���X.
**/
class CFrameRate
{
public:
	CFrameRate();
	CFrameRate( const double& fps = 60.0 );
	~CFrameRate();

	// �ҋ@�֐�.
	//	true �̏ꍇ���̃t���[�����I������.
	bool Wait();

	// FPS�̎擾.
	inline double GetFPS() const { return m_FPS; }
	// �f���^�^�C���̎擾.
	static inline double GetDeltaTime(){ return m_FrameTime; }

private:
	const double	FRAME_RATE;		// �t���[�����[�g.
	const double	MIN_FRAME_TIME;	// �ŏ��t���[���^�C��.

private:
	static double	m_FrameTime;	// �t���[���^�C��(�f���^�^�C��).
	double			m_FPS;			// ���݂�FPS.
	LARGE_INTEGER	m_StartTime;	// �J�n����.
	LARGE_INTEGER	m_NowTime;		// ���݂̎���.
	LARGE_INTEGER	m_FreqTime;		// �N����������.
};

// �f���^�^�C���̎擾.
template<class T = float>
static inline T GetDeltaTime()
{
	return static_cast<T>(CFrameRate::GetDeltaTime());
}

#endif	// #ifndef FRAME_RATE_H.