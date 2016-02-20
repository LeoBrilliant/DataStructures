/*
 * traverse.h
 *
 *  Created on: 2016��2��20��
 *      Author: LeoBrilliant
 */

#ifndef C_TRAVERSE_H_
#define C_TRAVERSE_H_


#include "bitree.h"

int preorder(const BiTreeNode *node, List *list);
int inorder(const BiTreeNode *node, List *list);
int postorder(const BiTreeNode *node, List *list);

#endif /* C_TRAVERSE_H_ */
