#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(2, "usage: xargs command [args...]\n");
		exit(1);
	}

	int n;
	char *xargs_argv[MAXARG];
	char buf[512];

	for (int i = 1; i < argc; i++) {
		xargs_argv[i - 1] = argv[i];
	}

	while (1) {
		int arg_index = argc - 1;
		int index = 0;

		while ((n = read(0, &buf[index], 1)) > 0 && buf[index] != '\n') {
			index++;
		}

		if (n <= 0 && index == 0) {
			break;
		}

		buf[index] = '\0';
		xargs_argv[arg_index] = buf;
		xargs_argv[arg_index + 1] = 0; // Cap the arguments array with a 0 (null pointer) so exec knows where it ends

		if (fork() == 0) {
			exec(xargs_argv[0], xargs_argv);
			fprintf(2, "exec failed\n");
			exit(1);
		} else {
			wait(0);
		}
	}

	exit(0);
}
