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
*	ゲームオブジェクト基底クラス.
**/
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

	// 更新関数.
	virtual void Update() = 0;
	// 描画関数.
	virtual void Draw() = 0;
};