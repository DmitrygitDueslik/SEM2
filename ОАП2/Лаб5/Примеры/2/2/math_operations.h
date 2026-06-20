#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

extern "C" {
	EXPORT double add ( double a, double b );
	EXPORT double subtract ( double a, double b );
	EXPORT double multiply ( double a, double b );
	EXPORT double divide ( double a, double b );
}

#endif // MATH_OPERATIONS_H
