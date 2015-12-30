all: main.o game.o computer.o computer.o player.o human.o deck.o suit.o hand.o card.o  
	g++ *.o -g -Wall
	rm -rf *.o

main.o: main.cpp 
	g++ -c main.cpp

game.o: game.cpp 
	g++ -c game.cpp

computer.o: computer.cpp 
	g++ -c computer.cpp

player.o: player.cpp 
	g++ -c player.cpp

human.o: human.cpp 
	g++ -c human.cpp

deck.o: deck.cpp
	g++ -c deck.cpp

suit.o: suit.cpp 
	g++ -c suit.cpp

hand.o: hand.cpp 
	g++ -c hand.cpp

card.o: card.cpp 
	g++ -c card.cpp

