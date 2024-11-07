MAKEFLAGS += --no-print-directory
CC = cc
PARENT = ..

BUFFER_SIZE = 42

TARGET = test
USER_TXT = srcs/text_user.txt		\
		   srcs/41_no_nl_user.txt	\
		   srcs/big_line_user.txt	\
		   srcs/empty_user.txt		\
		   srcs/only_nl_user.txt		\
		   srcs/read_error_user.txt	

ifdef BONUS
	SRC = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c bonus_test.c
	TEST = make_bonus_test.c
else
	SRC = ../get_next_line.c ../get_next_line_utils.c test.c
	TEST = make_test.c
endif

all : fclean $(USER_TXT) $(TARGET)
	@cc $(TEST) -o $(TARGET)
	@./$(TARGET)

$(TARGET) : $(SRC)
	cc $^ -D BUFFER_SIZE=$(BUFFER_SIZE) -o a.out

$(USER_TXT) :
	@touch $@

clean :
	rm $(USER_TXT)

fclean : clean
	@if [ -e "$(TARGET)" ]; then	\
		rm -r $(TARGET);	\
	fi
	@if [ -e "a.out" ]; then	\
		rm a.out;	\
	fi

user_txt :
	touch $(USER_TXT)

bonus :
	@make BONUS=1 all

