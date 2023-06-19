#define TOTAL 30

typedef struct {
    char Registro[12];
    char nome[36];
    int horasDeVoo;
    char email[36];
} Piloto;

typedef struct {
    char Numero[12];
    char cidadeOrigem[36];
    char cidadeDestino[36];
    char modeloAviao[12];
} Voo;

typedef struct {
    char Registro[12];
    char Numero[12];
    char DataHora[17];
    int passageiros;
} Viagem;

struct tm parse_date_hour(char *str){
    struct tm tm = {0};
    char *token;

    token = strtok(str, "/ ");
    tm.tm_mday = atoi(token);
    token = strtok(NULL, "/ ");
    tm.tm_mon = atoi(token) - 1;
    token = strtok(NULL, "/ ");
    tm.tm_year = atoi(token) - 1900;
    token = strtok(NULL, ": ");
    tm.tm_hour = atoi(token);
    token = strtok(NULL, ": ");
    tm.tm_min = atoi(token);

    return tm;
};