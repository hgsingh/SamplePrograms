/*****************
 * @author harsukh singh CS202 assignment 1
 * header file defines the player heirarchy and the game class
 ******************/

#include "helper.h"

/*****************
 * @author harsukh singh CS202 assignment 1
 * Generic player class that is mostly implemented as wrapper functions for the hand
 * manipulates players hand and cards during game play
 ******************/
class player
{
    public:
        player();
        ~player();
        void set_score(int current_score);
        int get_score();
	bool check(int num);
	int draw_card(card* to_draw);
        int check_book();
        bool is_hand_empty();
        void display_hand();
	card* get_from_player(int num);
	void get_cards(card* these_cards, int num);
	void remove_cards(int num);
    private:
        int score;
	hand player_hand;
};


/*****************
 * @author harsukh singh CS202 assignment 1
 * derived computer class that uses a number generator for the computer to use
 ******************/
class computer:public player
{
    public:
	int gen_num();
        computer();
        ~computer();
    private:

};

/*****************
 * @author harsukh singh CS202 assignment 1
 * derived computer class that uses a number generator for the computer to use
 ******************/
class human:public player
{
    public:
	human();
	~human();
    private:
};

/*****************
 * @author harsukh singh CS202 assignment 1
 * derived game class implements functions used during gameplay
 ******************/
class game:public deck
{
    private:
        human nick;
        computer cpu;
    public:
	void turn();
	bool again();
        int get_decision();
        game();
        ~game();
};
