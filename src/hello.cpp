#include "hello.hpp"

// constructor
TodoList::TodoList() {
   size = 0;
}

// add task
bool TodoList::add(string task) {
   if (task == "" || size >= 100) {
      return false;
   }

   tasks[size].task = task;
   tasks[size].completed = false;
   size++;

   return true;
}

// mark complete
bool TodoList::completeTask(string desc) {
   for (int i = 0; i < size; i++) {
      if (tasks[i].task == desc) {
         tasks[i].completed = true;
         return true;
      }
   }
   return false;
}

// show all
string TodoList::all() {
   if (size == 0) {
      return "List is empty\n";
   }

   string result = "";
   for (int i = 0; i < size; i++) {
      result += tasks[i].task;
      if (tasks[i].completed) {
         result += " (CHECK)";
      }
      result += "\n";
   }
   return result;
}

// show completed
string TodoList::complete() {
   string result = "";

   for (int i = 0; i < size; i++) {
      if (tasks[i].completed) {
         result += tasks[i].task + "\n";
      }
   }

   if (result == "") {
      return "No completed tasks\n";
   }

   return result;
}

// show incomplete
string TodoList::incomplete() {
   string result = "";

   for (int i = 0; i < size; i++) {
      if (!tasks[i].completed) {
         result += tasks[i].task + "\n";
      }
   }

   if (result == "") {
      return "No incomplete tasks\n";
   }

   return result;
}

// clear list
void TodoList::clear() {
   size = 0;
}