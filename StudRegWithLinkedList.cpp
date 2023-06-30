// doesnt work im confused i have no sleep
// ill fix this in the weekends i had a bad week

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int num_of_students;

int length_name = 6;
int length_srcode = 9;
int length_subj = 9;

struct Node{
    string data;
    Node *next;
};

Node *head = NULL;

void appendNode(string data){
    Node *n = new Node(), *curr;

    n = new Node();
    n->data = data;
    n->next = NULL;

    if (head==NULL) head = n;
    else {
        curr = head;
        while (curr->next !=NULL){
            curr = curr -> next;
        }
    }

    curr->next = n;
}

void displayList(){
    Node *curr;
    while (curr!=NULL){
        cout << left << setw(length_name) << curr->data
             << left << setw(length_srcode) << curr->next->data
             << left << setw(length_subj) << curr->next->next->data
             << endl;
        curr = curr->next->next->next;
    }
}

bool check_srcode(string srcode){
    if (srcode.length() != 8)
        return false;
    if (srcode[2] != '-')
        return false;
    for (int i = 0; i < 8; i++){
        if (i == 2) continue;
        else {
            if (isdigit(srcode[i]) == false)
                return false;
        }
    }
    return true;
}

int main(){
    bool input_loop = true;
    bool search_loop = true;
    string tempname, tempsrcode, tempsubj;
    Node *stud = NULL;
    
    cout << "Input number of students: ";
    cin >> num_of_students;

    for (int i = 0; i < num_of_students; i++){
        input_loop = true;
        do{
            cout << "Enter data of student no. " << i+1 << endl;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, tempname);
            if (tempname.length() > length_name)
                length_name = tempname.length() + 1;
            appendNode(tempname);

            cout << "Enter SR CODE: ";
            cin >> tempsrcode;
            if (check_srcode(tempsrcode)==false){
                cout << "SR-CODE is incorrect, please try again. " << endl << endl;
                continue;
            }
            else 
                appendNode(tempsrcode);

            cout << "Enter subject: ";
            cin >> tempsubj;
            appendNode(tempsubj);
            if (tempsubj.length() > length_subj)
                length_subj = tempsubj.length() + 1;

            cout << endl;
            input_loop = false;
        }
        while (input_loop);
    }
    
    cout << endl << endl;
    cout << left << setw(length_name) << "Name:"
        << left << setw(length_srcode) << "SR-CODE:"
        << left << setw (length_subj) << "Subject:"
        << endl;
    displayList();
    
    cout << endl << endl;

    do{
        string search_code;
        bool no_student = true;
        char cont_search;

        cout << "Input SR-CODE to search: ";
        cin >> search_code;

        Node* temp = head;
        
        for (int i = 0; i < num_of_students; i++){
            if(temp->next->data == search_code){
                no_student = false;
                cout << "Name: " << temp->data << endl;
                cout << "Subject: " << temp->next->next->data << endl << endl;
                break;
            }
        }

        if (no_student)
            cout << "No student with that SR-CODE was found.\n\n";

        
        cout << "Do you want to continue searching? ";
        cin >> cont_search;
        switch (cont_search){
            case 'n':
                search_loop = false;
                break;
            case 'N':
                search_loop = false;
                break;
            case 'y':
                cout << "\n";
                break;
            case 'Y':
                cout << "\n";
                break;
            default:
                cout << "That's not part of the options. You will continue searching.\n\n";
                break;
        }
    }
    while (search_loop);

}
