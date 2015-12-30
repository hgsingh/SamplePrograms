//@author harsukh singh
//Implementation of binary search tree ADT


#include "cs163_program4.h"
using namespace std;


/**
 * @author harsukh singh
 * @function constructor, sets root to null
 * @parameters void
 * @return void
 */
bs_tree::bs_tree()
{
    root = NULL;
}


/**
 * @author harsukh singh
 * @function destructor, deallocates memory for binary tree through the remove all function
 * @parameters void
 * @return void
 */
bs_tree::~bs_tree()
{
    remove_all(root);    
}


/**
 * @author harsukh singh
 * @function remove all function, recursively deletes all of the nodes in a binary tree
 * @parameters the reference to the root node
 * @return void
 */
int bs_tree::remove_all(bst_node* &root)
{
    if(root == NULL) return 0; //empty list
    if(root)
    {
        remove_all(root->right) + remove_all(root->left);
        delete[] root->nominee->data;
	root->nominee->vote = 0;
        delete root->nominee;
        delete root;
	root = NULL;
	return 1;
    }
}


/**
 * @author harsukh singh
 * @function compares nominees and data in alphabetical order 
 * @parameters dynamic array for nominee and data
 * @return 1,0,-1  for left or right ... duplicate nominees aren't allowed
 */
int bs_tree::compare_nominees(char* nominee, char* data)
{
    for(int i = 0; i<(unsigned)strlen(nominee) && i<=(unsigned)strlen(data); ++i)
    {
        nominee[i] = tolower(nominee[i]);
        data[i] = tolower(data[i]);
        if(nominee[i] < data[i])
        {
            return -1;
        }
        if(nominee[i] > data[i])
        {
            return 1;
        }
    }
    if(((unsigned) strlen(nominee) == (unsigned) strlen(data)) && check_string(nominee, data) == 1) return 0;
    if((unsigned) strlen(nominee) > (unsigned) strlen(data)) return 1;
    return -1;
}

/**
 * @author harsukh singh
 * @function finds a nominee and traverses based on data provided
 * @parameters  character array of nominee
 * @return returns 1 or 0
 */
int bs_tree::display_nominee(char* nominee)
{
    bst_node* current = find_nominee(root, nominee, false);
    if(!current) return 0;
    cout<<current->nominee->data<<endl;
    cout<<current->nominee->vote<<endl;
    return 1;
}

/**
 * @author harsukh singh
 * @function finds a nominee and traverses based on data provided
 * @parameters root node as a reference, character array of nominee, boolean ancestor parameter (true when parent is needed)
 * @return returns the nominee or parent depending on the ancestor value
 */
bst_node* bs_tree::find_nominee(bst_node* &root, char* nominee, bool ancestor)
{
    if(root == NULL) return root; //no tree bro
    if(ancestor == true && ((root -> right && compare_nominees(nominee, root->right->nominee->data) == 0 )|| (root -> left && compare_nominees(nominee, root->left->nominee->data) == 0)) )
    {
        bst_node* parent = root;
        return parent;
    }
    if(compare_nominees(nominee, root->nominee->data) == -1) //go left bro
    {
        return find_nominee(root-> left, nominee, ancestor);
    }
    if(compare_nominees(nominee, root->nominee->data) == 1) //go right bro
    {
        return find_nominee(root->right, nominee, ancestor);
    }
    if((compare_nominees(nominee, root->nominee->data) == 0) && ancestor == false)
    {
        bst_node* current = root;
        return current;
    }

}


/**
 * @author harsukh singh
 * @function increments vote for a particular nominee
 * @parameter character array of nominee
 * @return 0 or the vote value
 */
int bs_tree::vote(char* nominee)
{
    bst_node* current = find_nominee(root, nominee, false);
    if(!current) return 0; //nominee not found
    int this_vote = current->nominee->vote;
    ++this_vote;
    current->nominee->vote = this_vote;
    return this_vote;
}


/**
 *@author harsukh singh
 *@function wrapper function for display
 *@parameters void
 *@return the function was wrapped
 */
int bs_tree::display()
{
    return display_nominees(root);
}

/**
 * @author harsukh singh
 * @function displays all nominees in a binary tree in-order (alphabetically)
 * @parameter root node
 * @return 1 or 0
 */
int bs_tree::display_nominees(bst_node* &root)
{
    if(root == NULL) return 0;//empty bro
    display_nominees(root->left);
    cout<<root->nominee->data<<endl;
    cout<<root->nominee->vote<<endl;
    display_nominees(root->right);
    return 1;
}


/**
 *@author harsukh singh
 *@function wrapper function for add function
 *@param char* nominee and int of votes
 *@return function that was wrapped
 */
int bs_tree::add_nominee(char* nominee, int &initial_vote)
{
    return add_nominee(root, nominee, initial_vote);
}


/**
 * @author harsukh singh
 * @function adds nominee to end of binary tree
 * @parameter root node and character array of a nominee
 * @return 1 if successfull in add, 0 if duplicate is found
 */
int bs_tree::add_nominee(bst_node* &root, char* nominee, int &initial_vote)
{ 
  
    if(root == NULL) 
    {  
        bst_node* node = new bst_node;
        node -> left = NULL;
        node -> right = NULL;
        int length = strlen(nominee) + 1;
        node -> nominee = new oscar_node;
        node -> nominee-> data = new char[length];
        node -> nominee -> vote = initial_vote;
        strcpy(node->nominee->data, nominee);
        root = node;
        return 1;
    }
    if(compare_nominees(nominee, root->nominee->data) == 1)
    {
        return add_nominee(root->right, nominee, initial_vote);
    }
    if(compare_nominees(nominee, root->nominee->data) == -1)
    {
        return add_nominee(root->left, nominee, initial_vote);
    }
    if(compare_nominees(nominee, root->nominee->data) == 0)
    {
        return 0;
    }
}


/**
 *@author harsukh singh
 *@function wrapper for remove function
 *@params character array of nominee
 *@return remove function
 */
int bs_tree::remove_nominee(char* nominee)
{
    return remove_nominee(root, nominee); 
}


/**
 * @author harsukh singh
 * @function removes a nominee node
 * @parameter root node and character array of a nominee
 * @return 1 or 0 depending on value of current
 */
int bs_tree::remove_nominee(bst_node* &root, char* nominee)
{
    bst_node* current = find_nominee(root, nominee, false);
    bst_node* parent = find_nominee(root, nominee, true);
    if(!current) return 0;
    if(!current->right && !current->left) // leaf found
    {
	if (parent && parent->left == current) parent-> left = NULL;
	if (parent && parent->right == current) parent-> right = NULL;
        delete[] current->nominee->data;
        delete current->nominee;
        delete current;
        current = NULL;
	if (!parent)
	  root = NULL;
	return 1;
    }
    if(!current->right && current->left)
    { 
        if (!parent)
	{
	    root = current->left;
	    delete[] current->nominee->data;
            delete current->nominee;
            delete current;
            current = NULL;
	    return 1;
	    
	}
	if(parent &&  parent->right && compare_nominees(nominee, parent->right->nominee->data) == 0) // right child
	{
	    parent->right = current -> left;
            delete[] current->nominee->data;
            delete current->nominee;
            delete current;
            current = NULL;
	    return 1;

	}
	if(parent && parent->left && compare_nominees(nominee, parent->left->nominee->data) == 0) // left child
	{
	    parent-> left = current -> left;
            delete[] current->nominee->data;
            delete current->nominee;
            delete current;
            current = NULL;
	    return 1;
	}
	
    }
    if(!current->left && current -> right)
    {
	if (!parent) 
	{
	    root = current->right;
	    delete[] current->nominee->data;
            delete current->nominee;
            delete current;
            current = NULL;
	    return 1;
	}
	if(parent && parent->right && compare_nominees(nominee, parent->right->nominee->data) == 0) // right child
	{
	    parent-> right = current -> right;
            delete[] current->nominee->data;
            delete current->nominee;
            delete current;
            current = NULL;
	    return 1;
  
	}
	if(parent && parent->left && compare_nominees(nominee, parent->left->nominee->data) == 0) // left child
	{
	    parent-> left = current -> right;
            delete[] current->nominee->data;
            delete current->nominee;
            delete current;
            current = NULL;
	    return 1;

	}
    }
    if(current->left && current->right)
    {
        bst_node* successor = inorder_successor(current);
	bst_node* successor_parent = find_nominee(root, successor->nominee->data, true);
	if(successor -> right && successor_parent && successor_parent -> left && compare_nominees(successor_parent -> left->nominee -> data,  successor->nominee->data) == 0)
	{
	    successor_parent -> left = successor -> right;
	    successor -> right = NULL;
	}
        delete[] current-> nominee -> data;
        current -> nominee -> data = new char[strlen(successor->nominee->data)+1];
        current ->nominee ->vote = successor -> nominee -> vote;
        strcpy(current->nominee->data, successor->nominee->data);
	if(!parent)
	{
	    root = current;
	}
	if(!successor -> right && compare_nominees(current->right->nominee->data, successor -> nominee -> data ) == 0) current->right = NULL; 
	else
	{
	    if(successor -> right && (compare_nominees(current -> right -> nominee -> data, successor -> nominee -> data) == 0))
	    {
		current -> right = successor -> right;
		successor -> right = NULL;
	    }
	}
        delete[] successor->nominee->data;
        delete successor->nominee;
        delete successor;
        successor = NULL;
	return 1;
  
    }
}


/**
 *@author harsukh singh
 *@function gets the inorder succesor
 *@parameter current pointer to node that is to removed
 *@return pointer of node type to the inorder successor
 */
bst_node* bs_tree::inorder_successor(bst_node* &current)
{
    if(!current) return NULL;
    if(!current->right) return NULL;
    if(current->right) 
    {
        bst_node* temp = current -> right;
        while(temp->left)
        {
            temp = temp ->left; // go to the leftmost node
        }
        return temp;
    }
}


/**
 * @author harsukh singh
 * @function checks a nominee and another array to see if they are the same
 * @parameter a character array of key to check against another array called check
 * @return returns success which is 1 or 0
 */
int bs_tree::check_string(char* guess, char* check)
{
    char* comp1;
    char* comp2;
    int success = 0;
    int length = 0;
    char* temp_guess = new char[(unsigned) strlen(guess) + 1];
    char* temp_check = new char[(unsigned) strlen(check) + 1];
    for(unsigned int i = 0; i<(unsigned) strlen(guess); ++i)
    {
        if(guess[i] != ' ')
        {
            temp_guess[length] = tolower(guess[i]);
            ++length;
        }
    }
    temp_guess[length] = '\0';
    length = 0;
    for(unsigned int j = 0; j<(unsigned) strlen(check); ++j){
        
        if(check[j] != ' ')
        {
            temp_check[length] = tolower(check[j]);
            ++length;
        }
    }
    temp_check[length] = '\0';
    length = 0;
    for(unsigned int k = 0; k<(unsigned)strlen(temp_check); ++k)
    {
        if(temp_check[k] == temp_guess[0])
        { 
            int count = 0;
            comp1 = &temp_check[k];
            comp2 = &temp_guess[0];
            while(*comp1 == *comp2)
            {
                comp1 = comp1 +1;
                comp2 = comp2 +1;
                count = count + 1;
                if(count == ( unsigned) strlen(guess)){
                    success = 1;
                    delete[] temp_check;
                    delete[] temp_guess;
                    return success;
                } 
            } 
        }
    }
    delete[] temp_check;
    delete[] temp_guess;
    return success;
}
