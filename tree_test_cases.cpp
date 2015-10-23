#include "tree_test_cases.h"
#include <iostream>
using namespace std;

void log(std::string message, node* tree) {
    if (tree == nullptr)
        cout << message << endl;
    else {
        cout << message << endl << endl;
        tree->output_tree();
        cout << endl;
    }
}

/* We will store all nodes from an example tree as global variables.
 * That is usually a bad practice but uh whatever.
 */

node *a, *b, *c, *d, *e, *f, *g;

void test::init_example_tree() {
    a = new node("A");
    b = new node("B");
    c = new node("C");
    d = new node("D");
    e = new node("E");
    f = new node("F");
    g = new node("G");

    e->insert_child(f);
    e->insert_child(g);

    b->insert_child(c);

    a->insert_child(b);
    a->insert_child(d);
    a->insert_child(e);
}

void test::test_example_tree() {
    log("Let`s build our example tree: http://vk.cc/4kxlGT", a);
}

void test::simple_build_and_pop() {
    node* n1 = new node("N1");
    node* n2 = new node("N2");
    n1->insert_child(n2);
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
    e->move_under(b);
    log("After that, tree A looks like: http://vk.cc/4kxnvO", a);
}

void test::pop_smallest_child() {
    log("Suppose we have the initial tree: http://vk.cc/4kxlGT", a);
    log("and we want to remove subtree <B> which is the smallest child of <A>...");
    b->pop_subtree();
    log("After removing, tree A looks like:", a);
    log("And a new separated tree B is like: ", b);
}
