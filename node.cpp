#include "node.h"

using namespace std;

bool ptrs_compare_functior::operator ()(const node* lhs, const node* rhs) const {
    return lhs->get_name() < rhs->get_name(); // lexicographical order
}

node::node(std::string name_)
{
    parent = nullptr;
    left = 1; // pre-defined
    right = 2; // pre-defined
    name = name_;
    children = children_set(); // empty
}

string node::get_name() const {
    return name;
}

bool node::is_leaf() const {
    return children.size() == 0;
}

bool node::is_root() const {
    return parent == nullptr;
}

void node::output_tree(string indent, bool last) const {
    cout << indent;
    if (last) {
        if (indent == "") {
            cout << char(254);// root
        }
        else
            cout << char(200); // L
        indent += "  ";
    }
    else {
        cout << char(204);//"}";
        indent += char(186);//"I";
        indent += " ";
    }
    cout << char(205) << name << "(" << left << "," << right << ")" << endl;

    for (auto it: children)
        it->output_tree(indent, it->self_iterator == prev(children.end()));
}

void node::set_left() {
    if (is_root()) {
        left = 1;
        return;
    }
    auto ln = left_neighbour();
    if (ln == parent->children.end()) // no left neighbour
        left = parent->left + 1; // I am the smallest clild; rule 2
    else
        left = (*ln)->right + 1; // rule 4
}

void node::set_right() { // pre-condition: left is correct
    if (is_leaf())
        right = left + 1;
    else
        right = (*prev(children.end()))->right + 1;
}

children_set::iterator node::left_neighbour() {
    if (self_iterator == parent->children.begin())
        return parent->children.end(); // no left neighbour
    return std::prev(self_iterator);
}

void node::mark_tree() {
    set_left();
    for (auto it: children)
        it->mark_tree();
    set_right();
    if (!is_root())
        parent->mark_the_rest_of(self_iterator);

    /*  ^this will mark all neighbours to the right
     *  of the current node and then mark the rest
     *  of the tree above it
     */
}

void node::mark_the_rest_of(children_set::iterator x) {
/* x is the iterator pointing to one of (*this).children elements
 * <a, b, c, X, d, e>
 * based on X right number, recalculate (r, l) values for all subtrees to
 * the right of X subtree (in this case, d and e) and call this function
 * recursively for the parent
 * pre-condition: X.left and X.right are correct
 */
    for (auto it = std::next(x); it != children.end(); ++it)
        (*it)->mark_tree();
    set_right(); // based on the right value of last child
    if (!is_root())
        parent->mark_the_rest_of(self_iterator);
}

void node::insert_child(node* c) {
    auto result = children.insert(c);
    assert(result.second && "child with this name already exist");
    c->self_iterator = result.first;
    c->parent = this;
    c->mark_tree();    
}

void node::pop_subtree() {
    if (is_root()) {
        cout << "Warning: node <" << name << "> is not a subtree" << endl;
        return;
    }
    auto it = left_neighbour();
    parent->children.erase(self_iterator);
    node* former_parent = parent;
    parent = nullptr;
    mark_tree(); // sub-tree whose root is (*this)
    if (former_parent->is_leaf()) // we just erased the only child
        former_parent->mark_tree();
    else {// no need to re-calculate all values, just those that changed
        if (it == former_parent->children.end()) // we just removed smallest child
            former_parent->mark_tree(); // re-calculate values for all children
        else // we removed child that had left neighbour(s)
            former_parent->mark_the_rest_of(it); // so those neighbour(s) dont need to be re-marked
    }
}

void node::move_under(node* new_parent) {
    pop_subtree();
    new_parent->insert_child(this);
}
