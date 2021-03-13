#include <iostream>
#include <vector>
#include "Aluno.h"
#include "GerenciadorArquivoAlunos.h"

using namespace std;
using namespace Exercicio1;

int main()
{
    GerenciadorArquivoAlunos gerenciador;
    gerenciador.gerarArquivoAlunos();
    vector<Aluno> alunos = gerenciador.lerAlunosDoArquivo();

    for (int i = 0; i < (int)alunos.size(); i++)
    {
        Aluno alunoAtual = alunos[i];

        cout << "ALUNO " << i + 1 << endl;
        cout << "Matricula: " << alunoAtual.matricula << endl;
        cout << "Nome: " << alunoAtual.nome << endl;
        cout << "Nota media: " << alunoAtual.obterNotaMedia() << endl;
        cout << "Conceito: " << alunoAtual.obterConceitoDaNotaMedia() << endl << endl;
    }

    return 0;
}
