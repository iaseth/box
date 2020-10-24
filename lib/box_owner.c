#include "box_owner.h"

#include <string.h>



BoxOwner
box_new_owner (char *name)
{
	BoxOwner owner = malloc(sizeof(BoxOwnerStruct));
	strcpy(owner->name, name);
	return owner;
}

BoxOwner
box_delete_owner (BoxOwner owner)
{
	free(owner);
	return NULL;
}


