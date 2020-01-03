// Отключение предупреждений
#define _CRT_SECURE_NO_WARNINGS

// Подключение общего заголовка
#include "Headers/B_explorer.h"

// Функция, отвечающая за вывод сообщений об ошибках. Возвращает код ошибки
// • Error - любой поддерживаемый код ошибки
char *SaveData_ErrorPrompt (int Error)
	{
	// Переменные
	static char msg[SD_MaxStrSize];
	char msg1[SD_MaxStrSize];

	// Построение сообщения
	switch (Error)
		{
		// Новые ошибки
		case SD_FIXED:
			sprintf (msg1, "Корректировка выполнена успешно");
			break;

		case SD_LOAD_SUCCESS:
			sprintf (msg1, "Файл успешно загружен");
			break;

		case SD_SAVE_SUCCESS:
			sprintf (msg1, "Файл успешно сохранён");
			break;

		// Ошибки в командах
		case SD_INTRPR_ERR_ValueOutOfRange:
			sprintf (msg1, "Указанное значение находится вне допустимого диапазона");
			break;

		case SD_INTRPR_ERR_ModeIsIncorrect:
			sprintf (msg1, "Недопустимый код режима");
			break;

		case SD_INTRPR_ERR_OpCodeIsIncorrect:
			sprintf (msg1, "Недопустимый код операции для данного режима");
			break;

		case SD_INTRPR_ERR_ParCodeIsIncorrect:
			sprintf (msg1, "Недопустимый код параметра для данных режима и операции");
			break;

		// Ошибки в файлах обмена
		case SD_INTRPR_ERR_StatsFileNotFound:
			sprintf (msg1, "Указанный файл статистики недоступен");
			break;

		case SD_INTRPR_ERR_StatsFileIsIncorrect:
			sprintf (msg1, "Указанный файл повреждён или не является файлом статистики");
			break;

		case SD_INTRPR_ERR_CannotCreateStatsFile:
			sprintf (msg1, "Не удаётся записать файл статистики");
			break;

		case SD_INTRPR_ERR_CGFileNotFound:
			sprintf (msg1, "Указанный файл параметров парковок недоступен");
			break;

		case SD_INTRPR_ERR_CGFileIsIncorrect:
			sprintf (msg1, "Указанный файл повреждён или не является файлом параметров парковок");
			break;

		case SD_INTRPR_ERR_CannotCreateCGFile:
			sprintf (msg1, "Не удаётся записать файл параметров парковок");
			break;

		case SD_INTRPR_ERR_GaragesFileNotFound:
			sprintf (msg1, "Указанный файл параметров гаражей недоступен");
			break;

		case SD_INTRPR_ERR_GaragesFileIsIncorrect:
			sprintf (msg1, "Указанный файл повреждён или не является файлом параметров гаражей");
			break;

		case SD_INTRPR_ERR_CannotCreateGaragesFile:
			sprintf (msg1, "Не удаётся записать файл параметров гаражей");
			break;

		// Ошибки сохранения и загрузки
		case SD_SAVE_ERR_CannotCreateFile:
			sprintf (msg1, "Не удаётся создать заданный файл. Возможно, выбранное расположение или файл недоступны для записи");
			break;

		case SD_INTRPR_ERR_FileNotLoaded:
			sprintf (msg1, "Файл сохранения не был загружен (структура пуста)");
			break;

		// Ошибки загрузки
		case SD_LOAD_ERR_FileNotFound:
			sprintf (msg1, "Указанный файл отсутствует или недоступен");
			break;

		case SD_LOAD_ERR_MemoryAllocationFailure:
			sprintf (msg1, "Не удаётся выделить память для хранения данных программы");
			break;

		case SD_LOAD_ERR_LoadDP:
		case SD_LOAD_ERR_LoadSB:
		case SD_LOAD_ERR_LoadSBA:
		case SD_LOAD_ERR_LoadSBB:
		case SD_LOAD_ERR_LoadSC:
		case SD_LOAD_ERR_LoadSS:
		case SD_LOAD_ERR_LoadPPL:
		case SD_LOAD_ERR_LoadGR:
		case SD_LOAD_ERR_LoadVS:
		case SD_LOAD_ERR_LoadSR:
		case SD_LOAD_ERR_LoadTS:
		case SD_LOAD_ERR_LoadPH:
		case SD_LOAD_ERR_LoadPHD:
		case SD_LOAD_ERR_LoadOP:
		case SD_LOAD_ERR_LoadOS:
		case SD_LOAD_ERR_LoadCR:
		case SD_LOAD_ERR_LoadPU:
		case SD_LOAD_ERR_LoadPI:
		case SD_LOAD_ERR_LoadRL:
		case SD_LOAD_ERR_LoadRB:
		case SD_LOAD_ERR_LoadZB:
		case SD_LOAD_ERR_LoadGD:
		case SD_LOAD_ERR_LoadCG:
		case SD_LOAD_ERR_LoadPR:
		case SD_LOAD_ERR_LoadPRD:
		case SD_LOAD_ERR_LoadAU:
		case SD_LOAD_ERR_LoadAS:
		case SD_LOAD_ERR_LoadSP:
		case SD_LOAD_ERR_LoadPL:
		case SD_LOAD_ERR_LoadST:
		case SD_LOAD_ERR_LoadTZ:
		case SD_LOAD_ERR_LoadPT:
		case SD_LOAD_ERR_LoadCS:
			sprintf (msg1, "Неожиданный конец файла или ошибка чтения при загрузке ");

			switch (Error)
				{
				case SD_LOAD_ERR_LoadDP:
					sprintf (msg1, "%sобщих параметров сохранения", msg1);
					break;

				case SD_LOAD_ERR_LoadSB:
					sprintf (msg1, "%sблока общих параметров массива переменных", msg1);
					break;

				case SD_LOAD_ERR_LoadSBA:
					sprintf (msg1, "%sмассива переменных", msg1);
					break;

				case SD_LOAD_ERR_LoadSBB:
					sprintf (msg1, "%sпродолжения блока переменных", msg1);
					break;

				case SD_LOAD_ERR_LoadSC:
					sprintf (msg1, "%sобщих параметров массива скриптов", msg1);
					break;

				case SD_LOAD_ERR_LoadSS:
					sprintf (msg1, "%sмассива скриптов", msg1);
					break;

				case SD_LOAD_ERR_LoadPPL:
					sprintf (msg1, "%sобщих параметров массива игроков", msg1);
					break;

				case SD_LOAD_ERR_LoadPPS:
					sprintf (msg1, "%sмассива игроков", msg1);
					break;

				case SD_LOAD_ERR_LoadGR:
					sprintf (msg1, "%sблока описателей гаражей", msg1);
					break;

				case SD_LOAD_ERR_LoadVS:
					sprintf (msg1, "%sобщих параметров массива транспортных средств", msg1);
					break;

				case SD_LOAD_ERR_LoadVH:
					sprintf (msg1, "%sмассива транспортных средств", msg1);
					break;

				case SD_LOAD_ERR_LoadSR:
					sprintf (msg1, "%sблока стримминга", msg1);
					break;

				case SD_LOAD_ERR_LoadTS:
					sprintf (msg1, "%sблока описателей точек создания такси", msg1);
					break;

				case SD_LOAD_ERR_LoadPH:
					sprintf (msg1, "%sобщих параметров массива трасс", msg1);
					break;

				case SD_LOAD_ERR_LoadPHD:
					sprintf (msg1, "%sмассива трасс", msg1);
					break;

				case SD_LOAD_ERR_LoadOP:
					sprintf (msg1, "%sобщих параметров массива скрипт-контролируемых объектов", msg1);
					break;

				case SD_LOAD_ERR_LoadOS:
					sprintf (msg1, "%sмассива скрипт-контролируемых объектов", msg1);
					break;

				case SD_LOAD_ERR_LoadCR:
					sprintf (msg1, "%sблока портовых кранов", msg1);
					break;

				case SD_LOAD_ERR_LoadPU:
					sprintf (msg1, "%sблока собираемых объектов", msg1);
					break;

				case SD_LOAD_ERR_LoadPI:
					sprintf (msg1, "%sблока телефонов-автоматов", msg1);
					break;

				case SD_LOAD_ERR_LoadRL:
					sprintf (msg1, "%sблока зон респауна", msg1);
					break;

				case SD_LOAD_ERR_LoadRB:
					sprintf (msg1, "%sблока радарных указателей", msg1);
					break;

				case SD_LOAD_ERR_LoadZB:
					sprintf (msg1, "%sблока зон карты", msg1);
					break;

				case SD_LOAD_ERR_LoadGD:
					sprintf (msg1, "%sблока банд", msg1);
					break;

				case SD_LOAD_ERR_LoadCG:
					sprintf (msg1, "%sблока парковок", msg1);
					break;

				case SD_LOAD_ERR_LoadPR:
					sprintf (msg1, "%sобщих параметров массива эффектов анимации", msg1);
					break;

				case SD_LOAD_ERR_LoadPRD:
					sprintf (msg1, "%sмассива эффектов анимации", msg1);
					break;

				case SD_LOAD_ERR_LoadAU:
					sprintf (msg1, "%sобщих параметров массива аудиоскриптов", msg1);
					break;

				case SD_LOAD_ERR_LoadAS:
					sprintf (msg1, "%sмассива аудиоскриптов", msg1);
					break;

				case SD_LOAD_ERR_LoadSP:
					sprintf (msg1, "%sблока параметров пути перемещения спецобъектов", msg1);
					break;

				case SD_LOAD_ERR_LoadPL:
					sprintf (msg1, "%sблока информации о текущем игроке", msg1);
					break;

				case SD_LOAD_ERR_LoadST:
					sprintf (msg1, "%sблока статистики игры", msg1);
					break;

				case SD_LOAD_ERR_LoadTZ:
					sprintf (msg1, "%sблока триггер-зон", msg1);
					break;

				case SD_LOAD_ERR_LoadPT:
					sprintf (msg1, "%sблока типов персонажей", msg1);
					break;

				case SD_LOAD_ERR_LoadCS:
					sprintf (msg1, "%sблока контрольной суммы или её сравнении", msg1);
					break;
				}
			break;

		// Неизвестные ошибки (по идее, таких быть не должно)
		default:
			sprintf (msg1, "Неопознанная ошибка в процессе обработки файла сохранения");
			break;
		}

	// Возврат сформированного сообщения
	if (Error >= 0)
		{
		sprintf (msg, "> %s", msg1);
		}
	else
		{
		sprintf (msg, "\x13 %s", msg1);
		}
	return msg;
	}
