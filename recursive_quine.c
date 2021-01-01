#include <stdio.h>
#include <stdlib.h>

void recursive_quine(FILE* f, long int offset);

int main() {
	FILE* f = fopen("recursive_quine.c", "rb");
	if(f == NULL) {
		perror("fopen() failed");
		return EXIT_FAILURE;
	}
	recursive_quine(f, 0L);
	fclose(f);
	return 0;
}

void recursive_quine(FILE* f, long int offset) {
	// set file position offset number of bytes into the file
	// from start position
	int ret_code;
	ret_code = fseek(f, offset, SEEK_SET);
	if(ret_code != 0) {
		perror("fseek() call failed:");
		exit(EXIT_FAILURE);
	}
	
	// read characters until the newline or EOF
	int c;
	while( ((c = fgetc(f)) != '\n') && (c != EOF) ) {
		putchar(c);
	}
	if(c == '\n') {
		putchar(c);
		// get current file offset indicating number of bytes into the file	
		offset = ftell(f);
		if(offset == -1L) {
			perror("ftell() call failed");
			exit(EXIT_FAILURE);
		}
		
		// recurse, starting from that offset position
		recursive_quine(f, offset);
	} else {
		// c == EOF
		exit(EXIT_SUCCESS);
	}
}
