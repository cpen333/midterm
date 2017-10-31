#include "turtles.h"
#include <cpen333/process/shared_memory.h>
#include <cpen333/process/mutex.h>
#include <cpen333/process/subprocess.h>
#include <thread>

int main() {

  cpen333::process::shared_object<TurtleMemory> memory(TURTLE_MEMORY_NAME);

  //========================================================
  // TODO: Implement Leonardo
  //       - Initialize his memory
  //       - check-in
  //       - check if defeated
  //       - check on other turtle(s), restart if necessary
  //========================================================

  // re-initialize my memory
  {
    memory->leonardo.checkin = 0;
  }

  // take care of donatello
  int last_donatello = -1;
  int next_donatello = 0;
  int miss = 0;
  while (true) {
    memory->leonardo.checkin++;
    next_donatello = memory->donatello.checkin;

    // check on donatello and restart if necessary
    if (last_donatello == next_donatello) {
      ++miss;
      if (miss == 1) {
        // restart donny
        miss = 0;
        std::cout << "picking up donatello" << std::endl;
        cpen333::process::subprocess donny("./donatello", true, true);
      }
    }

    last_donatello = next_donatello;
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }

  return 0;
}