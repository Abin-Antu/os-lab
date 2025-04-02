#include <stdio.h>
#include <unistd.h>  // Required for getpid() and getppid()

int main() {
    int pid;

    pid = getpid();   // Get current process ID
    printf("Process ID is %d\n", pid);

    pid = getppid();  // Get parent process ID
    printf("Parent Process ID is %d\n", pid);

    return 0;
}
