#include "turtles.h"
#include <cpen333/process/shared_memory.h>
#include <cpen333/process/mutex.h>
#include <cpen333/process/subprocess.h>
#include <thread>

int main() {

  cpen333::process::shared_object<TurtleMemory> memory(TURTLE_MEMORY_NAME);

  //========================================================
  // TODO: Implement Donatello
  //       - Initialize his memory
  //       - check-in
  //       - check if defeated
  //       - check on other turtle(s), restart if necessary
  //========================================================

  // re-initialize my memory
  {
    memory->donatello.checkin = 0;
  }

  // take care of michelangelo
  int last_michelangelo = -1;
  int next_michelangelo = 0;
  int miss = 0;
  while (true) {
    memory->donatello.checkin++;
    next_michelangelo = memory->michelangelo.checkin;

    // check on michelangelo and restart if necessary
    if (last_michelangelo == next_michelangelo) {
      ++miss;
      if (miss == 1) {
        // restart mikey
        std::cout << "picking up michelangelo" << std::endl;
        miss = 0;
        cpen333::process::subprocess mikey("./michelangelo", true, true);
      }
    }

    last_michelangelo = next_michelangelo;
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }

  return 0;
}