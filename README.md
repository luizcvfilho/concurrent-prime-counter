# Lab4 - Programação Concorrente

Este repositório contém dois arquivos `.c` desenvolvidos para o laboratório 4 da disciplina de Programação Concorrente.

## Arquivos

1. **concurrent-prime.c**:
Recebe dois valores N e T como argumento no momento da execução. O programa então fará a contagem de quantos números primos existem até o número N, de maneira concorrente, utilizando T threads desejadas.

2. **sequential-prime.c**:
Recebe um valor como argumento no momento da execução. O programa então fará a contagem de quantos números primos existem até o número N, de maneira sequencial.

## Como Compilar

Para compilar os arquivos, utilize o `gcc` no terminal. Execute os seguintes comandos:

```bash
gcc -o concurrent-prime.exe concurrent-prime.c -Wall -lm
gcc -o sequential-prime.exe sequential-prime.c -Wall -lm
```

## Como Executar

Após a compilação, execute os programas com os comandos abaixo:

### Executar `concurrent-prime.c`

N = número limite para verificações de primos
T = número de threads a serem usadas  

```bash
./concurrent-prime N T
```

### Executar `produto-interno-concorrente.c`

N = número limite para verificações de primos

```bash
./sequential-prime N
```

## Performance Results (N = 1 000)

| Threads (p) | Tempo Tₚ (s)  | Speedup Sₚ = Sequencial/Tₚ | Efficiency Eₚ = Sₚ/p |
|------------:|--------------:|-------------------:|--------------------:|
| Sequencial  | 0.000021      | 1.00               | 1.00                |
| 1           | 0.000026      |                    |                     |
| 2           | 0.000637      | 0.03               | 0.02                |
| 3           | 0.000575      | 0.04               | 0.01                |
| 4           | 0.000898      | 0.02               | 0.01                |
| 5           | 0.000471      | 0.04               | 0.01                |
| 6           | 0.001366      | 0.02               | 0.00                |
| 7           | 0.000636      | 0.03               | 0.00                |
| 8           | 0.001193      | 0.02               | 0.00                |
| 9           | 0.000762      | 0.03               | 0.00                |
| 10          | 0.001936      | 0.01               | 0.00                |
| 11          | 0.001686      | 0.01               | 0.00                |
| 12          | 0.001601      | 0.01               | 0.00                |
| 13          | 0.001483      | 0.01               | 0.00                |
| 14          | 0.001693      | 0.01               | 0.00                |
| 15          | 0.001560      | 0.01               | 0.00                |

## Performance Results (N = 1 000 000)

| Threads (p) | Tempo Tₚ (s) | Speedup Sₚ = Sequencial/Tₚ  | Efficiency Eₚ = Sₚ/p |
|------------:|-------------:|-------------------:|--------------------:|
| Sequencial  | 0.094638      | 1.00               | 1.00                |
| 1           | 0.098045      |                    |                     |
| 2           | 0.169421      | 0.56               | 0.28                |
| 3           | 0.279692      | 0.34               | 0.11                |
| 4           | 0.372934      | 0.25               | 0.06                |
| 5           | 0.532404      | 0.18               | 0.04                |
| 6           | 0.610206      | 0.16               | 0.03                |
| 7           | 0.779780      | 0.12               | 0.02                |
| 8           | 0.838867      | 0.11               | 0.01                |
| 9           | 0.955696      | 0.10               | 0.01                |
| 10          | 0.996636      | 0.09               | 0.01                |
| 11          | 1.040942      | 0.09               | 0.01                |
| 12          | 1.060042      | 0.09               | 0.01                |
| 13          | 1.051120      | 0.09               | 0.01                |
| 14          | 1.077494      | 0.09               | 0.01                |
| 15          | 1.111125      | 0.09               | 0.01                |

## Conclusão

Através da análise das tabelas acima, é possível perceber que para esse problema, quanto maior o número de threadhs, maior o tempo de execução. Isso se dá por causa do mutex que usamos, que acaba impedindo o trabalho simultâneo das threads em alguns momentos, fazendo com que o custo de tempo para criar elas seja pior do que o tempo que elas economizam realizando as tarefas de maneira simultânea.
