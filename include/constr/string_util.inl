#include "string_util.hpp"

namespace constr {
	namespace details {
		namespace str {
			constexpr int32 case_sensitive_comp(uint8 l, uint8 r) {
				return l == r ? 0 : (l < r ? -1 : 1);
			}

			constexpr int32 case_insensitive_comp(uint8 lhs, uint8 rhs) {
				return lhs == rhs ? 0 : ((lhs | 32) < (rhs | 32) ? -1 : 1);
			}

			using str_comparer = int32 (*)(uint8, uint8);
			constexpr int32 strcmp(const char *lhs, const char *rhs, str_comparer cmp) {
				if (lhs == rhs) {
					return 0;
				}

				for (; *lhs && *rhs && cmp(*lhs, *rhs) == 0; ++lhs, ++rhs) {
					// just loop until either sting ends or they aren't equal
				}

				return cmp(*lhs, *rhs);
			}

			constexpr int32 strncmp(const char *lhs, const char *rhs, uint32 count, str_comparer cmp) {
				if (lhs == rhs) {
					return 0;
				}

				for (; *lhs && *rhs && count && cmp(*lhs, *rhs) == 0; ++lhs, ++rhs, --count) {
					// just loop until either sting ends or they aren't equal
				}

				if (!count) {
					--lhs, --rhs;
				}

				return cmp(*lhs, *rhs);
			}
		}    // namespace str
	}    // namespace details
}    // namespace constr

namespace constr {
	constexpr int32 tolower(int32 ch) {
		uint8 c = ch;
		if (c < 'A' || 'Z' < c) {
			return c;
		}
		return c - ('A' - 'a');
	}

	constexpr int32 toupper(int32 ch) {
		uint8 c = ch;
		if (c < 'a' || 'z' < c) {
			return c;
		}
		return c + ('A' - 'a');
	}

	constexpr uint32 strlen(const char *str) {
		if (!str) {
			return 0;
		}
		const char *ptr = str;
		for (; *ptr; ++ptr) {
			// Just counting as many non '\0' characters
		}
		return uint32(ptr - str);
	}

	constexpr char *strcat(char *dest, const char *src) {
		for (; *dest; ++dest) {
			// Find end of string
		}

		return strcpy(dest, src);
	}

	constexpr char *strcpy(char *dest, const char *src) {
		char *d = dest;
		for (; *src; ++d, ++src) {
			*d = *src;
		}
		return dest;
	}

	constexpr char *strncpy(char *dest, const char *src, uint32 count) {
		char *d = dest;
		uint32 i = 0;
		for (; *src && i < count; ++i, ++d, ++src) {
			*d = *src;
		}
		for (; i < count; ++i, ++d) {
			*d = '\0';
		}

		return dest;
	}

	constexpr char *strset(char *dest, char ch, uint32 count) {
		char *d = dest;
		for (; count; --count, ++d) {
			*d = ch;
		}
		return dest;
	}

	constexpr int32 strcmp(const char *lhs, const char *rhs) {
		return details::str::strcmp(lhs, rhs, details::str::case_sensitive_comp);
	}

	constexpr int32 stricmp(const char *lhs, const char *rhs) {
		return details::str::strcmp(lhs, rhs, details::str::case_insensitive_comp);
	}

	constexpr int32 strncmp(const char *lhs, const char *rhs, uint32 count) {
		return details::str::strncmp(lhs, rhs, count, details::str::case_sensitive_comp);
	}

	constexpr int32 strnicmp(const char *lhs, const char *rhs, uint32 count) {
		return details::str::strncmp(lhs, rhs, count, details::str::case_insensitive_comp);
	}
}    // namespace constr
