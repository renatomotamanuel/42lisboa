/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:50:11 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/25 21:11:32 by scorpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>

# define LC_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"
# define DEC "0123456789"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//FT_PRINTF
int	ft_printf(const char *s, ...);
int	ft_putchar_fd(int c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putunbr_base_fd(unsigned long bnb, int fd, char *base, unsigned int bs);
int	ft_putperc_fd(int fd);
int	ft_check_char(const char *s, va_list args);
int	ft_putnbr_base_fd(int n, int fd, char *base, int bs);
int	ft_putptr_fd(void *n, int fd, char *base, unsigned int bs);

//GNL
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_linelen(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_free_buffer(char *str);
void	ft_bzero(void *s, size_t n);

//SPLIT
char	**ft_split(char *s, char c);
void	*ft_free(char **strs);

//LIB_INC
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);

//SRCS
void	child_process(char **argv, char **envp, int *fd);
char *find_path(char **envp, char *cmd);
void	error_exit(void);
void	child_process_2(char **argv, char **envp, int *fd);

#endif