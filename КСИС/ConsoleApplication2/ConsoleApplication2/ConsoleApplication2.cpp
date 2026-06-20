#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display ( OLED_RESET );

void setup ( )
{
	display.begin ( SSD1306_SWITCHCAPVCC, 0x3C ); //
	display.clearDisplay ( ); // Очищаем дисплей
}

void loop ( )
{
	display.setTextSize ( 2 ); // Устанавливаем размер шрифта
	display.setTextColor ( WHITE ); // Цвет Шрифта
	display.setCursor ( 0, 0 ); // Положение курсора
	display.println ( "Hello" ); // Вывод сообщения на дисплей
	display.display ( );
	display.clearDisplay ( );
}