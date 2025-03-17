CC = gcc # Definição do compilador
CFLAGS = -Wall -g # Ativação de avisos e debug

all: jogo # Criação do executável

jogo: main.o mapa.o inventario.o
	$(CC) $(CFLAGS) -o jogo main.o mapa.o inventario.o $(LIBS)

main.o: main.c mapa.h inventario.h # Compilação do main.o
	$(CC) $(CFLAGS) -c main.c

mapa.o: mapa.c mapa.h # Compilação do mapa.o
	$(CC) $(CFLAGS) -c mapa.c

inventario.o: inventario.c inventario.h # Compilação do inventario.o
	$(CC) $(CFLAGS) -c inventario.c

clean: # Remoção dos arquivos desnecessários
	rm -rf *.o *~ jogo
