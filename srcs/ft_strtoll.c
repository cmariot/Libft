/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:47:24 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/09 17:51:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * The ft_strtoll() function converts the string in str to a long long value.
 *
 * The string may begin with an arbitrary amount of white space
 * (as determined by isspace(3))
 * followed by a single optional ‘+’ or ‘-’ sign.
 *
 * The remainder of the string is converted to a long long value, 
 * stopping at the first character which is not a valid digit.
 *
 *  If endptr is not NULL, strtol() stores the address of the first invalid
 *  character in *endptr.
 *  If there were no digits at all, however,
 *  strtol() stores the  original value of str in *endptr.
 *  (Thus, if *str is not ‘\0’ but **endptr is ‘\0’ on return,
 *  the entire string was valid.)
 *
 * If the result if > to LONG_LONG_MAX, the endptr will be decreased,
 * so at the end, if the result is LONG_LONG_MAX and there still
 * have digit on endptr you must have to use a bigger type.
 * (LONG_LONG_OVERFLOW)
 */

#define LONG_LONG_MAX 9223372036854775807

int	ft_isspace(char c)
{
	if ((c == '\t' || c == '\n' || c == '\v')
		|| (c == '\f' || c == '\r' || c == 32))
		return (1);
	else
		return (0);
}

void	skip_spaces(const char *restrict str, size_t *i)
{
	if (ft_isspace(str[*i]) == TRUE)
		while (ft_isspace(str[*i]) == TRUE)
			(*i)++;
}

int	get_sign(const char *restrict str, size_t *i)
{
	if (str[*i] == '-' || str[*i] == '+')
		if (str[(*i)++] == '-')
			return (-1);
	return (1);
}

long long	ft_strtoll(const char *restrict str, char **restrict endptr)
{
	unsigned long long	result;
	int					sign;
	size_t				i;

	if (str == NULL || (*endptr) == NULL)
		return (0);
	i = 0;
	skip_spaces(str, &i);
	sign = get_sign(str, &i);
	if (ft_isdigit(str[i]) == FALSE)
		return (0);
	result = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]) == TRUE
		&& result < LONG_LONG_MAX)
	{
		result = result * 10 + str[i++] - '0';
		if (result > LONG_LONG_MAX)
		{
			i--;
			result = LONG_LONG_MAX;
			break ;
		}
	}
	(*endptr) += i;
	return (sign * result);
}
