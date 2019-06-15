#include <clocale>
#include <ncurses.h>
#include <string>
#include <iostream>
using namespace std;

class Display {
public:
	void update(int map[][7], WINDOW* win) {
		for(int i = 0; i<9; i++) {
        	for(int j = 0; j<7; j++) {
            	printCell(i+2, 2*j, map[i][j], win);
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
	int map[9][7] = {{4, 4, 4, 4, 4, 4, 4},
					 {4, 1, 1, 1, 1, 1, 1},
					 {1, 3, 0, 2, 0, 0, 1},
					 {1, 3, 2, 5, 0, 0, 1},
					 {1, 3, 0, 2, 0, 0, 1},
					 {1, 0, 0, 0, 0, 0, 1},
					 {1, 1, 1, 1, 1, 1, 1},
					 {4, 4, 4, 4, 4, 4, 4},
					 {4, 4, 4, 4, 4, 4, 4}};
	keypad(stdscr, TRUE);
	Display d;
	int ch, moves=0;
	while ((ch = getch()) != KEY_F(1)) {
        clear();
        switch(ch) {
            case KEY_LEFT:
                printw("%s", "Key Left");
                break;
            case KEY_RIGHT:
                printw("%s", "Key Right");
                break;
            case KEY_UP:
                printw("%s", "Key Up");
                break;
            case KEY_DOWN:
                printw("%s", "Key Down");
				break;
    	}
		moves++;
		printw("%s", "\tmoves:");
		printw("%d", moves);
		d.update(map, win1);
	}
	delwin(win1);
	endwin();
	return 0;
}
	
