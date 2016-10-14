#pragma once
#include <type_traits>
#define _NORM_VEC_TYPE_ double
template<
typename N = _NORM_VEC_TYPE_,
typename = typename std::enable_if<std::is_arithmetic<N>::value, N>::type
>
struct vec2 {
	N x, y;
	vec2(N a, N b) : x(a), y(b) {}
	friend constexpr vec2& operator+(const vec2& a, const vec2& b) {
		return vec2(a.x + b.x, a.y + b.y);
	}
	constexpr vec2& operator+=(const vec2& b) {
		x += b.x, y += b.y;
		return this;
	}
	template<typename N1>
	friend constexpr vec2& operator*(const vec2& a, const N1& b) {
		return vec2(a.x * b, a.y * b);
	}
	template<typename N1>
	friend constexpr vec2& operator*(const N1& a, const vec2& b) {
		return vec2(a * b.x, a * b.y);
	}
	template<typename N1>
	constexpr vec2& operator*=(const N1& b) {
		x *= b, y *= b;
		return this;
	}
	N dot(vec2 rhs) {
    return (x * rhs.x + y * rhs.y);
	}
};

template<
typename N = _NORM_VEC_TYPE_,
typename = typename std::enable_if<std::is_arithmetic<N>::value, N>::type
>
struct vec3 {
	N x, y, z;
	vec3(N a, N b, N c) : x(a), y(b), z(c) {}
	friend constexpr vec3& operator+(const vec3& a, const vec3& b) {
		return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
	}
	constexpr vec3& operator+=(const vec3& b) {
		x += b.x, y += b.y, z += b.z;
		return this;
	}
	template<typename N1>
	friend constexpr vec3& operator*(const vec3& a, const N1& b) {
		return vec3(a.x * b, a.y * b, a.z * b);
	}
	template<typename N1>
	friend constexpr vec3& operator*(const N1& a, const vec3& b) {
		return vec3(a * b.x, a * b.y, a * b.z);
	}
	template<typename N1>
	constexpr vec3& operator*=(const N1& b) {
		x *= b, y *= b, z *= b;
		return this;
	}
	N dot(vec3 rhs) {
    return (x * rhs.x + y * rhs.y + z * rhs.z);
	}
};

template<
typename N = _NORM_VEC_TYPE_,
typename = typename std::enable_if<std::is_arithmetic<N>::value, N>::type
>
struct quat {
	N w, x, y, z;
	quat(N a, N b, N c, N d) : w(a), x(b), y(c), z(d) {}
};

template<
typename N = _NORM_VEC_TYPE_,
typename = typename std::enable_if<std::is_arithmetic<N>::value, N>::type
>
struct pose {
	vec3<N> p;
	quat<N> o;
	pose(vec3<N> a, quat<N> b) : p(a), o(b) {};
	// pose(vec3 a) : p(a), o(b) {};
};
