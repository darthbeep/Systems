#include <stdio.h>
#include <string.h>

int array[80][80][255];
int numarray[80][80];
int stophere[80][80];

void getInupt(/* arguments */) {
  FILE *fp;
  fp = fopen("/Users/shpeters/Desktop/Systems/pe81data.txt", "r");
  char hold[500];
  if (fp == NULL) {
    printf("sigh\n");
  }
  for (int i = 0; i < 80; i++) {
    fscanf(fp, "%s", hold);
    int k = 0;
    int past = 0;
    for (int j = 0; j < strlen(hold); j++) {
      char wait[255] = "";
      strncpy(wait, hold + j, 1);
      if (strcmp(wait, ",") == 0) {
        //printf("%s\n", array[i][k]);
        k++;
      }
      else {
        strcat(array[i][k],wait);
      }
    }
  }

  fclose(fp);

  for (int i = 0; i < 80; i++) {
    for (int j = 0; j < 80; j++) {
      numarray[i][j] = atoi(array[i][j]);
    }
  }
}
int stop = 0;
long collapse(int x, int y) {
  long a, b;
  stop++;
  int cap = 79;
  if (stophere[x][y] == 1) {
    return numarray[x][y];
  }
  if (x != cap && y != cap) {
    a = collapse(x + 1, y);
    b = collapse(x, y + 1);
  }
  else if (x != cap) {
    a = collapse(x + 1, y);
    b = 2147483647;
  }
  else if (y != cap) {
    a = 2147483647;
    b = collapse(x, y + 1);
  }
  else {
    //return 521;
    return 7981;
  }
  //printf("%d, %d\n",a, b );
  stophere[x][y] = 1;
  if (a < b)  {
    numarray[x][y] += a;
    return numarray[x][y];
  }
  if (b < a)  {
    numarray[x][y] += b;
    return numarray[x][y];
  }
  if (stop > 10)  {
    return 0;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  /* code */
  getInupt();
  long a = collapse(0, 0);
  printf("%d\n",a );
  return 0;
}
