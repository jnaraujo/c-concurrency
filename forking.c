#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void task() {
  printf("Hello from task %d\n", getpid());
  sleep(1);
  printf("Task %d done\n", getpid());
}

int main() {
  int num_children = 3;
  pid_t pid;

  for (int i = 0; i < num_children; i++){
    pid = fork();
    if(pid == 0) {
      task();
      return 0;
    }
  }

  for (int i = 0; i < num_children; i++) {
		pid_t child_pid = wait(NULL);
		printf("Child %d finished\n", child_pid);
	}

  printf("Parent done\n");
  return 0;
}
