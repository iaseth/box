#ifndef BOX_BX_H_IS_INCLUDED
#define BOX_BX_H_IS_INCLUDED

#include "box_types.h"

struct BoxBxStruct;

typedef const struct BoxBxStruct* (*BoxAllocatorFunction) (BoxOwner owner, unsigned int length);

struct BoxBxStruct {
	int status_code;

	BoxOwner (*new_owner) (char *title);
	BoxOwner (*delete_owner) (BoxOwner owner);
};

extern const struct BoxBxStruct *const bx;



#endif