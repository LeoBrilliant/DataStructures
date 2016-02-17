//list.cpp

#include <stdlib.h>
#include <string.h>
#include <cstdio>

#include "list.h"

//list_init
//初始化队列
void list_init(List *list, void(*destroy)(void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
	return;
}

//list_destroy
// 从头部依次移除链表元素
void list_destroy(List *list)
{
	void *data;
	while(list_size(list) > 0)
	{
		if( list_rem_next(list, NULL, (void **)&data) == 0 && 
			list->destroy != NULL)
		{
			list->destroy(data);
		}
	}

	memset(list, 0, sizeof(List));
	return;
}

//list_ins_next
//向队列中插入一个元素
int list_ins_next(List *list, ListElmt *element, const void *data)
{
	ListElmt *new_element;

	// 分配内存
	if((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL)
	{
		return -1;
	}
	// 建立数据与元素间的连接
	new_element->data = (void *)data;

	// 在链表头部插入数据
	if(element == NULL)
	{
		if(list_size(list) == 0)
		{
			list->tail = new_element;
		}	
		new_element->next = list->head;
		list->head = new_element;
	} 
	// 在element之后插入
	else
	{
			if(element->next == NULL)
			{
				list->tail = new_element;
			}
			new_element->next = element->next;
			element->next = new_element;
		
	}

	// 扩展空间
	list->size ++;

	return 0;
}

//list_rem_next
// 从链表中移除一个元素
int list_rem_next(List *list, ListElmt *element, void** data)
{
	ListElmt * old_element;

	if(list_size(list) == 0)
	{
		return -1;
	}

	// 从头部移除
	if(element == NULL)
	{
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;

		if(list_size(list) == 1)
		{
			list->tail = NULL;
		}
	}
	// 从element之后移除
	else
	{
		if(element->next == NULL)
		{
			return -1;
		}
		*data = element->next->data;
		old_element = element->next;
		element->next = element->next->next;

		if(element->next == NULL)
		{
			list->tail = element;
		}
	}

	free(old_element);

	list->size --;
	return 0;
}

void list_destroy(void *data)
{
	printf("数据被销毁啦\n");
}
