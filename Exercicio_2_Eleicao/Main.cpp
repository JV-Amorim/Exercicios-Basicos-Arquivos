#include <iostream>
#include "GerenciadorEleicao.h"

using namespace std;
using namespace Exercicio2;

int main()
{
    GerenciadorEleicao gerenciador;
    gerenciador.gerarArquivoDeVotos();
    vector<int> votos = gerenciador.obterContagemDeVotosDoArquivo();
    gerenciador.exibirResultadoDaEleicao(votos);
    return 0;
}
