#include "..\Console\Console.h"
#include "..\FrameRate\FrameRate.h"
#include "..\GameObject\Tetrimino\Tetrimino.h"
#include "..\GameObject\Field\Field.h"

#define IS_FPS_RENDER (0)

int main()
{
	// コンソールの初期化.
	if( FAILED( CConsole::Init() )) return 0;

	std::unique_ptr<CFrameRate> pFPS = std::make_unique<CFrameRate>(60.0);

	std::unique_ptr<CField> f = std::make_unique<CField>();

	while(1)
	{
		if( pFPS->Wait() == false ) continue;
		// 以下アップデート処理.

		f->Draw();
#if IS_FPS_RENDER
		CConsole::Draw(1,1, pFPS->GetFPS());
#endif	// #ifdef IS_FPS_RENDER.
	}


	// コンソールの解放.
	if( FAILED( CConsole::Release() )) return 0;

	return 0;
};