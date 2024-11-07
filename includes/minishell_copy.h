
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:26:57 by gcampos-          #+#    #+#             */
/*   Updated: 2024/08/19 23:30:14 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
#include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define META_CHARS "<>|"
# define MINI_MSG "\e[1;93mminishell\033[91m$ \033[0m"

# define RED "\033[31m"

# define MAXARGS 50

# define ERROR_CD_ARGS "cd: too many arguments"
# define ERROR_CD_HOME "cd: HOME not set"
# define ERROR_CD_DIRECTORY "cd: no such file or directory"
# define ERROR_CD_OLDPWD "cd: OLDPWD not set"
# define ERROR_UNSET_ARGS "unset: invalid number of arguments"
# define ERROR_UNSET_VAR "unset: variable not found"
# define ERROR_PWD_DIRECTORY "pwd: Couldn't get current directory"
# define ERROR_ENV_DIRECTORY "env: no such file or directory"
# define ERROR_EXIT_ARGS "exit: too many arguments"
# define ERROR_EXIT_DIGIT "exit: numeric argument required"

extern int g_exit_status;

//types of commands
typedef enum e_type
{
	PIPE,
	LESS,
	LESS_LESS,
	GREATER,
	GREATER_GREATER,
}	t_type;

//redirections
typedef struct s_redirection
{
	char			*input_file;
	char			*heredoc_delimiter;
	char			*truncate_file;
	char			*append_file;
}	t_redirection;

//commands
typedef struct s_token
{
	char			**cmds;
	//struct s_token	*next;
	t_type			*types;
}	t_token;

//status of the last command
typedef struct s_status
{
	int				last_exit_status;
}	t_status;

// envp linked list
typedef struct s_envp
{
	char			*name;
	char			*value;
	char			*full;
	char			*visible;
	struct s_envp	*next;
}	t_envp;

typedef struct s_cmd
{
	int				type;
}	t_cmd;

typedef struct s_exec
{
	int				type;
	char			*argv[MAXARGS];
}	t_exec;


//main struct
typedef struct s_program
{
	char			**env;
	char			*user_input;
	char			*pwd;
	char			*old_pwd;
	char 			**path;
	int				exit_status;
	int				stop;
	int				stdin_copy;
	int				stdout_copy;
	t_redirection	*redirection;
	t_token			*token;
	t_status		status;
	t_envp			**envp;
}	t_program;

//parsing.c
int		set_meta_chars(t_program *mini, int i);
void	parse_input(t_program *mini);

//clean.c
//void	*ft_memdel(void *ptr);
void	free_array(char **array);
void	free_redirection(t_redirection *redirection);
void	free_token(t_token *token);
void	free_program(t_program *mini);

//init.c
void	init_struct(t_program *mini, char **env);

//main.c


//builtin.c


//mini_loop.c
int		mini_loop(t_program *mini);

//utils.c
int		*save_path(t_program *mini, char **envp);

#endif