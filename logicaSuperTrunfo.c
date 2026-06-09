#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARTAS 100

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

// Variáveis globais
Carta cartas[MAX_CARTAS];
int totalCartas = 4; // Inicialmente temos 4 cartas

// Função para calcular densidade e PIB per capita
void calcularAtributos(Carta *carta) {
    carta->densidade = (float)carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0) / carta->populacao;
}

// Função para cadastrar uma nova carta
void cadastrarNovaCarta() {
    if(totalCartas >= MAX_CARTAS) {
        printf("\n❌ Limite máximo de cartas atingido!\n");
        return;
    }
    
    Carta novaCarta;
    
    printf("\n=========================================\n");
    printf("        CADASTRO DE NOVA CARTA\n");
    printf("=========================================\n");
    
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &novaCarta.estado);
    
    printf("Digite o código da carta (ex: C03, D04): ");
    scanf("%s", novaCarta.codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", novaCarta.nomeCidade);
    
    printf("Digite a população: ");
    scanf("%lu", &novaCarta.populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &novaCarta.area);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &novaCarta.pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &novaCarta.pontosTuristicos);
    
    // Calcular atributos derivados
    calcularAtributos(&novaCarta);
    
    // Adicionar ao array
    cartas[totalCartas] = novaCarta;
    totalCartas++;
    
    printf("\n✅ CARTA CADASTRADA COM SUCESSO!\n");
    printf("=========================================\n");
    
    // Exibir a carta cadastrada
    printf("\n--- DADOS DA CARTA CADASTRADA ---\n");
    printf("Estado: %c\n", novaCarta.estado);
    printf("Código: %s\n", novaCarta.codigo);
    printf("Cidade: %s\n", novaCarta.nomeCidade);
    printf("População: %lu habitantes\n", novaCarta.populacao);
    printf("Área: %.3f km²\n", novaCarta.area);
    printf("PIB: R$ %.2f bilhões\n", novaCarta.pib);
    printf("Pontos Turísticos: %d\n", novaCarta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", novaCarta.densidade);
    printf("PIB per Capita: R$ %.2f\n", novaCarta.pibPerCapita);
}

// Função para listar todas as cartas disponíveis
void listarCartas() {
    printf("\n=========================================\n");
    printf("        CARTAS DISPONÍVEIS\n");
    printf("=========================================\n");
    
    for(int i = 0; i < totalCartas; i++) {
        printf("%d. %s (%s) - %c\n", i+1, cartas[i].nomeCidade, cartas[i].codigo, cartas[i].estado);
    }
    printf("=========================================\n");
}

// Função para inicializar as cartas padrão
void inicializarCartasPadrao() {
    // Carta 1 - Belo Horizonte (M01)
    cartas[0].estado = 'M';
    strcpy(cartas[0].codigo, "M01");
    strcpy(cartas[0].nomeCidade, "Belo Horizonte");
    cartas[0].populacao = 2415872;
    cartas[0].area = 331.337;
    cartas[0].pib = 105.83;
    cartas[0].pontosTuristicos = 40;
    calcularAtributos(&cartas[0]);
    
    // Carta 2 - Rio de Janeiro (R01)
    cartas[1].estado = 'R';
    strcpy(cartas[1].codigo, "R01");
    strcpy(cartas[1].nomeCidade, "Rio de Janeiro");
    cartas[1].populacao = 6211223;
    cartas[1].area = 1200.329;
    cartas[1].pib = 418.46;
    cartas[1].pontosTuristicos = 100;
    calcularAtributos(&cartas[1]);
    
    // Carta 3 - Uberaba (M02)
    cartas[2].estado = 'M';
    strcpy(cartas[2].codigo, "M02");
    strcpy(cartas[2].nomeCidade, "Uberaba");
    cartas[2].populacao = 345893;
    cartas[2].area = 4523.957;
    cartas[2].pib = 23.6;
    cartas[2].pontosTuristicos = 20;
    calcularAtributos(&cartas[2]);
    
    // Carta 4 - Niterói (R02)
    cartas[3].estado = 'R';
    strcpy(cartas[3].codigo, "R02");
    strcpy(cartas[3].nomeCidade, "Niterói");
    cartas[3].populacao = 345893;
    cartas[3].area = 4523.957;
    cartas[3].pib = 11.2;
    cartas[3].pontosTuristicos = 20;
    calcularAtributos(&cartas[3]);
}

int main() {
    // Inicializar cartas padrão
    inicializarCartasPadrao();
    
    int opcaoPrincipal;
    int continuar = 1;
    
    while(continuar) {
        printf("\n=========================================\n");
        printf("      SUPER TRUNFO - NÍVEL MESTRE\n");
        printf("=========================================\n");
        printf("1. Cadastrar NOVA CARTA\n");
        printf("2. Listar todas as cartas\n");
        printf("3. JOGAR (comparar cartas)\n");
        printf("4. SAIR\n");
        printf("=========================================\n");
        printf("Total de cartas disponíveis: %d\n", totalCartas);
        printf("=========================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoPrincipal);
        
        switch(opcaoPrincipal) {
            case 1: // Cadastrar nova carta
                cadastrarNovaCarta();
                break;
                
            case 2: // Listar todas as cartas
                listarCartas();
                break;
                
            case 3: // JOGAR (comparar cartas)
                if(totalCartas < 2) {
                    printf("\n❌ É necessário ter pelo menos 2 cartas para jogar!\n");
                    break;
                }
                
                // Exibir cartas disponíveis
                listarCartas();
                
                // Escolha das cartas pelo usuário
                int escolha1, escolha2;
                printf("\nDigite o número da primeira carta (1 a %d): ", totalCartas);
                scanf("%d", &escolha1);
                printf("Digite o número da segunda carta (1 a %d): ", totalCartas);
                scanf("%d", &escolha2);
                
                // Validar escolhas
                if(escolha1 < 1 || escolha1 > totalCartas || escolha2 < 1 || escolha2 > totalCartas) {
                    printf("\n❌ Opção inválida! Escolha números entre 1 e %d.\n", totalCartas);
                    break;
                }
                
                if(escolha1 == escolha2) {
                    printf("\n❌ Você não pode comparar uma carta com ela mesma!\n");
                    break;
                }
                
                // Ajustar para índices do array (0-based)
                escolha1--;
                escolha2--;
                
                // Variáveis para as cartas escolhidas
                char* nomeCarta1 = cartas[escolha1].nomeCidade;
                char* nomeCarta2 = cartas[escolha2].nomeCidade;
                char* codCarta1 = cartas[escolha1].codigo;
                char* codCarta2 = cartas[escolha2].codigo;
                unsigned long int pop1 = cartas[escolha1].populacao;
                unsigned long int pop2 = cartas[escolha2].populacao;
                float area1 = cartas[escolha1].area;
                float area2 = cartas[escolha2].area;
                float pib1 = cartas[escolha1].pib;
                float pib2 = cartas[escolha2].pib;
                int pontos1 = cartas[escolha1].pontosTuristicos;
                int pontos2 = cartas[escolha2].pontosTuristicos;
                float densidade1 = cartas[escolha1].densidade;
                float densidade2 = cartas[escolha2].densidade;
                float pibPerCapita1 = cartas[escolha1].pibPerCapita;
                float pibPerCapita2 = cartas[escolha2].pibPerCapita;
                
                // Menu de comparação
                int opcaoJogo;
                int continuarJogo = 1;
                
                while(continuarJogo) {
                    printf("\n=========================================\n");
                    printf("           MENU DE COMPARAÇÃO\n");
                    printf("=========================================\n");
                    printf("1. Comparação SIMPLES (um atributo)\n");
                    printf("2. Comparação DUPLA (dois atributos)\n");
                    printf("3. SUPER PODER (todos atributos)\n");
                    printf("4. VOLTAR ao menu principal\n");
                    printf("=========================================\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcaoJogo);
                    
                    switch(opcaoJogo) {
                        case 1: // Comparação Simples
                            {
                                int atributo;
                                printf("\n--- ATRIBUTOS DISPONÍVEIS ---\n");
                                printf("1. População\n");
                                printf("2. Área\n");
                                printf("3. PIB\n");
                                printf("4. Pontos Turísticos\n");
                                printf("5. Densidade Demográfica (menor vence)\n");
                                printf("6. PIB per Capita\n");
                                printf("Escolha o atributo: ");
                                scanf("%d", &atributo);
                                
                                printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
                                printf("%s (%s) vs %s (%s)\n\n", nomeCarta1, codCarta1, nomeCarta2, codCarta2);
                                
                                switch(atributo) {
                                    case 1: // População
                                        printf("Atributo: POPULAÇÃO (maior vence)\n");
                                        printf("%s: %lu habitantes\n", nomeCarta1, pop1);
                                        printf("%s: %lu habitantes\n", nomeCarta2, pop2);
                                        printf("--------------------------------\n");
                                        printf(pop1 > pop2 ? "✅ VENCEDOR: %s\n" : (pop2 > pop1 ? "✅ VENCEDOR: %s\n" : "⚠️ EMPATE!\n"), 
                                               pop1 > pop2 ? nomeCarta1 : nomeCarta2);
                                        break;
                                    case 2: // Área
                                        printf("Atributo: ÁREA (maior vence)\n");
                                        printf("%s: %.3f km²\n", nomeCarta1, area1);
                                        printf("%s: %.3f km²\n", nomeCarta2, area2);
                                        printf("--------------------------------\n");
                                        printf(area1 > area2 ? "✅ VENCEDOR: %s\n" : (area2 > area1 ? "✅ VENCEDOR: %s\n" : "⚠️ EMPATE!\n"),
                                               area1 > area2 ? nomeCarta1 : nomeCarta2);
                                        break;
                                    case 3: // PIB
                                        printf("Atributo: PIB (maior vence)\n");
                                        printf("%s: R$ %.2f bilhões\n", nomeCarta1, pib1);
                                        printf("%s: R$ %.2f bilhões\n", nomeCarta2, pib2);
                                        printf("--------------------------------\n");
                                        printf(pib1 > pib2 ? "✅ VENCEDOR: %s\n" : (pib2 > pib1 ? "✅ VENCEDOR: %s\n" : "⚠️ EMPATE!\n"),
                                               pib1 > pib2 ? nomeCarta1 : nomeCarta2);
                                        break;
                                    case 4: // Pontos Turísticos
                                        printf("Atributo: PONTOS TURÍSTICOS (maior vence)\n");
                                        printf("%s: %d pontos\n", nomeCarta1, pontos1);
                                        printf("%s: %d pontos\n", nomeCarta2, pontos2);
                                        printf("--------------------------------\n");
                                        printf(pontos1 > pontos2 ? "✅ VENCEDOR: %s\n" : (pontos2 > pontos1 ? "✅ VENCEDOR: %s\n" : "⚠️ EMPATE!\n"),
                                               pontos1 > pontos2 ? nomeCarta1 : nomeCarta2);
                                        break;
                                    case 5: // Densidade (menor vence)
                                        printf("Atributo: DENSIDADE DEMOGRÁFICA (menor vence)\n");
                                        printf("%s: %.2f hab/km²\n", nomeCarta1, densidade1);
                                        printf("%s: %.2f hab/km²\n", nomeCarta2, densidade2);
                                        printf("--------------------------------\n");
                                        printf(densidade1 < densidade2 ? "✅ VENCEDOR: %s\n" : (densidade2 < densidade1 ? "✅ VENCEDOR: %s\n" : "⚠️ EMPATE!\n"),
                                               densidade1 < densidade2 ? nomeCarta1 : nomeCarta2);
                                        break;
                                    case 6: // PIB per Capita
                                        printf("Atributo: PIB PER CAPITA (maior vence)\n");
                                        printf("%s: R$ %.2f\n", nomeCarta1, pibPerCapita1);
                                        printf("%s: R$ %.2f\n", nomeCarta2, pibPerCapita2);
                                        printf("--------------------------------\n");
                                        printf(pibPerCapita1 > pibPerCapita2 ? "✅ VENCEDOR: %s\n" : (pibPerCapita2 > pibPerCapita1 ? "✅ VENCEDOR: %s\n" : "⚠️ EMPATE!\n"),
                                               pibPerCapita1 > pibPerCapita2 ? nomeCarta1 : nomeCarta2);
                                        break;
                                    default:
                                        printf("❌ Atributo inválido!\n");
                                }
                            }
                            break;
                            
                        case 2: // Comparação Dupla
                            {
                                int atributo1, atributo2;
                                int vitoriasCarta1 = 0, vitoriasCarta2 = 0;
                                
                                printf("\n--- ESCOLHA DOIS ATRIBUTOS PARA COMPARAÇÃO ---\n");
                                printf("1. População (maior vence)\n");
                                printf("2. Área (maior vence)\n");
                                printf("3. PIB (maior vence)\n");
                                printf("4. Pontos Turísticos (maior vence)\n");
                                printf("5. Densidade Demográfica (menor vence)\n");
                                printf("6. PIB per Capita (maior vence)\n");
                                printf("\nDigite o PRIMEIRO atributo: ");
                                scanf("%d", &atributo1);
                                printf("Digite o SEGUNDO atributo: ");
                                scanf("%d", &atributo2);
                                
                                printf("\n=========================================\n");
                                printf("     COMPARAÇÃO DUPLA DE ATRIBUTOS\n");
                                printf("=========================================\n");
                                printf("%s (%s) vs %s (%s)\n\n", nomeCarta1, codCarta1, nomeCarta2, codCarta2);
                                
                                // Primeiro atributo
                                printf("--- 1º ATRIBUTO ---\n");
                                switch(atributo1) {
                                    case 1:
                                        printf("POPULAÇÃO: %lu vs %lu\n", pop1, pop2);
                                        if(pop1 > pop2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(pop2 > pop1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 2:
                                        printf("ÁREA: %.3f vs %.3f km²\n", area1, area2);
                                        if(area1 > area2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(area2 > area1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 3:
                                        printf("PIB: R$ %.2f vs R$ %.2f bilhões\n", pib1, pib2);
                                        if(pib1 > pib2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(pib2 > pib1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 4:
                                        printf("PONTOS TURÍSTICOS: %d vs %d\n", pontos1, pontos2);
                                        if(pontos1 > pontos2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(pontos2 > pontos1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 5:
                                        printf("DENSIDADE: %.2f vs %.2f hab/km²\n", densidade1, densidade2);
                                        if(densidade1 < densidade2) { printf("✅ %s vence (menor densidade)!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(densidade2 < densidade1) { printf("✅ %s vence (menor densidade)!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 6:
                                        printf("PIB PER CAPITA: R$ %.2f vs R$ %.2f\n", pibPerCapita1, pibPerCapita2);
                                        if(pibPerCapita1 > pibPerCapita2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(pibPerCapita2 > pibPerCapita1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                }
                                
                                // Segundo atributo
                                printf("\n--- 2º ATRIBUTO ---\n");
                                switch(atributo2) {
                                    case 1:
                                        printf("POPULAÇÃO: %lu vs %lu\n", pop1, pop2);
                                        if(pop1 > pop2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(pop2 > pop1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 2:
                                        printf("ÁREA: %.3f vs %.3f km²\n", area1, area2);
                                        if(area1 > area2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(area2 > area1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 3:
                                        printf("PIB: R$ %.2f vs R$ %.2f bilhões\n", pib1, pib2);
                                        if(pib1 > pib2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(pib2 > pib1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 4:
                                        printf("PONTOS TURÍSTICOS: %d vs %d\n", pontos1, pontos2);
                                        if(pontos1 > pontos2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(pontos2 > pontos1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 5:
                                        printf("DENSIDADE: %.2f vs %.2f hab/km²\n", densidade1, densidade2);
                                        if(densidade1 < densidade2) { printf("✅ %s vence (menor densidade)!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(densidade2 < densidade1) { printf("✅ %s vence (menor densidade)!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                    case 6:
                                        printf("PIB PER CAPITA: R$ %.2f vs R$ %.2f\n", pibPerCapita1, pibPerCapita2);
                                        if(pibPerCapita1 > pibPerCapita2) { printf("✅ %s vence!\n", nomeCarta1); vitoriasCarta1++; }
                                        else if(pibPerCapita2 > pibPerCapita1) { printf("✅ %s vence!\n", nomeCarta2); vitoriasCarta2++; }
                                        else printf("⚠️ EMPATE!\n");
                                        break;
                                }
                                
                                printf("\n=== RESULTADO FINAL ===\n");
                                printf("Placar: %s %d x %d %s\n", nomeCarta1, vitoriasCarta1, vitoriasCarta2, nomeCarta2);
                                printf(vitoriasCarta1 > vitoriasCarta2 ? "🏆 VENCEDOR GERAL: %s 🏆\n" : 
                                      (vitoriasCarta2 > vitoriasCarta1 ? "🏆 VENCEDOR GERAL: %s 🏆\n" : "⚠️ EMPATE GERAL! ⚠️\n"),
                                      vitoriasCarta1 > vitoriasCarta2 ? nomeCarta1 : nomeCarta2);
                            }
                            break;
                            
                        case 3: // Super Poder
                            {
                                float superPoder1 = 0, superPoder2 = 0;
                                
                                printf("\n=== SUPER PODER ===\n");
                                printf("Comparando TODOS os atributos:\n\n");
                                
                                printf("▶ POPULAÇÃO: %lu vs %lu\n", pop1, pop2);
                                printf(pop1 > pop2 ? "   ✅ %s vence (+%lu)\n" : (pop2 > pop1 ? "   ✅ %s vence (+%lu)\n" : "   ⚠️ Empate\n"),
                                       pop1 > pop2 ? nomeCarta1 : nomeCarta2,
                                       pop1 > pop2 ? pop1 - pop2 : pop2 - pop1);
                                superPoder1 += pop1; superPoder2 += pop2;
                                
                                printf("\n▶ ÁREA: %.3f vs %.3f km²\n", area1, area2);
                                printf(area1 > area2 ? "   ✅ %s vence (+%.3f)\n" : (area2 > area1 ? "   ✅ %s vence (+%.3f)\n" : "   ⚠️ Empate\n"),
                                       area1 > area2 ? nomeCarta1 : nomeCarta2,
                                       area1 > area2 ? area1 - area2 : area2 - area1);
                                superPoder1 += area1; superPoder2 += area2;
                                
                                printf("\n▶ PIB: R$ %.2f vs R$ %.2f bi\n", pib1, pib2);
                                printf(pib1 > pib2 ? "   ✅ %s vence (+R$ %.2f)\n" : (pib2 > pib1 ? "   ✅ %s vence (+R$ %.2f)\n" : "   ⚠️ Empate\n"),
                                       pib1 > pib2 ? nomeCarta1 : nomeCarta2,
                                       pib1 > pib2 ? pib1 - pib2 : pib2 - pib1);
                                superPoder1 += pib1; superPoder2 += pib2;
                                
                                printf("\n▶ PONTOS TURÍSTICOS: %d vs %d\n", pontos1, pontos2);
                                printf(pontos1 > pontos2 ? "   ✅ %s vence (+%d)\n" : (pontos2 > pontos1 ? "   ✅ %s vence (+%d)\n" : "   ⚠️ Empate\n"),
                                       pontos1 > pontos2 ? nomeCarta1 : nomeCarta2,
                                       pontos1 > pontos2 ? pontos1 - pontos2 : pontos2 - pontos1);
                                superPoder1 += pontos1; superPoder2 += pontos2;
                                
                                printf("\n▶ DENSIDADE: %.2f vs %.2f hab/km² (menor vence)\n", densidade1, densidade2);
                                printf(densidade1 < densidade2 ? "   ✅ %s vence (menos %.2f hab/km²)\n" : 
                                      (densidade2 < densidade1 ? "   ✅ %s vence (menos %.2f hab/km²)\n" : "   ⚠️ Empate\n"),
                                      densidade1 < densidade2 ? nomeCarta1 : nomeCarta2,
                                      densidade1 < densidade2 ? densidade2 - densidade1 : densidade1 - densidade2);
                                superPoder1 += 1/densidade1; superPoder2 += 1/densidade2;
                                
                                printf("\n▶ PIB PER CAPITA: R$ %.2f vs R$ %.2f\n", pibPerCapita1, pibPerCapita2);
                                printf(pibPerCapita1 > pibPerCapita2 ? "   ✅ %s vence (+R$ %.2f)\n" : 
                                      (pibPerCapita2 > pibPerCapita1 ? "   ✅ %s vence (+R$ %.2f)\n" : "   ⚠️ Empate\n"),
                                      pibPerCapita1 > pibPerCapita2 ? nomeCarta1 : nomeCarta2,
                                      pibPerCapita1 > pibPerCapita2 ? pibPerCapita1 - pibPerCapita2 : pibPerCapita2 - pibPerCapita1);
                                superPoder1 += pibPerCapita1; superPoder2 += pibPerCapita2;
                                
                                printf("\n=== PONTUAÇÃO TOTAL (SUPER PODER) ===\n");
                                printf("%s: %.2f pontos\n", nomeCarta1, superPoder1);
                                printf("%s: %.2f pontos\n", nomeCarta2, superPoder2);
                                printf("--------------------------------\n");
                                
                                printf(superPoder1 > superPoder2 ? "🏆 CAMPEÃO DO SUPER PODER: %s 🏆\n" : 
                                      (superPoder2 > superPoder1 ? "🏆 CAMPEÃO DO SUPER PODER: %s 🏆\n" : "⚠️ EMPATE NO SUPER PODER! ⚠️\n"),
                                      superPoder1 > superPoder2 ? nomeCarta1 : nomeCarta2);
                            }
                            break;
                            
                        case 4: // Voltar
                            continuarJogo = 0;
                            break;
                            
                        default:
                            printf("\n❌ Opção inválida! Escolha entre 1 e 4.\n");
                    }
                }
                break;
                
            case 4: // Sair
                printf("\nEncerrando o jogo...\n");
                continuar = 0;
                break;
                
            default:
                printf("\n❌ Opção inválida! Escolha entre 1 e 4.\n");
        }
    }
    
    printf("\n=========================================\n");
    printf("     OBRIGADO POR JOGAR SUPER TRUNFO!\n");
    printf("=========================================\n");
    
    return 0;
}