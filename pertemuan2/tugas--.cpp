#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head = NULL;

void push(int n) {

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

    cout << n << " masuk ke Stack." << endl;
}

void pop() {

    if (head == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }

    node *temp = head;

    cout << temp->value << " keluar dari Stack." << endl;

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

    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    pop();

    display();

    return 0;
}

