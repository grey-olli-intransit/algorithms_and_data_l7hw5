#ifndef SWAP_H
#define SWAP_H

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a=*b;
  *b=tmp;
}

#endif
