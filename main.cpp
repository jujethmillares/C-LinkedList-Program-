#include<iostream>
using namespace std;

struct node {
    int number;
    node *next;
};

bool is_Empty(node *head) {
    if(head == NULL)
        return true;
    else
        return false;
}

char menu() {

}

void insert_FirstItem(node *&head, node *&last, int number) {
    node *temp = new node ;
    temp->number = number;
    temp->next = NULL;
    head = temp;
    last = temp;
}

void insert_Item(node *head, node *last, int number) {
    if(is_Empty(head))
        insert_FirstItem(head, last, number);
    else {
        node *temp = new node ;
        temp->number = number;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void delete_Item(node *head, node *last) {

}

void display_List(node *current) {

}


int main() {
    node *head = NULL;
    node *last = NULL;
    
    return 0;
}