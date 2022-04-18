/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 12:36:59 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	pipex(int ac, char **av, char **envp)
{
	int		i;
	int		status;
	t_node	params;

	if (ac < 5 || ft_args(ac, av) < 0)
		ft_wrong_args();
	params.heredoc = ft_cmp_heredoc(av, "here_doc", &params, ac);
	i = params.heredoc;
	if (ft_initialisation(&params, av, ac, i) < 0)
	{
		ft_free_struct(&params);
		exit(EXIT_FAILURE);
	}
	if (ft_child_exec(&params, av, envp) < 0)
		exit(EXIT_FAILURE);
	i = 0;
	ft_close_all(&params);
	while (i < params.nb)
		waitpid(params.pid[i++], &status, 0);
	ft_free_struct(&params);
	unlink(".heredoc_temp");
	ft_close();
	return (0);
}
