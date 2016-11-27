/*
** display.h for display in /home/jordan.roucom/CPool_Day09
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Thu Oct 13 08:16:05 2016 Jordan Rouco miguez
** Last update Sun Nov 20 17:16:23 2016 Jordan Rouco miguez
*/

#ifndef	MY_H_
# define MY_H_

char	*my_strdup(char *src);
int	my_strncmp(char *s1, char *s2, int n);
int	my_str_islower(char *c);
void	my_sort_int_tab(int *tab, int size);
char	my_strlowcase(char *str);
int	my_str_isalpha(char *str);
int	my_showstr(char *str);
int	my_power_rec(int nb, int p);
int	my_swap(int *a, int *b);
int	my_strlen(char *strlen);
char	*my_strcpy(char *dest, char *src);
int	my_showmem(char *str, int size);
int	my_is_prime(int nb);
char	*my_strupcase(char *str);
int	my_str_isupper(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_revstr(char *str);
int	my_isneg(int n);
char	*my_strstr(char *str);
int	my_str_isprintable(char *str);
char	*my_strcapitalize(char *str);
int	my_putstr(char *str);
int	my_getnbr(char *str);
char	*my_strncpy(char *dest, char *src, int n);
int	my_str_isnum(char *str);
int	my_square_root(int nb);
void	my_put_nbr(int nb);
int	my_find_prime_sup(int nb);
int	my_putchar(char c);
char	*infinadd(char *av1, char *av2);
int	minus(int *nb, char *av1, char *av2, int cpt1, int cpt2);
char	*multiplication(char *av1, char *av2);
int	modulo(char *av);
int	division(char *av);
void	my_put_error(char *s);
int	sum_stdarg(int i, int nb, ...);
void	disp_stdarg(char *s, ...);
void	fg_d();
void	fg_x();
void	fg_X();
void	fg_b();
void	fg_o();
void	fg_c();
void	fg_s();
void	fg_p();
void	fg_u();
void	fg_S();
int	my_printf(char *, ...);
int	my_convert_base(unsigned long int, char *);

#endif	/* MY_H_ */
