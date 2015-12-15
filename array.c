
#include <stdio.h>

#include "array.h"

// Return sum of the array
double sumArray(int n, double * array) {
  double sum = 0;
  
  double * p = array;
  double * pend = p+n;

  while (p < pend) {
    sum += *p;
    p++;
  }

  return sum;
}

// Return maximum element of array
double maxArray(int n, double * array) {
  double max = array[0];
  double *p = array;
  double *pend = p + n;
  while (p < pend) {
    if (*p > max) {
      max = *p;
    }
    p++;
  }
  return max;
}

// Return minimum element of array
double minArray(int n, double * array) {
  double min = array[0];
  double *p = array;
  double *pend = p + n;
  while (p < pend) {
    if (*p < min) {
      min = *p;
    }
    p++;
  }
  return min;
}

// Find the position int he array of the first element x 
// such that min<=x<=max or -1 if no element was found
int findArray(int n, double * array, double min, double max) {
  double *p = array;
  double *pend = p + n;
  while (p < pend) {
    if (*p >= min && *p <= max) {
      return p - array;
    }
    p++;
  }
  return -1;
}

// Sort array without using [] operator. Use pointers 
// Hint: Use a pointer to the current and another to the next element
int sortArray(int n, double * array) {
  double *p = array;
  double *q;
  double *pend = p + n;
  while (p < pend) {
    q = array;
    while (q < p) {
      if (*q > *p) {
        double m = *q;
        *q = *p;
        *p = m;
      }
      q++;
    }
    p++;
  }
  return 0;

}

// Print array
void printArray(int n, double * array) {
  double *p = array;
  double *pend = p + n;
  int i = 0;
  while (p < pend) {
    printf("%d:%lf\n",i,*p);
    p++;
    i++;
  }
}

