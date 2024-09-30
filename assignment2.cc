#include<iostream>
using namespace std;

class Employee
{
    public:

    int ID;
    string name;
    int Sal;

    void input()
    {
        cout<<"Enter name of Employee: "<<endl;
        cin>>name;
        cout<<"Enter Employee ID: "<<endl;
        cin>>ID;
        cout<<"Enter Salary of employee: "<<endl;
        cin>>Sal;
    }

    void display()
    {
        cout<<"Name of the employee is: "<<name<<endl;
        cout<<"Employee ID is: "<<ID<<endl;
        cout<<"Salary of employee is: "<<Sal<<endl;
     }

    void quicksort(Employee a[], int F, int L)
    {
        if(F<L)
        {
            int pivot = F;
            int i = F+1;
            int j = L;  
        
            while(i<=j){
                while(a[i].ID<a[pivot].ID){
                    i++;
                }
                while(a[j].ID>a[pivot].ID){
                    j--;
                }
                if(i<j){
                    Employee temp = a[i];
                    a[i]=a[j];
                    a[j]=temp;

                }
                else{
                    break;


                }
            }
                Employee temp = a[j];
                a[j]=a[pivot];
                a[pivot]=temp;
                quicksort(a,F,j-1);
                quicksort(a,j+1,L);           
        }       
    }
};

int main()
{
    Employee e;
    int n;
    cout<<"Enter number of employees: "<<endl;
    cin>>n;

    Employee a[n];

    for(int i=0;i<n;i++){
            a[i].input();
        }
        int F=0,L=n-1;
        e.quicksort(a,F,L);
        for(int i=0;i<n;i++){
            a[i].display();
        }

    
    return 0;
}


