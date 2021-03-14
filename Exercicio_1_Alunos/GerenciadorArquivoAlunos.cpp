#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "GerenciadorArquivoAlunos.h"
#include "Aluno.h"

using namespace std;

namespace Exercicio1
{
    // Public:

    void GerenciadorArquivoAlunos::gerarArquivoAlunos()
    {
        adicionarAlunoAoArquivo("001", "Ana", 9, 8, 10, true);
        adicionarAlunoAoArquivo("002", "Bernardo", 6, 7, 8, false);
        adicionarAlunoAoArquivo("003", "Carlos", 5, 7, 7, false);
        adicionarAlunoAoArquivo("004", "Dilma", 0, 0, 0, false);
        adicionarAlunoAoArquivo("005", "Eduarda", 10, 10, 10, false);
        adicionarAlunoAoArquivo("006", "Fernanda", 10, 10, 9, false);
        adicionarAlunoAoArquivo("007", "Gabriel", 1, 2, 3, false);
        adicionarAlunoAoArquivo("008", "Heitor", 8, 2, 7, false);
        adicionarAlunoAoArquivo("009", "Ivan", 5, 7, 6, false);
        adicionarAlunoAoArquivo("010", "Joao", 10, 10, 10, false);
        adicionarAlunoAoArquivo("011", "Karine", 8, 8, 8, false);
        adicionarAlunoAoArquivo("012", "Laura", 9, 9, 9, false);
        adicionarAlunoAoArquivo("013", "Maria", 4, 4, 4, false);
        adicionarAlunoAoArquivo("014", "Natalia", 6, 7, 7, false);
        adicionarAlunoAoArquivo("015", "Oscar", 10, 5, 6, false);
    }

    vector<Aluno> GerenciadorArquivoAlunos::lerAlunosDoArquivo()
    {
        vector<Aluno> alunos;
        Aluno aluno;

        fstream arquivo(m_nomeDoArquivo, ios::in | ios::binary);

        if (arquivo.fail())
        {
            cout << "Nao foi possivel abrir o arquivo." << endl;
            return {};
        }

        while(arquivo.read(reinterpret_cast<char*>(&aluno), sizeof(Aluno)))
        {
            alunos.push_back(aluno);
        }

        arquivo.close();

        return alunos;
    }

    // Private:

    void GerenciadorArquivoAlunos::adicionarAlunoAoArquivo(string t_matricula, string t_nome, float t_nota1, float t_nota2, float t_nota3, bool t_novoArquivo)
    {
        if (t_novoArquivo)
        {
            fstream arquivo(m_nomeDoArquivo, ios::out | ios::binary | ios::trunc);

            if (arquivo.fail())
            {
                cout << "Nao foi possivel manipular o arquivo." << endl;
                return;
            }

            Aluno aluno(t_matricula, t_nome, t_nota1, t_nota2, t_nota3);
            arquivo.write(reinterpret_cast<char*>(&aluno), sizeof(Aluno));
            arquivo.close();
        }
        else
        {
            int quantidadeAtualDeAlunos = obterQuantidadeDeAlunosNoArquivo();

            if (quantidadeAtualDeAlunos == -1)
            {
                return;
            }

            if (quantidadeAtualDeAlunos >= m_maximoDeRegistros)
            {
                cout << "O arquivo ja possui " << m_maximoDeRegistros << " alunos (maximo permitido na turma). Nao sera possivel adicionar o aluno de matricula " << t_matricula << "." << endl;
                return;
            }

            fstream arquivo(m_nomeDoArquivo, ios::out | ios::binary | ios::app);

            if (arquivo.fail())
            {
                cout << "Nao foi possivel manipular o arquivo." << endl;
                return;
            }

            Aluno aluno(t_matricula, t_nome, t_nota1, t_nota2, t_nota3);
            arquivo.write(reinterpret_cast<char*>(&aluno), sizeof(Aluno));
            arquivo.close();
        }
    }

    int GerenciadorArquivoAlunos::obterQuantidadeDeAlunosNoArquivo()
    {
        fstream arquivo(m_nomeDoArquivo, ios::in | ios::binary);

        if (arquivo.fail())
        {
            cout << "Nao foi possivel abrir o arquivo." << endl;
            return -1;
        }

        int counter = 0;
        Aluno aluno;

        while(arquivo.read(reinterpret_cast<char*>(&aluno), sizeof(Aluno)))
        {
            counter++;
        }

        return counter;
    }
}
