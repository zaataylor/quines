all: quine recursive_quine 

quine: quine.c
	gcc -Wall -Werror -g -o quine quine.c

recursive_quine: recursive_quine.c
	gcc -Wall -Werror -g -o recursive_quine recursive_quine.c

clean:
	rm quine recursive_quine
