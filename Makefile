CC = gcc # Definição do compilador
CFLAGS = -Wall -g # Ativação de avisos e debug

all: jogo # Criação do executável

jogo: main.o mapa.o
	$(CC) $(CFLAGS) -o jogo main.o mapa.o $(LIBS)

main.o: main.c mapa.h # Compilação do main.o
	$(CC) $(CFLAGS) -c main.c

mapa.o: mapa.c mapa.h # Compilação do mapa.o
	$(CC) $(CFLAGS) -c mapa.c

clean: # Remoção dos arquivos desnecessários
	rm -rf *.o *~ jogo
