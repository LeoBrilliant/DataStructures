/*
 * search.h
 *
 *  Created on: 2016��2��29��
 *      Author: LeoBrilliant
 */

#ifndef C_SEARCH_H_
#define C_SEARCH_H_


int bisearch(void *sorted, const void *target, int size, int esize, int(*compare)(const void *key1, const void *key2));


#endif /* C_SEARCH_H_ */
