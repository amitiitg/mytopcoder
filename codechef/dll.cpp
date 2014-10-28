#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LL {
    struct Node {
        int data;
        struct Node* next;
        struct Node* prev;

        Node():
            data(0),
            next(NULL),
            prev(NULL)
        {}
    };

    int N;
    struct Node* head, *tail;
    struct Node** hash;
    
    struct Node* _internal_nodes;
    int _internal_idx;
    
    Node *get_node()
    {
        return &(_internal_nodes[_internal_idx++]);
    }

    public:
    LL(int N):
        N(N),
        head(NULL), 
        tail(NULL)
    {
        hash = new Node *[N];
        _internal_nodes = new Node[N];
        _internal_idx = 0;
    }

    ~LL() 
    {
        delete [] hash;
        hash = NULL;
        delete [] _internal_nodes;
        _internal_nodes = NULL;
        _internal_idx = 0;
    }

    int append_item(int val);
    int delete_item(int val);
    int get_last();
};

int LL::append_item(int val)
{
    Node* n = get_node();
    n->data = val;
    hash[val-1] = n;

    if (tail == NULL) {
        tail = n;
        head = n; // if there is last elem, there would be first. 
    } else {
        tail->next = n;
        n->next = NULL;
        n->prev = tail;
        tail = n;
    }

    return 0;
}

int LL::delete_item(int val)
{
    struct Node* curr = hash[val-1];

    if(curr == NULL) { // error 
        cout << " ??" << val << endl;
        return -1;
    }

    if (curr->prev) {
        curr->prev->next = curr->next;
    } else {
        head = curr->next;
    }
    if (curr->next) {
        curr->next->prev = curr->prev;
    } else {
        tail = curr->prev;
    }

    return 0;
}

int LL::get_last()
{
    if (tail) {
        return tail->data;
    }

    return 0; // error
}
