#include "Arduino.h"
typedef struct Semaphore{
  int green = 0;
  int yellow = 1;
  int red = 10;
};

typedef enum State
  {GO,    ATENCION,   STOP, 
  G,      A,          S,
  GREEN,  YELLOW,     RED};

void newSemaphore(Semaphore s, int color[3]){
  s.green = color[0];
  s.yellow = color[1];
  s.red = color[2];
  for (int i = 0; i < 2; i++) {
    pinMode(color[i], OUTPUT);
  }
}

Semaphore newSemaphore(int green, int yellow, int red){
  Semaphore s;
  s.green = green;
  s.yellow = yellow;
  s.red = red;
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  return s;
}

void SetSemaphoreState(Semaphore s, State mode){
  switch (mode) {
    case STOP:
    case S:
    case RED:
      digitalWrite(s.green, LOW);
      digitalWrite(s.yellow, LOW);
      digitalWrite(s.red, HIGH);
    break;
    case GO:
    case G:
    case GREEN:
      digitalWrite(s.green, HIGH);
      digitalWrite(s.yellow, LOW);
      digitalWrite(s.red, LOW);
    break;
    case ATENCION:
    case A:
    case YELLOW:
      digitalWrite(s.green, LOW);
      digitalWrite(s.yellow, HIGH);
      digitalWrite(s.red, LOW);
    break;
  }
}
