#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Event
{
    char id;
    int start;
    int end;
};

// Comparison function
bool compareEvents(const Event &a, const Event &b)
{
    return a.end < b.end;
}

vector<char> max_events(int N, int X, vector<Event> &events)
{
    sort(events.begin(), events.end(), compareEvents);

    vector<char> chosen_events;
    int last_end = -1;
    for (Event &e : events)
    {
        if (e.start >= last_end + X)
        {
            chosen_events.push_back(e.id);
            last_end = e.end;
        }
    }

    return chosen_events;
}

int main()
{
    int N, X;
    cin >> N;
    vector<Event> events(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> events[i].id >> events[i].start >> events[i].end;
        events[i].end += events[i].start;
    }
    cin >> X;

    vector<char> chosen_events = max_events(N, X, events);

    cout << "Chosen clubs: \n";
    for (int i = 0; i < chosen_events.size(); ++i)
    {
        cout << chosen_events[i] << "\n";
    }

    return 0;
}