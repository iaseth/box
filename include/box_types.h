#ifndef BOX_TYPES_H_IS_INCLUDED
#define BOX_TYPES_H_IS_INCLUDED

#include <stdlib.h>

#define BOX_MAX_NAME_LENGTH 100
#define BOX_MIN_NUMBER_OF_CHILDREN 8
#define BOX_MIN_NUMBER_OF_SLOTS 32


struct BoxOwnerStruct;
struct BoxStruct;

typedef struct BoxOwnerStruct BoxOwnerStruct;
typedef struct BoxStruct BoxStruct;

typedef struct BoxOwnerStruct *BoxOwner;
typedef struct BoxStruct *Box;


struct BoxOwnerStruct {
	char name[BOX_MAX_NAME_LENGTH];

	BoxOwner parent;
	BoxOwner *children;
	unsigned int children_slots;
	unsigned int children_count;

	Box *boxes;
	unsigned int boxes_slots;
	unsigned int boxes_count;
	size_t bytes_allocated;
};

struct BoxStruct {
	void *memory;
	unsigned int size;
};



#endif