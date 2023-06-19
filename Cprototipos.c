// Pilotos
void carregar_piloto(Piloto *vetPilot, int *totPilot);

void salvar_piloto(Piloto *vetPilot, int *totPilot);

int buscar_piloto(Piloto *vetPilot, int totPilot, char registro[]);

void incluir_piloto(Piloto *vetPilot, int *totPilot);

void alterar_piloto(Piloto *vetPilot, int *totPilot);

void excluir_piloto(Piloto *vetPilot, int *totPilot);

void listar_piloto(Piloto *vetPilot, int *totPilot);

void listarTodos_pilotos(Piloto *vetPilot, int *totPilot);

// Voos
void carregar_voo(Voo *vetVoo, int *totVoo);

void salvar_voo(Voo *vetVoo, int *totVoo);

int buscar_voo(Voo *vetVoo, int totVoo, char Numero[]);

void incluir_voo(Voo *vetVoo, int *totVoo);

void alterar_voo(Voo *vetVoo, int *totVoo);

void excluir_voo(Voo *vetVoo, int *totVoo);

void listar_voo(Voo *vetVoo, int *totVoo);

void listarTodos_voos(Voo *vetVoo, int *totVoo);

// Viagens
void carregar_viagem(Viagem *vetViagem, int *totViagem);

void salvar_viagem(Viagem *vetViagem, int *totViagem);

int verificar_piloto_voo(Piloto *vetPilot, int totPilot, char Registro[], Voo *vetVoo, int totVoo, char Numero[]);

int buscar_viagem(Viagem *vetViagem, int totViagem, char Registro[], char Numero[], char DataHora[]);

void incluir_viagem(Viagem *vetViagem, int *totViagem, Piloto *vetPilot, int *totPilot, Voo *vetVoo, int *totVoo);

void alterar_viagem(Viagem *vetViagem, int *totViagem);

void excluir_viagem(Viagem *vetViagem, int *totViagem);

void listar_viagem(Viagem *vetViagem, int *totViagem);

void listarTodos_viagens(Viagem *vetViagem, int *totViagem);