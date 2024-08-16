CXX = g++

CXXFLAGS = -Wall -std=c++11

EXEC = programa

SRCS = main.cpp admin.cpp funcionario.cpp mecanico.cpp ordem.cpp user.cpp vendedor.cpp cliente.cpp produtos.cpp servicos.cpp veiculo.cpp menu.cpp valida.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
