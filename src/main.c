#include <stdio.h>

#include "box.h"

int
main (int argc, char const *argv[])
{
	BoxOwner owner = box_new_owner("Hector");
	owner = box_delete_owner(owner);
}
