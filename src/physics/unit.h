#pragma once
template<typename T = unsigned long long>
struct unit {
	T val;
	unit(T var) : var(val) {}
	constexpr operator+(const unit& a, const unit& b) {
		return a.val + b.val;
	}
	constexpr operator*(const unit& a, const unit& b) {
		return a.val * b.val;
	}
	constexpr operator*(const unit& a, const int& b) {
		return a.val * b;
	}
};

struct num {

};
