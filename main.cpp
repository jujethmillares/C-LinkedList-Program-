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

void insertFirstItem(node *&head, node *&last, int number) {
    node *temp = new node ;
    temp->number = number;
    temp->next = NULL;
    head = temp;
    last = temp;
}

void insert_Item(node *head, node *last, int number) {

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