#ifndef HCNODE_H
#define HCNODE_H

#include <iostream>

/**
 * Name: Daniel Huang
 * Date: 2/10/2017
 * Assignment: PA3
 * Header file that contains constructors and function declarations
 */
typedef unsigned char byte;

using namespace std;

/** A class, instances of which are nodes in an HCTree.
 */
class HCNode {

public:
    int count; // the frequency of the symbol
    byte symbol; // byte in the file we're keeping track of
    HCNode* c0;  // pointer to '0' child, null if leaf
    HCNode* c1;  // pointer to '1' child, null if leaf
    HCNode* parent;   // pointer to parent, null if root

    
    //the constructor of node, using member initializer list
    HCNode(int count,
      byte symbol,
      HCNode* c0 = 0,
      HCNode* c1 = 0,
      HCNode* parent = 0)
        : count(count), symbol(symbol), c0(c0), c1(c1), parent(parent) { }

    
    
    /** Less-than comparison, so HCNodes will work in std::priority_queue
     *  We want small counts to have high priority.
     *  And we want to break ties deterministically.
     */
    bool operator<(const HCNode& other);
};




/** For printing an HCNode to an ostream
 *  Possibly useful for debugging.
 */
ostream& operator<<(ostream&, const HCNode&) __attribute__((weak)); // shut the linker up
ostream& operator<<(ostream& stm, const HCNode& n) {
    stm << "[" << n.count << "," << (int) (n.symbol) << "]";
    return stm;
}


#endif // HCNODE_H
