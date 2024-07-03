#include<iostream>
using namespace std;

struct node {
    int number;
    node *next;
};

bool is_Empty(node *head) {
    return (head == NULL);
}

char menu() {
    char choice;

    cout << "********* MENU OPTIONS ********* \n";
    cout << "---------1. Add an item.---------\n";
    cout << "---------2. Delete an item.------\n";
    cout << "-------- 3. Display list.--------\n";
    cout << "---------4. Exit.----------------\n";

    cout << "\nPlease enter your choice: ";
    cin >> choice;

    return choice;
}

void insert_FirstItem(node *&head, node *&last, int number) {
    node *temp = new node ;
    temp->number = number;
    temp->next = NULL;
    head = temp;
    last = temp;
}

void insert_Item(node *&head, node *&last, int number) {
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

void delete_Item(node *&head, node *&last) {
    if(is_Empty(head)) {
        cout << "The list is already empty.\n";
        return;
    }

    int number;
    cout << "\nEnter the number to delete: ";
    cin >> number;

    node *current = head;
    node *prev = nullptr;

    while (current != nullptr && current->number != number) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Number not found in the list.\n";
        cout << endl;
        return;
    }

    if (current == head && current == last) {
        delete current;
        head = nullptr;
        last = nullptr;
    } else if (current == head) {
        head = head->next;
        delete current;
    } else {
        prev->next = current->next;
        if (current == last) {
            last = prev;
        }
        delete current;
    }

    cout << "Number " << number << " has been deleted.\n";
    cout << endl;
}

void display_List(node *current) {
    if (is_Empty(current))
        cout << "The list is currently empty.\n";
    else {
        cout << "The list contains: \n";
        while(current != NULL) {
            cout << current->number << endl;
            current = current->next;
        }
    }
}


int main() {
    node *head = NULL;
    node *last = NULL;
    char choice;
    int number;

    do {
        choice = menu();  

        switch(choice) {
            case '1': 
                cout << "\nPlease enter a number: ";
                cin >> number;
                insert_Item(head, last, number);
                cout << endl;
                break;
            case '2': 
                delete_Item(head, last);
                break;
            case '3':
                display_List(head);
                break;
            case '4':
                cout << "\nExiting program .... \n";
                break;
            default:
                cout << "Invalid choice. Please try  again. \n";
        }
    }
    while (choice != '4');

    return 0;
}