CC = gcc # Definição do compilador
CFLAGS = -Wall -g # Ativação de avisos e debug

MAPA_DIR = mapa
INVENTARIO_DIR = inventario
DECISAO_DIR = decisao

all: jogo # Criação do executável

jogo: main.o mapa.o inventario.o decisao.o
	$(CC) $(CFLAGS) -o jogo main.o mapa.o inventario.o decisao.o

main.o: main.c $(MAPA_DIR)/mapa.h $(INVENTARIO_DIR)/inventario.h $(DECISAO_DIR)/decisao.h # Compilação do main.o
	$(CC) $(CFLAGS) -c main.c

mapa.o: $(MAPA_DIR)/mapa.c $(MAPA_DIR)/mapa.h # Compilação do mapa.o
	$(CC) $(CFLAGS) -c $(MAPA_DIR)/mapa.c

inventario.o: $(INVENTARIO_DIR)/inventario.c $(INVENTARIO_DIR)/inventario.h # Compilação do inventario.o
	$(CC) $(CFLAGS) -c $(INVENTARIO_DIR)/inventario.c

decisao.o: $(DECISAO_DIR)/decisao.c $(DECISAO_DIR)/decisao.h # Compilação do decisao.o
	$(CC) $(CFLAGS) -c $(DECISAO_DIR)/decisao.c

clean: # Remoção dos arquivos desnecessários
	rm -rf *.o *~ jogo
