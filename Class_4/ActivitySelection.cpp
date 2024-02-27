#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct to hold the club information
struct Club {
    string id;
    int start;
    int duration;
};

// Comparator function to sort clubs by end time
bool compare(Club a, Club b) {
    return a.start + a.duration < b.start + b.duration;
}

int main() {
    int N, start, duration, X;
    string id;
    vector<Club> clubs;

    // Get the number of clubs
    cout << "Enter the number of clubs: ";
    cin >> N;

    // Get the club details
    for (int i = 0; i < N; i++) {
        cout << "Enter the club id, start time, and duration for club " << i+1 << ": ";
        cin >> id >> start >> duration;
        clubs.push_back({id, start, duration});
    }

    // Get the cleanup time
    cout << "Enter the cleanup time: ";
    cin >> X;

    // Sort the clubs by end time
    sort(clubs.begin(), clubs.end(), compare);

    vector<string> chosen_clubs;
    int current_time = 0;

    // Select the clubs
    for (Club club : clubs) {
        if (club.start >= current_time) {
            chosen_clubs.push_back(club.id);
            current_time = club.start + club.duration + X;
        }
    }

    // Print the chosen clubs
    cout << "Chosen clubs:\n";
    for (string club : chosen_clubs) {
        cout << club << "\n";
    }

    return 0;
}