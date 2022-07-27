#include "string.hpp"
#include "string_util.hpp"

namespace constr {
	constexpr string_view::string_view()
		: len{ 0 }
		, ptr{ nullptr } {
	}

	template<uint32 BUF_SIZE>
	constexpr string_view::string_view(const char (&buf)[BUF_SIZE])
		: len{ BUF_SIZE }
		, ptr{ buf } {
	}

	constexpr string_view::string_view(const char *src)
		: len{ constr::strlen(src) }
		, ptr{ src } {
	}

	constexpr string_view::string_view(const char *src, size_type size)
		: len{ size }
		, ptr{ src } {
	}

	constexpr string_view::string_view(const string_view &o)
		: len{ o.len }
		, ptr{ o.ptr } {
	}

	constexpr string_view::string_view(string_view &&o)
		: len{ o.len }
		, ptr{ o.ptr } {
		o.len = 0;
		o.ptr = nullptr;
	}

	template<typename StringLike>
	constexpr string_view::string_view(const StringLike &str)
		: len{ str.size() }
		, ptr{ str.data() } {
	}

	// Element access
	constexpr const char &string_view::at(size_type pos) const {
		return ptr[pos];
	}

	constexpr const char &string_view::operator[](size_type pos) const {
		return ptr[pos];
	}

	constexpr const char *string_view::c_str() const {
		return ptr;
	}

	constexpr const char *string_view::data() const {
		return ptr;
	}

	constexpr const char &string_view::back() const {
		return ptr[len - 1];
	}

	constexpr const char &string_view::front() const {
		return ptr[0];
	}

	// Capacity

	constexpr bool string_view::empty() const {
		return !ptr || len == 0;
	}

	constexpr string_view::size_type string_view::size() const {
		return len;
	}

	constexpr string_view::size_type string_view::length() const {
		return len;
	}
}    // namespace constr

namespace constr {
	constexpr bool operator==(const string_view &lhs, const string_view &rhs) {
		return lhs.size() == rhs.size() && constr::strcmp(lhs.data(), rhs.data()) == 0;
	}

	constexpr bool operator!=(const string_view &lhs, const string_view &rhs) {
		return !(lhs == rhs);
	}

	constexpr bool operator<(const string_view &lhs, const string_view &rhs) {
		return constr::strcmp(lhs.data(), rhs.data()) < 0;
	}

	constexpr bool operator>(const string_view &lhs, const string_view &rhs) {
		return constr::strcmp(lhs.data(), rhs.data()) > 0;
	}

	constexpr bool operator<=(const string_view &lhs, const string_view &rhs) {
		return !(lhs > rhs);
	}

	constexpr bool operator>=(const string_view &lhs, const string_view &rhs) {
		return !(lhs < rhs);
	}

	constexpr bool operator==(const string_view &lhs, const char *rhs) {
		return constr::strcmp(lhs.data(), rhs) == 0;
	}

	constexpr bool operator!=(const string_view &lhs, const char *rhs) {
		return !(lhs == rhs);
	}

	constexpr bool operator<(const string_view &lhs, const char *rhs) {
		return constr::strcmp(lhs.data(), rhs) < 0;
	}

	constexpr bool operator>(const string_view &lhs, const char *rhs) {
		return constr::strcmp(lhs.data(), rhs) > 0;
	}

	constexpr bool operator<=(const string_view &lhs, const char *rhs) {
		return !(lhs > rhs);
	}

	constexpr bool operator>=(const string_view &lhs, const char *rhs) {
		return !(lhs < rhs);
	}

	constexpr bool operator==(const char *lhs, const string_view &rhs) {
		return constr::strcmp(lhs, rhs.data()) == 0;
	}

	constexpr bool operator!=(const char *lhs, const string_view &rhs) {
		return !(lhs == rhs);
	}

	constexpr bool operator<(const char *lhs, const string_view &rhs) {
		return constr::strcmp(lhs, rhs.data()) < 0;
	}

	constexpr bool operator>(const char *lhs, const string_view &rhs) {
		return constr::strcmp(lhs, rhs.data()) > 0;
	}

	constexpr bool operator<=(const char *lhs, const string_view &rhs) {
		return !(lhs > rhs);
	}

	constexpr bool operator>=(const char *lhs, const string_view &rhs) {
		return !(lhs < rhs);
	}
}    // namespace constr
