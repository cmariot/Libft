# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:57:32 by cmariot           #+#    #+#              #
#    Updated: 2022/02/11 19:38:09 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME		= libft.a

PRINT_DIR	= srcs/print

# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I ./includes
INCLUDES	+= -I ./srcs/print/includes

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

DIRSRC		= srcs/

DIROBJ		= objs/

SRC			= colors.c \
			  ft_arraylen.c \
			  ft_atoi.c \
			  ft_atoi_base.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_free_array.c \
			  ft_intlen.c \
			  ft_isadirectory.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_is_in_str.c \
			  ft_isprint.c \
			  ft_itoa.c \
			  ft_join_array.c \
			  ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstlast.c \
			  ft_lstmap.c \
			  ft_lstnew.c \
			  ft_lstsize.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_putarray.c \
			  ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr.c \
			  ft_putnbr_base.c \
			  ft_putnbr_fd.c \
			  ft_putstack.c \
			  ft_putstr.c \
			  ft_putstr_fd.c \
			  ft_realloc.c \
			  ft_split.c \
			  ft_strchr.c \
			  ft_strcmp.c \
			  ft_strdup.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strmapi.c \
			  ft_strncmp.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_strtoll.c \
			  ft_strtrim.c \
			  ft_substr.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  get_next_line.c \
			  gnl_without_backslash_n.c

OBJ			:= $(SRC:.c=.o)

DIROBJS		= $(addprefix $(DIROBJ), $(OBJ))

SRCS		= $(addprefix $(SRC_DIR), $(SRC))


# **************************************************************************** #
#                                COLORS                                        #
# **************************************************************************** #

GREEN		= \033[32;1m
RED			= \033[31;1m
YELLOW		= \033[33;1m
CYAN		= \033[36;1m
RESET		= \033[0m


# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #

.SILENT : all

all : header $(NAME)

$(DIROBJ)%.o: $(DIRSRC)%.c
		@mkdir -p $(DIROBJ)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(NAME)	: $(DIROBJS)
		@make --no-print-directory -C $(PRINT_DIR)
		ar rcs $(NAME) $(DIROBJS)

norm :
		@norminette

clean :
		@make --no-print-directory -C $(PRINT_DIR) clean
		@rm -rf $(DIROBJ)
		@printf "$(RED)"
		@printf "Object files removed.\n"
		@printf "$(RESET)"

fclean :
		@make --no-print-directory -C $(PRINT_DIR) fclean
		@rm -f $(NAME)
		@rm -rf $(DIROBJ)
		@printf "$(RED)"
		@printf "Object files and libraries removed.\n"
		@printf "$(RESET)"

re :	 fclean all

header :
		@printf "$(CYAN)"
		@printf "LIBFT COMPILATION\n"
		@printf "$(RESET)"

.PHONY : clean fclean
