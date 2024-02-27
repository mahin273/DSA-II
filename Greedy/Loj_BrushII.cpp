#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dust
{
    int x, y;
};

bool compareDusts(Dust a, Dust b)
{
    return a.y < b.y;
}

int main()
{
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        int N, w;
        cin >> ws; // Consume the blank line
        cin >> N >> w;

        vector<Dust> dusts(N);
        for (int i = 0; i < N; i++)
        {
            cin >> dusts[i].x >> dusts[i].y;
        }

        sort(dusts.begin(), dusts.end(), compareDusts);

        int moves = 0;
        int brushStart = dusts[0].y;
        int brushEnd = brushStart + w;

        for (int i = 1; i < N; i++)
        {
            if (dusts[i].y > brushEnd)
            {
                moves++;
                brushStart = dusts[i].y;
                brushEnd = brushStart + w;
            }
            else
            {
                brushEnd = max(brushEnd, dusts[i].y + w);
            }
        }

        moves++; // Last move to cover remaining dust points

        cout << "Case " << caseNum << ": " << moves << endl;
    }

    return 0;
}