#include "box_owner.h"

#include <stdio.h>
#include <string.h>



BoxOwner
box_new_owner (char *name)
{
	BoxOwner owner = malloc(sizeof(BoxOwnerStruct));
	strcpy(owner->name, name);
	owner->parent = NULL;
	owner->children = malloc(sizeof(BoxOwner) * BOX_MIN_NUMBER_OF_CHILDREN);
	for (int i = 0; i < BOX_MIN_NUMBER_OF_CHILDREN; ++i) {
		owner->children[i] = NULL;
	}
	owner->number_of_children = BOX_MIN_NUMBER_OF_CHILDREN;

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
	free(owner->children);
	free(owner->slots);
	free(owner);
	return NULL;
}



void
box_print_slots (BoxOwner owner)
{
	printf("\tName: %s (%d slots, %d allocated, %d in use)\n",
		owner->name, owner->number_of_slots,
		owner->boxes_currently_allocated, owner->boxes_currently_in_use
	);
	for (int i = 0; i < owner->number_of_slots; ++i) {
		Box box = owner->slots[i];
		printf("\t#%-3d ", i+1);
		if (box == NULL) {
			printf("....");
		} else {
			printf("%-4d", box->size);
		}
		if (i % 8 == 7) {
			printf("\n");
		}
	}
	printf("\tTotal slots: %d\n", owner->number_of_slots);
}


