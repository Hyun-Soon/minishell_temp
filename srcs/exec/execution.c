/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:35:15 by hyuim             #+#    #+#             */
/*   Updated: 2023/11/14 20:45:45 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	exec_tree(t_bundle *bundle, t_pipe *root)
{
	if (!root)
		return (-1);
	get_fork_cnt(bundle, root);
	if (check_one_cmd_and_builtin(root) == 1)
	{
		if (exec_one_builtin(bundle, root) == -1)
		{
			g_exit_status = 1;
			return (-1);
		}
		return (0);
	}
	else
		exec_command(bundle, root);
	return (0);
}

void	sigquit_handler_for_another_minishell(int sig)
{
	(void)sig;
	return ;
}

void	exec_command(t_bundle *bundle, t_pipe *root)
{
	int	idx;

	idx = -1;
	if (pre_exec_here_doc(root, bundle) == -1)
		return ;
	if (root && root->cmd)
		exec_recur(root, bundle, -1, 0);
	signal(SIGINT, sigint_handler_during_fork);
	signal(SIGQUIT, sigquit_handler_during_fork);
	if (root && root->cmd && root->cmd->simple_cmd->cmd_path
		&& ft_strlen(root->cmd->simple_cmd->cmd_path)
		>= ft_strlen("./minishell")
		&& ft_strncmp(root->cmd->simple_cmd->cmd_path,
			"./minishell", ft_strlen("./minishell")) == 0)
		signal(SIGQUIT, sigquit_handler_for_another_minishell);
	if (bundle->cmd_cnt >= 1 || bundle->fork_cnt != 0)
		while (++idx < bundle->fork_cnt)
			set_exit_status(bundle);
	if (bundle->cmd_cnt == 0)
		set_exit_status(bundle);
	if (root && !(root->cmd))
		g_exit_status = 1;
}
