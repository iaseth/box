#include "box_box.h"

#include <stdio.h>



void *
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
	return box->memory;
}

void *
box_delete (BoxOwner owner, void *memory)
{
	if (owner == NULL) return NULL;
	if (memory == NULL) return NULL;
	unsigned int last_index = owner->boxes_count - 1;
	for (int i = 0; i < owner->boxes_count; ++i) {
		Box box = owner->boxes[i];
		if (box->memory == memory) {
			free(box->memory);
			free(box);
			owner->boxes[i] = NULL;
			owner->boxes_count--;
			if (i != last_index) {
				owner->boxes[i] = owner->boxes[last_index];
				owner->boxes[last_index] = NULL;
			}
			break;
		}
	}
	return NULL;
}

void *
box_new_int_array (BoxOwner owner, int length)
{
	size_t size = sizeof(int) * length;
	return box_new(owner, size);
}


