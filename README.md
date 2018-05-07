# Fuzzy logic
This is a simple implementation of fuzzy logic in C++. Its just a little exercise on operator overloading.

## Example
``` cpp
FBool t = true; //= is overloaded for bool
FBool f = 0.3f; //and for float

//&&, || and ! are overloaded
FBool x = t && f;
FBool y = t || f;
FBool z = t && !f;

//<< is overloaded
std::cout << "t=" << t << " f=" << f << std::endl;
std::cout << "x=" << x << " y=" << y << " z=" << z << std::endl;
```
This would output
```
t=T(1) f=F(0.3)
x=F(0.3) y=T(1) z=T(0.7)
```
[Fuzzy logic](https://en.wikipedia.org/wiki/Fuzzy_logic) on Wikipedia