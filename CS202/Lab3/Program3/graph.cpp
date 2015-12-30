#include "table.h"
using namespace std;


//@author harsukh singh

/**
 * @author harsukh singh
 * @function non-default constructor
 * @params size of table to implement
 * @return void
 */
graph::graph(int size)
{
    //Allocate the adjacency list and set each
    //head pointer to NULL
    list_size = size;
    adjacency_list = new genre[list_size];
    for(int i = 0; i<list_size;++i)
    {
        adjacency_list[i] = genre();
    }   
}


/**
 * @author harsukh singh
 * @function Destructor for table
 * @params void
 * @return void
 */
graph::~graph()
{
    for(int i = 0; i<list_size; ++i)
    {
	if(adjacency_list[i].get_head() != NULL)
	{
	    remove_list(adjacency_list[i].get_head());
	}
    }
    delete[] adjacency_list;
}


/**
 * @author harsukh singh
 * @function Recursively removes from a linear linked list
 * @params edge_genre* current
 * @return 1 if removed 0 if not current
 */
int graph::remove_list(edge_genre* &current)
{
    if(!current) return 0;
    remove_list(current->get_next());
    delete current;
    current = NULL;
    return 1;
}

/**
 * @author harsukh singh
 * @function finds a location in the graph given char* key
 * @params char* key of location 
 * @return the index if found or -1 as a false boolean
 */
int graph::find_location(const char * key_value)
{
    for(int i = 0; i<list_size;++i)
    {
        /*if(check_string(key_value, adjacency_list[i].get_title()) == 1)
        {
            return i;
        }*/
        if(strcmp(key_value, adjacency_list[i].get_title()) == 0)
        {
            return i;
        }
    }
    return -1;
}


/**
 * @author harsukh singh
 * @function Stores the vertex at this location given that char* destination is NULL
 * @params char* to_insert
 * @return 1 if inserted or 0 as a false boolean when full
 */
int graph::insert_vertex(char* to_insert)
{
    for(int i = 0; i<list_size; ++i)
    {
        if(adjacency_list[i].get_title() == NULL)
        {
            adjacency_list[i].set_title(to_insert);
            return 1;
        }
    }
    // full here
    return 0;
}


/**
 * @author harsukh singh
 * @function Attach an edge to a vertex
 * @params char* current_vertex, char* to_attach
 * @return 1 if inserted or 0 as a false boolean when to_attach is not found
 */
int graph::insert_edge(const song &obj)
{
    char** to_insert = obj.get_genre();
    for(int i = 0; i<obj.get_length(); ++i)
    {
        int index = find_location(to_insert[i]);
        if(index == -1)
        {
            return -1;
        }
        if(adjacency_list[index].get_head() == NULL)
        {
            edge_genre* new_edge = new edge_genre(obj);
            adjacency_list[index].set_head(new_edge);
	    for(int j =0; j<obj.get_length(); ++j)
	    {
	        int index = find_location(to_insert[i]);
                new_edge->set_genre(adjacency_list[index]);
	    }
        }
        else
        {
            edge_genre* temp = adjacency_list[index].get_head();
            edge_genre* new_edge = new edge_genre(obj);
            adjacency_list[index].set_head(new_edge);
            new_edge->set_next(temp);
            for(int j =0; j<obj.get_length(); ++j)
	    {
	        int index = find_location(to_insert[i]);
                new_edge->set_genre(adjacency_list[index]);
	    }
        }

    }
    return 1;
}


/**
 * @author harsukh singh
 * @function get song function 
 * @params char* key of location, int q  
 * @return 0 or 1
 */
song* graph::get_song(char* key_value, int q)
{
    int index = find_location(key_value);
    if(index == -1 ) return NULL;
    edge_genre* current = adjacency_list[index].get_head();
    for(int i =0; i<q; ++i)
    {
        current = current -> get_next();
    }
    return current->get_song();
}


/**
 * @author harsukh singh
 * @function Display all vertices adjacent to the one specified
 * @params char* key of location 
 * @return 0 or 1
 */
int graph::display_adjacent(char * key_value)
{
   int index = find_location(key_value);
   if(index == -1 ) return 0;
   edge_genre* current = adjacency_list[index].get_head();
   int size = 0;
   while(current)
   {
        //current->display();
        ++size;
        current = current -> get_next();
   }
   int q = rand() % size;
   current = adjacency_list[index].get_head();
   for(int i =0; i<q; ++i)
   {
        current = current -> get_next();
   }
   current->display();
   return q;
}

/**
 * @author harsukh singh
 * @function Display all
 * @params void
 * @return void
 */
void graph::display_all()
{
    for(int i = 0; i<list_size;++i)
    {
        if(adjacency_list[i].get_title())
        {
            cout<<"Genre is, "<<adjacency_list[i].get_title()<<endl;
            edge_genre* temp = adjacency_list[i].get_head();
            while(temp)
            {
                temp->display();
                temp = temp ->get_next();
            }
        }
    }
}

/**
 * @author harsukh singh
 * @function gets the next song to play
 * @params char* key and int
 * @return 0 or 1
 */
int graph::get_next(char* key_value, int q)
{
    int index = find_location(key_value);
    if(index == -1 ) return NULL;
    edge_genre* current = adjacency_list[index].get_head();
    for(int i =0; i<q; ++i)
    {
        current = current -> get_next();
    }
    return display_adjacent(current->get_genre()->get_title());
    
}
