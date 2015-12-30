//author harsukh singh
#include <iostream> //used for input and output
#include <cctype> //used for character identification
#include <cstring> //string operations
#include <cstdlib> //atoi?
const int stack_array_size = 10; //maximum size of each c_node array
/**
 * @ author: Harsukh Singh
 * @ operation struct, members hold a number of double type and character of an operation
 */
struct c_node 
{
  double number;
  char operation;
};
struct node
{
  c_node* calc;
  node* next;
};
/**
 * @ author: Harsukh Singh
 * @ queue node struct for creating a circular linked list of queue nodes 
 */
struct q_node
{
  c_node* calc;
  q_node* next;
};
/**
 * @ author: Harsukh Singh
 * @ stack struct holds an array of c_nodes 
 */
struct s_node
{
  c_node* calc;
  s_node* next;
};
 
class queue //first in first out
{
  public:
    int enqueue(const c_node &operation);
    int dequeue(c_node &operation);
    int display() const;
  private:
    q_node* rear = NULL;

};
class stack //first in last out
{
  public:
    stack();
    int push(const c_node &operation, int &node_count);
    int pop();  
    int peek(c_node &operation)const;
    int display() const;
    int is_empty();
  private:
    int top_index;
    s_node* top = NULL;
};
class calculator
{
  public:
    calculator();
    //int add(double value);
    //int subtract(double value);
    //int multiply(double value);
    //int divide(double value);
    int calculate(int &node_count);
    int last_operation(c_node &operation);
    int undo(int number); 
    int undo(c_node &operation);
    int view_history();
    int populate(char* string, int &node_count); //populates stack and queue
  private:
    stack s_object;
    queue q_object;
    double current_total;
};
