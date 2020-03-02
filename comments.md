-1 else-if in your vector op+ is redundant - if isn't not >= then by definition it's less

-1 Euler constructor should use initialization list

-2 vector size constructor should be explicit

-4 op= throws an exception when trying to copy a zero-size vector - your handling of zero-size vectors is inconsistent (if you consider a zero-size vec to be an invalid state, then you shouldn't allow one to be constructed)

-1 Euler constructor arguments are out of order

-10 segfault/illegal memory access in extraction operator - check your clear() logic

-1 scalar * vec should support arguments in opposite direction

Size constructor is incorrect - you appear to be treating size as capacity/available

-2 vector is missing some template type preconditions (e.g. resize calls op= for T)

-3 Euler method shouldn't be wrapped into the differential equation itself (in SIRD), it should be part of Euler class

-4 Driver doesn't check for correct number of args

-1 Euler doesn't check for negative step size

-1 Euler doesn't use your vector class - shouldn't be included on UML

-1 Types are incorrect in UML - your SIRD model member variables don't match the code

apply should be templated on its arg type for performance

-1 Mismatch between header file and class name
Your score is:
67
