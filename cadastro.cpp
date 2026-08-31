#include <iostream>
#include <cstring>
using namespace std;

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    Pessoa pessoas[10];
    int total = 0;

    // Adicionar
    strcpy(pessoas[0].nome, "João");
    pessoas[0].idade = 30;
    total++;

    strcpy(pessoas[1].nome, "Maria");
    pessoas[1].idade = 25;
    total++;

    // Listar
    for (int i = 0; i < total; i++) {
        cout << pessoas[i].nome << " - " << pessoas[i].idade << " anos" << endl;
    }

    return 0;
}
