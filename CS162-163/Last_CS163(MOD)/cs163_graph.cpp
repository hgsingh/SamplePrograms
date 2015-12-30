//@author harsukh singh
#include "cs163_graph.h"
using namespace std;


/**
 * @author harsukh singh
 * @function non-default constructor
 * @params size of table to implement
 * @return void
 */
table::table(int size)
{
    //Allocate the adjacency list and set each
    //head pointer to NULL
    list_size = size;
    adjacency_list = new vertex[list_size];
    for(int i = 0; i<list_size;++i)
    {
        adjacency_list[i].head = NULL;
	adjacency_list[i].visited = false;
        adjacency_list[i].destination = NULL;
    }   
}


/**
 * @author harsukh singh
 * @function Destructor for table
 * @params void
 * @return void
 */
table::~table()
{
    for(int i = 0; i<list_size; ++i)
    {
	if(adjacency_list[i].head != NULL)
	{
	    remove_list(adjacency_list[i].head);
	}
	if(adjacency_list[i].destination != NULL)
	{
	    delete[] adjacency_list[i].destination;
	}
    }
    delete[] adjacency_list;
}


/**
 * @author harsukh singh
 * @function Recursively removes from a linear linked list
 * @params node* current
 * @return 1 if removed 0 if not current
 */
int table::remove_list(node* current)
{
    if(!current) return 0;
    remove_list(current->next);
    delete current;
    current = NULL;
    return 1;
}


/**
 * @author harsukh singh
 * @function Stores the vertex at this location given that char* destination is NULL
 * @params char* to_insert
 * @return 1 if inserted or 0 as a false boolean when full
 */
int table::insert_vertex(char* to_insert)
{
    for(int i = 0; i<list_size; ++i)
    {
        if(adjacency_list[i].destination == NULL)
        {
            adjacency_list[i].destination = new char[strlen(to_insert) + 1];
            strcpy(adjacency_list[i].destination, to_insert);
            return 1;
        }
    }
    //not full here
    return 0;
}


/**
 * @author harsukh singh
 * @function Attach an edge to a vertex
 * @params char* current_vertex, char* to_attach
 * @return 1 if inserted or 0 as a false boolean when to_attach is not found
 */
int table::insert_edge(char * current_vertex, char * to_attach)
{
    int index = find_location(current_vertex);
    int k = find_location(to_attach);
    if(k == -1) return 0;
    if(index == -1) return 0;
    node* new_node = new node;
    new_node -> next = NULL;
    new_node -> adjacent = &adjacency_list[k];
    if(adjacency_list[index].head == NULL)
    {
        adjacency_list[index].head = new_node;
        return 1;
    }
    node* current = adjacency_list[index].head;
    adjacency_list[index].head = new_node;
    new_node -> next = current;
    return 1;
}


/**
 * @author harsukh singh
 * @function Display all vertices leading to desired destination
 * @params char* key of location of starting position and char* to find destination 
 * @return 0 or 1
 */
int table::depth_first(char* current_vertex, char* to_find)
{
    int index = find_location(current_vertex);
    int k = find_location(to_find);
    if(index == -1) return 0;
    if(k == -1) return 0;
    node* current = adjacency_list[index].head;
    adjacency_list[index].visited = true;//visit node
    cout<<"Starting from "<< adjacency_list[index].destination<<"."<<endl;
    if(check_string(current_vertex, to_find) == 1) return 1;
    while(current)
    {
        if(current->adjacent->visited == false)
        {
            if (depth_first(current -> adjacent->destination, to_find) == 1)
                return 1;
        }
        current = current -> next;
    }
    return 0;
}


/**
 * @author harsukh singh
 * @function Display all vertices adjacent to the one specified
 * @params char* key of location 
 * @return 0 or 1
 */
int table::display_adjacent(char * key_value)
{
   int index = find_location(key_value);
   if(index == -1 ) return 0;
   node* current = adjacency_list[index].head;
   while(current)
   {
        cout<<current->adjacent->destination<<endl;
        current = current -> next;
   }
   return 1;
}


/**
 * @author harsukh singh
 * @function finds a location in the graph given char* key
 * @params char* key of location 
 * @return the index if found or -1 as a false boolean
 */
int table::find_location(char * key_value)
{
    for(int i = 0; i<list_size;++i)
    {
        if(check_string(key_value, adjacency_list[i].destination) == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * @author harsukh singh
 * @function displays all vertices
 * @params void
 * @return void
 */
void table::display_all()
{
    for(int i = 0; i<list_size; ++i)
    {
        if(adjacency_list[i].destination != NULL)
        {
	    cout<<adjacency_list[i].destination<<endl;
        }
    } 
}


/**
 * @author harsukh singh
 * @function checks a nominee and another array to see if they are the same
 * @parameter a character array of key to check against another array called check
 * @return returns success which is 1 or 0
 */
int table::check_string(char* guess, char* check)
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
