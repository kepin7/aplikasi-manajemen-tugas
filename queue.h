#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

// Kelas untuk merepresentasikan antrian tugas
class Queue {
private:
    Task** tasks;   // Array pointer ke tugas
    int size;       // Ukuran maksimum antrian
    int front;      // Indeks depan antrian
    int rear;       // Indeks belakang antrian
public:
    Queue(int size);   // Konstruktor
    ~Queue();          // Destruktor
    bool isFull();     // Periksa apakah antrian penuh
    bool isEmpty();    // Periksa apakah antrian kosong
    void enqueue(Task* task);   // Tambahkan tugas ke antrian
    Task* dequeue();            // Hapus tugas dari antrian
};

#endif // QUEUE_H