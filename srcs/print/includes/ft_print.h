/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:26:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/02/02 14:42:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_flags
{
	va_list	args;
	int		fd;
	int		minus;
	int		zero;
	int		star_for_field_width;
	int		field_width;
	int		dot;
	int		star_for_precision;
	int		precision;
	int		total_print;
	int		minus_printed;
	int		pointer;
	int		blank;
	int		hashtag;
	int		plus;
}	t_flags;

/* This functiun works like the printf function. */
int				print(int fd, const char *format, ...);
/* All the struct variables are set to 0. */
void			initialize_flags(t_flags *flags, int fd);
/* Reset the struct variables to zero. */
void			reset_flags(t_flags *flags);
/* Print a char and return 1. */
int				ft_putchar_ret_fd(char c, int fd);
/* When we see a '%' we check the flags and put data in the structure. */
int				get_flags(const char *frmt, t_flags *flgs, unsigned int i);
/* We check if the specifier is correct. */
int				ft_is_in_type_list(int c);
/* We call the right function for the specifier. */
void			print_type(const char *frmt, unsigned int i, t_flags *flgs,
					int fd);
/* If %c print a char. */
void			ft_print_char(t_flags *flags, int fd);
/* If %s print a str. */
void			ft_print_str(t_flags *flags, int fd);
/* If %u print a unsigned int. */
void			ft_print_unsigned_int(t_flags *flags, int fd);
/* If %d or %i print an integer. */
void			ft_print_integer(t_flags *flags, int fd);
/* If %x convert an unsigned int to hexa (0123456789abcdef). */
void			ft_print_hexa(t_flags *flags, int fd);
/* If %X convert an unsigned int to hexa (0123456789ABCDEF). */
void			ft_print_hexa_maj(t_flags *flags, int fd);
/* If %p print the memory. */
void			ft_print_addr(t_flags *flags, int fd);
/* Print '%' if "%%" is given to ft_printf */
void			ft_print_percent(t_flags *flags, int fd);
/* If there is a flag that specifies a field width. */
void			ft_print_space(t_flags *flags, int len, int fd);
/* If there is a star flag we take a va_arg as field width. */
void			ft_field_width_star(t_flags *flags);
/* If there is a star flag after the dot the va_arg is for the precision. */
void			ft_precision_star(t_flags *flags);
/* Itoa for unsigned int. */
char			*ft_u_itoa(unsigned int n);
/* Print the string with the correct field_with & precision. */
void			ft_print(char *str, t_flags *flags, int fd);
/* In case of minus flag (without dot), print zero instead spaces. */
char			ft_c_is_zero(t_flags *flags, char *str, int fd);
/* Print the field width before the string. */
void			ft_space_before(t_flags *flags, int len, char *str, int fd);
/* Print the field width after the string. */
void			ft_space_after(t_flags *flags, int len, int fd);
/* Count the final len (with field width and precision) of a string */
int				ft_len_of_print(char *str, t_flags *flags);
/* Print the precision */
void			ft_print_precision(t_flags *flags, char **str, int initial_len,
					int fd);
/* If a precision is given for an address */
int				ft_print_0x(t_flags *flags, char ***str, int fd);
/* If a 0 is parsed set the zero element of the structure to 1 */
unsigned int	ft_set_zero(t_flags *flags);
/* If a * is parsed set the star element of the structure to 1 */
unsigned int	ft_set_star(t_flags *flags);
/* If a + is parsed set the plus element of the structure to 1 */
unsigned int	ft_set_plus(t_flags *flags);
/* Print the correct number of spaces for the field_width */
void			ft_print_fw(t_flags *flags, char *str, int i, char c);

#endif
