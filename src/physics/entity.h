/* -*- C++ -*- */
#include <utility>

class hunk {
	std::vector<joint> v;
	
};

class joint {
	std::pair<hunk, hunk> parts;
};

class entity {

};
