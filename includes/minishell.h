/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:26:57 by gcampos-          #+#    #+#             */
/*   Updated: 2024/11/13 22:35:23 by fgomes-c         ###   ########.fr       */
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
# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define META_CHARS "<>|"
# define ON 0
# define OFF 1

# define ERROR_PWD_ARGUMENTS "pwd: too many arguments"
# define ERROR_PWD_DIRECTORY "pwd: couldn't get current directory"
# define ERROR_CD_ARGS "cd: too many arguments"
# define ERROR_CD_HOME "cd: HOME not set"
# define ERROR_CD_OLDPWD "cd: OLDPWD not set"
# define ERROR_CD_DIRECTORY "cd: no such file or directory"

typedef struct s_organize
{
	char				*input_file;
	char				*output_file;
	char				*append_file;
	char				*heredoc_dlm;
	char				*cmds;
	char				*args;
	struct s_organize	*next;
}		t_organize;
/*
typedef struct s_envp
{
	char			*name;
	char			*value;
	int				visible;
	struct s_envp	*next;
}		t_envp;
*/

//main struct
typedef struct s_program
{
	int				pipes;
	int				loop;
	char			**env;
	char			**path;
	char			*user_input;
	char			*pwd;
	char			*old_pwd;
	// t_envp			*envp;
}		t_program;

//echo/echo.c
void		ft_echo(t_organize *program);

//pwd/pwd.c
void		ft_pwd(t_organize *program);

//clean/clean.c
void		free_array(char **array);
void		free_organize(t_organize *program);
void		free_program(t_program *mini); //old -> free_program(t_program *mini, t_organize *program);

//initialize/init.c
void		print_list(t_organize *program);
void		save_path(t_program *mini, char **envp);
t_organize	*init_organize(t_program *mini);
void		init_struct(t_program *mini, char **env);

//loop/loop.c
int			mini_loop(t_program *mini); // old -> int mini_loop(t_program *mini, t_organize *program);

//parser/new_split.c
char		**ft_new_split(char *s, char c);

//parser/parseline.c
int			ft_isspaces(char c);
char		*fix_redir_spaces(char *input);
int			parseline(t_program *mini);

//parser/parsing.c
void		parse_input(t_program *mini, t_organize *program);

//parser/quotes.c
int			inside_quotes(char *input, int index);
char		*expand_variable(char *input, int *i);
char		*expander(char *input);

//utils/utils.c
int			is_token(char c);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

//utils/utils2.c
char		*ft_strcpy(char *src);
int			pipes_counter(char *str);
void		update_sh_lvl(t_program *mini);

#endif