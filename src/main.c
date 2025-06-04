#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../include/calculator.h"

int main(int argc, char argv[]) {
    double result = 0.0;

    if (argc == 4) {
        // Opérations binaires : add, sub, mul, div
        const char op = argv[1];
        double a = atof(argv[2]);
        double b = atof(argv[3]);

        if (strcmp(op, "add") == 0) {
            result = _add(a, b);
        } else if (strcmp(op, "sub") == 0) {
            result = _sub(a, b);
        } else if (strcmp(op, "mul") == 0) {
            result = _mul(a, b);
        } else if (strcmp(op, "div") == 0) {
            if (b == 0) {
                printf("Erreur : division par zéro.\n");
                return 1;
            }
            result = _div(a, b);
        } else {
            printf("Erreur : opération binaire inconnue.\n");
            return 1;
        }

        printf("%lf\n", result);
        return 0;
    }

    if (argc == 3) {
        // Opérations unaires : car
        const char* op = argv[1];
        double a = atof(argv[2]);

        if (strcmp(op, "car") == 0) {
            result = car(a);
            printf("%lf\n", result);
            return 0;
        } else {
            printf("Erreur : opération unaire inconnue.\n");
            return 1;
        }
    }

    // Mauvais nombre d'arguments
    printf("Usage : ./calculator <operation> <a> [b]\n");
    printf("Opérations disponibles : add, sub, mul, div, car\n");
    return 1;
}




