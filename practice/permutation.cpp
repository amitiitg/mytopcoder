#include <iostream>
#include <vector>

using namespace std;

class Permutation {
    public:
        static void print_permutations(int idx, int N,int in[]); 
};

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Permutation::print_permutations(int idx, int N, int in[])
{
    if (idx == N) {
        for (int i=0; i<idx; i++) cout << in[i] << " "; cout << endl;
    }

    for (int i=idx; i<N; i++) {
        swap(&in[i], &in[idx]);
        print_permutations(idx+1, N, in);
        swap(&in[i], &in[idx]);
    } 
}

int main()
{
    int tmp[] = {1,2,3,4};
    vector<int> a(tmp, tmp + sizeof(tmp)/sizeof(int));
    Permutation p;
    p.print_permutations(0, sizeof(tmp)/sizeof(tmp[0]), tmp);
}

