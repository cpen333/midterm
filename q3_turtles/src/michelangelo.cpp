#include "turtles.h"
#include <cpen333/process/shared_memory.h>
#include <cpen333/process/mutex.h>
#include <cpen333/process/subprocess.h>
#include <thread>

int main() {

  cpen333::process::shared_object<TurtleMemory> memory(TURTLE_MEMORY_NAME);

  //========================================================
  // TODO: Implement Michelangelo
  //       - Initialize his memory
  //       - check-in
  //       - check if defeated
  //       - check on other turtle(s), restart if necessary
  //========================================================

  // re-initialize my memory
  {
    memory->michelangelo.checkin = 0;
  }

  // take care of leonardo
  int last_leonardo = -1;
  int next_leonardo = 0;
  int miss = 0;
  while (true) {
    memory->michelangelo.checkin++;
    next_leonardo = memory->leonardo.checkin;

    // check on leonardo and restart if necessary
    if (last_leonardo == next_leonardo) {
      ++miss;
      if (miss == 1) {
        // restart leonardo
        std::cout << "picking up leonardo" << std::endl;
        miss = 0;
        cpen333::process::subprocess leo("./leonardo", true, true);
      }
    }

    last_leonardo = next_leonardo;
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }

  return 0;
}