CXX = g++
CXXFLAGS = -Wall -g -Iinclude -I/path/to/doctest
# 静的ライブラリ作成に使用するアーカイバ
AR = ar
LDFLAGS = -L. -llogger
# ログ出力ライブラリの定義
LIB_LOGGER = liblogger.a
LIB_LOGGER_OBJS = src/logger.o

# デフォルトターゲット
all: log_test test_logger

# ログライブラリのビルド
$(LIB_LOGGER): $(LIB_LOGGER_OBJS)
	$(AR) rcs $@ $^

src/logger.o: src/logger.cpp include/logger.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ログライブラリの動作確認用の簡単なバイナリ
log_test: examples/log_test.o $(LIB_LOGGER)
	$(CXX) -o $@ $^ $(LDFLAGS)

exapmles/log_test.o: examples/log_test.cpp include/logger.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# doctestを使った単体テストのビルド
test_logger: tests/test_logger.o $(LIB_LOGGER)
	$(CXX) -o $@ $^ $(LDFLAGS)

tests/test_logger.o: tests/test_logger.cpp include/logger.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
# make test: テストの実行
test: test_logger
	./test_logger

clean:
	rm -f *.o *.a log_test test_logger examples/*.o tests/*.o test_output.log

.PHONY: all clean test
