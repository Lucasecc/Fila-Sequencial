# Nome do executável
PROG = fila

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra

# Arquivos fonte
SRC = main.c fila.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(PROG)

# Como compilar o programa
$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

# Limpar arquivos compilados
clean:
	del *.o $(PROG).exe 2>nul

# Rodar o programa após compilar
run: all
	./$(PROG)
