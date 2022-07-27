#include <constr/string_view.hpp>

std::ostream &operator<<(std::ostream &o, const constr::string_view &str) {
	return o << str.c_str();
}
