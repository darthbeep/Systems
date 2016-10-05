#include <string.h>
void compareStrings(const char *compare) {
  printf("Type a number that you think will be greater than %s.\n", compare);
  char comped[20];
  scanf("%s", comped);
  int hold = strcmp(compare, comped);
  hold++;
  if (hold < 1) {
    printf("%s is greater than %s\n", comped, compare);
  }
  else if (hold > 1) {
    printf("%s is less than %s\n", comped, compare);
  }
  else {
    printf("%s and %s are the same\n", comped,compare );
  }
}
int fakeStrLen(char c) {

  return 0;
}
int main(int argc, char const *argv[]) {
  compareStrings("24");
  return 0;
}
//Now since you alone of all the italians dared to write down an entire era on three sheets of paper
