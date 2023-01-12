// stripped down from tests/dnet/rand.c

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <dumbnet.h>

int
main(int argc, char *argv[])
{
	rand_t *r;
	int len;
	u_char *p;
	
	if ((len = atoi(argv[1])) == 0)
		err(1, "length");

	if ((p = malloc(len)) == NULL)
		err(1, "malloc");

	if ((r = rand_open()) == NULL)
		err(1, "rand_init");

	if (rand_get(r, p, len) < 0)
		err(1, "rand_get");
	
	if (write(STDOUT_FILENO, p, len) != len)
		err(1, "write");
	
	return (0);
}
