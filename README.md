### Syntax Checker
## Assignment 3
Devon Ball
CPSC-350
Section1


  Syntax Checker searches through files of text, returning the line of the first instance of mismatch and displaying the types of mismatching demiliters. Currently, Syntax Checker verifies only three delimiter types: "()", "[]", and "{}".
  
  The program uses a template stack class, Stack, to keep track of demiliters as it searches the file. One source, excluding the class's textbook, was used when learning to reference object members in class member functions. 
  http://www.agapow.net/programming/cplusplus/no-arguments-that-depend-on-a-template-parameter/
  
  A second class, Delim, was used to to create an object for each character read into the program. It allows for a more easy comparison of characters.
