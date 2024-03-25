#include <stdio.h>

int validarCPF(char *cpf) {
    int numeros[11], soma = 0, digito;

    for (int i = 0; i < 11; i++) {
        numeros[i] = cpf[i] - '0';
        soma += i < 9 ? numeros[i] * (10 - i) : 0;
    }

    digito = soma % 11;
    numeros[9] = (digito < 2) ? 0 : 11 - digito;

    soma = 0;

    for (int i = 0; i < 10; i++) {
        soma += numeros[i] * (11 - i);
    }

    digito = soma % 11;
    numeros[10] = (digito < 2) ? 0 : 11 - digito;

    return (numeros[9] == cpf[9] - '0' && numeros[10] == cpf[10] - '0');
}

int main() {
    char cpf1[] = "27653892094";
    char cpf2[] = "12345678901";

    printf("CPF %s eh %s.\n", cpf1, validarCPF(cpf1) ? "valido" : "invalido");
    printf("CPF %s eh %s.\n", cpf2, validarCPF(cpf2) ? "valido" : "invalido");

    return 0;
}
