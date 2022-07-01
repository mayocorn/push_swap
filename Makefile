# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 17:09:48 by mayocorn          #+#    #+#              #
#    Updated: 2022/07/02 03:41:18 by mayocorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

SRCDIR  = ./src/
SRCS    = main.c \
          array/check_unique.c \
          array/duplicate_int_array.c \
          array/convert_array_stoi.c \
          console_out/print_commands.c \
          coordinate_compression/coordinate_compression.c \
          deque/create_deque.c \
          deque/create_node.c \
          deque/delete_deque.c \
          deque/disjoint_node.c \
          deque/get_minelement.c \
          deque/pop_and_push.c \
          deque/popback.c \
          deque/popfront.c \
          deque/pushback.c \
          deque/pushfront.c \
          divide/check_div_abbbbf.c \
          divide/check_div_abbfbb.c \
          divide/check_div_afabbb.c \
          divide/check_div_afbbab.c \
          divide/check_div_afbbbf.c \
          divide/check_div_afbfbb.c \
          divide/check_div_bbabbf.c \
          divide/check_div_bbbfab.c \
          divide/check_div_bfabbb.c \
          divide/check_div_bfbbab.c \
          divide/create_div_info.c \
          divide/divide.c \
          libft/ft_isdigit.c \
          libft/ft_memmove.c \
          mergesort/ft_mergesort.c \
          optimize/optimize.c \
          optimize/optimize_each_command.c \
          optimize/optimize_pa.c \
          optimize/optimize_pa_sub.c \
          optimize/optimize_pb.c \
          optimize/optimize_pb_sub.c \
          optimize/optimize_ra.c \
          optimize/optimize_rb.c \
          optimize/optimize_rra.c \
          optimize/optimize_rra_sub.c \
          optimize/optimize_rrb.c \
          optimize/optimize_rrb_sub.c \
          optimize/optimize_sametime_command.c \
          pushswap/delete_back.c \
          pushswap/move_hold.c \
          pushswap/pushswap.c \
          pushswap/sort_a_back.c \
          pushswap/sort_a_front.c \
          pushswap/sort_a_maxvalue.c \
          pushswap/sort_a_start.c \
          pushswap/sort_b_back.c \
          pushswap/sort_b_front.c \
          pushswap/sort_b_minvalue.c \
          pushswap/sort_next_division.c \
          utils/free_and_setnull.c \
          utils/ft_exit.c \
          utils/ft_min.c \
          utils/malloc_and_checknull.c

OBJDIR  = ./obj/
OBJS    = $(addprefix $(OBJDIR), $(SRCS:%.c=%.o))

DEPS    = $(OBJS:%.o=%.d)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJDIR):
	mkdir obj

-include $(DEPS)

.PHONY: all
all: $(NAME)

# bonus: all

.PHONY: clean
clean: 
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
