#include <string.h>
#include "Aluno.h"

using namespace std;

namespace Exercicio1
{
    Aluno::Aluno() { }

    Aluno::Aluno(char* t_matricula, char* t_nome, float t_nota1, float t_nota2, float t_nota3)
    {
        strcpy(matricula, t_matricula);
        strcpy(nome, t_nome);
        notas[0] = t_nota1;
        notas[1] = t_nota2;
        notas[2] = t_nota3;
    }

    Aluno::Aluno(string t_matricula, string t_nome, float t_nota1, float t_nota2, float t_nota3)
    {
        strcpy(matricula, t_matricula.c_str());
        strcpy(nome, t_nome.c_str());
        notas[0] = t_nota1;
        notas[1] = t_nota2;
        notas[2] = t_nota3;
    }

    float Aluno::obterNotaMedia()
    {
        return (notas[0] + notas[1] + notas[2])/3;
    }

    string Aluno::obterConceitoDaNotaMedia()
    {
        float notaMedia = obterNotaMedia();

        if (notaMedia >= 8.5)
        {
            return "Excelente";
        }
        else if (notaMedia >= 7 && notaMedia < 8.5)
        {
            return "Bom";
        }

        return "Preocupante";
    }
}
