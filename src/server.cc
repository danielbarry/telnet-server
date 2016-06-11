#include "server.hh"

#include "client.cc"
#include "config.hh"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "pthread.h"
#include <unistd.h>

Server::Server(int port, long timeout){
  /* Define socket address */
  struct sockaddr_in serv_addr;
  /* Store values */
  serverPort = port;
  serverTimeout = timeout;
  /* Create server  */
  sockfd = (int*)malloc(sizeof(int));
  *sockfd = socket(AF_INET, SOCK_STREAM, 0);
  /* Check to see if the socket was opened */
  if(*sockfd < 0){
    Main::error("Failed to open socket.");
  }
  /* Zero the server definition structure */
  bzero((char*)&serv_addr, sizeof(serv_addr));
  /* Set the server values */
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(serverPort);
  /* Bind and report an binding error */
  if(bind(*sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
    Main::error("Failed to bond socket.");
  }
}

Server::~Server(){
  /* Close main Server socket */
  close(*sockfd);
}

void Server::run(){
  /* Listen on the socket with a maximum backlog of 5 connections */
  listen(*sockfd, 5);
  /* Setup the Client class */
  Client::init(sockfd);
  /* Setup the server's running loop */
  bool running = true;
  while(running){
    //Main::error("Waiting for new...");
    /* Accept the next client connection */
    Client client;
    //client->run(); // TODO: Remove line.
    pthread_t t;
    pthread_create(&t, 0, &Client::threadLauncher, &client);
    pthread_detach(t);
  }
}
