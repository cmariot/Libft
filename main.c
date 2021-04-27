/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:35:33 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/27 19:49:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <time.h>
#include <execinfo.h>
#include <locale.h>
#include <sys/mman.h>
#include <errno.h>
#include <sys/time.h>
#include <stdarg.h>

void	*electric_alloc(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr + 4096, 4096, PROT_NONE);
	return (ptr + 4096 - size);
}

int main(void)
{
/*        const char	*str;
	int		is_alpha;
	int		is_digit;
	int		is_alnum;
	int		is_ascii;
	int		is_print;
	int		to_upper;
	int		to_lower;
	const char	*constr;
	int		c;
	const char	*constr2;
        size_t		n;
	char		*src;


	str = "compte";
        printf("ft_strlen %s : %zu\n", str, ft_strlen(str));

	is_alpha = 'A';
	printf("ft_isalpha %c : %d\n", is_alpha, ft_isalpha(is_alpha));
	printf("isalpha %c : %d\n", is_alpha, isalpha(is_alpha));

	is_digit = '1';
	printf("ft_isdigit %c : %d\n", is_digit, ft_isdigit(is_digit));
	printf("isdigit %c : %d\n", is_digit, isdigit(is_digit));
	
	is_alnum = 'Z';
	printf("ft_isalnum %c : %d\n", is_alnum, ft_isalnum(is_alnum));
	printf("isalnum %c : %d\n", is_alnum, isalnum(is_alnum));
	
	is_ascii = 128;
	printf("ft_isascii %c : %d\n", is_ascii, ft_isascii(is_ascii));
	printf("isascii %c : %d\n", is_ascii, isascii(is_ascii));
	
	is_print = 32;
	printf("ft_isprint %c : %d\n", is_print, ft_isprint(is_print));
	printf("isprint %c : %d\n", is_print, isprint(is_print));
	
	to_upper = 'a';
	printf("ft_toupper %c : %d\n", to_upper, ft_toupper(to_upper));
	printf("toupper %c : %d\n", to_upper, toupper(to_upper));

	to_lower = 'A';
	printf("ft_tolower %c : %d\n", to_lower, ft_tolower(to_lower));
	printf("tolower %c : %d\n", to_lower, tolower(to_lower));

	constr = "First occurence";
	c = '\0';
	printf("ft_strchr %c dans %s : %s\n", c, constr, ft_strchr(constr, c));
	printf("strchr %c dans %s : %s\n", c, constr, strchr(constr, c));

	constr = "Last occurence";
	c = 'Z';
	printf("ft_strrchr %c dans %s : %s\n", c, constr, ft_strrchr(constr, c));
	printf("strrchr %c dans %s : %s\n", c, constr, strrchr(constr, c));

	constr2 = "Last occurence";
	n = 20;
	printf("ft_strncmp de %s VS %s sur %zu char : %d\n", constr, constr2, n, ft_strncmp(constr, constr2, n));
	printf("strncmp de %s VS %s sur %zu char : %d\n", constr, constr2, n, strncmp(constr, constr2, n));

	src = "COPIE MOI";
	char	dest[10];
	printf("ft_strlcpy : %lu\n", ft_strlcpy(dest, src, ft_strlen(dest)));
	printf("strlcpy : %lu\n", strlcpy(dest, src, ft_strlen(dest)));
	
	src = "COPIE MOI";
	char	dest2[3] = "ICI";
	printf("ft_strlcat : %lu\n", ft_strlcat(dest2, src, ft_strlen(dest2)));
	printf("strlcat : %lu\n", strlcat(dest2, src, ft_strlen(dest2)));

	const char *haystack = "TROUVE TOTO";
	const char *needle = "TOTO";
	size_t size = 20; 
	printf("ft_strnstr : %s\n", ft_strnstr(haystack, needle, size));
	printf("strnstr : %s\n", strnstr(haystack, needle, size));

	const char *atoi_str;
	atoi_str = "   \t \n \r \v -9823456789998123456776543210";
	printf("ft_atoi %s : %d\n", atoi_str, ft_atoi(atoi_str));
	printf("atoi %s : %d\n", atoi_str, atoi(atoi_str));

	char test[100] = "Salut";
	printf("memset : %s\n", memset(test, '$', 3));
	printf("ft_memset : %s\n", ft_memset(test, '$', 3));

	int		file_descriptor;
	file_descriptor = open("./test.txt", O_RDWR, O_APPEND);
	file_descriptor = 1;	
	ft_putchar_fd('X', file_descriptor);
	ft_putendl_fd("TEST@", file_descriptor);
	ft_putnbr_fd(100234, file_descriptor);
	ft_putstr_fd("NOTUVEAU TEST", file_descriptor);

	char *src;
	src = "test pour voir";
	printf("%s\n", ft_strdup(src));
	printf("%s\n", strdup(src));

	char *s1;
	char *s2;
	s1 = "Concatene ";
	s2 = "moi !";
	printf("%s\n", ft_strjoin(s1, s2));

	char *str;
	unsigned int start;
	size_t	len;
	str = "SUB MOI CETTE STR";
	start = 4;
	len = 3;
	printf("%s\n", ft_substr(str, start, len));

	char const *s1;
	char const *set;

	s1 = "-SALUT-";
	set = "-";
	printf("%s\n", ft_strtrim(s1, set));

	char **strs;
	strs = ft_split("      split       this for   me  !       ", ' ');
	int i = 0;
	while (i < 5)
	{
		printf("%s\n", strs[i]);
		i++;
	}

*/
//	ft_itoa(-2147483648LL);
//	ft_strrchr("0123456789", 9999999);











	return (0);
}
