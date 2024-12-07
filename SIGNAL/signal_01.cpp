#include <signal.h>
#include <stdio.h>

void handle_signal(int signal)
{
    printf("Received signal %d\n", signal);
}

int main(void)
{
    // Install a signal handler.
    signal(SIGTERM, handle_signal);

    printf("Sending signal %d\n", SIGFPE);
    raise(SIGFPE);
    printf("main function exits()\n");
}
