#include <bits/stdc++.h>
using namespace std;

vector<int> readDustPoints(int N)
{
    vector<int> dusts(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        dusts[i] = y;
    }
    return dusts;
}

int calculateMoves(vector<int> &dusts, int w)
{
    sort(dusts.begin(), dusts.end());
    int moves = 1, current = dusts[0];
    for (int i = 1; i < dusts.size(); i++)
    {
        if (dusts[i] > current + w)
        {
            moves++;
            current = dusts[i];
        }
    }
    return moves;
}

void printResult(int caseNumber, int moves)
{
    cout << "Case " << caseNumber << ": " << moves << "\n";
}

int main()
{

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, w;
        cin >> N >> w;
        vector<int> dusts = readDustPoints(N);
        int moves = calculateMoves(dusts, w);
        printResult(t, moves);
    }
    return 0;
}
