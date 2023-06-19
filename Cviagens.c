#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carregar_viagem(Viagem *vetViagem, int *totViagem) {
    FILE *arqViagens;

    arqViagens = fopen("viagens.dat", "rb");

    if (arqViagens == NULL) {
        arqViagens = fopen("viagens.dat", "wb");
        printf("\nArquivo criado com sucesso!\n");
        return;
    } else {   
        fread(totViagem, sizeof(int), 1, arqViagens);
        fread(vetViagem, sizeof(Viagem), *totViagem, arqViagens);
        fclose(arqViagens);
        printf("\nArquivo carregado com sucesso!\n");
        return;
    }
}

void salvar_viagem(Viagem *vetViagem, int *totViagem) {
    FILE *arqViagens;

    arqViagens = fopen("viagens.dat", "wb");

    if (arqViagens == NULL) {
        printf("\n*ERRO* nao foi possivel abrir o arquivo!\n");
        return;
    } else {
        fwrite(totViagem, sizeof(int), 1, arqViagens);
        fwrite(vetViagem, sizeof(Viagem), *totViagem, arqViagens);
        fclose(arqViagens);
        printf("\nArquivo salvo com sucesso!\n");
        return;
    }
}

int verificar_piloto_voo(Piloto *vetPilot, int totPilot, char registro[], Voo *vetVoo, int totVoo, char numero[]) {
    int i;
    for(i=0 ; i < totPilot ; i++) {
        if (strcmp(vetPilot[i].Registro, registro) == 0) {
            for(i=0 ; i < totVoo ; i++) {
                if (strcmp(vetVoo[i].Numero, numero) == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int buscar_viagem(Viagem *vetViagem, int totViagem, char registro[], char numero[], char dataHora[]) {
    int i;
    for(i=0 ; i < totViagem ; i++) {
        if (strcmp(vetViagem[i].Registro, registro) == 0 && strcmp(vetViagem[i].DataHora, dataHora) == 0) {
            return i;
        } else if (strcmp(vetViagem[i].Numero, numero) == 0 && strcmp(vetViagem[i].DataHora, dataHora) == 0) {
            return i;
        } else if (strcmp(vetViagem[i].Registro, registro) == 0 && strcmp(vetViagem[i].Numero, numero) == 0 && strcmp(vetViagem[i].DataHora, dataHora) == 0) {
            return i;
        }        
    }
    return -1;
}  

void incluir_viagem(Viagem *vetViagem, int *totViagem, Piloto *vetPilot, int *totPilot, Voo *vetVoo, int *totVoo) {
    char registro[12];
    char numero[12];
    char dataHora[17];
    int qtdPassageiros;
    char LIXO[2];

    printf("\n_-_-Incluir Viagem-_-_\n");
    
    if (*totViagem == TOTAL) {
        printf("\n*ERRO* nao ha espaço para incluir mais uma Viagem!\n");
    } else {
        printf("\nRegistro do Piloto: ");
        gets(registro);
        printf("\nNumero do Voo: ");
        gets(numero);

        if (verificar_piloto_voo(vetPilot, *totPilot, registro, vetVoo, *totVoo, numero) == 1){
            printf("\nData e Hora dd/mm/aaaa hh:mm: ");
            gets(dataHora);
            if (buscar_viagem(vetViagem, *totViagem, registro, numero, dataHora) != -1) {
                printf("\n*ERRO* Viagem ja cadastrada!\n");
            } else {
                printf("\nQuantidade de passageiros: ");
                scanf("%d%*c", &qtdPassageiros);

                strcpy(vetViagem[*totViagem].Registro, registro);
                strcpy(vetViagem[*totViagem].Numero, numero);
                strcpy(vetViagem[*totViagem].DataHora, dataHora);
                vetViagem[*totViagem].passageiros = qtdPassageiros;

                (*totViagem)++;
                printf("\n* Viagem incluida com sucesso!\n");
            }
        } else {
            printf("\n*ERRO* Piloto ou Voo nao registrado!\n");
        }
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}

void alterar_viagem(Viagem *vetViagem, int *totViagem) {
    char registro[12];
    char numero[12];
    char dataHora[17];
    int qtdPassageiros;
    char LIXO[2];
    int i;

    printf("\n_-_-Alterar Viagem-_-_\n");
    
    printf("\nRegistro do Piloto: ");
    gets(registro);
    printf("\nNumero do Voo: ");
    gets(numero);

    i = buscar_viagem(vetViagem, *totViagem, registro, numero, dataHora);

    if (i == -1) {
        printf("\n*ERRO* Viagem nao cadastrada!\n");
    } else {
        printf("\nData e Hora dd/mm/aaaa hh:mm: ");
        gets(dataHora);
        printf("\nQuantidade de passageiros: ");
        scanf("%d%*c", &qtdPassageiros);

        strcpy(vetViagem[i].DataHora, dataHora);
        vetViagem[i].passageiros = qtdPassageiros;
        printf("\nViagem alterada com sucesso!\n");
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}

void excluir_viagem(Viagem *vetViagem, int *totViagem) {
    char registro[12];
    char numero[12];
    char dataHora[17];
    char LIXO[2];
    int i;

    printf("\n_-_-Excluir Viagem-_-_\n");
    
    if (*totViagem == 0) {
        printf("\n*ERRO* Nao ha Viagens cadastradas!\n");
    } else {
        printf("\nRegistro do Piloto: ");
        scanf("%s", registro);
        printf("\nNumero do Voo: ");
        scanf("%s", numero);
        printf("\nData e Hora dd/mm/aaaa hh:mm: ");
        scanf("%s", dataHora);

        i = buscar_viagem(vetViagem, *totViagem, registro, numero, dataHora);
        if (i == -1) {
            printf("\n*ERRO* Viagem nao cadastrada!\n");
        } else {
            strcpy(vetViagem[i].Registro, vetViagem[i+1].Registro);
            strcpy(vetViagem[i].Numero, vetViagem[i+1].Numero);
            strcpy(vetViagem[i].DataHora, vetViagem[i+1].DataHora);
            vetViagem[i].passageiros = vetViagem[i+1].passageiros;
            (*totViagem)--;
            printf("\nViagem excluida com sucesso!\n");
        }        
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}

void listar_viagem(Viagem *vetViagem, int *totViagem) {
    char registro[12];
    char numero[12];
    char dataHora[17];
    char LIXO[2];
    int i;

    printf("\n_-_-Listar Viagem-_-_\n");
    
    if (*totViagem == 0) {
        printf("\n*ERRO* Nao ha Viagens cadastradas!\n");
    } else {
        printf("\nRegistro do Piloto: ");
        gets(registro);
        printf("\nNumero do Voo: ");
        gets(numero);
        printf("\nData e Hora dd/mm/aaaa hh:mm: ");
        gets(dataHora);

        i = buscar_viagem(vetViagem, *totViagem, registro, numero, dataHora);
        if (i == -1) {
            printf("\n*ERRO* Viagem nao cadastrada!\n");
        } else {
            printf("\nRegistro do Piloto: %s / ", vetViagem[i].Registro);
            printf("Numero do Voo: %s / ", vetViagem[i].Numero);
            printf("Data e Hora: %s / ", vetViagem[i].DataHora);
            printf("Quantidade de passageiros: %d / \n", vetViagem[i].passageiros);
        }
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}

void listarTodos_viagens(Viagem *vetViagem, int *totViagem) {
    int i;
    char LIXO[2];

    printf("\n_-_-Listar Viagem-_-_\n");
    
    if (*totViagem == 0) {
        printf("\n*ERRO* nao ha Viagens cadastradas!\n");
    } else {
        for(i=0 ; i < *totViagem ; i++) {
            printf("\nRegistro do Piloto: %s / ", vetViagem[i].Registro);
            printf("Numero do Voo: %s / ", vetViagem[i].Numero);
            printf("Data e Hora: %s / ", vetViagem[i].DataHora);
            printf("Quantidade de passageiros: %d / \n", vetViagem[i].passageiros);
        }
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}

/////////////////////////////////////////////
////////////// Relatorio ////////////////////
/////////////////////////////////////////////
void relatorio_piloto(Viagem *vetViagem, int *totViagem){
    char registro[12];
    int i;
    char LIXO[2];

    printf("Informe o registro do piloto: ");
    gets(registro);

    for(i = 0; i < *totViagem; i++){
        if(strcmp(vetViagem[i].Registro, registro) == 0){
            printf("\nNumero do Voo: %s / ", vetViagem[i].Numero);
            printf("Data e Hora: %s / ", vetViagem[i].DataHora);
            printf("Quantidade de passageiros: %d / \n", vetViagem[i].passageiros);
        }
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}

void relatorio_datas(Viagem *vetViagem, int *totViagem){
    char data1[17], data2[17], data3[17];
    int i;
    char LIXO[2];

    printf("Informe a data inicial (dd/mm/aaaa hh:mm): ");
    gets(data1);
    printf("Informe a data final (dd/mm/aaaa hh:mm): ");
    gets(data2);
    struct tm tm1 = parse_date_hour(data1);
    struct tm tm2 = parse_date_hour(data2);

    time_t tinicio = mktime(&tm1);
    time_t tfim = mktime(&tm2);

    for (i = 0; i < *totViagem; i++){
        strcpy(data3, vetViagem[i].DataHora);
        struct tm tm3 = parse_date_hour(data3);
        time_t tviagem = mktime(&tm3);

        if (difftime(tinicio,tviagem)<=0 && difftime(tfim,tviagem)>=0){
            printf("\nRegistro do Piloto: %s / ", vetViagem[i].Registro);
            printf("Numero do Voo: %s / ", vetViagem[i].Numero);
            printf("Data e Hora: %s / ", vetViagem[i].DataHora);
            printf("Quantidade de passageiros: %d / \n", vetViagem[i].passageiros);
        }
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}