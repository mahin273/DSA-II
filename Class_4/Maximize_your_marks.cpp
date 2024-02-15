#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Question
{
    int id;
    double marks;
    double time;
    double ratio;
};

bool compare(Question a, Question b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int N;
    double T;
    cin >> N >> T;
    vector<Question> questions(N);
    for (int i = 0; i < N; i++)
    {
        questions[i].id = i + 1;
        cin >> questions[i].marks >> questions[i].time;
        questions[i].ratio = questions[i].marks / questions[i].time;
    }

    sort(questions.begin(), questions.end(), compare);

    double totalMarks = 0;
    vector<int> answeredQuestions;
    for (int i = 0; i < N && T > 0; i++)
    {
        if (questions[i].time <= T)
        {
            T -= questions[i].time;
            totalMarks += questions[i].marks;
            answeredQuestions.push_back(questions[i].id);
        }
        else
        {
            double fraction = T / questions[i].time;
            totalMarks += questions[i].marks * fraction;
            answeredQuestions.push_back(questions[i].id);
            T = 0;
        }
    }

    cout << "marks " << totalMarks << endl;
    cout << "Questions you have to answer: ";
    for (int id : answeredQuestions)
    {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}