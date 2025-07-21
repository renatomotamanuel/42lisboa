/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:50:02 by dicosta-          #+#    #+#             */
/*   Updated: 2025/07/20 20:14:33 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*shell(void)
{
	static t_shell	shell;

	return (&shell);
}

void	print_banner() {
	ft_printf(1, "\033[1;95m ________________________________");
	ft_printf(1, "____________________________\n");
	ft_printf(1, "|  \033[1;96m _    _  _____  _____  _    _");
	ft_printf(1, " ______ _      _    __   __  \033[1;35m|\n");
	ft_printf(1, "|  \033[1;96m| |  | ||_   _|/ ____\\| |  |");
	ft_printf(1, " |  ____| |    | |   \\ \\ / /  \033[1;35m|\n");
	ft_printf(1, "|  \033[1;96m| |  | |  | | | |____ | |__| | ");
	ft_printf(1, "|__  | |    | |    \\ V /   \033[1;35m|\n");
	ft_printf(1, "|  \033[1;96m| |/\\| |  | |  \\____ ");
	ft_printf(1, "\\|  __  |  __| | |    | |     \\ /    \033[1;35m|\n");
	ft_printf(1, "|  \033[1;96m|  /\\  |  | |  _____| | |");
	ft_printf(1, "  | | |____| |____| |____ | |    \033[1;35m|\n");
	ft_printf(1, "|  \033[1;96m|_/  \\_|  |_|  \\_____/|_|  ");
	ft_printf(1, "|_|______|______|______||_|    \033[1;35m|\n");
	ft_printf(1, "\033[1;95m|____________________________");
	ft_printf(1, "________________________________|\n\n");
	ft_printf(1, "\033[1;95m                       M I N I S H E L L\n\n");
	ft_printf(1, "\033[1;95m                              b y       \n\n");
	ft_printf(1, "\033[1;92m                      rmota-ma");
	ft_printf(1, " & dicosta-       \033[0m\n\n");
}

void	print_tree(t_tree *tree)
{
	if (tree == NULL)
	{
		ft_printf(1, "NULL\n");
		return ;
	}
	ft_printf(1, "Value: [%s]\t Type: [%d]\n", tree->value, tree->type);	
	ft_printf(1, "LEFT: ");
	print_tree(tree->left);
	ft_printf(1, "RIGHT: ");
	print_tree(tree->right);
}

void	free_list(t_token *token)
{
	t_token *temp;
	
	while (token)
	{
		temp = token;
		token = token->next;
		free(temp->value);
		free(temp);
	}
}

void	print_tokens(t_token *token)
{
	while (token)
	{
		ft_printf(1, "Value: [%s]\t Type: [%d]\n", token->value, token->type);	
		token = token->next;
	}
}

int parser(char *line)
{
	
	if (syntax_check(line) == 0)
		return (0);
	line = expand_caller(line);
	if (syntax_check2(line) == 0)
		return (0);
	t_token *token;
	
	token = assign_token(line);
	/* printf("TOKEN\n");
	 print_tokens(token);
	 printf("\n\n");*/
	if(token)
	{
		pipe_counter(token);
		shell()->tree = tokens_to_tree(token, NULL, shell()->tree);
	}
	/* printf("TREE\n");
	 print_tree(shell()->tree);*/
	free_list(token);
	free(line);
	return (1);
}

void	reset_input(char *line)
{
	//printf("%s\n", line);
	close_fds();
	shell()->pid = 0;
	shell()->in = dup(0);
	shell()->out = dup(1);
	if(shell()->tree && shell()->tree->value)
	{
		tree_free(shell()->tree);
		shell()->tree = NULL;
	}
	shell()->count = 0;
	shell()->pipe_count = 0;
	shell()->hist = hist_manage(line, 0);
}

int	main(int ac, char **av, char **ev)
{
	(void)av;
	char *line;
	
	if (ac != 1)
		return (ft_printf(1, "No arguments are needed\n"), 1);
	//print_banner();
	init_shell(ev);
	while(1)
	{
		choose_signal(ROOT);
		line = readline("minishell ▸ ");
		if (!line)
		{
			ft_printf(1, "exit\n");
			exit_cmd(NULL, 0);
		}
		if(!line[0])
		{
			shell()->exit = 0;
			free(line);
			continue ;
		}
		reset_input(line);
		if(!parser(line))
		{
			continue ;
		}
		if(shell()->tree)
		{
			if(manage_here_doc() == 1)
			{
				if(shell()->docs)
					free(shell()->docs);
				continue ;
			}
			if(shell()->tree->type == PIPE)
			{
				shell()->pid = fork();
				if(!shell()->pid)
				{
					choose_signal(CHLD);
					tree_executer(0, 0);
				}
				else
				{
					choose_signal(IGNORE);
					waitpid(shell()->pid, &shell()->exit, 0);
					choose_signal(ROOT);
					shell()->exit = shell()->exit / 256;
				}
			}
			else
				nptree_executer(NULL, NULL, 0);
		}
	}
	return (0);
}

