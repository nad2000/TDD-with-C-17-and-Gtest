#include <stdio.h>
#include <wordexp.h>

int main(int argc, char *argv[]) {
  wordexp_t exp_result;
  wordexp(argv[1], &exp_result, 0);
  printf("%s\n", exp_result.we_wordv[0]);
}
