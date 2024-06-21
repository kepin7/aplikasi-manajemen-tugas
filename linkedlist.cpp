#include <iostream>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;   // Inisialisasi head ke nullptr
}

LinkedList::~LinkedList() {
    Task* current = head;
    while (current != nullptr) {
        Task* next = current->next;   // Simpan pointer ke tugas berikutnya
        delete current;               // Hapus tugas saat ini
        current = next;               // Lanjutkan ke tugas berikutnya
    }
}

void LinkedList::addTask(Task* task) {
    if (head == nullptr) {
        head = task;   // Jika linked list kosong, set head ke tugas baru
    } else {
        Task* current = head;
        while (current->next != nullptr) {
            current = current->next;   // Cari tugas terakhir dalam linked list
        }
        current->next = task;   // Tambahkan tugas baru di akhir linked list
    }
}

void LinkedList::removeTask(int id) {
    if (head == nullptr) {
        return;   // Jika linked list kosong, tidak ada yang dihapus
    }
    if (head->id == id) {
        Task* temp = head;   // Simpan head yang lama
        head = head->next;   // Set head ke tugas berikutnya
        delete temp;         // Hapus head yang lama
        return;
    }
    Task* current = head;
    while (current->next != nullptr) {
        if (current->next->id == id) {
            Task* temp = current->next;   // Simpan tugas yang akan dihapus
            current->next = current->next->next;   // Lewati tugas yang dihapus
            delete temp;   // Hapus tugas yang dihapus
            return;
        }
        current = current->next;   // Lanjutkan ke tugas berikutnya
    }
}

void LinkedList::editTask(int id, string name, string description, string date, int priority) {
    Task* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            current->name = name;                   // Perbarui nama tugas
            current->description = description;     // Perbarui deskripsi tugas
            current->date = date;                   // Perbarui tanggal tugas
            current->priority = priority;           // Perbarui prioritas tugas
            return;
        }
        current = current->next;  // Lanjutkan ke tugas berikutnya
    }
}

void LinkedList::displayTasks() {
    Task* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->id << ", Name: " << current->name << ", Description: " << current->description
             << ", Date: " << current->date << ", Priority: " << current->priority << endl;
        current = current->next;  // Lanjutkan ke tugas berikutnya
    }
}