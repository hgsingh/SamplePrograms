/********************
 *@author harsukh singh CS 202 assignment 2
 *@file classes.h contains prototypes for types of classes and bst node and binary tree
 * ******************/
#include "node.h"


/********************
 *@author harsukh singh CS 202 assignment 2
 *@class  gen_class inherits from node and stands for a generic class
 * contains the grade, course name and credit information. All the data that is associated with a a class type 
 * and the associated setter and getters
 * ******************/
class gen_class //: public node not used anymore
{
    protected:
        char* course_name; //course name
        float grade; //floating point value for grade
        int credits; //number of credits 
        gen_class* next; //next pointer for LLL
    public:
	gen_class(); //default constructor
        gen_class(const gen_class  &node_to_copy);
        gen_class(char* current_course, float course_grade, int course_credits); //constructor
        virtual void display(); //virtual display function
        void set_grade(float course_grade); //grade setter
        float get_grade(); //grade getter
        void set_course_name(char* current_course);//course setter
        char* get_course();//course getter
        int get_credits(); //credit getter
        void set_credits(int course_credits); //credit setter
        int check_string(char* guess, char* check); //strncmp
	gen_class* &get_next(); //getter for next
        void set_next(gen_class* next_ptr); //setter for next
        virtual ~gen_class(); //virtual destructor
};


/********************
 *@author harsukh singh CS 202 assignment 2
 *@class core class inherits from general class
 * ******************/
class core: public gen_class
{
  public:
    core();
    core(char* current_course, float course_grade, int course_credits);
    core(const core  &node_to_copy);
    ~core();
    void display();
  private:
};


/********************
 *@author harsukh singh
 *@class non core class inhertis from gen class
 * ******************/
class non_core: public gen_class
{
  public:
    non_core();
    non_core(char* current_course, float course_grade, int course_credits);
    non_core(const non_core  &node_to_copy);
    ~non_core();
    void display();
  private:
};


/********************
 *@author harsukh singh
 *@class required class is a list of requirements that are checked off as they are completed
 * ******************/
class required
{
    protected:
	gen_class* a_class; //head of the list
        int remove_all(gen_class* &a_class); // remove all from the list
	int insert_class(gen_class* &a_class, char* course_name, int credits, char type); //insert into the LLL
	int remove_class(gen_class* &a_class, char* course_name);//remove from list
        void display(gen_class * &a_class);//display a class in the list
    public:
	required();//constructor 
	~required(); //destructor
       	void make_list(); // make the list
        int remove_class(char* course_name);//remove class
        void display(); //display list
        bool is_empty();
};


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@class bst_node class represents one node in a binary search tree
 *the class contains LLL functions as well to work with gen_class
 * ******************/
class bst_node: public term
{
    public:
        bst_node(char* current_term, int courses, float term_gpa, int credits_to_add, int school_year);//constructor
        bst_node(const bst_node &node_to_copy); //copy constructor
        //int copy_node(bst_node * &node_to_copy); //copy node function
	bst_node(); //default constructor
        bst_node* &go_left(); //return left pointer
        bst_node* &go_right(); //return right pointer
	int val(); //hash for school term
        void connect_left(bst_node* connection); //connect left pointer
        void connect_right(bst_node* connection); //connect right pointer
        int remove_class(char* course_name);//remove class
	void update_values();
	int insert_class(char* course_name,float grade , int credits, char type); //insert into the LLL
	int map(char* school_term, int year); //hash for school term
        void display();//display list
        ~bst_node(); //destructor
    protected: //node data
	int insert_class(gen_class* &a_class, char* course_name, float grade, int credits, char type); //insert into the LLL
	int remove_class(gen_class* &a_class, char* course_name);//remove from list
       // int copy_course_list(gen_class * &copy_to);
	int update_values(gen_class* a_class);
        void display(gen_class * &a_class);//display a class in the list
        int remove_all(gen_class* &a_class); //removes everything from LLL
	int copy_course_list(gen_class * &copy_to, gen_class* copy_from); //copy list function
        gen_class* a_class;
        bst_node* left;
        bst_node* right;
};


/********************
 *@author harsukh singh
 *@binary tree class function prototypes
 * ******************/
class binary_tree
{
      public:
             binary_tree(); //binary tree constructor     			
             ~binary_tree();    //binary tree destructor
             void display_all();  //display all function
             void display_term(char* term, int year); //display for specific term
             int remove(char* term, int year); //remove node
             bst_node* retrieve(char* term, int year); //retrieve node
	     void insert(bst_node* &current);
      protected:
	     void insert(bst_node* &root, bst_node* &current); //insert function
             int remove(bst_node* &root, char* term, int year);
             void delete_all(bst_node * & root); //delete all used in destructor                
             void display_all(bst_node * root); //display all function using root 
             bst_node* &inorder_successor(bst_node* current); //find inorder successor here
             bst_node * root; //root of the tree                   
};

