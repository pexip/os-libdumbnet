// stripped down from tests/dnet/addr.c

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <dumbnet.h>

int
main(int argc, char *argv[])
{
	struct addr addr;
	int c, len;
	
	for (c = 1; c < argc; c++) {
		if (addr_aton(argv[c], &addr) < 0)
			err(1, "length");
		
		len = addr.addr_bits / 8;
		
		if (write(STDOUT_FILENO, addr.addr_data8, len) != len)
			err(1, "write");
	}
	exit(0);
}
