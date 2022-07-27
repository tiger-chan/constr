#if !defined(CONSTR_MACRO_HPP__)
#	define CONSTR_MACRO_HPP__

// https://stackoverflow.com/a/4840428/3261668
#	define CONSTR_ALIGN_UP(x, a) (((x) + (a - 1)) & ~(a - 1))
#	define CONSTR_ALIGN_DOWN(x, a) ((x) & ~(a - 1))

#	define CONSTR_STR(str) #str


#ifndef CONSTR_EXPORT
#	if defined _WIN32 || defined __CYGWIN__ || defined _MSC_VER
#		define CONSTR_EXPORT __declspec(dllexport)
#		define CONSTR_IMPORT __declspec(dllimport)
#		define CONSTR_HIDDEN
#	elif defined __GNUC__ && __GNUC__ >= 4
#		define CONSTR_EXPORT __attribute__((visibility("default")))
#		define CONSTR_IMPORT __attribute__((visibility("default")))
#		define CONSTR_HIDDEN __attribute__((visibility("hidden")))
#	else /* Unsupported compiler */
#		define CONSTR_EXPORT
#		define CONSTR_IMPORT
#		define CONSTR_HIDDEN
#	endif
#endif

#ifndef CONSTR_API
#	if defined ConStr_EXPORT
#		define CONSTR_API CONSTR_EXPORT
#	elif defined ConStr_IMPORT
#		define CONSTR_API CONSTR_IMPORT
#	else /* No API */
#		define CONSTR_API
#	endif
#endif

#endif    // CONSTR_MACRO_HPP__
