#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define printf_dec_format(x) _Generic((x), \
    char: "%c", \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    signed short: "%hd", \
    unsigned short: "%hu", \
    signed int: "%d", \
    unsigned int: "%u", \
    long int: "%ld", \
    unsigned long int: "%lu", \
    long long int: "%lld", \
    unsigned long long int: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char *: "%s", \
    void *: "%p")


#define printnl(x) printf(printf_dec_format(x), x), printf("\n");

// evaluates to true if an expression is compatible with the provided type
#define is_compatible(x, T) _Generic((x), T:1, default: 0)

// ensure that an expression, perhaps a function argument, is of a given type
#define ensure_type(p, t) _Static_assert(is_compatible(p, t), \
    "incorrect type for parameter '" #p "', expected " #t)


/* Get the name of a type */
#define typename(x) _Generic((x), _Bool: "_Bool", \
    char: "char", \
    signed char: "signed char", \
    unsigned char: "unsigned char", \
    short int: "short int", \
    unsigned short int: "unsigned short int", \
    int: "int", \
    unsigned int: "unsigned int", \
    long int: "long int", \
    unsigned long int: "unsigned long int", \
    long long int: "long long int", \
    unsigned long long int: "unsigned long long int", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    char *: "pointer to char", \
    void *: "pointer to void", \
    int *: "pointer to int", \
    default: "other")

int main(void)
{
    printnl('a');    // prints "97" (on an ASCII system)
    printnl((char)'a');  // prints "a"
    printnl(123);    // prints "123"
    printnl(1.234);      // prints "1.234000"
    printnl("abc");
    const int ci = 123;
    printnl(ci);

    printnl(is_compatible((size_t){0}, unsigned long));


    size_t s;
    ptrdiff_t p;
    intmax_t i;

    int ai[3] = {0};

    printf("size_t is '%s'\n", typename(s));
    printf("ptrdiff_t is '%s'\n", typename(p));
    printf("intmax_t is '%s'\n", typename(i));

    printf("character constant is '%s'\n", typename('0'));
    printf("0x7FFFFFFF is '%s'\n", typename(0x7FFFFFFF));
    printf("0xFFFFFFFF is '%s'\n", typename(0xFFFFFFFF));
    printf("0x7FFFFFFFU is '%s'\n", typename(0x7FFFFFFFU));
    printf("array of int is '%s'\n", typename(ai));
}