#ifndef HELLO_HPP
#define HELLO_HPP

#include <string>
using namespace std;

struct Task {
    string task;
    bool completed;
};

class TodoList {
private:
    static const int MAX_TASKS = 100;
    Task tasks[MAX_TASKS];
    int size;

public:
    TodoList();

    bool add(string task);
    bool completeTask(string desc);

    string all();
    string complete();
    string incomplete();

    void clear();
};

#endif