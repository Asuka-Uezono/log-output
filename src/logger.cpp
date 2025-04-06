#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

// デフォルトのログ出力先は標準出力
static FILE* log_output = NULL;

// 内部関数：ログメッセージを出力
static void log_message(LogLevel level, const char* message) {
	if (log_output == NULL) {
	    log_output == stdout;
	}

	const char* level_str;
	switch (level) {
		case INFO: level_str = "[INFO] "; break;
		case WARNING: level_str = "[WARNING] "; break;
		case ERROR: level_str = "[ERROR] "; break;
		case DEBUG: level_str = "[DEBUG] "; break;
		default: level_str = "[INFO] "; break;
	}

	fprintf(log_output, "%s%s\n", level_str, message);
	fflush(log_output);
}

void log_info(const char* message) {
	log_message(INFO, message);
}

void log_warning(const char* message) {
	log_message(WARNING, message);
}

void log_error(const char* message) {
	log_message(ERROR, message);
}

void log_debug(const char* message) {
	log_message(DEBUG, message);
}

void set_log_file(const char* filename) {
	if (log_output != NULL && log_output != stdout) {
		fclose(log_output);
	}

	if (filename == NULL) {
		log_output = stdout;
	} else {
		log_output = fopen(filename, "a");
		if (log_output == NULL) {
			perror("ログファイルを開けませんでした");
			exit(EXIT_FAILURE);
		}
	}
}
