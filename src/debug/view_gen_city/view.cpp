#include "view.h"
#include <generation/culture/congregate/city.h>
#include <cwchar>
#include <cmath>

const wchar_t person_char = '@';
const char * const room_ids = "qwerasdfzxcvtgbyhnujmiopkl";

vector<room>::iterator cursor_room;
person** cursor_person;

unsigned win_x = 0;
unsigned win_y = 0;

unsigned room_description(room* r, unsigned begin) {
	
}

float trait_to_float(trait t) {	
	const float mult = std::pow(2, sizeof(trait) * 8);
	return mult * float(t);
}

unsigned person_description(person* p, unsigned begin) {
	const unsigned int TEXT_WIDTH = 16;
	const unsigned int TEXT_LINES = 5;
	mvprintw(begin + 0, win_x - TEXT_WIDTH, "sense : %1.6f", trait_to_float(p->sensation_seeking));
	mvprintw(begin + 1, win_x - TEXT_WIDTH, "neuro : %1.6f", trait_to_float(p->neuroticism_anxiety));
	mvprintw(begin + 2, win_x - TEXT_WIDTH, "aggro : %1.6f", trait_to_float(p->aggression_hostility));
	mvprintw(begin + 3, win_x - TEXT_WIDTH, "socia : %1.6f", trait_to_float(p->sociability));
	mvprintw(begin + 4, win_x - TEXT_WIDTH, "activ : %1.6f", trait_to_float(p->activity));
	return begin + TEXT_LINES;
}

void view_room(unsigned line, vector<room>::iterator viewing) {
	unsigned i = 0;
	if(cursor_room == viewing)
		attron(COLOR_PAIR(2));
	else
		attron(COLOR_PAIR(1));
	mvaddch(line, i + 3, ':');
	attron(COLOR_PAIR(1));
	mvaddch(line, i + 4, '[');

	for(; i < viewing->size; i++) {
		person* peeple = viewing->people[i];
		if(cursor_person && ((*cursor_person && *cursor_person == peeple) || (cursor_person == viewing->people + i)))
			attron(COLOR_PAIR(4));
		else
			attron(COLOR_PAIR(1));
		if(peeple)
			mvaddch(line, i + 5, person_char);
		else
			mvaddch(line, i + 5, ' ');
		attron(COLOR_PAIR(1));
	}
	mvaddch(line, i + 6, ']');
}

void view_city(city* c) {
	cursor_room = c->rooms.end();
	for(int ch = 0;; ch = getch()) {
		get_size();
		for(auto it = c->rooms.begin(); it != c->rooms.end(); ++it) {
			view_room(std::distance(c->rooms.begin(), it), it);
		}
		if(cursor_person && *cursor_person)
			person_description(*cursor_person, 0);
		switch(ch) {
			case KEY_BACKSPACE :
				if(cursor_room == c->rooms.end())
					return;
				else if (!cursor_person)
					cursor_room = c->rooms.end();
				else if (true)
					cursor_person = NULL;
				break;
			case '\n' :
				if(cursor_room == c->rooms.end())
					cursor_room = c->rooms.begin();
				else if(!cursor_person)
					cursor_person = (&(*cursor_room))->people;
				break;
			case KEY_UP :
				if(cursor_room != c->rooms.end()) {
					if(cursor_room == c->rooms.begin())
						cursor_room = c->rooms.end() - 1;
					else
						cursor_room--;
				}
				break;
			case KEY_DOWN :
				if(cursor_room != c->rooms.end()) {
					if(cursor_room == c->rooms.end() - 1)
						cursor_room = c->rooms.begin();
					else
						cursor_room++;
				}
			case KEY_RIGHT :
				if(cursor_person) {
					cursor_person++;
					if(cursor_person == (&(*cursor_room))->people + (&(*cursor_room))->size)
						cursor_person = (&(*cursor_room))->people;
				}
				break;
			case KEY_LEFT :
				if(cursor_person) {
					if(cursor_person == (&(*cursor_room))->people)
						cursor_person = (&(*cursor_room))->people + (&(*cursor_room))->size - 1;
					else
						cursor_person--;
				}
				break;
		}
	}
}

void setup_ncurses() {
	initscr();
	raw();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
  timeout(0);
	curs_set(0);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_GREEN, COLOR_BLUE);
	init_pair(4, COLOR_RED, COLOR_YELLOW);
	city c(10, 1);

	view_city(&c);

	refresh();
	endwin();
}

void get_size() {
	getmaxyx(stdscr, win_y, win_x);
}

