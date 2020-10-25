#include "box_box.h"



Box
box_new (BoxOwner owner, size_t size)
{
	if (owner == NULL) return NULL;
	Box box = malloc(sizeof(BoxStruct));
	box->memory = malloc(size);
	box->size = size;
	if (owner->boxes_slots > owner->boxes_count) {
		int index = owner->boxes_count;
		owner->boxes[index] = box;
		owner->boxes_count++;
	}
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


