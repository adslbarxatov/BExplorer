# BExplorer v 3.1.7
> PCC: 00175768868F6DA0


A tool based on BExplorer API for editing of GTA Vice City save files (`.b`)

Инструмент для редактирования файлов сохранений GTA Vice City (`.b`) на базе собственного API


#

Warning! Tool is not completed yet and may cause unexpected effects in save files.
If you got some, please, remind us about it. And *backup your save files before using this tool*!

Внимание! Инструмент ещё разрабатывается и может вызывать непредвиденные эффекты в файлах
сохранений. Если Вы столкнулись с одним из них, пожалуйста, напишите нам об этом. И обязательно
*делайте резервные копии файлов перед использованием программы*!

&nbsp;



## Usage / Применение

You need to download two files – executable and library. At first start you will also be asked for `carcols.dat` file.
Just specify it in GTA Vice city installation directory and have fun!

#

Вам нужны два файла – приложение и библиотека. При первом запуске также потребуется указать расположение
файла `carcols.dat`. Просто найдите его в папке установки GTA Vice city, и готово!

&nbsp;



## Requirements / Требования

- Windows 7 or newer / или новее;
- [Microsoft .NET Framework 4.8](https://go.microsoft.com/fwlink/?linkid=2088631).
- [Microsoft Visual C++ 2015 – 2022 redistributable](https://aka.ms/vs/17/release/vc_redist.x86.exe).

Interface languages / языки интерфейса: ru_ru, en_us.

&nbsp;



# BExplorer library / API


An API for work with GTA Vice City save files (`.b`)

API для работы с файлами сохранений GTA Vice City

#

Here is a set of header files that represent the structure and parameters of GTA Vice City save file
(as it is known today) and file loading/saving functions that represent the order and processing
features of data blocks. It can be useful for developers that want to create an UI for loading,
editing and saving GTAVCsf.

WARNING! It is strongly recommended to use EXACTLY THESE header files and EXACTLY THESE functions TOGETHER.
Header definitions use direct handling with memory (unsafe mode) (implicitly defined pointers/arrays,
structures and unions) and using them without recommended functions may cause unexpected application behaviour
(of course, if you don’t know what you’re doing).

&nbsp;

Здесь располагается набор заголовочных файлов, представляющих структуру и параметры файла сохранения игры GTA Vice City
(насколько они известны сегодня), а также функции загрузки и сохранения, демонстрирующие алгоритм чтения/записи файла.
Эта страница может быть полезна разработчикам, планирующим создать UI для работы с файлами сохранений GTA.

ВНИМАНИЕ! Настоятельно рекомендуется использовать ИМЕННО ЭТИ заголовочные файлы с ИМЕННО ЭТИМИ функциями. Описанные структуры
работают с памятью напрямую (в небезопасном режиме) (строго заданные указатели, массивы, структуры и объединения). Их использование
вне рекомендованных функций может вызвать непредвиденное поведение программы (конечно, если вы не знаете, что делаете).

&nbsp;

Information source / Источник информации: [gtamodding.com](http://gtamodding.com/wiki/Saves_(GTA_VC))

#



## [Development policy and EULA](https://adslbarxatov.github.io/ADP) / [Политика разработки и EULA](https://adslbarxatov.github.io/ADP/ru)

This Policy (ADP), its positions, conclusion, EULA and application methods
describes general rules that we follow in all of our development processes, released applications and implemented ideas.
***It must be acquainted by participants and users before using any of laboratory’s products.
By downloading them, you agree and accept this Policy!***

Данная Политика (ADP), её положения, заключение, EULA и способы применения
описывают общие правила, которым мы следуем во всех наших процессах разработки, вышедших в релиз приложениях
и реализованных идеях.
***Обязательна к ознакомлению для всех участников и пользователей перед использованием любого из продуктов лаборатории.
Загружая их, вы соглашаетесь и принимаете эту Политику!***
