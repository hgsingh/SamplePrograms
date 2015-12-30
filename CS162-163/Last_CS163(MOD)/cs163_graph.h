//@author harsukh singh

#include <cstring>
#include <iostream>
#include <cctype>

//@author harsukh singh
//vertex struct for graph vertices
struct vertex
{
   char * destination;  //NULL, if the vertex isn't set
   bool visited; //false if not visited
   struct node * head;  //edge list
};

//@author harsukh singh
//nodes for edge list can be weighted if needed (implementations of kruskal and floyd)
struct node
{
   vertex * adjacent;	  
   //int weight;                
   node * next;
};


//@author harsukh singh
//graph object adt with associated functions
class table
{
      public:
                table(int size);  
                ~table(void);     //destructor
                int insert_vertex(char* to_insert);  
                int find_location(char * key_value);  
                int depth_first(char* current_vertex, char* to_find);
                int insert_edge(char * current_vertex, char * to_attach);
                int display_adjacent(char * key_value);  
                int remove_list(node* current);
                void display_all();
                int check_string(char* guess, char* check);
      private:
                vertex * adjacency_list;
                int list_size;

};
