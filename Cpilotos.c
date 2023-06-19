#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carregar_piloto(Piloto *vetPilot, int *totPilot) {
    FILE *arqPilotos;

    arqPilotos = fopen("pilotos.dat", "rb");

    if (arqPilotos == NULL) {
        arqPilotos = fopen("pilotos.dat", "wb");
        printf("\nArquivo criado com sucesso!\n");
        return;
    } else {   
        fread(totPilot, sizeof(int), 1, arqPilotos);
        fread(vetPilot, sizeof(Piloto), *totPilot, arqPilotos);
        fclose(arqPilotos);
        printf("\nArquivo carregado com sucesso!\n");
        return;
    }
}

void salvar_piloto(Piloto *vetPilot, int *totPilot) {
    FILE *arqPilotos;

    arqPilotos = fopen("pilotos.dat", "wb");

    if (arqPilotos == NULL) {
        printf("\n*ERRO* Nao foi possivel abrir o arquivo!\n");
        return;
    } else {
        fwrite(totPilot, sizeof(int), 1, arqPilotos);
        fwrite(vetPilot, sizeof(Piloto), *totPilot, arqPilotos);
        fclose(arqPilotos);
        printf("\nArquivo salvo com sucesso!\n");
        return;
    }
}

int buscar_piloto(Piloto *vetPilot, int totPilot, char registro[]) {
    int i;
    for(i=0 ; i < totPilot ; i++) {
        if (strcmp(vetPilot[i].Registro, registro) == 0)
            return i;
    }
    return -1;
}

void incluir_piloto(Piloto *vetPilot, int *totPilot) {
    char registro[12];
    char nome[36];
    int horasDeVoo;
    char email[36];
    char LIXO[2];

    printf("\n_-_-Incluir Piloto-_-_\n");
    
    if (*totPilot == TOTAL) {
        printf("\n*ERRO* Nao ha espaço para incluir mais um Piloto!\n");
    } else {
        printf("Digite o registro do Piloto: ");
        gets(registro);

        if (buscar_piloto(vetPilot, *totPilot, registro) != -1 ) {
            printf("\n* Este registro ja existe!*\n");
        } else {
            printf("Digite o nome do piloto: ");
            gets(nome);
            printf("Digite o numero de horas de voo do piloto: ");
            scanf("%d%*c", &horasDeVoo);
            printf("Digite o email do piloto: ");
            gets(email);

            strcpy(vetPilot[*totPilot].Registro, registro);
            strcpy(vetPilot[*totPilot].nome, nome);
            vetPilot[*totPilot].horasDeVoo = horasDeVoo;
            strcpy(vetPilot[*totPilot].email, email);

            (*totPilot)++;
            printf("\n* Piloto inserido com sucesso!\n");
        }
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}

void alterar_piloto(Piloto *vetPilot, int *totPilot) {
    char registro[12];
    char nome[36];
    int horasDeVoo;
    char email[36];
    char LIXO[2];
    int index;
    
    printf("\n_-_-Alterar Piloto-_-_\n");
    
    printf("Digite o Registro do piloto: ");
    gets(registro);
    
    index = buscar_piloto(vetPilot, *totPilot, registro);
    
    if (index == -1) {
        printf("\n* Este Registo nao existe!*\n");
    } else {
        printf("Digite o nome do piloto: ");
        gets(nome);
        printf("Digite o numero de horas de voo do piloto: ");
        scanf("%d%*c", &horasDeVoo);
        printf("Digite o email do piloto: ");
        gets(email);

        strcpy(vetPilot[index].nome, nome);
        vetPilot[index].horasDeVoo = horasDeVoo;
        strcpy(vetPilot[index].email, email);

        printf("\n* Cadastro do Piloto alterado com sucesso!\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}

void excluir_piloto(Piloto *vetPilot, int *totPilot) {
    char registro[12];
    char LIXO[2];
    int index, i;
    
    printf("\n_-_-Excluir Piloto-_-_\n");
    
    printf("Digite o Registro do piloto: ");
    gets(registro);
    
        index = buscar_piloto(vetPilot, *totPilot, registro);
    
        if (index == -1) {
            printf("\n* Este Registro nao existe!*\n");
        } else {
            for(i=index; i < (*totPilot)-1 ; i++) {
                strcpy(vetPilot[index].Registro, vetPilot[index+1].Registro);
                strcpy(vetPilot[index].nome, vetPilot[index+1].nome);
                vetPilot[index].horasDeVoo = vetPilot[index+1].horasDeVoo;
                strcpy(vetPilot[index].email, vetPilot[index+1].email);
            }
            (*totPilot)--;
            printf("\n* Piloto excluido com sucesso!\n");
        }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}

void listar_piloto(Piloto *vetPilot, int *totPilot) {
    char registro[12];
    char LIXO[2];
    int index;
    
    printf("\n_-_-Listar Piloto-_-_\n");
    
    printf("Digite o Registro do Piloto: ");
    gets(registro);

    index = buscar_piloto(vetPilot, *totPilot, registro);
    
    if (index == -1) {
        printf("\n* Este Registro nao existe!*\n");
    } else {
        printf("\nRegistro: %s / ", vetPilot[index].Registro);
        printf("Nome: %s / ", vetPilot[index].nome);
        printf("Horas de Voo: %d / ", vetPilot[index].horasDeVoo);
        printf("Email: %s / \n", vetPilot[index].email);
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}

void listarTodos_pilotos(Piloto *vetPilot, int *totPilot) {
    char LIXO[2];
    int i;
    
    if ((*totPilot) == 0) {
        printf("\nNao existem pilotos registrados!\n");
    } else {
        printf("\n_-_-Listar Todos Pilotos-_-_\n");

        for( i=0; i<(*totPilot); i++ ) {            
            printf("\nRegistro: %s / ", vetPilot[i].Registro);
            printf("Nome: %s / ", vetPilot[i].nome);
            printf("Horas de Voo: %d / ", vetPilot[i].horasDeVoo);
            printf("Email: %s / \n", vetPilot[i].email);
        }
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}