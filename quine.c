#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* f = fopen("quine.c", "r");
	if(f == NULL) {
		perror("fopen() failed");
		return EXIT_FAILURE;
	}

	int c;
	while((c = fgetc(f)) != EOF) {
		putchar(c);
	}
	fclose(f);
}
