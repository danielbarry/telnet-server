#include "main.hh"

#include "config.hh"
#include "server.cc"

int main(int argc, char** argv){
  /* Default values */
  int port = DEFAULT_PORT;
  long timeout = DEFAULT_TIMEOUT;
  /* TODO: Accept command line arguments. */
  /* Create a new Server object and run it */
  Server* server = new Server(port, timeout);
  server->run();
  return 0;
}

void Main::error(std::string msg){
  std::cout << "[!!]" << msg << "\n";
}
