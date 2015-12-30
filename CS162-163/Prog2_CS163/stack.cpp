#include "cs163_program2.h"
using namespace std;
/*
 * @author Harsukh Singh
 * @function constructor initializes top index to 0
 * @param void
 * @return implicitly returns an instance of the stack class
 */
stack::stack()
{
  top_index = 0;
}
/*
 * @author Harsukh Singh
 * @function pushes a value into the array of c_node struct nodes, note here that top_index is limited to values from 0 to 9. 
 * @param takes a constant of a c_node struct instance
 * @return top_index
 */
int stack::push(const c_node &operation, int &node_count)
{
  s_node* stack = new s_node; 
  s_node* temp; 
  if(top == NULL)
  {
    top = stack; // make top point to stack 
    stack->calc = new c_node[stack_array_size];  //make calc array  
    stack -> next = NULL;
    ++node_count;
  } 
  else if(top_index == stack_array_size -1)
  {
   temp = top;
   top = stack;
   stack->calc = new c_node[stack_array_size];  //make calc array
   stack->next = temp;
   top_index = 0; 
   ++node_count;
  }
  top->calc[top_index].number = operation.number;
  top->calc[top_index].operation = operation.operation;
  ++top_index;
  return top_index;
}
/*
 * @author Harsukh Singh
 * @function peeks at the value at the top of the stack
 * @param takes a constant of a c_node struct instance
 * @return success or fail of integer value
 */
int stack::peek(c_node &operation)const
{
 int success = 0;
 if(top == NULL)
 {
  cout<<"Nothing to peek"<<endl;
  return 0; 
 }
 operation.number = top->calc[top_index].number;
 operation.operation = top->calc[top_index].operation;
 success = 1;
 return success;
}
/*
 * @author Harsukh Singh
 * @function pops c_node object off stack
 * @param void
 * @return success or fail of integer value
 */
int stack::pop()
{
 int success = 0;
 s_node* temp;
 if(top == NULL)
 {
  cout<<"Nothing to remove."<<endl;
  return success;
 }
 if(top_index == 0)
 {
    if(top->next == NULL)
    {
      delete[] top->calc;
      delete top;
      top_index = 0; 
    }
    else{
      temp = top;
      top = top->next;
      delete[] temp->calc;
      delete temp->next;
      delete temp;
      top_index = stack_array_size - 1;
    }
    return success;
 }
  top_index = top_index - 1;
  success = 1;
  return success;
}
/*
 * @author Harsukh Singh
 * @function display function for stack
 * @param void
 * @return success or fail of integer value
 */
int stack::display() const
{
  int success = 0;
  s_node* temp = top;
  if(top == NULL)
  {
    return success;
  }
  while(temp != NULL)
  {
    for(int i = 0; i<stack_array_size;++i){
      cout<<temp->calc[i].number<<endl;
      cout<<temp->calc[i].operation<<endl;
    }
    temp = temp->next;
  }
  success = 1;
  return success;
}
/*
 * @author Harsukh Singh
 * @function checks if stack is empty
 * @param void
 * @return success or fail of integer value
 */
int stack::is_empty()
{
 if(top == NULL)
 {
   return 1;
 }
 else{
  return 0; 
 }
}