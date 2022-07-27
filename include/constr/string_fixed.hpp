#if !defined(CONSTR_STRING_FIXED_HPP__)
#	define CONSTR_STRING_FIXED_HPP__

#	include <cstddef>
#	include "fwd.hpp"

namespace constr {
	struct string_view;
}    // namespace constr

namespace constr {
	template<uint32 BUFFER_SIZE = 16>
	struct CONSTR_API basic_fixed_string {
		static_assert(BUFFER_SIZE > 0, "BUFFER_SIZE must be greater than 0");
		using size_type = uint32;
		using value = char;

		static constexpr size_type npos = BUFFER_SIZE;

		constexpr basic_fixed_string();

		template<uint32 BUF_SIZE>
		constexpr basic_fixed_string(const char (&buf)[BUF_SIZE]);

		constexpr basic_fixed_string(const char *src);

		constexpr basic_fixed_string(const char *src, size_type count);

		constexpr basic_fixed_string(size_type count);

		constexpr basic_fixed_string(std::nullptr_t) = delete;

		// Element access

		constexpr char &at(size_type pos);

		constexpr const char &at(size_type pos) const;

		constexpr char &operator[](size_type pos);

		constexpr const char &operator[](size_type pos) const;

		constexpr const char *c_str() const;

		constexpr const char *data() const;

		constexpr char *data();

		constexpr const char &back() const;

		constexpr char &back();

		constexpr const char &front() const;

		constexpr char &front();

		constexpr operator string_view() const noexcept;

		// Capacity

		constexpr size_type size() const;

		constexpr size_type length() const;

		constexpr bool empty() const;

		constexpr size_type capacity() const;

		// Operations
		constexpr void resize(size_type count);
		constexpr void resize(size_type count, char ch);

		constexpr void clear();

		constexpr basic_fixed_string<BUFFER_SIZE> &erase(size_type index = 0, size_type count = npos);

	private:
		size_type len = 0;
		value arr[BUFFER_SIZE] = {};
	};

	template<uint32 Size = 16>
	using fixed_string = basic_fixed_string<Size>;
}    // namespace constr

namespace constr {
	template<uint32 LSize, uint32 RSize>
	constexpr basic_fixed_string<LSize + RSize> operator+(const basic_fixed_string<LSize> &lhs, const basic_fixed_string<RSize> &rhs);

	template<uint32 LSize, uint32 RSize>
	constexpr basic_fixed_string<LSize> &operator+=(basic_fixed_string<LSize> &lhs, const basic_fixed_string<RSize> &rhs);

	template<uint32 BUFFER_SIZE>
	constexpr basic_fixed_string<BUFFER_SIZE> operator+(const basic_fixed_string<BUFFER_SIZE> &lhs, const char *rhs);

	template<uint32 BUFFER_SIZE>
	constexpr basic_fixed_string<BUFFER_SIZE> operator+(const char *lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);

	template<uint32 BUFFER_SIZE>
	constexpr basic_fixed_string<BUFFER_SIZE> &operator+=(basic_fixed_string<BUFFER_SIZE> &lhs, const char *rhs);

	template<uint32 BUFFER_SIZE>
	constexpr basic_fixed_string<BUFFER_SIZE> operator+(const basic_fixed_string<BUFFER_SIZE> &lhs, char rhs);

	template<uint32 BUFFER_SIZE>
	constexpr basic_fixed_string<BUFFER_SIZE> operator+(char lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);

	template<uint32 BUFFER_SIZE>
	constexpr basic_fixed_string<BUFFER_SIZE> &operator+=(const basic_fixed_string<BUFFER_SIZE> &lhs, char rhs);

	template<uint32 BUFFER_SIZE, typename StringViewLike>
	constexpr basic_fixed_string<BUFFER_SIZE> operator+(const basic_fixed_string<BUFFER_SIZE> &lhs, const StringViewLike &rhs);

	template<typename StringViewLike, uint32 BUFFER_SIZE>
	constexpr basic_fixed_string<BUFFER_SIZE> operator+(const StringViewLike &lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);

	template<uint32 BUFFER_SIZE, typename StringViewLike>
	constexpr basic_fixed_string<BUFFER_SIZE> &operator+=(basic_fixed_string<BUFFER_SIZE> &lhs, const StringViewLike &rhs);

	template<uint32 LSize, uint32 RSize>
	constexpr bool operator==(const basic_fixed_string<LSize> &lhs, const basic_fixed_string<RSize> &rhs);
	template<uint32 LSize, uint32 RSize>
	constexpr bool operator!=(const basic_fixed_string<LSize> &lhs, const basic_fixed_string<RSize> &rhs);
	template<uint32 LSize, uint32 RSize>
	constexpr bool operator<(const basic_fixed_string<LSize> &lhs, const basic_fixed_string<RSize> &rhs);
	template<uint32 LSize, uint32 RSize>
	constexpr bool operator>(const basic_fixed_string<LSize> &lhs, const basic_fixed_string<RSize> &rhs);
	template<uint32 LSize, uint32 RSize>
	constexpr bool operator<=(const basic_fixed_string<LSize> &lhs, const basic_fixed_string<RSize> &rhs);
	template<uint32 LSize, uint32 RSize>
	constexpr bool operator>=(const basic_fixed_string<LSize> &lhs, const basic_fixed_string<RSize> &rhs);

	template<uint32 BUFFER_SIZE>
	constexpr bool operator==(const basic_fixed_string<BUFFER_SIZE> &lhs, const char *rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator!=(const basic_fixed_string<BUFFER_SIZE> &lhs, const char *rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator<(const basic_fixed_string<BUFFER_SIZE> &lhs, const char *rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator>(const basic_fixed_string<BUFFER_SIZE> &lhs, const char *rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator<=(const basic_fixed_string<BUFFER_SIZE> &lhs, const char *rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator>=(const basic_fixed_string<BUFFER_SIZE> &lhs, const char *rhs);

	template<uint32 BUFFER_SIZE>
	constexpr bool operator==(const char *lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator!=(const char *lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator<(const char *lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator>(const char *lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator<=(const char *lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);
	template<uint32 BUFFER_SIZE>
	constexpr bool operator>=(const char *lhs, const basic_fixed_string<BUFFER_SIZE> &rhs);
}    // namespace constr

#	include <iostream>

template<unsigned BUFFER_SIZE>
extern std::ostream &operator<<(std::ostream &o, const constr::basic_fixed_string<BUFFER_SIZE> &str);
template<unsigned BUFFER_SIZE>
extern std::istream &operator>>(std::istream &i, constr::basic_fixed_string<BUFFER_SIZE> &str);

#	include "string_fixed.inl"

#endif    // CONSTR_STRING_FIXED_HPP__
