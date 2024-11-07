# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 20:14:58 by takwak            #+#    #+#              #
#    Updated: 2024/10/24 21:13:33 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --no-print-directory

CC = cc
FLAGS = -Werror -Wextra -Wall

TARGET = takwak
OBJS = $(SRCS:.c=.o)

ifdef BONUS
	BONUS_FLAG = 1
else
	BONUS_FLAG = 0
endif

all : header compile exe fclean

exe :
	@./$(TARGET)
	@NO_SLEEP=1 valgrind --leak-check=full ./$(TARGET) > valgrind.txt

header : 
	@cp ../ft_printf.h ./
	@mkdir libft
	@cp ../libft/libft.h ./libft/

compile :
	@$(CC) -D BONUS=$(BONUS_FLAG) -w -c Printftest.c
	@make -s -C ../
	@$(CC) ../*.o ../libft/*.o *.o -o $(TARGET)

fclean :
	@make -s -C ../ fclean
	@rm -rf *.o $(TARGET) *.h libft

bonus :
	make BONUS=1 all
