#ifndef BOX_OWNER_H_IS_INCLUDED
#define BOX_OWNER_H_IS_INCLUDED

#include <stdlib.h>

#include "box_types.h"


BoxOwner box_new_owner (char *name);
BoxOwner box_delete_owner (BoxOwner owner);



#endif