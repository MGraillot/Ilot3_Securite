#include <Arduino.h>

// Définir les broches des capteurs et du bouton
const int sensorPin1 = 12; // Capteur 1 (analogique)
const int sensorPin2 = 14; // Capteur 2 (analogique)
const int sensorPin3 = 26; // Capteur 3 (analogique)
const int sensorPin4 = 27; // Capteur 4 (analogique)
const int buttonPin = 28;  // Bouton pour redémarrer le robot

// Seuil de distance pour activer la barrière (en mm)
const int SensorDistance = 300;

// Variables pour stocker les valeurs des capteurs
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;

// Variable pour déterminer si le robot est arrêté
bool robotStopped = false;
// Fonctions pour contrôler le robot

void initializeRobot()
{
  // Initialiser le mouvement du robot
  // Ajouter un bout de code pour faire des mouvements au robot
}

void stopRobot()
{
  // Arrêter le robot
  Serial.println("Robot arrêté");
}

void startRobot()
{
  // Redémarrer le robot a l'aide d'un bouton
  Serial.println("Robot redémarré");
}

void randomMove()
{
  // Implémenter les mouvements aléatoires du robot
  Serial.println("Robot en mouvement");
}
void setup()
{
  Serial.begin(115200);
  // Initialiser les broches des capteurs et du bouton
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);


}

void loop()
{
  // Lire les valeurs des capteurs
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);

  // Afficher les valeurs pour le débogage
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);
  Serial.print(" | Sensor 2: ");
  Serial.print(sensorValue2);
  Serial.print(" | Sensor 3: ");
  Serial.print(sensorValue3);
  Serial.print(" | Sensor 4: ");
  Serial.println(sensorValue4);
  delay(1000);
  // Vérifier si un capteur dépasse le seuil
  if (sensorValue1 < SensorDistance || sensorValue2 < SensorDistance ||
      sensorValue3 < SensorDistance || sensorValue4 < SensorDistance)
  {
    stopRobot(); // Arrêter le robot
    robotStopped = true;
  }

  // Vérifier si le bouton est pressé pour redémarrer le robot
  if (robotStopped && digitalRead(buttonPin) == LOW)
  {
    delay(200);   // Attendre pour éviter les rebonds du bouton
    startRobot(); // Redémarrer le robot
    robotStopped = false;
  }

  // Si le robot n'est pas arrêté, le faire bouger de manière aléatoire
  if (!robotStopped)
  {
    randomMove();
  }

  delay(100); // Délai pour réduire la fréquence de lecture des capteurs
}

