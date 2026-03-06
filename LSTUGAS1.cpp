#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertFirst(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertLast(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertNext(int key, int data) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp != NULL) {
        Node* newNode = new Node();
        newNode->data = data;

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }
}

void deleteFirst() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

void deleteLast() {
    if (head == NULL) return;

    Node* temp = head;

    if (temp->next == NULL) {
        head = NULL;
        delete temp;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void deleteNode(int key) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp == head) {
        deleteFirst();
        return;
    }

    if (temp->next == NULL) {
        deleteLast();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    insertFirst(10);
    insertFirst(5);
    insertLast(20);
    insertLast(30);

    cout << "Setelah Insert:" << endl;
    display();

    insertNext(20, 25);
    cout << "Setelah insertNext:" << endl;
    display();

    deleteFirst();
    cout << "Setelah deleteFirst:" << endl;
    display();

    deleteLast();
    cout << "Setelah deleteLast:" << endl;
    display();

    deleteNode(20);
    cout << "Setelah deleteNode 20:" << endl;
    display();

    return 0;
}