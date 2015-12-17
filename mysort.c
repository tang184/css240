#include "mysort.h"
#include <alloca.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//

//
// See test_sort to see how to use mysort.
/**
 * @brief Arbitrary sort func
 *
 * Sort an array of element of any type
 * using "compFunc" to sort the elements.
 * 
 * The elements are sorted such as:
 * 
 * if ascending != 0
 *   compFunc( array[ i ], array[ i+1 ] ) <= 0
 * else
 *   compFunc( array[ i ], array[ i+1 ] ) >= 0
 * 
 * @param n Number of elements.
 * @param elementSize Size of each element.
 * @param array Pointer to an array of arbitrary type.
 * @param ascending Boolean controlling the direction of the sort.
 * @param compFunc Comparison funciton.
 **/
void mysort(int n, int elementSize, void * array, int ascending, CompareFunction compFunc)
{
	/** @todo **/
	void * tmp = malloc(elementSize);
	int i = 0;
	for (i = 0; i < n - 1; i++) {
		void *a = (void*) ((char*)array + i * elementSize);
		int j;
		for (j = i + 1; j < n; j++) {
			void *b = (void*) ((char*)array + j * elementSize);
			if (ascending) {
				if (compFunc(a, b) >= 0) {
					memcpy(tmp, a, elementSize);
					memcpy(a,b,elementSize);
					memcpy(b, tmp, elementSize);
				}
			} else {
				if (compFunc(a, b) <= 0) {
					memcpy(tmp, a, elementSize);
					memcpy(a,b,elementSize);
					memcpy(b, tmp, elementSize);
				}
			}
		}
	}
}

