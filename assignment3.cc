#include <iostream>
#include<string>
using namespace std;

class Song
{
public:
    string title;
    string artist;
    float duration; // duration can be any number of seconds
    Song* next;

    Song()
    {
        title = "";
        next = NULL;
    }

    Song(string d)
    {
        title = d;
        next = NULL;
    }
};

class PlayList
{
    Song* head = NULL;

public:
    void Create()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty" << " ";
            Song* nn = new Song();
            head = nn;
        }
    }

    void insert_start(string d)  // Inserts at the start of the linked list 
    {
        Song* nn = new Song(d);
        if (head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            nn->next = head;
            head = nn;
        }
    }

    void print()
    {
        cout << "Displaying linked list" << endl;
        Song* temp = head;
        while (temp != NULL)
        {
            cout << temp->title << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert_bet(string d)
    {
        Song* nn = new Song(d);
       
        if (head == NULL)
        {
            cout<<"List is empty"<<endl;
            head = nn;
            return;

        }

        else
        {
            Song *temp  = new Song(d);
            temp  = head;
            while (temp->next != NULL)
            {
                if(temp ->data == key)
                {
                    nn->next = temp->next;
                    temp->next = nn;
                }
                temp = temp->next;
            }
            
        }

    }



    void insert_end(string d)
    {
        Song* nn = new Song(d); //New Song is initialized here

        if (head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            Song* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    void delete_start()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            head = head->next;
        }
    }

    void delete_end()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Song* temp = head;
            Song*  prev = NULL;
            while(temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            

        }
        

    }

   void search() {
        string title;
        cout << "Enter the title of song: ";
        cin >> title;

        Song* temp = head;
        while (temp != NULL) {
            if (title == temp->title) {
                cout << "Song Found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song Not Found" << endl;
    }
};

int main()
{
    PlayList list;
    int choice = 0;
    string data;

    while (choice != 10)
    {
        cout << "1. Create a playlist" << endl;
        cout << "2. Add song at start" << endl;
        cout << "3. Add song at end" << endl;
        cout << "4. Display the entire playlist" << endl;
        cout<<"5. Delete  the first song"<<endl;
        cout<<"6. Delete the last song"<<endl;
        cout<<"7. Search song by title"<<endl;
        cout<<"8. Delete song by title"<<endl;
        cout <<"9. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            list.Create(); //Prints the choices to create
            break;
        case 2:
            cout << "Enter title of song: "; //Prints the the  title of the song at start 

            cin >> data;
            list.insert_start(data);
            break;
        case 3:
            cout << "Enter title: ";  //Prints the title of the song at end

            cin >> data;
            list.insert_end(data);
            list.print();
            break;
        
        case 4:
            list.print();
            break ;
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
            list.insert_bet(string d);
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
