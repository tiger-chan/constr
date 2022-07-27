#if !defined(CONSTR_STRING_VIEW_HPP__)
#	define CONSTR_STRING_VIEW_HPP__

#	include <cstddef>
#	include "fwd.hpp"

namespace constr {
	struct CONSTR_API string_view {
		using size_type = uint32;
		using value = char;

		constexpr string_view();

		template<uint32 BUF_SIZE>
		constexpr string_view(const char (&buf)[BUF_SIZE]);

		constexpr string_view(const char *src);

		constexpr string_view(const char *src, size_type size);

		constexpr string_view(std::nullptr_t) = delete;

		constexpr string_view(const string_view &o);

		constexpr string_view(string_view &&o);

		template<typename StringLike>
		constexpr string_view(const StringLike &str);

		// Element access
		constexpr const char &at(size_type pos) const;

		constexpr const char &operator[](size_type pos) const;

		constexpr const char *c_str() const;

		constexpr const char *data() const;

		constexpr const char &back() const;

		constexpr const char &front() const;

		// Capacity

		constexpr bool empty() const;

		constexpr size_type size() const;

		constexpr size_type length() const;

	private:
		size_type len = 0;
		const value *ptr = nullptr;
	};
}    // namespace constr

namespace constr {
	constexpr bool operator==(const string_view &lhs, const string_view &rhs);
	constexpr bool operator!=(const string_view &lhs, const string_view &rhs);
	constexpr bool operator<(const string_view &lhs, const string_view &rhs);
	constexpr bool operator>(const string_view &lhs, const string_view &rhs);
	constexpr bool operator<=(const string_view &lhs, const string_view &rhs);
	constexpr bool operator>=(const string_view &lhs, const string_view &rhs);

	constexpr bool operator==(const string_view &lhs, const char *rhs);
	constexpr bool operator!=(const string_view &lhs, const char *rhs);
	constexpr bool operator<(const string_view &lhs, const char *rhs);
	constexpr bool operator>(const string_view &lhs, const char *rhs);
	constexpr bool operator<=(const string_view &lhs, const char *rhs);
	constexpr bool operator>=(const string_view &lhs, const char *rhs);

	constexpr bool operator==(const char *lhs, const string_view &rhs);
	constexpr bool operator!=(const char *lhs, const string_view &rhs);
	constexpr bool operator<(const char *lhs, const string_view &rhs);
	constexpr bool operator>(const char *lhs, const string_view &rhs);
	constexpr bool operator<=(const char *lhs, const string_view &rhs);
	constexpr bool operator>=(const char *lhs, const string_view &rhs);
}    // namespace constr

#	include <iostream>

extern CONSTR_API std::ostream &operator<<(std::ostream &o, const constr::string_view &str);

#	include "string_view.inl"

#endif    // CONSTR_STRING_VIEW_HPP__
