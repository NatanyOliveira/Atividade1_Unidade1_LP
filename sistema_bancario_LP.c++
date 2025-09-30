#include <iostream>
#include <string>
using namespace std;

// Classe Cliente representa os dados básicos de uma pessoa que vai ser titular da conta
class Cliente {
private:
    string nome; // Aqui eu guardo o nome do cliente
    string cpf;  // Aqui eu guardo o CPF do cliente
public:
    // Construtor da classe Cliente: quando eu criar um Cliente, preciso informar o nome e o cpf
    Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}

    // Métodos "getters" (somente leitura) para acessar o nome e o cpf do cliente
    string getNome() const { return nome; }
    string getCpf() const { return cpf; }
};

// Classe ContaBancaria representa uma conta de banco vinculada a um Cliente
class ContaBancaria {
private:
    int numConta;    // Aqui eu guardo o número da conta
    double saldo;    // Aqui eu guardo quanto de dinheiro tem na conta
    Cliente titular; // Aqui eu guardo quem é o dono da conta (um objeto Cliente)
public:
    // Construtor da classe ContaBancaria
    // Eu passo o número da conta, um cliente (titular) e o saldo inicial
    // O "saldoInicial = 0.0" é para permitir criar contas com saldo inicial opcional
    ContaBancaria(int numConta, const Cliente& cli, double saldoInicial = 0.0)
        : numConta(numConta), titular(cli), saldo(saldoInicial) {}

    // Método para realizar depósitos
    // Só deixa depositar valores positivos
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor; // aumenta o saldo da conta
        }
    }

    // Método para realizar saques
    // Aqui eu verifico se o valor é positivo e se tem saldo suficiente
    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor; // diminui o saldo da conta
        }
    }

    // Transferência para uma conta destino
    // Verificação de saldo sem imprimir mensagem de erro
    void transferir(double valor, ContaBancaria &destino) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;//diminui o saldo da conta origem
            destino.depositar(valor);//aumenta o saldo da conta destino
            cout << "Transferido: R$ " << valor 
                 << " da conta " << numConta 
                 << " para a conta " << destino.numConta << endl;
        }
    }

    // Transferência para duas contas destino
    // Verificação de saldo sem imprimir mensagem de erro
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;//diminui o saldo da conta origem
            double metade = valor / 2.0;
            destino1.depositar(metade);//aumenta o saldo da conta destino1
            destino2.depositar(metade);//aumenta o saldo da conta destino2
            cout << "Transferido: R$ " << metade
                 << " para cada conta (" << destino1.numConta
                 << " e " << destino2.numConta
                 << ") da conta " << numConta << endl;
        }
    }

    // Método para mostrar apenas o saldo da conta
    void exibirSaldo() const {
        cout << "Saldo atual da conta " << numConta << ": R$ " << saldo << endl;
    }

    // Método para mostrar todas as informações da conta
    // Aqui eu uso os métodos getNome() e getCpf() da classe Cliente
    void exibirInformacoes() const {
        cout << "Titular: " << titular.getNome()//usando o método getNome() da classe Cliente
             << ", CPF: " << titular.getCpf() << endl;
        cout << "Número da Conta: " << numConta
             << ", Saldo: R$ " << saldo << endl;
    }
};

int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
