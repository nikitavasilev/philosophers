# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 21:15:41 by nvasilev          #+#    #+#              #
#    Updated: 2023/01/28 04:25:13 by nvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = 			philo

CC = 			cc
CFLAGS =		-Wall -Wextra -Werror -g
RM =			rm -f

BUILD =			build
INCLUDES =		-I ./includes/
SRCS =			$(addsuffix .c, \
				$(MAIN) $(CORE_SRCS) $(PARSER_SRCS) $(UTILS_SRCS) $(DISPLAY_SRCS))

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

MAIN =			./main

CORE_SRCS =		$(addprefix core/, \
				routine \
				create_threads \
				init \
				destroy)

PARSER_SRCS =	$(addprefix parser/, \
				parse)

UTILS_SRCS =	$(addprefix utils/, \
				atoi_err_overflow \
				ft_isdigit \
				ft_isspace \
				print_args \
				get_time_ms)

DISPLAY_SRCS =	$(addprefix display/, \
				logs)

################################################################################
#                                     OBJECTS                                  #
################################################################################

OBJS := $(SRCS:%.c=$(BUILD)/%.o)

################################################################################
#                                     RULES                                    #
################################################################################

all: $(NAME)

$(BUILD)/%.o: %.c ./includes/*.h
	@mkdir -p '$(@D)'
	$(CC) $(CFLAGS) -MMD $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lpthread $(INCLUDES) -o $@

clean:
	$(RM) -r $(BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
