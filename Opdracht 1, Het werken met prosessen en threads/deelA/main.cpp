#include <iostream>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h> // for wait()

#include "Timer.hpp"

using namespace std;

int pipefd[2] = {0};

void doeIets(char c, unsigned int tijd, unsigned int aantal);
int main()
{

   Timer tm1;
   tm1.Reset();
   printf("PID0: %d\n", getpid());

   if (pipe(pipefd) != 0)
   {
      exit(1);
   }

   pid_t pid1 = fork();
   if (pid1 == 0)
   {
      printf("PID1 (child a): %d\n", getpid());
      doeIets('a', 10, 8);
      exit(0);
   }

   pid_t pid2 = fork();
   if (pid2 == 0)
   {
      printf("PID2 (child b): %d\n", getpid());
      doeIets('b', 15, 8);
      exit(0);
   }

   pid_t pid3 = fork();
   if (pid3 == 0)
   {
      printf("PID3 (child c): %d\n", getpid());
      doeIets('c', 20, 8);
      exit(0);
   }

   // Parent
   printf("PID1: %d\n", pid1);
   printf("PID2: %d\n", pid2);
   printf("PID3: %d\n", pid3);
   doeIets('p', 5, 8);

   char output = NULL;
   close(pipefd[1]);          /* Close unused write end */
   while (read(pipefd[0], &output, 1) > 0)
      write(STDOUT_FILENO, &output, 1);
   write(STDOUT_FILENO, "\n", 1);
   close(pipefd[0]);
   printf("%c", output);
   wait(NULL);
   wait(NULL);
   wait(NULL);

   tm1.Stop();
   cout << tm1.deTijd() << "  " << tm1.deNtijd() << endl;

   return 0;
}

void doeIets(char c, unsigned int tijd, unsigned int aantal)
{

   for (int i = 0; i < aantal; ++i)
   {
      write(pipefd[1], &c, sizeof(char)); // flush leeg output buffer (print direct)
      // usleep(100000 * tijd);
   }
   cout << endl;
}
