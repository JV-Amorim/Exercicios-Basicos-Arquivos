#include <iostream>
#include <vector>
#include "Modelo.h"
#include "GerenciadorAgencia.h"

using namespace std;
using namespace Exercicio5;

int main()
{
    GerenciadorAgencia gerenciador;
    gerenciador.gerarArquivoDeDados();

    vector<Modelo> modelos = gerenciador.obterModelosDoArquivoDeDados();

    gerenciador.separarModelosPorSexoEmArquivosBinarios(modelos);

    cout << "CONTEUDO DO ARQUIVO TEXTO DE DADOS:" << endl << endl;
    for (int i = 0; i < (int)modelos.size(); i++)
    {
        cout << i + 1 << ". " << endl;
        cout << modelos[i].toString();
        cout << endl;
    }

    gerenciador.exibirModelosDosArquivosBinarios();

    return 0;
}
