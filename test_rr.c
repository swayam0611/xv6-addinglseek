// test_rr.c
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  nice(10);

  for (int i = 0; i < 3; i++) {
    if (fork() == 0) {
      for (int j = 0; j < 5; j++) {
        printf(1, "Child %d running step %d\n", i + 1, j);
        sleep(1);
      }
      exit();
    }
  }

  for (int i = 0; i < 3; i++) wait();
  exit();
}
