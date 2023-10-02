#include <IRremote.h>

/*Pin Vars*/
#define PIN_IR 3
#define PIN_DETECT 2
#define PIN_STATUS 13

/*Program Constants*/
#define OK_TO_RESET 5 //arbitrary - can be fine-tuned

IRsend ir_send;

int number_of_marbles;
int sliding_window ;

void setup() {
  /*Init variables*/
  number_of_marbles = 0;
  sliding_window = OK_TO_RESET;

  pinMode(PIN_DETECT, INPUT);
  pinMode(PIN_STATUS, OUTPUT);
  irsend.enableIROut(38);
  irsend.mark(0);
}

void loop() {
  digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT));

  /*I was able to detect a marble, AND its been long enough since I last
    saw a marble to increment again*/
  if (digitalRead(PIN_STATUS) && (sliding_window == OK_TO_RESET)) {
    number_of_marbles++;
    sliding_window = -1; //will be incremented to zero on the same frame
  }

  /*Enables us to not reread marbles on adjacent frames*/
  if (sliding_window < OK_TO_RESET) {
    sliding_window++;
  }
}