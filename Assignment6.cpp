#include<iostream>
using namespace std;
class Node
{
    public:
    int pow;
    int coeff;

    Node* next;
    Node()
    {
        pow = 0;
        coeff = 0;
        next = NULL;
    }

    Node(int x, int y)
    {
        coeff = x;
        pow = y;
        next = NULL;

    }
};

class Poly
{
    public:
    Node* head=NULL;
    void create_node(int x, int y)
    {
        Node* nn = new Node(x,y);
        nn->coeff = x;
        nn->pow  = y;
        if(head==NULL)
        {
            head = nn;

        }
        else
        {
            Node* temp = new Node();
            temp = head;
            
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }

    }

    void printpoly()
    {
        if(head!=NULL)
        {
            Node* temp = head;
            while(temp->next!=NULL)
            {
                cout<<temp->coeff<<"x"<<temp->pow<<"+";
                temp = temp->next;
            }
            cout<<temp->coeff<<"x"<<temp->pow;
        }
    }


    void polyadd(Poly l1, Poly l2)
    {
        Node* p1 = l1.head;
        Node* p2 = l2.head;
        Node* result = new Node();
        Node* curr = result;

        while(p1!=NULL && p2!=NULL)
        {
            Node*nn = new Node();
            if(p1->pow>p2->pow)
            {
                nn->pow = p1->pow;
                nn->coeff = p1->coeff;
                p1 = p1->next;
            }
            else if(p2->pow>p1->pow)
            {
                nn->pow = p2->pow;
                nn->coeff = p2->coeff;
                p2 = p2->next;

            }
            else
            {
                nn->pow = p1->pow;
                nn->coeff = p1->coeff + p2->coeff;
                p1 = p1->next;
                p2 = p2->next;

            }
            curr ->next = nn;
            curr = curr->next;

        }

        // while(p1!=NULL && p2!=NULL)
        // {
        //     if(p1->pow>p2->pow)
        //     {
        //         curr->next = p1;
        //         curr = curr->next;
        //         p1 = p1->next;
        //     }
        //     else if(p1->pow<p2->pow)
        //     {
        //         curr->next=p2;
        //         curr = curr->next;
        //         p2=p2->next;

        //     }

        // }

        while(p1!=NULL)
        {
            curr->next=p1;
            curr= curr->next;
            p1 = p1->next;

        }

        while(p2!=NULL)
        {
            curr->next=p2;
            curr= curr->next;
            p2 = p2->next;        
        }
        head = result -> next;

    }
}; 


int main()
{
    Poly l1,l2,l3;
    l1.create_node(15,6);
    l1.create_node(23,5);
    l1.create_node(3,2);
    cout<<"First Polynomial "<<endl;

    l1.printpoly();

    l2.create_node(5,4);
    l2.create_node(12,4);
    l2.create_node(7,3);
    
    cout<<"Second Polynomial "<<endl;
    l2.printpoly();

    l3.polyadd(l1,l2);
    cout<<"Addition of polynomial is: "<<endl;
    l3.printpoly();
return 0;
}