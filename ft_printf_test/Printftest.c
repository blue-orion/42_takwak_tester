/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printftest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:13:50 by takwak            #+#    #+#             */
/*   Updated: 2024/10/31 03:26:01 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

#define RESET       "\033[0m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"

void	my_sleep(int seconds)
{
	if (getenv("NO_SLEEP") == NULL)
		usleep(seconds);
}
#define SEC 200000

int		ori_res;
int		my_res;

void	s_test(void);
void	p_test(void);
void	d_test(void);
void	u_test(void);
void	x_test(void);
void	X_test(void);
void	bonus_minus_flag(void);
void	bonus_plus_flag(void);
void	bonus_space_flag(void);
void	bonus_sharp_flag(void);
void	bonus_zero_flag(void);
void	bonus_width(void);
void	bonus_prec(void);
void	bonus_mixed();
void	error(void);

void	result_cmp(int a, int b, char *arg) {
	if (a == b)
		printf(GREEN "OK!" RESET "\n\n");
	else
	{
		printf(RED "KO!" RESET " => ");
		printf("input : \033[0;31m%s" RESET "\n\n", arg);
	}
}

int	main(void)
{
	s_test();
	p_test();
	d_test();
	u_test();
	x_test();
	X_test();
	error();

	printf(YELLOW "\n%%%% test" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%%"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%%"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%%\")");

	if (BONUS == 1)
	{
		bonus_minus_flag();
		bonus_plus_flag();
		bonus_space_flag();
		bonus_sharp_flag();
		bonus_zero_flag();
		bonus_width();
		bonus_prec();
		bonus_mixed();
	}
}

void	s_test(void)
{
	printf(YELLOW "\n%%s test" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%s", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%s", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%s\", NULL)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%s", "Printftest"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%s", "Printftest"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%s\", \"Printftest\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %s ", "-"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %s ", "-"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %s \", \"-\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %s %s ", "", "-"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %s %s ", "", "-"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %s %s \", \"\", \"-\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %s %s ", "-", ""));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %s %s ", "-", ""));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %s %s \", \"-\", \"\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %s %s %s %s %s", " - ", "", "4", "", "2"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %s %s %s %s %s", " - ", "", "4", "", "2"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %s %s %s %s %s\", \" - \", \"\", \"4\", \"\", \"2\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%22s", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%22s", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%22s\", NULL)");
	my_sleep(SEC);
}

void	p_test(void)
{
	printf(YELLOW "%%p test" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%p", "1224"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%p", "1224"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%p\", \"1224\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%p", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%p", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%p\", NULL)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %p %p ", 0, 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %p %p ", 0, 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %p %p \", 0, 0)");
	my_sleep(SEC);
}

void	d_test(void)
{
	printf(YELLOW "\n%%d test" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%d", (int)2147483648));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%d", (int)2147483648));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%d\", (int)2147483648)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%d", (int)-2147483648));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%d", (int)-2147483648));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%d\", (int)-2147483648)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%d", -100));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%d", -100));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%d\", -100)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%d", -1));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%d", -1));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%d\", -1)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%d", (int)-2147483648));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%d", (int)-2147483648));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%d\", (int)-2147483648)");
	my_sleep(SEC);
}

void	u_test(void)
{
	printf(YELLOW "\n%%u test" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%u", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%u", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%u\", 0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%u", -1));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%u", -1));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%u\", -1)");
	my_sleep(SEC);
}

void	x_test(void)
{
	printf(YELLOW "\n%%x test" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%x", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%x", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%x\", 0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%x", -1));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%x", -1));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%x\", -1)");
	my_sleep(SEC);
}

void	X_test(void)
{
	printf(YELLOW "\n%%X test" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%X", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%X", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%X\", 0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%X", -1));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%X", -1));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%X\", -1)");
	my_sleep(SEC);
}

void	bonus_minus_flag(void)
{
	printf(YELLOW "\nbonus(- flag)" RESET "\n");
	printf("- type c -\n");
	ori_res = printf("| printf return : %d\n", printf("%-20c", 'c'));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-20c", 'c'));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-20c\", \'c\')");
	my_sleep(SEC);

	printf("- type s -\n");
	ori_res = printf("| printf return : %d\n", printf("%-20s", "s format"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-20s", "s format"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-20s\", \"s format\")");
	my_sleep(SEC);

	printf("- type p -\n");
	ori_res = printf("| printf return : %d\n", printf("%-20p", "s format"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-20p", "s format"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-20p\", \"s format\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %-11p %-12p ", INT_MIN, INT_MAX));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %-11p %-12p ", INT_MIN, INT_MAX));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %-11p %%-12p \", INT_MIN, INT_MAX)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %-13p %%-14p \", ULONG_MAX, -ULONG_MAX)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %-2p ", 1));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %-2p ", 1));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %-2p \", 1)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %-2p ", 15));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %-2p ", 15));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %-2p \", 15)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %-3p ", 16));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %-3p ", 16));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %-3p \", 16)");
	my_sleep(SEC);

	printf("- type d -\n");
	ori_res = printf("| printf return : %d\n", printf("%-20d", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-20d", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-20d\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-10d", 12245));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-10d", 12245));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-10d\", 12245)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %-1d ", -0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %-1d ", -0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %-1d \", -0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %-1d ", -9));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %-1d ", -9));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %-1d \", -9)");
	my_sleep(SEC);

	printf("- type i -\n");
	ori_res = printf("| printf return : %d\n", printf("%-20i", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-20i", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-20i\", 42)");
	my_sleep(SEC);

	printf("- type u -\n");
	ori_res = printf("| printf return : %d\n", printf("%-20u", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-20u", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-20u\", 42)");
	my_sleep(SEC);

	printf("- type x -\n");
	ori_res = printf("| printf return : %d\n", printf("%-20x", 0x42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-20x", 0x42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-20x\", 0x42)");
	my_sleep(SEC);

	printf("- type X -\n");
	ori_res = printf("| printf return : %d\n", printf("%-20X", 0x42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-20X", 0x42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-20X\", 0x42)");
	my_sleep(SEC);
}

void	bonus_plus_flag(void)
{
	printf(YELLOW "\nbonus(+ flag)" RESET "\n");
	printf("- type d -\n");
	ori_res = printf("| printf return : %d\n", printf("%+d", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+d", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+d\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+d", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+d", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+d\", -42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+d", 12245));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+d", 12245));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+d\", 12245)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+d", -1));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+d", -1));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+d\", -1)");
	my_sleep(SEC);

	printf("- type i -\n");
	ori_res = printf("| printf return : %d\n", printf("%+i", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+i", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+i\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+i", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+i", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+i\", -42)");
	my_sleep(SEC);
}

void	bonus_space_flag(void)
{
	printf(YELLOW "\nbonus(' ' flag)" RESET "\n");
	printf("- type d -\n");
	ori_res = printf("| printf return : %d\n", printf("% d", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("% d", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"% d\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("% d", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("% d", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"% d\", -42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("% d", 12245));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("% d", 12245));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"% d\", 12245)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("% d", -12245));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("% d", -12245));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"% d\", -12245)");
	my_sleep(SEC);

	printf("- type i -\n");
	ori_res = printf("| printf return : %d\n", printf("% i", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("% i", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"% i\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("% i", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("% i", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"% i\", -42)");
	my_sleep(SEC);
}

void	bonus_sharp_flag(void)
{
	printf(YELLOW "\nbonus(# flag)" RESET "\n");
	printf("- type x -\n");
	ori_res = printf("| printf return : %d\n", printf("%#x", 0x42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%#x", 0x42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%#x\", 0x42)");
	my_sleep(SEC);
	printf("- type X -\n");
	ori_res = printf("| printf return : %d\n", printf("%#X", 0x42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%#X", 0x42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%#X\", 0x42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%#X", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%#X", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%#X\", 0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%#X", LONG_MIN));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%#X", LONG_MIN));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%#X\", LONG_MIN)");
	my_sleep(SEC);
}

void	bonus_zero_flag(void)
{
	printf(YELLOW "\nbonus(0 flag)" RESET "\n");
	printf("- type d -\n");
	ori_res = printf("| printf return : %d\n", printf("%010d", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%010d", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%010d\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%010d", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%010d", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%010d\", -42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %01d ", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %01d ", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %01d \", 0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %012d ", LONG_MIN));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %012d ", LONG_MIN));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %012d \", LONG_MIN)");
	my_sleep(SEC);

	printf("- type i -\n");
	ori_res = printf("| printf return : %d\n", printf("%010i", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%010i", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%010i\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%010i", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%010i", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%010i\", -42)");
	my_sleep(SEC);

	printf("- type u -\n");
	ori_res = printf("| printf return : %d\n", printf("%010u", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%010u", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%010u\", 42)");
	my_sleep(SEC);

	printf("- type x -\n");
	ori_res = printf("| printf return : %d\n", printf("%010x", 0x42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%010x", 0x42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%010x\", 0x42)");
	my_sleep(SEC);
	
	printf("- type X -\n");
	ori_res = printf("| printf return : %d\n", printf("%010X", 0x42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%010X", 0x42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%010X\", 0x42)");
	my_sleep(SEC);
}

void	bonus_width(void)
{
	printf(YELLOW "\nbonus(number width)" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%10d", 12245));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%10d", 12245));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%010d\", 12245)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%3d", 12245));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%3d", 12245));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%03d\", 12245)");
	my_sleep(SEC);
}

void	bonus_prec(void)
{
	printf(YELLOW "\nbonus(. prec)" RESET "\n");
	printf("- type d -\n");
	ori_res = printf("| printf return : %d\n", printf("%.3d", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3d", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3d\", 424242)");
	my_sleep(SEC);
	
	printf("- type i -\n");
	ori_res = printf("| printf return : %d\n", printf("%.3i", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3i", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3i\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.0i", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.0i", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.0i\", 0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.0i", 10));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.0i", 10));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.0i\", 10)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf(" %.6i ", -9));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf(" %.6i ", -9));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\" %.6i \", -9)");
	my_sleep(SEC);

	printf("- type u -\n");
	ori_res = printf("| printf return : %d\n", printf("%.3u", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3u", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3u\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.3u", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3u", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3u\", 424242)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.0u", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.0u", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.0u\", 0)");
	my_sleep(SEC);

	printf("- type x -\n");
	ori_res = printf("| printf return : %d\n", printf("%.3x", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3x", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3x\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.3x", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3x", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3x\", 424242)");
	my_sleep(SEC);

	printf("- type X -\n");
	ori_res = printf("| printf return : %d\n", printf("%.3X", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3X", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3X\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.3X", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3X", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3X\", 424242)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.X", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.X", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.X\", 424242)");
	my_sleep(SEC);

	printf("- type s -\n");
	ori_res = printf("| printf return : %d\n", printf("%.s", "424242"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.s", "424242"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.s\", \"424242\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.s", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.s", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.s\", NULL)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.09s", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.09s", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.09s\", NULL)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%.3s", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3s", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3s\", NULL)");
	my_sleep(SEC);

	printf("- type p -\n");
	ori_res = printf("| printf return : %d\n", printf("%.3p", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%.3p", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%.3p\", NULL)");
	my_sleep(SEC);
}

void	bonus_mixed()
{
	printf(YELLOW "\nbonus mixed" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%+20d", 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+20d", 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+20d\", 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+20d", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+20d", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+20d\", -42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+10d", 12245));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+10d", 12245));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+10d\", 12245)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+10d", 12245));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+10d", 12245));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+10d\", 12245)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%08.3i", 8375));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%08.3i", 8375));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%08.3i\", 8375)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%10.1s", "42"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%10.1s", "42"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%10.1s\", \"42\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%10.3d", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%10.3d", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%10.3d\", -42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%11.10s", "424242"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%11.10s", "424242"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%11.10s\", \"424242\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+10.3i", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+10.3i", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+10.3i\", 424242)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%+3.10d", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%+3.10d", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%+3.10d\", 424242)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%3.10i", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%3.10i", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%3.10i\", 424242)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%3.10u", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%3.10u", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%3.10u\", 424242)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%#11.10x", 424242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%#11.10x", 424242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%#11.10x\", 424242)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%3.1s", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%3.1s", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%3.1s\", NULL)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%10.s", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%10.s", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%10.s\", NULL)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-7.5s", "tubular"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-7.5s", "tubular"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-7.5s\", \"tubular\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-10.8s", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-10.8s", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-10.8s\", NULL)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%5.0i", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%5.0i", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%5.0i\", 0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%5.0u", 0));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%5.0u", 0));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%5.0u\", 0)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%15p", NULL));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%15p", NULL));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%15p\", NULL)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%--120.50d" , -1355834522));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%--120.50d", -1355834522));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%--120.50d\", -1355834522)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-%%-112.167X" , 3814946551u));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-%%-112.167X" , 3814946551u));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-%%-112.167X\" , 3814946551u)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-32.65u" , 404243169u));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-32.65u" , 404243169u));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-32.65u\" , 404243169u)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-#120.50d" , -1355834522));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-#120.50d", -1355834522));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-#120.50d\", -1355834522)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-00120.50d" , -1355834522));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-00120.50d", -1355834522));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-00120.50d\", -1355834522)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%197c%12p%013.i%--147.185x%-1c" ,7,(void*)18229185041105221837lu,-1488496170,703835510u,120));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%197c%12p%013.i%--147.185x%-1c" ,7,(void*)18229185041105221837lu,-1488496170,703835510u,120));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%197c%12p%013.i%--147.185x%-1c\" ,7,(void*)18229185041105221837lu,-1488496170,703835510u,120)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%013.i" , -1488496170));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%013.i" , -1488496170));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%013.i\" , -1488496170)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%08.5i" , 42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%08.5i" , 42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%08.5i\" , 42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%7.5s", "yolo"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%7.5s", "yolo"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%7.5s\", \"yolo\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-0007.5s", "yolo"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-0007.5s", "yolo"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-0007.5s\", \"yolo\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%-7.4s", "yolo"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%-7.4s", "yolo"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%-7.4s\", \"yolo\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%0+-6d", -42));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%0+-6d", -42));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%0+-6d\", -42)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%13.10d", -4242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%13.10d", -4242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%13.10d\", -4242)");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%13.10d", -4242));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%13.10d", -4242));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%13.10d\", -4242)");
	my_sleep(SEC);
}

void	error(void)
{
	printf(YELLOW "\nerror test" RESET "\n");
	ori_res = printf("| printf return : %d\n", printf("%y", "122"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%y", "122"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%y\", \"122\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("%z", "122"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("%z", "122"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"%z\", \"122\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("(%z)", "122"));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("(%z)", "122"));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"(%z)\", \"122\")");
	my_sleep(SEC);
	ori_res = printf("| printf return : %d\n", printf("(%x)", 122));
	my_res = ft_printf("| ft_printf return : %d\n", ft_printf("(%x)", 122));
	result_cmp(ori_res - 19, my_res - 22, "ft_printf(\"(%x)\", 122)");
	my_sleep(SEC);
}
