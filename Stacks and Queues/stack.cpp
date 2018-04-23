#include <iostream>
 
using namespace std;
 
class llist
{
public:
    int data;
    llist *pNext;
    llist *pPrev;
    llist(int n)
    {
        data = n;
        pNext = NULL;
        pPrev = NULL;
    }
};
 
class Stack
{
private:
    int top;
    llist *list;
    llist *midNodeOfList;
    llist *lastNodeOfList;
    bool flagSet;
public:
    Stack()
    {
        list = NULL;
        top = 0;
        midNodeOfList = NULL;
        lastNodeOfList = NULL;
        flagSet = false;
    }
    ~Stack()
    {
        while(list != NULL)
        {
            llist* temp = list;
            list = list->pNext;
            delete temp;
        }
    }
    void push(int n)
    {
        llist *newNode = new llist(n);
        if(list == NULL)
        {
            list = newNode;
            midNodeOfList = newNode;
            lastNodeOfList = newNode;
            flagSet = true;
        }
        else
        {
            lastNodeOfList->pNext = newNode;
            newNode->pPrev = lastNodeOfList;
            lastNodeOfList = newNode;
            flagSet = !flagSet;
            if(flagSet)
            {
                midNodeOfList = midNodeOfList->pNext;
            }
        } 
        top++;
    }
    int pop()
    {
        int nRet=0;
        llist *temp = lastNodeOfList;
        lastNodeOfList = lastNodeOfList->pPrev;
        if(lastNodeOfList)lastNodeOfList->pNext = NULL;
        nRet = temp->data;
        delete temp;
 
        top--;
 
        flagSet = !flagSet;
        if(flagSet)
        {
            midNodeOfList = midNodeOfList->pPrev;
        }
        return nRet;
    }
    int mid()
    {
        return midNodeOfList->data;
    }
    void deleteMid()
    {
        if(midNodeOfList != NULL)
        {
            llist *temp = midNodeOfList;
            if(midNodeOfList->pPrev != NULL)
            {
                midNodeOfList = midNodeOfList->pPrev;
            }
            midNodeOfList->pNext = temp->pNext;
            temp->pNext->pPrev = midNodeOfList;
            delete temp;
            flagSet = !flagSet;
            if(flagSet)
            {
                midNodeOfList = midNodeOfList->pNext;
            }
            top--;
        }
    }
    void display()
    {
        llist* temp = list;
        while(temp != NULL)
        {
            cout<<temp->data;
            temp = temp->pNext;
            (temp!=NULL)?cout<<"<=>":cout<<"\n";
        }
    }
    bool isEmpty()
    {
        if(list == NULL)
        {
            return true;
        }
        return false;
    }
};
 
int main(int argc, char* argv[])
{
    Stack s;
    int ch;
    for(int i=1;i<10;i++)
        s.push(i);
 
    do{
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Display stack"<<endl;
        cout<<"4.Display mid"<<endl;
        cout<<"5.Delete mid"<<endl;
        cout<<"6.Exit "<<endl;
        cout<<"Select the operations on stack:";
        cin>>ch;
        
        switch(ch){
        case 1:
            int n;
            cout<<"Enter element to insert";
            cin>>n;
            s.push(n);
            break;
        case 2:
            if(s.isEmpty())
                cout<<"Sorry, stack is empty"<<endl;
            else
                cout<<"Popped element"<<s.pop()<<endl;
            break;
        case 3:
            if(s.isEmpty())
                cout<<"Sorry, stack is empty\n";
            else
                s.display();
            break;
        case 4:
            if(s.isEmpty())
                cout<<"Sorry, stack is empty\n";
            else
                cout<<"Mid element is "<<s.mid()<<endl;
            break;
        case 5:
            if(s.isEmpty())
                cout<<"Sorry, stack is empty\n";
            else
                s.deleteMid();
            break;
        default:
            if(ch!=6)
                cout<<"Invalid choice"<<endl;
            break;
        }
    }while(ch != 6);
 
    return 0;
}