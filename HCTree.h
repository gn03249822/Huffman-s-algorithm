#ifndef HCTREE_H
#define HCTREE_H

#include <queue>
#include <vector>
#include <fstream>
#include "HCNode.h"
#include "BitInputStream.h"
#include "BitOutputStream.h"

/**
 * Name: Daniel Huang
 * Date: 2/10/2017
 * Assignment: PA3
 * Header file that contains constructors and function declarations
 */
using namespace std;

/** A 'function class' for use as the Compare class in a
 *  priority_queue<HCNode*>.
 *  For this to work, operator< must be defined to
 *  do the right thing on HCNodes.
 */
class HCNodePtrComp {
public:
    bool operator()(HCNode*& lhs, HCNode*& rhs) const {
        return *lhs < *rhs;
    }
};

/** A Huffman Code Tree class.
 *  Not very generic:  Use only if alphabet consists
 *  of unsigned chars.
 */
class HCTree {
private:
    HCNode* root;
    
    vector<HCNode*> leaves;
    
    //the helper method for the destructor
    void deleteAll(HCNode* p) ;
    
public:
    
    
    // explicit keyword is used to avoid accidental implicit conversions
    explicit HCTree() : root(0) {
        leaves = vector<HCNode*>(256, (HCNode*) 0);
        
    }
    
    ~HCTree();
    
    //the getter for the root
    HCNode* getRoot() const{
        return this->root;
    }
    
    //the setter for the root of the tree
    void setRoot(HCNode* p) {
        this->root=p;
    }
    
    //the getter for the leaves
    vector<HCNode*> getLeaves() const {
        return this->leaves;
        
    }
    //the setter for leaves
    void setLeaves(HCNode *p, int idx) {
        
        this->leaves[idx]=p;
    }
    
    //return true if the node is a leaf
    bool noChild(HCNode*p) const{
        if(p->c0==0 && p->c1==0) {
            return true;
        }
        return false;
    }
    
    
    /** Use the Huffman algorithm to build a Huffman coding trie.
     *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is
     *  the frequency of occurrence of byte i in the message.
     *  POSTCONDITION:  root points to the root of the trie,
     *  and leaves[i] points to the leaf node containing byte i.
     */
    void build(const vector<int>& freqs);
    
    /** Write to the given BitOutputStream
     *  the sequence of bits coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    void encode(byte symbol, BitOutputStream& out) const;
    
    
    /** Write to the given ofstream
     *  the sequence of bits (as ASCII) coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT
     *  BE USED IN THE FINAL SUBMISSION.
     */
    void encode(byte symbol, ofstream& out) const;
    
    
    /** Return symbol coded in the next sequence of bits from the stream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    int decode(BitInputStream& in) const;
    
    /** Return the symbol coded in the next sequence of bits (represented as
     *  ASCII text) from the ifstream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT BE USED
     *  IN THE FINAL SUBMISSION.
     */
    int decode(ifstream& in) const;
    
    /* My own method that would traverse through the tree and write to header file
       more efficiently
     */
    void writeHeader(HCNode* curr, ostream& out);
    
};

#endif // HCTREE_H
