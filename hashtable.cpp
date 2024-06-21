#include "hashtable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int size) {
    this->size = size;           // Set ukuran hash table
    table = new Task*[size];     // Alokasi memori untuk array pointer tugas
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;      // Inisialisasi semua elemen ke nullptr
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < size; ++i) {
        Task* current = table[i];
        while (current != nullptr) {
            Task* next = current->next;
            delete current;      // Hapus tugas dalam linked list di setiap bucket
            current = next;
        }
    }
    delete[] table;   // Hapus array pointer tugas
}

int HashTable::hashFunction(int id) {
    return id % size;   // Fungsi hash sederhana menggunakan operasi modulus
}

void HashTable::insertTask(Task* task) {
    int index = hashFunction(task->id);   // Hitung indeks menggunakan fungsi hash
    if (table[index] == nullptr) {
        table[index] = task;   // Jika bucket kosong, masukkan tugas ke bucket
    } else {
        Task* current = table[index];
        while (current->next != nullptr) {
            current = current->next;   // Cari elemen terakhir dalam linked list di bucket
        }
        current->next = task;   // Tambahkan tugas baru di akhir linked list
    }
}

void HashTable::removeTask(int id) {
    int index = hashFunction(id);   // Hitung indeks menggunakan fungsi hash
    Task* current = table[index];
    Task* prev = nullptr;
    while (current != nullptr) {
        if (current->id == id) {
            if (prev == nullptr) {
                table[index] = current->next;   // Jika tugas berada di awal linked list, update head
            } else {
                prev->next = current->next;   // Lewati tugas yang dihapus
            }
            delete current;   // Hapus tugas yang dihapus
            return;
        }
        prev = current;
        current = current->next;   // Lanjutkan ke tugas berikutnya
    }
}

Task* HashTable::searchTask(int id) {
    int index = hashFunction(id);   // Hitung indeks menggunakan fungsi hash
    Task* current = table[index];
    while (current != nullptr) {
        if (current->id == id) {
            return current;   // Jika ditemukan, kembalikan pointer ke tugas
        }
        current = current->next;   // Lanjutkan ke tugas berikutnya
    }
    return nullptr;   // Jika tidak ditemukan, kembalikan nullptr
}