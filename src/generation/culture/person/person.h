/* -*- C++ -*- */
#pragma once
#include <cstdint>
#include <utility>
#include <vector>
#include "thought.h"
#include "groups.h"
class person {
public:
	trait sensation_seeking;
	trait neuroticism_anxiety;
	trait aggression_hostility;
	trait sociability;
	trait activity;
	shared_ptr<thought_group> memes;
	vector<shared_ptr<idea>> new_memes;
	vector<shared_ptr<idea>> un_memes;
	// std::vector<feeling> feelings;
};

class person_stat {
public:
	trait_range sensation_seeking_avg;
	trait_range neuroticism_anxiety_avg;
	trait_range aggression_hostility_avg;
	trait_range sociability_avg;
	trait_range activity_avg;
	shared_ptr<thought_group> t_group;
	vector<shared_ptr<idea>> new_memes;
	vector<shared_ptr<idea>> un_memes;

	// std::vector<feeling_dist> feelings;
};
