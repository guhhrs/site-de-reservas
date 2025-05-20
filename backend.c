#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------- ESTRUTURAS ---------------------
#define MAX 100

typedef struct {
    int user_id;
    char cpf[15];
    char nome[100];
    char telefone[20];
    char celular[20];
    char data_nasc[11];
    char cep[10];
    char endereco[100];
    char tipo[20];
} Usuario;

typedef struct {
    int acomo_id;
    char tipo[50];
    char endereco[100];
    char cidade[50];
    char estado[50];
    char pais[50];
    int capacidade;
    char anfitriao[100];
    int disponibilidade;
} Acomodacao;

typedef struct {
    int reserva_id;
    int user_id;
    int acomo_id;
    char checkin[11];
    char checkout[11];
    int qtd_hospedes;
    float valor;
} Reserva;

typedef struct {
    int pag_id;
    int reserva_id;
    char tipo_trans[30];
    char dados_banc[100];
    char data_trans[11];
} Pagamento;

// --------------------- VARIÁVEIS GLOBAIS ---------------------
Usuario usuarios[MAX];
int totalUsuarios = 0;

Acomodacao acomodacoes[MAX];
int totalAcomodacoes = 0;

Reserva reservas[MAX];
int totalReservas = 0;

Pagamento pagamentos[MAX];
int totalPagamentos = 0;

// --------------------- FUNÇÕES USUÁRIO ---------------------
void cadastrarUsuario() {
    Usuario u;
    u.user_id = totalUsuarios + 1;

    printf("CPF: ");
    scanf(" %[^\n]", u.cpf);
    printf("Nome: ");
    scanf(" %[^\n]", u.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", u.telefone);
    printf("Celular: ");
    scanf(" %[^\n]", u.celular);
    printf("Data de Nascimento (DD/MM/AAAA): ");
    scanf(" %[^\n]", u.data_nasc);
    printf("CEP: ");
    scanf(" %[^\n]", u.cep);
    printf("Endereco: ");
    scanf(" %[^\n]", u.endereco);
    printf("Tipo (cliente/admin): ");
    scanf(" %[^\n]", u.tipo);

    usuarios[totalUsuarios++] = u;
    printf("Usuario cadastrado com sucesso!\n");
}

void listarUsuarios() {
    for(int i = 0; i < totalUsuarios; i++) {
        Usuario u = usuarios[i];
        printf("\nID: %d\nNome: %s\nCPF: %s\n", u.user_id, u.nome, u.cpf);
    }
}

// --------------------- FUNÇÕES ACOMODAÇÃO ---------------------
void cadastrarAcomodacao() {
    Acomodacao a;
    a.acomo_id = totalAcomodacoes + 1;

    printf("Tipo: ");
    scanf(" %[^\n]", a.tipo);
    printf("Endereco: ");
    scanf(" %[^\n]", a.endereco);
    printf("Cidade: ");
    scanf(" %[^\n]", a.cidade);
    printf("Estado: ");
    scanf(" %[^\n]", a.estado);
    printf("Pais: ");
    scanf(" %[^\n]", a.pais);
    printf("Capacidade: ");
    scanf("%d", &a.capacidade);
    printf("Anfitriao: ");
    scanf(" %[^\n]", a.anfitriao);
    printf("Disponibilidade (1=Sim, 0=Não): ");
    scanf("%d", &a.disponibilidade);

    acomodacoes[totalAcomodacoes++] = a;
    printf("Acomodacao cadastrada com sucesso!\n");
}

void listarAcomodacoes() {
    for(int i = 0; i < totalAcomodacoes; i++) {
        Acomodacao a = acomodacoes[i];
        printf("\nID: %d\nTipo: %s\nCidade: %s\nDisponível: %s\n",
               a.acomo_id, a.tipo, a.cidade, a.disponibilidade ? "Sim" : "Não");
    }
}

// --------------------- FUNÇÕES RESERVA ---------------------
void cadastrarReserva() {
    Reserva r;
    r.reserva_id = totalReservas + 1;

    printf("ID do Usuario: ");
    scanf("%d", &r.user_id);
    printf("ID da Acomodacao: ");
    scanf("%d", &r.acomo_id);
    printf("Check-in (DD/MM/AAAA): ");
    scanf(" %[^\n]", r.checkin);
    printf("Check-out (DD/MM/AAAA): ");
    scanf(" %[^\n]", r.checkout);
    printf("Qtd de Hospedes: ");
    scanf("%d", &r.qtd_hospedes);
    printf("Valor da reserva: ");
    scanf("%f", &r.valor);

    reservas[totalReservas++] = r;
    printf("Reserva cadastrada com sucesso!\n");
}

void listarReservas() {
    for(int i = 0; i < totalReservas; i++) {
        Reserva r = reservas[i];
        printf("\nID: %d\nUsuario ID: %d\nAcomodacao ID: %d\nCheck-in: %s\nCheck-out: %s\n",
               r.reserva_id, r.user_id, r.acomo_id, r.checkin, r.checkout);
    }
}

// --------------------- FUNÇÕES PAGAMENTO ---------------------
void cadastrarPagamento() {
    Pagamento p;
    p.pag_id = totalPagamentos + 1;

    printf("ID da Reserva: ");
    scanf("%d", &p.reserva_id);
    printf("Tipo de Transacao: ");
    scanf(" %[^\n]", p.tipo_trans);
    printf("Dados Bancarios: ");
    scanf(" %[^\n]", p.dados_banc);
    printf("Data da Transacao (DD/MM/AAAA): ");
    scanf(" %[^\n]", p.data_trans);

    pagamentos[totalPagamentos++] = p;
    printf("Pagamento registrado com sucesso!\n");
}

void listarPagamentos() {
    for(int i = 0; i < totalPagamentos; i++) {
        Pagamento p = pagamentos[i];
        printf("\nID: %d\nReserva ID: %d\nTipo: %s\nData: %s\n",
               p.pag_id, p.reserva_id, p.tipo_trans, p.data_trans);
    }
}

// --------------------- MENU ---------------------
void menu() {
    int opcao;
    do {
        printf("\n---- MENU RESERVA JA ----\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Listar Usuarios\n");
        printf("3. Cadastrar Acomodacao\n");
        printf("4. Listar Acomodacoes\n");
        printf("5. Cadastrar Reserva\n");
        printf("6. Listar Reservas\n");
        printf("7. Cadastrar Pagamento\n");
        printf("8. Listar Pagamentos\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrarUsuario(); break;
            case 2: listarUsuarios(); break;
            case 3: cadastrarAcomodacao(); break;
            case 4: listarAcomodacoes(); break;
            case 5: cadastrarReserva(); break;
            case 6: listarReservas(); break;
            case 7: cadastrarPagamento(); break;
            case 8: listarPagamentos(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
}

// --------------------- MAIN ---------------------
int main() {
    menu();
    return 0;
}