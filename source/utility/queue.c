#include "../include/utility/queue.h"

//Implementation specific includes
#include <malloc.h>



struct _Node
{
	void *item;

	Node *next_node;
};

struct _Queue
{
	Node *head_node;

	u32 current_size;
	u32 upper_bound;
};


static Node *create_node(void *item)
{
	Node *self = malloc(sizeof *self);
	if (!self) return NULL;

	return self;
}

Queue *queue_init(u32 max_size)
{
	Queue *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->head_node = NULL;

		self->current_size = 0;
		self->upper_bound = max_size;
	}

	return self;
}


bool queue_is_full(Queue *queue)
{
	return (queue->current_size >= queue->upper_bound);
}

int queue_get_size(Queue *queue)
{
	return queue->current_size;
}


static Node *get_last_node(Queue *queue)
{
	Node *current_node = queue->head_node;

	while (current_node != NULL)
	{
		current_node = current_node->next_node;
	}

	return current_node;
}


void queue_add(Queue *queue, void *item)
{
	if (!queue_is_full(queue))
	{
		Node *current_node = get_last_node(queue);

		queue->current_size++;
		current_node->next_node = create_node(item);
	}
}

void *piece_queue_pop(Queue *queue)
{
	if (queue_get_size(queue) <= 0) return NULL;

	Node *old_head = queue->head_node;
	queue->head_node = old_head->next_node;
	queue->current_size--;

	return old_head->item;
}
