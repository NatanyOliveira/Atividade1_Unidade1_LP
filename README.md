# Sistema Bancário Simples em C++

Este projeto é uma implementação de um sistema bancário básico em C++, desenvolvido para demonstrar conceitos fundamentais de **Programação Orientada a Objetos (POO)**.

-----

## Descrição

O sistema simula operações bancárias essenciais, como depósitos, saques e transferências entre contas. Ele é estruturado em duas classes principais: `Cliente` e `ContaBancaria`, que trabalham juntas para gerenciar as informações dos correntistas e suas respectivas finanças.

O objetivo principal é aplicar conceitos como **classes**, **objetos**, **encapsulamento**, **construtores** e **sobrecarga de métodos** em um cenário prático.

-----

## Funcionalidades

  - **Gerenciamento de Clientes:**

      - Criação de clientes com nome e CPF.

  - **Operações de Conta Bancária:**

      - Abertura de contas com saldo inicial (opcional, o padrão é zero).
      - Realizar **depósitos**.
      - Efetuar **saques**, com validação de saldo suficiente.
      - **Transferir** valores para uma única conta de destino.
      - **Transferir** valores com divisão igual para duas contas de destino (sobrecarga de método).
      - Exibir o saldo atual da conta.
      - Exibir um extrato completo com as informações do titular e o saldo.

-----

## Estrutura do Código

O projeto é composto por duas classes principais:

### 1\. `Cliente`

Armazena os dados pessoais do titular da conta.

  - **Atributos:**
      - `string nome`
      - `string cpf`
  - **Métodos:**
      - `getNome()`: Retorna o nome do cliente.
      - `getCpf()`: Retorna o CPF do cliente.

### 2\. `ContaBancaria`

Gerencia os dados e as operações de uma conta bancária.

  - **Atributos:**
      - `int numConta`
      - `double saldo`
      - `Cliente titular` (composição de objetos)
  - **Métodos Principais:**
      - `depositar(double valor)`
      - `sacar(double valor)`
      - `transferir(double valor, ContaBancaria &destino)`
      - `transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2)`
      - `exibirSaldo()`
      - `exibirInformacoes()`

-----

## Exemplo de Saída

A execução do código de exemplo (`main`) produzirá a seguinte saída no console:

```
Saldo atual da conta 1001: R$ 1000
Transferido: R$ 200 da conta 1001 para a conta 1002
Transferido: R$ 150 para cada conta (1002 e 1003) da conta 1001

Titular: Ana, CPF: 111.111.111-11
Número da Conta: 1001, Saldo: R$ 500
Titular: Bruno, CPF: 222.222.222-22
Número da Conta: 1002, Saldo: R$ 350
Titular: Carla, CPF: 333.333.333-33
Número da Conta: 1003, Saldo: R$ 150
```
