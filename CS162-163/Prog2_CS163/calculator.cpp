#include "cs163_program2.h"
using namespace std;
/*
 * @author Harsukh Singh
 * @function constructor of function, initializes current total to zero
 * @param void
 * @return imiplicitly makes a class object on stack
 */
calculator::calculator()
{
 current_total = 0; 
}

/*
 * @author Harsukh Singh
 * @function performs addition
 * @param a number of a double type
 * @return current total 
 *
int add(double number)
{
 current_total = current_total + number; 
 return current_total;
}
/*
 * @author Harsukh Singh
 * @function performs subtraction
 * @param a number of a double type
 * @return current total 
 *
int subtract(double number)
{
 current_total = current_total - number;
 return current_total;
}
/*
 * @author Harsukh Singh
 * @function performs division
 * @param a number of a double type
 * @return current total 
 *
int divide(double number)
{
 current_total = current_total/number;
 return current_total;
}
/*
 * @author Harsukh Singh
 * @function performs multiplication
 * @param a number of a double type
 * @return current total 
 *
int multiply(double number)
{
  current_total = current_total*number;
  return current_total;
}*/
/*
 * @author Harsukh Singh
 * @function performs requested calculations taking in count the precedence
 * @param void
 * @return success or fail of integer value
 */
int calculator::calculate(int &node_count) //precedence is solved using look ahead
{ 
  //stack is set now pop
  node* head = NULL;
  node* temp = head;
  node* current = head;
  int j = 0;
  while(s_object.is_empty() == 0)
  {
    node* new_node = new node;
    s_object.peek(*(new_node->calc));
    s_object.pop();
    if(head == NULL)
    { 
      head = new_node;
      head->next = NULL;
    } 
    else{
      head = new_node;
      head ->next = temp;
    }
  }
  temp = current;
  while(current -> next != NULL)
  {
    if(current->calc->operation == '*') 
    {    
      node* delete_pointer = current;
      temp->calc->number = temp->calc->number * delete_pointer->calc->number;
      current = current->next;
      temp->next = current ->next;
      delete_pointer ->next = NULL;
      delete delete_pointer->calc;
      delete delete_pointer->next;
      delete delete_pointer;
    }
    if(current->calc->operation == '/')
    {
      node* delete_pointer = current;
      temp ->calc->number = temp->calc->number / delete_pointer->calc->number;
      temp->next = current ->next;
      delete_pointer ->next = NULL;
      delete delete_pointer->calc;
      delete delete_pointer->next;
      delete delete_pointer;
 
    }
    else{
       temp = current;
       current = current ->next;
    }
  }
  while(current -> next != NULL)
  {
    if(current->calc->operation == '+') 
    {    
      node* delete_pointer = current;
      temp->calc->number = temp->calc->number + delete_pointer->calc->number;
      current = current->next;
      temp->next = current ->next;
      delete_pointer ->next = NULL;
      delete delete_pointer->calc;
      delete delete_pointer->next;
      delete delete_pointer;
    }
    if(current->calc->operation == '-')
    {
      node* delete_pointer = current;
      temp ->calc->number = temp->calc->number - delete_pointer->calc->number;
      temp->next = current ->next;
      delete_pointer ->next = NULL;
      delete delete_pointer->calc;
      delete delete_pointer->next;
      delete delete_pointer;
 
    }
    else{
       temp = current;
       current = current ->next;
    }
  }
  /*
  while(s_object.is_empty() ==0)
  {
    c_node* temp;
    s_object.pop(temp);
    if(temp.operation == '+')
    {
      add(temp.number);
    }
    if(temp.operation == '-')
    {
     subtract(temp.number); 
    }
    if(temp.operation == '*')
    {
     multiply(temp.number); 
    }
    if(temp.operation == '/')
    {
      divide(temp.number);
    }
  }
  */
  return head->calc->number;
}
/*
 * @author Harsukh Singh
 * @function populates stack and queue
 * @param takes the input from user
 * @return success or fail of integer value
 */
int calculator::populate(char string[], int &node_count) //begin populate function 
{
  int length = (unsigned) strlen(string) + 1;
  char* temp = new char[length];
  //cout<<length<<endl;
  int j = 0;
  for(int i = 0; i<length; ++i)
  {
    if(string[i] != ' ')
    {
      temp[j] = string[i];
      j++;
    }
  }
  temp[j] = '\0';
  //cout<<temp[j]<<' ' <<j <<endl; //gets here okay
  for(int i =0; temp[i] != '\0'; i++)
  {
    if(i == 0 && isdigit(temp[i]))
    {
      int k = 0;
      char* number = new char[32];
      while(isdigit(temp[k+i]))
      {
	number[k] = temp[k+i];
	//cout<<number[i]<<endl;
	k++;
      }
      c_node computation;
      computation.number = atoi(number);
      computation.operation = '+';
      q_object.enqueue(computation);  //call global queue object and call the enqueue function
      s_object.push(computation, node_count);   //call push function from stack object
      delete[] number;
    }
    if(temp[i] == '+' || temp[i] == '-' || temp[i] == '/' || temp[i] == '*' && i != 0)  
    {
        if(isdigit(temp[i+1]))//check if the char before is a number
        {
           c_node computation;
           int count = 0;
           int k = 0;
           while(isdigit(temp[i+1+count])) //counts the number of digit chars
           {
              ++count;
           }
           char* number = new char[count];
           while(isdigit(temp[i+1]) && k <= count)
           {
              number[k] =temp[i+1+k];
              ++k;
           }
           computation.number = atoi(number);
           computation.operation = temp[i];
           q_object.enqueue(computation);  //call global queue object and call the enqueue function
           s_object.push(computation, node_count);   //call push function from stack object
           delete[] number;
        }      
    }
  }
  delete[] temp;
  return 1;
}
/*
 * @author Harsukh Singh
 * @function pops nodes off stack for a set number of times
 * @param takes a number
 * @return success or fail of integer value
 */
int calculator::undo(int number) //only pop from stack never dequeue
{
  c_node temp;
  for(int i = 0; i<number; ++i)
  {
    s_object.peek(temp);
    temp.operation = 'u';
    q_object.enqueue(temp);
    s_object.pop();
  }
  return 1;
}
/*
 * @author Harsukh Singh
 * @function pops nodes off stack until matching node is found 
 * @param takes a constant of a c_node struct instance
 * @return success or fail of integer value
 */
int calculator::undo(c_node &operation) //see above
{
  c_node temp;
  int success = 0;
  s_object.peek(temp);
  if(temp.operation != operation.operation && temp.number != operation.number) 
  {  while(temp.operation != operation.operation && temp.number != operation.number)
    {
      temp.operation = 'u';
      q_object.enqueue(temp);
      s_object.pop();
      s_object.peek(temp);
    } 
  }
  else{
      s_object.peek(temp);
      temp.operation = 'u';
      q_object.enqueue(temp);
      s_object.pop();  
      success = 1;
  }
  return success;    
}
/*
 * @author Harsukh Singh
 * @function views all history of operations, i.e. view queue
 * @param void
 * @return success or fail of integer value
 */
int calculator::view_history()
{
 int success = q_object.display();
  return success;
}
/*
 * @author Harsukh Singh
 * @function returns last operation, i.e., peek at stack
 * @param takes a constant of a c_node struct instance
 * @return success or fail of integer value
 */
int calculator::last_operation(c_node &operation)
{
  int success =s_object.peek(operation);
  if(success == 1)
  {
    cout<<operation.operation<<endl;
    cout<<operation.number<<endl;
  }
  return success;
}
