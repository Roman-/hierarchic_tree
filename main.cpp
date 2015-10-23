#include <iostream>
#include <set>
#include "node.h"
#include "tree_test_cases.h"

using namespace std;

int main()
{
    test::init_example_tree(); // mandatory

    /*
     * To apply any testcase, please comment or uncomment
     * one of the lines above:
     */

    //test::test_example_tree();
    //test::simple_build_and_pop();
    //test::build_and_pop();
    test::move();
    //test::pop_smallest_child();


    return 0;
}
