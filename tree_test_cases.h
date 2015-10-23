#ifndef TREE_TEST_CASES_H
#define TREE_TEST_CASES_H
#include "node.h"

void log(std::string message, node* tree = nullptr);

class test {
public:
    static void init_example_tree();
    /* test cases */
    static void test_example_tree();
    static void simple_build_and_pop();
    static void build_and_pop();
    static void pop_smallest_child();
    static void move();
};

#endif // TREE_TEST_CASES_H
