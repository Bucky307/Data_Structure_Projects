#include <iostream>
#include "binarynode.h"
using namespace std;

#ifndef BINARYSEARCHTREE_
#define BINARYSEARCHTREE_


template <class T>
class BinarySearchTree  {
public:
//------------------------------------------ CONSTRUCTOR
    BinarySearchTree()
    {
        for(int i = 0; i < 15; i++)
        tree[i] = nullptr;
    }
//------------------------------------------ DESTRUCTOR
    ~BinarySearchTree() 
    {
        string x("");
        for(int i = 0; i < 15; i++)
        {
            remove(x, tree[i]);
        }
    }
//------------------------------------------ REMOVE
    void remove (T x, BinaryNode<T> *&t)
     {
        if ( t == nullptr) return;   // Item not found; do nothing
        if ( x.compare(t->data) < 0)
            remove( x, t->left );
        else if( x.compare(t -> data) > 0)
            remove( x, t -> right );
        else {
            BinaryNode<T> * oldNode;
            if ( t -> left == nullptr) { // has a right child or no children
                oldNode = t;
                t = t->right;
                delete oldNode;
                size--;
                return;
            } 
            else if( t -> right == nullptr) { //has a left child
                oldNode = t;
                t = t->left;
                delete oldNode;
                size--;
                return;
            }
            //has two children
            oldNode = findMin( t -> right );
            t->data = oldNode->data;
            remove( t -> data, t ->right );
        }
    }
//------------------------------------------ INSERT (PUBLIC)
    void insert (T item)
    {
        if(item.length() < 15)
            insert(item, tree[item.length()-1]);
        else
            insert(item, tree[14]);
    }
//------------------------------------------ FIND (PUBLIC)
    BinaryNode<T> * find (T item, long long int &wfCompares, long long int &wnfCompares)
    {
        //public find is overlay to a recurve find.

        if(item.length() < 15)
            return find(item, tree[item.length()-1], wfCompares, wnfCompares);
        else
            return find(item, tree[14], wfCompares, wnfCompares);
    }
//------------------------------------------ GET SIZE
    int getSize()
    {
        return size;
    }
//-------------------PRIVATE-------------------
private:
//------------------------------------------ FIND (PRIVATE)
    BinaryNode<T> *find (T item, BinaryNode<T> *t, long long int &wfCompares, long long int &wnfCompares)
    {
        if ( t == nullptr )
        {
            wnfCompares += count;
            count = 0;
            return nullptr;
        }
        else if (item.compare(t -> data) < 0)
        {
            count++;
            return find ( item, t -> left, wfCompares, wnfCompares);
        }
        else if (item.compare(t -> data) > 0)
        {
            count++;
            return find ( item, t -> right, wfCompares,wnfCompares);
        }
        else
        {
            wfCompares += count;
            count = 0;
            return t;    // Match
        }
    } 
//------------------------------------------ FIND MIN
    BinaryNode<T> *findMin (BinaryNode<T> *t) 
    {
      if ( t == nullptr )
            return nullptr;
      else if ( t -> left == nullptr )
            return t;
      return findMin (t -> left);
    }
//------------------------------------------ INSERT (PRIVATE)
    void insert (T item, BinaryNode<T> *&t)
    {
        if (t == nullptr)
        {
            size++;
            t = new BinaryNode<T> (item);
        }
        else if (item.compare(t -> data) < 0)
        {
            insert(item, t -> left);
        }
        else if(item.compare(t -> data) > 0)
        {
            insert(item, t -> right);   
        }
        else
            ;  // Duplicate entry; do nothing
 
    }

    BinaryNode<T> *tree[15];
    int size = 0;
    long long int count = 0;
};

#endif
