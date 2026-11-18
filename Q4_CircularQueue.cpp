// Q4_CircularQueue.cpp - Circular Queue berbasis array (kapasitas 5), tanpa STL
#include <iostream>
using namespace std;

const int MAX = 5;
int cq[MAX];
int frontIdx = 0;   // indeks elemen terdepan
int rear = -1;      // indeks elemen paling belakang
int count = 0;      // jumlah elemen -> membedakan Full vs Empty dengan jelas

bool isEmpty() { return count == 0; }
bool isFull()  { return count == MAX; }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Queue penuh, " << value << " tidak dapat dimasukkan." << endl;
        return;
    }
    rear = (rear + 1) % MAX;     // wrap-around dengan modulo
    cq[rear] = value;
    count++;
    cout << value << " inserted successfully." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong." << endl;
        return;
    }
    cout << cq[frontIdx] << " removed successfully." << endl;
    frontIdx = (frontIdx + 1) % MAX;   // geser front TANPA menggeser elemen array
    count--;
}

void front() {
    if (isEmpty()) {
        cout << "Queue kosong, tidak ada front element." << endl;
        return;
    }
    cout << "Front element: " << cq[frontIdx] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue: (kosong)" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = 0; i < count; i++) {
        cout << cq[(frontIdx + i) % MAX] << " ";
    }
    cout << endl;
}

bool readInt(int &x) {
    cin >> x;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

int main() {
    int choice, value;

    // Panduan tes wajib (dijalankan manual oleh user lewat menu)
    cout << "Test sequence: Enqueue 10,20,30,40,50 -> Dequeue 2x -> Enqueue 60,70 -> Display" << endl;
    cout << "Expected: Queue: 30 40 50 60 70" << endl;

    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
        cout << "Choose operation: ";
        if (!readInt(choice)) { cout << "Input tidak valid!" << endl; choice = 0; continue; }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                if (readInt(value)) enqueue(value);
                else cout << "Input tidak valid!" << endl;
                break;
            case 2: dequeue(); break;
            case 3: front();   break;
            case 4: display(); break;
            case 5: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid (1-5)." << endl;
        }
    } while (choice != 5);
    return 0;
}