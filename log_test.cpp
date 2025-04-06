#include "logger.h"

int main() {
	log_info("これはinfoログです。");
	log_warning("これはwarningログです。");
	log_error("これはerrorログです。");
	log_debug("これはdebugログです。");

	return 0;
}
