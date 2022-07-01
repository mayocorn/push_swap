# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 17:09:48 by mayocorn          #+#    #+#              #
#    Updated: 2022/07/02 00:32:41 by mayocorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	src/main.c \
			src/array/check_unique.c \
			src/array/convert_array_stoi.c \
			src/array/duplicate_int_array.c \
			src/console_out/print_commands.c \
			src/coordinate_compression/coordinate_compression.c \
			src/deque/create_deque.c \
			src/deque/create_node.c \
			src/deque/delete_deque.c \
			src/deque/disjoint_node.c \
			src/deque/get_minelement.c \
			src/deque/pop_and_push.c \
			src/deque/popback.c \
			src/deque/popfront.c \
			src/deque/pushback.c \
			src/deque/pushfront.c \
			src/divide/check_div_abbbbf.c \
			src/divide/check_div_abbfbb.c \
			src/divide/check_div_afabbb.c \
			src/divide/check_div_afbbab.c \
			src/divide/check_div_afbbbf.c \
			src/divide/check_div_afbfbb.c \
			src/divide/check_div_bbabbf.c \
			src/divide/check_div_bbbfab.c \
			src/divide/check_div_bfabbb.c \
			src/divide/check_div_bfbbab.c \
			src/divide/create_div_info.c \
			src/divide/divide.c \
			src/libft/ft_isdigit.c \
			src/libft/ft_memmove.c \
			src/mergesort/mergesort.c \
			src/optimize/optimize.c \
			src/optimize/optimize_each_command.c \
			src/optimize/optimize_pa.c \
			src/optimize/optimize_pa_sub.c \
			src/optimize/optimize_pb.c \
			src/optimize/optimize_pb_sub.c \
			src/optimize/optimize_ra.c \
			src/optimize/optimize_rb.c \
			src/optimize/optimize_rra.c \
			src/optimize/optimize_rra_sub.c \
			src/optimize/optimize_rrb.c \
			src/optimize/optimize_rrb_sub.c \
			src/optimize/optimize_sametime_command.c \
			src/pushswap/delete_back.c \
			src/pushswap/move_hold.c \
			src/pushswap/pushswap.c \
			src/pushswap/sort_a_back.c \
			src/pushswap/sort_a_front.c \
			src/pushswap/sort_a_maxvalue.c \
			src/pushswap/sort_a_start.c \
			src/pushswap/sort_b_back.c \
			src/pushswap/sort_b_front.c \
			src/pushswap/sort_b_minvalue.c \
			src/pushswap/sort_next_division.c \
			src/utils/free_and_setnull.c \
			src/utils/ft_exit.c \
			src/utils/malloc_and_checknull.c

OBJDIR	=	./obj/
OBJS	=	$(addprefix $(OBJDIR), $(notdir $(SRCS:%.c=%.o)))

DEPS	=	$(OBJS:%.o=%.d)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

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