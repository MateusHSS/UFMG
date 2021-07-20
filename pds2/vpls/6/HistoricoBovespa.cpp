#include "HistoricoBovespa.hpp"
#include <iomanip>

HistoricoBovespa::HistoricoBovespa(){}

void HistoricoBovespa::inserir_cotacao(std::string sigla, std::string data, double valor){
  Cotacao cotacao = Cotacao(data, valor);
  this->cotacoes[sigla].push_back(cotacao);
}

double HistoricoBovespa::calcular_valor_medio_acao(std::string sigla){
  double soma = 0;
  int total = 0;

  for(Cotacao cotacao : this->cotacoes.at(sigla)){
    soma += cotacao.get_valor();
    total ++;
  }

  double media = soma / total;

  return media;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_maxima_acao(std::string sigla){
  int init = 1;
  Cotacao* maxi;

  std::map<std::string, Cotacao>::iterator it;

  for (auto it = this->cotacoes.begin(); it != this->cotacoes.end(); it++) {
    if(it->first == sigla){
      std::vector<Cotacao>::iterator it2;
      for (it2 = it->second.begin(); it2 != it->second.end(); ++it2){
        if(init){
          maxi = &(*it2);
          init = 0;
        }else{
          if(it2->get_valor() > maxi->get_valor()){
            maxi = &(*it2);
          }
        }
      }
    }
  }
  return maxi;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_minima_acao(std::string sigla){
  int init = 1;
  Cotacao* mini;

  std::map<std::string, Cotacao>::iterator it;

  for (auto it = this->cotacoes.begin(); it != this->cotacoes.end(); it++) {
    if(it->first == sigla){
      std::vector<Cotacao>::iterator it2;
      for (it2 = it->second.begin(); it2 != it->second.end(); ++it2){
        if(init){
          mini = &(*it2);
          init = 0;
        }else{
          if(it2->get_valor() < mini->get_valor()){
            mini = &(*it2);
          }
        }
      }
    }
  }

  return mini;
}

void HistoricoBovespa::imprimir_estatisticas_completas(){
  std::cout << std::fixed << std::showpoint;
  std::cout << std::setprecision(2);
  
  std::map<std::string, std::vector<Cotacao>>::iterator it;
  for(it = this->cotacoes.begin(); it != this->cotacoes.end(); it++){
    std::cout << it->first << " ";
    for(Cotacao cotacao : it->second){
      std::cout << cotacao.get_valor() << " ";
    }
    std::cout << "| " << this->recuperar_cotacao_minima_acao(it->first)->get_valor() << " " << this->recuperar_cotacao_maxima_acao(it->first)->get_valor() << " " << this->calcular_valor_medio_acao(it->first) << std::endl;
  }
}

