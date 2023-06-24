//Nath�lia Gon�alves Calisto Valim de Souza
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

/*  */

struct Candidato {//estrutura representando candidato
    string nome;
    int numero;
    Candidato *proximo=NULL;
};

vector<Candidato> candidatos;

typedef struct {//estrutura representando eleitor
    char nome[50];
    int numeroTitulo;
} Eleitor;

typedef struct {//estrutura representando votos
    int numeroTitulo;
    int numeroCandidato;
} Voto;

typedef struct {//estrutura de controle de ordem de chegada dos eleitores
    Eleitor eleitores[2];
    int frente;
    int fundo;
} FilaEleitores;


void inserirCandidato(Candidato candidato);//fun��o para inserir candidatos
void removerCandidato(int numero);//fun��o para remover candidatos
void listarCandidatos();//fun��o para listar candidatos

//fun��o de armazenamento para armazenar os dados dos candidatos
void salvarCandidatos();
void carregarCandidatos();


void inserirEleitor(Eleitor eleitor);//fun��o para inserir eleitor
void removerEleitor(int numeroTitulo);//fun��o para remover eleitor
void listarEleitores();//fun��o para listar todosos eleitores
bool verificarEleitorApto(int numeroTitulo);//fun��o para verificar se o eleitor est� apto a votar

void votar(int numeroTitulo);//essa fun��o verifica se o eleitor esta apto a votar

//implementando fun��es para gerar relat�rios
void gerarRelatorioVotos();//quantos votos cada candidato teve
void gerarRelatorioEleitoresFaltantes();//eleitores faltantes
void salvarRelatorio();//armazenar os dados do relat�rio



int main() {

setlocale(LC_ALL, "Portuguese");

string Candidato;




return 0;
}
//fun��o inserir candidato
void inserirCandidato(Candidato candidato) {
    candidatos.push_back(candidato);
    cout << "Candidato inserido com sucesso!" << endl;
}
//fun��o remover candidato
void removerCandidato(int numero) {
    for (int i = 0; i < candidatos.size(); i++) {
        if (candidatos[i].numero == numero) {
            candidatos.erase(candidatos.begin() + i);
            cout << "Candidato removido com sucesso!" << endl;
            return;
        }
    }
    cout << "Candidato n�o encontrado." << endl;
}
//fun��o listar candidatos
void listarCandidatos() {
    if (candidatos.empty()) {
        cout << "N�o h� candidatos cadastrados." << endl;
        return;
    }
    
    cout << "Lista de candidatos:" << endl;
    for (int i = 0; i < candidatos.size(); i++) {
        cout << "Nome: " << candidatos[i].nome << endl;
        cout << "N�mero: " << candidatos[i].numero << endl;
        cout << endl;
    }
}

//fun��o para salvar candidatos
void salvarCandidatos() {
    ofstream arquivo("candidatos.txt");
    
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }
    
    for (int i = 0; i < candidatos.size(); i++) {
        arquivo << "Nome: " << candidatos[i].nome << endl;
        arquivo << "N�mero: " << candidatos[i].numero << endl;
        arquivo << endl;
    }
    
    arquivo.close();
    cout << "Dados dos candidatos salvos com sucesso!" << endl;
}

