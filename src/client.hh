#ifndef CLIENT_HH
  #define CLIENT_HH

  #include <string.h>
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
      static std::string MSG_ABOUT;
      static std::string MSG_BUGS;
      static std::string MSG_HELP;
      static std::string MSG_HOME;
      static std::string MSG_UNKNOWN;
      static std::string DIR_BLOG;
      static std::string DIR_PROJ;
      static std::string DIR_ROOT;
      static std::string DIR_SOFT;
      static std::string FLE_BLOG;
      static std::string EXT_HTML;
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
       * about()
       *
       * Displays information about the program.
       **/
      void about();

      /**
       * bugs()
       *
       * Displays bugs information for the program.
       **/
      void bugs();

      /**
       * help()
       *
       * Displays help information for the program.
       **/
      void help();

      /**
       * home()
       *
       * Displays home information for the program.
       **/
      void home();

      /**
       * open()
       *
       * Opens a file from a given directory and writes it to the socket.
       *
       * NOTE: This method should in theory be safe guarded against directory
       *       traversal as the directory is fixed and cannot be changed. The
       *       added measure of specifying the valid extension should also make
       *       hacking difficult, only being able to load a safe type of file.
       *
       * @param dir The directory of the file.
       * @param filename The name of the file in the specified directory
       * without the extension.
       * @param ext The extension of the file to be loaded.
       **/
      void open(std::string dir, std::string filename, std::string ext);

      /**
       * unknown()
       *
       * Displays an unknown command message.
       **/
      void unknown();

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
