#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>


struct Node
{
    int data;
    struct Node *next; //Node *next in cpp
};

//Node *head in cpp
struct Node *head;
//struct Node *current;

    void insert(int x)
    {
        struct Node *temp = (Node*)malloc(sizeof(struct Node));
		//Node *temp=new Node() in cpp
        //struct Node *current;

         temp->data=x;
         temp->next=head;
         head=temp;



/*
        if(head==NULL)
        {
                                                //if(head!=NULL) //temp->next=head;           //temp->next=head
            head= temp;
            current=temp;

        }

        else
        {
            current->next=temp;
            current=temp;


        }
*/


    }

    void display ()
    {
        struct Node *temp = head;
        while(temp!= NULL)
        {
            printf("\n %d",temp->data);
            temp=temp->next;


        }
        printf("\n");

    }

    void insertbetween(int x,int n)
    {
        Node *temp;
        temp=(Node*)malloc(sizeof(Node));

        temp->data=x;
        temp->next=NULL;

        if(n==1)
        {
            temp->next=head;
            head=temp;
            return;

        }
        Node *temp2 = head;
        for(int i=1;i<=n-1;i++)
        {
            temp2=temp2->next;
        }
        temp->next=temp2->next;
        temp2->next=temp;

    }
void deleten(int n)
{
    Node *temp = head;

    for(int i=1;i<=n-1;i++)
    {
        temp=temp->next;

    }

     Node *temp1 = head;
    for(int i=1;i<=n+1;i++)
    {
        temp1=temp1->next;

    }

    temp->next=temp1;


}



void displayn(struct Node* p)
{
    if(p==NULL)return;

    //printf("%d",p->data);
    displayn(p->next);
    printf("%d",p->data);

}

void searchbyn(int n)
{
    Node *temp =head;

    for(int i=1;i<=n;i++)
    {

        temp=temp->next;

    }

    printf("\n %d\n",temp->data);

}

void searchbyd(int d)
{
    Node *temp=head;
    int count=0;
    while(temp->data!=d)
    {

        temp=temp->next;
        count++;
    }
    printf("found at location %d",count);
}




void reverse()
{
    Node *next,*prev,*current;

    current=head;
    prev=NULL;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;

    }
    head=prev;

}

void reverser(Node *p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverser(p->next);
    Node *q=p->next;
    q->next=p;
    p->next=NULL;

}


int main()
{
    head = NULL;
    insert(2);
    display();
    insert(5);
    display();
    insert(6);
    display();
    insertbetween(7,2);
    display();
    deleten(2);
    display();
    searchbyn(2);
    //reverse();
    //displayn(head);
    reverser(head);
    display();
    //searchbyd(7);


}

/*

if(head==NULL)
    head=temp;

    else
    temp1=head
    while(temp1!=NULL) temp1=temp1->next;
    temp1->next=temp; */

