#include <iostream>
#include <set>
#include "node.h"
#include "tree_test_cases.h"

using namespace std;


int main()
{
    char command;
    while (true) {
        test::init_example_tree();
        output_welcome_message();
        cin >> command;
        switch (command) {
            case '1': test::test_example_tree(); break;
            case '2': test::simple_build_and_pop(); break;
            case '3': test::build_and_pop(); break;
            case '4': test::pop_smallest_child(); break;
            case '5': test::move(); break;
            case 'e': exit(0); break;
            default: cout << "unknown command. " << endl;
        }
        cout << endl << "<<end of testcase>>" << endl << endl;

    }
    return 0;
}
