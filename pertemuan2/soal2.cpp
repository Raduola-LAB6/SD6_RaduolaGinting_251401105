//soal 2 queue
#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertLast(int n) {

    node *newNode = new node;

    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteFirst() {

    if (head == NULL) {
        cout << "Queue kosong!" << endl;
        return;
    }

    node *temp = head;

    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    delete temp;
}

void display() {

    node *temp = head;

    cout << "Queue: ";

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    insertLast(10);
    insertLast(20);
    insertLast(30);

    display();

    deleteFirst();

    display();

    return 0;
}