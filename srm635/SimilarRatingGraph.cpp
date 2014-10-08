#include <iostream>
#include <vector>
#include <map>

using namespace std;

class LonglongestPathTree
{
    struct Node {
        map<Node *, int> _adjs;
        public:
        Node()
        { 
            _adjs.clear();
        }
        ~Node()
        { 
            _adjs.clear();
        }
        int add_neighbor(Node *n, int weight);
    };

    vector<Node> _nodes;
    Node *_root;

    public:
        LonglongestPathTree() :
            _root(NULL)
        { 
            _nodes.clear();
        }

        int constructTree(int []a, int []b, int []W);
        virtual int maxLength(int []a, int []b, int []W);
        virtual ~LonglongestPathTree();
};

LonglongestPathTree::constructTree(int []a, int []b, int []W)
{
    for (int i=0; i<SIZE(a); i++) {
        _nodes.push_back(new Node());
    }

    for int (i=0; i<SIZE(a); i++)
    {
        _nodes[a[i]].add_neighbors(_nodes[b[i]], W[i]);
    }

    _root = _nodes[0];
}

int LonglongestPathTree::maxLength(int []a, int []b, int []W)
{
    constructTree(a, b, W);
    return find_diameter();
}

virtual LonglongestPathTree::~LonglongestPathTree()
{
    for(vector<Node>::interator itr=_nodes.begin(); itr!=_nodes.end(); itr++)
    {
        delete *itr;
    }

    _nodes.clear();
    _root = NULL;
}

int maxD = -1;
int LonglongestPathTree::find_diameter(Node *root)
{
    vector<int> maxDs;

    if(!root) return 0;
    
    for(map<Node*, int>::const_iterator itr=root->_adjs.begin(); itr!=root->_adjs.end(); itr++) 
    {
        maxDs.push_back(find_diameter(itr->first) + itr->second);
    }

    maxD = std::max(maxD, maxDs.max_element());
    return maxDs.max_element();
}

