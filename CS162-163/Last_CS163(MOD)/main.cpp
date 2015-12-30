//@author harsukh singh


#include "cs163_graph.h"
using namespace std;


/**
 *@author harsukh singh
 *@function main, to be read by the linker
 *@params void
 *@return 0
 */
int main()
{
    int j = 0;
    cout<<"Please enter how many rides you would like to visit."<<endl;
    cin>>j;
    cin.ignore(100, '\n');
    cin.clear();
    while(j < 0 || j > 100) //while loop to check that the rides entered are of correct size
    {
        cout<<"This is an invalid number of rides. Please choose another one."<<endl;
        cin>>j;
        cin.ignore(100, '\n');
        cin.clear();
    }
    char** rides = new char*[j]; //new array of arrays created of size j ...which is the amount of rides the user wants to attend

    for(int i = 0; i < j; ++ i)
    {
        rides[i] = new char[300];
        cout<<"Please enter a ride you would like to visit, limited to 300 characters."<<endl;
        cin.get(rides[i], 300, '\n');
        cin.ignore(100, '\n');
    }
    table* graph = new table(j);
    for(int i = 0; i < j ; ++ i)
    {
        graph->insert_vertex(rides[i]);
    }
    //Let's add some connections
    char again;
    do
    {
       char* ride_a = new char[300];
       char* ride_b = new char[300];
       cout <<"Enter the ride that you are currently near. "<<endl;
       cin.get(ride_a, 100); cin.ignore(100,'\n');
        cout<<"Enter a ride that is near this ride."<<endl;
       cin.get(ride_b, 100); cin.ignore(100,'\n');
       graph->insert_edge(ride_a, ride_b);
       cout<<"Are more rides connected? Press 'y' otherwise press 'n'."<<endl;
       cin>>again;
       cin.ignore(100, '\n');
       cin.clear();
       delete[] ride_a;
       delete[] ride_b;
    } while (again == 'y');
    //Let's display what we have 
    cout <<"\n\nThis is the all the rides in the park:\n";
    graph -> display_all();
    cout<<"\n\nIf you would like to view the rides near a ride press 'y'\n"<<endl;
    char near_here;
    cin >> near_here;
    cin.ignore(100, '\n');
    cin.clear();
        //displaying all adjacent to one node
    while(near_here == 'y')
    {
        char * ride_near = new char[300];
        cout<<"Please enter the ride you'd like to find rides near."<<endl;
        cin.get(ride_near, 300, '\n');
        cin.ignore(100, '\n');
        int adj  = graph -> display_adjacent(ride_near);
        if(adj == 0)
        {
            cout<<"This ride does not exist."<<endl;
        }
        cout<<"If you would like to view the rides near a ride press 'y'"<<endl;
        cin >> near_here;
        cin.ignore(100, '\n');
        cin.clear();
        delete[] ride_near;
    }
        //implementation of depth first here
        char depth;
        cout<<"If you would like the route from a ride, press 'y'."<<endl;
        cin>>depth;
        cin.ignore(100, '\n');
        cin.clear();
    while(depth == 'y')
    {
        char* ride_near = new char[300];
        cout<<"Please enter the ride you are currently near."<<endl;
        cin.get(ride_near, 300, '\n');
        cin.ignore(100, '\n');
        char* destination = new char[300];
        cout<<"Please enter the destination (the ride you would like to go to)."<<endl;
        cin.get(destination, 300, '\n');
        cin.ignore(100, '\n');
        int adj = graph ->depth_first(ride_near, destination);
        if(adj == 0) cout<<"This ride does not exist."<<endl;
        cout<<"If you would like to view more routes, please press 'y'."<<endl;
        cin>>depth;
        cin.ignore(100, '\n');
        cin.clear();
        delete[] ride_near;
        delete[] destination;	
    }
    for(int i = 0; i<j; ++i)
    {
        delete[] rides[i];
    }
    delete[] rides;
    delete graph;
    return 0;
}
