#ifndef MAIN_HH
  #define MAIN_HH

  #include <iostream>
  #include <string>

  /**
   * Main.hh
   *
   * The main class that parses the parameters the program runs with.
   **/
  class Main{
    public:
      /**
       * error()
       *
       * Writes an error message to the terminal.
       *
       * @param msg The message to be displayed.
       **/
      static void error(std::string msg);
  };
#endif
