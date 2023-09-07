#include <Novice.h>
#include <stdio.h>

const char kWindowTitle[] = "ランキング";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	const int kRankMax = 5;
	int scoreNums[kRankMax] = { 10,20,30,40,50 };

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ソート
	for (int i = 0; i < kRankMax; i++)
	{
		int searchIndex = i;

		for (int j = i; j < kRankMax; j++)
		{
			if (scoreNums[j] > scoreNums[searchIndex])
			{
				searchIndex = j;
			}
		}
		int temp = scoreNums[searchIndex];
		scoreNums[searchIndex] = scoreNums[i];
		scoreNums[i] = temp;
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		FILE* fp;

		char fname[] = " ";

		errno_t err;

		err = fopen_s(&fp, fname, "r");

		if (err != 0){
			printf(" ", fname);
			return err;
		}else{
			printf("", fname);
		}

		fclose(fp);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
