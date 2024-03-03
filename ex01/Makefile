CC 			=	c++
CFLAGS 		=	-Wall -Wextra -Werror 
OPTION 		=	-std=c++98
NAME 		=	converter
INCLUDES	=	./include
SRC			=	$(shell find ./src -name "main.cpp" -o -name "Serializer.cpp" -type f)

OBJECTS		=	$(SRC:.cpp=.o)

Y	= "\033[33m"
R	= "\033[31m"
G	= "\033[32m"
B	= "\033[34m"
X	= "\033[0m"
UP	= "\033[A"
CUT	= "\033[K"

all : $(NAME)

$(NAME) : $(OBJECTS)
	      $(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(OPTION)
	@echo $(G)==================================$(X)
	@echo $(G)Make Successfully
	@echo $(G)The output file is [$(NAME)]$(X)
	@echo $(G)==================================$(X)
	@echo

$(OBJECTS) : %.o : %.cpp
	@echo $(Y)Compiling [$<]...
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@ $(OPTION)
	@echo $(Y)==================================$(X)
	@echo $(Y)Finish Compiling [$<]$(X)
	@echo $(Y)==================================$(X)
	@echo

clean:
	rm -rf $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	rm -rf $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re : fclean all

.PHONY : clean fclean all re