#include <cuda_runtime.h>
#include <iostream>
#include <signal.h>
#include <stdexcept>
#include <string>

std::ostream &log_error() { return std::cerr; }

std::ostream &log_info() { return std::cout; }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    log_error() << "cudallocator takes exactly one argument - amount of memory "
                   "to allocate in megabytes"
                << std::endl;
    return 1;
  }
  size_t allocate_amount;
  try {
    int parsed_value = std::stoi(argv[1]);
    if (parsed_value <= 0) {
      throw std::runtime_error(
          "Amount of memory to allocate must be positive integer");
    }
    allocate_amount = static_cast<size_t>(parsed_value);
  } catch (const std::exception &e) {
    log_error() << "exception: " << e.what() << std::endl;
    return 1;
  }

  log_info() << "cudallocator: allocating " << allocate_amount << " megabytes"
             << std::endl;

  void *allocatedMem;
  cudaMalloc(&allocatedMem, allocate_amount * 1024 * 1024);

  log_info() << "Use Ctrl+C to exit" << std::endl;
  pause();
  return 0;
}
