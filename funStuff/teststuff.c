int len(char *st) {
  int len = 0;
  for (int i = 0; i < sizeof(st); i++) {
    if (st[i] == 0) {
      return len;
    }
    len++;
  }
  return len;
}
char cat (char str1, char str2) {
  printf("%d\n", len(str1));
  return 0;
}
int main(int argc, char const *argv[]) {
  char s[] = "three";
  len(s);
  printf("Length: %d\n", len(s));
  cat("abcd", "ef");
  return 0;
}
