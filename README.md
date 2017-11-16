# BExplorer
An API for work with GTA Vice City save files (.b) / API для работы с файлами сохранений GTA Vice City
#
Here is a set of header files that represent the structure and parameters of GTA Vice City save file (as it is known today) and file loading/saving functions that represent the order and processing features of data blocks. It can be useful for developers that want to create an UI for loading, editing and saving GTAVCsf.

WARNING! It is strongly recommended to use EXACTLY THESE header files and EXACTLY THESE functions TOGETHER. Header definitions use direct handling with memory (unsafe mode) (implicitly defined pointers/arrays, structures and unions) and using them without recommended functions may cause unexpected application behaviour (of course, if you don't know what you're doing).

#

Здесь располагается набор заголовочных файлов, представляющих структуру и параметры файла сохранения игры GTA Vice City
(насколько они известны сегодня), а также функции загрузки и сохранения, демонстрирующие алгоритм чтения/записи файла.
Эта страница может быть полезна разработчикам, планирующим создать UI для работы с файлами сохранений GTA.

ВНИМАНИЕ! Настоятельно рекомендуется использовать ИМЕННО ЭТИ заголовочные файлы с ИМЕННО ЭТИМИ функциями. Описанные структуры
работают с памятью напрямую (в небезопасном режиме) (строго заданные указатели, массивы, структуры и объединения). Их использование
вне рекомендованных функций может вызвать непредвиденное поведение программы (конечно, если вы не знаете, что делаете).

#

Information source / Источник информации: http://www.gtamodding.com/wiki/Saves_(GTA_VC)
