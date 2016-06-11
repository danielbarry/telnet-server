#include "main.hh"

int main(int argc, char** argv){
  /* Default values */
  int port = 3333;
  long timeout = 2000;
  return 0;
}

void Main::error(std::string msg){
  std::cout << "[!!]" << msg << "\n";
}
