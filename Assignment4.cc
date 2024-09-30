#include <iostream>
#include <string>
using namespace std;

class Text

{
public:
    string data;
    string title;
    Text *next;
    Text *prev;
    
    Text()
    {
        title = "";
        next = NULL;
    }

    Text(string d)
    {
        title = d;
        next = NULL;
    }
};

class Texteditor
{
    Text *head = NULL;

public:
    void Create()
    {
        if (head == NULL)
        {
            cout << "Texteditor is empty" << " ";
            Text*nn = new Text();
            head = nn;
        }
    }

    void insert_start(string d) // Inserts at the start of the linked list
    {
        Text*nn = new Text(d);
        if (head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }

    void print()
    {
        cout << "Displaying linked list" << endl;
        Text
            *temp = head;
        while (temp != NULL)
        {
            cout << temp->title << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert_end(string d)
    {
        Text*nn = new Text(d); // New Text is initialized here

            if (head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            Text*temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            nn->prev = temp;
            temp->next = nn;
        }
    }

    void delete_start()
    {
        if (head == NULL)
        {
            cout << "texteditor is empty" << endl;
        }
        else
        {
            head = head->next;
            head->prev =  NULL;

        }
    }

    void delete_end()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Text*temp = head;
            Text*prev = NULL;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            temp =  NULL;
            prev->next = NULL;
        }
    }

    void search()
    {
        string title;
        cout << "Enter the title of Text: ";
              cin >>title;

        Text*temp = head;
        while (temp != NULL)
        {
            if (title == temp->title)
            {
                cout << "TextFound " << endl;
                    return;
            }
            temp = temp->next;
        }
        cout << "Text Not Found " << endl;
    }

    void reverse(string d)
    {
        Text*temp = head;

        while(temp->next!=NULL)
        {
            temp =  temp->next;
            return;
        }

        while(temp !=NULL)

        {
            cout<<temp->data<<"  "; 
            temp  = temp->prev;
            return;

        }
        
    }
};

int main()
{
    Texteditor list;
    int choice = 0;
    string data;

    while (choice != 10)
    {
        cout << "1. Create a text" << endl;
        cout << "2. Add Text at start " << endl;
        cout<< "3. Add Text at end " << endl;
        cout<< "4. Display the entire Text editor" << endl;
        cout << "5. Delete  the first Text"<<endl;
        cout<< "6. Delete the last Text"<<endl;
        cout<< "7. Search Text by title "<<endl;
        cout<<"8. Reverse the message"<<endl;
        cout<< "9. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            list.Create(); // Prints the choices to create
            break;
        case 2:
            cout << "Enter title of Text: "; //Prints the the  title of the Text at start

            cin >>data;
            list.insert_start(data);
            break;
        case 3:
            cout << "Enter title: "; // Prints the title of the Textat end

            cin >>data;
            list.insert_end(data);
            list.print();
            break;

        case 4:
            list.print();
            break;
        case 5:
            list.delete_start();
            break;
        case 6:
            list.delete_end();
            break;
        case 7:

            list.search();
            break;
        case 8:
            list.reverse(data);
            break;    

        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
