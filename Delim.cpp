#include "Delim.h"

using namespace std;

Delim::Delim() //No use for default constructor in this implementation
{
  data = '\0';
  rightDelim = false;
  leftDelim = false;
  newLine = false;
}

Delim::Delim(char someChar)
{
  data = someChar;
  checkIfDelim();

  if(data==')'){
    closer = '(';
  }
  else if(data==']'){
    closer = '[';
  }
  else if(data == '}'){
    closer = '{';
  }
  else{
    closer = '\0';
  }
}

/*~Delim::Delim()
{
  cout << "Delim deconstructed" << endl;
}*/

bool Delim::checkIfDelim()
{
  if((data=='(') || (data=='{') || (data=='[')){
    this->leftDelim = true;
    this->rightDelim = false;
    this->newLine = false;
  } //identifies left Delimiters
  else if((data==')') || (data=='}') || (data==']')){
    this->leftDelim = false;
    this->rightDelim = true;
    this->newLine = false;
  } //identifies right delimiters
  else {
    this->leftDelim = false;
    this->rightDelim = false;
    if(data=='\n'){
      this->newLine = true;
    }else {
      this->newLine = false;
    }
  } // Identifies non-delimiters
}
