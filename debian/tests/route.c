// stripped down from tests/dnet/route.c

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <dumbnet.h>

static int
print_route(const struct route_entry *entry, void *arg)
{
	printf("%-20s %-20s\n",
	    addr_ntoa(&entry->route_dst), addr_ntoa(&entry->route_gw));
	return (0);
}

int
main(int argc, char *argv[])
{
	route_t *r;

	if ((r = route_open()) == NULL)
		err(1, "route_open");

        printf("%-20s %-20s\n", "Destination", "Gateway");
        if (route_loop(r, print_route, NULL) < 0)
                err(1, "route_loop");
	
	route_close(r);
	
	exit(0);
}
