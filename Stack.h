#include <iostream>
#include <cstdlib>
#include <cstdbool>

using namespace std;

template <typename T>
class Stack
{
public:
  Stack();
  Stack(int maxSize);
  ~Stack();

  void push(T data);
  T pop();
  T peek();
  int getSize();
  bool isEmpty();
  //bool isFull();
  void resize();

  int size;
  int top;

  T *myArray;
};


//Function Definitions//
//Constructors:
template <typename T>
Stack<T>::Stack()
{
  myArray = new T[3];
  size = 3;
  top = -1;
}

template <typename T>
Stack<T>::Stack(int maxSize)
{
  myArray = new T[maxSize];
  size = maxSize;
  //numElements= 0;
  top = -1;
}


template <typename T>
bool Stack<T>::isEmpty()
{
  if(top==-1){
    return true;
  }
  else{
    return false;
  }
}

//Deconstructor
template <typename T>
Stack<T>::~Stack()
{
  while(!(this->isEmpty())){
    pop();
  }
  delete myArray;
}

//Functions:
template <typename T>
void Stack<T>::push(T data)
{
  if((top+1)==size){
    resize();
  }

  myArray[++top] = data;
}

template <typename T>
T Stack<T>::pop()
{
  if(this->isEmpty()){
    cout << "can't pop empty stack";
    //exit(EXIT_FAILURE);
  }
  size--;
  return myArray[top--];
}

template <typename T>
T Stack<T>::peek()
{
  if(!this->isEmpty()){
    return myArray[top];
  }
  else
    exit(EXIT_FAILURE);
}

template <typename T>
int Stack<T>::getSize()
{
  return (top++);
}

template <typename T>
void Stack<T>::resize()
{
  T* temp = new T[this->size*2];
  for(int i = 0; i < this->size; i++){
    temp[i] = this->myArray[i];
  }
  delete [] this->myArray;
  this->myArray = temp;
  this->size = size*2;
}
