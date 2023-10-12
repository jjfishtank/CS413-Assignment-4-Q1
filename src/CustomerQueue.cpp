// CustomerQueue.cpp
// Author: Jeremy Renati
// Created: 10/11/2023
// passes input.txt and output.txt to CustomerQueue

#include <iostream>
#include "CustomerQueue.h"

int main() {
  CustomerQueue queue(10);
  std::ifstream inputFile("../../../input.txt");
  std::ofstream outputFile("../../../output.txt", std::ios::out);

  if (!inputFile.is_open()) {
    std::cerr << "Failed to open input.txt\n";
    return 1;
  }

  if (!outputFile.is_open()) {
    std::cerr << "Failed to open output.txt\n";
    return 1;
  }

  queue.runCommandFile(inputFile, outputFile);

  return 0;
}
