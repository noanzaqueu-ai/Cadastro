#include <iostream>
#include <cstring>
using namespace std;

const int MAX_PESSOAS = 100;

struct Pessoa {
    char nome[100];
    int idade;
    char cpf[15];
};

// Funções auxiliares
void adicionarPessoa(Pessoa pessoas[], int& total) {
    if (total >= MAX_PESSOAS) {
        cout << "Erro: Lista cheia!" << endl;
        return;
    }
    
    cout << "\n--- Adicionar Pessoa ---" << endl;
    cout << "Nome: ";
    cin.ignore();
    cin.getline(pessoas[total].nome, 100);
    
    cout << "Idade: ";
    cin >> pessoas[total].idade;
    
    cout << "CPF: ";
    cin.ignore();
    cin.getline(pessoas[total].cpf, 15);
    
    total++;
    cout << "Pessoa adicionada com sucesso!" << endl;
}

void listarPessoas(Pessoa pessoas[], int total) {
    if (total == 0) {
        cout << "Nenhuma pessoa cadastrada." << endl;
        return;
    }
    
    cout << "\n=== Lista de Pessoas ===" << endl;
    for (int i = 0; i < total; i++) {
        cout << "Nome: " << pessoas[i].nome << endl;
        cout << "Idade: " << pessoas[i].idade << endl;
        cout << "CPF: " << pessoas[i].cpf << endl;
        cout << "------------------------" << endl;
    }
}

void buscarPorCPF(Pessoa pessoas[], int total) {
    char cpf[15];
    cout << "Digite o CPF: ";
    cin.ignore();
    cin.getline(cpf, 15);
    
    for (int i = 0; i < total; i++) {
        if (strcmp(pessoas[i].cpf, cpf) == 0) {
            cout << "\nPessoa encontrada:" << endl;
            cout << "Nome: " << pessoas[i].nome << endl;
            cout << "Idade: " << pessoas[i].idade << endl;
            return;
        }
    }
    cout << "Pessoa não encontrada!" << endl;
}

void buscarPorNome(Pessoa pessoas[], int total) {
    char nome[100];
    cout << "Digite o nome: ";
    cin.ignore();
    cin.getline(nome, 100);
    
    bool encontrou = false;
    cout << "\nResultados da busca:" << endl;
    for (int i = 0; i < total; i++) {
        if (strstr(pessoas[i].nome, nome) != nullptr) {
            cout << "Nome: " << pessoas[i].nome << endl;
            cout << "Idade: " << pessoas[i].idade << endl;
            cout << "CPF: " << pessoas[i].cpf << endl;
            cout << "------------------------" << endl;
            encontrou = true;
        }
    }
    
    if (!encontrou) {
        cout << "Nenhuma pessoa encontrada!" << endl;
    }
}

void removerPessoa(Pessoa pessoas[], int& total) {
    char cpf[15];
    cout << "Digite o CPF da pessoa a remover: ";
    cin.ignore();
    cin.getline(cpf, 15);
    
    for (int i = 0; i < total; i++) {
        if (strcmp(pessoas[i].cpf, cpf) == 0) {
            // Move todas as pessoas após a removida uma posição para trás
            for (int j = i; j < total - 1; j++) {
                pessoas[j] = pessoas[j + 1];
            }
            total--;
            cout << "Pessoa removida com sucesso!" << endl;
            return;
        }
    }
    cout << "Pessoa não encontrada!" << endl;
}

int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int total = 0;
    int opcao;
    
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Adicionar Pessoa" << endl;
        cout << "2. Listar Pessoas" << endl;
        cout << "3. Buscar por CPF" << endl;
        cout << "4. Buscar por Nome" << endl;
        cout << "5. Remover Pessoa" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                adicionarPessoa(pessoas, total);
                break;
            case 2:
                listarPessoas(pessoas, total);
                break;
            case 3:
                buscarPorCPF(pessoas, total);
                break;
            case 4:
                buscarPorNome(pessoas, total);
                break;
            case 5:
                removerPessoa(pessoas, total);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);
    
    return 0;
}
