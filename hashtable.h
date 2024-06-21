#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"

class HashTable {
private:
    Task** table;   // Array pointer ke tugas
    int size;       // Ukuran hash table
    int hashFunction(int id);   // Fungsi hash untuk menghitung indeks berdasarkan ID
public:
    HashTable(int size);   // Konstruktor
    ~HashTable();          // Destruktor
    void insertTask(Task* task);   // Menambahkan tugas ke hash table
    void removeTask(int id);       // Menghapus tugas dari hash table berdasarkan ID
    Task* searchTask(int id);      // Mencari tugas dalam hash table berdasarkan ID
};

#endif // HASHTABLE_H