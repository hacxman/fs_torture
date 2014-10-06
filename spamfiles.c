#include <sys/stat.h>
#include <errno.h>

int main(int argc, char * argv[]) {
	char n[64];
	if (argc < 2) {
		printf("usage: %s prefix", argv[0]);
		return 1;
	}
	for (int i=0; ; i++) {
		sprintf(n, "%s%li", argv[1], i);
		int fd = creat(n, 0666);
		if (fd < 0) {
			perror(n);
			return 1;
		}
		close(fd);
		if (i & 0xffff == 1) {
			printf("%s: %li", argv[1], i);
		}
	}
	return 0;
}
