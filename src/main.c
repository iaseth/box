#include <stdio.h>

#include "box.h"

int
main (int argc, char const *argv[])
{
	BoxOwner owner = box_new_owner("Hector");
	Box box = box_new(owner, 20);
	box_print_slots(owner);
	box = box_delete(owner, box);
	box_print_slots(owner);
	owner = box_delete_owner(owner);
}
