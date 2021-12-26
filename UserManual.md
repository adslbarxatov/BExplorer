# BExplorer 2.19: user manual

[*Русская версия*](https://github.com/adslbarxatov/BExplorer/blob/master/UserManual.md#bexplorer-219-руководство-пользователя)

**BExplorer** – a set of API descriptions and a tool that supports basic operations of reading and editing of save settings of GTA Vice City.

***The application is under development now. Therefore, some parameters during usage of this application are edited by user at own risk. It is recommended that you back up your save files before using this tool.***


# 1. Launch and file opening

When the program starts, the «File» tab is displayed. By pressing the «Open file...» button, user can select the save file for editing. Upon successful opening, the name of save (corresponding to name of the last completed mission) will be displayed in the middle of the tab.

At the end of all changes, you must save the file using the appropriate button («Save to file...»). All changes that will not be «confirmed» with this button will be lost when the program is closed. The corresponding warning is displayed when you click the «Exit» button.

The «Reset potentially hazardous parameters» button will be described later. Before reading its description, it is not recommended to touch it.


# 2. Parameters changing

## 2.1. Basic parameters

Here user can change (from top to bottom):
- Date and time recorded in the save (if necessary); valid values are from 01/01/1980 to 12/31/2080);
- Duration of the minute in the game in milliseconds (it can be convenient if the days and nights seem too long or short; valid values are from 100 to 60’000);
- Game speed multiplier (unlike the previous parameter, this one affects the entire game, not just the clock; valid values are from 10 to 0.1);
- Current weather (the environment in the game will change to this weather during the next gaming hour from the start; the same weather will remain until the completion of any mission);
- Location of the camera relative to the car (there is a similar parameter for the player, but it doesn’t work in the game);
- State of the radio wave of taxi drivers (this wave is switched on by game after completing all missions in the taxi park. But it can be turned on earlier, although it is hardly necessary.

## 2.2. Player’s parameters

Here you can change (from top to bottom):
- Maximum level of health (increases by the game when passing the «Pizza deliverer» mission and when completing all the missions; valid values are from 100 to 200);
- Maximum level of armor (increases by the game when completing the «Vigilante» mission and when completing all missions); valid values are from 100 to 200);
- Current level of armor (manually set in the range from 0 to 900; maybe more, but have not yet been tested – usually enough);
- Maximum level of police interest (values are from 0 to 6; rises by the game as it progresses; if the value is zero, the player can perform any action with impunity – maniac mode);
- Account status (values are from $0 to $99’000’000; for honest players it’s suitable if you want to leave your cash, but start the game from beginning);
- Suit / skin of the player (values from the list);
- The mode of perpetual running (player stops getting tired of running when completing an «Ambulance» mission; you can turn it on earlier).

Flags:
- Fireproof mode (player ceases to receive damage from burning when passing the «Firefighter» mission; you can turn it on earlier);
- Fast reload mode (set by the game when completing «The shootist» mission; you can turn it on earlier);
- Infinite ammo (ammo ceases to decrease when player passes all the missions; you can turn it on earlier, but it’s better to turn it off to restore realism).

Three fields below:
- Type of weapon and ammo. Here you must select the weapon’s slot that should be changed, and then set its type and ammo. Please note that the game will ignore attempts to put the weapon not in its slot (for example, a baseball bat can be put only in weapon slot 2). The assigned slots can be viewed in the weapon.dat file in the last column.

The ammo is limited to 12’000 (anything greater than 10’000 is displayed as a void under the weapon’s icon). For slots 1 (fist), 2 (cold steel / striking weapon) and 10 (special equipment), the value is ignored.

## 2.3. Garages

In this tab you can configure cars stored in garages purchased by the player along with the property. At the same time, the application orientates them in all garages while saving the file so that their use is as convenient as possible. Settings can be entered or changed even before buying a property: when it is purchased, cars will automatically appear in the specified garages.

Before setting up a garage, you need to select it in the list at the top of the tab. Then you can specify:
- Auto model (the value «нет» («no») indicates an empty space in the garage; technically it allows putting boats, helicopters and airplane into the garage);
- Primary and secondary color of the car (tool takes colors from carcols.dat file, so it is important to use the same file that is in the folder where game is installed);
- Radio wave (allows you to turn the radio on or off in the car; in some cases, you can turn on the police wave);
- Set fire resistance (it is impossible to set fire or catch fire), protection against bullets (shots will not cause damage), protection against damage (there will be no dents and broken glasses), protection against explosions (the car will not catch fire from an explosion nearby); from coup, unfortunately, there is no protection in principle.
- Bomb type (only time bomb for 10 seconds and acceleration bomb are available).

Parameters can be saved to a file and transferred to another save file if necessary. In addition, current colors of the car are displayed on the right side of the tab.

## 2.4. Pickups

For now this tab only allows you to change the limits of cash accumulators that appear at completion of missions related to purchased property. Accumulators themselves become available as you progress through these missions; at the beginning of the game, none of them can be changed.

To find out which accumulator is currently selected, you can use «Where is it» button. The maximum amount is $50’000.

## 2.5. Gangsters

Having previously selected the necessary gang, on this tab you can change:
- Model of car that the gang will use (or forbid them to use «their» cars);
- Skins (appearance) of gangsters (a pair of values from which the game randomly selects a skin for each generated gangster when meeting him);
- Weapons (also a pair of values; it allows, among other things, to disarm the gang or make it «self-destructive» by handing, for example, Molotov cocktails).

## 2.6. Car parks

This tab allows you to configure cars, boats, helicopters and airplanes placed around the city. These parameters can be replaced with recommended ones (see Crazy cheater’s mod) or chosen independently using the «Download parameters» and «Save parameters» buttons.

It is recommended to uncheck the «Cancel sorting by type» checkbox only when the program has finished adding vehicles after missions. If the flag is unchecked, cars in the parking list will be sorted by model when saving the file. However, technically nothing prevents you from unchecking it with every save.

After choosing the number of parking place, you can change:
- Car model (including the option «random»);
- Coordinates and rotation of the parking space (you can specify coordinates and rotation on the city map using the «Specify coordinates» button);
- Primary and secondary colors (the value «–1» corresponds to random color from list of allowed colors for this model in carcols.dat);
- Probability of an alarm (from 0 to 100%);
- Probability of blocking the car (when the doors will not open even after the explosion; value from 0 to 100%);
- Accessibility of the place (when unchecked, car will not be generated);
- The «constancy» of the place (when unchecked, car will be generated intermittently).

## 2.7. Stats

On this tab, you can download achievements from another save, as well as upload and see your achievements in text form. Also in the list below are available all actions that must be completed in order to complete the game 100%.


# 3. Resetting of potentially hazardous parameters

This function allows you to remove all elements that may lead to crashes when further modding the game on this save or long permanent use of this save. For now, we have found out that these elements include port cranes and objects that replace other objects after some missions (for example, an exploded cafe in the north mall instead of a normal one).

This operation is recommended to be performed only after the full passage of the game. Otherwise, the consequences are difficult to predict. In addition, this manipulation guarantees an unhindered (probably) change of number and / or type of objects on the maps. Other types of modding should be checked in practice.


# 4. Other functions and abilities

Header files developed for this application technically supports a lot of manipulations (besides those described above) with save files. They are available for use by developers who want to expand the functionality of this or own tools. In any case, we will be glad to receive wishes and suggestions from all who care. Thanks!



#

# BExplorer 2.19: руководство пользователя

**BExplorer** – набор API-описаний и инструмент, поддерживающий основные операции чтения и редактирования параметров сохранений игры GTA Vice City.

***Программа находится в разработке. Поэтому часть параметров при использовании данного приложения редактируется пользователем на свой страх и риск. Рекомендуется делать резервные копии файлов сохранений перед использованием данной программы.***


# 1. Запуск и открытие файла

При запуске программы отображается вкладка «Файл». По нажатию кнопки «Открыть файл...» пользователь может выбрать нужное сохранение для редактирования. При успешном открытии в середине вкладки отобразится название сохранения, соответствующее названию последней выполненной миссии.

По окончании всех изменений необходимо сохранить файл с помощью соответствующей кнопки. Все изменения, которые не будут «закреплены» этой кнопкой, будут утеряны при закрытии программы; соответствующее предупреждение отображается при нажатии кнопки «Выход».

Кнопка «сброс потенциально опасных параметров» будет описана далее. До прочтения её описания трогать её не рекомендуется.


# 2. Изменение параметров

## 2.1. Базовые параметры

Здесь пользователь может изменить:
- Дату и время, записанные в сохранении (если в этом есть необходимость; допустимы значения от 01.01.1980 до 31.12.2080);
- Длительность минуты в игре в миллисекундах (может быть удобно, если дни и ночи кажутся слишком длинными или короткими; значения от 100 до 60’000);
- Множитель скорости игры (в отличие от предыдущего параметра влияет на всю игру, а не только на часы; значения от 10 до 0,1);
- Погоду (на эту погоду будет меняться окружение в игре при старте в течение следующего игрового часа; на этой же погоде оно останется до завершения любой миссии);
- Расположение камеры относительно автомобиля (есть аналогичный параметр для игрока, но он не работает в самой игре);
- Состояние радиоволны таксистов (эта волна включается игрой в такси после завершения всех миссий в таксопарке; но её можно включить раньше, хотя вряд ли в этом есть необходимость).

## 2.2. Параметры игрока

Здесь можно изменить:
- Максимальный уровень здоровья (увеличивается игрой при прохождении миссии доставщика пиццы и при прохождении всех миссий; значения от 100 до 200);
- Максимальный уровень брони (увеличивается игрой при прохождении миссии Vigilante и при прохождении всех миссий; значения от 100 до 200);
- Текущий уровень брони (выставляется вручную в диапазоне от 0 до 900; возможно, можно больше, но пока не проверяли – обычно и так хватает);
- Максимальный уровень интереса полиции (значения от 0 до 6; поднимается игрой по мере прохождения; при нулевом значении игрок может безнаказанно совершать любые действия – режим маньяка);
- Состояние счёта (значения от 0 до 99’000’000$; для честных игроков подойдёт при желании оставить свои наличные, но начать игру заново);
- Костюм / скин игрока (значения из списка);
- Режим вечного бега (игрок перестаёт уставать от бега при прохождении миссии скорой помощи; можно включить раньше);
- Режим несгораемости (игрок перестаёт получать урон от горения при прохождении миссии пожарного; можно включить раньше);
- Режим быстрой перезарядки (выставляется игрой при прохождении миссии стрелка в тире; можно включить раньше);
- Бесконечные патроны (патроны перестают уменьшаться, когда игрок проходит все миссии; можно включить раньше, но лучше выключить, чтобы вернуть реалистичность);
- Тип оружия и патроны.

В последнем случае необходимо сначала выбрать номер оружия, которое следует изменить, а затем выставить его тип и количество патронов. Обращаем внимание, что игра будет игнорировать попытки поставить оружие не в свой слот (например, дубинку можно поставить только в оружие №2). Назначенные слоты можно посмотреть в файле weapon.dat в самом крайнем столбце.

Число патронов ограничено значением 12’000 (всё, что больше 10’000, отображается как пустота под значком оружия). Для слотов 1 (кулак / костет), 2 (холодное оружие / ударное оружие) и 10 (спецсредства) значение игнорируется.

## 2.3. Гаражи

В этой вкладке настраиваются авто, хранящиеся в гаражах, приобретённых игроком вместе с имуществом. При этом программа сама ориентирует их во всех гаражах при сохранении файла таким образом, чтобы их использование было максимально удобным. Настройки могут быть введены или изменены даже до покупки недвижимости: когда она будет приобретена, авто автоматически появятся в заданных гаражах.

Перед настройкой гаража нужно выбрать его в списке в самом верху вкладки. Далее можно установить:
- Модель авто (значение «нет» указывает на пустое место в гараже; технически позволяет ставить в гараж лодки, вертолёты и самолёт);
- Основной и дополнительный цвет авто (программа берёт цвета из файла carcols.dat, поэтому важно использовать тот же файл, что находится в папке, где установлена игра);
- Радиоволна (позволяет включить или выключить радио в авто; в некоторых случаях можно включить полицейскую волну);
- Установить несгораемость (нельзя поджечь или загореться от пожара), защиту от пуль (выстрелы не будут наносить урон), защиту от повреждений (не будет вмятин и разбитых стёкол), защиту от взрывов (машина не загорится от взрыва рядом); от переворота, к сожалению, защиты нет в принципе;
- Установить бомбу (работоспособными оказались только два варианта – часовая бомба на 10 секунд и разгонная);

Параметры можно сохранить в файл и перенести в другой файл сохранения при необходимости. Кроме того, текущая расцветка авто отображается в правой части вкладки.

## 2.4. Pickups

На данный момент эта вкладка позволяет только изменять ограничения денежных накопителей, которые появляются при завершении миссий, связанных с недвижимостью. Сами накопители становятся доступны по мере прохождения этих миссий; в начале игры ни один из них нельзя будет изменить.

Чтобы узнать, какой именно накопитель сейчас выбран, можно воспользоваться кнопкой «Где это». Максимальный размер накопителя 50’000$.

## 2.5. Гангстеры

Предварительно выбрав нужную банду, на этой вкладке можно изменить:
- Модель авто, которую будет использовать банда (или запретить ей использовать «свои» автомобили);
- Скины (внешний вид) гангстеров (пара значений, из которых игра случайным образом выбирает скин для каждого генерируемого гангстера при встрече с ним);
- Оружие (так же пара значений; позволяет, в том числе, обезоружить банду или сделать её «самоуничтожаемой», вручив ей, например, коктейли Молотова).

## 2.6. Парковки

Эта вкладка позволяет настроить авто, лодки, вертолёты и самолёты, расставленные по городу. Эти параметры можно заменить рекомендуемыми (см. Crazy cheater’s mod) или выбранными самостоятельно, используя кнопки «Загрузить» и «Сохранить».

Флажок «Отменить сортировку по типам» рекомендуется снимать лишь тогда, когда программа закончила добавлять транспорт после миссий. При снятом флажке авто в списке парковок будут отсортированы по моделям при сохранении файла. Впрочем, технически ничто не мешает снимать его при каждом сохранении.

Выбрав номер парковочного места, можно изменить:
- Модель авто (в то числе доступен вариант «случайная»);
- Координаты и поворот парковочного места (можно указать координаты и поворот на карте города, используя кнопку «Указать координаты»);
- Основной и дополнительный цвета (значение «–1» соответствует произвольному цвету из допустимых для данной модели авто в файле carcols.dat);
- Вероятность срабатывания сигнализации (от 0 до 100%);
- Вероятность блокировки авто (когда двери не будут открываться даже после взрыва; значение от 0 до 100%);
- Доступность места (при снятом флажке авто не будет генерироваться);
- Постоянность места (при снятом флажке авто будет генерироваться непостоянно).

## 2.7. Статистика

На этой вкладке можно загрузить достижения из другого сохранения, а также выгрузить и посмотреть в текстовом виде свои достижения. Также в списке ниже доступны все действия, которые необходимо выполнить, чтобы пройти игру на 100% процентов.


# 3. Сброс потенциально опасных параметров

Данная функция позволяет убрать из файла сохранения все элементы, которые могут привести к сбоям при дальнейшем моддинге игры на данном сохранении или долгом постоянном использовании этого сохранения. На данный момент мы выяснили, что к таким объектам относятся краны в порту и объекты, заменяющие другие объекты после некоторых миссий (например, взорванное кафе в торговом центре вместо нормального).
Эту операцию рекомендуется выполнять только после полного прохождения игры; в противном случае последствия сложно предугадать. Кроме того, эта манипуляция гарантирует беспрепятственное (вероятно) изменение количества и/или типа объектов на картах. Остальные виды моддинга следует проверять на практике.


# 4. Прочие функции и возможности

Заголовочные файлы, разработанные для данной программы, технически поддерживают множество манипуляций (помимо описанных выше) с файлами сохранений. Они доступны для использования разработчиками, желающими расширить функционал этой или своей программы. В любом случае, будем рады пожеланиям и предложениям от всех неравнодушных. Спасибо!
