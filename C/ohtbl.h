/*
 * ohtbl.h
 *
 *  Created on: 2016Äê2ÔÂ17ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef C_OHTBL_H_
#define C_OHTBL_H_

#include <stdlib.h>

typedef struct OHTbl_
{
	int positions;
	void *vacated;

	int (*h1)(const void *key);
	int (*h2)(const void *key);
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);

	int size;
	void **table;
} OHTbl;

int ohtbl_init(OHTbl *htbl, int positions, int (*h1)(const void *key),
		int (*h2)(const void *key),
		int (*match)(const void *key1, const void *key2),
		void (*destroy)(void *data));

void ohtbl_destroy(OHTbl *htbl);

int ohtbl_insert(OHTbl *htbl, const void *data);

int ohtbl_remove(OHTbl *htbl, void **data);

int ohtbl_lookup(const OHTbl *htbl, void **data);

#define ohtbl_size(htbl) ((htbl)->size)

#endif /* C_OHTBL_H_ */
