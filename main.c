
#include "headerFile.h"

int main(int argc, char **argv) {
	// Load config files, if any.

	// get home directory
	getcwd(home_dir, 1024);
	next = 0;
	// Run command loop.
	signal(SIGTSTP, clash_ctrlz);
	signal(SIGINT, clash_ctrlc);
	clash_loop();

	// Perform any shutdown/cleanup.

	return EXIT_SUCCESS;
}
