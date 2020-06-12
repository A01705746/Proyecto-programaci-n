# Proyecto programación
[![Run on Repl.it](https://repl.it/badge/github/A01705746/Proyecto-programaci-n)](https://repl.it/github/A01705746/Proyecto-programaci-n)

# Programación Orientada a Objetos C++: Resumen

Autor: Enrique Santos Fraire
Matrícula: A01705746

El siguiente programa tiene como propósito simular el comportamiento de un videojuego MMORPG (el cual es Warframe). Se tiene un total de 7 clases para guardar y configurar los datos de las diferentes partes del juego: como son los datos del usuario, de su equipamiento, escuadrón, los enemigos, el juego base y los modos de juego, los cuales por practcidad se limitaron a dos opciones.

# Detalles de entraga:

Se implementó y enfocó la herencia en los modos de juego, incluyendo polimorismo y clases abstractas, las demás clases son composición o agregación y emplean métodos  con apuntadores para modificar parámetros de información que se desplegarán al jugador y que podrá cambiar a voluntad.

# Descripción:

Dentro del programa se desplegará la información del ususrio que entre, aceptando parámetros tanto de un jugador registrado como uno nuevo, se le permitirá agregar amigos y agregar dinero virtual a su cuenta.
Se proyectará un menú general con sub-menús, donde el usuario tendrá la opción de comprar la moneda virtual del juego, agregar amigos y cambiar cada elemento de su equipo, una vez con eso podrá crear un escuadrón, donde podrá agregar o eliminar jugadores adicionales para jugar juntos.
Finalmente podrán elegir entre dos modos de juego.
Exterminio: deberán eleminiar un número específico de enemigos para ganar.
Captura: el fin es buscar y capturar un objetivo antes de que se acabe el tiempo.

# Consideraciones

Utilizar números para elegir las opciones del menu cuando se indica.
Usar letras en los menus generará error y será necesario volver a correr el programa.
El programa solo corre en consola y fue hecho en c++, por lo que debe correr en la mayoría de los sistemas operativos.
