#if !defined(CONSTR_FWD_HPP__)
#define CONSTR_FWD_HPP__

#include "config/macro.hpp"

namespace constr {
	using uint8 = unsigned char;
	using int32 = int;
	using uint32 = unsigned int;

	template<typename T>
	static constexpr T min(const T &x, const T &y) {
		return x < y ? x : y;
	}

	template<typename T>
	static constexpr T max(const T &x, const T &y) {
		return x > y ? x : y;
	}
}

#endif // CONSTR_FWD_HPP__
