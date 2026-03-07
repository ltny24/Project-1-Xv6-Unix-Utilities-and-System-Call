#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

void
tree(char *path, int depth)
{
	char buf[512], *p;
	int fd;
	struct dirent de;
	struct stat st;

	if ((fd = open(path, O_RDONLY)) < 0) {
		fprintf(2, "tree: cannot open %s\n", path);
		return;
	}

	if (fstat(fd, &st) < 0) {
		fprintf(2, "tree: cannot stat %s\n", path);
		close(fd);
		return;
	}

	// Print indentation base on depth
	for (int i = 0; i < depth; i++) {
		printf("  ");
	}

	// Get the base name of the file/directory to print it
	char *name = path;
	for (char *temp = path; *temp; temp++) {
		if (*temp == '/') {
			name = temp + 1;
		}
	}
	if (st.type == T_DIR) {
		printf("%s/\n", name);
	} else {
		printf("%s\n", name);
	}

	if (st.type == T_DIR) {
		// Ensure path (path + '/' + longest name possible for file/dir + '\0') is not too long for the buffer
		if (strlen(path) + 1 + DIRSIZ + 1 > sizeof buf) {
			printf("tree: path too long\n");
			close(fd);
			return;
		}

		// Setup the buffer with the current path + '/'
		strcpy(buf, path);
		p = buf + strlen(buf);
		*p++ = '/';

		while (read(fd, &de, sizeof(de)) == sizeof(de)) {
			if (de.inum == 0) {
				continue;
			}

			if (strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0) {
				continue;
			}

			memmove(p, de.name, DIRSIZ);
			p[DIRSIZ] = 0;

			tree(buf, depth + 1);
		}
	}
	close(fd);
}

int
main(int argc, char *argv[])
{
	if (argc > 2) {
		fprintf(2, "Usage: tree <directory>\n");
		exit(1);
	}

	if (argc == 2) {
		tree(argv[1], 0);
	} else {
		tree(".", 0);
	}

	exit(0);
}
