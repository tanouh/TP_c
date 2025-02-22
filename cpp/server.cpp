//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Database.h"

const int PORT = 3331;

int main(int argc, char *argv[])
{
  // cree le TCPServer
  auto *server =
      new TCPServer([&](std::string const &request, std::string &response)
                    {

    // // the request sent by the client to the server
    // std::cout << "request: " << request << std::endl;

    // // the response that the server sends back to the client
    // response = "RECEIVED: " + request;

    // // return false would close the connection with the client
    // return true;


    Database& db = Database::getInstance();  // Access the database

    std::istringstream iss(request);
    std::string command, arg;
    iss >> command;  // Retrieve the command
    std::getline(iss, arg);  // Get the arguments
    // Suppress leading spaces
    if (!arg.empty() && arg[0] == ' ') {
        arg = arg.substr(1);
    }

    if (command == "SEARCH") {  // Search for multimedia information
        std::ostringstream oss;
        db.displayMultimedia(arg);  // Display multimedia information
        db.displayGroup(arg);  // Try as a group 
        response = oss.str();
    }
    else if (command == "PLAY") {  // Play multipedia
        db.playMultimedia(arg);
        response = "Playing " + arg;
    }
    else {
        response = "Unknown command. Use SEARCH <name> or PLAY <name>";
    }

    return true; });

  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0)
  {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}
