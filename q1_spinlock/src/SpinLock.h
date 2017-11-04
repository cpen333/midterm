#ifndef MIDTERM_Q1_SPINLOCK_H
#define MIDTERM_Q1_SPINLOCK_H

#include <atomic>
#include <thread>

class SpinLock {
  std::atomic_flag flag_;

 public:

  SpinLock() : flag_{ATOMIC_FLAG_INIT} {}

  /**
   * Acquires the lock, blocking if necessary
   */
  void lock() {
    //=======================================
    // TODO: Implement lock operation
    //=======================================
  }

  /**
   * Tries to acquire the lock
   * @return true if lock is available and acquired successfully, false otherwise
   */
  bool try_lock() {
    //=======================================
    // TODO: Implement try_lock operation
    //=======================================
    return false;
  }

  /**
   * Releases or unlocks the lock, regardless of who may have locked it
   */
  void unlock() {
    //=======================================
    // TODO: Implement unlock operation
    //=======================================
  }
};

#endif

