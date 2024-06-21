#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "task.h"
using namespace std;

class LinkedList {
private:
    Task* head;   // Pointer ke tugas pertama dalam linked list
public:
    LinkedList();   // Konstruktor
    ~LinkedList();  // Destruktor
    void addTask(Task* task);   // Menambahkan tugas ke linked list
    void removeTask(int id);    // Menghapus tugas dari linked list berdasarkan ID
    void editTask(int id, string name, string description, string date, int priority); // Mengedit tugas dalam linked list
    void displayTasks();   // Menampilkan semua tugas dalam linked list
};

#endif // LINKEDLIST_H