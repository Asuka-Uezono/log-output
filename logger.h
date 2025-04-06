#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	INFO,
	WARNING,
	ERROR,
	DEBUG
} LogLevel;

void log_info(const char* message);
void log_warning(const char* message);
void log_error(const char* message);
void log_debug(const char* message);

// 出力先をファイルに変更(NULLを渡すと標準出力に戻る)
void set_log_file(const char* filename);

#ifdef __cplusplus
}
#endif

#endif // LOGGER_H
