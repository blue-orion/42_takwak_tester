#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int	main(int argc, char *argv[])
{
	char	command[1000];
	int		flag;

	flag = 1;
	if (argc > 2)
	{
		printf("Invalid argc");
		return (0);
	}
	if (argc == 1)
	{
		strcpy(command, "cc ");
		strcat(command, " ../get_next_line.c ../get_next_line_utils.c test.c -o test.out");

	}
	else
	{
		strcpy(command, "cc -g ");
		strcat(command, "-Wall -Wextra -Werror ");
		strcat(command, "-D BUFFER_SIZE=");
		strcat(command, argv[1]);
		strcat(command, " ../get_next_line.c ../get_next_line_utils.c test.c ");
		strcat(command, "-o test.out");
	}
	printf("%s\n", command);
	int	ret = system(command);
	
	// test.out 실행
	// if (ret == 0)
	// {
	// 	printf("./test.out\n");
	// 	printf("===============================================================================\n\n");
	// 	ret = system("./test.out");
	// 	printf("\n===============================================================================\n");
	// }
	if (ret == 0)
	{
		printf("valgrind --leak-check=full ./test.out\n");
		printf("===============================================================================\n\n");
		ret = system("valgrind --leak-check=full ./test.out > valgrind.txt");
		printf("\n===============================================================================\n");
	}
	// if (ret == 0)
	// {
	// 	printf("rm test.out\n");
	// 	ret = system("rm test.out");
	// }
	if (ret == 0)
	{
		printf("diff -q -c -d text.txt text_user.txt => ");
		ret = system("diff -q -c -d text.txt text_user.txt");
		if (ret == 0)
		{
			flag = 1;
			printf("diff OK!\n");
		}
		else
		{
			flag = 0;
			system("diff text.txt text_user.txt");
		}
	}
	assert(flag);
	if (ret == 0)
	{
		printf("diff -q -c -d empty.txt empty_user.txt => ");
		ret = system("diff -q -c -d empty.txt empty_user.txt");
		if (ret == 0)
		{
			flag = 1;
			printf("diff OK!\n");
		}
		else
		{
			flag = 0;
			system("diff empty.txt empty_user.txt");
		}
	}
	assert(flag);
	if (ret == 0)
	{
		printf("diff -q -c -d read_error.txt read_error_user.txt => ");
		ret = system("diff -q -c -d read_error.txt read_error_user.txt");
		if (ret == 0)
		{
			flag = 1;
			printf("diff OK!\n");
		}
		else
		{
			flag = 0;
			system("diff read_error.txt read_error_user.txt");
		}
	}
	assert(flag);
	if (ret == 0)
	{
		printf("diff -q -c -d big_line.txt big_line_user.txt => ");
		ret = system("diff -q -c -d big_line.txt big_line_user.txt");
		if (ret == 0)
		{
			flag = 1;
			printf("diff OK!\n");
		}
		else
		{
			flag = 0;
			system("diff big_line.txt big_line_user.txt");
		}
	}
	if (ret == 0)
	{
		printf("diff -q -c -d 41_no_nl.txt 41_no_nl_user.txt => ");
		ret = system("diff -q -c -d 41_no_nl.txt 41_no_nl_user.txt");
		if (ret == 0)
		{
			flag = 1;
			printf("diff OK!\n");
		}
		else
		{
			flag = 0;
			system("diff 41_no_nl.txt 41_no_nl_user.txt");
		}
	}
	assert(flag);
	return (0);
}
