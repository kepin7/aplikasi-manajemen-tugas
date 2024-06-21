#include <iostream>
#include "queue.h"
using namespace std;

// Konstruktor untuk inisialisasi antrian
Queue::Queue(int size) {
    this->size = size;           // Set ukuran antrian
    front = -1;                  // Inisialisasi front
    rear = -1;                   // Inisialisasi rear
    tasks = new Task*[size];     // Alokasi memori untuk array pointer tugas
}

// Destruktor untuk membersihkan memori
Queue::~Queue() {
    delete[] tasks;   // Hapus array pointer tugas
}

// Fungsi untuk memeriksa apakah antrian penuh
bool Queue::isFull() {
    return (rear + 1) % size == front;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool Queue::isEmpty() {
    return front == -1;
}

// Fungsi untuk menambahkan tugas ke antrian
void Queue::enqueue(Task* task) {
    if (isFull()) {
        cout << "Failed to enqueue task: Queue is full." << endl;
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % size;
    tasks[rear] = task;
}

// Fungsi untuk menghapus tugas dari antrian
Task* Queue::dequeue() {
    if (isEmpty()) {
        cout << "Failed to dequeue task: Queue is empty." << endl;
        return nullptr;
    }
    Task* task = tasks[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }
    cout << "Task dequeued successfully." << endl;
    return task;
}