#include "box_owner.h"
#include "box_box.h"

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
	owner->children_slots = BOX_MIN_NUMBER_OF_CHILDREN;
	owner->children_count = 0;

	owner->boxes = malloc(sizeof(Box) * BOX_MIN_NUMBER_OF_SLOTS);
	for (int i = 0; i < BOX_MIN_NUMBER_OF_SLOTS; ++i) {
		owner->boxes[i] = NULL;
	}
	owner->boxes_slots = BOX_MIN_NUMBER_OF_SLOTS;
	owner->boxes_count = 0;
	owner->bytes_allocated = 0;
	return owner;
}

BoxOwner
box_delete_owner (BoxOwner owner)
{
	free(owner->children);
	for (int i = 0; i < owner->boxes_count; ++i) {
		Box box = owner->boxes[i];
		if (box != NULL) {
			box_delete(owner, box);
		}
	}
	free(owner->boxes);
	free(owner);
	return NULL;
}



void
box_print_slots (BoxOwner owner)
{
	printf("\tName: %s (%d slots, %d allocated)\n",
		owner->name,
		owner->boxes_slots, owner->boxes_count
	);
	for (int i = 0; i < owner->boxes_slots; ++i) {
		Box box = owner->boxes[i];
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
	printf("\tTotal slots: %d\n", owner->boxes_slots);
}


