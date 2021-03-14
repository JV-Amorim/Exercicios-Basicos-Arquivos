#include <iostream>
#include <fstream>
#include <string.h>
#include "Modelo.h"

using namespace std;

namespace Exercicio5
{
    Modelo::Modelo(){ }

    Modelo::Modelo(char* t_nome, char t_sexo, char t_corDosOlhos, float t_altura, float t_peso)
    {
        strcpy(nome, t_nome);
        sexo = t_sexo;
        corDosOlhos = t_corDosOlhos;
        altura = t_altura;
        peso = t_peso;
    }

    Modelo::Modelo(string t_nome, char t_sexo, char t_corDosOlhos, float t_altura, float t_peso)
    {
        strcpy(nome, t_nome.c_str());
        sexo = t_sexo;
        corDosOlhos = t_corDosOlhos;
        altura = t_altura;
        peso = t_peso;
    }

    string Modelo::toString()
    {
        string modeloString = "";

        modeloString += "Nome: " + string(nome) + "\n";
        modeloString += "Sexo: ";
        modeloString += sexo;
        modeloString += "\n";
        modeloString += "Cor dos olhos: ";
        modeloString += corDosOlhos;
        modeloString += "\n";
        modeloString += "Altura: " + to_string(altura) + " m" + "\n";
        modeloString += "Peso: " + to_string(peso) + " kg" + "\n";

        return modeloString;
    }

    void Modelo::gravarEmArquivoTexto(ofstream& arquivo)
    {
        int nomeLength = strlen(nome);
        for (int i = 0; i < nomeLength; i++)
        {
            arquivo << nome[i];
        }
        for (int i = nomeLength; i < 30; i++)
        {
            arquivo << ' ';
        }

        arquivo << sexo << corDosOlhos << ' ';

        string alturaString = to_string(altura).substr(0, 4);
        string pesoString = to_string(peso).substr(0, 5);
        arquivo << alturaString << ' ' << pesoString << endl;
    }

    Modelo Modelo::parseFromArquivoTexto(string t_conteudo)
    {
        if (t_conteudo.size() != 43)
        {
            cout << "O conteudo lido, referente a um ou mais modelos, nao esta correto no arquivo." << endl << endl;
            return {};
        }

        Modelo modelo;
        strcpy(modelo.nome, t_conteudo.substr(0, 29).c_str());
        modelo.sexo = t_conteudo.substr(30, 1)[0];
        modelo.corDosOlhos = t_conteudo.substr(31, 1)[0];
        modelo.altura = atof(t_conteudo.substr(33, 4).c_str());
        modelo.peso = atof(t_conteudo.substr(38, 5).c_str());

        return modelo;
    }
}
