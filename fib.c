#include <stdio.h>
#include <stdlib.h>

int fibbi(int n) {

  int num1 = 0;
  int num2 = 1;
  int sum = 1;

  if (n == 1) {
    return 0;
  } else {
    for (int ix = 0; ix < n - 1; ++ix) {
      if (ix + 2 == n) {
        return sum;
      }
      sum = num1 + num2;
      num1 = num2;
      num2 = sum;
    }
  }
}

int fibbr(int n) {

  if (n == -1) {
    return 0;
  }
  if (n == 0 || n == 1) {
    return 1;
  }

  return fibbr(n - 1) + fibbr(n - 2);
}

int main(int argc, char *argv[]) {

  FILE *fptr = fopen(argv[3], "r");
  char str1[100];
  fgets(str1, 100, fptr);
  int input1 = atoi(str1);
  int input2 = atoi(argv[1]);
  int n = input1 + input2;

  if (*argv[2] == 'i') {
    printf("%d", fibbi(n));
  } else if (*argv[2] == 'r') {
    printf("%d", fibbr(n - 2));
  }

  return 0;
}