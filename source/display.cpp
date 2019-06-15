#include <clocale>
#include <ncurses.h>
#include <string>
#include <iostream>
#include "position.h"
#include "box.h"
#include "game.h"
#include "mapContainer.h"
using namespace std;

class Display {
public:
	void update(Game g) {
		for(int i = 0; i<9; i++) {
        	for(int j = 0; j<7; j++) {
            	printCell(i+4, 2*j, g.at(i,j));
	        }
   		}
		refresh();
	}
private:
	void printCell(int x, int y, int c) {
		if (c==0) { // Void
			attron(COLOR_PAIR(4));
        	mvprintw(x, y, "  ");
        	attroff(COLOR_PAIR(4));
		}
		if (c==1) { // Wall
			attron(COLOR_PAIR(1));
			mvprintw(x, y, "\u2B1B");
			attroff(COLOR_PAIR(1));
		}
		else if (c==2) { // Box
    		attron(COLOR_PAIR(2));
	    	mvprintw(x, y, "\u2B1C");
    		attroff(COLOR_PAIR(2));
		}
		else if (c==3) { // Goal
    		attron(COLOR_PAIR(3));
			mvprintw(x, y, "\u2B1A");
	    	attroff(COLOR_PAIR(3));
		}
		else if (c==4) { // Outer
			attron(COLOR_PAIR(4));
			mvprintw(x, y, "  ");
			attroff(COLOR_PAIR(4));
		}
		else if (c==5) { // Player
			attron(COLOR_PAIR(5));
			mvprintw(x, y, "\u2B55");
			attroff(COLOR_PAIR(5));
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	keypad(stdscr, TRUE);
	WINDOW *win1;
	initscr();
	resize_term(14, 25);

	start_color();
	init_pair(1, COLOR_WHITE,COLOR_BLACK); // wall
    init_pair(2, COLOR_YELLOW,COLOR_BLACK); // box
    init_pair(3, COLOR_WHITE, COLOR_BLACK); // goal
    init_pair(4, COLOR_WHITE, COLOR_BLACK); // void, outer
    init_pair(5, COLOR_BLUE, COLOR_BLACK); // player
	
	border('*','*','*','*','*','*','*','*');
	mvprintw(4,1,"     S O K O B A N");
	mvprintw(6,1,"press any key to start");
	refresh();
	getch();
	
	keypad(stdscr, TRUE);
	mapContainer mapcontainer;
	Display d;
	int ch;

	while(mapcontainer.mapindex != 5) {
		Game g(mapcontainer.getMap());
		clear();
		printw("%s", "level:");
        printw("%d", mapcontainer.mapindex+1);
        printw("%s", "\tmoves:");
        printw("%d", g.getMove());
        printw("%s", "\npushed:");
		printw("%d", g.getPushed());
		printw("%s" "\nmove:arrow\nexit:F1 reset:F2");
		d.update(g);
		ch = getch();
		while (ch != KEY_F(1) && ch != KEY_F(2)) {
        	clear();
        	switch(ch) {
	            case KEY_LEFT:
    	            g.move(g.getChar(), 1);
        	        break;
	            case KEY_RIGHT:
    	            g.move(g.getChar(), 0);
        	        break;
	            case KEY_UP:
    	            g.move(g.getChar(), 2);
        	        break;
	            case KEY_DOWN:
    	            g.move(g.getChar(), 3);
					break;
	    	}
			if(g.isWin()) {
				printw("%s", "You Win!\npress any key");
				d.update(g);
				getch();
				mapcontainer.getNextMap();
				break;
			}
			else {
				printw("%s", "level:");
				printw("%d", mapcontainer.mapindex+1);
				printw("%s", "\tmoves:");
				printw("%d", g.getMove());
				printw("%s", "\npushed:");
				printw("%d", g.getPushed());
				printw("%s", "\nmove:arrow\nexit:F1 reset:F2");
			}
			d.update(g);
			ch = getch();
		}
		if (ch == KEY_F(1)) break;
	}
	endwin();
	return 0;
}
	
