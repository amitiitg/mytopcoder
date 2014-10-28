#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

class SegmentTree { 
    int* _st;
    int _st_max;
    int _N;

    int build_stree_internal(int idx, int ss, int se);
    public:
    SegmentTree();
    ~SegmentTree();
    void build_stree(int N);
    /**
     * K = [1, N]. 1 being largest, N being smallest. 
     */
    int search_and_delete(int idx, int ss, int se, int K);
};

SegmentTree::SegmentTree()
{}

SegmentTree::~SegmentTree()
{}

void SegmentTree::build_stree(int N)
{
    _N = N;
    int height = ceil(log2(N));
    _st_max = 2*pow(2, height) - 1;
    _st = new int[_st_max];
    memset(_st, 0, sizeof(int)*_st_max);

    build_stree_internal(0, _N-1, 0);
}

int SegmentTree::build_stree_internal(int ss, int se, int idx)
{
    if (ss == se) {
        _st[idx] = 1;
        return 1;
    }

    int mid = (ss+se)/2;
    _st[idx] = build_stree_internal(ss, mid, 2*idx+1) + 
        build_stree_internal(mid+1, se, 2*idx+2);
    return _st[idx];
}

// starts with 0, 0, N-1, K
int SegmentTree::search_and_delete(int idx, int ss, int se, int K)
{
    if (ss == se) {
        _st[idx] = 0;
        return ss+1;
    }

    int mid = (ss + se)/2;
    int ret = 0;
    if (_st[2*idx+2] >= K) {
        ret = search_and_delete(2*idx+2, mid+1, se, K);
    } else {
        ret = search_and_delete(2*idx+1, ss, mid, K-_st[2*idx+2]);
    }

    _st[idx] -= 1;
    return ret;
}

vector<int> get_orig_order(vector<int>& in, int N)
{
    SegmentTree st;
    st.build_stree(N);

    int res[N];
    int i=1;
    for (vector<int>::reverse_iterator itr=in.rbegin(); itr!=in.rend(); itr++) {
        int val = st.search_and_delete(0, 0, N-1, *itr + 1);
        res[N - i++] = val;
    }

    vector<int> rres(res, res+sizeof(res)/sizeof(int));
    return rres;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, tmp;
        vector<int> in;

        cin >> N;
        for (int i=0; i<N; i++) { cin >> tmp; in.push_back(tmp); }
    
        vector<int> res = get_orig_order(in, N);

        for (vector<int>::const_iterator itr=res.begin(); itr!=res.end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }

    return 0;
}

