#include "common.h"

#include "common.h"

#include <cpen333/process/semaphore.h>
#include <cpen333/process/mutex.h>
#include <cpen333/process/shared_memory.h>
#include <cpen333/process/condition_variable.h>
#include <iostream>

int main() {

  //==========================================================
  // TODO: Implement passenger
  //   - Wait until roller coaster is ready and boarding
  //   - Notify roller coaster when boarded
  //   - Wait until ride is over and safe to leave
  //   - Notify roller coaster when leaving
  //==========================================================

  std::cout << "Passenger waiting in line" << std::endl;

  // wait until roller coaster is boarding and there is room

  std::cout << "Passenger boarded" << std::endl;

  // wait until ride is over

  std::cout << "Passenger leaving" << std::endl;

  return 0;
}