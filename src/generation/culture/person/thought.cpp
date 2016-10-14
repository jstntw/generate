#include "thought.h"
template<class RNG>
emotion::emotion(RNG& rng, emotion_dist& dist) : activity(rng(dist.activity_dist())), pleasant(rng(dist.pleasant_dist())) {}
template<class RNG>
feeling::feeling(RNG& rng, const feeling_dist& dist) {
	//todo do shit
}

normal_distribution<> emotion_dist::pleasant_dist() {
	return normal_distribution<>(get<0>(pleasant), get<1>(pleasant));
}


normal_distribution<> emotion_dist::activity_dist() {
	return normal_distribution<>(get<0>(activity), get<1>(activity));
}
