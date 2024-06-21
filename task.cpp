#include "task.h"
using namespace std;

// Implementasi fungsi untuk membuat tugas baru
Task* createTask(int id, const string& name, const string& description, const string& date, int priority) {
    Task* task = new Task;             // Alokasi memori untuk tugas baru
    task->id = id;                     // Set ID tugas
    task->name = name;                 // Set nama tugas
    task->description = description;   // Set deskripsi tugas
    task->date = date;                 // Set tanggal tugas
    task->priority = priority;         // Set prioritas tugas
    task->next = nullptr;              // Inisialisasi pointer next ke nullptr
    return task;                       // Kembalikan pointer ke tugas yang baru dibuat
}