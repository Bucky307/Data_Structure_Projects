#include <string>
#include <iostream>

using namespace std;

#ifndef MYHASH_
#define MYHASH_

template <class T>
class myHash {
 private:
     //hashsize is number you are going to decided on.
     const static int HASHSIZE = 133168*2;
    T * hash; 
    int size;
public:
    //constructor
    myHash() 
    {
        hash = new T[HASHSIZE];
        //initialize
        size =0;
        for(int i=0; i<HASHSIZE; i++) 
        {
            hash[i]="";
        }
        
    }
    //destructor
    ~myHash() 
    {
        delete []hash;
    }
    //insert
    void insert(T item)
    {
        int attempttimes = 0;
        int key = findhash(item);
        if (hash[key].empty()) 
        {
            hash[key] = item;
        } 
        else  
        {
            bool entered = false;
            while (!entered) 
            {
                attempttimes ++;
                key += attempttimes*attempttimes;          
                if (hash[key].empty()) 
                {
                    hash[key] = item;
                    entered = true;
                }
            }
        }   
        size++;
    }

    //find
    bool find(T item, long long int &wf, long long int &wnf)
    {
        int attempttimes = 0;
        int key = findhash(item);
        if (key > HASHSIZE) key %= HASHSIZE;
        if (hash[key].compare(item) ==0)
        {     //found it
            wf ++;
            return true;
        } 
        else if (hash[key].empty()) 
        {
            wnf++;
            return false;
        } 
        else   
        {
            bool found = false;
            while (!found) 
            {
                attempttimes ++;
                key += attempttimes*attempttimes;  
                if (hash[key].compare(item) ==0) 
                {
                    wf++;
                    return true; // or found = true;
                } 
                else if (hash[key].empty()) 
                {
                    wnf++;
                    return false;
                }
            }
            wnf++;
            return false; 
        }
    }

     int getSize() { return size;}
     int findhash(string word)
     {
        int val = 0;
        for(int i = 0; i < word.length(); i++)
        {
            val += (int)word[i]*(i+3)*(i*5)*(i+7);
        }
        val %= HASHSIZE;
        return val;
     }
};

#endif