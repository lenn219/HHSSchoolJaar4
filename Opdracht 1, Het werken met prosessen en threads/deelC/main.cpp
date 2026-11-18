#include <iostream>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h> // for wait()
#include <thread>

#include "Timer.hpp"

using namespace std;

int pipefd[2] = {0};

void doeIets(char c, unsigned int tijd, unsigned int aantal);
int main()
{

   Timer tm1;
   tm1.Reset();

   std::thread myThread0(doeIets, 'a', 10, 8);
   std::thread myThread1(doeIets, 'b', 15, 8);
   std::thread myThread2(doeIets, 'c', 20, 8);
   std::thread myThread3(doeIets, 'p', 5, 8);

   myThread0.join();
   myThread1.join();
   myThread2.join();
   myThread3.join();

   tm1.Stop();
   std::cout << tm1.deTijd() << "  " << tm1.deNtijd() << endl;

   return 0;
}

void doeIets(char c, unsigned int tijd, unsigned int aantal)
{

   for (int i = 0; i < aantal; ++i)
   {
      std::cout << c << flush;
      // write(pipefd[1], &c, sizeof(char)); // flush leeg output buffer (print direct)
      usleep(100000 * tijd);
   }
   cout << endl;
}
