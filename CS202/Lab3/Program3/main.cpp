//@author harsukh singh
#include "table.h"
using namespace std;

//@author harsukh singh
//@function main function
//function initializes the seed and the insert
int main()
{
    srand(time(NULL));
     //test for playlist, song and node classes
    manager CS_pandora;
    CS_pandora.load_graph("genre");
    CS_pandora.insert_songs("songs");
    //CS_pandora.test();   
    CS_pandora.start_program();
}
