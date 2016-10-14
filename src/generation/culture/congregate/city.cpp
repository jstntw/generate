/* -*- C++ -*- */
#include "city.h"
room::room(unsigned size_) : size(size_) {
	people = new person*[size]{NULL};
}
city::city(unsigned room_count, unsigned people_count) {
	for(int i = 0; i < room_count; i++) {
		rooms.push_back(room(7));
	}
	rooms[0].people[0] = new person();
	rooms[0].people[1] = new person();
}
