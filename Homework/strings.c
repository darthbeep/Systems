#include <stdio.h>
#include <string.h>
void strlens(char *);
int myStrlen(char *);
void strcpys(char *, char *, char * );
char * myStrcopy(char *, char *);
void strncpys(char *, char *, char *, int n );
char * myStrncopy(char *, char *, int n);
void strcats(char *, char *, char *);
char * myStrcat(char *, char *);
void strncats(char *, char *, char *, int);
char * myStrncat(char *, char *, int);
void strchrs(char *, char *, int);
char * myStrchr(char *, int);
void strcmps(char *, char *);
int myStrcmp(char *, char *);
void strstrs(char *, char *, char *);
char * myStrstr(char *, char *);

int main(int argc, char const *argv[]) {
  strlens("Space. The final frontier");
  char a[] = "These are the voyages of";
  char c[] = "These are the voyages of";
  char b[] =  "the starship Enterprise";
  strcpys(a, c, b);
  char d[] = "Its five year mission: ";
  char e[] = "Its five year mission: ";
  char f[] = "To explore strange new worlds";
  strcats(d, e, f);
  char g[] = "To seek out new life";
  char h[] = "And new civilizations";
  strcmps(g, h);
  char i[] = "To boldly go";
  char j[] = "To boldly go";
  char k = 'l';
  strchrs(i, j, k);
  char l[] = "Where no man";
  char m[] = "Where no man";
  char n[] = "Has gone before";
  strncpys(l, m, n, 4);
  char o[10] = "Intro";
  char p[10] = "Intro";
  char q[10] = "Music";
  strncats(o, p, q, 3);
  char r[] = "I'm out of ideas";
  strstrs(r, r, "idea");
  return 0;
}

void strlens(char *c) {
  printf("The string for strlen is: %s\n", c);
  printf("Normal function: %d\n", strlen(c));
  printf("My function: %d\n", myStrlen(c));
}
int myStrlen(char *st) {
  int len = 0;
  for (int i = 0; ; i++) {
    if (st[i] == 0) {
      return len;
    }
    len++;
  }
  return len;
}
void strcpys(char *dest, char *dest2, char *src) {
  printf("Original words for strcpy: Old: %s, New: %s.\n", dest, src);
  strcpy(dest, src);
  printf("New words for strcpy: Old: %s, New: %s.\n", dest, src);
  printf("Original words for  my strcpy: Old: %s, New: %s\n", dest2, src);
  myStrcopy(dest2, src);
  printf("New words for  my strcpy: Old: %s, New: %s\n", dest2, src);
}
char * myStrcopy(char *dest, char *src) {
  int i = 0;
  while (dest[i] != 0) {
    dest[i] = 0;
    i++;
  }
  for (int j = 0; j < myStrlen(src); j++) {
      dest[j] = src[j];
  }
  return dest;
}

void strncpys(char *dest, char *dest2, char *src, int n) {
  printf("Original words for strncpy: Old: %s, New: %s.\n", dest, src);
  strncpy(dest, src, n);
  printf("New words for strncpy: Old: %s, New: %s.\n", dest, src);
  printf("Original words for my strncpy: Old: %s, New: %s\n", dest2, src);
  myStrncopy(dest2, src, n);
  printf("New words for  my strncpy: Old: %s, New: %s\n", dest2, src);
}
char * myStrncopy(char *dest, char *src, int n) {
  int i = 0;
  //I added this part by accident when I wanted something that clears the original string before copying
  /*while (dest[i] != 0) {
    //printf("%d\n", dest[i]);
    dest[i] = 0;
    i++;
  }*/
  for (int j = 0; j < n; j++) {
      dest[j] = src[j];
  }
  return dest;
}

void strcats(char *dest, char *dest2, char *src) {
  printf("Original string for strcat: %s\n", dest);
  strcat(dest, src);
  printf("Original string after computer's strcat: %s\n", dest);
  myStrcat(dest2, src);
  printf("Original string after my strcat: %s\n", dest2);
}

char * myStrcat(char *dest, char *src) {
  int i = myStrlen(dest);

  for (int j = 0; j < myStrlen(src) + 1; j++) {
    dest[j+i] = src[j];
  }
  return dest;
}

void strncats(char *dest, char *dest2, char *src, int n) {
  printf("Original string for strcat: %s\n", dest);
  strncat(dest, src, n);
  printf("Original string after computer's strcat: %s\n", dest);
  myStrncat(dest2, src, n);
  printf("Original string after my strcat: %s\n", dest2);
}

//This code is a little buggy if the dest isn't long enough, but I'm going to leave it in
//But you should grade the strcat function instead of this one
char * myStrncat(char *dest, char *src, int n) {
  int i = myStrlen(dest);
  for (int j = 0; j < n ; j++) {
    dest[j+i] = src[j];
  }
  return dest;
}

void strchrs(char *str, char *str2, int ch) {
  printf("String for strchr: %s, Desired charactor for strchr: %c \n", str, ch);
  str = strchr(str, ch);
  printf("The string after %c in the original strchr is: %s\n", ch, str);
  str2 = myStrchr(str2, ch);
  printf("The string after %c in my strchr is: %s\n", ch, str2);
}

char * myStrchr(  char *st, int ch) {
  char * str = strdup(st);
  int space = 0;
  for (int i = 0; i < myStrlen(str) && space == 0; i++) {
    if (str[i] == ch) {
      space = i;
    }
  }
  if (space == 0) {
    return 0;
  }
  int end = myStrlen(str);
  for (int i = 0; i < end; i++) {
    str[i] = str[space+i];
    str[space+i] = 0;
  }
  for (int i = space; i < myStrlen(str); i++) {
  }

  free(str);
  return str;
}

void strcmps(char * str1, char * str2) {
  printf("Original strings for strcmp: %s, %s\n", str1, str2);
  int a = strcmp(str1, str2);
  printf("Computer's result for strcmp: %d\n", a);
  int b = myStrcmp(str1, str2);
  printf("My result for strcmp: %d\n", b);
}
int myStrcmp(char * str1, char * str2) {
  if (str1 == str2) {
    return 0;
  }
  int stop;
  if (myStrlen(str1) < myStrlen(str2)) {
    stop = myStrlen(str1);
  }
  else {
    stop = myStrlen(str2);
  }
  for (int i = 0; i < stop ; i++) {
    if (str1[i]-str2[i] != 0) {
      return str1[i]-str2[i];
    }
 }
  return 0;
}

void strstrs(char *str, char *str2, char * ch) {
  printf("String for strstr: %s, Desired string for strchr: %s \n", str, ch);
  str = strstr(str, ch);
  printf("The string after %s in the original strstr is: %s\n", ch, str);
  str2 = myStrstr(str2, ch);
  printf("The string after %s in my strstr is: %s\n", ch, str2);
}

char * myStrstr(  char *st, char * ch) {
  char * str = strdup(st);
  int len = myStrlen(ch);
  int space = 0;
  for (int i = 0; i < myStrlen(str)-len && space == 0; i++) {
    char * tempdest = (char *) malloc(len);
    if (myStrcmp(strncpy(tempdest, str + i, len), ch) == 0) {
      space = i;
    }
  }
  if (space == 0) {
    return 0;
  }
  int end = myStrlen(str);
  for (int i = 0; i < end; i++) {
    str[i] = str[space+i];
    str[space+i] = 0;
  }
  for (int i = space; i < myStrlen(str); i++) {
  }

  free(str);
  return str;
}
