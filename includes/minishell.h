/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:26:57 by gcampos-          #+#    #+#             */
/*   Updated: 2024/09/10 21:03:19 by caliman          ###   ########.fr       */
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
# include <errno.h>
# include <string.h>
#include "libft.h"

//Flávio ->

#include <stdbool.h>

# define ERROR_CD_ARGS "cd: too many arguments"
# define ERROR_CD_HOME "cd: HOME not set"
# define ERROR_CD_OLDPWD "cd: OLDPWD not set"
# define ERROR_CD_DIRECTORY "cd: no such file or directory"
# define ERROR_PWD_DIRECTORY "pwd: couldn't get current directory"
# define ERROR_ENV_DIRECTORY "emv: no such file or directory"
# define ERROR_UNSET_ARGS "unset: invalid number of arguments"
# define ERROR_UNSET_VAR "unset: variable not found"
# define ERROR_EXIT_ARGS "exit: too many arguments"
# define ERROR_EXIT_DIGIT "exit: numeric argument required"

# define RED "\033[0;31m"

# define MAXARGS 50

//Flávio <-

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define META_CHARS "<>|"
# define MINI_MSG "\e[1;93mminishell\033[91m$ \033[0m"
# define ON 0
# define OFF 1

# define EXEC 10
# define REDIR 11
# define HERE_DOC 12
# define APPEND 13
# define PIPE 14

//Flávio ->

// envp linked list
typedef struct s_envp
{
	char			*name;
	char			*value;
	char			*full;
	char			*visible;
	struct s_envp	*next;
}	t_envp;

typedef struct s_command
{
	int				type;
}	t_command;

typedef struct s_exec
{
	int				type;
	char			*argv[MAXARGS];
}	t_exec;

typedef struct s_redir
{
	int				type;
	char			*file;
	int				fd;
}	t_redir;

typedef struct s_pipe
{
	int				type;
	t_command		*left;
	t_command		*right;
}	t_pipe;

typedef struct s_heredoc
{
	int				type;
	char			*delimiter;
	char			*content;
}	t_heredoc;

//Flávio <-


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
	char *input_file; // <
	char *output_file; // >
	char *append_file; // >>
	char *heredoc_delimiter; // <<
	char *cmds; // pipe
} t_input_organize;

//commands struct
/*typedef struct s_command
{
	char			*cmd;
	char			*expansion;
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
	t_envp			**envp;
	t_command		*command;
}	t_program;


//Flávio ->

extern int g_exit_status;

//Flávio <-


//clean/clean.c
void	free_array(char **array);
void	free_organize(t_input_organize *program);
void	free_program(t_program *mini, t_input_organize *program);

//initialize/init.c
int		*save_path(t_program *mini, char **envp);
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
void	*ft_realloc(void *ptr, size_t size);

#endif