#include <stdio.h>

#include "box.h"

int
main (int argc, char const *argv[])
{
	BoxOwner owner = bx->new_owner("Hector");
	int *arr = box_new_int_array(owner, 20);
	for (int i = 0; i < 20; ++i) {
		arr[i] = (i+1) * (i+1);
		printf("\tarr[%d] = %d", i, arr[i]);
		if (i % 4 == 3) {
			printf("\n");
		}
	}
	bx->print_slots(owner);
	owner = bx->delete_owner(owner);
}
