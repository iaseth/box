#ifndef BOX_TYPES_H_IS_INCLUDED
#define BOX_TYPES_H_IS_INCLUDED

#define MAX_NAME_LENGTH 100


struct BoxOwnerStruct;
struct BoxStruct;

typedef struct BoxOwnerStruct BoxOwnerStruct;
typedef struct BoxStruct BoxStruct;

typedef struct BoxOwnerStruct *BoxOwner;
typedef struct BoxStruct *Box;


struct BoxOwnerStruct {
	char name[MAX_NAME_LENGTH];

	BoxOwner parent;
	BoxOwner first_child;
	BoxOwner last_child;

	Box *boxes;
	int boxes_length;

	int boxes_currently_allocated;
	int boxes_currently_in_use;

	int bytes_currently_allocated;
	int bytes_currently_in_use;
};

struct BoxStruct {
	void *memory;
	int size;
};



#endif