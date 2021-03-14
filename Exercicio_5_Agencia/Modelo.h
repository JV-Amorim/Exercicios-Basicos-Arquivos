#ifndef MODELO_H
#define MODELO_H

#include <string>
#include <iostream>

namespace Exercicio5
{
    class Modelo
    {
    public:
        char nome[30+1]{""}, sexo, corDosOlhos;    // [1] VER NOTA ABAIXO.
        float altura{0}, peso{0};
        Modelo();
        Modelo(char* t_nome, char t_sexo, char t_corDosOlhos, float t_altura, float t_peso);
        Modelo(std::string t_nome, char t_sexo, char t_corDosOlhos, float t_altura, float t_peso);
        std::string toString();
        void gravarEmArquivoTexto(std::ofstream& arquivo);
		static Modelo parseFromArquivoTexto(std::string t_conteudo);
    };
}

// [1] Embora o nome deva ter 30 caracteres é adicionado 1 espaço a mais na array de chars para o caractere '\0' poder ser
//     inserido, já que ele é quem indica o final de um array de caracteres. O +1 é apenas uma forma visual de indicar isso.

#endif
