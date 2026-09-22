#include "types.h"
#include "stat.h"
#include "user.h"

void
count_work(int prio, int id)
{
  nice(prio);
  
  volatile unsigned int count = 0;
  int start_time = uptime();
  
  // Run loop for ~200 ticks
  while (uptime() - start_time < 200) {
    count++;
  }
  
  printf(1, "Child %d [Priority %d]: Completed %d iterations\n", id, prio, count);
  exit();
}

int
main(void)
{
  printf(1, "Starting Priority Scheduler Test...\n");

  int prios[4] = {1, 5, 15, 32};
  int num_children = 4;
  int i;

  for (i = 0; i < num_children; i++) {
    int pid = fork();
    if (pid == 0) {
      count_work(prios[i], i + 1);
    }
  }

  for (i = 0; i < num_children; i++) {
    wait();
  }

  exit();
}
