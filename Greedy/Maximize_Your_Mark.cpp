#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Question
{
    double ratio;
    int marks;
    int time;
    int index;
};

bool compareQuestions(const Question &a, const Question &b)
{
    return a.ratio > b.ratio;
}

vector<Question> max_marks(int N, int T, vector<int> &m, vector<int> &t)
{
    vector<Question> questions(N);
    for (int i = 0; i < N; ++i)
    {
        double ratio = static_cast<double>(m[i]) / t[i];
        questions[i] = {ratio, m[i], t[i], i + 1};
    }

    sort(questions.begin(), questions.end(), compareQuestions);

    vector<Question> answered_questions;
    for (Question &q : questions)
    {
        if (T >= q.time)
        {
            T -= q.time;
            answered_questions.push_back({100.0, q.marks, q.time, q.index});
        }
        else if (T > 0)
        {
            double percentage = static_cast<double>(T) * 100 / q.time;
            q.marks = static_cast<int>(q.marks * percentage / 100);
            q.time = T;
            T = 0;
            answered_questions.push_back({percentage, q.marks, q.time, q.index});
        }
    }

    return answered_questions;
}

vector<Question> max_marks_group(int N, int T, vector<int> &m, vector<int> &t)
{
    return max_marks(N, 2 * T, m, t);
}

int main()
{
    int M, T, N;
    cin >> M >> T >> N;
    vector<int> m(N), t(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> m[i] >> t[i];
    }

    vector<Question> solo = max_marks(N, T, m, t);
    vector<Question> group = max_marks_group(N, T, m, t);

    int solo_marks = 0, group_marks = 0;
    for (int i = 0; i < solo.size(); ++i)
    {
        solo_marks += solo[i].marks;
    }
    for (int i = 0; i < group.size(); ++i)
    {
        group_marks += group[i].marks;
    }

    cout << "Maximum " << solo_marks << " marks answering alone\n";
    for (int i = 0; i < solo.size(); ++i)
    {
        cout << "ques " << solo[i].index << " " << solo[i].ratio << "% done -- " << solo[i].marks << " marks\n";
    }

    cout << "Maximum " << group_marks << " marks answering with a friend\n";

    return 0;
}

// All ok