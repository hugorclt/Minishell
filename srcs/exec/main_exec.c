/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:44:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/09 13:34:23 by hrecolet         ###   ########.fr       */
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

int	ft_count_in(char **cmd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "<") == 0)
			ret++;
		i++;
	}
	return (ret);
}

int	ft_count_out(char **cmd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], ">") == 0)
			ret++;
		i++;
	}
	return (ret);
}

int	ft_init_in_out(t_list **lst, char **cmd)
{
	(*lst)->infile_name = malloc(sizeof(char *) * (ft_count_in(cmd) + 1));
	(*lst)->outfile_name = malloc(sizeof(char *) * (ft_count_out(cmd) + 1));
	(*lst)->nb_infile = ft_count_in(cmd);
	(*lst)->nb_outfile = ft_count_out(cmd);
	if (!(*lst)->infile_name || !(*lst)->outfile_name)
		return (-1);
	return (0);
}

int	ft_init_io(t_list **lst, char **cmd)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tmp = (*lst);
	//printf("lel test\n");
	if (ft_init_in_out(&tmp, cmd) == -1)
		return (-1);
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "< ") == 0)
		{
			tmp->infile_name[j] = ft_strdup(cmd[i + 1]);
			if (!tmp->infile_name[j])
				return (-1);
			j++;
		}
		else if (ft_strcmp(cmd[i], "> ") == 0)
		{
			tmp->outfile_name[k] = ft_strdup(cmd[i + 1]);
			if (!tmp->outfile_name[k])
				return (-1);
			k++;
		}
		i++;
	}
	tmp->outfile_name[k] = 0;
	tmp->infile_name[j] = 0;
	return (0);
}

char	*ft_cut_redirect(char *cmd)
{
	int		i;
	char	*ret;
	int		start;

	start = 0;
	i = 0;
	ret = ft_strdup_pimp("\0");
	while (cmd[i])
	{
		//printf("%c\n", cmd[i]);
		if (cmd[i] == '>')
		{
			ret = ft_strjoin_pimp(ret, ft_substr(cmd, start, i));
			i++;
			while (cmd[i] && cmd[i] == ' ')
				i++;
			while (cmd[i] && cmd[i] != ' ')
				i++;
			start = i + 1;
			i--;
		}
		else if (cmd[i] == '<')
		{
			ret = ft_strjoin_pimp(ret, ft_substr(cmd, start, i));
			i++;
			while (cmd[i] && cmd[i] == ' ')
				i++;
			while (cmd[i] && cmd[i] != ' ')
				i++;
			while (cmd[i] && cmd[i] != ' ')
				i++;
			i--;
			start = i + 1;
		}
		i++;
	}
	ret = ft_strjoin_pimp(ret, ft_substr(cmd, start, i));
	return (free(cmd), ret);
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

void	ft_init_node(t_node *params, int len)
{
	params->nb = len;
	ft_init_pipe(params);
	ft_init_pid(params);
}

int	ft_main_exec(t_list **lst, char **env)
{
	t_list	*tmp;
	t_node	params;

	tmp = (*lst);
	if (ft_lstsize(tmp) == 1)
		return (ft_exec_one(tmp, env), 0);
	ft_init_node(&params, ft_lstsize(tmp));
	while (tmp)
	{
		ft_init_io(&tmp, ft_split_space(tmp->token));
		tmp->token = ft_cut_redirect(tmp->token);
		tmp = tmp->next;
	}
	ft_child_exec(&params, lst, env);
	return (0);
}
