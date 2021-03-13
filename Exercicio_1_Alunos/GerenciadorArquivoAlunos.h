#ifndef GERENCIADOR_ARQUIVO_ALUNOS_H
#define GERENCIADOR_ARQUIVO_ALUNOS_H

#include <string>
#include <vector>
#include "Aluno.h"

namespace Exercicio1
{
    class GerenciadorArquivoAlunos
    {
    private:
        const std::string m_nomeDoArquivo{"alunos.bin"};
        const int m_maximoDeRegistros{50};
        void adicionarAlunoAoArquivo(std::string t_matricula, std::string t_nome, float t_nota1, float t_nota2, float t_nota3,  bool t_novoArquivo);
        int obterQuantidadeDeAlunosNoArquivo();
    public:
        void gerarArquivoAlunos();
        std::vector<Aluno> lerAlunosDoArquivo();
    };
}

#endif
