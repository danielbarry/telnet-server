#include "server.hh"

#include "config.hh"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

Server::Server(int port, long timeout){
  /* Define socket address */
  struct sockaddr_in serv_addr;
  /* Store values */
  serverPort = port;
  serverTimeout = timeout;
  /* Create server  */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  /* Check to see if the socket was opened */
  if(sockfd < 0){
    Main::error("Failed to open socket.");
  }
  /* Zero the server definition structure */
  bzero((char*)&serv_addr, sizeof(serv_addr));
  /* Set the server values */
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(serverPort);
  /* Bind and report an binding error */
  if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
    Main::error("Failed to bond socket.");
  }
}

Server::~Server(){
  /* Close main Server socket */
  close(sockfd);
}

void Server::loop(){
  /* Setup the server's running loop */
  bool running = true;
  while(running){
    /* TODO: Implement client on separate thread. */
    /* Pre-define input buffer */
    char buffer[DEFAULT_BUFFER_SIZE];
    /* Listen on the socket with a maximum backlog of 5 connections */
    listen(sockfd, 5);
    /* Accept the next client connection */
    struct sockaddr cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    /* Make sure we were able to bind to the client */
    if(newsockfd < 0){
      Main::error("Failed to bind to client.");
    }
    /* Zero out the buffer we read from the client */
    bzero(buffer, DEFAULT_BUFFER_SIZE);
    /* Read bytes from client */
    int n = read(newsockfd, buffer, DEFAULT_BUFFER_READ);
    /* Make sure the read didn't return an error */
    if(n < 0){
      Main::error("Failed to read from client");
    }
    /* Write bytes to the client */
    n = write(newsockfd, "I got your message", 18);
    /* Make sure the write didn't return an error */
    if(n < 0){
      Main::error("Failed to write to client");
    }
    /* Close the client socket */
    close(newsockfd);
  }
}
