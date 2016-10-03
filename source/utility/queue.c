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

	self->item = item;
	self->next_node = NULL;

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


void **queue_get_item_list(Queue *queue)
{
	if (queue->current_size <= 0) return NULL;

	void **item_list = malloc(queue->current_size * sizeof(void));

	Node *current_node = queue->head_node;
	for (int i=0; current_node->next_node != NULL; i++)
	{
		item_list[i] = current_node->item;
		current_node = current_node->next_node;
	}

	return item_list;
}


bool queue_is_full(Queue *queue)
{
	return (queue->current_size >= queue->upper_bound);
}

int queue_get_current_size(Queue *queue)
{
	return queue->current_size;
}


void queue_add(Queue *queue, void *item)
{
	if (queue_is_full(queue)) return;

	if (queue->head_node == NULL)
	{
		queue->head_node = create_node(item);
	}
	else
	{
		Node *current_node = queue->head_node;
		while (current_node->next_node != NULL)
		{
			current_node = current_node->next_node;
		}
		current_node->next_node = create_node(item);
	}

	queue->current_size++;
}

void *queue_pop(Queue *queue)
{
	if (queue_get_current_size(queue) <= 0) return NULL;

	Node *old_head = queue->head_node;
	queue->head_node = old_head->next_node;
	queue->current_size--;

	void *head_item = old_head->item;
	free(old_head);

	return head_item;
}
