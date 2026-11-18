// Q3_Queue.cpp - Linear Queue berbasis array (kapasitas 5), tanpa STL
#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = 0;     // indeks elemen terdepan
int rear = -1;        // indeks elemen paling belakang (-1 = kosong)

bool isEmpty() { return frontIdx > rear; }
bool isFull()  { return rear == MAX - 1; }

// Sisipkan di belakang (rear)
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Queue penuh, " << value << " tidak dapat dimasukkan." << endl;
        return;
    }
    queueArr[++rear] = value;
    cout << value << " inserted successfully." << endl;
}

// Hapus dari depan (front)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong." << endl;
        return;
    }
    cout << queueArr[frontIdx++] << " removed successfully." << endl;
    if (isEmpty()) {          // reset posisi agar ruang array bisa dipakai lagi
        frontIdx = 0;
        rear = -1;
    }
}

void front() {
    if (isEmpty()) {
        cout << "Queue kosong, tidak ada front element." << endl;
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue: (kosong)" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = frontIdx; i <= rear; i++) cout << queueArr[i] << " ";
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
    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
        cout << endl;
        display();
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
