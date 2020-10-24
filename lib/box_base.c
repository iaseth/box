#include "box_base.h"

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



Box
box_new (BoxOwner owner, size_t size)
{
	return NULL;
}

Box
box_delete (BoxOwner owner, Box box)
{
	return NULL;
}


