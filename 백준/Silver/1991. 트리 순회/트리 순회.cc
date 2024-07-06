#include <iostream>
#include <queue>
using namespace std;

struct node {
    string position;
    node* first;
    node* second;
};

struct org_tree {
    node* root;
    static org_tree create_org_structure(const string& pos) {
        org_tree tree;
        tree.root = new node{ pos,NULL,NULL };
        return tree;
    }

    static node* find(node* root, const string& value) {
        if (root == NULL)
            return NULL;
        if (root->position == value)
            return root;

        auto firstFound = org_tree::find(root->first, value);

        if (firstFound != NULL)
            return firstFound;

        return org_tree::find(root->second, value);
    }
    bool addSubordinate(const string& manager, const string& subordinate) {
        auto managerNode = org_tree::find(root, manager);
            
        if (!managerNode->first)
            managerNode->first = new node{ subordinate,NULL,NULL };
        else
            managerNode->second = new node{ subordinate,NULL,NULL };

        return true;
    }
};

static void preOrder(node* start) {
    if (start->position==".")
        return;
    cout << start->position;
    preOrder(start->first);
    preOrder(start->second);
}

static void inOrder(node* start) {
    if (start->position==".")
        return;
    inOrder(start->first);
    cout << start->position;
    inOrder(start->second);
}

static void postOrder(node* start) {
    if (start->position==".")
        return;
    postOrder(start->first);
    postOrder(start->second);
    cout << start->position;
}

int main() {
    auto tree = org_tree::create_org_structure("A");

    int n;
    string r, lc, rc;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> r >> lc >> rc;
        tree.addSubordinate(r, lc);
        tree.addSubordinate(r, rc);
    }

    preOrder(tree.root);
    cout << endl;
    inOrder(tree.root);
    cout << endl;
    postOrder(tree.root);
}