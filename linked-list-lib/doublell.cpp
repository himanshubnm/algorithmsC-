#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* insertStart(struct node *head, int data){
    struct node *newnode = new struct node;
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL){
        newnode->prev = NULL;
        return newnode;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    newnode->prev = NULL;
    
    return head;
}

struct node* insertLast(struct node *head, int data){
    struct node* newnode = new struct node;
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL){
        newnode->prev = NULL;
        return newnode;
    }

    struct node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct node* insertLocation(struct node *head, int data, int idx){
    struct node * newnode = new struct node; 
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL){
        newnode->prev = NULL;
        return newnode;
    }

    int count = 0;
    struct node *temp = head;
    while(count < idx - 2){
        temp = temp->next;
        count++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next->prev = newnode;
    return head;
}

struct node* deleteFirst(struct node *head){
    if (head == NULL){
        throw::invalid_argument("Linked List Empty");
    }
    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

struct node* deleteLast(struct node* head){
    if (head == NULL){
        throw::invalid_argument("Linked List Empty");
    }

    struct node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    struct node* temp2 = temp->next;
    delete temp2;
    temp->next = NULL;
    return head;
} 

struct node* deleteLocation(struct node* head, int idx){
    if (head == NULL){
        throw::invalid_argument("Linked List Empty");
    }

    int count = 0;
    struct node * temp = head;
    while(count < idx - 1){
        temp = temp->next;
        count++;
    }

    struct node* pr = temp->prev;
    pr->next = temp->next;
    temp->next->prev = pr;
    delete temp;
    return head;
}

int main(int argc, char const *argv[])
{
    struct node *head = NULL;

    head = insertStart(head, 5);
    head = insertStart(head, 4);
    head = insertStart(head, 3);
    head = insertStart(head, 2);
    head = insertStart(head, 1);
    head = insertLast(head, 0);
    head = insertLast(head, -1);
    head = insertLast(head, -2);
    head = insertLast(head, -3);    
    head = insertLocation(head, 99, 5);
    
    struct node *temp = head;
    while(temp!=  NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        if (temp->next == NULL){
            cout << temp->data << " ";
            break;
        }
    } cout << endl;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    } cout << endl;

    head = deleteFirst(head);
    
    temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;

    head = deleteLast(head);
    temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;

    head = deleteLocation(head, 4);
    temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;

    return 0;
}