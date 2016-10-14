/* -*- C++ -*- */
#pragma once
#include <random>
#include <memory>
#include <string>
#include "base.h"


using namespace std;

class emotion_dist;
class feeling_dist;

class emotion {
public:
	trait pleasant;
	trait activity;
	template<class RNG>
	emotion(RNG& rng, emotion_dist& dist);
};

class idea {
public:
	string name;
};

class feeling {
public:
	vector<idea*> objects;
	emotion response;
	template<class RNG>
	feeling(RNG& rng, const feeling_dist& dist);
};


class emotion_dist {
public:
	trait_range pleasant;
	trait_range activity;
	normal_distribution<> pleasant_dist();
	normal_distribution<> activity_dist();
};

class feeling_dist {
public:
	vector<shared_ptr<idea>> objects;
	emotion_dist response;
};
