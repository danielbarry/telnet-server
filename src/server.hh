#ifndef SERVER_HH
  #define SERVER_HH

  #include <netinet/in.h>

  /**
   * Server()
   *
   * Handles the overall server system.
   **/
  class Server{
    public:
      int serverPort;
      long serverTimeout;
      int* sockfd;

      /**
       * Server()
       *
       * Initialises the Server object.
       *
       * @param port The port to initialise the Server object on.
       * @param timeout The default timeout to wait for a response and/or action
       * from the client machine. This amount is measured in milliseconds.
       **/
      Server(int port, long timeout);

      /**
       * ~Server()
       *
       * The Server's deconstruction, allowing it to be safely closed down.
       **/
      ~Server();

      /**
       * run()
       *
       * The main blocking loop of the Server. Due to design, the only reason
       * this is likely to ever exit is through an error which is very unlikely.
       * Therefore this loop is likely to run until manually closed.
       **/
      void run();
  };
#endif
