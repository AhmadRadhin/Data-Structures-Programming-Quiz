// Q1_Stack.cpp - Stack berbasis array (kapasitas tetap 5), tanpa STL
#include <iostream>
using namespace std;

const int MAX = 5;      // kapasitas maksimum stack
int stackArr[MAX];      // array penyimpan elemen
int top = -1;           // -1 artinya stack kosong

bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }

// Menambah elemen di puncak stack
void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Stack penuh, " << value << " tidak dapat dimasukkan." << endl;
        return;
    }
    stackArr[++top] = value;   // naikkan top, lalu simpan
    cout << value << " inserted successfully." << endl;
}

// Menghapus elemen di puncak stack
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack kosong." << endl;
        return;
    }
    cout << stackArr[top--] << " removed successfully." << endl;
}

// Melihat elemen puncak tanpa menghapus
void peek() {
    if (isEmpty()) {
        cout << "Stack kosong, tidak ada top element." << endl;
        return;
    }
    cout << "Top element: " << stackArr[top] << endl;
}

// Menampilkan isi stack dari puncak ke dasar
void display() {
    if (isEmpty()) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "Stack (top -> bottom): ";
    for (int i = top; i >= 0; i--) cout << stackArr[i] << " ";
    cout << endl;
}

// Membaca integer dengan validasi input
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
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push  2. Pop  3. Peek" << endl;
        cout << "4. Display  5. Exit" << endl;
        cout << "\nChoose operation: ";
        if (!readInt(choice)) { cout << "Input tidak valid!" << endl; choice = 0; continue; }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                if (readInt(value)) push(value);
                else cout << "Input tidak valid!" << endl;
                break;
            case 2: pop();     break;
            case 3: peek();    break;
            case 4: display(); break;
            case 5: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid (1-5)." << endl;
        }
    } while (choice != 5);
    return 0;
}
