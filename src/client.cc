#include "client.hh"

#include <algorithm>
#include "config.hh"
#include <fstream>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

std::string Client::MSG_ABOUT;
std::string Client::MSG_BUGS;
std::string Client::MSG_HELP;
std::string Client::MSG_HOME;
std::string Client::MSG_UNKNOWN;
std::string Client::DIR_BLOG;
std::string Client::DIR_PROJ;
std::string Client::DIR_ROOT;
std::string Client::DIR_SOFT;
std::string Client::FLE_BLOG;
std::string Client::FLE_PROJ;
std::string Client::FLE_ROOT;
std::string Client::FLE_SOFT;
std::string Client::EXT_HTML;
int* Client::serverSockfd;
socklen_t Client::clilen;

void Client::init(int* sockfd){
  serverSockfd = sockfd;
  clilen = sizeof(cli_addr);
  /* TODO: Put these in the config file.  */
  MSG_ABOUT = "Program written by B[].\n";
  MSG_BUGS = "# Bugs\n";
  MSG_BUGS.append("\n");
  MSG_BUGS.append("  * None currently\n");
  MSG_HELP = "# Help\n";
  MSG_HELP.append("\n");
  MSG_HELP.append("  * `blog` - Opens a blog entry\n");
  MSG_HELP.append("  * `bugs` - Lists the program bugs list\n");
  MSG_HELP.append("  * `chat` - The chat room\n");
  MSG_HELP.append("  * `exit` - Quits the session\n");
  MSG_HELP.append("  * `help` - Displays this help\n");
  MSG_HELP.append("  * `home` - Displays welcome page\n");
  MSG_HELP.append("  * `kill` - Quits the session\n");
  MSG_HELP.append("  * `proj` - Opens a project entry\n");
  MSG_HELP.append("  * `soft` - Opens a software entry\n");
  MSG_HELP.append("  * `todo` - Lists the program TODO list\n");
  MSG_HELP.append("  * `quit` - Quits the session\n");
  MSG_HELP.append("  * `????` - About the program\n");
  MSG_HOME = "Welcome to CoffeeSpace. Type `help` for more options.\n";
  MSG_UNKNOWN = "Unknown command.\n";
  DIR_BLOG = "www/blogs/";
  DIR_PROJ = "www/projects/";
  DIR_ROOT = "www/";
  DIR_SOFT = "www/software/";
  FLE_BLOG = "blogs";
  FLE_BLOG = "projects";
  FLE_BLOG = "index";
  FLE_BLOG = "software";
  EXT_HTML = ".html";
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
  bool running = true;
  while(running){
    /* Write prompt */
    write(clientSocketid, "> ", 2);
    /* Read bytes from client */
    int n = read(clientSocketid, buffer, DEFAULT_BUFFER_READ);
    /* Make sure the read didn't return an error */
    if(n < 0){
      Main::error("Failed to read from client.");
    }else{
      buffer[n - 2] = '\0';
      std::string str(buffer);
      if(str.compare("") == 0){
        home();
      }else if(str.compare("blog") == 0){
        if(n <= 6){
          open(DIR_ROOT, FLE_BLOG, EXT_HTML);
        }else{
        }
      }else if(str.compare("bugs") == 0){
        bugs();
      }else if(str.compare("chat") == 0){
        write(clientSocketid, "TODO: Build this section.\n", 26);
      }else if(str.compare("exit") == 0){
        running = false;
      }else if(str.compare("help") == 0){
        help();
      }else if(str.compare("home") == 0){
        write(clientSocketid, "TODO: Build this section.\n", 26);
      }else if(str.compare("kill") == 0){
        running = false;
      }else if(str.compare("proj") == 0){
        write(clientSocketid, "TODO: Build this section.\n", 26);
      }else if(str.compare("soft") == 0){
        write(clientSocketid, "TODO: Build this section.\n", 26);
      }else if(str.compare("todo") == 0){
        write(clientSocketid, "TODO: Build this section.\n", 26);
      }else if(str.compare("quit") == 0){
        running = false;
      }else if(str.compare("????") == 0){
        about();
      }else{
        unknown();
        home();
      }
    }
    /* Make sure the write didn't return an error */
    if(n < 0){
      Main::error("Failed to write to client.");
      running = false;
    }
  }
  /* Display connection close message */
  write(clientSocketid, "\nClosed connection.\n", 20);
  /* Close the client socket */
  close(clientSocketid);
  /* Return message for successful run */
  return 0;
}

void Client::about(){
  write(clientSocketid, MSG_ABOUT.data(), MSG_ABOUT.size());
}

void Client::bugs(){
  write(clientSocketid, MSG_BUGS.data(), MSG_BUGS.size());
}

void Client::help(){
  write(clientSocketid, MSG_HELP.data(), MSG_HELP.size());
}

void Client::home(){
  write(clientSocketid, MSG_HOME.data(), MSG_HOME.size());
}

void Client::open(std::string dir, std::string filename, std::string ext){
  /* TODO: Make sure filename is safe. */
  std::ifstream file(dir + filename + ext);
  if(file.is_open()){
    /* TODO: Replace this heavy function. */
    int numLines = std::count(
      std::istreambuf_iterator<char>(file),
      std::istreambuf_iterator<char>(),
      '\n'
    ) - DEFAULT_FILE_SKIP_E;
    /* Reset file position back to the beginning */
    file.seekg(0, file.beg);
    std::string line;
    int lineCount = 0;
    while(getline(file, line)){
      line += "\n";
      if(lineCount >= DEFAULT_FILE_SKIP_F && lineCount < numLines){
        write(clientSocketid, line.data(), line.size());
      }
      lineCount++;
    }
    file.close();
  }else{
    Main::error("Unable to open file.");
    /* Display failure message to client */
    unknown();
  }
}

void Client::unknown(){
  write(clientSocketid, MSG_UNKNOWN.data(), MSG_UNKNOWN.size());
}

void* Client::threadLauncher(void* context){
  return ((Client*)context)->run();
}
