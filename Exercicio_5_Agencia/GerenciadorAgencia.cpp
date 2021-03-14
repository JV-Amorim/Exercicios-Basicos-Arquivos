#include <iostream>
#include <fstream>
#include <string.h>
#include "GerenciadorAgencia.h"

using namespace std;

namespace Exercicio5
{
    // Public:

    void GerenciadorAgencia::gerarArquivoDeDados()
    {
        Modelo modelo;

        strcpy(modelo.nome, "Gisele");
        modelo.sexo = 'F';
        modelo.corDosOlhos = 'A';
        modelo.altura = 1.8;
        modelo.peso = 65;
        adicionarModeloAoArquivoDeDados(modelo, true);

        strcpy(modelo.nome, "Julia");
        modelo.sexo = 'F';
        modelo.corDosOlhos = 'B';
        modelo.altura = 1.75;
        modelo.peso = 62.25;
        adicionarModeloAoArquivoDeDados(modelo, false);

        strcpy(modelo.nome, "Francisco");
        modelo.sexo = 'M';
        modelo.corDosOlhos = 'D';
        modelo.altura = 1.9;
        modelo.peso = 75;
        adicionarModeloAoArquivoDeDados(modelo, false);

        strcpy(modelo.nome, "Margarida");
        modelo.sexo = 'F';
        modelo.corDosOlhos = 'C';
        modelo.altura = 1.85;
        modelo.peso = 64.75;
        adicionarModeloAoArquivoDeDados(modelo, false);

        strcpy(modelo.nome, "Catarina");
        modelo.sexo = 'F';
        modelo.corDosOlhos = 'C';
        modelo.altura = 1.7;
        modelo.peso = 60.5;
        adicionarModeloAoArquivoDeDados(modelo, false);

        strcpy(modelo.nome, "Charles");
        modelo.sexo = 'M';
        modelo.corDosOlhos = 'A';
        modelo.altura = 2;
        modelo.peso = 80;
        adicionarModeloAoArquivoDeDados(modelo, false);
    }

    vector<Modelo> GerenciadorAgencia::obterModelosDoArquivoDeDados()
    {
        ifstream arquivo(m_nomeDoArquivoDeDados);

        if (arquivo.fail())
        {
            cout << "Nao foi possivel abrir o arquivo." << endl << endl;
            return { };
        }

        vector<Modelo> modelos;
        string output;

        while (getline(arquivo, output))
        {
            Modelo modelo = Modelo::parseFromArquivoTexto(output);
            modelos.push_back(modelo);
        }

        return modelos;
    }

    void GerenciadorAgencia::separarModelosPorSexoEmArquivosBinarios(vector<Modelo> t_modelos)
    {
        fstream arquivoM(m_nomeDoArquivoBinarioM, ios::out | ios::binary);
        fstream arquivoF(m_nomeDoArquivoBinarioF, ios::out | ios::binary);

        if (arquivoM.fail() || arquivoF.fail())
        {
            cout << "Nao foi possivel manipular um ou mais arquivos binarios." << endl << endl;
            return;
        }

        for (int i = 0; i < (int)t_modelos.size(); i++)
        {
            if (t_modelos[i].sexo == 'M')
            {
                arquivoM.write(reinterpret_cast<char*>(&t_modelos[i]), sizeof(Modelo));
            }
            else if (t_modelos[i].sexo == 'F')
            {
                arquivoF.write(reinterpret_cast<char*>(&t_modelos[i]), sizeof(Modelo));
            }
        }
    }

    void GerenciadorAgencia::exibirModelosDosArquivosBinarios()
    {
        fstream arquivoM(m_nomeDoArquivoBinarioM, ios::in | ios::binary);
        fstream arquivoF(m_nomeDoArquivoBinarioF, ios::in | ios::binary);

        if (arquivoM.fail() || arquivoF.fail())
        {
            cout << "Nao foi possivel abrir um ou mais arquivos binarios." << endl << endl;
            return;
        }

        Modelo modelo;
        int counter = 0;

        cout << "CONTEUDO DO ARQUIVO BINARIO DE MODELOS MASCULINOS:" << endl << endl;
        while (arquivoM.read(reinterpret_cast<char*>(&modelo), sizeof(Modelo)))
        {
            cout << ++counter << ". " << endl;
            cout << modelo.toString();
            cout << endl;
        }

        counter = 0;

        cout << "CONTEUDO DO ARQUIVO BINARIO DE MODELOS FEMININOS:" << endl << endl;
        while (arquivoF.read(reinterpret_cast<char*>(&modelo), sizeof(Modelo)))
        {
            cout << ++counter << ". " << endl;
            cout << modelo.toString();
            cout << endl;
        }
    }

    // Private:

    void GerenciadorAgencia::adicionarModeloAoArquivoDeDados(Modelo t_modelo, bool t_novoArquivo)
    {
        if (t_novoArquivo)
        {
            ofstream arquivo(m_nomeDoArquivoDeDados);

            if (arquivo.fail())
            {
                cout << "Nao foi possivel manipular o arquivo." << endl << endl;
                return;
            }

            t_modelo.gravarEmArquivoTexto(arquivo);

            arquivo.close();
        }
        else
        {
            ofstream arquivo(m_nomeDoArquivoDeDados, ios::app);

            if (arquivo.fail())
            {
                cout << "Nao foi possivel manipular o arquivo." << endl << endl;
                return;
            }

            t_modelo.gravarEmArquivoTexto(arquivo);

            arquivo.close();
        }
    }
}
