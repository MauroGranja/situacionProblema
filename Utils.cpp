#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#include "Utils.h"

int contarValoresCSV (string line) {

  int count = 0;
  int lastComma;

  for (int i = 0; i < line.length(); i++) {
      if (line[i] == ',' && line[i - 1] != ',') {
          count++;
          lastComma = i;
      }
  }

  if (line[lastComma + 1] != ',') {
      count++;
  }

  return count;
}

void enterParaContinuar() {
  cout << "Presione enter para continuar...";
  cin.ignore();
  cin.get();
}

vector<string> splitString(const string &input, char delimiter) {
  vector<string> tokens;
  istringstream iss(input);
  string token;

  while (getline(iss, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

string removeSpaceBeginningAndEnd(string str) {
  return str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') + 1);
}
