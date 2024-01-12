#include "semaphore.h"

#define verde 10
#define amarelo 6
#define vermelho 2

Semaphore s;
void setup() {
  s = newSemaphore(verde,amarelo,vermelho);
}

void loop() {
  SetSemaphoreState(s, G);
  delay(3000);

  SetSemaphoreState(s, A);
  delay(1000);

  SetSemaphoreState(s, S);
  delay(5000);
}