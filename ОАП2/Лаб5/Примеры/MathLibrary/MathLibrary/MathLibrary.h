#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHAPI __declspec(dllexport)
#else
#define MATHAPI __declspec(dllimport)
#endif

MATHAPI double add ( double a, double b );
MATHAPI double subtract ( double a, double b );
MATHAPI double multiply ( double a, double b );
MATHAPI double divide ( double a, double b );