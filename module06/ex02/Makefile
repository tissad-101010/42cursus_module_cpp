# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tissad <tissad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 08:44:42 by tissad            #+#    #+#              #
#    Updated: 2025/01/09 18:27:07 by tissad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilator
CXX = c++

# Compilator flags
CXXFLAGS = -g -Wall -Wextra -Werror -Wshadow -std=c++98 

# Target name
TARGET = identify

# Sources files
SRCS =	main.cpp \
		src/Base.cpp \
		src/A.cpp \
		src/B.cpp \
		src/C.cpp \
		

# Include files
INC = ./inc

# Object files (from source files)
OBJS = $(SRCS:.cpp=.o)

# make all rule (default rule)
all: $(TARGET)

# Rule to compile the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INC) -o $@ $^

# Rule to compile the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INC) -c $< -o $@

# Rule to clean object files
clean:
	rm -f $(OBJS) 

# rule to clean all files
fclean: clean
	rm -f $(TARGET) *~

# rule that clean all and recompile all
re: fclean all

# .PHONY is a special rule that is used to declare some rules as not being files
.PHONY: all clean fclean re
