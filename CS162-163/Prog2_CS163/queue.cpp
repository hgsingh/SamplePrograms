#include "cs163_program2.h"
using namespace std;
/*
 * @author Harsukh Singh
 * @function enqueues a node object at the end of a circular linked list
 * @param takes a constant of a c_node struct instance
 * @return success or fail of integer value
 */
int queue::enqueue(const c_node &operation)
{
  q_node* add_q = new q_node; //create new q_node object pointer
  add_q->calc = new c_node;
  add_q->calc->number = operation.number;
  add_q->calc->operation = operation.operation;
  q_node* temp; //temp pointer for adding
  if(rear ==NULL)
  {
    rear = add_q; // let q_first point to rear
    add_q->next = rear; //point back to rear
    return 1;
  }
  temp = rear -> next; // hold on to head
  rear->next = add_q; //add the new node
  rear = rear -> next; //update rear pointer
  rear->next = temp; //make circular
  return 1;
}
/*
 * @author Harsukh Singh
 * @function dequeues a node object at the front of a circular linked list
 * @param takes a constant of a c_node struct instance
 * @return success or fail of integer value
 */
int queue::dequeue(c_node &operation)
{
  int success = 0;
  q_node* temp;
  q_node* delete_pointer;
  temp = rear->next;
  delete_pointer = temp;
  if(rear == NULL)
  {
   cout<<"Nothing to dequeue."<<endl;
   return 0;
  }
  else if(rear->next == rear && operation.number == rear->calc->number && operation.operation == rear->calc->operation)
  {
    delete rear->calc;
    delete rear->next;
    delete rear;
    success = 1;
    return success;
  }
  else
  {
    rear->next = NULL; //make linear for a while
    while(operation.number != temp->calc->number && operation.operation != temp->calc->operation && temp->next != NULL)
    {
      delete_pointer = temp;
      temp = temp->next;
      delete delete_pointer->calc;
      delete delete_pointer->next;
      delete delete_pointer;
    } 
    if(temp->next == NULL)
    {
     cout<<"Nothing to dequeue."<<endl;
     success = 0;
     return success;
    }
    delete_pointer = temp;
    temp = temp->next;
    delete delete_pointer->calc;
    delete delete_pointer->next;
    delete delete_pointer;
    rear->next = temp;
  }
}
/*
 * @author Harsukh Singh
 * @function displays an entire circular linked list of queue, this does a linear traversal
 * @param void
 * @return success or fail of integer value
 */
int queue::display() const 
{
  q_node* front;
  q_node* temp;
  if(rear == NULL)
  {
   cout<< "Nothing to display."<<endl;
   return 0; 
  }
  front = rear->next;
  rear->next = NULL;
  temp = front;
  while(temp != NULL)
  {
   cout<<temp->calc->number<<endl;
   cout<<temp->calc->operation<<endl;
   temp = temp->next; //iterate through
  }
  return 1;
}