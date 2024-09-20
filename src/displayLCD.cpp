#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include "displayLCD.h"
#include "funcoes.h"

LiquidCrystal_I2C lcd(0x27,16,2);

byte customChar1[] = {
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000};

byte customChar2[] = {
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000};

byte customChar3[] = {
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100};

byte customChar4[] = {
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110};

void inicializaLCD()
{
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    lcd.createChar(0, customChar1);
    lcd.createChar(1, customChar2);
    lcd.createChar(2, customChar3);
    lcd.createChar(3, customChar4);
}

void printaSenha(byte coluna, byte linha, int senha)
{
    lcd.setCursor(coluna, linha);
    lcd.print(F("                "));
    lcd.setCursor(coluna, linha);
    lcd.print(F("Senha: "));
    lcd.print(senha);
}


void printaTempo(byte coluna, byte linha, byte tempo)
{
    lcd.setCursor(coluna, linha);
    byte blocospreenchidos = tempo / 5;
    byte blocoparcial = tempo % 5;
    for (byte i = 0; i < blocospreenchidos; i++)
    {
        lcd.write(byte(3));
    }

    if (blocoparcial > 0)
    {
        lcd.write(byte(blocoparcial - 1));
    }
    for(byte i = 0; i < 16 - blocospreenchidos - 1; i++)
    {
        lcd.print(F(" "));
    }
}

void printaSaudacao(String usuario)
{
    lcd.setCursor(0, 0);
    lcd.print(F("ola, "));
    lcd.print(usuario);
    lcd.print(F("!         "));
}
