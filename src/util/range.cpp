#include "range.h"


void domain::sort() {
	std::sort(values.begin(), values.end(), pairCompare);
}
