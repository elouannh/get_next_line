#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("test", O_RDONLY);
	char *buffer;
	int i = 0;
	while ((buffer = get_next_line(fd))) {
		printf("%s", buffer);
		// TODO: fix le nombre d'allocations sur un crash de lecture
		if (i == 10) close(fd);
		i++;
	}
}
