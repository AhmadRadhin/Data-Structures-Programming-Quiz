// Q2_ReverseWord.cpp - Membalik kata dengan stack karakter (LIFO), tanpa STL
#include <iostream>
using namespace std;

const int MAX = 100;        // kapasitas stack karakter
char charStack[MAX];
int top = -1;

bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }

void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow! Kata terlalu panjang." << endl;
        return;
    }
    charStack[++top] = c;
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    return charStack[top--];
}

int main() {
    char word[MAX];
    cout << "Enter a word: ";
    cin >> word;                       // baca satu kata (spasi tidak ikut)

    // 1) Push setiap karakter dari kiri ke kanan
    for (int i = 0; word[i] != '\0'; i++) {
        push(word[i]);
    }

    // 2) Pop semua karakter -> otomatis urutannya terbalik (LIFO)
    char reversed[MAX];
    int n = 0;
    while (!isEmpty()) {
        reversed[n++] = pop();
    }
    reversed[n] = '\0';

    cout << "\nOriginal word: " << word << endl;
    cout << "Reversed word: " << reversed << endl;
    return 0;
}
