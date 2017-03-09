#include "libftprintf.h"

intmax_t ft_smodifier(t_conv *flags, void *arg) //shuld i return pointer or value (if pointer ami right with this function)
{
	if (flags->output == 'D')
	{
		flags->output = 'd';
		flags->letter < 3 ? flags->letter = 3 : 0;
	}
	if ((flags->output == 'd' || flags->output == 'i') && flags->letter != 0)
	{
		if (flags->letter == 1)
			return ((signed char)arg);
		if (flags->letter == 2)
			return ((short) arg);
		if (flags->letter == 3)
			return ((long) arg);
		if (flags->letter == 4)
			return ((long long) arg);
		if (flags->letter == 5)
			return ((intmax_t) arg);
		if (flags->letter == 6)
			return ((long)arg);
	}
	return ((int) arg);
}

uintmax_t ft_umodifier(t_conv *flags, void *arg) //not done yet
{
	if (flags->output == 'O')
	{
		flags->output = 'o';
		flags->letter < 3 ? flags->letter = 3 : 0;
	}
	if (flags->output == 'U')
	{
		flags->output = 'u';
		flags->letter < 3 ? flags->letter = 3 : 0;
	}
	if ((flags->output == 'o' || flags->output == 'u' || flags->output == 'x' || flags->output == 'X')
		&& flags->letter != 0)
	{
		if (flags->letter == 1)
			return ((unsigned char) arg);
		if (flags->letter == 2)
			return ((unsigned short) arg);
		if (flags->letter == 3)
			return ((unsigned long) arg);
		if (flags->letter == 4)
			return ((unsigned long long) arg);
		if (flags->letter == 5)
			return ((uintmax_t) arg);
		if (flags->letter == 6)
			return ((size_t)arg);
	}
	return ((unsigned int) arg);
}
