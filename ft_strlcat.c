/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:27:12 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/10 21:15:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

//     The strlcpy() and strlcat()
//     functions copy and concatenate
//     strings with the same input
//     parameters and output result as
//     snprintf(3)

//ft_strlcat() appends string src to the end of dst
//It will append at most dstsize - ft_strlen(dst) - 1 characters
//Il will then NULL terminate
//Unless dstsize is 0, or the original dst string was longer than dstsize
//strlcat() returns the total length of the string she tried to create.


#include <stdio.h>


size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{

/*	size_t dst_len;
	size_t src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (dst_len + src_len);
	else if (dst_len > dstsize)
		return (dst_len - src_len);
	while (dstsize-- - dst_len - 1)
	{
		*dst = *src++;
		printf("%c", *dst);
	}
	*dst = '\0';
	return (dst_len + src_len);
		
	//ft_strlcat() appends string src to the end of dst
	//It will append at most dstsize - ft_strlen(dst) - 1 characters
	//Il will then NULL terminate
	//Unless dstsize is 0, or the original dst string was longer than dstsize
	//strlcat() returns the total length of the string she tried to create.
*/
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (!dest_size)
		return (ft_strlen(src) + ft_strlen(dest));
	i = 0;
	while (src[i] && i + dest_len < dest_size - 1)
		dest[dest_len + i] = src[i++];
	dest[dest_len + i] = '\0';
	if (dest_size < dest_len + 1)
		return (src_len + dest_size);
	else
		return (src_len + dest_len);
}

int	main(void)
{
	char *dest;
	size_t result;

	dest = malloc(sizeof(char) * 16);
	ft_memset(dest, 'r', 15);

	printf("%s\n", dest);
	result = ft_strlcat(dest, "abc", 5);
	printf("%zu\n", result);





/*	char	*dst;
	char	*src;
	size_t	dstsize;
	size_t	result;


	dst = ft_strdup("test");
	src = ft_strdup("_strlcat");
	dstsize = ft_strlen(dst) + ft_strlen(src);

	printf("\ndst before strlcat = %s\n", dst);
	printf("src before strlcat = %s\n\n", src);
	
	result = ft_strlcat(dst, src, dstsize);
	
	printf("dst after strlcat = %s\n", dst);
	printf("src after strlcat = %s\n", src);
	
	printf("return (%zu);\n",result);

	return (0);
*/}
