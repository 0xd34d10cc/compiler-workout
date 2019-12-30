#include <stdint.h>
#include <stdio.h>

extern int32_t nox_rt_write(int32_t i) {
  printf("%d\n", i);
}

extern int32_t nox_rt_read() {
  printf("> ");
  fflush(stdout);
  int32_t val;
  scanf("%d", &val);
  return val;
}
