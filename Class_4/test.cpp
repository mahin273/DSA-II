#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Question {
    int marks;
    int time;
    int index;
    double ratio;
};

bool compare(Question a, Question b) {
    return a.ratio > b.ratio;
}

void printMaxMarks(vector<Question> questions, int T, string scenario, bool printBreakdown) {
    double totalMarks = 0;
    stringstream breakdown;
    for (int i = 0; i < questions.size(); i++) {
        if (T == 0)
            break;
        if (questions[i].time <= T) {
            T -= questions[i].time;
            totalMarks += questions[i].marks;
            if (printBreakdown) {
                breakdown << "ques " << questions[i].index << " 100% done -- " << questions[i].marks << " marks\n";
            }
        } else {
            double fraction = (double)T / questions[i].time;
            totalMarks += questions[i].marks * fraction;
            if (printBreakdown) {
                breakdown << "ques " << questions[i].index << " " << fraction*100 << "% done -- " << questions[i].marks * fraction << " marks\n";
            }
            T = 0;
        }
    }
    cout << "Maximum " << totalMarks << " marks " << scenario << "\n";
    if (printBreakdown) {
        cout << breakdown.str();
    }
}

int main() {
    int M, T, N;
    cin >> M >> T >> N;
    vector<Question> questions(N);
    for (int i = 0; i < N; i++) {
        cin >> questions[i].marks >> questions[i].time;
        questions[i].index = i + 1;
        questions[i].ratio = (double)questions[i].marks / questions[i].time;
    }
    sort(questions.begin(), questions.end(), compare);

    printMaxMarks(questions, T, "answering alone", true);
    printMaxMarks(questions, 2*T, "answering with a friend", false);

    return 0;
}