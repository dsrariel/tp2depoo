# Trabalho Prático 1 - Sistema de Controle Bancário
Universidade Federal de Minas Gerais, maio de 2018 </br>
Engenharia de Controle e Automação </br>
Ariel de Souza Ribeiro - http://github.com/arieldsr </br>
João Pedro Temponi de Andrade - http://github.com/JhonnyTA </br>

## Tarefa
  Implemente um conjunto de classes para um sistema de controle bancário. 
  Um Banco necessita manter informações sobre seus clientes e contas. 
  Por simplificação do trabalho, não existirá uma classe Agência e uma Conta pertencerá a 
  um único Cliente (não existe conta conjunta). Para isso, foi feito o seguinte projeto (em UML):

<img src="https://i.imgur.com/HXK3e0k.png" alt="Diagrama UML do Sistema de Controle Bancário"/>

### Classe Cliente:
<ul>
  <li> Atributos: nomeCliente (string), cpf_cnpj (string), endereço (string) e fone (string).
  Todos com acesso privado; </li>
  <li> Método construtor para inicializar todos os atributos através de parâmetros;
  <li> Métodos get e set para obter e modificar cada um dos valores dos atributos.
</ul>

### Classe Movimentação:
<ul>
  <li> Atributos: dataMov (sugiro usar a classe GregorianCalendar para programadores
  Java; em C++, o programador está livre para criar sua própria classe que
  manipula Datas ou usar alguma já existente na biblioteca padrão), descrição
  (string), débitoCrédito (char) e valor (double). Todos com acesso privado; </li>
  </li><li> Método construtor para inicializar os atributos descrição, débitoCrédito e valor
  através de parâmetros e dataMov com a data corrente do sistema;
  </li><li> Métodos get para obter cada um dos valores dos atributos. </li>
</ul>

### Classe Conta:
<ul>
  <li> Atributos: numConta (int), saldo (double), cliente (Cliente), movimentações (lista
  de Movimentação) e próximoNumConta (int). O atributo próximoNumConta deve
  ser estático e será usado para armazenar o próximo número de conta. A lista de
  movimentações deve ser implementada usando alguma classe que manipula
  containers, tais como Listas ou Vetores Dinâmicos (Vector). Todos com acesso
  privado;
  </li><li> Método construtor para gerar o número da conta, inicializar o saldo com valor
  zero e o cliente com um valor passado como parâmetro;
  </li><li> Métodos get para obter os valores dos atributos;
  </li><li> Método para debitar um valor da conta. Parâmetros: o valor a ser debitado e a
  descrição da movimentação. Deve adicionar um objeto de movimentação à lista
  de movimentações da conta com as seguintes informações: dataMov obtida do
  sistema, descrição passada como parâmetro, débitoCrédito com valor “D” e valor
  passado como parâmetro. O atributo saldo deve ser decrementado pelo valor do
  débito. Se o saldo se tornar negativo, a operação não deve ser efetuada;
  </li><li> Método para creditar um valor à conta. Parâmetros: o valor a ser creditado e a
  descrição da movimentação. Deve adicionar um objeto de movimentação à lista
  de movimentações da conta com as seguintes informações: dataMov obtida do
  sistema, descrição passada como parâmetro, débitoCrédito com valor “C” e valor
  passado como parâmetro. O atributo saldo deve ser incrementado pelo valor do
  crédito;
  </li><li> Método para obter um extrato da conta. Parâmetros: a data inicial e a data final.
  Deve retornar uma lista contendo todas as movimentações da conta no período
  entre a data inicial e a data final, inclusive;
  </li><li> Método para obter um extrato da conta. Parâmetros: a data inicial. Deve retornar
  uma lista contendo todas as movimentações da conta no período entre a data
  inicial e a data corrente, inclusive;
  </li><li> Método para obter um extrato da conta. Deve retornar uma lista contendo todas
  as movimentações da conta no mês corrente.</li>
</ul>

### Classe Banco:
<ul>
  <li> Atributos: nomeBanco (String), clientes (lista de Clientes) e contas (lista de
  Contas). As listas devem ser implementadas usando alguma classe que
  manipula containers, tais como Listas ou Vetores Dinâmicos (Vector). Todos com
  acesso privado;
  </li><li> Método construtor para inicializar o atributo nomeBanco com um valor passado
  como parâmetro;
  </li><li> Método para inserir um novo cliente na lista de clientes. Parâmetro: o cliente;
  </li><li> Método para criar uma nova conta. Parâmetro: o cliente. A conta criada deve ser
  adicionada à lista de contas do Banco;
  </li><li> Método para excluir um cliente da lista de clientes. Parâmetro: o CPF ou CNPJ
  do cliente. O cliente não pode ser excluído se possuir alguma conta;
  </li><li> Método para excluir uma conta da lista de contas. Parâmetro: o número da
  conta;
  </li><li> Método para efetuar depósito em uma conta. Parâmetros: o número da conta e o
  valor a depositar. Gera uma movimentação de crédito com a descrição
  “Depósito”;
  </li><li> Método para efetuar um saque em uma conta. Parâmetros: o número da conta e
  o valor a sacar. Gera uma movimentação de débito com a descrição “Saque”;
  </li><li> Método para efetuar uma transferência entre contas. Parâmetros: o número da
  conta de origem, o número da conta de destino e o valor a transferir. Gera uma
  movimentação de débito na conta de origem com a descrição “Transferência
  para conta ‘número da conta de destino’” e uma movimentação de crédito na
  conta de destino com a descrição “Transferência da conta ‘número da conta de
  origem’”. Decrementa o saldo da conta de origem e incrementa o saldo da conta
  de destino;
  </li><li> Método para cobrar tarifa. Debita R$15,00 do saldo de todas as contas do
  Banco. Gera uma movimentação de débito em cada conta com a descrição
  “Cobrança de tarifa”;
  </li><li> Método para cobrar CPMF. Debita, de todas as contas, 0,38% do valor total das
  movimentações de débito nos últimos 7 dias. Gera uma movimentação de débito
  em cada conta com a descrição “Cobrança de CPMF”;
  </li><li> Método para obter o saldo de uma conta. Parâmetro: o número da conta;
  </li><li> Método para obter o extrato de uma conta. Parâmetro: o número da conta.
  Obtém o extrato para o mês corrente;
  </li><li> Método para obter o extrato de uma conta. Parâmetros: o número da conta e a
  data inicial. Obtém o extrato a partir da data inicial até a data corrente;
  </li><li> Método para obter o extrato de uma conta. Parâmetros: o número da conta, a
  data inicial e a data final. Obtém o extrato para o período entre a data inicial e a
  data final, inclusive;
  </li><li> Método para obter a lista de clientes;
  </li><li> Método para obter a lista de contas;
  </li><li> Método para gravar os dados em arquivo;
  </li><li> Método para ler os dados armazenados em arquivo.</li>
</ul>

### Classe Interface:
<ul>
  <li> Método para apresentar um menu (interface de caracteres) com opções para:
  cadastrar um novo cliente, criar uma nova conta, excluir um cliente, excluir uma
  conta, efetuar depósito, efetuar saque, efetuar transferência entre contas, cobrar
  tarifa, cobrar CPMF, obter saldo, obter extrato, listar clientes, listar contas e sair
  do programa;
  </li><li> Método para cadastrar um novo cliente. Deve permitir que o usuário entre com
  os dados do cliente a ser inserido;
  </li><li> Método para criar uma nova conta. Deve permitir que o usuário escolha o cliente
  para a conta;
  </li><li> Método para excluir um cliente. Deve permitir que o usuário escolha o cliente a
  ser excluído;
  </li><li> Método para excluir uma conta. Deve permitir que o usuário escolha a conta a
  ser excluída;
  </li><li> Método para efetuar um depósito. Deve permitir que o usuário escolha a conta e
  o entre com o valor a depositar;
  </li><li> Método para efetuar um saque. Deve permitir que o usuário escolha a conta e o
  entre com o valor a sacar;
  </li><li> Método para efetuar uma transferência. Deve permitir que o usuário escolha a
  conta de origem, a conta de destino e o entre com o valor a transferir;
  </li><li> Método para cobrar tarifa. Na prática, este método seria chamado
  automaticamente uma vez por mês em uma data específica. No trabalho, ele
  poderá ser acionado a qualquer momento;
  </li><li> Método para cobrar CPMF. Na prática, este método seria chamado
  automaticamente uma vez por semana em uma data específica. No trabalho, ele
  poderá ser acionado a qualquer momento;
  </li><li> Método para obter saldo. Deve permitir que o usuário escolha a conta. O saldo
  deve ser exibido na tela;
  </li><li> Método para obter extrato. Deve ter opções para que o usuário escolha entre
  extrato do mês, extrato a partir de uma data ou extrato em um período específico
  e, dependendo da escolha, entre com os dados necessários. Todas as
  informações do extrato (data da movimentação, descrição, débito/crédito e valor)
  devem ser listadas e, no final, o saldo atual deve ser exibido;
  </li><li> Método para listar todos os clientes. Deve listar os dados de todos os clientes;
  </li><li> Método para listar todas as contas. Deve listar os dados de todas as contas;
  </li><li> Método main para ler os dados armazenados em arquivo, apresentar o menu
  principal e, antes de sair do programa, gravar os dados em arquivo. </li>
</ul>
