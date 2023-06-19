#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Cestruturas.c"
#include "Cprototipos.c"
#include "Cpilotos.c"
#include "Cvoos.c"
#include "Cviagens.c"

int main() {
    Piloto BDPilotos[TOTAL];
    Voo BDVoos[TOTAL];
    Viagem BDViagens[TOTAL];
    int totPilot = 0;
    int totVoo = 0;
    int totViagem = 0;

    int opcao_principal, opcao_submenu;
    do {
        printf("_-_-MENU PRINCIPAL-_-_\n");
        printf("1. Pilotos\n");
        printf("2. Voos\n");
        printf("3. Viagens\n");
        printf("4. Relatorios\n");
        printf("5. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d%*c", &opcao_principal);

        switch (opcao_principal) {
            case 1:
                carregar_piloto(BDPilotos, &totPilot);
                do {
                    printf("\n_-_-SUBMENU PILOTOS-_-_\n");
                    printf("1. Incluir Piloto\n");
                    printf("2. Alterar Piloto\n");
                    printf("3. Excluir Piloto\n");
                    printf("4. Listar Piloto\n");
                    printf("5. Listar Todos\n");
                    printf("6. Salvar\n");
                    printf("7. Voltar ao menu anterior\n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d%*c", &opcao_submenu);

                    switch (opcao_submenu) {
                        case 1:
                            incluir_piloto(BDPilotos, &totPilot);
                            break;
                        case 2:
                            alterar_piloto(BDPilotos, &totPilot);
                            break;
                        case 3:
                            excluir_piloto(BDPilotos, &totPilot);
                            break;
                        case 4:
                            listar_piloto(BDPilotos, &totPilot);
                            break;
                        case 5:
                            listarTodos_pilotos(BDPilotos, &totPilot);
                            break;
                        case 6:
                            salvar_piloto(BDPilotos, &totPilot);
                            break;
                        case 7:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }

                } while (opcao_submenu != 7);
                break;
            case 2:
                carregar_voo(BDVoos, &totVoo);
                do {
                    printf("\n_-_-SUBMENU VOOS-_-_\n");
                    printf("1. Incluir Voo\n");
                    printf("2. Alterar Voo\n");
                    printf("3. Excluir Voo\n");
                    printf("4. Listar Voo\n");
                    printf("5. Listar Todos\n");
                    printf("6. Salvar\n");
                    printf("7. Voltar ao menu anterior\n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d%*c", &opcao_submenu);

                    switch (opcao_submenu) {
                        case 1:
                            incluir_voo(BDVoos, &totVoo);
                            break;
                        case 2:
                            alterar_voo(BDVoos, &totVoo);
                            break;
                        case 3:
                            excluir_voo(BDVoos, &totVoo);
                            break;
                        case 4:
                            listar_voo(BDVoos, &totVoo);
                            break;
                        case 5:
                            listarTodos_voos(BDVoos, &totVoo);
                            break;
                        case 6:
                            salvar_voo(BDVoos, &totVoo);
                            break;
                        case 7:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while (opcao_submenu != 7);
                break;
            case 3:
                carregar_piloto(BDPilotos, &totPilot);
                carregar_voo(BDVoos, &totVoo);
                carregar_viagem(BDViagens, &totViagem);
                do {
                    printf("\n_-_-SUBMENU VIAGENS-_-_\n");
                    printf("1. Incluir Viagem\n");
                    printf("2. Alterar Viagem\n");
                    printf("3. Excluir Viagem\n");
                    printf("4. Listar Viagem\n");
                    printf("5. Listar Todos\n");
                    printf("6. Salvar\n");
                    printf("7. Voltar ao menu anterior\n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d%*c", &opcao_submenu);

                    switch (opcao_submenu) {
                        case 1:
                            incluir_viagem(BDViagens, &totViagem, BDPilotos, &totPilot, BDVoos, &totVoo);
                            break;
                        case 2:
                            alterar_viagem(BDViagens, &totViagem);
                            break;
                        case 3:
                            excluir_viagem(BDViagens, &totViagem);
                            break;
                        case 4:
                            listar_viagem(BDViagens, &totViagem);
                            break;
                        case 5:
                            listarTodos_viagens(BDViagens, &totViagem);
                            break;
                        case 6:
                            salvar_viagem(BDViagens, &totViagem);
                            break;
                        case 7:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while (opcao_submenu != 7);
                break;
            case 4:
                carregar_viagem(BDViagens, &totViagem);
                do {
                    printf("\n_-_-SUBMENU RELATORIOS-_-_\n");
                    printf("1. Viagens de 1 piloto\n");
                    printf("2. viagens entre datas\n");
                    printf("3. Voltar ao menu anterior\n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d%*c", &opcao_submenu);

                    switch (opcao_submenu) {
                        case 1:
                            relatorio_piloto(BDViagens, &totViagem);
                            break;
                        case 2:
                            relatorio_datas(BDViagens, &totViagem);
                            break;
                        case 3:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while (opcao_submenu != 3);
                break;
            case 5:
                printf("Opcao escolhida: Sair\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao_principal != 5);
}