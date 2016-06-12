#ifndef CONFIG_HH
  #define CONFIG_HH
  /**
   * config.hh
   *
   * The configuration file for the server's internal defaults compiled into the
   * system.
   **/
  #define DEFAULT_PORT        23
  #define DEFAULT_TIMEOUT     2000
  #define DEFAULT_BUFFER_SIZE 256
  #define DEFAULT_BUFFER_READ (DEFAULT_BUFFER_SIZE - 1)
  #define DEFAULT_MAX_CLIENTS 2048
#endif
