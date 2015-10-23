#include <iostream>
#include <set>
#include "node.h"
#include "tree_test_cases.h"

using namespace std;

void output_welcome_message() {
    cout << "Please enter a number from 1 to 5 to fetch the testcase." << endl;
    cout << "1: test example tree building;" << endl;
    cout << "2: test remove function on a simple tree;" << endl;
    cout << "3: test remove function on example tree;" << endl;
    cout << "4: test remove smallest chile on example tree;" << endl;
    cout << "5: test move function on example tree;" << endl;
    cout << "e: exit." << endl << endl;
    cout << "command: ";
}

int main()
{
    test::init_example_tree(); // mandatory
    char command;
    while (true) {
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
