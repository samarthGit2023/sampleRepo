#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node*ptr;
void insert(int x, node *&head)
{
    node*temp=new node;
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        ptr=temp;
    }
    else{
        ptr->next=temp;
        ptr=temp;
    }
}

void traverse(node* &head)
{
    node *temp2 = new node;
    temp2 = head;
    while (temp2 != NULL)
    {
        cout << temp2->data << "->";
        temp2 = temp2->next;
    }
    cout<<"NULL"<<endl;

}

void insert_at_start(node* &head, int &element1)
{
    node *temp3 = new node;
    temp3->data = element1;
    temp3->next=head;
    head=temp3;
}

void insert_at_middle(node*head, int &x1, int &element2)
{
    node *temp4 = new node;
    node *temp5 = new node;
    temp4 = head;
    while (temp4->data != x1)
    {
        temp4 = temp4->next;
    }
    temp5->data = element2;
    temp5->next = temp4->next;
    temp4->next = temp5;
}

void insert_at_end(node*head, int &element3)
{
    node *temp7 = new node;
    temp7->data = element3;
    temp7->next = NULL;
    node *temp6 = new node;
    temp6 = head;
    while (temp6->next != NULL)
    {
        temp6 = temp6->next;
    }
    temp6->next = temp7;
}

void delete_in_list(node* &head, int &element4)
{
    node*temp8;
    temp8=head;
    if(head->data==element4){
        head=head->next;
        delete(temp8);
    }
    else{
        node*temp9;
        temp9=head;
        while(temp9->next->data!=element4){
            temp9=temp9->next;
        }
        node*temp10;
        temp10=temp9->next;
        temp9->next=temp10->next;
        delete(temp10);
    }
}

int main()
{
    node *head;
    head = NULL;

    insert(34, head);
    insert(67, head);
    insert(77, head);
    insert(21, head);
    insert(45, head);
    insert(99, head);

    traverse(head);
    cout << endl;

    while (1)
    {

        cout << "Enter 1 to insert at start" << endl;
        cout << "Enter 2 to insert at middle" << endl;
        cout << "Enter 3 to insert at end" << endl;
        cout << "Enter 4 to delete the element" << endl;
        cout << "Enter 5 to exit the code" << endl;
        int var;
        cin >> var;

        if (var == 1)
        {
            cout << "Enter the element you want to insert at the start" << endl;
            int element1;
            cin >> element1;
            insert_at_start(head, element1);
            traverse(head);
        }

        else if (var == 2)
        {
            cout << "Enter the element after which you want to insert" << endl;
            int x1;
            cin >> x1;
            cout << "Enter the element which you want to insert after " << x1 << endl;
            int element2;
            cin >> element2;
            insert_at_middle(head, x1, element2);
            traverse(head);
        }

        else if (var == 3)
        {
            cout << "Enter the element you wanna insert at the end" << endl;
            int element3;
            cin >> element3;
            insert_at_end(head, element3);
            traverse(head);
        }

        else if (var == 4)
        {
            cout << "Enter the element you wanna delete" << endl;
            int element4;
            cin >> element4;
            delete_in_list(head, element4);
            traverse(head);
        }

        else if (var == 5)
        {
            cout << "Program exit" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}
