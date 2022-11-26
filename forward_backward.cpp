#include<iostream>
#include<string.h>
using namespace std;
#define max 10

class forward_backward
{
    public:
    
    int top = -1;
    string stack[max];

    bool isFull(){
    if(top == max-1)
    return true;
    else
    return false;
    }
    
    bool isEmpty(){
    if(top == -1)
    return true;
    else
    return false;
    }

    void push(string url){
        if(isFull())
        cout<<"Stack overflow"<<endl;
        else{
            top++;
            stack[top]=url;
        }
    }

    string pop(){
        if(isEmpty())
        cout<<"Stack underflow"<<endl;
        else{
            return stack[top--];
        }
    }
}f,b;

string current_url = "http://abc.com";

void display_url(){
    cout<<"------------------------------------"<<endl;
    cout<<"current page:"<<current_url<<endl;
    cout<<"------------------------------------"<<endl;
}

void add_url(string url){
    while(!f.isEmpty()){
        f.pop();
    }
    b.push(current_url);
    current_url = url;
    display_url();
}

void go_forward(){
    if(f.isEmpty())
    cout<<"No url to go forward"<<endl;
    else{
        b.push(current_url);
        current_url = f.pop();
    }
    display_url();
}

void go_backward(){
    if (b.isEmpty())
    cout<<"No url to go backward"<<endl;
    else{
        f.push(current_url);
        current_url = b.pop();
    }
    display_url();
}

void display(){
    if (f.isEmpty())
    cout<<"Forward stack empty"<<endl;
    else{
        cout<<"------------------------------------"<<endl;
        cout<<"Forward stack"<<endl;
        cout<<"------------------------------------"<<endl;
        for (int i = f.top; i >= 0; i--)
        {
            cout<<i+1<<"."<<f.stack[i]<<endl;
        }
        cout<<"------------------------------------"<<endl;
    }

    if (b.isEmpty())
    cout<<"backward stack empty"<<endl;
    else{
        cout<<"------------------------------------"<<endl;
        cout<<"backward stack"<<endl;
        cout<<"------------------------------------"<<endl;
        for (int i = b.top; i >= 0; i--)
        {
            cout<<i+1<<"."<<b.stack[i]<<endl;
        }
        cout<<"------------------------------------"<<endl;
    }
}

int main()
{
    int choice;
    string link;

    display_url();

    do
    {
    cout<<"1.Add new web link"<<endl;
    cout<<"2.Go forward"<<endl;
    cout<<"3.Go backward"<<endl;
    cout<<"4.Display both stack"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"Enter choice:"<<endl;
    cin>>choice;

        switch(choice)
        {
            case 1: cout<<"Enter a web link:";
                    cin>>link;
                    add_url(link);
            break;

            case 2: go_forward();
            break;

            case 3: go_backward();
            break;

            case 4: display();
            break;

            case 5: cout<<"Exit"<<endl;
            break;
            
            default: cout<<"Invalid Choice"<<endl;
                     break;
        }
    }while(choice!=5);
    return 0;
}