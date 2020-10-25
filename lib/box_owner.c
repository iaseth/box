#include "box_owner.h"

#include <stdio.h>
#include <string.h>



BoxOwner
box_new_owner (char *name)
{
	BoxOwner owner = malloc(sizeof(BoxOwnerStruct));
	strcpy(owner->name, name);
	owner->parent = NULL;
	owner->first_child = NULL;
	owner->last_child = NULL;

	owner->slots = malloc(sizeof(Box) * BOX_MIN_NUMBER_OF_SLOTS);
	for (int i = 0; i < BOX_MIN_NUMBER_OF_SLOTS; ++i) {
		owner->slots[i] = NULL;
	}
	owner->number_of_slots = BOX_MIN_NUMBER_OF_SLOTS;

	owner->boxes_currently_allocated = 0;
	owner->boxes_currently_in_use = 0;
	owner->bytes_currently_allocated = 0;
	owner->bytes_currently_in_use = 0;
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
			printf("\tSlot #%-3d is of %d bytes.\n", i, box->size);
		}
	}
	printf("\tTotal slots: %d\n", owner->number_of_slots);
}


