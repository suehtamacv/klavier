## Bem vindo ao **That Piano Program**.

Este programa decorre da disciplina de Técnicas de Programação (Turma II) do curso de Engenharia Elétrica da UFCG, no período 2013.2, ministrado pelo professor Marcus Salerno.
Os autores deste programa, por ordem alfabética, são:

1. Fernando Marreiro II
2. Hugo Gayoso Meira Suassuna de Medeiros
3. Matheus Alves dos Santos
4. Matheus de Araújo Cavalcante (mantenedor)

##Instalação

### Instalação no Windows

Este programa foi compilado utilizando o _Visual Studio Ultimate 2012_. Para a execução do **That Piano Program** é essencial, portanto, a instalação do _Visual C++ Redistributable for Visual Studio 2012 Update 4_, versão **x86**. Ele pode ser encontrado [aqui](http://www.microsoft.com/en-us/download/details.aspx?id=30679).

Após isso o download do executável pode ser realizado. A última versão estável do **That Piano Program** e pode ser encontrada na página de _releases_, [aqui](https://github.com/suehtamacv/that-piano-program/releases/).

### Instalação no Linux

Você pode compilar o **That Piano Program** a partir do código fonte. Primeiro, instale as dependências. Em um sistema baseado em _Debian_, rode `sudo apt-get install qt5-default qt5-qmake libqt5multimedia5 libqt5multimedia5-dev`. Num sistema baseado em _Fedora_, rode então  `sudo yum install qt5-default qt5-qmake libqt5multimedia5 libqt5multimedia5-dev`.

Então faça o download do código fonte em _tar.gz_, no link encontrável no topo desta página. Abra o terminal e rode a seguinte sequência de comandos: `cd ~/Downloads; tar xzvf suehtamacv-that-piano-program-v2.0-beta-7-g7b673e7.tar.gz; mkdir thatpianoprogram-build; cd thatpianoprogram-build; qmake -makefile ../suehtamacv-that-piano-program-7b673e7; make`

A sequência de comandos compilará o programa na pasta _thatpianoprogram-build_. Deverá ocorrer sem erros se todas as dependências estiverem instaladas. Para executar o programa, você pode tanto dar um duplo clique no executável, ou na linha de comando, digitar `./that-piano-program`.

## Suporte

Algum problema com o **That Piano Program**? Envie um e-mail para o mantenedor (matheus.cavalcante@ee.ufcg.edu.br) e ele terá prazer em respondê-lo.
