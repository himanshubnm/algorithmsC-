#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node * insertStart(struct node *head, int data){    
    struct node *newnode = new struct node;
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL){
        return newnode;
    }

    newnode->next = head->next;
    head->next = newnode;
    return head;
}

struct node * insertLast(struct node *head, int data){
    struct node *newnode = new struct node;
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        return newnode;
    }

    struct node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    return head;
}

struct node * insertLocation(struct node *head, int data, int idx){
    
    struct node *newnode = new struct node;
    newnode->data = data;
    newnode->next = NULL;
    int count = 1;
    
    if (head == NULL){
        return newnode;
    }

    struct node *temp = head;

    while(count < idx-1){
        count++;
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node * deleteFirst(struct node *head){
    if (head == NULL){
        throw::invalid_argument("Empty LIST\n");
    }
    head = head->next;
    return head;
}

struct node * deleteLast(struct node *head){
    struct node *newnode = head;
    while(newnode->next->next != NULL){
        newnode = newnode->next;
    } newnode->next = NULL;
    return head;
}

struct node * deleteLocation(struct node *head, int idx){
    struct node *newnode = head;
    int count = 1;
    while(count < idx - 1){
        count++;
        newnode = newnode->next;
    }

    newnode->next = newnode->next->next;
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
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
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
