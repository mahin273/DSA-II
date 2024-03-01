#include <vector>
#include <algorithm>
#include <iostream>

struct Task
{
    std::string name;
    int payment;
    int duration;
    int deadline;
    double paymentPerHour;
};

bool compare(Task a, Task b)
{
    return a.paymentPerHour > b.paymentPerHour;
}

void maximize_payment(std::vector<Task> &tasks)
{
    // Calculate payment per hour for each task
    for (Task &task : tasks)
    {
        task.paymentPerHour = (double)task.payment / task.duration;
    }

    // Sort tasks by payment per hour in descending order
    std::sort(tasks.begin(), tasks.end(), compare);

    // Initialize schedule with empty tasks
    std::vector<std::string> schedule(10);

    int total_payment = 0;
    for (Task &task : tasks)
    {
        bool canSchedule = true;
        for (int i = task.deadline - 1; i >= task.deadline - task.duration; i--)
        {
            // Check if the task can be scheduled
            if (i < 0 || !schedule[i].empty())
            {
                canSchedule = false;
                break;
            }
        }

        if (canSchedule)
        {
            for (int i = task.deadline - 1; i >= task.deadline - task.duration; i--)
            {
                schedule[i] = task.name;
            }
            total_payment += task.payment;
        }
    }

    // Print tasks and total payment
    std::cout << "Tasks: ";
    for (const auto &task_name : schedule)
    {
        if (!task_name.empty())
        {
            std::cout << task_name << ",";
        }
    }
    std::cout << "\nTotal payment: " << total_payment << std::endl;
}
                        
int main()
{
    int n;
    std::cout << "Enter the number of tasks: ";
    std::cin >> n;

    std::vector<Task> tasks(n);

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter name, payment, duration and deadline for task " << i + 1 << ": ";
        std::cin >> tasks[i].name >> tasks[i].payment >> tasks[i].duration >> tasks[i].deadline;
    }

    maximize_payment(tasks);

    return 0;
}