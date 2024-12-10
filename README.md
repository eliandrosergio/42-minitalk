# minitalk

O projeto *minitalk* da Escola 42 tem como objetivo implementar um sistema de comunicação entre dois processos utilizando sinais Unix. O desafio consiste em enviar e receber mensagens entre processos por meio de sinais `SIGUSR1` e `SIGUSR2`.

## Objetivo

O objetivo do projeto é aprender a trabalhar com sinais em Unix, especificamente `SIGUSR1` e `SIGUSR2`, e entender como a comunicação entre processos pode ser feita de forma eficiente e segura.

## Funcionalidades Implementadas

- Envio de mensagens do processo cliente para o processo servidor utilizando sinais.
- O servidor deve ser capaz de receber a mensagem e exibi-la no terminal.
- Implementação de codificação e decodificação de dados utilizando sinais binários (1 para `SIGUSR1` e 0 para `SIGUSR2`).
- O cliente envia a mensagem ao servidor e aguarda a confirmação de recebimento.

## Como Compilar

1. Clone o repositório:
   ```bash
   git clone https://github.com/eliandrosergio/minitalk.git
   cd minitalk
   make
