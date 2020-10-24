#ifndef BOX_BOX_H_IS_INCLUDED
#define BOX_BOX_H_IS_INCLUDED

#include <stdlib.h>

#include "box_types.h"


Box box_new (BoxOwner owner, size_t size);
Box box_delete (BoxOwner owner, Box box);



#endif