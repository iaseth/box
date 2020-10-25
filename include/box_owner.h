#ifndef BOX_OWNER_H_IS_INCLUDED
#define BOX_OWNER_H_IS_INCLUDED

#include "box_types.h"


BoxOwner box_new_owner (char *name);
BoxOwner box_delete_owner (BoxOwner owner);

void box_print_slots (BoxOwner owner);



#endif