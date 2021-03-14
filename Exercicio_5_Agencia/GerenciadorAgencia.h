#ifndef GERENCIADOR_AGENCIA_H
#define GERENCIADOR_AGENCIA_H

#include <string>
#include <vector>
#include "Modelo.h"

namespace Exercicio5
{
    class GerenciadorAgencia
    {
    private:
        const std::string m_nomeDoArquivoDeDados{"dados.txt"};
        const std::string m_nomeDoArquivoBinarioM{"modelosM.bin"};
        const std::string m_nomeDoArquivoBinarioF{"modelosF.bin"};
        void adicionarModeloAoArquivoDeDados(Modelo t_modelo, bool t_novoArquivo);
    public:
        void gerarArquivoDeDados();
        std::vector<Modelo> obterModelosDoArquivoDeDados();
        void separarModelosPorSexoEmArquivosBinarios(std::vector<Modelo> t_modelos);
        void exibirModelosDosArquivosBinarios();
    };
}

#endif
