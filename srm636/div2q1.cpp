#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class GameOfStones {
    public:
        int count(const vector<int>& stones);
};

int GameOfStones::count(const vector<int>& stones)
{
    int size = stones.size();
    int sum = 0;

    for(int i=0; i<size; i++)
    {
        sum += stones[i];
    }

    if (sum % size) return -1;
    bool doable = true;
    int f = sum/size;

    for(int i=0; i<size; i++) {
        if (abs(stones[i] - f) % 2) doable = false;
    }

    int moves = 0;
    if(doable) {
        for(int i=0; i<size; i++) 
            moves += (abs(stones[i]-f)/2);
    } else {
        return -1;
    }

    return moves/2;
}

int main()
{
    int tmp[] = {92, 100, 90, 100, 58, 100, 96, 100, 82, 82, 94, 90, 82, 94, 56, 92, 28, 96, 98, 96, 98, 88, 100, 88, 68, 100, 82, 100, 92, 84, 72, 96, 88, 74, 62, 94, 48, 94, 94, 94, 60, 88, 94, 96, 70, 100, 70, 42, 74, 84, 100, 100, 90, 56, 88, 96, 92, 54, 82, 92, 86, 96, 72, 82, 98, 92, 44, 96, 86, 92, 96, 100, 94, 98, 72, 100, 70, 100, 90, 78, 64, 74, 86, 60, 96, 96, 84, 70, 100, 78, 94, 48, 58, 78, 80, 80, 74, 82, 90, 96};
    vector<int> foo(tmp, tmp + sizeof(tmp)/sizeof(int));

    GameOfStones gs;
    cout << gs.count(foo) << endl;
    return 0;
}
