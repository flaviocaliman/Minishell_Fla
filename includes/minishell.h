/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:26:57 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/05 20:54:28 by caliman          ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include <errno.h>
# include <error.h>
# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define META_CHARS "<>|"
# define MINI_MSG "\e[1;93mminishell\033[91m$ \033[0m"
# define ON 0
# define OFF 1

// Flávio ->

# define MAXARGS 50

# define ERROR_TITLE "minishell: "
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

typedef struct s_envp
{
	char			*name;
	char			*value;
	char			*full;
	char			*visible;
	struct s_envp	*next;
}	t_envp;

// Flávio <-

//types of commands
/*typedef enum e_type
{
	PIPE,
	LESS,
	LESS_LESS,
	GREATER,
	GREATER_GREATER,
}	t_type;*/

typedef struct s_input_organize {
	int		pipes;
	char	*input_file;
	char	*output_file;
	char	*append_file;
	char	*heredoc_delimiter;
	char	**cmd_split;
} t_input_organize;

//commands struct
/*typedef struct s_command
{
	char			*cmd;
	char			**args;
	t_type			token;
	struct s_command	*next;
}	t_command;*/

//main struct
typedef struct s_program
{
	char			**env;
	char 			**path;
	char			*user_input;
	char			*pwd;
	char			*old_pwd;
	int				loop;
	//t_command		*commands;
	//Flavio
	t_envp			*envp;
}	t_program;

//clean/clean.c
void	free_array(char **array);
void	free_organize(t_input_organize *program);
void	free_program(t_program *mini, t_input_organize *program);

//initialize/init.c
char	**save_path(t_program *mini, char **envp);
void	init_organize(t_input_organize *program);
void	init_struct(t_program *mini, char **env);

//lexer/parseline.c
int		ft_isspaces(char c);
char	*fix_redir_spaces(const char *input);
int		parseline(t_program *mini);

//loop/loop.c
int		mini_loop(t_program *mini, t_input_organize *program);

//parser/parsing.c
void	parse_input(t_program *mini, t_input_organize *program);

//parser/quotes.c
char	*expand_variable(char *input, int *i);
int		check_quotes(const char *input);

//utils/utils.c
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strndup(const char *s, size_t size);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

//builtin
bool	is_builtins(char *cmd);
void	run_bultin(t_program *mini, t_input_organize *pgr, char **cmd);
void	ft_cd(t_program *mini, char **cmd);
void	ft_echo(char **cmd);
void	ft_env(t_program *pgr);
t_envp	*add_envp_node(t_envp *new, t_envp *envp);
t_envp	*new_envp_node(char *name, char *value);
t_envp	*find_envp_node(char *name, t_envp *envp);
void	ft_exit(t_program *pgr, char **cmd);
void	ft_pwd(void);
void	env_export(t_program *pgr, char *name, char *value, int visible);

//error/error.c
void	print_error(char *cmd);

#endif