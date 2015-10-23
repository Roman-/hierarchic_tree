#ifndef NODE_H
#define NODE_H

#include <set>
#include <string>
#include <iostream>
#include <cassert>

class node; // forward declaration for number typedef
struct ptrs_compare_functior; // forward declaration for children_set typedef

typedef unsigned short number; // left and right values
typedef std::set<node*, ptrs_compare_functior> children_set;

struct ptrs_compare_functior { // function object to compare two node pointers
  bool operator() (const node* lhs, const node* rhs) const;
};

class node
{
    number left; // assuming left value < 65536
    number right; // right value, < 65536
    std::string name; // for sorting
    children_set children;
    node* parent; // nullptr if the node is root
    children_set::iterator self_iterator; // points to current node inside parent's set of clildren

    void mark_the_rest_of(std::set<node*>::iterator); // see the description in fucntion definition
    void mark_tree(); // set left, mark children subtrees and mark the rest of current tree above
    void set_left(); // based on left neighbour or parent
    void set_right(); // based on left value or last child
    children_set::iterator left_neighbour(); // based on self_iterator; returns end() if no left neighbours

public:
    node(std::string name_); // create a single-node tree

    std::string get_name() const;
    bool is_leaf() const; // has no children
    bool is_root() const; // has no parent
    void output_tree(std::string indent = "", bool last = true) const; // print to console

    void insert_child(node*); // insert into set of clildren and recalculate (l,r) of changed nodes including nodes above
    void pop_subtree(); //separates sub-tree with root (*this) from the rest of current tree
    void move_under(node* new_parent); // move current subtree under new_parent

};

#endif // NODE_H
