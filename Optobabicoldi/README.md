# Juego-Basico

Algunas ideas básicas de la clase de Juego

El loop de Juego tiene la siguente estructura:

1. Procesar los inputs (Entradas de teclado por ejemplo)
2. Actualizar la información del juego (Ejemplo: posición de personaje, detectar y procesar coliciones, etc)
3. Generar algún output (Aquí se muestran los dibujos en pantalla)

La "Game" class tiene tres métodos principales(de atributo público):
void Initialize() // Inicia el juego, crea la ventana
void RunLoop()   // El método donde se encuentra el loop principal del juego (dentro se usan tres métodos privados)
void ShutDown() //Cierra la ventana

Dentro del RunLoop() se define:

void Game::RunLoop()
{
    while(!WindowShouldClose())
    {
        ProcessInput();     //Procesar los inputs
        UpdateGame();      //Actualizar la información de juego
        GenerateOutput();  //Cierre la ventana 
    }
}
<<<<<<< HEAD
=======

>>>>>>> 76e330fbcc7c138cae2a8d380d76d6ceab71008a
