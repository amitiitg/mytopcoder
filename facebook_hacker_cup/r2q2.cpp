#include <iostream>
#include <vector>

using namespace std;

int number_ways_get_sum(int S, int N, int x1, int x2)
{
    int ways = 0;

    for (int i=1; i<=N-1; i++) 
        for (int j=i+1; j<=N; j++)
        {
            if(i==x1 || i==x2 || j==x1 || j==x2) continue;
            if (i+j == S) ways++;
        }

    cout << ways << endl;
    return ways;
}

int find_same_sum(int x1, int x2, int N)
{
    int ways = 0;
    for (int i=max(x1, x2)+1; i<=min(N, x1+x2-1); i++) {
        if (x1+x2 - i != min(x1, x2)) ways++;
    }

    return ways;
}

int ways_to_lose(int x1, int x2, int N)
{
    int lose_ways = 0;
    for (int i=x1+x2+1; i<2*N; i++) {
        lose_ways += number_ways_get_sum(i, N, x1, x2);
    }
    lose_ways += find_same_sum(x1, x2, N);
    
    return lose_ways;
}

int main()
{
    int N, H;
    int x1, x2;

    cin >> N >> H;
    for (int i=0; i<H; i++) {
        cin >> x1 >> x2;
        int lose_ways = ways_to_lose(x1, x2, N);
        float lose_pb = (lose_ways*2.0)/(N*(N-1) - 1.0);
        cout << lose_ways << " " << N << " " << lose_pb << endl;
        if(lose_pb*3 > 0.8) cout << 'F';
        else cout << 'B';
    }
    cout << endl;
}
