# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 21:25:07 by syamada           #+#    #+#              #
#    Updated: 2018/10/03 12:49:05 by syamada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
DEBUG		:= -g
SANITIZER	:= -fsanitize=address

LIB			:= libft.a
LIBDIR		:= libft

SRCDIR		:= srcs
INCDIR		:= includes

MINI		:= minishell

MINISRC		+= $(addprefix $(SRCDIR)/, minishell.c read_cmd.c \
			   cd_func.c echo_func.c env_funcs.c pwd_func.c \
			   exit_func.c env_crud.c error.c)

#color
COM_COLOR	:= \033[0;34m
OK_COLOR	:= \033[0;32m
EXEC_COLOR	:= \033[1;32m
DEBUG_COLOR	:= \033[0;33m
NO_COLOR	:= \033[m

.PHONY: all
all: $(MINI)

$(MINI): $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(MINISRC) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

$(LIBDIR)/$(LIB):
	@make -C $(LIBDIR)

.PHONY: clean
clean:
	@make -C $(LIBDIR) clean

.PHONY: fclean
fclean:
	@make -C $(LIBDIR) fclean
	@printf "%b" "$(NO_COLOR)Removing $(MINI)...\n"
	@rm -f $(MINI)
	@printf "%b" "$(OK_COLOR)[OK]: $(NO_COLOR)$(MINI) were successfully removed\n"

.PHONY: re
re: fclean all

sanitize: $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(SANITIZER) $(MINISRC) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

.PHONY: debug
debug:
	@rm -f d$(MINI)
	@make d$(MINI)

d$(MINI): $(LIBDIR) $(LIBDIR)/$(LIB)
	@printf "%b" "$(DEBUG_COLOR)[DEBUG MODE] $(NO_COLOR)Creating $(EXEC_COLOR)$@"
	@$(CC) -o $@ $(CFLAG) $(DEBUG) $(MINISRC) -I$(INCDIR) -L$< -lft
	@printf "%b" " ✔\n"

.PHONY: cleandebug
cleandebug:
	@rm -rf d$(MINI).dSYM
	@rm -f d$(MINI)

.PHONY: quick
quick:
	@printf "%b" "Quick recompile for $(MINI)\n"
	@rm -f $(MINI)
	@make $(MINI)
