// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define  MAX_TERRITORIOS 5 
#define MAX_MISSOES 20
#define TAM_STRING 50
#define TAM_TROPAS 20

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct territorio {
    char nome[30];
    char cor[10];
    int tropas; 
    
};

// --- Protótipos das Funções ---

// cadastro
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
void cadastrarTerritorios(struct territorio *war, int total) {
    int i;

    for (i = 0; i < total; i++) {
        
    }
}
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
void liberarMemoria(struct territorio *mapa);
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
     int total;
     int i;

    // 1. Configuração Inicial (Setup):
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");
    struct territorio *war;
    
    liberarMemoria(war);

    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    printf("Digite o numero de territorios: ");
    scanf("%d", &total);
    getchar(); // limpa o '\n'
    // - Define a cor do jogador e sorteia sua missão secreta.

    // 2. Laço Principal do Jogo (Game Loop):
    for (i = 0; i < total; i++ ){

    printf("\n--- Cadastrando Território %d ---\n", i + 1);

        printf("Nome do territorio: ");  
        fgets(war[i].nome, TAM_STRING, stdin); 

        printf("Cor do Exercito (ex: azul, verde): ");
        fgets(war[i].cor, TAM_STRING, stdin);

        printf("Numero de tropas: ");
        scanf("%d", &war[i].tropas);
        getchar(); // remove o '\n' que ficou no buffer

    }


    for (i = 0; i < total; i++ ){
        printf("Território %d\n", i + 1);
        printf("Nome: %s", war[i].nome);
        printf("Dominado por: %s", war[i].cor);
        printf("Tropas: %d\n\n", war[i].tropas);
    }

    // alocarMapa():
    // Aloca dinamicamente a memória para o vetor de territórios usando calloc.
    struct territorio *war = calloc(total, sizeof(struct territorio));

    // Retorna um ponteiro para a memória alocada ou NULL em caso de falha.
    if (war == NULL) {
    printf("Erro ao alocar memoria!\n");
    return 1;
    }

    cadastrarTerritorios(war, total);
    // - Opção 1: Inicia a fase de ataque.
    atacar(&war[0], &war[1]);

    liberarMemoria(war); 
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.
    
    
    printf("\n--- FASE DE ATAQUE ---\n");

    return 0;
}

    void liberarMemoria(struct territorio *mapa)
    {
        free(mapa);
    }
//Fase de ataque
void faseAtaque(struct territorio territorios[], int quantidade)
{
    int atacante, defensor;

    printf("\n--- FASE DE ATAQUE ---\n");

    for (int i = 0; i < quantidade; i++)
    {
        printf("%d. %s (Exercito %s, Tropas: %d)\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }

    printf("\nEscolha o territorio atacante (1 a %d, ou 0 para sair): ", quantidade);
    scanf("%d", &atacante);

    if (atacante == 0)
        return;

    printf("Escolha o territorio defensor (1 a %d): ", quantidade);
    scanf("%d", &defensor);

    if (atacante < 1 || atacante > quantidade ||
        defensor < 1 || defensor > quantidade ||
        atacante == defensor)
    {
        printf("Territorios invalidos!\n");
        return;
    }

    atacar(&territorios[atacante - 1], &territorios[defensor - 1]);
}

//Fase de resposta
   void atacar(struct territorio *atacante, struct territorio *defensor)
{
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n--- RESULTADO DA BATALHA ---\n");
    printf("O atacante %s rolou um dado e tirou: %d\n",
           atacante->nome, dadoAtacante);

    printf("O defensor %s rolou um dado e tirou: %d\n",
           defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor)
{
    printf("\nVITORIA DO ATAQUE!\n");

    defensor->tropas--;

    printf("O defensor perdeu 1 tropa.\n");

    if (defensor->tropas == 0)
    {
        printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s!\n",
               defensor->nome, atacante->cor);

        strcpy(defensor->cor, atacante->cor);

        int tropasTransferidas = atacante->tropas / 2;

        if (tropasTransferidas < 1)
            tropasTransferidas = 1;

        atacante->tropas -= tropasTransferidas;
        defensor->tropas = tropasTransferidas;

        printf("%d tropas foram transferidas.\n", tropasTransferidas);

        printf("\nEstado dos territorios:\n");
        printf("%s -> %d tropas\n", atacante->nome, atacante->tropas);
        printf("%s -> %d tropas\n", defensor->nome, defensor->tropas);
    }
}
else
{
    printf("\nO defensor venceu!\n");

    if (atacante->tropas > 1)
        atacante->tropas--;

    printf("%s perdeu 1 tropa.\n", 
    atacante->nome);
 }
}

//Enter
void proximoTurno()
{
    getchar(); // limpa o '\n' do scanf

    printf("\nPressione Enter para continuar para o proximo turno...");
    getchar();
}

//mapa atual
void mostrarMapa(struct territorio territorios[], int quantidade)
{
    printf("\n================================================\n");
    printf("           MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("================================================\n\n");

    for (int i = 0; i < quantidade; i++)
    {
        printf("%d. %s (Exercito %s, Tropas: %d)\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }

    printf("\n");
}

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
