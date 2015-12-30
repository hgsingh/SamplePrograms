/***********
 * @author harsukh singh CS 202 Assignment 2
 *@file pertains to implementations of binary tree and bst_node functions
 * *********/
#include "classes.h"
using namespace std;

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function bst node constructor
 *@args term data that is pushed into the term class in the heirarchy
 *@return void
 ************/
bst_node::bst_node(char* current_term, int courses, float term_gpa, int credits_to_add, int school_year):left(0), right(0), a_class(0), term(current_term, courses, term_gpa, credits_to_add, school_year)
{
}


/*************
 *@author harsukh singh CS202 Assignment 2
 *@function default constructor with no term data
 *@args void 
 *@return void
 ************/
bst_node::bst_node():left(0), right(0), a_class(0)
{
}


/*************
 *@author harsukh singh CS202 Assignment 2
 *@function returns the left pointer in the bst node
 *@args void
 *@return bst_node pointer
 ************/
bst_node*& bst_node::go_left()
{
    return left;
}


/*************
 *@author harsukh singh CS202 Assignment 2
 *@function return right pointer of bst node
 *@args void
 *@return bst_node pointer
 ************/
bst_node*& bst_node::go_right()
{
    return right;
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function maps a value to the bst node of int type based on year and school term
 *@args char* and int
 *@return int of value
 ************/
int bst_node::map(char* school_term, int year)
{
    int sum  = 0;
    if(!school_term) return -1;
    for(int i = 0; i<strlen(school_term); ++i)
    {
        sum += school_term[i];
    }
    return (year % sum);
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function wrapper for map
 *@args void
 *@return int
 ************/
int bst_node::val()
{
    return map(school_term, year);
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function connects left pointer 
 *@args a connection of bst_node type
 *@return void
 ************/
void bst_node::connect_left(bst_node* connection)
{
    left = connection;
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function connects right pointer 
 *@args connection of bst_node type
 *@return void
 ************/
void bst_node::connect_right(bst_node* connection)
{
    right = connection;
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function removes a node in the LLL
 *@args char* and head of the list
 *@return 0 or 1 based on success
 ************/
int bst_node::remove_class(gen_class* &a_class, char* course_name)
{
    if(!a_class) return 0;
    if(!course_name) return 0;
    if(a_class->check_string(course_name, a_class->get_course()) == 1)
    {
        gen_class* temp = a_class;
        a_class = (gen_class *)a_class->get_next();
        delete temp;
        return 1;
    }
    return remove_class( (gen_class *&)a_class->get_next(), course_name);
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function wrapper for remove node
 *@args char* 
 *@return 0 or 1 based on success
 ************/
int bst_node::remove_class(char* course_name)
{
    return remove_class(a_class, course_name);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display list
 *@args class head 
 *@return void
 * ******************/
void bst_node::display(gen_class * &a_class)
{
    if(!a_class) return;
    a_class -> display();
    display((gen_class * &)a_class->get_next());
    return;
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display wrapper
 *@args void
 *@return void
 * ******************/
void bst_node::display()
{
    cout<<school_term<<endl;
    cout<<num_courses<<endl;
    cout<<gpa<<endl;
    cout<<credits<<endl;
    cout<<year<<endl;
    display(a_class);
}


/*************
 *@author harsukh singh CS202 Assignment 2
 *@function wrapper for insert into LLL
 *@args course data
 *@return 1 or 0 depending on success
 ************/
int bst_node::insert_class( char* course_name,float grade,  int credits, char type)
{
    return insert_class(a_class, course_name, grade, credits, type);
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function insert function into LLL
 *@args course data and head pointer
 *@return 1 or 0 depending on success
 ************/
int bst_node::insert_class(gen_class* &a_class, char* course_name, float grade,int credits, char type)
{
    if(!a_class)
    {
        if(type == 'n')
        {
            a_class = new non_core(course_name, grade, credits);
            return 1;
        }
        if(type == 'c')
        {
            a_class = new core(course_name, grade, credits);
            return 1;
        }
        if(type == 'g')
        {
            a_class = new gen_class(course_name, grade, credits);
        }
        else{
            return 0;
        }
    }
    gen_class* temp = a_class;
    if(type == 'n')
    {
        a_class = new non_core(course_name, grade, credits);
        a_class->set_next(temp);
        return 1;
    }
    if(type == 'c')
    {
        a_class = new core(course_name, grade, credits);
        a_class->set_next(temp);
        return 1;
    }
    if(type == 'g')
    {
        a_class = new gen_class(course_name, grade, credits);
        a_class->set_next(temp);
        return 1;
    }
    else{
        return 0;
    }
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function destructor 
 *@args void
 *@return void
 ************/
bst_node::~bst_node()
{
    remove_all(a_class);
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function copy constructor 
 *@args node to copy
 *@return void
 ************/
bst_node::bst_node(const bst_node  &to_copy): term(to_copy)
{
    copy_course_list(a_class, to_copy.a_class);
}

/*
function not used anymore
*************
 *@author harsukh singh CS202 Assignment 2
 *@function root and copy node function 
 *@args node to copy
 *@return int 1
 ************
int bst_node::copy_node(bst_node * &node_to_copy)
{
    if(!node_to_copy) return 0;
    remove_all(a_class);
    //copy stuff here
    set_credits(node_to_copy->get_credits());
    set_year(node_to_copy->get_year());
    set_num_courses(node_to_copy->get_num_courses());
    set_gpa(node_to_copy->get_gpa());
    set_term(node_to_copy->get_term());
    node_to_copy -> copy_course_list(a_class);
    return 1;
}


*************
 *@author harsukh singh CS202 Assignment 2
 *@function copy list function 
 *@args node of LLL
 *@return wrapper function
 ************
int bst_node::copy_course_list(gen_class * &copy_to)
{
    return copy_course_list(copy_to, const a_class);   
}
*/


/*************
 *@author harsukh singh CS202 Assignment 2
 *@function updates values of variables like gpa, num courses and credits
 *@args void
 *@return void
 ************/
void bst_node::update_values()
{
    update_values(a_class);
    gpa = gpa/num_courses;
    //cout<<"this terms gpa is "<<gpa<<endl;
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function updates values of variables like gpa, num courses and credits
 *@args head of list
 *@return 1 or 0 depending on success
 ************/
int bst_node::update_values(gen_class* a_class)
{
    if(!a_class) return 0;
    ++num_courses;
    credits = a_class->get_credits() + credits;
    float temp = a_class->get_grade();
    int check = ceil(temp);
    if(check >=  95 && check < 101)
    {
	gpa = gpa + 4.0;
    }
    else if(check >=  90 && check < 95)
    {
	gpa = gpa + 3.7;
    }
    else if(check >=  85 && check < 90)
    {
	gpa = gpa + 3.3;
    }
    else if(check >=  80 && check < 85)
    {
	gpa = gpa + 3.0;
    }
    else if(check >=  75 && check < 80)
    {
	gpa = gpa + 2.7;
    }
    else if(check >=  70 && check < 75)
    {
	gpa = gpa + 2.3;
    }
    else if(check >=  65 && check < 70)
    {
	gpa = gpa + 2.0;
    }
    else if(check >=  60 && check < 65)
    {
	gpa = gpa + 1.7;
    }
    else if(check >=  55 && check < 60)
    {
	gpa = gpa + 1.3;
    }
    else if(check >=  50 && check < 55)
    {
	gpa = gpa + 1.0;
    }
    else{
	gpa = gpa + 0;
    }
    return update_values((gen_class*)a_class->get_next());
}

/*************
 *@author harsukh singh CS202 Assignment 2
 *@function copy list function 
 *@args node of LLL
 *@return 1
 ************/
int bst_node::copy_course_list(gen_class * &copy_to,  gen_class* copy_from)
{
    if(!copy_from) 
    {
        copy_to = NULL;
        return 1;
    }
    //copy stuff here
    copy_to = new gen_class(*copy_from);
    return copy_course_list(copy_to -> get_next(),copy_from->get_next());   
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function remove all function for destructor
 *@args head
 *@return 1 or 0 based on success
 * ******************/
int bst_node::remove_all(gen_class* &a_class)
{
    if(!a_class) return 0;
    remove_all((gen_class *&)a_class->get_next());
    delete a_class;
    return 1;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function constructor
 *@args void
 *@return void
 * ******************/
binary_tree:: binary_tree()
{
    root = NULL;
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function remove all function for destructor wrapper
 *@args void
 *@return void
 * ******************/
binary_tree:: ~binary_tree()
{
    delete_all(root);
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function remove all function for destructor
 *@args root of bst
 *@return void
 * ******************/
void binary_tree::delete_all(bst_node * & root)
{
    if(root == NULL) return; //empty list
    if(root)
    {
        delete_all(root->go_left());
	delete_all(root->go_right());
        delete root;
	root = NULL;
	return;
    }
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display all function wrapper
 *@args void
 *@return void
 * ******************/
void binary_tree::display_all()
{
    display_all(root);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display all function 
 *@args root of bst
 *@return void
 * ******************/
void binary_tree::display_all(bst_node * root)
{
	if(!root) return;
	root->display();
	display_all(root->go_left());
	display_all(root->go_right());
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function removes a term from a binary tree wrapper
 *@args char* term and the year to remove
 *@return void
 * ******************/
int binary_tree::remove(char* term, int year)
{
   return remove(root, term, year);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function removes a term from binary tree
 *@args char* term and the year to remove and root
 *@return void
 * ******************/
int binary_tree::remove(bst_node* &root, char* term, int year)
{
    if(!root) return 0;
    if(strcmp(root->get_term(), term) == 0 && root->get_year() == year) 
    {
        if(!root->go_right() && root->go_left())
        {
            bst_node* temp = root;
            root = root-> go_left();
            delete temp;
            return 1;
        }
        if(!root->go_left() && root->go_right())
        {
            bst_node* temp = root;
            root = root -> go_right();
            delete temp;
            return 1;
        }
        if(!root->go_right() && !root->go_left())
        {
            delete root;
            root =  NULL;
            return 1;
        }
        if(root->go_right() && root->go_left())
        {
            bst_node* successor = inorder_successor(root);
            bst_node* temp = root;
            bst_node* left = root -> go_left();
            bst_node* right = root -> go_right();
            root = new bst_node(*successor);
            root->connect_left(left);
            root->connect_right(right);
            delete temp;
            return remove(successor, successor->get_term(), successor->get_year());
        }
    }
    else if(root->val() > root->map(term, year))
    {
	return remove(root->go_left(), term, year);
    }
    else{
	return remove(root->go_right(), term, year);
    }
    cout<<"Nothing to remove."<<endl;
    return 0;
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function insert into tree
 *@args root of bst and current to insert
 *@return void
 * ******************/
void binary_tree::insert(bst_node* &current)
{
    insert(root, current);
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function insert into tree
 *@args root of bst and current to insert
 *@return void
 * ******************/
void binary_tree::insert(bst_node* &root, bst_node* &current)
{
    if(!root)
    {
	root = current;
    }
    else if(root->val() > current->val())
    {
	return insert(root->go_left(), current);
    }
    else{
	return insert(root->go_right(), current);
    }
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function inorder successor finder 
 *@args bst_node current
 *@return bst_node
 * ******************/
bst_node* &binary_tree::inorder_successor(bst_node* current)
{
    if(!current) return current;
    if(!current->go_right()) return current;
    else 
    {
        bst_node* temp = current -> go_right();
        while(temp->go_left())
        {
            temp = temp ->go_left(); // go to the leftmost node
        }
        return temp;
    }
}

