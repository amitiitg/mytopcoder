#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedArray {
    vector<int> _data;
    public:
        SortedArray(const vector<int>& data);
        ~SortedArray();

        int find_next_data(int val);
        int find_min();
        int find_max();

        int find_smaller_count(int val);
        vector<int>& data();
};

vector<int>& SortedArray::data()
{
    return _data;
}

SortedArray::SortedArray(const vector<int>& data)
    : _data(data)
{
    sort(_data.begin(), _data.end());
}

SortedArray::~SortedArray()
{ }

int SortedArray::find_next_data(int val)
{
    int size = _data.size();
    int l = 0, r = size-1;
    // we are not finding the val.
    while (l < r) {
        int idx = l + (r-l)/2;
        if(_data[idx] < val) {
            l = idx + 1;
        } else {
            r = idx - 1;
        }
    }

    int retidx = -1;
    if (l < size) { 
        retidx = (_data[l]<val) ? ((l+1<size) ? l+1: -1) : l;
    }
    _data.erase(_data.begin() + retidx);
    return _data[retidx];
}

int SortedArray::find_min()
{
    int ret = _data[0];
    _data.erase(_data.begin());

    return ret;
}

int SortedArray::find_max()
{
    return _data[_data.size()-1];
}

int SortedArray::find_smaller_count(int val)
{
    int size = _data.size();
    int l = 0, r = size-1;
    if (val > _data[r]) return size;
    // we are not finding the val.
    while (l < r) {
        int idx = l + (r-l)/2;
        if(_data[idx] < val) {
            l = idx + 1;
        } else {
            r = idx - 1;
        }
    }

    return ((_data[l] < val) ? l+1 : l);
}

//////////////////////////// End of Sorted Array impl //////////////////////////

class GreaterGame {
    public:
        double calc(vector<int> hand, vector<int>sothe);
};

bool IsMinusOne(int data) { return data == -1; }

vector<int> find_unfilled(const vector<int>& A, const vector<int>& B)
{
    int N = A.size();
    vector<int> tmp(A);
    tmp.reserve(2*N);

    tmp.insert(tmp.end(), B.begin(), B.end());
    remove_if(tmp.begin(), tmp.end(), IsMinusOne);

    sort(tmp.begin(), tmp.end());

    vector<int> unfilled;
    for (int i=1; i<=2*N; i++) {
        if(find(tmp.begin(), tmp.end(), i) == tmp.end()) {
            unfilled.push_back(i);
        }
    }

    return unfilled;
}

double GreaterGame::calc(vector<int> hand, vector<int> sothe)
{
    SortedArray A(hand), B(sothe);
    int winnable = 0;

    for(vector<int>::const_iterator itr=sothe.begin(); itr!=sothe.end(); itr++) {
        if(*itr != -1) {
            if (A.find_max() > *itr) {
                A.find_next_data(*itr);
                winnable++;
            } else {
                // throw in min
                A.find_min();
            }
        }
    }

    vector<int> B_new = find_unfilled(hand, sothe);
    SortedArray B_remained(B_new);

    /*
    for (int i=0; i<A.data().size(); i++) {
        cout << "-->" << A.data()[i];
    }
    cout << endl;
    for (int i=0; i<B_new.size(); i++) {
        cout << "-->" << B_new[i];
    }
    cout << endl;
    */

    double win_p = 0.0;
    for(vector<int>::const_iterator itr=A.data().begin(); itr!=A.data().end(); itr++) {
        double win_ai_p = (1.0*B_remained.find_smaller_count(*itr))/(1.0*B_new.size());
        win_p += win_ai_p;
    }

    return winnable*1.0 + win_p;
}

int main()
{
    int a[] = {6,12,17,14,20,8,16,7,2,15}; 
    int b[] = {-1,-1,4,-1,11,3,13,-1,-1,18};
    vector<int> tmp1(a, a+sizeof(a)/sizeof(int));
    vector<int> tmp2(b, b+sizeof(b)/sizeof(int));

    GreaterGame g;
    cout << g.calc(tmp1, tmp2) << endl;

    return 0;
}
