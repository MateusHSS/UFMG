#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("^(\\d*\\s*)+$");
  return std::regex_match(str, regularExpr);
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);

  int sum = 0;
  int n;

  while(ss >> n){
    sum += n;
  }

  std::cout << sum << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("^\\s*[A-Za-z]+\\s+\\d+\\s+[A-Za-z]+\\s+\\d+$");
  
  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);
  std::string time_1, time_2, vencedor;
  int gols_1, gols_2;

  ss >> time_1 >> gols_1 >> time_2 >> gols_2;

  if(gols_1 > gols_2){
    vencedor = "Vencedor: " + time_1;
  }else if(gols_2 > gols_1){
    vencedor = "Vencedor: " + time_2;
  }else{
    vencedor = "Empate";
  }

  std::cout << vencedor << std::endl;
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);

  int sum = 0;
  std::string w;

  while(ss >> w){
    sum++;
  }

  std::cout << sum << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("^(([A-Za-z]+\\s*)+)$");
  return std::regex_match(str, regularExpr);
}

void InversorDeFrases::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);

  std::string w;
  int n = 0;

  while (ss >> w)
  {
    n++;
  }

  std::string new_word;

  for (int i = n-1; i <= 0; i--)
  {
    new_word +=
  }
  
  

  std::cout << ss.str().length() << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  return false;
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
  std::cout << "Imprime algo aqui!" << std::endl;
}