#include<iostream>
using namespace std;

class Stack
{
    int top;
    string history[10];
    public:
    Stack()
    {
        top = -1;
    }
    void add(string s)
    {
        
        top++;
        history[top] = s;
        
    }

    void view_current()
    {
        if(top == -1)
        {
            cout<<"Browser History is empty"<<endl;
        }
        else
        {
        cout<<history[top]<<endl;
        }
    }
    void nav_back()
    {
        if(top == -1)
        {
            cout<<"Browser History is empty"<<endl;
        }
        else
        {
           top--;
           for(int i = top; i>=0; i--)
           {
            cout<<history[i]<<endl;
           }
        }    
    
    }   

    void check()
    {
        if(top == -1)
        {
            cout<<"Browser History is empty"<<endl;
        }
        else
        {
            cout<<"Browser History is not empty"<<endl;
        }
    }

    void display()
     {
           
           for(int i = top; i>=0; i--)
           {
            cout<<history[i]<<endl;
           }
    }

    
};

int main()
{
    Stack s;
    int choice;
    string data;

    while (choice != 6)
    {
        cout << "1. Add Visited Page" << endl;
        cout << "2. Navigate Back " << endl;
        cout<< "3. View Current page " << endl;
        cout<< "4. Check if History is empty or not" << endl;
        cout<<"5.Display the websites in the history"<<endl;
        cout<< "6. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
        cout<<"Enter History"<<endl;
        cin>>data;
        s.add(data);
        break;

        case 2:
        s.nav_back();
        break;
        
        case 3: 
        s.view_current();
        break;

        case 4:
        s.check();
        break;
        case 5:
        s.display();
        break;

        case 6:
        cout << "Exiting............" << endl;
        break;
        default:
        cout << "Invalid choice" << endl;
        break;
        }
    }

    return 0;
}