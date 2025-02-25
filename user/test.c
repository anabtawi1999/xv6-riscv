//trial user program
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"


void kill_system_dem(int interval, int loop_size) {
    int pid = getpid();
    for (int i = 0; i < loop_size; i++) {
        if (i % interval == 0 && pid == getpid()) {
            printf("kill system %d/%d completed.\n", i, loop_size);
        }
        if (i == loop_size / 2) {
            kill_system();
        }
    }
    printf("\n");
}

int main(int argc, char** argv){
  kill_system_dem(10, 100);
  exit(0);
}
