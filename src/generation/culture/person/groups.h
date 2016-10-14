/* -*- C++ -*- */
#pragma once
#include <vector>
#include <memory>
#include "thought.h"

using namespace std;

struct thought_group {
	vector<thought_group*> supers;
	vector<shared_ptr<idea>> new_memes;
	vector<shared_ptr<idea>> un_memes;
	// feeling_dist<>
};
