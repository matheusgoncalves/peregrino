#include <stdio.h>
#include <stdlib.h>
#include "mapa/mapa.h"
#include "inventario/inventario.h"
#include "decisao/decisao.h"
#include <time.h>

void gerenciarAcoes(NoMapa **localAtual, Inventario *inventario);
int eventoAleatorio();

int main(void) {
    int saude = 20;
    int escolha = 0;

    // Criando o inventário
    Inventario *inventario = criarInventario();

    // Criando os locais
    NoMapa *bree = criarNoMapa("Bree", "o vilarejo com a famosa Estalagem do Ponei Saltitante.");
    NoMapa *shire = criarNoMapa("Condado Ocidental", "uma regiao tranquila de colinas verdes e hobbits pacatos.");
    NoMapa *topo_vento = criarNoMapa("Topo do Vento", "uma colina antiga com ruinas que sussurram segredos do passado.");
    NoMapa *floresta = criarNoMapa("Floresta das Trevas", "um lugar misterioso e cheio de perigos.");
    NoMapa *valfenda = criarNoMapa("Valfenda", "a antiga morada dos anoes, agora infestada de inimigos.");
    NoMapa *lothlorien = criarNoMapa("Lothlorien", "a floresta dourada dos elfos, protegida pela magia de Galadriel.");
    NoMapa *pantanos = criarNoMapa("Pantanos dos Mortos", "lamacais traicoeiros onde luzes-fatuas levam viajantes a morte.");
    NoMapa *fangorn = criarNoMapa("Floresta de Fangorn", "morada dos Ents, onde as arvores guardam segredos ancestrais.");
    NoMapa *edoras = criarNoMapa("Edoras", "a capital de Rohan, onde o salao dourado de Meduseld se ergue.");
    NoMapa *isengard = criarNoMapa("Isengard", "a fortaleza de Saruman, com sua torre de Orthanc e maquinas de guerra.");
    NoMapa *gondor = criarNoMapa("Minas Tirith", "a cidade branca de Gondor, ultima esperanca dos homens.");
    NoMapa *minas_morgul = criarNoMapa("Minas Morgul", "a cidade-fantasma iluminada por uma luz palida e maligna.");
    NoMapa *mordor = criarNoMapa("Mordor", "a terra sombria de Sauron, cercada por montanhas de cinzas.");
    NoMapa *montanha = criarNoMapa("Montanha da Perdicao", "o seu destino final, o local onde o Um Anel deve ser destruido.");

    // Conectando os locais
    conectarMapas(bree, shire, 1);
    conectarMapas(shire, topo_vento, 1);
    conectarMapas(topo_vento, floresta, 1);
    conectarMapas(topo_vento, valfenda, 2);
    conectarMapas(floresta, pantanos, 1);
    conectarMapas(valfenda, lothlorien, 1);
    conectarMapas(pantanos, fangorn, 1);
    conectarMapas(lothlorien, fangorn, 1);
    conectarMapas(fangorn, edoras, 1);
    conectarMapas(fangorn, isengard, 2);
    conectarMapas(edoras, gondor, 1);
    conectarMapas(isengard, gondor, 1);
    conectarMapas(gondor, minas_morgul, 1);
    conectarMapas(gondor, mordor, 2);
    conectarMapas(minas_morgul, montanha, 1);
    conectarMapas(mordor, montanha, 1);

    // Boas vindas ao jogador
    printf("Seja bem vindo ao mundo de Peregrino. Aqui voce ira contar a historia de Frodo, o Hobbit mais importante da historia de Senhor dos Aneis, e suas decisoes impactam diretamente no rumo da historia.\n\n");
    printf("Um velho hobbit se aproxima na estalagem e entrega um anel dourado, sussurrando: 'Leve-o a Montanha da Perdicao.'\n");
    adicionarItem(inventario, "Um Anel");

    // Iniciando a exploração a partir de Bree
    NoMapa *localAtual = bree;

    // Loop principal da aventura
    while (localAtual != montanha) {
        // Evento em Bree
        if (localAtual == bree) {
            NoDecisao *decisao_bree = criarNoDecisao(
                "Na estalagem, um viajante suspeito te observa e oferece um item estranho em troca de informacoes sobre o anel.",
                "Aceitar e contar sobre o anel",
                "Recusar e manter silencio"
            );

            escolha = executarDecisao(decisao_bree);

            if (escolha == 1) {
                adicionarItem(inventario, "Amuleto Misterioso");
                printf("Voce conta sobre o anel e recebe um amuleto misterioso do viajante.\n");
                printf("Ele murmura: 'Isso pode te proteger... ou te amaldicoar.'\n\n");
            } else {
                printf("\nVoce mantem silencio, e o viajante sai frustrado, deixando uma faca para tras.\n");
                adicionarItem(inventario, "Faca Desgastada"); // A faca desgastada vai dar +1 na rolagem de ataque
            }
        } else if (localAtual == shire) {
            // Evento no Condado Ocidental
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);
            printf("Hobbits te dao suprimentos.\n");
            adicionarItem(inventario, "Pao Hobbit"); // +3 de vida
        } else if (localAtual == topo_vento) {
            // Evento no Topo do Vento
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            int evento_topo = eventoAleatorio();
            if (evento_topo == 0) {
                printf("Voce encontra uma pedra runica.\n");
                adicionarItem(inventario, "Pedra Runica"); // A pedra runica vai dar +1 na rolagem de ataque
            } else {
                printf("Espiritos surgem das ruinas! Vou implementar um combate aqui. Por enquanto o Frodo vai no soco.\n\n");
                saude-=10;
            }
        } else if (localAtual == floresta) {
            // Evento na Floresta das Trevas
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            NoDecisao *decisao_floresta = criarNoDecisao(
                "Voce encontra um acampamento abandonado.",
                "Revistar o acampamento",
                "Seguir em frente"
            );

            escolha = executarDecisao(decisao_floresta);

            if (escolha == 1) {
                adicionarItem(inventario, "Adaga Enferrujada");
                printf("Voce encontra uma adaga no acampamento!\n\n"); // +1 no ataque
            } else if (escolha == 2) {
                printf("Voce abandona o acampamento.\n\n");
            }
        } else if (localAtual == valfenda) {
            // Evento em Valfenda
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);
            printf("Voce ve uma comocao de elfos feridos e resolve ajuda-los.\n"); 
            printf("Os elfos feridos te dao uma pocao.\n");
            adicionarItem(inventario, "Pocao Elfica"); // +2 de vida            
        } else if (localAtual == pantanos) {
            // Evento nos Pântanos dos Mortos (se veio da Floresta)
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            NoDecisao *decisao_pantano = criarNoDecisao(
                "Voce ve algo cintilante na distancia. Luzes-fatuas tentam te atrair.",
                "Seguir as luzes",
                "Resistir"
            );

            escolha = executarDecisao(decisao_pantano);

            if (escolha == 1) {
                printf("Voce se perde e e atacado! Mais luta aqui.\n\n");
            } else {
                printf("Voce nao e bobo nem nada e segue seu caminho!\n\n");
            }
        } else if (localAtual == lothlorien) {
            // Evento em Lothlorien (se veio de Valfenda)
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            NoDecisao *decisao_loth = criarNoDecisao(
                "Voce encontra Galadriel e ele pede para ver o anel (laele).",
                "Mostrar o anel (laele)",
                "Esconder"
            );

            escolha = executarDecisao(decisao_loth);

            if (escolha == 1) {
                printf("Galadriel demonstra confianca e pede para voce tomar cuidado. Voce ganhou 2 de protecao.\n\n");
            }
        } else if (localAtual == fangorn) {
            // Evento em Fangorn
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            int evento_fangorn = eventoAleatorio();
            if (evento_fangorn == 0) {
                printf("Um Ent te entrega um galho magico.\n\n"); // +1 no ataque
                adicionarItem(inventario, "Galho Vivo");
            } else {
                printf("Aranhas gigantes aparecem! Aqui lascou.\n\n");
            }
        } else if (localAtual == edoras) {
            // Evento em Edoras
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            NoDecisao *decisao_edoras = criarNoDecisao(
                "Cavaleiros oferecem escolta ate Gondor.",
                "Aceitar a escolta",
                "Recusar a oferta."
            );

            escolha = executarDecisao(decisao_edoras);
            if (escolha == 1) {
                adicionarItem(inventario, "Lanca de Rohan");
                printf("Voce ganha uma lanca dos cavaleiros!\n\n"); // +3 no ataque
            }
        } else if (localAtual == isengard) {
            // Evento em Isengard
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            NoDecisao *decisao_isengard = criarNoDecisao(
                "Ao se aproximar de Isengard, voce ouve o som de maquinas e avista Uruk-hai patrulhando a area.",
                "Tentar sabotar uma das maquinas de guerra para criar uma distracao",
                "Enfrentar os Uruk-hai em combate direto"
            );
            
            escolha = executarDecisao(decisao_isengard);        
            if (escolha == 1) {
                printf("Voce sabota uma maquina de guerra, causando um caos que permite sua fuga.\n");
            } else if (escolha == 2) {
                printf("Voce enfrenta os Uruk-hai! Luta.\n");
                printf("Apos derrota-los, voce pega um machado de um dos corpos.\n\n");
                adicionarItem(inventario, "Machado Uruk");
            }
        } else if (localAtual == gondor) {
            // Evento em Minas Tirith
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            NoDecisao *decisao_gondor = criarNoDecisao(
                "Um guarda exige o anel para 'proteger a cidade'.",
                "Entregar o anel",
                "Recusar e lutar"
            );

            escolha = executarDecisao(decisao_gondor);
            if (escolha == 1) {
                removerItem(inventario, "Um Anel");
                printf("\nO guarda tomou o anel. Voce perdeu o jogo.\n");

                return 0;
            } else {
                printf("\nLutinha com o guarda.\n");
                printf("Voce vence e segue em frente.\n\n");        
            }
        } else if (localAtual == minas_morgul) {
            // Evento em Minas Morgul
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            NoDecisao *decisao_minas_morgul = criarNoDecisao(
                "A luz palida de Minas Morgul revela a silhueta de um Nazgul. Ele se aproxima, exigindo o Um Anel.",
                "Tentar negociar com o Nazgul oferecendo outro item",
                "Enfrentar o Nazgul em combate"
            );

            escolha = executarDecisao(decisao_minas_morgul);
            if (escolha == 1) {
                printf("\nVoce oferece uma pocao elfica ao Nazgul, que o aceita e te deixa passar, mas com um aviso sombrio.\n");
                removerItem(inventario, "Pocao Elfica");
            } else if (escolha == 2) {
                printf("\nNazgul te perseguem! Massacre de nazgul.\n");
                printf("Voce escapa com um ferimento.\n\n");
            }
        } else if (localAtual == mordor) {
            // Evento em Mordor
            printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);

            int evento_mordor = eventoAleatorio();
            if (evento_mordor == 0) {
                printf("\nVoce encontra um orc ferido que te da uma dica.\n");
                adicionarItem(inventario, "Pergaminho de Mordor");
            } else {
                printf("\nVoce confronta os orcs! Massacre de orc.\n");
                printf("Apos derrota-los, voce pega uma arma quebrada de um dos corpos.\n\n");
                adicionarItem(inventario, "Lamina de Orc");
            }
        }

        gerenciarAcoes(&localAtual, inventario);
    }

    // Chegada na Montanha da Perdição
    printf("\nVoce chega em %s, %s\n", localAtual->nome, localAtual->descricao);
    printf("Voce joga o Um Anel no fogo. A terra treme, e a missao esta completa!\n\n");
    removerItem(inventario, "Um Anel");
    printf("Vitoria! O mal foi derrotado.\n");

    return 0;
}

// Função para gerenciar ações
void gerenciarAcoes(NoMapa **localAtual, Inventario *inventario) {
    int opcao = 0;

    while (opcao != 1) {
        printf("O que deseja fazer?\n");
        printf("[1] - Explorar\n");
        printf("[2] - Ver inventario\n");
        printf("[3] - Ver informacoes obtidas\n\n");
    
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
    
        switch(opcao) {
            case 1:
                *localAtual = explorar(*localAtual); // Atualiza localAtual com o retorno de explorar
                if (*localAtual == NULL) {
                    printf("Nenhum caminho disponivel! Voltando para Bree.\n");
                    *localAtual = criarNoMapa("Bree", "o vilarejo com a famosa Estalagem do Ponei Saltitante.");
                }
                break;
                return;
            case 2:
                listarItens(inventario);
                break;
            case 3:
                printf("\nFalta implementar.\n\n");
                break;
            default:
                printf("Opcao invalida! Leia com mais atencao.\n");
                break;
        }
    }
}

// Função auxiliar para eventos aleatórios
int eventoAleatorio() {
    srand(time(NULL)); // Para aleatoriedade nos numeros
    return rand() % 3; // Retorna 0, 1 ou 2 para variar eventos
}
