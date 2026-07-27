#include <Modulino.h>

//COMPONENTES PRINCIPALES
ModulinoThermo thermo;
ModulinoDistance distance;
ModulinoKnob knob;
ModulinoButtons botones; 
ModulinoPixels pixels;
ModulinoBuzzer buzzer;

const int DISTANCIA_MINIMA = 150;      //Distancia mínima fija
const float UMBRAL_ALARMA_TEMP = 10.0; // Temperatura máxima fija

// Variables de control de los botones
bool sonidoSilenciado = false;   //True -> no suena
bool sistemaApagado = false;     //True -> apagan LEDs y no suena nada

void setup() {
  //Inicializa comunicación y módulos
  Serial.begin(9600);
  
  Modulino.begin();
  thermo.begin();
  distance.begin();
  knob.begin();
  botones.begin();       
  pixels.begin();
  buzzer.begin();
  
  // Apagar LEDs al inicio
  for (int i = 0; i < 8; i++) pixels.set(i, 0, 0, 0); 
  pixels.show();
  
  //Mensaje de inicio
  Serial.println("SISTEMA CON TERMÓMETRO DE LEDS INICIADO");
}

void loop() {
  // 1. ACTUALIZAR BOTONES
  botones.update();

  if (botones.isPressed(0)) { sonidoSilenciado = true; Serial.println("-> Silenciado por A"); }
  if (botones.isPressed(1)) { sistemaApagado = true; Serial.println("-> Apagado por B"); }
  if (botones.isPressed(2)) { sonidoSilenciado = false; sistemaApagado = false; Serial.println("-> Reset por C"); }

  // 2. LECTURA DE SENSORES (leen la temperatura 10 veces y se hace un promedio)
  float tempSuma = 0;
  for (int i=0; i < 10; i++) {
    tempSuma += thermo.getTemperature();
    delay(2); 
  }
  float tempActual = tempSuma / 10.0;
  
  int distActual = 0;
  if (distance.available()) {
    distActual = distance.get();
  }

  // 3. EVALUAR PELIGROS. CONDICIONES
  bool peligroTemperatura = (tempActual > UMBRAL_ALARMA_TEMP);
  bool peligroDistancia = (distActual > 0 && distActual < DISTANCIA_MINIMA); 
  bool condicionPeligro = peligroTemperatura || peligroDistancia; //si se cumplen una de las dos

  // 4. CONTROL DEL ZUMBADOR (BUZZER)
  if (!sistemaApagado && condicionPeligro && !sonidoSilenciado) {
    buzzer.tone(1200, 100); //suena
  } else {
    buzzer.noTone();
  }

  // 5. CONTROL DE LOS LEDS
  if (!sistemaApagado) {
    
    // Limita temperatura entre 20 y 40, se asocia un rango a cada LED 
    // constrain asegura que si baja de 20 o sube de 40, el código no se vuelva loco
    float tempLimitada = constrain(tempActual, 20.0, 40.0);
    int ledsAEncender = map(tempLimitada, 20, 40, 1, 8);

    // Definimos el color  de la barra: Verde si es seguro, Rojo si superó los 30°C
    int r = 0, g = 0, b = 0;
    if (peligroTemperatura) {
      r = 255; g = 0;   b = 0;   // ROJO (Peligro)
    } else {
      r = 0;   g = 255; b = 0;   // VERDE (Seguro)
    }

    // Dibujamos la barra en el Modulino Pixels
    for (int i = 0; i < 8; i++) {
      if (i < ledsAEncender) {
        pixels.set(i, r, g, b);  // Enciende los LEDs que correspondan con el color asignado
      } else {
        pixels.set(i, 0, 0, 0);  // Apaga el resto de LEDs de la barra
      }
    }
    pixels.show();

  } else {
    // Si el sistema está apagado por el Botón B, LEDs a negro absoluto
    for (int i = 0; i < 8; i++) pixels.set(i, 0, 0, 0); 
    pixels.show();
  }

  // 6. MONITOR SERIE
  Serial.println("=========================================");
  Serial.print("MEDICIONES -> Temp: "); Serial.print(tempActual);
  Serial.print(" C | Dist: "); Serial.print(distActual); Serial.println(" mm");
  
  Serial.print("UMBRALES   -> Alarma Temp: "); Serial.print(UMBRAL_ALARMA_TEMP);
  Serial.print(" C | Min Dist: "); Serial.print(DISTANCIA_MINIMA); Serial.println(" mm");

  Serial.print("ESTADO     -> ");
  if (sistemaApagado) {
    Serial.println("[SISTEMA APAGADO POR B]");
  } else {
    if (peligroTemperatura) Serial.print("[ALERTA TEMPERATURA] ");
    if (peligroDistancia) Serial.print("[ALERTA DISTANCIA] ");
    
    if (!condicionPeligro) {
      Serial.println("[TODO SEGURO]");
    } else {
      if (sonidoSilenciado) Serial.println("- SILENCIADA POR A");
      else Serial.println("- ¡¡SONANDO!!");
    }
  }
  Serial.println("=========================================");
  Serial.println(); 

  delay(150); 
}