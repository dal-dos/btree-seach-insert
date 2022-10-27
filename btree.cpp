
// Implement your C++ subroutines and methods here.

#include "btree.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstdlib>


using namespace std;



//--------------------------//
//--------------------------//
//    Methods for btnode    //
//--------------------------//
//--------------------------//

//-------------------------------------------------------------------
//
//   Constructor :: creates a leaf node with 0 keys and parent = NULL;
//
//-------------------------------------------------------------------
btnode::btnode() {
    keys.resize(0);
    children.resize(1, NULL);
    parent = NULL;
} // btnode::btnode


//-------------------------------------------------------------------
//
//   Constructor :: creates a node with k keys, k+1 children and a parent
//
//-------------------------------------------------------------------
btnode::btnode(vector<int>& keys, vector<btnode*>& children, btnode* parent) : keys(keys), children(children), parent(parent) {
    if (keys.size() != children.size() - 1) {
        char buf[512];
        sprintf_s(buf, "Tried to create BTNode with %d keys and %d children.", keys.size(), children.size());
        string exc = string(buf);
        throw exc;
    }
} // btnode::btnode


//-------------------------------------------------------------------
//
//   Constructor :: creates a node with k keys, k+1 NULL children and a parent
//
//-------------------------------------------------------------------
btnode::btnode(vector<int>& keys, btnode* parent) : keys(keys), children(keys.size() + 1, NULL), parent(parent) {
} // btnode::btnode


//*************************************************************************//
//*************************************************************************//

//-------------------------//
//-------------------------//
//    Methods for btree    //
//-------------------------//
//-------------------------//


//-------------------------------------------------------------------
//
//    Constructor :: creates an empty btree data structure
//
//-------------------------------------------------------------------
btree::btree() {
    root = NULL;
} // btree::btree



//-------------------------------------------------------------------
//
//    Constructor :: scans a btree from input stream is
//      - not all btree invariants are checked
//
//-------------------------------------------------------------------
btree::btree(istream& is) {
    stack<btnode*> S;

    btnode* x = new btnode();

    int state = 0;  //  0 = next may be either key or subtree
                    //  1 = next may be only key
    char c;
    int d;

    is >> c;

    while (!is.eof()) {
        //   get the next token
        //     - tokens are either integers, '[' or ']'.
        //     - all other characters are treated as whitespace

        if (c == '[') {

            //  new subtree
            if (state == 1) {
                cout << "Two subtrees in a row, but no separating key." << endl;
                root = NULL;
                return;
            }
            S.push(x);
            x = new btnode();
            state = 0;


        }
        else if (c == ']') {

            //  end subtree
            if (S.empty()) {
                cout << "Unbalanced square brackets. (Unmatched ']')" << endl;
                root = NULL;
                return;
            }
            while (x && x->keys.size() == 0) {
                btnode* tmp = x;
                x = x->children[0];
                delete tmp;
            }
            S.top()->children[S.top()->children.size() - 1] = x;
            if (x) {
                x->parent = S.top();
                state = 1;
            }
            else {
                state = 0;
            }
            x = S.top();
            S.pop();


        }
        else if (c == '-') {

            //  negative number
            char tst;
            is >> tst;
            if (!is.eof()) {
                is.unget();

                if ('0' <= tst && tst <= '9') {
                    is >> d;
                    x->keys.push_back(-d);
                    x->children.push_back(NULL);
                    state = 0;
                }
            }


        }
        else if ('0' <= c && c <= '9') {

            //  nonnegative number
            is.unget();
            is >> d;
            x->keys.push_back(d);
            x->children.push_back(NULL);
            state = 0;


        }
        else {

            // ignore


        }

        is >> c;

    }

    if (!S.empty()) {
        cout << "Unbalanced square brackets. (Unmatched '[')" << endl;
        root = NULL;
        return;
    }

    root = x;

    while (root && root->keys.size() == 0) {
        btnode* tmp = root;
        root = root->children[0];
        delete tmp;
    }
} // btree::btree



//-------------------------------------------------------------------
//
//    prints a btree (prettily)
//
//-------------------------------------------------------------------
void btree::print(ostream& os) {
    print_helper(os, root);
    os << endl;
} // btree::print



void btree::print_helper(ostream& os, btnode* x) {
    if (x == NULL) return;
    os << " [";
    int i = 0;
    while (i < x->keys.size() || i < x->children.size()) {
        if (i < x->children.size()) {
            print_helper(os, x->children[i]);
        }
        if (i < x->keys.size()) {
            os << ' ' << x->keys[i];
        }
        i++;
    }
    os << " ]";
} // btree::print_helper



//-------------------------------------------------------------------
//
//    searches the btree for key; returns true iff found [10 marks]
//
//-------------------------------------------------------------------
bool btree::search(int key) {



    return false;

} // btree::search



//-------------------------------------------------------------------
//
//    inserts key [30 marks]
//      - pre-condition:  key is not already in the btree
//
//-------------------------------------------------------------------
void btree::insert(int key) {

} // btree::insert

