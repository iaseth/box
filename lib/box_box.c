#include "box_box.h"

#include <stdio.h>



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
	unsigned int last_index = owner->boxes_count - 1;
	for (int i = 0; i < owner->boxes_count; ++i) {
		Box current_box = owner->boxes[i];
		if (current_box == box) {
			if (box->memory != NULL) {
				free(box->memory);
			}
			free(box);
			owner->boxes[i] = NULL;
			owner->boxes_count--;
			if (i != last_index) {
				owner->boxes[i] = owner->boxes[last_index];
				owner->boxes[last_index] = NULL;
			}
		}
	}
	return NULL;
}


