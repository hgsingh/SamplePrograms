//@author harsukh singh assignment 3 CS202
//5/12/2012

#include "table.h"
using namespace std;

/***********
 *@author harsukh singh
 *@function playlist constructor
 *@args void
 *@return void
 ***********/
playlist::playlist():rear(0){}


/***********
 *@author harsukh singh
 *@function copy constructor
 *@args const playlist obj
 *@return void
 ***********/
playlist::playlist(const playlist &to_copy):rear(0)
{
    if(to_copy.rear) //check if CLL is NULL
        copy_cll(to_copy.rear); //call function here
}

/***********
 *@author harsukh singh
 *@function copy CLL wrapper
 *@args rear of the node
 *@return void
 ***********/
void playlist::copy_cll(node* to_copy) //wrapper function
{
    if(!to_copy) return; //check CLL here
    if(rear) //check CLL here if it is NULL
    {
        node* head = rear -> get_next();
        rear -> set_next(NULL);
        delete_all(head);
        rear = NULL;
    }
    copy_cll(rear, to_copy->get_next(), to_copy);
    node* temp = rear;
    node* front = rear;
    while(temp->get_next())
        temp = temp->get_next();
    rear = temp;
    rear->get_next() = front;
}

/***********
 *@author harsukh singh
 *@function copy CLL function
 *@args rear of the node to copy as a check, rear next of node to copy, rear of the node
 *@return void
 ***********/
void playlist::copy_cll(node* &rear, node* to_copy, node* rear_check)
{
    if(to_copy == rear_check)
    { 
        rear = new node(*to_copy);
        return;
    }
    rear = new node(*to_copy);
    copy_cll(rear->get_next(), to_copy->get_next(), rear_check);
}

/***********
 *@author harsukh singh
 *@function delete all function
 *@args the head of the list
 *@return void
 ***********/
void playlist::delete_all(node* &head)
{
    if(!head) return;
    delete_all(head->get_next());
    delete head;
    head = NULL;
}

/***********
 *@author harsukh singh
 *@function destructor
 *@args void
 *@return void
 ***********/
playlist::~playlist()
{
    if(rear)
    {
        node* head = rear -> get_next();
        rear -> set_next(NULL);
        delete_all(head);
    }
    rear = NULL;
}

/***********
 *@author harsukh singh
 *@function assignment operator
 *@args const playlist object 
 *@return playlist residual value
 ***********/
playlist& playlist::operator=(const playlist &op2)
{
    if(this == &op2)
    {
        return *this;
    }
    copy_cll(op2.rear);
    return *this;
}

/***********
 *@author harsukh singh
 *@function addition to queue
 *@args const playlist object 
 *@return playlist residual value
 ***********/
playlist& playlist::operator+=(const song &op2)
{
    if(rear == NULL)
    {
        rear = new node(op2);
        rear->set_next(rear);
        return *this;
    }
    node* temp = rear->get_next();
    node* to_add = new node(op2);
    rear->set_next(to_add);
    rear = rear ->get_next();
    rear->set_next(temp);
    return *this;
}

/***********
 *@author harsukh singh
 *@function addition to queue
 *@args const playlist object 
 *@return playlist residual value
 ***********/
ostream& operator<<(ostream &op1, const playlist &op2)
{
    if(!op2.rear) 
    {
        op1<<"Playlist is empty."<<endl;
        return op1;
    }
    node* temp = op2.rear->get_next();
    while(temp != op2.rear)
    {
        op1 <<*temp<<'\n';
        temp = temp -> get_next();
    }
    op1<<*temp<<'\n';
    return op1;
}

/***********
 *@author harsukh singh
 *@function remove from queue
 *@args const song object and temp pointer to the head of the list 
 *@return int for true of false
 ***********/
int playlist::remove(node* & temp, const song &to_compare)
{
    if(temp->compare(to_compare) ==1)
    {
        //cout<<temp<<endl;
        node* del_ptr = temp;
        temp = temp->get_next();
        delete del_ptr;
        del_ptr = NULL;
        return 1;
    }
    else{
        return remove(temp->get_next(), to_compare);
    }
}

/***********
 *@author harsukh singh
 *@function remove from the queue
 *@args const song object
 *@return playlist residual value
 ***********/
playlist& playlist::operator-=(const song &op2)
{
    if(rear == NULL) 
    {
        cout<<"Playlist empty! Nothing to remove."<<endl;
        return *this;
    }
    node* temp = rear->get_next();
    rear->set_next(NULL);
    int check = remove(temp, op2);
    node* front = temp;
    while(temp->get_next())
        temp = temp->get_next();
    rear = temp;
    rear->get_next() = front;
    if(check == 1) 
    {
        cout<<"song removed"<<endl;
        return *this;
    }
    else{
        cout<<"song not found"<<endl;
        return *this;
    }

}
