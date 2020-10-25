#include "box_owner.h"

#include <string.h>



BoxOwner
box_new_owner (char *name)
{
	BoxOwner owner = malloc(sizeof(BoxOwnerStruct));
	strcpy(owner->name, name);
	owner->slots = malloc(sizeof(Box) * BOX_MIN_NUMBER_OF_SLOTS);
	owner->slots_length = BOX_MIN_NUMBER_OF_SLOTS;
	return owner;
}

BoxOwner
box_delete_owner (BoxOwner owner)
{
	free(owner->slots);
	free(owner);
	return NULL;
}


