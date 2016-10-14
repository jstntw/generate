/* -*- C++ -*- */
#include <vector>
#include <generation/culture/person/person.h>
using std::vector;
class room {
public:
	unsigned size;
	person** people;
	room(unsigned size_);
};
class city {
public:
	vector<room> rooms;
	city(unsigned room_count, unsigned people_count);
};
