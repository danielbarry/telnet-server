#ifndef CLIENT_HH
  #define CLIENT_HH

  #include <sys/types.h>

  /**
   * client.hh
   *
   * This class fully handles a new client connection, offering the telnet
   * capabilities to somebody connecting. This class has been designed to run on
   * a different thread to the server, therefore must make itself fully
   * independent as quickly as possible to not block the main server loop.
   *
   * NOTE: This class should also be extremely safe in use, memory leakage or
   *       buffer overflow could be catastrophic.
   **/
  class Client{
    public:
      static int* serverSockfd;
      static socklen_t clilen;
      struct sockaddr cli_addr;
      int clientSocketid;
      int n;
      char buffer[DEFAULT_BUFFER_SIZE];

      /**
       * init()
       *
       * Statically initialise the Client class.
       *
       * @param sockfd The server socket reference.
       **/
      static void init(int* sockfd);

      /**
       * Client()
       *
       * The initialiser for the Client class.
       *
       * NOTE: Everything done in this method directly blocks the main Server
       *       loop - minimum time should be spent here to prevent attack via
       *       DoS.
       **/
      Client();

      /**
       * ~Client()
       *
       * Handles the destruction of the Client instance.
       **/
      ~Client();

      /**
       * run()
       *
       * This is the method that gets run on a different thread to the Server
       * thread. Ultimately, this thread will be responsible for fully handling
       * the client's connection until a disconnection or timeout. Here, memory
       * and access should be handled carefully as the client has in theory got
       * root access if care is not taken.
       **/
      void* run();

      /**
       * threadLauncher()
       *
       * Invokes a member function of a predefined object.
       *
       * @param context The context of this instance.
       **/
      static void* threadLauncher(void* context);
  };
#endif
