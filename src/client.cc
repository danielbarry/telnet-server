#include "client.hh"

#include "config.hh"
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int* Client::serverSockfd;
socklen_t Client::clilen;

void Client::init(int* sockfd){
  serverSockfd = sockfd;
  clilen = sizeof(cli_addr);
}

Client::Client(){
  clientSocketid = accept(*serverSockfd, (struct sockaddr*)&cli_addr, &clilen);
}

Client::~Client(){
}

void* Client::run(){
  /* Make sure we were able to bind to the client */
  if(clientSocketid < 0){
    Main::error("Failed to bind to client.");
  }
  /* Read bytes from client */
  int n = read(clientSocketid, buffer, DEFAULT_BUFFER_READ);
  /* Make sure the read didn't return an error */
  if(n < 0){
    Main::error("Failed to read from client.");
  }else{
    /* TODO: Sanitise the input. */
    buffer[n - 2] = '\0';
    std::ifstream file(buffer);
    if(file.is_open()){
      std::string line;
      while(getline(file, line)){
        line += "\n";
        std::cout << line;
        write(clientSocketid, line.data(), line.size());
      }
      file.close();
    }else{
      Main::error("Unable to open file.");
    }
  }
  /* Write bytes to the client */
  n = write(clientSocketid, "I got your message", 18);
  /* Make sure the write didn't return an error */
  if(n < 0){
    Main::error("Failed to write to client.");
  }
  /* Close the client socket */
  close(clientSocketid);
  /* Return message for successful run */
  return 0;
}

void* Client::threadLauncher(void* context){
  return ((Client*)context)->run();
}
