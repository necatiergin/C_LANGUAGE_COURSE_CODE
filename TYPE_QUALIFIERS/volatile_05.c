#include <stdio.h>
#include <signal.h>
#include <Windows.h>

volatile int keep_running = 1;  

void handle_sigint(int sig);

int main(void) 
{
    signal(SIGINT, handle_sigint);  // Handle Ctrl+C (SIGINT)

    while (keep_running) {  // Always check `keep_running`'s latest value
        printf("Running...\n");
        Sleep(1000);
    }

    printf("Exited safely!\n");
}

void handle_sigint(int sig) 
{
    keep_running = 0;  // Signal handler changes `keep_running`
}
