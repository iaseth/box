#include <stdio.h>

#include "box.h"

int
main (int argc, char const *argv[])
{
	BoxOwner owner = box_new_owner("Hector");
	int *arr;
	for (int i = 0; i < 20; ++i) {
		arr = box_new(owner, 20);
	}
	box_print_slots(owner);
	owner = box_delete_owner(owner);
}
