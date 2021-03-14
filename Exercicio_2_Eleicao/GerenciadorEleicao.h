#ifndef GERENCIADOR_ELEICAO_H
#define GERENCIADOR_ELEICAO_H

#include <string>
#include <vector>

namespace Exercicio2
{
    class GerenciadorEleicao
    {
    private:
        const std::string m_nomeDoArquivo{"votos.txt"};
        const int m_maximoDeRegistros{100};
        void adicionarVotoAoArquivo(int t_voto, bool t_novoArquivo);
        int obterQuantidadeDeVotosNoArquivo();
    public:
        void gerarArquivoDeVotos();
        std::vector<int> obterContagemDeVotosDoArquivo();
        void exibirResultadoDaEleicao(std::vector<int> votos);
    };
}

#endif
