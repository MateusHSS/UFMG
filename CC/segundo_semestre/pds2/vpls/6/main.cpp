
// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bovespa.hpp"
// #include "Cotacao.hpp"
// #include "HistoricoBovespa.hpp"

int main() {
  
    // NÃO ALTERE ESSA LINHA
    // avaliacao_basica();


    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //
    HistoricoBovespa historico;
    std::string sigla;
    std::string data;
    double valor;

    while(std::cin >> sigla){
        std::cin >> data;
        std::cin >> valor;

        historico.inserir_cotacao(sigla, data, valor);
    }


    // //
    // // Ao final faça uma chamada para o método 'imprimir_estatisticas_completas()'
    // //
    historico.imprimir_estatisticas_completas();

    return 0;
}