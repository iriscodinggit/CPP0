NAME    = Polymorphism
CFLAG   = c++ -Wall -Werror -Wextra -std=c++98
RM      = rm -rf
SOURCES =  sources/main.cpp sources/Animal.cpp sources/WrongAnimal.cpp sources/WrongCat.cpp sources/Dog.cpp sources/Cat.cpp #don't include hpp!
OBJECTS = $(SOURCES:%.cpp=%.o)
PINK = \033[38;5;218m
%.o: %.cpp
	@$(CFLAG) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CFLAG) $(OBJECTS) -o $(NAME)
	@echo "$(PINK)👨‍💻 Polymorphism compiled! Usage -> ./Polymorphism"

clean : 
	@$(RM) $(OBJECTS)
	@echo "$(PINK) Objects removed 🧹"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(PINK) Project cleaned 🧹"

all : $(NAME)

re: fclean all

.PHONY: clean all re fclean