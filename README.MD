# Cajero Automático Digital

## Descripción
Sistema que simula el funcionamiento básico de un cajero automático, 
desarrollado en lenguaje C. Permite gestionar cuentas de usuarios 
previamente registrados con autenticación segura.

## Funcionalidades
- Inicio de sesión con usuario y contraseña
- Bloqueo tras 3 intentos fallidos
- Consultar saldo disponible
- Depositar dinero
- Retirar dinero con validación de fondos
- Menú interactivo en consola

## Usuarios de prueba
| Usuario | Contraseña | Saldo inicial |
|---------|-----------|---------------|
| juan    | 1234      | $5000.00      |
| maria   | abcd      | $8500.00      |
| pedro   | pass      | $3200.00      |

## Instrucciones para compilar
Asegúrese de tener instalado GCC. Luego ejecute:## Instrucciones para ejecutar
En Windows (Git Bash):## Mejoras implementadas
- **Límite de intentos:** El sistema bloquea al usuario tras 3 intentos fallidos de inicio de sesión, mejorando la seguridad.
- **Validación de montos:** No se permiten depósitos ni retiros de montos negativos o en cero.
- **Mensajes claros:** El sistema informa al usuario el resultado de cada operación con el saldo actualizado.