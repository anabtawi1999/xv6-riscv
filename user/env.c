#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

void env(int size, int interval, char* env_name) {
    int result = 1;
    int loop_size = 1000000;
    int n_forks = 5;
    int pid;
    for (int i = 0; i < n_forks; i++) {
        pid = fork();
    }
    for (int i = 0; i < loop_size; i++) {
        if (i % 100000 == 0) {
        	if (pid == 0) {
                sleep(10);
        		printf("%s %i/%i completed.\n", env_name, i, loop_size);
        	} else {
        		printf(" ");
        	}
        }
        if (i % interval == 0) {
            result = result * size;
        }
    }
    printf("\n");
}

void env_large() {
    env(10e6, 10e6, "env_large");
}
// void env_large(){

//     int pid;
//     int status;

//     for (int i=0; i<4; i++) {
//         if ((pid = fork()) == 0) {
//             for (int i = 0; i <= 10000000; i++){
//                 if (i % 10000 == 0){
//                     printf("%d", i);
//                 }
//             }
//             exit(0);
//         }
//     }

//     while (wait(&status) > 0);
// }

void env_freq() {
    env(10e1, 10e1, "env_freq");
}

int
main(int argc, char *argv[])
{

    env_large();
    //env_freq();
    print_stats();

    exit(0);
}
