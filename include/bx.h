#ifndef BOX_BX_H_IS_INCLUDED
#define BOX_BX_H_IS_INCLUDED

#include "box_types.h"

struct BoxBxStruct;

struct BoxBxStruct {
	int status_code;

	BoxOwner (*new_owner) (char *title);
	BoxOwner (*delete_owner) (BoxOwner owner);

	Box (*new_box) (BoxOwner owner, size_t size);
	Box (*delete_box) (BoxOwner owner, Box box);

	void* (*new) (BoxOwner owner, size_t size);
	void* (*delete) (BoxOwner owner, void *memory);

	struct BoxBxStruct* (*print_status) (BoxOwner owner);
	struct BoxBxStruct* (*print_slots) (BoxOwner owner);
};

extern const struct BoxBxStruct *const bx;



#endif