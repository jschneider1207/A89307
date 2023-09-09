#include "A89307.hpp"
#define Serial Serial1

A89307::A89307Chip *chip = new A89307::A89307Chip();
volatile uint8_t outOfSyncBuffer[ADDRESS_COUNT];
void setup()
{
  chip->begin();
  // chip->writeAddressMap();
  volatile uint8_t *pointer = outOfSyncBuffer;
  for (uint8_t i; i < ADDRESS_COUNT; i++)
  {
    (*pointer++) = 0x00;
  }
}

char readCommandToken(const char *tokens, int tokenCount, int defaultToken = -1)
{
  char answer = 0;

  while (answer == 0)
  {
    // Flush input buffer
    while (Serial.available())
      Serial.read();

    while (!Serial.available())
      ;

    char readChar = Serial.read();

    if (defaultToken >= 0 && defaultToken < tokenCount && isSpace(readChar))
    {
      answer = tokens[defaultToken];
      break;
    }

    for (int i = 0; i < tokenCount; i++)
      if (readChar == tokens[i])
        answer = readChar;

    if (answer == 0)
      Serial.print("Invalid character. ");
  }

  return answer;
}

void help(void);
void cycle(void);
void status(void);
void write(void);
void print(void);
void read(void);
void drive(void);

void loop()
{
  Serial.println("Enter a command [h(elp), c(ycle), s(tatus), w(rite), r(ead), p(rint), d(rive)]: ");
  char cmd = readCommandToken("hcswprd", 7, 3);
  switch (cmd)
  {
  case 'h':
    help();
    break;
  case 'c':
    cycle();
    break;
  case 's':
    status();
    break;
  case 'w':
    write();
    break;
  case 'p':
    print();
    break;
  case 'r':
    read();
    break;
  case 'd':
    drive();
    break;
  };
  Serial.println();
}

void help() {}

void cycle()
{
  chip->end();
  DELAY(100);
  chip->begin();
}

void status()
{
  uint8_t *oosList;
  uint8_t count = chip->syncStatus(oosList);
  Serial.print(count);
  Serial.print(" addresses are out of sync: ");
  for (uint8_t i = 0; i < count; i++)
  {
    Serial.print((*oosList++));
    Serial.print(", ");
  }
}

void write()
{
  chip->writeAddressMap();
}

void read()
{
  chip->readAddressMap();
}

void print()
{
  Serial.println("Address map or register values? [a(ddress), r(egister)]: ");
  char cmd = readCommandToken("ar", 2, 1);
  if (cmd == 'a')
  {
    Serial.println("// -----------------------------------------------------------------------------");
    Serial.println("//                         >---- Address map ----<");
    Serial.println("// -----------------------------------------------------------------------------");
    chip->printAddressMap();
  }
  else if (cmd == 'r')
  {
    Serial.println("// -----------------------------------------------------------------------------");
    Serial.println("//                         >---- Registers ----<");
    Serial.println("// -----------------------------------------------------------------------------");
    chip->printRegisters();
  }
}

void drive()
{
  chip->end();
  Serial.println("How fast should the motor be ran? [s(low), m(edium), f(ast)]: ");
  char cmd = readCommandToken("smf", 3, 2);
  uint8_t percent = 0;
  switch (cmd)
  {
  case 's':
    percent = 50;
    break;
  case 'm':
    percent = 75;
    break;
  case 'f':
    percent = 100;
    break;
  }
  analogWrite(SCL_PIN, map(percent, 0, 100, 0x00, 0xFF));
  delay(15000);
  pinMode(SCL_PIN, INPUT);
  chip->begin();
}