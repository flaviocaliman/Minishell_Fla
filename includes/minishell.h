/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:26:57 by gcampos-          #+#    #+#             */
/*   Updated: 2024/12/04 23:01:37 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h> //functions: read, write, close, fork, execve, chdir...
# include <stdlib.h> //functions: malloc, free, exit, execve, getenv...
# include <stdio.h> //functions: printf, perror, strerror
# include <sys/wait.h> //functions: waitpid, wait, wait3, wait4
# include <sys/stat.h> //functions: stat, lstat, fstat
# include <signal.h> //functions: signal, kill
# include <limits.h> //functions: PATH_MAX
# include <fcntl.h> //functions: open, close, read, write
# include <readline/readline.h> //functions: readline, add_history
# include <readline/history.h> //functions: using_history
# include <stdbool.h> //types: bool
# include <errno.h> //variables: errno
# include "libft.h" //libft functions

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ENV 0
# define META_CHARS "<>|"
# define ON 0
# define OFF 1
# define MAIN 0
# define CHILD 1
# define HERE_DOC 2
# define PIPE 3
# define IGNORE 4

# define PATH_MAX 4096
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define ERROR_PWD_ARGUMENTS "pwd: too many arguments"
# define ERROR_PWD_DIRECTORY "pwd: couldn't get current directory"
# define ERROR_CD_ARGS "cd: too many arguments"
# define ERROR_CD_HOME "cd: HOME not set"
# define ERROR_CD_OLDPWD "cd: OLDPWD not set"
# define ERROR_CD_DIRECTORY "cd: no such file or directory"
# define ERROR_CD_OPTION "invalid option"
# define ERROR_ENV_ARGS "env: dont accept arguments"
# define ERROR_ENV_DIRECTORY "no such file or directory"
# define ERROR_EXIT_ARGS "exit: too many arguments"	
# define ERROR_EXIT_DIGIT "exit: numeric argument required"

extern int	g_exit_status;

typedef struct s_var
{
	int		i;
	int		j;
	int		k;
	int		inside;
	int		size;
	char	c;
	char	*new_str;
	char	*str;
}	t_var;

typedef struct s_organize
{
	int					fd_in;
	int					fd_out;
	int					list_pos;
	char				*input_file;
	char				*output_file;
	char				*append_file;
	char				*heredoc_dlm;
	char				*cmds;
	char				*args;
	struct s_organize	*next;
}		t_organize;

typedef struct s_env
{
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
}		t_env;

typedef struct s_program
{
	int				pipes;
	struct s_env	*env_list;
}		t_program;

//builtin/builtin.c
int			run_builtin(t_program *mini, t_organize *program, int fd1, int fd2);

//builtin/cd00.c
void		ft_cd(t_env *env_list, t_organize *program);
t_env		*ft_get_env(t_env *env_list, char *name);
void		ft_update_env(t_env *env_list, char *name, char *value, int repl);

//builtin/echo.c
void		ft_echo(t_organize *program);

//builtin/env.c
void		add_env_node(t_env *node, t_env *new);
t_env		*new_env_node(void);
t_env		*init_env(char **env);
void		print_env_list(t_env *list);
void		ft_env(t_env *env_list, t_organize *program);

//builtin/exit.c
void		check_exit_args(char **args);
int			ft_exit(t_organize *program, char *str);

//builtin/exit_free.c
void		free_and_exit(t_organize *pgr, int status);
void		handle_exit_error(void);
void		handle_exit_success_args(t_organize *program, char **args);

//builtin/export00.c
int			get_var_len(char *var);
void		update_env_node(t_env *tmp, char *var);
void		update_or_add_env_node(t_program *mini, char *var, int replace);
void		handle_export_args(t_program *mini, char **args);
void		ft_export(t_program *mini, char *input);

//builtin/export01.c
void		sort_env_array(char **env_array, int count);
int			count_env_list(t_env *env_list);
char		**create_env_array(t_env *env_list, int count);
void		print_env_array(char **env_array);
void		print_sorted_env_list(t_env *env_list);

//builtin/export02.c
t_env		*new_env_node_with_content(char *content);

//builtin/pwd.c
void		ft_pwd(t_organize *program);

//builtin/unset.c
void		ft_unset(t_env *env_list, t_organize *program);

//clean/clean.c
void		delete_node(t_env *node);
void		delete_list(t_env *list);
void		free_array(char **array);
void		free_organize(t_organize *program);
int			size_without_quotes(char *input);

//error/error00.c
void		print_error(char *cmd, int status);
void		ft_error_cmds(char *cmds, int status);
void		ft_error_dir(char *dir, int status);
void		ft_error_args(char *str, int status);
void		ft_error_opt(char *str, int status);

//error/error01.c
void		ft_error_digit(char *str, int status);
void		ft_error_path_cmd(char *cmd, int status);
void		ft_error_env_dir(char *dir, int status);
void		ft_error_exp_equal(char *dir, int status);

//exec/execution.c
void		exec_one_cmd(t_program *mini, t_organize *pgm, int fd1, int fd2);
int			is_builtin(char *command);
void		reset_fds(int fd1, int fd2, int status);
void		exec_with_pipes(t_program *mini, t_organize *program);

//exec/exec_utils.c
int			ft_list_size(t_organize *program);
int			exec_cmd(char *cmd, char *args, t_env *envp);

//heredoc/heredoc.c
int			heredoc(char *input, t_env *env);

//initialize/init.c
t_organize	*init_organize(char *input, t_program *mini);

//loop/loop.c
int			mini_loop(t_program *mini, int fd1, int fd2);

//parser/new_split.c
char		**ft_new_split(char *s, char c);

//parser/parseline_utils.c
int			size_without_quotes(char *input);
char		*remove_quotes(char *input);
char		*alloc_with_spaces(char *input);

//parser/parseline.c
int			ft_isspaces(char c);
char		*fix_redir_spaces(char *input);
int			parse_readline(char **input, t_env *env);

//parser/parsing.c
int			parse_organize(t_organize *program, char *str, t_env *env);
int			process_input(t_organize *program, char **str, t_env *env);

//parser/quotes.c
int			inside_quotes(char *input, int index);
char		*expand_variable(char *input, int *i, t_env *env);
char		*expander(char *input, t_env *env);

//signals/signal.c
void		sigint_handler(int signum);
void		signals_loop(void);

//signals/signals.c
void		ft_handle_signals(int id);

//utils/utils.c
void		free_ptr(char *ptr);
int			is_token(char c);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

//utils/utils2.c
char		*ft_strcpy(char *src);
int			pipes_counter(char *str);
void		update_sh_lvl(t_env *env);

#endif