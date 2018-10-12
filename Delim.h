#include <iostream>
#include <fstream>

using namespace std;

class Delim
{
public:
  Delim();
  Delim(char someChar);
  //~Delim();

  bool checkIfDelim();
  bool isLeftDelim();

  //bool isDelim;
  bool leftDelim;
  bool rightDelim;
  bool newLine;
  char data;
  char closer;
};
