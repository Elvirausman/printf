#include "main.h"

void zee_get_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				zee_get_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			zee_get_buffer(buffer, &buff_ind);
			flags = zee_print_flags(format, &i);
			width = zee_print_width(format, &i, list);
			precision = zee_print_precision(format, &i, list);
			size = zee_print_size(format, &i);
			++i;
			printed = zee_print_handle(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	zee_get_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * zee_get_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void zee_get_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
