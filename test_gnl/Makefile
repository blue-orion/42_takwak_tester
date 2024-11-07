CC = cc
PARENT = ..

TARGET = user_exe

TEST = make_test.c
BONUS_TEST = make_bonus_test.c

ifdef BONUS
	SRC = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c bonus_test.c
	TEST_SRC = make_bonus_test.c
else
	GNL_SRC = ../get_next_line.c ../get_next_line_utils.c test.c
	TEST_SRC = make_test.c
endif

all : $(TARGET)

$(TARGET) :
	cc $(TEST_SRC) -o test
	./test

bonus :
	make BONUS=1 all

