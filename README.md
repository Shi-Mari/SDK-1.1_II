# Имитатор гирлянды с переключением режимов <br> 

## Задание

Разработать и реализовать два варианта драйверов UART для стенда SDK-1.1M: с использованием и без использования прерываний. Драйверы, использующие прерывания, должны обеспечивать работу в «неблокирующем» режиме (возврат из функции происходит сразу же, без ожидания окончания приема/отправки), а также буферизацию данных для исключения случайной потери данных. В драйвере, не использующем прерывания, функция приема данных также должна быть «неблокирующей», то есть она не должна зависать до приема данных (которые могут никогда не поступить). При использовании режима «без прерываний» прерывания от соответствующего блока UART должны быть запрещены. Каждый принимаемый стендом символ должен отсылаться обратно, чтобы он был выведен в консоли (так называемое «эхо»). Каждое новое сообщение от стенда должно выводиться с новой строки. Если вариант предусматривает работу с командами, то на каждую команду должен выводиться ответ, определенный в задании или «ОК», если ответ не требуется. Если введена команда, которая не поддерживается, должно быть выведено сообщение об этом.


## Результаты работы

Доработан имитатор гирлянды. Реализована возможность добавления четырёх новых последовательностей миганий светодиодов с индивидуальной настройкой частоты переключения состояний для каждой последовательности. Каждая вводимая последовательность имеет от двух до восьми состояний. Смена отображаемой в определённый момент последовательности осуществляться нажатием кнопки или командой, посылаемой через UART.
Команды  посылаемой через UART:
•	new xx… – ввести новую последовательность, где «x» – это одна из букв g, r, y, n («g» соответствует включению зелѐного светодиода, «r» – красного, «y» – жѐлтого, «n» означает, что ни один светодиод не горит); количество вводимых значений «x» может быть от двух до восьми, ввод завершается либо по нажатию Enter, либо после ввода восьми значений;
•	после окончания ввода последовательности мерцаний стенд послает сообщение, приглашающее ввести частоту мерцаний светодиодов;
•	ввод частоты мерцаний заканчивается по нажатию Enter; новой последовательности присваивается очередной свободный номер от 5 до 8; если уже есть 8 последовательностей, то переопределяется последовательность 5 и т.д.; 
•	set х – сделать активной последовательность мерцаний х, где х – порядковый номер;
•	set interrupts on или set interrupts off – включить или выключить прерывания.
В функции main ([main.c](main.c)), перед основным циклом while(1): 
Настраиваем систему тактирования внешнего тактового генератора;
Настраиваем работу USART;
Настраиваем порт кнопки (тактируем и задаем на вход);
Настраиваем порты светодиодов на выход 5. 
Настраиваем таймеры 2 и 3. 
Таймер 2 используем для переключения светодиодов, таймер 3 – для борьбы с дребезгом кнопки.
Для работы с USART создаем буферы для приема и для передачи – массивы элементов типа char. Когда байт приходит на прием – добавляем в приемный буфер, когда отправляем – добавляем в отправной буфер. По условиям задачи нужно сделать два режима USART – с прерываниями и без. 
Для реализации режима без прерываний в конце каждой итерации вечного цикла вызываем функции для проверки на прием или передачу.
С помощью функции «USART6_StringTX» выводим строку на экран. Если ожидается, что пользователь введёт частоту сравниваем принятое значение с значением в массиве, в котором хранятся номера режимов частоты и устанавливается соответствующая частота мигания. Далее ожидается команда «new» или «set», осуществляется проверка первых трёх введённых символов. Если приходит команда «new», то 8 символов, введённые после new сохраняются в следующий режим после 4, если количество новых режимов больше 4, то следующий введённый режим сохранится в 5тый и так далее. Далее ожидаем команду «set» с прерываниями или без; если приходит команда «set interrupt on», включаем прерывания; если «set interrupt off» – выключаем. Получаем номер режима и устанавливаем соответствующий режим. 
В файле [main.h](main.h)  находятся постоянные для регулирования частоты моргания, вспомогательные переменные и массивы для работы режимов, Драйвер UART и т. д.
В файле [regmap.h](regmap.h) записаны адреса регистров контроллера.
Платформа разработки - CubeIDE, контроллер - STM32F427VI.
