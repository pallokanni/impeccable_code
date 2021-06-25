//linked list class
//add front
//add last
//add index
//delete front
//delete last
//delete index

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<list>
#include<limits.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<math.h>

using namespace std;

#define impeccable_code 0
#define MOD 1000000007

inline int fscan(){
    int a=0;
    char c= getchar();

    while (c < '0' || c>'9')c=getchar();

    while( c >= '0' && c <= '9' )
     {
       a = (a<<3)+(a<<1) + c-'0';
       c=getchar();
     }

     return a;
}

long long int pw_mod(long long int base,long long int exp)
{
  if(base==1)
    return 1;

  long long int res = 1;

  while(exp>0){
    if(exp&1)res =(res*base)%MOD;
    base=(base*base)%MOD;
    exp>>=1;
  }

  return res;
}

int gcd(int A, int B)
{
	if(A % B == 0)
	{
		return B;
	}

	gcd(B, A%B);
}

class linkedList
{
//Access specifier
private:
    //Data Members
    struct node
    {
        int data;
        struct node *next;
    }*head;

//Access specifier
public:

    //Default Constructor
    linkedList()
    {
        cout<<"Constructor called"<<endl;
        head = NULL;
    }

    //Parameterized Constructor
    linkedList(int val)
    {
        cout<<"Parameterized Constructor with val: "<<val<<endl;
        head = (node*)malloc(sizeof(struct node));
        head->data = val;
        head->next = NULL;
    }

    //Function to add new_node at front
    void addFront(int val)
    {
        node *new_node = (node*)malloc(sizeof(node));

        new_node->data = val;
        new_node->next = head;

        head = new_node;
    }

    //Function to add new_node at last
    void addLast(int val)
    {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = val;
        new_node->next = NULL;

        node *temp;

        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = new_node;
        }
    }

    //Function to add new_node at particular Index
    bool addIndex(int val, int index)
    {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = val;
        new_node->next = NULL;

        node *temp;
        int i;

        if(index <= 0)
        {
            cout<<"Invalid Index: "<<index<<endl;
            return false;
        }
        else if(index == 1)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            temp = head;
            i = 2;
            while(temp != NULL && i < index)
            {
                temp = temp->next;
                i++;
            }

            if(temp == NULL)
            {
                cout<<"Invalid Index: "<<index<<endl;
                return false;
            }
            else
            {
                new_node->next = temp->next;
                temp->next     = new_node;
            }
        }
        return true;
    }

    //Function to delete front node of the list
    void deleteFront()
    {
        node *temp;
        temp = head;
        if(temp == NULL)
        {
            cout<<"List already empty"<<endl;
        }
        else
        {
            head = temp->next;
            cout<<"deteled front: "<<temp->data<<endl;
            free(temp);
        }
    }

    //Function to delete last node of the list
    void deleteLast()
    {
        node *temp;
        temp = head;

        if(temp == NULL)
        {
            cout<<"List already empty"<<endl;
        }
        if(temp->next == NULL)
        {
            cout<<"Deleted Last Node: "<<temp->data<<endl;
            free(temp);
            head = NULL;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }

            cout<<"Deleted Last Node: "<<temp->next->data<<endl;
            free(temp->next);
            temp->next = NULL;
        }
    }

    //Function to delete node at particular Index
    bool deleteIndex(int index)
    {
        node *temp, *prev;
        temp = head;
        int i = 0;

        if(index <= 0)
        {
            cout<<"DeleteIndex: Invalid Index: "<<index<<endl;
            return false;
        }
        if(index == 1)
        {
            deleteFront();
        }
        else
        {
            prev = temp;
            temp = temp->next;
            i = 2;
            while(temp !=  NULL && i < index)
            {
                prev = temp;
                temp = temp->next;
                i++;
            }

            if(temp == NULL)
            {
                cout<<"Invalid Index: "<<index<<endl;
                return false;
            }
            else
            {
                cout<<"Deleted Index Node: "<<temp->data<<endl;
                prev->next = temp->next;
                free(temp);
            }
        }
        return true;
    }

    void printList()
    {
        node *temp;
        temp = head;

        while(temp != NULL)
        {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<endl;
    }

    //Definition for Destructor
    ~linkedList()
    {
        cout <<"Destructor called"<<endl;
    }
};

int main() {

    linkedList myList;
    //cout<<myList.head.data<<endl;
    myList.addFront(3);
    myList.addFront(2);
    myList.addFront(1);
    myList.addLast(5);
    myList.addLast(6);
    myList.addIndex(4, 1);

    myList.printList();

    myList.deleteFront();
    myList.printList();

    myList.deleteLast();
    myList.printList();

    myList.deleteIndex(4);
    myList.printList();

return impeccable_code;
}
