#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct peca {
    char cor[20];
    int tipo;
    float peso;
    float tamanho;
    char borda[10];
    struct peca *prox;
} peca;


int tam = 0;
peca *head = NULL;

// Função para cadastrar uma nova peça
void cadastro(){
    peca *nova = (peca *)malloc(sizeof(peca));
    nova->prox = NULL;
    if (nova == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    //Definição do tipo da peça:
    if(head == NULL){
        head = nova;
    }
    else{
        peca *aux = head;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = nova;
        
    }

    char escolha_char[20];

    printf("Qual o tipo da peça?\n [1] - Peça T\n [2] - Peça S1\n [3] - Peça S2\n [4] - Peça I\n [5] - Peça L1\n [6] - Peça L2\n [7] - Peça Q\n");
    scanf("%d", &nova ->tipo);
    printf("\033[1;35m_______________________\033[0m\n");

    //Definição da cor da peça:
    printf("Qual a cor da peça:\n-\033[1;35m[Roxa]\033[0m\n- \033[1;33m[Amarela]\033[0m\n- \033[1;32m[Verde]\033[0m\n- \033[1;34m[Azul]\033[0m\n- \033[38;5;214m[Laranja]\033[0m\n- \033[38;5;94m[Marrom]\033[0m\n- \033[1;31m[Vermelho]\033[0m\n");
    scanf(" %[^\n]", escolha_char);
    strcpy(nova->cor, escolha_char); 
    printf("\033[1;35m_______________________\033[0m\n");

    //Pergunta se a peça possui borda:
    printf("A peça possui borda[S/N]?\n");
    scanf(" %[^\n]", escolha_char);
    strcpy(nova->borda, escolha_char);
    printf("\033[1;35m_______________________\033[0m\n");

    //Pergunta o tamanho da peça:
    printf("Qual o tamanho da peça?[m]\n");
    scanf("%f", &nova->tamanho);
    printf("\033[1;35m_______________________\033[0m\n");

    //Pergunta o peso da peça:
    printf("Qual o peso da peso:[Kg]\n");
    scanf("%f", &nova ->peso);
    printf("Peça cadastrada com sucesso!\n");

    tam++;
}

// Função para listar as peças
void listar_pecas() {
    if (!head) {
        printf("Nenhuma peça cadastrada.\n");
        return;
    }

    peca *aux = head;
    int i = 1;
    printf("--- Listagem de Peças ---\n");

    while (aux) {
        printf("%dº Peça --> Cor: %s, Tipo: %d, Peso: %.2f Kg, Tamanho: %.2f m, Borda: %s\n",
               i++, aux->cor, aux->tipo, aux->peso, aux->tamanho, aux->borda);
        aux = aux->prox;
    }
}

//Lógica para reorganizar os peças por tipo:
//Função para dividir a lista
peca *dividir_lista(peca *head) {
    if (!head || !head->prox) return head;

    peca *slow = head, *fast = head->prox;
    
    while (fast && fast->prox) {
        slow = slow->prox;
        fast = fast->prox->prox;
    }

    peca *meio = slow->prox;
    slow->prox = NULL;
    return meio;
}
//Função para mesclar lista:
peca *mesclar_listas(peca *esq, peca *dir) {
    if (!esq) return dir;
    if (!dir) return esq;

    peca *resultado = NULL;
    
    //Ordenação por tipo
    if (esq->tipo <= dir->tipo) {
        resultado = esq;
        resultado->prox = mesclar_listas(esq->prox, dir);
    } else {
        resultado = dir;
        resultado->prox = mesclar_listas(esq, dir->prox);
    }
    
    return resultado;
}

peca *merge_sort(peca *head) {
    if (!head || !head->prox) return head;

    peca *meio = dividir_lista(head);
    peca *esq = merge_sort(head);
    peca *dir = merge_sort(meio);

    return mesclar_listas(esq, dir);
}

void reorganizar_pecas() {
    if (!head || !head->prox) {
        printf("A lista já está ordenada ou vazia.\n");
        return;
    }
    
    head = merge_sort(head);
    printf("Peças reorganizadas por tipo!\n");
}



#include <stdio.h>
#include <stdlib.h>

int main(){
    // Representação do menu de usuário:
    int opcao;
    
    do {
        printf("\033[1;31mMenu:\033[0m\n");
        printf("\033[1;35m_______________________\033[0m\n");
        printf("\033[1;31m1 - Cadastrar peça\033[0m\n");
        printf("\033[1;35m_______________________\033[0m\n");
        printf("\033[1;31m2 - Listar peças\033[0m\n");
        printf("\033[1;35m_______________________\033[0m\n");
        printf("\033[1;31m3 - Reorganizar peças\033[0m\n");
        printf("\033[1;35m_______________________\033[0m\n");
        printf("\033[1;31m0 - Sair\033[0m\n");
        printf("Opção: ");
        
        if (scanf("%d", &opcao) != 1) { //Tratando erro para caso o usuário insira uma string.
            printf("Entrada inválida, insira um número válido.\n");
            while (getchar() != '\n');  
            continue;  
        }

        switch (opcao) {
            case 1: 
                cadastro(); 
                break;
            case 2:
                listar_pecas();  
                break;
            case 3:
                reorganizar_pecas();  
                break;
            case 0:
                printf("Programa encerrado com sucesso\n");
                break;
            default:
                printf("Opção não encontrada, tente novamente.\n");
                break;
        }
    } while (opcao != 0);
    
    return 0;
}
