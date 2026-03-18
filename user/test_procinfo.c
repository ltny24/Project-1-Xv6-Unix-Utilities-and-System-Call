#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/procinfo.h"

char* states[] = {
  "UNUSED",
  "USED",
  "SLEEPING",
  "RUNNABLE",
  "RUNNING",
  "ZOMBIE"
};

int main(void)
{
  struct procinfo info;
  int pid;

  printf("Case 1: valid pid\n");
  if (procinfo(getpid(), &info) == 0) {
    printf("P: %s\n", info.name);
    printf("PID: %d, PPID: %d\n", info.pid, info.ppid);
    printf("State: %s\n", states[info.state]);
    printf("Memory: %d bytes\n", info.sz);
  }
  else {
    printf("Failed\n");
  }

  printf("\nCase 2: invalid pid\n");
  if (procinfo(9999, &info) == -1) {
    printf("Correct: return -1\n");
  }
  else {
    printf("Error\n");
  }

  printf("\nCase 3: NULL pointer\n");
  if (procinfo(getpid(), 0) == -1) {
    printf("Correct: return -1\n");
  }
  else {
    printf("Error\n");
  }

  printf("\nCase 4: fork process\n");

  pid = fork();

  if (pid == 0) {
    printf("Child process\n");
    sleep(10);
    exit(0);
  }
  else {
    sleep(1);
    if (procinfo(pid, &info) == 0) {
      printf("Child PID: %d\n", info.pid);
      printf("Child name: %s\n", info.name);
    }
    else {
      printf("Failed\n");
    }
  }

  exit(0);
}
