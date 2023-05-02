# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:59:40 by ltrinchi          #+#    #+#              #
#    Updated: 2022/04/12 08:58:35 by ltrinchi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_WITHOUT_PATH = main.c \
					ft_atoi.c \
					ft_error.c \
					ft_isnum.c \
					ft_init.c \
					ft_check_arg.c \
					ft_free.c \
					ft_ms_sleep.c \
					ft_get_ms_time.c \
					ft_thread.c \
					ft_routine.c \
					ft_alfred.c \
					ft_eat.c

OBJS_WITHOUT_PATH = $(SRCS_WITHOUT_PATH:.c=.o)
HEADER_WITHOUT_PATH = philo.h

PATH_TO_SRCS = ./srcs/
PATH_TO_OBJS = ./objs/
PATH_TO_HEADER = ./inclds/

SRCS = $(addprefix $(PATH_TO_SRCS), $(SRCS_WITHOUT_PATH))
OBJS = $(addprefix $(PATH_TO_OBJS), $(OBJS_WITHOUT_PATH))

HEADER = $(addprefix $(PATH_TO_HEADER), $(HEADER_WITHOUT_PATH))

	##### COMMANDS ######
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -rf
	#####################

	########### RESOURCES ###########
	#################################

	###### COLORS FOR PRINTF ######
GREEN 		= \033[0;32m
RED			= \033[0;91m
YELLOW      = \033[0;93m
WHITE       = \033[1;49;97m
	###############################

all: $(PATH_TO_OBJS) $(NAME)
	printf "$(GREEN)✅ $(NAME) is up to date$(WHITE) 👏\n"  

$(PATH_TO_OBJS):
	mkdir -p ./objs/

$(PATH_TO_OBJS)%.o: $(PATH_TO_SRCS)%.c Makefile $(HEADER)
	printf "\033[2K\r$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞"  
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	printf "\n$(GREEN)✅ $(NAME) has been build 👍$(WHITE)\n"  

git: fclean
	git add *
	git add -u
	git commit 

clean:
	$(RM) $(PATH_TO_OBJS)
	printf "$(RED)👌 Files has been deleted in $(PATH_TO_OBJS) ($(NAME))$(WHITE)\n"  
	printf "$(GREEN)✅ Clean 👍$(WHITE)\n"  

fclean: clean
	$(RM) $(NAME)
	printf "$(RED)👌 $(NAME) has been deleted$(WHITE)\n"  
	printf "$(GREEN)✅ Fclean 👍\033$(WHITE)\n"

re: fclean all

.PHONY: all git clean fclean re
.SILENT:
