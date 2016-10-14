/* -*- C++ -*- */
#pragma once
#include <type_traits>
#include <utility>
#include <vector>

//a value so that domain resorts its list somewhat randomly
//how often it should do that about???
#define QUOTES_AROUND_OFTENESS = 15;


template<typename A, typename B>
bool pairCompare(const std::pair<A, B>& firstElem, const std::pair<A, B>& secondElem) {
  return firstElem.first < secondElem.first;
}

template<
    typename N, //number type
		typename V, //value type
    typename = typename std::enable_if<std::is_arithmetic<N>::value, N>::type
>
class range {
	std::pair<N, N> a_b;
	V val;
	range(N min, N max, V val) : a_b(std::min(min, max), std::max(min, max)) {}

};

template<
    typename N, //number type
		typename V, //value type
    typename = typename std::enable_if<std::is_arithmetic<N>::value, N>::type
>
class domain {
	std::vector<range<N, V>> values;

	void sort();

	void add_overlap(range<N, V> b) {

		// if(values.size() % QUOTES_AROUND_OFTENESS != 0)
		// 	sort();
		//
		// for(auto it = vector.begin(); it != vector.end(); it++) {
		// 	range<N, V> r =
		// 	if(!((r.a_b.first <= b.a_b.second) & (b.a_b.first <= r.a_b.second)))
		// 		continue;
		// 	// bool n_begin_inside = v0 < n0 < v1;
		// 	//the value iterated on is WITHIN the new value
		// 	if(b1 < r1 && r2 < b2)
		//
		//
		// }
	}
};
