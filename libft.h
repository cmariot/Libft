#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
char 	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t  ft_strlcat(char *dest, char *src, size_t dest_size);
char    *ft_strnstr(const char *str, const char *to_find, size_t len);

#endif
