NAME    = Iter
CFLAG   = c++ -Wall -Werror -Wextra -std=c++98
RM      = rm -rf
SOURCES =  main.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
PINK = \033[38;5;218m
WHITE = \033[0m
%.o: %.cpp
	@$(CFLAG) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CFLAG) $(OBJECTS) -o $(NAME)
	@echo "$(PINK)👨‍💼 $(NAME) compiled! Usage -> ./$(NAME)$(WHITE)"

clean : 
	@$(RM) $(OBJECTS)
	@echo "$(PINK) Objects removed 🧹$(WHITE)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(PINK) Project cleaned 🧹$(WHITE)"

all : $(NAME)

re: fclean all

.PHONY: clean all re fclean