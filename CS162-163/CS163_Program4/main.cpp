#include "cs163_program4.h"
using namespace std;

int main()
{
    bs_tree movie;
    cout<< "The category is best movie."<<endl;
    char add_movie = 'y';
    while(add_movie == 'y')
    {
       char* new_movie = new char[300];
       int vote = 0;
       cout<<"Please enter a movie name for the Oscar's Academy Awards."<<endl;
       cin.get(new_movie, 300, '\n');
       cin.ignore(100, '\n');
       cout<<"Please enter an initial vote count from 1 to a 100."<<endl;
       cin>>vote;
       cin.ignore(100, '\n');
       cin.clear();
       if(vote > 100 || vote< 0)
       {
            while(vote>100 || vote <0)
            {
                cin>>vote;
                cin.ignore(100, '\n');
                cin.clear();
            }
       }
       movie.add_nominee(new_movie, vote);
       movie.display();
       delete[] new_movie;
       cout<<"If you would like to add more movies, press 'y'."<<endl;
       cin.get(add_movie);
       cin.ignore(100, '\n');
       add_movie = tolower(add_movie);
    }
    char remove_movie;
    cout << "If you would like to remove movies press 'y'." << endl;
    cin >> remove_movie;
    cin.ignore(100, '\n');
    cin.clear();
    remove_movie = tolower(remove_movie);
    int j = 1;
    while(remove_movie == 'y' && j != 0)
    {
        char* movie_to_remove = new char[300];
        cout<<"Please enter a movie to remove."<<endl;
        cin.get(movie_to_remove, 300, '\n');
        cin.ignore(100, '\n');
        j = movie.remove_nominee(movie_to_remove);
        movie.display();
        delete[] movie_to_remove;
        cout << "If you would like to remove more movies press 'y'." << endl;
        cin >> remove_movie;
        cin.ignore(100, '\n');
        remove_movie = tolower(remove_movie);
    }
    char vote;
    cout << "If you would like to add votes to a movie press 'y'." << endl;
    cin >> vote;
    cin.ignore(100, '\n');
    cin.clear();
    vote = tolower(vote);
    int k = 1;
    while(vote == 'y')
    {
        char* nominee = new char[300];
        cout<<"Please enter a movie to vote for."<<endl;
        cin.get(nominee, 300, '\n');
        cin.ignore(100, '\n');
        movie.vote(nominee);
        k = movie.display_nominee(nominee);
	if(k == 0) cout<< "This movie does not exist."<<endl;
        delete[] nominee;
        cout << "If you would like to vote for more movies press 'y'." << endl;
        cin >> vote;
        cin.ignore(100, '\n');
        vote = tolower(vote);
    }
    return 0;
}
