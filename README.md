# Exercícios Básicos - Arquivos

Exercícios básicos sobre arquivos em C++. Os projetos foram criados no CodeBlocks. Estes exercícios fazem parte da disciplina de Organização e Sistemas de Arquivos (Ciência da Computação (IFNMG)).

### Exercícios:

1) Considere um arquivo binário de registros (denominado "alunos.bin") onde cada registro armazena as seguintes informações sobre um aluno qualquer de uma turma de, no máximo, 50 alunos: matrícula (cadeia de 3 caracteres), nome (cadeia de 30 caracteres) e três notas referentes às avaliações feitas pelo aluno (valores reais entre 0 e 10). Faça um programa que leia este arquivo e apresente a matrícula, o nome, a nota média (a soma das três notas dividida por três) e o conceito ("excelente" se a média for maior ou igual a 8.5, "bom" se a média for maior ou igual a 7.0 e menor que 8.5, e "preocupante" se a média for menor que 7.0) de cada aluno da turma.

2) Faça um programa que apure o resultado de uma eleição que possua, no máximo, 100 eleitores. Suponha que existam 5 candidatos cujos códigos de identificação são: 1, 2, 3, 4, 5. Considere um arquivo texto (denominado "votos.txt") que contém, em cada linha, um determinado voto (um voto é representado pelo código de identificação do candidato). O programa deverá apresentar, como resultado, o código de identificação e a quantidade de votos do candidato mais votado, o código de identificação e a quantidade de votos do candidato menos votado e a quantidade de votos nulos (um voto nulo é um voto cujo código de identificação é inválido).

5) Considere um arquivo texto (denominado "dados.txt") que contém, em cada linha, as seguintes informações sobre os modelos de uma determinada agência:

- nome (cadeia de 30 caracteres, ocupando as colunas de 1 a 30 do arquivo texto);
- sexo (um caractere, ocupando a coluna 31 do arquivo texto, podendo ser 'M' ou 'F');
- cor dos olhos (um caractere, ocupando a coluna 32 do arquivo texto, podendo ser 'A', 'B', 'C', ou 'D');
- altura (valor real em metros, ocupando as colunas de 34 a 37 do arquivo texto);
- peso (valor real em quilos, ocupando as colunas de 39 a 43 do arquivo texto).

Faça um programa que separe este arquivo texto em dois arquivos binários de registros cujos campos são as informações descritas acima: o 1º arquivo deve conter apenas os modelos do sexo masculino ('M') e o 2º arquivo deve conter apenas os modelos do sexo feminino ('F').