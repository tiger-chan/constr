#if !defined(CONSTR_STRING_UTIL_HPP__)
#	define CONSTR_STRING_UTIL_HPP__

#	include "fwd.hpp"
#	include <cstdio>    // for EOF

namespace constr {
	/**
	 * @brief Converts the given character to lowercase according to the
	 * character conversion rules defined by the currently installed C locale.
	 * 
	 * In the default "C" locale, the following uppercase letters 
	 * ABCDEFGHIJKLMNOPQRSTUVWXYZ are replaced with respective
	 * lowercase letters abcdefghijklmnopqrstuvwxyz.
	 * 
	 * @param ch character to be converted. If the value of ch is not representable
	 * as unsigned char and does not equal EOF, the behavior is undefined
	 * @return Lowercase version of ch or unmodified ch if no lowercase version
	 * is listed in the current C locale.
	 */
	constexpr int32 tolower(int32 ch);

	/**
	 * @brief Converts the given character to uppercase according to the character
	 * conversion rules defined by the currently installed C locale.
	 * 
	 * In the default "C" locale, the following lowercase letters
	 * abcdefghijklmnopqrstuvwxyz are replaced with respective
	 * uppercase letters ABCDEFGHIJKLMNOPQRSTUVWXYZ.
	 * 
	 * @param ch character to be converted. If the value of `ch` is not representable
	 * as unsigned char and does not equal `EOF`, the behavior is undefined.
	 * @return Converted character or ch if no uppercase version is defined by the current C locale.
	 */
	constexpr int32 toupper(int32 ch);

	/**
	 * @brief Returns the length of the given byte string, that is, the number
	 * of characters in a character array whose first element is pointed to by
	 * str up to and not including the first null character. The behavior is
	 * undefined if there is no null character in the character array pointed to by str.
	 * 
	 * @param str pointer to the null-terminated byte string to be examined
	 * @return The length of the null-terminated string str.
	 */
	constexpr uint32 strlen(const char *str);

	/**
	 * @brief Appends a copy of the character string pointed to by src
	 * to the end of the character string pointed to by dest. The 
	 * character src[0] replaces the null terminator at the end of dest.
	 * The resulting byte string is null-terminated.
	 * 
	 * The behavior is undefined if the destination array is not large enough
	 * for the contents of both src and dest and the terminating null character.
	 * 
	 * The behavior is undefined if the strings overlap.
	 * 
	 * @note Because strcat needs to seek to the end of dest on each call,
	 * it is inefficient to concatenate many strings into one using strcat.
	 * 
	 * @example
	 * int main() {
	 * 	char str[50] = "Hello ";
	 * 	char str2[50] = "World!";
	 * 	tt::strcat(str, str2);
	 * 	tt::strcat(str, " Goodbye World!");
	 *	std::cout << str << "\n";
	 *	// Outputs: Hello World! Goodbye World!\n
	 * }
	 * 
	 * @param dest pointer to the null-terminated byte string to append to
	 * @param src pointer to the null-terminated byte string to copy from
	 * @return dest
	 */
	constexpr char *strcat(char *dest, const char *src);

	/**
	 * @brief Copies the character string pointed to by src, including the null terminator, to the character array whose first element 
	 * is pointed to by dest.
	 * 
	 * The behavior is undefined if the dest array is not large enough. The behavior is undefined if the strings overlap.
	 * 
	 * @param dest 	pointer to the character array to write to
	 * @param src 	pointer to the null-terminated byte string to copy from
	 * @return dest
	 */
	constexpr char *strcpy(char *dest, const char *src);

	/**
	 * @brief Copies at most count characters of the byte string pointed to by src (including the terminating null character) to 
	 * character array pointed to by dest.
	 * 
	 * If count is reached before the entire string src was copied, the resulting character array is not null-terminated.
	 * 
	 * If, after copying the terminating null character from src, count is not reached, additional null characters are written to dest 
	 * until the total of count characters have been written.
	 * 
	 * If the strings overlap, the behavior is undefined.
	 * 
	 * @param dest pointer to the character array to copy to
	 * @param src pointer to the byte string to copy from
	 * @param count maximum number of characters to copy
	 * @return dest
	 */
	constexpr char *strncpy(char *dest, const char *src, uint32 count);

	/**
	 * @brief Copies the value `ch` into each of the first count characters of the object pointed to by dest. If the object is a 
	 * potentially-overlapping subobject the behavior is undefined. If count is greater than the size of the object pointed to by dest, 
	 * the behavior is undefined.
	 * 
	 * @param dest pointer to the character array to fill
	 * @param ch fill character
	 * @param count number of characters to fill
	 * @return dest
	 */
	constexpr char *strset(char *dest, char ch, uint32 count);

	/**
	 * @brief Compares two null-terminated byte strings lexicographically.
	 * 
	 * The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as 
	 * unsigned char) that differ in the strings being compared.
	 * 
	 * The behavior is undefined if lhs or rhs are not pointers to null-terminated strings.
	 * 
	 * @param lhs pointer to null-terminated byte strings to compare
	 * @param rhs pointer to null-terminated byte strings to compare
	 * @return Negative value if lhs appears before rhs in lexicographical order.
	 * 
	 * Zero if lhs and rhs compare equal.
	 * 
	 * Positive value if lhs appears after rhs in lexicographical order.
	 */
	constexpr int32 strcmp(const char *lhs, const char *rhs);

	/**
	 * @brief Compares two null-terminated byte strings lexicographically insensitive to case.
	 * 
	 * The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as 
	 * unsigned char) that differ in the strings being compared.
	 * 
	 * The behavior is undefined if lhs or rhs are not pointers to null-terminated strings.
	 * 
	 * @param lhs pointer to null-terminated byte strings to compare
	 * @param rhs pointer to null-terminated byte strings to compare
	 * @return Negative value if lhs appears before rhs in lexicographical order.
	 * 
	 * Zero if lhs and rhs compare equal.
	 * 
	 * Positive value if lhs appears after rhs in lexicographical order.
	 */
	constexpr int32 stricmp(const char *lhs, const char *rhs);

	/**
	 * @brief Compares at most count characters of two possibly null-terminated arrays. The comparison is done lexicographically. 
	 * Characters following the null character are not compared.
	 * 
	 * The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as 
	 * unsigned char) that differ in the arrays being compared.
	 * 
	 * The behavior is undefined when access occurs past the end of either array lhs or rhs. The behavior is undefined when either lhs 
	 * or rhs is the null pointer.
	 * 
	 * @param lhs pointer to null-terminated byte strings to compare
	 * @param rhs pointer to null-terminated byte strings to compare
	 * @param count maximum number of characters to compare
	 * @return Negative value if lhs appears before rhs in lexicographical order.
	 * 
	 * Zero if lhs and rhs compare equal.
	 * 
	 * Positive value if lhs appears after rhs in lexicographical order.
	 */
	constexpr int32 strncmp(const char *lhs, const char *rhs, uint32 count);

	/**
	 * @brief Compares at most count characters of two possibly null-terminated arrays. The comparison is done lexicographically. 
	 * Characters following the null character are not compared.
	 * 
	 * The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as 
	 * unsigned char) that differ in the arrays being compared.
	 * 
	 * The behavior is undefined when access occurs past the end of either array lhs or rhs. The behavior is undefined when either lhs 
	 * or rhs is the null pointer.
	 * 
	 * @param lhs pointer to null-terminated byte strings to compare
	 * @param rhs pointer to null-terminated byte strings to compare
	 * @param count maximum number of characters to compare
	 * @return Negative value if lhs appears before rhs in lexicographical order.
	 * 
	 * Zero if lhs and rhs compare equal.
	 * 
	 * Positive value if lhs appears after rhs in lexicographical order.
	 */
	constexpr int32 strnicmp(const char *lhs, const char *rhs, uint32 count);

	template<typename char_t>
	struct char_traits {
		using char_type = char_t;
		using int_type = int;

		static constexpr char_type to_char_type(int_type i) {
			return char_type(i);
		}

		static constexpr int_type to_int_type(char_type c) {
			return int_type(c);
		}

		static constexpr bool eq_int_type(int_type c1, int_type c2) {
			return c1 == c2;
		}

		static constexpr int_type eof() {
			return int_type(EOF);
		}

		static constexpr int_type not_eof(int_type c) {
			return eq_int_type(c, eof()) ? ~eof() : c;
		}
	};
}    // namespace constr

#	include "string_util.inl"

#endif    // CONSTR_STRING_UTIL_HPP__
