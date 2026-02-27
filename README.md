# 📇 Gerenciador de Contatos Simples em C

**👥 Integrantes**
* Rafael Farias – 2510314
* Cauã Felype – 2510189
* Gabryel Rodrigues – 2510200
* Roger Prado – 2512516

Projeto prático desenvolvido para o Ciclo 1 da disciplina de Laboratório de Programação do curso de Engenharia de Software da **UniEVANGÉLICA** (2026/1).

**Orientador:** Prof. Renato Luan de Sousa Araújo

---

## 🎯 Objetivos
O sistema tem como objetivo aplicar e consolidar fundamentos da linguagem C, incluindo:
- Modularização e estruturação de pastas (`src` e `include`).
- Manipulação de memória com ponteiros (passagem por referência).
- Uso e tratamento de strings (`<string.h>`).
- Implementação de algoritmos recursivos.
- **[EXTRA]** Persistência simples de dados em arquivo de texto.

## ⚙️ Funcionalidades
- **Cadastrar:** Adiciona novos contatos (Nome, Telefone, E-mail).
- **Listar:** Exibe todos os contatos salvos na memória.
- **Buscar:** Localiza contatos por nome usando busca parcial (`strstr`).
- **Editar e Excluir:** Modifica ou remove registros realocando os índices do array.
- **Estatísticas (Recursiva):** Calcula quantos contatos possuem um domínio de e-mail específico (ex: `@gmail.com`) percorrendo o array recursivamente.
- **💾 Salvar e Carregar (Persistência):** Os contatos são salvos automaticamente em um arquivo `contatos.txt` ao sair do programa e recarregados ao iniciar.

## 🚀 Como Compilar e Executar

Este projeto utiliza uma arquitetura separando cabeçalhos (`.h`) e códigos-fonte (`.c`). Para compilar corretamente, utilize um compilador C padrão (como o GCC).

1. Clone o repositório ou baixe os arquivos.
2. Abra o terminal na pasta raiz do projeto.
3. Execute o comando de compilação apontando para as pastas corretas:

```bash
gcc src/main.c src/contatos.c -I include -o gerenciador

Execute o programa gerado:

Windows: .\gerenciador.exe

Linux/Mac: ./gerenciador

Nota: O arquivo contatos.txt será criado automaticamente na raiz do projeto após a primeira execução e encerramento correto do programa através da opção "7. Sair".
