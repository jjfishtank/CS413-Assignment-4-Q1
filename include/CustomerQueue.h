// CustomerQueue.h
// Author: Jeremy Renati
// Created: 10/11/2023
// Maintains and displays a queue of customer IDs with error checks

#pragma once

#include <sstream>
#include <fstream>
#include "Queue.h"


class CustomerQueue {
public:
  CustomerQueue(int maxCustomers) : customers(maxCustomers) {}

  void runCommandFile(std::ifstream& inputFile, std::ofstream& outputFile);

private:
  Queue customers;
};

inline void CustomerQueue::runCommandFile(std::ifstream& inputFile, std::ofstream& outputFile) {
  std::string line;

  // Process each line in the input file
  while (std::getline(inputFile, line)) {
    std::string command;
    std::stringstream commandStream(line);
    commandStream >> command;

    if (command == "Add") {

      // Get ID from next line
      if (std::getline(inputFile, line)) {
        std::stringstream idStream(line);
        int id;

        if (idStream >> id) {
          try {
            customers.enqueue(id);
          }
          catch (std::runtime_error e) {
            outputFile << "Error: " << e.what() << '\n';
          }
        } else {
          outputFile << "Invalid ID: " << line << '\n';
        }
      }

    } else if (command == "Delete") {

      try {
        customers.dequeue();
      }
      catch (std::runtime_error e) {
        outputFile << "Error: " << e.what() << '\n';
      }

    } else if (command == "Exit") {
      return;
    } else { 
      outputFile << "Invalid command: " << command << '\n';
    }

    outputFile << "Queue: " << customers.toString() << '\n';
  }
}