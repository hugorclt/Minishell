/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:44:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/07 14:34:33 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_cut_tab(char	**tab, int start, int end)
{
	char	**ret;
	int		i;

	ret = malloc(sizeof(char *) * ft_tab_size(tab) - 1);
	i = 0;
	if (!ret)
		return (NULL);
	while (i < start)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	while (tab[end])
	{
		ret[i] = ft_strdup(tab[end]);
		i++;
		end++;
	}
	ret[i] = 0;
	return (ret);
}

void	ft_exec_one(t_list *lst, char **env)
{
	(void)lst;
	(void)env;
}

int	ft_init_io(t_node *pipe, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "<") == 0)
		{
			pipe->infile_name = ft_strdup(cmd[i + 1]);
			if (!pipe->infile_name)
				return (-1);
		}
		else if (ft_strcmp(cmd[i], ">") == 0)
		{
			pipe->outfile_name = ft_strdup(cmd[i + 1]);
			if (!pipe->outfile_name)
				return (-1);
		}
		i++;
	}
	return (0);
}

char	*ft_cut(char *cmd, int *i)
{
	char	*ret;
	int		start;

	start = *i;
	if (cmd[*i] && cmd[*i] == ' ')
		i++;
	while (cmd[*i] && cmd[*i] != ' ')
		i++;
	ret = ft_strcut(cmd, start, *i);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*ft_cut_redirect(char *cmd)
{
	int		i;
	char	*ret;
	int		flag;

	i = 0;
	flag = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<')
		{
			ret = ft_cut(cmd, &i);
			if (!ret)
				return (NULL);
			flag = 1;
		}
		else if (cmd[i] == '>')
		{
			ret = ft_cut(cmd, &i);
			if (!ret)
				return (NULL);
			flag = 1;
		}
		else
			i++;
	}
	if (flag == 0)
		ret = ft_strdup(cmd);
	free(cmd);
	return (ret);
}

void	ft_print_struct_info(t_node params)
{
	int	i;

	i = 0;
	while (params.cmd[i])
	{
		printf("%s\n", params.cmd[i]);
		i++;
	}
	printf("%d\n", params.infile);
	printf("%d\n", params.outfile);
	printf("%d\n", params.nb);
}

int	ft_main_exec(t_list *lst, char **env)
{
	t_list	*tmp;
	t_node	params;
	(void)env;
	int		i;

	tmp = lst;
	params.nb = ft_lstsize(lst);
	params.cmd = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	params.heredoc = 0;
	params.infile = 0;
	params.outfile = 1;
	if (ft_lstsize(lst) == 1)
		return (ft_exec_one(lst, env), 0);
	i = 0;
	while (tmp)
	{
		if (ft_init_io(&params, ft_split_space(tmp->token)) == -1)
			return (-1);
		tmp->token = ft_cut_redirect(tmp->token);
		params.cmd[i] = ft_strdup(tmp->token);
		if (!params.cmd[i])
			return (-1);
		ft_init_pipe(&params);
		ft_init_pid(&params);
		//ft_open(&params, params.infile_name, params.outfile_name, params.heredoc);
		tmp = tmp->next;
		i++;
	}
	params.cmd[i] = NULL;
	ft_print_struct_info(params);
	ft_child_exec(&params, params.cmd, env);
	return (0);
}