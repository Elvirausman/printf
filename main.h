#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int zee_print_handle(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


/* Functions to print chars and strings */
int zee_get_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int zee_get_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int zee_get_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int zee_get_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int zee_get_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int zee_get_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int zee_get_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int zee_get_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int zee_get_upper_hexa(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int zee_get_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int zee_get_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print memory address */
int zee_get_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int zee_print_flags(const char *format, int *i);
int zee_print_width(const char *format, int *i, va_list list);
int zee_print_precision(const char *format, int *i, va_list list);
int zee_print_size(const char *format, int *i);

/*Function to print string in reverse*/
int zee_print_str_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int zee_print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int zee_handle_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int zee_handle_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int zee_handle_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int zee_handle_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int zee_handle_unsgned(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int zee_printable(char);
int zee_add_hexa_code(char, char[], int);
int zee_digit(char);

long int zee_size_number(long int num, int size);
long int zee_size_unsgned(unsigned long int num, int size);

#endif /* MAIN_H */

