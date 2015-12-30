/********************
 * @author harsukh singh cs 202 assignment 1
 * @file game class pertains to functions used in the game
 * ******************/


#include "prog1.h"
using namespace std;


/********************
 * @author harsukh singh cs 202 assignment 1
 * @function default constructor, shuffles the deck and sets the players hand 
 * @param void
 * @return void
 * ******************/
game::game()
{
   // srand(time(NULL));
    nick.set_score(0);
    cpu.set_score(0);
    shuffle();
    for(int i= 0; i<7;++i)
    {
        nick.draw_card(draw_card());
        cpu.draw_card(draw_card());
    }
}


/********************
 * @author harsukh singh cs 202 assignment 1
 * @function gameplay between player and cpu 
 * @param void
 * @return void
 * ******************/
void game::turn()
{
    int player_score;
    int cpu_score;
    while(again() == true)
    {
      cout<<"Displaying current hand."<<endl;
      nick.display_hand();
      cout<<"Player score ";
      nick.check_book();
      int num = get_decision();
      if(num != 0)
      {
	  bool check = cpu.check(num);
	  if(check == false)
	  {
	      cout<<"Go Fish."<<endl;
	      int draw = nick.draw_card(draw_card());
	      if(draw == -1)
	      {
		  player_score = nick.get_score();
		  cpu_score = cpu.get_score();
		  if(cpu_score > player_score) cout<<"CPU wins!"<<endl;
		  if(player_score > cpu_score) cout<<"Player wins!"<<endl;
		  else cout<<"It is a tie!"<<endl;
		  break;
	      }
	      cout<<"Player score ";
	      nick.check_book();
	      cout<<"Displaying updated hand."<<endl;
	      nick.display_hand();
	  }
	  else{
	      card* to_insert = cpu.get_from_player(num);
	      nick.get_cards(to_insert, num);
	      cpu.remove_cards(num);
	      cout<<"Player score ";
	      nick.check_book();
	  }
      }
      if(nick.is_hand_empty() == true) 
      {
	  cout<<"Player wins!"<<endl;
	  break;
      }
      cout<<"Switching players..."<<endl;
      cout<<"CPU score ";
      cpu.check_book();
      num = cpu.gen_num();
      bool check = nick.check(num);
      if(check == false)
      {
	  cout<<"Go Fish."<<endl;
	  int draw = cpu.draw_card(draw_card());
	  if(draw == -1)
	  {
	      player_score = nick.get_score();
	      cpu_score = cpu.get_score();
	      if(cpu_score > player_score) cout<<"CPU wins!"<<endl;
	      if(player_score > cpu_score) cout<<"Player wins!"<<endl;
	      else cout<<"It is a tie!"<<endl;
	      break;
	  }
	  cout<<"CPU score ";
	  cpu.check_book();
      }
      else{
	  card* to_insert = nick.get_from_player(num);
	  cpu.get_cards(to_insert, num);
	  nick.remove_cards(num);
	  cout<<"CPU score ";
	  cpu.check_book();
      }
      if(cpu.is_hand_empty() == true) 
      {
	  cout<<"CPU wins!"<<endl;
	  break;
      }
    }
}


/********************
 * @author harsukh singh cs 202 assignment 1
 * @default destructor 
 * @param void
 * @return boolean true or false
 * ******************/
bool game::again()
{
    if(nick.is_hand_empty() == false || cpu.is_hand_empty() == false)
        return true;
    return false;
}


/********************
 * @author harsukh singh cs 202 assignment 1
 * @function gets number to ask for or the players decision 
 * @param void
 * @return card number
 * ******************/
int game::get_decision()
{
    int decision;
    cout<<"Please enter the number you would like to ask for."<<endl;
    cin>>decision;
    cin.ignore(100, '\n');
    cin.clear();
    if(decision <= 0 || decision > 10)
    {
        return 0;
    }
    return decision;
}


/********************
 * @author harsukh singh cs 202 assignment 1
 * @function default destructor 
 * @param void
 * @return void
 * ******************/
game::~game()
{

}
