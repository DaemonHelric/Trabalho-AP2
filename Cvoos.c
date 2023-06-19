#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carregar_voo(Voo *vetVoo, int *totVoo) {
    FILE *arqVoos;

    arqVoos = fopen("voos.dat", "rb");

    if (arqVoos == NULL) {
        arqVoos = fopen("voos.dat", "wb");
        printf("\nArquivo criado com sucesso!\n");
        return;
    } else {   
        fread(totVoo, sizeof(int), 1, arqVoos);
        fread(vetVoo, sizeof(Voo), *totVoo, arqVoos);
        fclose(arqVoos);
        printf("\nArquivo carregado com sucesso!\n");
        return;
    }
}

void salvar_voo(Voo *vetVoo, int *totVoo) {
    FILE *arqVoos;

    arqVoos = fopen("voos.dat", "wb");

    if (arqVoos == NULL) {
        printf("\n*ERRO* Nao foi possivel abrir o arquivo!\n");
        return;
    } else {
        fwrite(totVoo, sizeof(int), 1, arqVoos);
        fwrite(vetVoo, sizeof(Voo), *totVoo, arqVoos);
        fclose(arqVoos);
        printf("\nArquivo salvo com sucesso!\n");
        return;
    }
}

int buscar_voo(Voo *vetVoo, int totVoo, char numero[]) {
    int i;
    for(i=0 ; i < totVoo ; i++) {
        if (strcmp(vetVoo[i].Numero, numero) == 0)
            return i;
    }
    return -1;
}

void incluir_voo(Voo *vetVoo, int *totVoo) {
    char numero[12];
    char cidadeOrigem[36];
    char cidadeDestino[36];
    char modeloAviao[12];
    char LIXO[2];

    printf("\n_-_-Incluir Voo-_-_\n");
    
    if (*totVoo == TOTAL) {
        printf("\n*ERRO* Nao ha espaço para incluir mais um Voo!\n");
    } else {
        printf("Digite o numero do Voo: ");
        gets(numero);

        if (buscar_voo(vetVoo, *totVoo, numero) != -1 ) {
            printf("\n* Este numero ja existe!*\n");
        } else {
            printf("Digite a cidade Origem do voo: ");
            gets(cidadeOrigem);
            printf("Digite a cidade Destino do voo: ");
            gets(cidadeDestino);
            printf("Digite o modelo do aviao: ");
            gets(modeloAviao);

            strcpy(vetVoo[*totVoo].Numero, numero);
            strcpy(vetVoo[*totVoo].cidadeOrigem, cidadeOrigem);
            strcpy(vetVoo[*totVoo].cidadeDestino, cidadeDestino);
            strcpy(vetVoo[*totVoo].modeloAviao, modeloAviao);

            (*totVoo)++;
            printf("\n* Voo inserido com sucesso!\n");
        }
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}

void alterar_voo(Voo *vetVoo, int *totVoo) {
    char numero[12];
    char cidadeOrigem[36];
    char cidadeDestino[36];
    char modeloAviao[12];
    char LIXO[2];
    int index;
    
    printf("\n_-_-Incluir Voo-_-_\n");
    
    printf("Digite o Numero do voo: ");
    gets(numero);
    
    index = buscar_voo(vetVoo, *totVoo, numero);
    
    if (index == -1) {
        printf("\n* Este Voo nao existe!*\n");
    } else {
        printf("Digite a cidade Origem do voo: ");
        gets(cidadeOrigem);
        printf("Digite a cidade Destino do voo: ");
        gets(cidadeDestino);
        printf("Digite o modelo do aviao: ");
        gets(modeloAviao);

        strcpy(vetVoo[index].cidadeOrigem, cidadeOrigem);
        strcpy(vetVoo[index].cidadeDestino, cidadeDestino);
        strcpy(vetVoo[index].modeloAviao, modeloAviao);

        printf("\n* Voo alterado com sucesso!\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}

void excluir_voo(Voo *vetVoo, int *totVoo) {
    char numero[12];
    char LIXO[2];
    int index, i;
    
    printf("\n_-_-Excluir Voo-_-_\n");
    
    printf("Digite o Numero do voo: ");
    gets(numero);
    
        index = buscar_voo(vetVoo, *totVoo, numero);
    
        if (index == -1) {
            printf("\n* Este Voo nao existe!*\n");
        } else {
            for(i=index; i < (*totVoo)-1 ; i++) {
                strcpy(vetVoo[index].Numero, vetVoo[index+1].Numero);
                strcpy(vetVoo[index].cidadeOrigem, vetVoo[index+1].cidadeOrigem);
                strcpy(vetVoo[index].cidadeDestino, vetVoo[index+1].cidadeDestino);
                strcpy(vetVoo[index].modeloAviao, vetVoo[index+1].modeloAviao);
            }
            (*totVoo)--;
            printf("\n* Voo excluido com sucesso!\n");
        }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}

void listar_voo(Voo *vetVoo, int *totVoo) {
    char numero[12];
    char LIXO[2];
    int index;
    
    printf("\n_-_-Listar Voo-_-_\n");
    
    printf("Digite o Numero do Voo: ");
    gets(numero);

    index = buscar_voo(vetVoo, *totVoo, numero);
    
    if (index == -1) {
        printf("\n* Este Registro nao existe!*\n");
    } else {
        printf("\nNumero: %s / ", vetVoo[index].Numero);
        printf("Origem: %s / ", vetVoo[index].cidadeOrigem);
        printf("Destino: %s / ", vetVoo[index].cidadeDestino);
        printf("Modelo do Aviao: %s / \n", vetVoo[index].modeloAviao);
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}

void listarTodos_voos(Voo *vetVoo, int *totVoo) {
    char LIXO[2];
    int i;
    
    if ((*totVoo) == 0) {
        printf("\nNao existem voos registrados!\n");
    } else {
        printf("\n_-_-Listar Todos Pilotos-_-_\n");

        for( i=0; i<(*totVoo); i++ ) {            
            printf("\nNumero: %s / ", vetVoo[i].Numero);
            printf("Origem: %s / ", vetVoo[i].cidadeOrigem);
            printf("Destino: %s / ", vetVoo[i].cidadeDestino);
            printf("Modelo do Aviao: %s / \n", vetVoo[i].modeloAviao);
        }
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}
