#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string &x)
{
    if (root == NULL)
    {
        root = new BinaryNode();
        root->value = x;
    }
    else
    {
        insert(root, x);
    }
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string &x)
{
    root = remove(root, x);
}

void BinarySearchTree::insert(BinaryNode *&i, const string &s)
{
    int number = i->value.compare(s);
    if (number > 0)
    {
        if (i->left == NULL)
        {
            i->left = new BinaryNode();
            i->left->value = s;
        }
        else
        {
            insert(i->left, s);
        }
    }

    if (number < 0)
    {
        if (i->right == NULL)
        {
            i->right = new BinaryNode();
            i->right->value = s;
        }
        else
        {
            insert(i->right, s);
        }
    }
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode *BinarySearchTree::remove(BinaryNode *&n, const string &x)
{
    if (n == NULL)
    {
        return NULL;
    }

    // first look for x
    if (x == n->value)
    {
        // found
        if (n->left == NULL && n->right == NULL)
        {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        }
        else if (n->left == NULL)
        {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode *temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        else if (n->right == NULL)
        {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode *temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        else
        {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    }
    else if (x < n->value)
    {
        n->left = remove(n->left, x);
    }
    else
    {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string &x) const
{
    // YOUR IMPLEMENTATION GOES HERE
    if (find(x) != true)
    {
        return "";
    }
    if (root != NULL)
    {
        string result = pathTo(root, x);
        return result;
    }

    return NULL;
}

string BinarySearchTree::pathTo(BinaryNode *const &someNode, const string &x) const
{

    string result;
    int num = someNode->value.compare(x);
    if (num == 0)
    {
        result += someNode->value;
        result += " ";
    }
    if (num > 0)
    {
        result += someNode->value;
        result += " ";
        if (someNode->left != NULL)
        {
            result += pathTo(someNode->left, x);
        }
    }
    if (num < 0)
    {
        result += someNode->value;
        result += " ";
        if (someNode->right != NULL)
        {
            result += pathTo(someNode->right, x);
        }
    }
    return result;
}

bool BinarySearchTree::find(const string &x) const
{
    if (root == NULL)
    {
        return false;
    }
    bool result = find(root, x);
    return result;
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const
{
    // YOUR IMPLEMENTATION GOES HERE
    if (root == NULL)
    {
        return 0;
    }
    int result = numNodes(root);
    return result;
}

int BinarySearchTree::numNodes(BinaryNode *const &someNode) const
{

    int result = 1;
    if ((someNode->left != NULL))
    {
        result += numNodes(someNode->left);
    }
    if ((someNode->right != NULL))
    {
        result += numNodes(someNode->right);
    }
    return result;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode *node) const
{
    // go to bottom-left node
    if (node->left == NULL)
    {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree()
{
    printTree(root, NULL, false);
}

bool BinarySearchTree::find(BinaryNode *const &someNode, const string &someString) const
{
    if (someNode == NULL)
    {
        return false;
    }
    if (someNode->value == someString)
    {
        return true;
    }
    if (someNode->value > someString)
    {
        return find(someNode->left, someString);
    }
    if (someNode->value < someString)
    {
        return find(someNode->right, someString);
    }
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode *root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}
