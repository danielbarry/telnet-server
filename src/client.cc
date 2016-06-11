#include "client.hh"

#include "config.hh"
#include <sys/socket.h>
#include <unistd.h>

#include<stdio.h> // TODO: Remove me

int* Client::serverSockfd;
socklen_t Client::clilen;

void Client::init(int* sockfd){
  serverSockfd = sockfd;
  printf("server orig->%i\n", *sockfd); // TODO: Remove me
  clilen = sizeof(cli_addr);
}

Client::Client(){
  clientSocketid = accept(*serverSockfd, (struct sockaddr*)&cli_addr, &clilen);
  printf("server after->%i\n", *serverSockfd); // TODO: Remove me
  printf("client origin->%i\n", clientSocketid); // TODO: Remove me
}

Client::~Client(){
}

void* Client::run(){
  printf("client after->%i\n", clientSocketid); // TODO: Remove me
  /* Make sure we were able to bind to the client */
  if(clientSocketid < 0){
    Main::error("Failed to bind to client.");
  }
  /* Read bytes from client */
  int n = read(clientSocketid, buffer, DEFAULT_BUFFER_READ);
  /* Make sure the read didn't return an error */
  if(n < 0){
    Main::error("Failed to read from client");
  }
  /* Write bytes to the client */
  n = write(clientSocketid, "I got your message", 18);
  /* Make sure the write didn't return an error */
  if(n < 0){
    Main::error("Failed to write to client");
  }
  /* Close the client socket */
  close(clientSocketid);
  /* Return message for successful run */
  return 0;
}

void* Client::threadLauncher(void* context){
  return ((Client*)context)->run();
}
