#include "box_box.h"



Box
box_new (BoxOwner owner, size_t size)
{
	if (owner == NULL) return NULL;
	Box box = malloc(sizeof(BoxStruct));
	box->memory = malloc(size);
	box->size = size;
	return box;
}

Box
box_delete (BoxOwner owner, Box box)
{
	if (owner == NULL) return NULL;
	if (box == NULL) return NULL;
	if (box->memory != NULL) {
		free(box->memory);
	}
	free(box);
	return NULL;
}


