#include "common.h"

#include <cpen333/process/semaphore.h>
#include <cpen333/process/mutex.h>
#include <cpen333/process/shared_memory.h>
#include <cpen333/process/condition_variable.h>

#include <thread>
#include <chrono>

int main() {

  //==========================================================
  // TODO: Implement roller coaster
  //   - Initialize anything that needs to be initialized
  //   - Loop
  //      - Notify passengers it is safe to board
  //      - Wait until full OR
  //          there is at least one passenger boarded AND
  //          no more passengers are in line
  //      - Go for ride
  //      - Notify passengers it is safe to exit
  //      - Wait until all passengers have exited
  //==========================================================

  // initialize

  // keep running roller coaster forever
  while(true) {

    // start boarding

    std::cout << "Roller coaster loading passengers" << std::endl;

    // wait until either coaster is full or we have at least one and nobody waiting
    int npassengers = 0;

    // GO!
    std::cout << "Roller coaster running with " << npassengers << " passengers" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Roller coaster returned, letting passengers off" << std::endl;

    // let passengers off

    std::cout << "Roller coaster waiting for passengers to exit" << std::endl;

    // wait for passengers to leave

  }

  return 0;
}