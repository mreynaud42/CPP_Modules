# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 13:19:13 by mreynaud          #+#    #+#              #
#    Updated: 2025/07/03 20:51:26 by mreynaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------     HEAD     ------------------------------- #
# -------------------------------   preamble   ------------------------------- #
NAME			= RPN
DIR_BUILD		= .build/

WFLAGS			= -Wall -Werror -Wextra -std=c++98
DEPFLAGS		= -MMD -MP
CFLAGS			= $(WFLAGS) $(DEPFLAGS) $(IFLAGS)

CXX				= c++
RM				= rm -fr
AR				= ar -crs
MKDIR			= mkdir -p $(shell dirname $@)
ECHO			= echo

# -------------------------------    source    ------------------------------- #
SRCS			= main RPN

# -------------------------------    colors    ------------------------------- #
COLOR_GREEN	= \033[0;32m
COLOR_WHITE	= \033[0m

# -------------------------------   message   ------------------------------- #
MSG_OK		= $(COLOR_GREEN)[OK]$(COLOR_WHITE)
MSG_RULE	= $(ECHO) "$(MSG_OK) $(NAME) => Rule: $@"
MSG_OBJECT	= $(ECHO) "$(basename $(notdir $@))"
MSG_OBJECTS	= $(ECHO) "$(MSG_OK) compilation object"

# -------------------------------  obj & dep  ------------------------------- #
OBJ		= $(addprefix $(DIR_BUILD), $(addsuffix .o, $(SRCS)))
DEP		= $(OBJ:.o=.d)

-include $(DEP)
# -------------------------------    RULES    ------------------------------- #
# -------------------------------     all     ------------------------------- #
.DEFAULT_GOAL	:= all
.PHONY	: all
all		: $(NAME)

# -------------------------------     cpp     ------------------------------- #
$(NAME)	: $(OBJ)
	@$(MSG_OBJECTS)
	$(CXX) $(LFLAGS) -o $(NAME) $(OBJ)
	@$(MSG_RULE)

# -------------------------------    object    ------------------------------- #
$(DIR_BUILD)%.o : $(DIR_SRC)%.cpp Makefile
	@$(MKDIR)
	$(CXX) $(CFLAGS) -o $@ -c $<

# -------------------------------    clean    ------------------------------- #
.PHONY	: clean
clean	:
	@$(RM) $(DIR_BUILD)
	@$(MSG_RULE)

# -------------------------------    fclean    ------------------------------- #
.PHONY	: fclean
fclean	: clean
	@$(RM) $(NAME)
	@$(MSG_RULE)

# -------------------------------      re      ------------------------------- #
.PHONY	: re
re		: fclean all
	@$(MSG_RULE)
