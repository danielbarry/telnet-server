#include "server.hh"

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

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
  bzero((char*)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(serverPort);
  if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
    Main::error("Failed to bond socket.");
  }
}

Server::~Server(){
  /* Close main Server socket */
  close(sockfd);
}

void Server::loop(){
  char buffer[256];
  bool running = true;
  while(running){
    /* TODO: Implement client on separate thread. */
    listen(sockfd, 5);
    struct sockaddr cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    if(newsockfd < 0){
      Main::error("Failed to bind to client.");
    }
    bzero(buffer, 256);
    int n = read(newsockfd, buffer, 255);
    if(n < 0){
      Main::error("Failed to read from client");
    }
    n = write(newsockfd, "I got your message", 18);
    if(n < 0){
      Main::error("Failed to write to client");
    }
    close(newsockfd);
  }
}
