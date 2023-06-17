#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void enterParaContinuar();
vector<string> splitString(const string &input, char delimiter);
string removeSpaceBeginningAndEnd(string str);
int contarValoresCSV (string line);

#endif // !UTILS_H
