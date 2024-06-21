#include <iostream>
#include <unordered_set>
#include <regex>
#include "linkedlist.h"
#include "hashtable.h"
#include "queue.h"
#include "task.h"

using namespace std;

// Fungsi untuk memvalidasi format tanggal
bool isValidDate(const string& date) {
    regex datePattern("^\\d{2}-\\d{2}-\\d{4}$");
    return regex_match(date, datePattern);
}

int main() {
    LinkedList list;              // Inisialisasi linked list
    HashTable table(10);          // Inisialisasi hash table dengan ukuran 10
    Queue queue(10);              // Inisialisasi queue dengan ukuran 10
    unordered_set<int> priorities; // Set untuk menyimpan prioritas tugas

    while (true) {
        // Menu utama
        cout << "Task Management System" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Edit Task" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. Display Tasks" << endl;
        cout << "5. Search Task" << endl;
        cout << "6. Dequeue Task" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            string invalid_input;
            cin >> invalid_input; // Membaca input yang tidak valid
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                // Menambahkan tugas baru
                int id;
                string name, description, date;
                int priority;

                cout << "Enter task ID: ";
                cin >> id;
                // Handling input yang tidak valid
                if (cin.fail()) {
                    cin.clear();
                    string invalid_input;
                    cin >> invalid_input;
                    cout << "Invalid ID. Please enter a valid number." << endl;
                    break;
                }
                // Cek apakah ID sudah ada
                if (table.searchTask(id) != nullptr) {
                    cout << "Task with ID " << id << " already exists." << endl;
                    break;
                }

                cout << "Enter task name: ";
                cin >> ws; // Mengabaikan spasi putih
                getline(cin, name);

                cout << "Enter task description: ";
                getline(cin, description);

                cout << "Enter task date (DD-MM-YYYY): ";
                getline(cin, date);
                // Handling format tanggal yang salah
                if (!isValidDate(date)) {
                    cout << "Invalid date format. Please use DD-MM-YYYY." << endl;
                    break;
                }

                cout << "Enter task priority: ";
                cin >> priority;
                // Handling input priority yang tidak valid
                if (cin.fail() || priority < 0) {
                    cin.clear();
                    string invalid_input;
                    cin >> invalid_input;
                    cout << "Invalid priority. Please enter a non-negative number." << endl;
                    break;
                }
                // Cek apakah prioritas sudah ada
                if (priorities.find(priority) != priorities.end()) {
                    cout << "Task with priority " << priority << " already exists." << endl;
                    break;
                }

                // Menambahkan task baru
                priorities.insert(priority);
                Task* task = createTask(id, name, description, date, priority);
                list.addTask(task);
                table.insertTask(task);
                queue.enqueue(task);
                cout << "Task added successfully." << endl;
                break;
            }
            case 2: {
                // Mengedit tugas yang ada
                int id;
                string name, description, date;
                int priority;

                cout << "Enter task ID: ";
                cin >> id;
                if (cin.fail()) {
                    cin.clear();
                    string invalid_input;
                    cin >> invalid_input;
                    cout << "Invalid ID. Please enter a valid number." << endl;
                    break;
                }

                // Mencari task berdasarkan ID
                Task* task = table.searchTask(id);
                if (task == nullptr) {
                    cout << "Task with ID " << id << " not found." << endl;
                    break;
                }

                // Memasukkan informasi baru
                cout << "Enter new task name: ";
                cin >> ws; // Mengabaikan spasi putih
                getline(cin, name);

                cout << "Enter new task description: ";
                getline(cin, description);

                cout << "Enter new task date (DD-MM-YYYY): ";
                getline(cin, date);
                if (!isValidDate(date)) {
                    cout << "Invalid date format. Please use DD-MM-YYYY." << endl;
                    break;
                }

                cout << "Enter new task priority: ";
                cin >> priority;
                if (cin.fail() || priority < 0) {
                    cin.clear();
                    string invalid_input;
                    cin >> invalid_input;
                    cout << "Invalid priority. Please enter a non-negative number." << endl;
                    break;
                }

                // Update tugas dalam linked list dan hash table
                list.editTask(id, name, description, date, priority);
                task->name = name;
                task->description = description;
                task->date = date;
                task->priority = priority;

                cout << "Task edited successfully." << endl;
                break;
            }
            case 3: {
                // Menghapus tugas berdasarkan ID
                int id;
                cout << "Enter task ID to remove: ";
                cin >> id;
                if (cin.fail()) {
                    cin.clear();
                    string invalid_input;
                    cin >> invalid_input;
                    cout << "Invalid ID. Please enter a valid number." << endl;
                    break;
                }

                // Mencari task berdasarkan ID
                Task* task = table.searchTask(id);
                if (task == nullptr) {
                    cout << "Task with ID " << id << " not found." << endl;
                    break;
                }

                // Menghapus task dari set, linked list, dan hash table
                priorities.erase(task->priority);
                list.removeTask(id);
                table.removeTask(id);
                cout << "Task removed successfully." << endl;
                break;
            }
            case 4: {
                // Menampilkan semua tugas
                cout << "Displaying all tasks:" << endl;
                list.displayTasks();
                break;
            }
            case 5: {
                // Mencari tugas berdasarkan ID
                int id;
                cout << "Enter task ID to search: ";
                cin >> id;
                if (cin.fail()) {
                    cin.clear();
                    string invalid_input;
                    cin >> invalid_input;
                    cout << "Invalid ID. Please enter a valid number." << endl;
                    break;
                }

                // Mencari task berdasarkan ID
                Task* task = table.searchTask(id);
                if (task == nullptr) {
                    cout << "Task with ID " << id << " not found." << endl;
                } else {
                    // Menampilkan informasi task
                    cout << "Task found: " << endl;
                    cout << "ID: " << task->id << ", Name: " << task->name << ", Description: " << task->description
                         << ", Date: " << task->date << ", Priority: " << task->priority << endl;
                }
                break;
            }
            case 6: {
                // Menghapus tugas dari antrian
                Task* task = queue.dequeue();
                if (task != nullptr) {
                    priorities.erase(task->priority);
                    list.removeTask(task->id);
                    table.removeTask(task->id);
                    delete task;
                }
                break;
            }
            case 7: {
                // Keluar dari program
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                // Handling pilihan yang tidak valid
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                break;
            }
        }
    }

    return 0;
}