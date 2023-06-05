#include <sys/wait.h>
#include <unistd.h>

#include <iostream>


void signal_handler(int signo) {
    if (signo == SIGCHLD) {
        pid_t pid;
        while ((pid = waitpid(-1, NULL, WNOHANG)) > 0) {
            printf("SIGCHLD pid %d\n", pid);
        }
    }
    else {
        std::cout << "signo: " << signo << "\n";
    }

    return;
}

int main(int argc, char **argv) {
    signal(SIGCHLD, signal_handler);

    while (1) {
        pid_t pid = fork();
        if (pid > 0) {
            std::cout << "I am main process, waiting for child process to exit.\n";
            // wait(NULL);
            // std::cout << "Sub process exit.\n";
            sleep(10);
        }
        else
        if (pid == 0) {
            std::cout << "Child pid: " << getpid() << "\n";
            std::cout << "I am child process.\n";
            sleep(2);
            std::cout << "Exit child process.\n";
            return 0;
        }
        else {
            std::cerr << ("fork error\n");
            return 2;
        }
    }
}


// blog.csdn.net/zjerryj/article/details/77940669


