/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:50:11 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/01/03 17:43:38 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

# define LC_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"
# define DEC "0123456789"

typedef struct s_list
{
	int 			nbr;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putunbr_base_fd(unsigned long bnb, int fd, char *base, unsigned int bs);
int		ft_putperc_fd(int fd);
int		ft_check_char(const char *s, va_list args);
int		ft_putnbr_base_fd(int n, int fd, char *base, int bs);
int		ft_putptr_fd(void *n, int fd, char *base, unsigned int bs);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

#endif