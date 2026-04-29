/*
 * CAJERO AUTOMATICO DIGITAL
 * Desarrollado en lenguaje C
 * Autor: Gabriel Suero
 * Descripcion: Sistema que simula un cajero automatico
 * con autenticacion de usuarios y operaciones bancarias basicas.
 */

#include <stdio.h>
#include <string.h>

/* Estructura que representa la cuenta de cada usuario */
typedef struct {
    char usuario[20];
    char contrasena[20];
    float saldo;
} Cuenta;

/* Usuarios registrados con sus saldos iniciales */
Cuenta cuentas[] = {
    {"juan",  "1234", 5000.00},
    {"maria", "abcd", 8500.00},
    {"pedro", "pass", 3200.00}
};

/* Total de usuarios en el sistema */
int totalUsuarios = 3;

/*
 * Funcion: iniciarSesion
 * Descripcion: Verifica si el usuario y contrasena son correctos
 * Parametros: user (nombre de usuario), pass (contrasena)
 * Retorna: indice del usuario si existe, -1 si no existe
 */
int iniciarSesion(char user[], char pass[]) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(cuentas[i].usuario, user) == 0 &&
            strcmp(cuentas[i].contrasena, pass) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Funcion: menuCajero
 * Descripcion: Muestra el menu principal y ejecuta las operaciones
 * Parametros: indice del usuario autenticado
 */
void menuCajero(int indice) {
    int opcion;
    float monto;

    do {
        /* Mostrar menu de opciones */
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
                /* Mostrar saldo actual */
                printf("\nSu saldo actual es: $%.2f\n", cuentas[indice].saldo);
                break;

            case 2:
                /* Depositar dinero en la cuenta */
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
                /* Retirar dinero verificando fondos suficientes */
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

/*
 * Funcion: main
 * Descripcion: Punto de entrada del programa
 * Solicita credenciales y permite hasta 3 intentos de inicio de sesion
 */
int main() {
    char usuario[20];
    char contrasena[20];
    int intentos = 0;
    int indice;

    printf("===== CAJERO AUTOMATICO =====\n");
    printf("Por favor inicie sesion\n");

    /* Permitir hasta 3 intentos de inicio de sesion */
    while (intentos < 3) {
        printf("\nUsuario: ");
        scanf("%s", usuario);
        printf("Contrasena: ");
        scanf("%s", contrasena);

        indice = iniciarSesion(usuario, contrasena);

        if (indice != -1) {
            /* Credenciales correctas, acceder al menu */
            menuCajero(indice);
            return 0;
        } else {
            intentos++;
            printf("Credenciales incorrectas. Intentos restantes: %d\n", 3 - intentos);
        }
    }

    /* Bloquear sistema tras 3 intentos fallidos */
    printf("\nDemasiados intentos fallidos. Sistema bloqueado.\n");
    return 0;
}