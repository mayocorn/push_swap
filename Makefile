# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 17:09:48 by mayocorn          #+#    #+#              #
#    Updated: 2022/06/17 17:27:13 by mayocorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = ./src/
OBJDIR = ./obj/
# SRCS = 
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:%.c=%.o)))
DEPS = $(OBJS:%.o=%.d)
# LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $@
	ar -rcs $@ $(OBJS) 

$(OBJDIR):
	mkdir obj

-include $(DEPS)

all: $(NAME)

bonus: all

clean: 
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re