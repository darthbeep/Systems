#include <stdio.h>
#include <math.h>

int blocked[1000000] = {0};

int length(long test) {
  long n = test;
  int len = 0;
  //printf("%s%ld\n","not" ,n);
  while (n != 1) {
    //printf("%s%ld\n","very",n );
    if (n < 1000000) {
      if (blocked[n] != 0) {
        return len + blocked[n];
      }
      //blocked[n] = len(n);
    }
    if (n % 2 == 0) {
      n = n/2;
    }
    else {
      n = (3 *n) + 1;
    }
    if (n < 1000000) {
      blocked[n] = length(n);
    }
    len++;
  }
  //printf("%s %d\n","fun", len );
  return len + 1;
}
/*int storagelen(long get) {
  long n = get;
  int len = 0;
  //printf("%s%ld\n","not" ,n);
  while (n != 1) {
    //printf("%s%ld\n","very",n );
    if (n < 1000000) {
      if (blocked[n] != 0) {
        return len + blocked[n];
      }
      blocked[n] = len;
    }
    if (n % 2 == 0) {
      n = n/2;
    }
    else {
      n = (3 *n) + 1;
    }
    len++;
  }
  //printf("%s %d\n","fun", len );
  return len + 1;
}*/
int main(int argc, char const *argv[]) {
  //printf("%s\n","test" );
  int lenstore = 0;
  int longstore = 0;
  for (long i = 1; i <  1000000; i++) {
    /* code */
    //printf("%s %d\n", "ing",i );
    if (blocked[i] == 0) {
      //printf("%d is %d\n", "is",i );
      int newlen = length(i);
      if (newlen > lenstore) {
        lenstore = newlen;
        longstore = i;
      }
      //printf("%ld: %d\n",i, newlen);
    }
  }
  printf("%ld is the longest, with a length of %d\n", longstore, lenstore);
  return 0;
}
