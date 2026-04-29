#include <stdio.h>
#include <string.h>

typedef struct {
    char usuario[20];
    char contrasena[20];
    float saldo;
} Cuenta;

Cuenta cuentas[] = {
    {"juan",  "1234", 5000.00},
    {"maria", "abcd", 8500.00},
    {"pedro", "pass", 3200.00}
};

int totalUsuarios = 3;

int iniciarSesion(char user[], char pass[]) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(cuentas[i].usuario, user) == 0 &&
            strcmp(cuentas[i].contrasena, pass) == 0) {
            return i;
        }
    }
    return -1;
}

void menuCajero(int indice) {
    int opcion;
    float monto;
    do {
        printf("\n===== CAJERO AUTOMATICO =====\n");
        printf("Bienvenido, %s\n", cuentas[indice].usuario);
        printf("-----------------------------\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Salir\n");
        printf("-----------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("\nSu saldo actual es: $%.2f\n", cuentas[indice].saldo);
                break;
            case 2:
                printf("Ingrese el monto a depositar: $");
                scanf("%f", &monto);
                if (monto > 0) {
                    cuentas[indice].saldo += monto;
                    printf("Deposito exitoso. Nuevo saldo: $%.2f\n", cuentas[indice].saldo);
                } else {
                    printf("Monto invalido.\n");
                }
                break;
            case 3:
                printf("Ingrese el monto a retirar: $");
                scanf("%f", &monto);
                if (monto > 0 && monto <= cuentas[indice].saldo) {
                    cuentas[indice].saldo -= monto;
                    printf("Retiro exitoso. Nuevo saldo: $%.2f\n", cuentas[indice].saldo);
                } else if (monto > cuentas[indice].saldo) {
                    printf("Fondos insuficientes.\n");
                } else {
                    printf("Monto invalido.\n");
                }
                break;
            case 4:
                printf("Gracias por usar el cajero. Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}

int main() {
    char usuario[20];
    char contrasena[20];
    int intentos = 0;
    int indice;
    printf("===== CAJERO AUTOMATICO =====\n");
    printf("Por favor inicie sesion\n");
    while (intentos < 3) {
        printf("\nUsuario: ");
        scanf("%s", usuario);
        printf("Contrasena: ");
        scanf("%s", contrasena);
        indice = iniciarSesion(usuario, contrasena);
        if (indice != -1) {
            menuCajero(indice);
            return 0;
        } else {
            intentos++;
            printf("Credenciales incorrectas. Intentos restantes: %d\n", 3 - intentos);
        }
    }
    printf("\nDemasiados intentos fallidos. Sistema bloqueado.\n");
    return 0;
}