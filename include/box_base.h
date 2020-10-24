#ifndef BOX_BASE_H_IS_INCLUDED
#define BOX_BASE_H_IS_INCLUDED

#include <stdlib.h>

#include "box_types.h"


BoxOwner box_new_owner (char *name);
BoxOwner box_delete_owner (BoxOwner owner);

Box box_new (BoxOwner owner, size_t size);
Box box_delete (BoxOwner owner, Box box);



#endif