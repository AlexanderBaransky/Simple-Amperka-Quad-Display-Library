// Подключаем библиотеку для работы с дисплеем
#include <SimpleAmperkaQuadDisplay2.h>
// создаём объект класса QuadDisplay и передаём номер пина CS
QuadDisplay qd(9);

void setup()
{
  qd.begin();
}

void loop()
{  // можно выводить целые числа
  qd.displayInt(123);
  delay(2000);

  // и отрицательные тоже
  qd.displayInt(-123);
  delay(2000);

  // можно показывать ведущие нули (0012)
  qd.displayInt(12, true);
  delay(2000);

  // можно показывать вещественные числа
  // с заданной точностью, например 2 знака после запятой
  qd.displayFloat(-1.23, 2);
  delay(2000);

  // можно показывать температуру в °C
  qd.displayTemperatureC(-5);
  delay(2000);
  // можно показывать нехитрый текст (on/off, например) или
  // произвольную графику
  qd.displayDigits(qd_O, qd_f, qd_f, qd_none); // off
  delay(2000);
  qd.displayDigits(qd_O, qd_n, qd_none, qd_none); // on
  delay(2000);
  // и, конечно, всё очищать
  qd.displayClear();
  delay(2000);
}
