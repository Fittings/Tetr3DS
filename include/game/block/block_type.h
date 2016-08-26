#ifndef BLOCK_TYPE_H_
#define BLOCK_TYPE_H_

typedef enum {
	BLOCK_TYPE_USER, //Standard Block. It's controlled at some time by the User.
	BLOCK_TYPE_PERMENANT,//Permenant piece. Cannot be cleared normally.
	BLOCK_TYPE_BACKGROUND //A background block. Is not interactable and has no affect on gameplay.
} BlockType;


#endif
