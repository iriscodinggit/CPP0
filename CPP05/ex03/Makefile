NAME    = AtLeastThisBeats
CFLAG   = c++ -Wall -Werror -Wextra -std=c++98
RM      = rm -rf
SOURCES =  sources/main.cpp sources/Bureaucrat.cpp sources/AForm.cpp sources/ShrubberyCreationForm.cpp sources/RobotomyRequestForm.cpp sources/PresidentialPardonForm.cpp sources/Intern.cpp #don't include hpp!
OBJECTS = $(SOURCES:%.cpp=%.o)
PINK = \033[38;5;218m
%.o: %.cpp
	@$(CFLAG) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CFLAG) $(OBJECTS) -o $(NAME)
	@echo "$(PINK)👨‍💼 $(NAME) compiled! Usage -> ./$(NAME)"

clean : 
	@$(RM) $(OBJECTS)
	@echo "$(PINK) Objects removed 🧹"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(PINK) Project cleaned 🧹"

all : $(NAME)

re: fclean all

.PHONY: clean all re fclean