#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "logger.h"

// このテストファイルは、doctestを使ってloggerライブラリの基本的な動作を検証

TEST_CASE("log_info が例外を投げずに呼び出せる") {
	// todo: 出力をファイルにリダイレクトして検証してもいいが
	// まずは関数を呼び出せることを確認するだけ
	CHECK_NOTHROW(log_info("これは info レベルのテストログです。"));
}

TEST_CASE("log_warning が例外を投げずに呼び出せる") {
	// WARNINGログ出力の基本動作を確認
	CHECK_NOTHROW(log_warning("これは warning レベルのテストログです。"));
}

TEST_CASE("log_error が例外を投げずに呼び出せる") {
	// ERRORログ出力の基本動作を確認
	CHECK_NOTHROW(log_error("これは error レベルのテストログです。"));
}

TEST_CASE("set_log_file によってログ出力先をファイルに変更できる") {
	// ログ出力先を一時ファイルに設定し、log_errorを出力してみる
	CHECK_NOTHROW(set_log_file("test_output.log"));
	log_error("このログは test_output.log に記録されるはずです。");
	set_log_file(NULL); // 元に戻す

	// 出力先を元に戻す(標準出力に切り替える)
	CHECK_NOTHROW(set_log_file(NULL));
}
