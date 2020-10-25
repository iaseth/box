#ifndef BOX_BOX_H_IS_INCLUDED
#define BOX_BOX_H_IS_INCLUDED

#include "box_types.h"


void* box_new (BoxOwner owner, size_t size);
void* box_delete (BoxOwner owner, void *memory);



#endif