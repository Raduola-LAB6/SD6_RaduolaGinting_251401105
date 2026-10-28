//soal 1 stack
#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head = NULL;


void insertFirst(int n) {

    node *newNode = new node;

    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void deleteFirst() {

    if (head == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }

    node *temp = head;

    head = head->next;

    delete temp;
}

void display() {

    node *temp = head;

    cout << "Stack: ";

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    insertFirst(10);
    insertFirst(20);
    insertFirst(30);

    display();

    deleteFirst();

    display();

    return 0;
}