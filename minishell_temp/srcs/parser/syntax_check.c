/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:37:46 by dicosta-          #+#    #+#             */
/*   Updated: 2025/07/20 19:35:48 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	empty_check(char *line)
{
	int var;
	char *temp = ft_strdup(line);
	temp = expand_caller(temp);
	var = 0;
	while(line[var])
	{
		if(!ft_isspace(line[var]))
		{
			if (line[var + 1] && (line[var] == '\"' && line[var + 1] == '\"'))
				var++;
			else if (line[var + 1] && (line[var] == '\'' && line[var + 1] == '\''))
				var++;
			else if (line[var] == '|' || line[var] == '\n')
				var = var;
			else
				return (free(temp), 1);
		}
		var++;
	}
	var = 0;
	while(line[var])
	{
		if(!ft_isspace(line[var]))
			if (line[var] != '|' && line[var] != '\n')
				return (free(temp), 0);
		var++;
	}
	return (free(temp), 1);
}

int	syntax_check(char *line)
{
	if (count_quotes(line) % 2 != 0)
		return (free(line), ft_printf(2, RED INV NOCLR ERR_3), 0);
	else if (!empty_check(line))
	{
		shell()->exit = 127;
		return (free(line), ft_printf(2, ": command not found\n"), 0);
	}
	else if (check_pipes(line, 0) == 0)
		return (free(line), 0);
	else if (check_consecutive(line, 0, 0) == 0)
		return (free(line), ft_printf(2, RED INV NOCLR ERR_4), 0);
	else if (check_redirection(line, 0) == 0)
		return (free(line), 0);
	return (1);
}

int	check_pipes(char *line, int i)
{
	i += skip_spaces(&line[i]);
	if (line && line[i] == '|')
		return (ft_printf(2, RED INV NOCLR ERR_5), 0);
	while (line && line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			i++;
			i += skip_quotes(&line[i], line[i - 1]);
			if (line[i])
				i++;
		}
		else
		{
			if (line[i] == '|' && line[i + 1] == '|')
				return (ft_printf(2, RED INV NOCLR ERR_1), 0);
			else if (line[i] == '|')
			{
				i++;
				i += skip_spaces(&line[i]);
				if (line[i] == '\0')
					return (ft_printf(2, RED INV NOCLR ERR_2), 0);
			}
			i++;
		}
	}
	return (1);
}

int	check_redirection(char *line, int i)
{
	char	redir_type;

	while (line && line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			i++;
			i += skip_quotes(&line[i], line[i - 1]) + 1;
		}
		else
		{
			if (line[i] == '>' || line[i] == '<')
			{
				redir_type = line[i];
				while (line[i] == redir_type)
					i++;
				i += skip_spaces(&line[i]);
				if (line[i] == '\0' || line[i] == '|')
					return (ft_printf(2, RED INV NOCLR ERR_6" '%c'.\n", redir_type), 0);
			}
			else
				i++;
		}
	}
	return (1);
}

//int	check_redirection2(char *line, int i, char redir_type)
//{
//	ft_printf(1, "%s\n", line);
//	while (line[i] == redir_type)
//		i++;
//	i += skip_spaces(&line[i]);
//	if (line[i] == '\0')
//		return (0);
//	return (1);
//}

int	check_consecutive(char *line, int i, char temp)
{
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			i++;
			i += skip_quotes(&line[i], line[i - 1]) + 1;
		}
		else
		{
			if (is_token(line[i]))
			{
				temp = line[i++];
				if ((temp == '>' || temp == '<') && consec_counter(&i, line, temp) > 1)
					return (0);
				else if ((temp != '>' && temp != '<') &&  consec_counter(&i, line, temp) > 0)
					return (0);
			}
			else
				i++;
		}
	}
	return (1);
}

int consec_counter(int *i, char *line, char temp)
{
	int	consecutive;

	consecutive = 0;
	while (line[*i] && line[*i] == temp)
	{
		(*i)++;
		consecutive++;
	}
	return (consecutive);
}
