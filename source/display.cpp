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
	void update(Game g, WINDOW* win) {
		for(int i = 0; i<9; i++) {
        	for(int j = 0; j<7; j++) {
            	printCell(i+2, 2*j, g.at(i,j), win);
	        }
   		}
		//mvprintw(win, 10, 5, "aa");
		refresh();
    	getch();
	}
private:
	void printCell(int x, int y, int c, WINDOW* win) {
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
	resize_term(25, 25);

	start_color();
	init_pair(1, COLOR_WHITE,COLOR_BLACK); // wall
    init_pair(2, COLOR_YELLOW,COLOR_BLACK); // box
    init_pair(3, COLOR_WHITE, COLOR_BLACK); // goal
    init_pair(4, COLOR_WHITE, COLOR_BLACK); // void, outer
    init_pair(5, COLOR_BLUE, COLOR_BLACK); // player
	
	border('*','*','*','*','*','*','*','*');
	mvprintw(1,1,"SOKOBAN");
	mvprintw(2,1,"press any key to start");
	refresh();
	getch();
	
	win1 = newwin(20, 20, 3, 3);
	wbkgd(win1, COLOR_PAIR(1));
	wattron(win1, COLOR_PAIR(1));
	mvwprintw(win1, 1, 1, "A new window");
	wborder(win1, '@','@','@','@','@','@','@','@');
	wrefresh(win1);
	getch();
	
	keypad(stdscr, TRUE);
	mapContainer mapcontainer;
	Display d;
	int ch;

	while(mapcontainer.mapindex != 5) {
		Game g(mapcontainer.getMap());
		int moves = 0;
	while ((ch = getch()) != KEY_F(1)) {
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
		moves++;
		if(g.isWin()) {
			printw("%s", "You Win!\npress any key");
			d.update(g, win1);
			getch();
			mapcontainer.getNextMap();
			break;
		}
		else {
			printw("%s", "level:");
			printw("%d", mapcontainer.mapindex+1);
			printw("%s", "\tmoves:");
			printw("%d", moves);
		}
		d.update(g, win1);
	}
	

	}
	delwin(win1);
	endwin();
	return 0;
}
	
