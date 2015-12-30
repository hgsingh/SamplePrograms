#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL
    list_size = size;
    adjacency_list = new vertex[list_size];
    for(int i = 0; i<list_size;++i)
    {
        adjacency_list[i].head = NULL;
        adjacency_list[i].entry = NULL;
    }   
    

}

//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{

    for(int i = 0; i<list_size; ++i)
    {
        if(adjacency_list[i].entry == NULL)
        {
            adjacency_list[i].entry = new journal_entry;
            adjacency_list[i].entry->copy_entry(to_add);
            return 1;
        }
    }
    //not full here
    return 0;
}

//Attach an edge to a vertex
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
}

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{
   int index = find_location(key_value);
   if(index == -1 ) return 0;
   node* current = adjacency_list[index].head;
   while(current)
   {
        current->adjacent->entry->display();
        current = current -> next;
   }
}

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{
    for(int i = 0; i<list_size;++i)
    {
        if(adjacency_list[i].entry->compare(key_value) == true)
        {
            return i;
        }
    }
    return -1;
}


