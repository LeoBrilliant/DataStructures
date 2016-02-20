/*
 * heap.h
 *
 *  Created on: 2016Äê2ÔÂ20ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef C_HEAP_H_
#define C_HEAP_H_

typedef struct Heap_
{
	int size;
	int (*compare)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	void **tree;
}Heap;

void heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2),
		void (*destroy)(void *data));

void heap_destroy(void *data);

int heap_insert(Heap *heap, const void *data);

int heap_extract(Heap *heap, void **data);

#define heap_size(heap) ((heap)->size)

#endif /* C_HEAP_H_ */
