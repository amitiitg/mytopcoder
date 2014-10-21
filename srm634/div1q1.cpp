#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ShoppingSurveyDiv1 {
    public:
        int minValue(int, int, vector<int>&);
};

bool myfunc(int i, int j) { return i>j; }

int ShoppingSurveyDiv1::minValue(int N, int K, vector<int>& s)
{
    sort(s.begin(), s.end(), myfunc);

    int i=0, agg = 0, sz = s.size(); 
    while(i < sz && (agg < N*(K-1))) {
        agg += s[i++];
    }

    int tmp = max(0, agg - N*(K-1));
    for (int j=i; j<sz; j++) {
        tmp = max(tmp, s[j]);
    }

    return tmp;
}

int main()
{
    int tmp[] = {1, 2, 3};
    vector<int> v(tmp, tmp + sizeof(tmp)/sizeof(tmp[0]));

    ShoppingSurveyDiv1 s;
    cout << s.minValue(10, 2, v) << endl;

    return 0;
}
