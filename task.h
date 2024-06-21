#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

// Struct untuk merepresentasikan sebuah tugas
struct Task {
    int id, priority;      // ID dan prioritas tugas
    string name;           // Nama tugas
    string description;    // Deskripsi tugas
    string date;           // Tanggal tugas
    Task* next;            // Pointer ke tugas berikutnya dalam linked list
};

// Deklarasi fungsi untuk membuat tugas baru
Task* createTask(int id, const string& name, const string& description, const string& date, int priority);

#endif // TASK_H