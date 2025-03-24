/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:50:11 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/24 16:35:49 by rmota-ma         ###   ########.fr       */
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

//PRINTF
int		ft_printf(const char *s, ...);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putunbr_base_fd(unsigned long bnb, int fd,
			char *base, unsigned int bs);
int		ft_putperc_fd(int fd);
int		ft_check_char(const char *s, va_list args);
int		ft_putnbr_base_fd(int n, int fd, char *base, int bs);
int		ft_putptr_fd(void *n, int fd, char *base, unsigned int bs);

//GNL
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_linelen(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_free_buffer(char *str);
void	ft_bzero(void *s, size_t n);

//SPLIT
char	**ft_split(char *s, char c, size_t var, int var2);
void	*ft_free(char **strs);
int		check_plica(char *s);
void	cut_word(char *s, size_t *var);

//LIB_INC
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);

//LIB_INC_2
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//PIPEX
void	child_process(char **argv, char **envp, int *fd);
char	*find_path(char **envp, char *cmd);
void	child_process_2(char **argv, char **envp, int *fd);

//ERRORS
void	error(void);
void	error_env(char **cmd1);
void	close_fds(void);
void	execve_error(char *path, char **cmd1);

//PIPEX_BONUS
char	*find_path(char **envp, char *cmd);

//DOC_HANDLE
int		here_doc(char **argv, char**envp, int argc, int *pids);
int		here_doc_pipe(char **argv, int argc, char **envp, int *pids);
void	loop(char **argv, int cmds, int infile);
void	print_pipe(int cmds);

//PIPE_HANDLE
int		multiple_pipes(int argc, char **argv, char **envp, int *pids);
int		pimping(char *cmd1, char **envp, int *pids);
void	process(char *argv, char **envp);
void	waitpids(int *pids, int argc);
void	last_process(char **argv, char **envp, int argc, int perm);
int		parent(int argc, char **argv, char **envp, int *pids);
void	first_process(char **argv, char **envp, int *fd);
#endif