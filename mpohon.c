//driver pohon

#include "pohon.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
  TriTree T1;
  TriTree T2;
  TriTree T3;
  paddress P;
  P = Allocate(5);
  if (Visited(P)) {
    printf ("Salah\n");
  } else {
    printf ("Anda benaaar!!\n");
  }
  
  T1 = Allocate(1);
  T2 = Allocate(2);
  T3 = Allocate(3);
  printf("%.2f %.2f %.2f\n", Info(T1), Info(T2), Info(T3));
  TriTree T;
  T = Tree(4, T1, T2, T3);
  printf("%.2f %.2f %.2f %.2f\n", Info(T), Info(Next1(T)), Info(Next2(T)), Info(Next3(T)));
  printf("%.2f %.2f %.2f\n", Info(Prev(T1)), Info(Prev(T2)), Info(Prev(T3)));
  
  TriTree T11;
  TriTree T12;
  InsertAfter(T1, 9, &T11);
  InsertAfter(T1, 8, &T12);
  printf("%x = %.2f, %x = %.2f\n", T11, Info(T11), T12, Info(T12));
  
  PrintTrace(T12);
  printf("\n");  
  float *a;
  a = PrintTraceToArray(T12);
  for (int i=0; i<=Level(T12); i++) {
    printf("%.2f->", a[i]);
  }
  printf("\n");
  
  TriTree T13;
  InsertAfter(T1, 2.5, &T13);
  a = PrintTraceToArray(T13);
  for (int i=0; i<=Level(T13); i++) {
    printf("%.2f->", a[i]);
  }
  printf("\n");
  
  TriTree T1n;
  InsertAfter(T1, 5.5, &T1n);
  
  return 0;
}
