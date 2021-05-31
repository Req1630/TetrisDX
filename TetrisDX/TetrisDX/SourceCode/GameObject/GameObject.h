#pragma once

#include "..\Console\Console.h"

template<typename T>
struct Vector2D
{
	T x;
	T y;
	Vector2D()
		: x ( 0 ) , y ( 0 )
	{} 
	Vector2D( const T& _x, const T& _y )
		: x ( _x ) , y ( _y )
	{} 
};

using IntVec2D		= Vector2D<int>;
using FloatVec2D	= Vector2D<float>;

/*********************************
*	�Q�[���I�u�W�F�N�g���N���X.
**/
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

	// �X�V�֐�.
	virtual void Update() = 0;
	// �`��֐�.
	virtual void Draw() = 0;
};