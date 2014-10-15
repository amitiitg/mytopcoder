#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortishDiv2 {
    public:
    int ways(int sortedness, vector<int> seq);
};

int find_sortedness(vector<int> seq)
{
    int sortedness = 0;
    for (int i=0; i<seq.size(); i++) 
        for (int j=i+1; j<seq.size(); j++)
            if(seq[i]<seq[j]) sortedness++;

    return sortedness;
}

int SortishDiv2::ways(int sortedness, vector<int> seq)
{
    int A = seq.size();
    vector<int> perm, sorted_seq(seq);
    vector<int> missing(A);
    vector<int>::iterator it;

    for(int i=1; i<=A; i++) perm.push_back(i);
    sort(sorted_seq.begin(), sorted_seq.end());

    it = std::set_difference(perm.begin(), perm.end(), sorted_seq.begin(), sorted_seq.end(), missing.begin());
    missing.resize(it-missing.begin());
    sort(missing.begin(), missing.end());

    int ways = 0;
    do {
        int j = 0;
        vector<int> possible(seq);
        for (int i=0; i<seq.size(); i++) {
            if (seq[i] == 0) possible[i] = missing[j++];
        }
        if ( find_sortedness(possible) == sortedness) ways++;
    } while (next_permutation(missing.begin(), missing.end()));

    return ways;
}

int main()
{
    int tmp[] = {1, 2, 0, 5, 0, 0};
    vector<int> foo(tmp, tmp + sizeof(tmp)/sizeof(int));

    SortishDiv2 ques;
    cout << ques.ways(2, foo) << endl;
    return 0;
}

