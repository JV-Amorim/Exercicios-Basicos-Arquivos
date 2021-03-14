#include <iostream>
#include <fstream>
#include "GerenciadorEleicao.h"

using namespace std;

namespace Exercicio2
{
    // Public:

    void GerenciadorEleicao::gerarArquivoDeVotos()
    {
        adicionarVotoAoArquivo(1, true);
        adicionarVotoAoArquivo(1, false);
        adicionarVotoAoArquivo(1, false);
        adicionarVotoAoArquivo(1, false);
        adicionarVotoAoArquivo(1, false);
        adicionarVotoAoArquivo(1, false);

        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);
        adicionarVotoAoArquivo(2, false);

        adicionarVotoAoArquivo(3, false);
        adicionarVotoAoArquivo(3, false);
        adicionarVotoAoArquivo(3, false);

        adicionarVotoAoArquivo(4, false);
        adicionarVotoAoArquivo(4, false);
        adicionarVotoAoArquivo(4, false);
        adicionarVotoAoArquivo(4, false);
        adicionarVotoAoArquivo(4, false);
        adicionarVotoAoArquivo(4, false);
        adicionarVotoAoArquivo(4, false);
        adicionarVotoAoArquivo(4, false);
        adicionarVotoAoArquivo(4, false);

        adicionarVotoAoArquivo(5, false);
        adicionarVotoAoArquivo(5, false);
        adicionarVotoAoArquivo(5, false);
        adicionarVotoAoArquivo(5, false);
        adicionarVotoAoArquivo(5, false);

        adicionarVotoAoArquivo(-2, false);
        adicionarVotoAoArquivo(-1, false);
        adicionarVotoAoArquivo(0, false);
        adicionarVotoAoArquivo(6, false);
        adicionarVotoAoArquivo(7, false);
    }


    vector<int> GerenciadorEleicao::obterContagemDeVotosDoArquivo()
    {
        ifstream arquivo(m_nomeDoArquivo);

        if (arquivo.fail())
        {
            cout << "Nao foi possivel abrir o arquivo." << endl << endl;
            return {};
        }

        // No vector abaixo: votos[0] = votos nulos; votos[n] = votos do candidato n, para n > 0.
        vector<int> votos{0, 0, 0, 0, 0, 0};
        string output;

        while (getline(arquivo, output))
        {
            int parsedOutput = std::stoi(output);

            if (parsedOutput < 1 || parsedOutput > 5)
            {
                votos[0]++;
            }
            else
            {
                votos[parsedOutput]++;
            }
        }

        return votos;
    }

    void GerenciadorEleicao::exibirResultadoDaEleicao(vector<int> votos)
    {
        if (votos.size() < 6)
        {
            cout << "Nao foi possivel exibir o resultado, devido a erros na contagem de votos." << endl << endl;
            return;
        }

        int candidatoMaisVotado = -1, candidatoMenosVotado = -1, quantidadeVotosMaisVotado = 0, quantidadeVotosMenosVotado = m_maximoDeRegistros;

        for (int i = 1; i <= 5; i++)
        {
            if (votos[i] == quantidadeVotosMaisVotado)
            {
                candidatoMaisVotado = -1;
            }
            else if (votos[i] > quantidadeVotosMaisVotado)
            {
                candidatoMaisVotado = i;
                quantidadeVotosMaisVotado = votos[i];
            }

            if (votos[i] == quantidadeVotosMenosVotado)
            {
                candidatoMenosVotado = -1;
            }
            else if (votos[i] < quantidadeVotosMenosVotado)
            {
                candidatoMenosVotado = i;
                quantidadeVotosMenosVotado = votos[i];
            }
        }

        cout << "CANDIDATO MAIS VOTADO" << endl;
        if (candidatoMaisVotado == -1)
        {
            cout << "Nao foi possivel determinar o candidato mais votado (empate)." << endl << endl;
        }
        else
        {
            cout << "Candidato: " << candidatoMaisVotado << endl << "Quantidade de votos: " << quantidadeVotosMaisVotado << endl << endl;
        }

        cout << "CANDIDATO MENOS VOTADO" << endl;
        if (candidatoMenosVotado == -1)
        {
            cout << "Nao foi possivel determinar o candidato menos votado (empate)." << endl << endl;
        }
        else
        {
            cout << "Candidato: " << candidatoMenosVotado << endl << "Quantidade de votos: " << quantidadeVotosMenosVotado << endl << endl;
        }

        cout << "VOTOS NULOS" << endl;
        cout << "Quantidade: " << votos[0] << endl;
    }

    // Private:

    void GerenciadorEleicao::adicionarVotoAoArquivo(int t_voto, bool t_novoArquivo)
    {
        if (t_novoArquivo)
        {
            ofstream arquivo(m_nomeDoArquivo);

            if (arquivo.fail())
            {
                cout << "Nao foi possivel manipular o arquivo." << endl << endl;
                return;
            }

            arquivo << t_voto << endl;

            arquivo.close();
        }
        else
        {
            int quantidadeAtualDeVotos = obterQuantidadeDeVotosNoArquivo();

            if (quantidadeAtualDeVotos == -1)
            {
                return;
            }

            if (quantidadeAtualDeVotos >= m_maximoDeRegistros)
            {
                cout << "O arquivo ja possui " << m_maximoDeRegistros << " votos (maximo permitido). Nao sera possivel adicionar o novo voto." << endl;
                return;
            }

            ofstream arquivo(m_nomeDoArquivo, ios::app);

            if (arquivo.fail())
            {
                cout << "Nao foi possivel manipular o arquivo." << endl << endl;
                return;
            }

            arquivo << t_voto << endl;

            arquivo.close();
        }
    }

    int GerenciadorEleicao::obterQuantidadeDeVotosNoArquivo()
    {
        ifstream arquivo(m_nomeDoArquivo);

        if (arquivo.fail())
        {
            cout << "Nao foi possivel abrir o arquivo." << endl << endl;
            return -1;
        }

        int counter = 0;
        string output;

        while (getline(arquivo, output))
        {
            counter++;
        }

        arquivo.close();

        return counter;
    }
}
