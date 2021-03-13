#ifndef ALUNO_H
#define ALUNO_H

#include <string>

namespace Exercicio1
{
    class Aluno
    {
    public:
        char matricula[3+1]{""}, nome[30+1]{""};    // [1] VER NOTA ABAIXO.
        float notas[3]{-1,-1,-1};

        Aluno();
        Aluno(char* t_matricula, char* t_nome, float t_nota1, float t_nota2, float t_nota3);
        Aluno(std::string t_matricula, std::string t_nome, float t_nota1, float t_nota2, float t_nota3);
        float obterNotaMedia();
        std::string obterConceitoDaNotaMedia();
    };
}

// [1] Embora a matr�cula deva ter 3 caracteres, no m�ximo, e o nome 30 caracteres, no m�ximo, � adicionado 1 espa�o
//     a mais na array de chars para o caractere '\0' poder ser inserido, j� que ele � quem indica o final de um
//     array de caracteres. O +1 � apenas uma forma visual de indicar isso.

#endif
