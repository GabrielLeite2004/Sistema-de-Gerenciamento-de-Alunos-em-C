# Sistema de Gerenciamento de Alunos em C

## Descrição
Este projeto em C implementa um sistema básico de gerenciamento de alunos. O sistema permite cadastrar, editar, deletar, ordenar e pesquisar alunos, além de salvar e carregar os dados em um arquivo de texto. 

## Funcionalidades
- **Cadastrar Aluno**: Adiciona um novo aluno ao sistema com uma matrícula e nome.
- **Editar Aluno**: Permite a edição do nome de um aluno existente com base na matrícula.
- **Deletar Aluno**: Remove um aluno do sistema com base na matrícula.
- **Ordenar Alunos**: Ordena os alunos pelo número sequencial.
- **Pesquisar Aluno**: Pesquisa um aluno pelo número de matrícula.
- **Salvar Dados**: Salva os dados dos alunos em um arquivo de texto.
- **Carregar Dados**: Carrega os dados dos alunos a partir de um arquivo de texto.

## Como Usar
1. Compile o código utilizando um compilador C. Exemplo:
   ```bash
   gcc -o sistema_alunos sistema_alunos.c
   ```
2. Execute o programa:
   ```bash
   ./sistema_alunos
   ```
3. Siga as instruções no menu para gerenciar os alunos no sistema.

## Estrutura de Dados
O projeto utiliza uma estrutura `Aluno` para representar cada aluno. Cada aluno contém:
- **sequencial**: Número sequencial do aluno.
- **matricula**: Número de matrícula do aluno.
- **nome**: Nome completo do aluno.

## Persistência de Dados
Os dados dos alunos são salvos em um arquivo de texto chamado `alunos.txt`. Quando o programa é iniciado, ele carrega os dados salvos automaticamente, se o arquivo estiver presente.

## Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).
