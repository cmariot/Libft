# Projet Libft

Libft est un projet ayant pour but de coder en C une librairie de fonctions utiles dans les prochains projets.

Pour compiler la librairie et générer libft.a, il faut simplement taper la commande "make".</br>
Les commandes "make re", "make clean", "make fclean" et "make bonus" (liste chainées) sont égalenent displonibles.</br>
Pour compiler un programme qui utilise une fonction de la Libft, il s'uffit de compiler avec "gcc mon_programme.c libft.a"

<img width="1046" alt="Libft" src="https://user-images.githubusercontent.com/65048901/122075773-9d545580-cdfa-11eb-9ea3-c029d036e78f.png">

## Prototypes des fonctions :

<ul>
<li>int			ft_atoi(const char *str);</li>
<li>void		ft_bzero(void *b, size_t n);</li>
<li>void		*ft_calloc(size_t count, size_t size);</li>
<li>int			ft_isalnum(int c);</li>
<li>int			ft_isalpha(int c);</li>
<li>int			ft_isascii(int c);</li>
<li>int			ft_isdigit(int c);</li>
<li>int			ft_isprint(int c);</li>
<li>char		*ft_itoa(int n);</li>
<li>void		ft_lstadd_back(t_list **alst, t_list *new);</li>
<li>void		ft_lstadd_front(t_list **alst, t_list *new);</li>
<li>void		ft_lstclear(t_list **lst, void (*del)(void*));</li>
<li>void		ft_lstdelone(t_list *lst, void (*del)(void*));</li>
<li>void		ft_lstiter(t_list *lst, void (*f)(void *));</li>
<li>t_list		*ft_lstlast(t_list *lst);</li>
<li>t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));</li>
<li>t_list		*ft_lstnew(void *content);</li>
<li>int			ft_lstsize(t_list *lst);</li>
<li>void		*ft_memset(void *b, int c, size_t len);</li>
<li>void		*ft_memccpy(void *dst, const void *src, int c, size_t n);</li>
<li>void		*ft_memchr(const void *s, int c, size_t n);</li>
<li>int			ft_memcmp(const void *s1, const void *s2, size_t n);</li>
<li>void		*ft_memcpy(void *dst, const void *src, size_t n);</li>
<li>void		*ft_memmove(void *dst, const void *src, size_t len);</li>
<li>void		ft_putchar_fd(char c, int fd);</li>
<li>void		ft_putendl_fd(char *s, int fd);</li>
<li>void		ft_putnbr_fd(int n, int fd);</li>
<li>void		ft_putstr_fd(char *s, int fd);</li>
<li>char		**ft_split(char const *s, char c);</li>
<li>char		*ft_strchr(const char *s, int c);</li>
<li>char		*ft_strdup(const char *s1);</li>
<li>char		*ft_strjoin(char const *s1, char const *s2);</li>
<li>size_t		ft_strlcat(char *dest, const char *src, size_t dest_size);</li>
<li>size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);</li>
<li>size_t		ft_strlen(const char *s);</li>
<li>char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));</li>
<li>int			ft_strncmp(const char *s1, const char *s2, size_t n);</li>
<li>char		*ft_strnstr(const char *str, const char *to_find, size_t len);</li>
<li>char		*ft_strrchr(const char *s, int c);</li>
<li>char		*ft_strtrim(char const *s1, char const *set);</li>
<li>char		*ft_substr(char const *s, unsigned int start, size_t len);</li>
<li>int			ft_tolower(int c);</li>
<li>int			ft_toupper(int c);</li>
</ul>
