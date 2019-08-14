# Rootfinding
C++ Rootfinding Project: A library of root-finding functions utilizing modern C++ to code straightforward and intuitive methods of root-finding.

## Table of Contents
* [Introduction](#introduction)
* [Installation](#installation)
* [Available functions](#functions)
  - [Steffensen's Method](#steffensen)
  - [Bisection Method](#bisection)
* [References](#references)

## <a name = "introduction"></a> Introduction
With the implementation of lambdas in modern C++, it has become easier to perform operations on functions. With this library, we hope to create a library of .h header files to make rootfinding in C++ more simple and less time-consuming. The .h files included in this library do not have any other dependencies and work on any compilier.

## <a name = "installation"></a> Installation
There are no special actions needed for installation or compilation. Download the desired header file for your project and use 
```cpp 
#include "[file_name].h" 
``` 
in your .cpp or .h file to use the functions in the header file.

## <a name = "functions"></a> Available functions
### <a name = "steffensen"></a> Steffensen's Method
The basic formula for Steffensen's Method is:

x<sub>n</sub> = x<sub>n-1</sub>

### <a name = "bisection"></a> Bisection Method
The basic formula for the bisection method is:


## <a name = "references"></a> References
[1] R.L Burden and J. D. Faires, *Numerical Analysis*, 5th ed., PWS Publishing Company, Boston, MA, 1993

[2] K.E. Atkinson, *An Introduction to Numerical Analysis*, 2nd ed., John Wiley and Sons, Inc., Hoboken, NJ, 1989

[3] S.D. Conte and C de Boor, *Elementary Numerical Analysis: An Algorithmic Approach*, 3rd ed., McGraw-Hill Book Company, New York City, New York, 1980

[4] L. Råde and B. Westergren, *Mathematics Handbook for Science and Engineering*, 5th Ed. Springer-Verlag, Berlin, Heidelberg, 2010

[5] J. Solomon, *Numerical Algorithms: Methods for Computer Vision, Machine Learning*, and Graphics, CRC Press, Boca Raton, FL, 2015
