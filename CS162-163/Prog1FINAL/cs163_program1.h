/*Author:: Harsukh Singh
 * Header file for hero match database declares three objects, Hero, Power and Node.
 * Hero object contains the name of hero and description and are dynamically allocated arrays.
 * Power object contains power, situation in which the power is used, the heros name.
 * node_type object contains the node itself which consists of heroes and arrays
 * functions are described in the cpp file.
 */
struct Hero
{
  char* name;
  char* description;
};

struct Power
{
  char* power;
  char* situation;
  int number; 
  char* hero;
};

struct node_type
{
  Power *power_type;
  Hero *heroes;
  node_type* next;
};

class Hero_Match
{
  public:
    Hero_Match();
    ~Hero_Match(); 
    int add_hero();
    int load_heros(char power_file_name[], char hero_file_name[]); 
    int remove_power(char super_power[]); //
    int display(); //displays all heros 
    int display(char super_power[]); // display heroes with a particular super power 
    char* find(char situation[]); 
    int prompt();
  private:
    node_type* head;
    node_type* current;
    node_type* temp; // for sorting reasons
};