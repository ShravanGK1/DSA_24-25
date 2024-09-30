#include <iostream>
#include <string>
using namespace std;

class route {
public:
    string data;
    route* next;

    route(string d) {
        data = d;
        next = NULL;
    }
};

class navigation {
    route* head = NULL;

public:
    // Insert a route at the start
    void insert_start(string d) {
        route* nn = new route(d);
        if (head == NULL) {
            head = nn;
            head->next = head; 
        } else {
            route* temp = head;
            
            while (temp->next != head) {
                temp = temp->next;
            }
            nn->next = head;  
            temp->next = nn;   
            head = nn;         
        }
    }

    
    void insert_end(string d) {
        route* nn = new route(d);
        if (head == NULL) {
            head = nn;
            head->next = head; 
        } else {
            route* temp = head;
            
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = nn;   
            nn->next = head;  
        }
    }

    
        void delete_start() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (head->next == head) 
        {
            delete head;
            head = NULL;
        } else {
            route* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            route* toDelete = head; 
            temp->next = head->next; 
            head = head->next;       
            delete toDelete;         
        }
    }

    void delete_end() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (head->next == head) 
        { 
            
            delete head;
            head = NULL;
        } else {
            route* temp = head;
            // Traverse to the second last node
            while (temp->next->next != head) {
                temp = temp->next;
            }
            route* toDelete = temp->next; // Last node to be deleted
            temp->next = head;            // Second last node points to head
            delete toDelete;              // Delete the last node
        }
    }

    // Print the routes
    void print() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        route* temp = head;
        cout << "Displaying linked list: ";
        while (temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";  // Print the last node
        cout << endl;
    }

    // Search for a route
    void search() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        string title;
        cout << "Enter the destination: ";
        cin >> title;

        route* temp = head;
        while (temp->next != head) {
            if (temp->data == title) {
                cout << "Route found: " << temp->data << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->data == title) { // Check last node
            cout << "Route found: " << temp->data << endl;
        } else {
            cout << "Route not found." << endl;
        }
    }
};

int main() {
    navigation n;
    int choice = 0;
    string data;

    while (choice != 7) {
        cout << "\nNavigation System" << endl;
        cout << "1. Add Route at start" << endl;
        cout << "2. Add Route at end" << endl;
        cout << "3. Delete route at start" << endl;
        cout << "4. Display Routes" << endl;
        cout << "5. Delete route at end" << endl;
        cout << "6. Search Route" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter destination to be added at start: ";
            cin >> data;
            n.insert_start(data);
            break;

        case 2:
            cout << "Enter destination to be added at end: ";
            cin >> data;
            n.insert_end(data);
            break;

        case 3:
            n.delete_start();
            break;

        case 4:
            n.print();
            break;

        case 5:
            n.delete_end();
            break;

        case 6:
            n.search();
            break;

        case 7:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
