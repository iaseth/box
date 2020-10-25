#include "box_owner.h"

#include <stdio.h>
#include <string.h>



BoxOwner
box_new_owner (char *name)
{
	BoxOwner owner = malloc(sizeof(BoxOwnerStruct));
	strcpy(owner->name, name);
	owner->slots = malloc(sizeof(Box) * BOX_MIN_NUMBER_OF_SLOTS);
	owner->number_of_slots = BOX_MIN_NUMBER_OF_SLOTS;
	return owner;
}

BoxOwner
box_delete_owner (BoxOwner owner)
{
	free(owner->slots);
	free(owner);
	return NULL;
}



void
box_print_slots (BoxOwner owner)
{
	printf("Called %s on %s:\n", __func__, owner->name);
	for (int i = 0; i < owner->number_of_slots; ++i) {
		Box box = owner->slots[i];
		if (box == NULL) {
			printf("\tSlot #%-3d is NULL.\n", i);
		} else {
			printf("\tSlot #-%3d is not NULL.\n", i);
		}
	}
	printf("\tTotal slots: %d\n", owner->number_of_slots);
}


