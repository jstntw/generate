/* -*- C++ -*- */
#pragma once
#include <cstdint>
#include <functional>
#include <vector>
#include <map>
#include <boost/lambda/lambda.hpp>
#include <boost/variant.hpp>



struct tile_entity {
	std::function<void()>;
};
struct block {
	uint32_t
	filled : 8,
	light : 8,
	is_te : 1,
	//could be material or tile entity "pointer"

	value : 12;
	// unsigned UNUSED_VAL : 3;
};

class loc {
	uint32_t x;
	uint32_t y;
	uint32_t z;
};

class block_chunk {
	block data[16*16*16];

	std::vector<tile_entity> tile_entities;
};

class height_map_chunk {

};
class gen_chunk {

};

class any_chunk {
	boost::variant<block_chunk, height_map_chunk, gen_chunk>;
	any_chunk(block_chunk& ch);
};

class world {
	std::map<loc, any_chunk> chunks;
	world();
};
