#include <iostream>
#include "node.h"
using namespace std;

#ifndef MYLIST_
#define MYLIST_


template <class T>
class myList{
 public:
    myList()
    { 
    for(int i = 0; i < 15; i++)
    {
      sort[i] = nullptr;
    }
    size = 0; 
    
    }
    ~myList();

    void remove();
    void insert (T item);
    //void print(int, int, int , long int , long int, double);
    bool find(T item, long int&, long int&);
    bool isEmpty() { return size == 0; }
    int getSize() { return size;}
    

 private:
    // x1 through x14 are linked lists for words with the size x_ (eg. "and" will be stored in x3). 
    //Other is for words with a length longer than 14.
    node<T> * x1;
    node<T> * x2;
    node<T> * x3;
    node<T> * x4;
    node<T> * x5;
    node<T> * x6;
    node<T> * x7;
    node<T> * x8;
    node<T> * x9;
    node<T> * x10;
    node<T> * x11;
    node<T> * x12;
    node<T> * x13;
    node<T> * x14;
    node<T> * other;
    node<T> * sort[15] = {x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,other};
    int size;
};

template <class T>
//------------------------------------------ REMOVE
void myList<T>:: remove() {
  node<T> * tmp = nullptr;

  for (int i = 0; i < 15; i++)
  {
    if(sort[i] != nullptr)
    {
      tmp = sort[i];
      sort[i] = tmp->next;
      delete tmp;  
      size--;
    }
  }
}
template <class T>
//------------------------------------------ INSERT 
void myList<T>:: insert (T item) {
  
  node<T> * tmp = new node<T>;


    if(item.length() < 15)
      {
        tmp->data = item;
        tmp->next = sort[item.length()-1];
        sort[item.length()-1] = tmp;
      }
      else
      {
        tmp->data = item;
        tmp->next = sort[14];
        sort[14] = tmp;
      }
  
  size++;

}
template <class T>
//------------------------------------------ FIND
bool myList<T>::find(T item, long int& wfCompares, long int& wnfCompares)
{
  node<T> * tmp;
  int compareCounter = 0;


    if(item.length() < 15)
      {
        for (tmp = sort[item.length()-1];  tmp != nullptr; tmp = tmp->next) 
        {
          compareCounter++;
          if (tmp->data.compare(item) == 0) 
          {    
            wfCompares += compareCounter; return true;
          }
        }  
        wnfCompares += compareCounter;
        return false;
      }
      else
      {
        for (tmp = sort[14];  tmp != nullptr; tmp = tmp->next) 
        {
          compareCounter++;
          if (tmp->data.compare(item) == 0) 
          {    
            wfCompares += compareCounter; return true;
          }
        }  
        wnfCompares += compareCounter;
        return false;
      }
}
template <class T>
//------------------------------------------ DESTRUCTOR
myList<T>:: ~myList() {

  while(!isEmpty())
 {
   remove();
 }
}


#endif