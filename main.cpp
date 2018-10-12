#include "Stack.h"
#include "Delim.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h> //exclusively for toupper()

using namespace std;

int main(int argc, char **argv)
{
  string fileName;
  Stack<char> DelimStack;
  bool validPath = false;
  bool runAgain = true;
  ifstream inFile;


/*
Entire program runs within whileloop to allow for multiple files to be analyzed
during one runtime. After each file, the user is prompted to determine if the
process will be repeated.
*/
  while(runAgain == true) //loop adds ability to go over multiple files per run
  {
    char userResponse = '\0';
    string fileName;
    Stack<char> delimStack;
    bool validPath = false;
    bool runAgain = true;
    ifstream inFile;
    int lineNum = 1;

  /*
The following whileloop repeated until the user has entered a valid filepath.
Note that there is no option for the user to exit the program if they cannot
enter the name of a valid file. That would be a nice feature for future updates.
  */
    while(validPath == false){
      cout << "Before entering the filepath to the file containing your code, "
        << " be sure to remember that if the file is not in the local directory"
        << ", you must type in the full file path." << endl << "Filepath: ";

      getline(cin,fileName);
      inFile.open(fileName);

      if(!inFile){
        cout << "Your file could not be opened. Please check to see if the "
          << "filepath is typed correctly and that the file is not already";
      }//checks if file opened
      else{
        validPath = true;
      }//file opened correctly, breaks whileloop
    }//end of path validation loop


/*
while(!inFile.eof()) is where the file analysis occurs.
*/
   while(!inFile.eof())
   {
     //Creates delim object with bool flags set
     Delim someChar(inFile.get());

     if(someChar.leftDelim==true)
     {
       delimStack.push(someChar.data);
     }//end of statement pushing delimiters to stack
     else if(someChar.rightDelim==true)
     {
       if(someChar.closer!=delimStack.peek())
       {
          cout << "Line " << lineNum << ": " << someChar.data
             << " was encountered which does not match the last opening "
             << "delimiter: " << delimStack.peek() << endl;
          return 1;
       }else{
         delimStack.pop();
       }
     }//end of elif statement handling closing delimiters
     else if(someChar.newLine == true)
     {
       lineNum++;
     }//increments line number for error statement
   }//end of whileloop analyzing file


/*
If every delimiter was popped from the stack, there are no unmatched delimiters.
There will be no error message. Below ifstatement checks before declaring that
there is nothing unmatched.
*/
   if(delimStack.isEmpty()){
     cout << "No delimiter errors found in the file." << endl;
   }

   inFile.close();

   cout << "Would you like to analyze another file? (Please type \'y\' to "
   << "analyze another file):" << endl;
   cin.get(userResponse);
   userResponse = toupper(userResponse);
   if(userResponse=='Y'){
     runAgain = true;
   } else{
     return 0;
   }// elif statement to stop additional file analysis
 }//end of whileloop used for multiple fils
}//end of main
