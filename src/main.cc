#include "main.hh"

#include "server.cc"

int main(int argc, char** argv){
  /* Default values */
  int port = 23;
  long timeout = 2000;
  /* TODO: Accept command line arguments. */
  /* Create a new Server object and run it */
  Server* server = new Server(port, timeout);
  server->loop();
  return 0;
}

void Main::error(std::string msg){
  std::cout << "[!!]" << msg << "\n";
}
