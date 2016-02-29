/*
 * sort.h
 *
 *  Created on: 2016��2��29��
 *      Author: LeoBrilliant
 */

#ifndef C_SORT_H_
#define C_SORT_H_

int issort(void *data, int size, int esize, int(*compare)(const void *key1, const void *key2));

int qksort(void *data, int size, int esize, int i, int k, int(*compare)(const void *key1, const void *key2));

#endif /* C_SORT_H_ */
