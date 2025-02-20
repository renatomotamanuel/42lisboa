/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:50:11 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/18 15:33:09 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define LC_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"
# define DEC "0123456789"

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putunbr_base_fd(unsigned long bnb, int fd, char *b, unsigned int bs);
int		ft_putperc_fd(int fd);
int		ft_check_char(const char *s, va_list args);
int		ft_putnbr_base_fd(int n, int fd, char *base, int bs);
int		ft_putptr_fd(void *n, int fd, char *base, unsigned int bs);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
long	ft_atoi_check(char *str);
void	ft_bzero(void *s, size_t n);
int		error_syntax(char **array, int var);
int		ft_arrlen(int **z);
void	swap_a(int **a);
void	push_a(int **a, int **b);
void	swap_b(int **b);
void	push_b(int **a, int **b);
void	rot_a(int **a);
void	rot_b(int **b);
void	rotrot_a(int **a);
void	rotrot_b(int **b);
int		init_stack(char **argv, int len, int var);
void	*ft_free(char **strs, int check);
int		ft_strcmp(int s1, int s2);
int		stack_sorted(int **a, int len);
void	sort_big(int **a, int **b, int len);
int		*normalize(int *a, int len);
void	sort_small(int **a, int **b, int len);
void	sort_three(int **a);
void	sort_four(int **a, int **b, int len, int var);
int		equal_nbr(int **a, int len);
int		error_len(char **array);
int		ver_atoi(char **argv, int len);
void	sort(int **a, int **b, int len);
int		ft_atoi(const char *str);

#endif