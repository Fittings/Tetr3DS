#ifndef INCLUDE_UTILITY_QUEUE_H_
#define INCLUDE_UTILITY_QUEUE_H_

#include <stdbool.h>
#include <3ds.h>

typedef struct _Node Node;
typedef struct _Queue Queue;


extern Queue *queue_init(u32 max_size);

extern void **queue_get_item_list(Queue *queue);

extern bool queue_is_full(Queue *queue);

extern int queue_get_current_size(Queue *queue);

extern void queue_add(Queue *queue, void *item);

extern void *queue_pop(Queue *queue);

#endif /* INCLUDE_UTILITY_QUEUE_H_ */
