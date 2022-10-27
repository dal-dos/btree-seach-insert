
#ifndef _BTREE_HPP_
#define _BTREE_HPP_

#include <vector>
#include <iostream>

//  This is the parameter t that governs the branching factor of the btree.  
//  It may change when we test your code.
#define _BTREE_T_ 2

using namespace std;

class btnode;
class btree;


class btnode {
public:
    btnode();
    btnode(vector<int>& keys, vector<btnode*>& children, btnode* parent);
    btnode(vector<int>& keys, btnode* parent);

    // invariant:  keys.size() + 1 == children.size()
    // invariant:  if parent != NULL then _BTREE_T_ <= children.size()
    // invariant:  if parent != NULL then children.size() <= 2 * _BTREE_T_
    vector<int> keys;
    vector<btnode*> children;
    btnode* parent;
};


class btree {
public:
    btree();                   //  default constructor:  empty tree
    btree(istream& is);        //  constructor:  build a tree from input stream
    void print(ostream& os);   //  display a tree to output stream
    bool search(int key);      //  search for key [10 marks]
    void insert(int key);      //  insert key [30 marks]

private:
    btnode* root;              //  the root btnode of the tree
    void print_helper(ostream& os, btnode* x);
};


#endif // _BTREE_HPP_
