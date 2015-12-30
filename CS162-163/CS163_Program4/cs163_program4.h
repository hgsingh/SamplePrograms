// @author harsukh singh
// @version 1 3/5/2015


#include <iostream>
#include <cstring>
#include <cctype>


/**
 *@author harsukh singh
 *struct object to hold oscar nominee name and number of votes
 */
struct oscar_node
{
  char* data;
  int vote;
};


/**
 *@author harsukh singh
 *binary node struct object that holds nominee object and pointers left and right 
 */
struct bst_node
{
  oscar_node* nominee;
  bst_node* left;
  bst_node* right;
};


/**
 *@author harsukh singh
 *Binary Search Tree ADT class with associated functions
 */
class bs_tree
{
  public:
    bs_tree(); //constructor
    ~bs_tree(); //destructor
    int remove_all(bst_node* &root); //removes everything from binary search tree
    int vote(char* nominee); // increments vote for a given nominee 
    int display_nominee(char* nominee);
    bst_node* find_nominee(bst_node* &root, char* nominee, bool ancestor); //finds a given nominee and returns a pointer object to the nominee
    int check_string(char* guess, char* check); //checks if a nominee exists
    int compare_nominees(char* nominee, char* data); //compares two nominees for alphabetical order
    int remove_nominee(bst_node* &root, char* nominee); //removes a nominee from a binary search tree
    int add_nominee(char* nominee, int &initial_vote);
    int add_nominee(bst_node* &root, char* nominee, int &initial_vote); //adds a nominee to a binary search tree
    int display_nominees(bst_node* &root); // displays entire binary search tree
    int display();
    bst_node* inorder_successor(bst_node* &current); // finds a inorder successor and returns a pointer to this object
    int remove_nominee(char* nominee); //wrapper function for remove
  private:
    bst_node* root; //root of the binary search tree
};
