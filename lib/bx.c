#include "bx.h"

#include "box_owner.h"

struct BoxBxStruct bx_struct = {
	.status_code = 0,
	.new_owner = &box_new_owner,
	.delete_owner = &box_delete_owner
};

const struct BoxBxStruct *const bx = &bx_struct;
