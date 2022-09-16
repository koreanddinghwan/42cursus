NAME = simulation
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address -std=c++98
INC = .

SRCS = $(addprefix ./, main.cpp Base.cpp A.cpp B.cpp C.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INC) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -I$(INC) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean :
	make clean;
	rm -rf $(NAME);

re :
	make fclean;
	make all;

.PHONY : all clean fclean re
