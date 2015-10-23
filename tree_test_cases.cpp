#include "tree_test_cases.h"
#include <iostream>
using namespace std;

void log(std::string message, shared_ptr<node> tree) {
    if (tree == nullptr)
        cout << message << endl;
    else {
        cout << message << endl << endl;
        tree->output_tree();
        cout << endl;
    }
}

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


/* We will store all nodes from an example tree as global variables.
 * That is usually a bad practice but uh whatever.
 */

shared_ptr<node> a, b, c, d, e, f, g;

void test::init_example_tree() {
    a = shared_ptr<node>(new node("A"));
    b = shared_ptr<node>(new node("B"));
    c = shared_ptr<node>(new node("C"));
    d = shared_ptr<node>(new node("D"));
    e = shared_ptr<node>(new node("E"));
    f = shared_ptr<node>(new node("F"));
    g = shared_ptr<node>(new node("G"));

    /* In real life, we will only insert pointers like this:
     *      node *a("A"), *b("B");
     *      a->insert_child(b);
     * but in this case I use shared_ptr because I have to
     * re-init the tree every time without taking care of
     * making allocated memory free over and over again.
     * */

    e->insert_child(&* f);
    e->insert_child(&* g);

    b->insert_child(&* c);

    a->insert_child(&* b);
    a->insert_child(&* d);
    a->insert_child(&* e);
}

void test::test_example_tree() {
    log("Let`s build our example tree: http://vk.cc/4kxlGT", a);
}

void test::simple_build_and_pop() {
    shared_ptr<node> n1(new node("N1"));
    shared_ptr<node> n2(new node("N2"));
    n1->insert_child(&*n2);
    log("Suppose we have a simple tree: ", n1);
    log("Let`s try to separate n2. ");
    n2->pop_subtree();
    log("Now, n1 looks like: ", n1);
    log("and n2 looks like: ", n2);
    log("And if we try to pop <N2> again, we will get this message: ");
    n2->pop_subtree();
    log("So that afterwards tree <N2> remains the same: ", n2);
}

void test::build_and_pop() {
    log("So we have the initial tree: http://vk.cc/4kxlGT", a);
    log("Now let`s remove subtree <E>: http://vk.cc/4kxnc0 ");
    e->pop_subtree();
    log("After that, tree A looks like:", a);
    log("And a new separated tree E is like: ", e);
}

void test::test::move() {
    log("Let`s test the move operation for our tree: http://vk.cc/4kxlGT", a);
    log("We move subtree E under node B: http://vk.cc/4kxnc0");
    e->move_under(&*b);
    log("After that, tree A looks like: http://vk.cc/4kxnvO", a);
}

void test::pop_smallest_child() {
    log("Suppose we have the initial tree: http://vk.cc/4kxlGT", a);
    log("and we want to remove subtree <B> which is the smallest child of <A>...");
    b->pop_subtree();
    log("After removing, tree A looks like:", a);
    log("And a new separated tree B is like: ", b);
}
