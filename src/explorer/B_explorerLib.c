// Отключение предупреждений
#define _CRT_SECURE_NO_WARNINGS

// Подключение общего заголовка
#include "Headers/B_explorer.h"

// Общая переменная для внутреннего хранения структуры
struct SaveData SD;

// Оболочка функции загрузки файла сохранения
extern __declspec(dllexport) __int16 SaveData_LoadEx (char *FilePath)
	{
	return SaveData_Load (FilePath, &SD);
	}

// Оболочка функции обработки команд
extern __declspec(dllexport) char* SaveData_CommandInterpreterEx (uint Mode, uint OpCode, uint ParCode, char* Value)
	{
	return SaveData_CommandInterpreter (&SD, Mode, OpCode, ParCode, Value);
	}

// Оболочка функции сообщений об ошибках
extern __declspec(dllexport) char* SaveData_ErrorPromptEx (__int16 ErrorCode)
	{
	return SaveData_ErrorPrompt (ErrorCode);
	}

// Метод запроса краткого описания сохранения
extern __declspec(dllexport) char* SaveData_GetSaveInfoEx (void)
	{
	static char info[SD_MaxStrSize];
	int i;

	for (i = 0; i < sizeof (SD.SD_DP.DP.DP_SaveName) / 2; i++)
		{
		info[i] = (char)SD.SD_DP.DP.DP_SaveName[i];
		}
	info[i] = '\0';

	sprintf (info, "%s (%u.%02u.%04u; %u:%02u)", info, SD.SD_DP.DP.DP_Day, SD.SD_DP.DP.DP_Month, SD.SD_DP.DP.DP_Year,
		SD.SD_DP.DP.DP_Hour, SD.SD_DP.DP.DP_Minute);

	return info;
	}

// Метод запроса ToDo-статуса сохранения
extern __declspec(dllexport) char* SaveData_GetToDoStatusEx (void)
	{
	static char status[SD_MaxStrSize];
	char flags1[SD_MaxStrSize],
		outofs1[SD_MaxStrSize],
		flags2[SD_MaxStrSize];

	// Контроль параметров
	if (SD.SD_DP.DP.DP_BlockSize == 0)
		return NULL;

	// Флаги, готовые к отправке
	sprintf (flags1, "%lu%lu%lu%lu%lu%lu%lu%lu%lu%lu%lu%lu",
		SD.SD_SBA[270].SBA_Variable[0],		// Main missions flag
		SD.SD_SBA[373].SBA_Variable[0],		// Taxi mission flag
		SD.SD_SBA[389].SBA_Variable[0],		// Pizza boy mission flag
		SD.SD_SBA[363].SBA_Variable[0],		// Trial by dirt mission flag
		SD.SD_SBA[364].SBA_Variable[0],		// Test track mission flag
		SD.SD_SBA[108].SBA_Variable[0],		// Shooting range mission flag
		SD.SD_SBA[7854].SBA_Variable[0],	// Cherry popper asset flag
		SD.SD_SBA[1096].SBA_Variable[0],	// Pole position asset flag
		SD.SD_SBA[51].SBA_Variable[0],		// Sunshine export 1 flag
		SD.SD_SBA[52].SBA_Variable[0],		// Sunshine export 2 flag
		SD.SD_SBA[53].SBA_Variable[0],		// Sunshine export 3 flag
		SD.SD_SBA[54].SBA_Variable[0]);		// Sunshine export 4 flag

	// Диапазонные значения
	sprintf (outofs1, "%lu%lu%2lu%lu%2lu%lu%2lu%lu%2lu%lu%3lu%lu",
		(ulong)SD.SD_ST.ST.ST_ToDoAsassinationContractsDone, 5,
		SD.SD_ST.ST.ST_ToDoOwnedPropertyCount, 15,
		SD.SD_ST.ST.ST_ToDoRampagesPassed, SD.SD_ST.ST.ST_RampagesCount,
		(ulong)SD.SD_ST.ST.ST_ToDoStoresKnockedOff, 15,
		SD.SD_ST.ST.ST_ToDoUniqueJumpsPassed, SD.SD_ST.ST.ST_UniqueJumpsCount,
		SD.SD_PL.PL.PL_CollectedHiddenPackages, SD.SD_PL.PL.PL_HiddenPackagesCount);

	// Флаги, требующие подготовки
	flags2[0] = (SD.SD_ST.ST.ST_ToDoCheckpointCharlieRecord > 0) ? '1' : '0';
	flags2[1] = (SD.SD_ST.ST.ST_ToDoConeCrazyRecord > 0) ? '1' : '0';
	flags2[2] = (SD.SD_ST.ST.ST_ToDoDirtringRecord > 0) ? '1' : '0';
	flags2[3] = (SD.SD_ST.ST.ST_ToDoDowntownChopperRecord > 0) ? '1' : '0';
	flags2[4] = (SD.SD_ST.ST.ST_ToDoHighestAmbulanceLevel >= 12) ? '1' : '0';
	flags2[5] = (SD.SD_ST.ST.ST_ToDoHighestFirefighterLevel >= 12) ? '1' : '0';
	flags2[6] = (SD.SD_ST.ST.ST_ToDoHighestVigilanteLevel >= 12) ? '1' : '0';
	flags2[7] = (SD.SD_ST.ST.ST_ToDoHotringRecord > 0) ? '1' : '0';
	flags2[8] = (SD.SD_ST.ST.ST_ToDoLittleHaitiChopperRecord > 0) ? '1' : '0';
	flags2[9] = (SD.SD_ST.ST.ST_ToDoLongestTimeInBlooding > 0) ? '1' : '0';
	flags2[10] = (SD.SD_ST.ST.ST_ToDoOceanBeachChopperRecord > 0) ? '1' : '0';
	flags2[11] = (SD.SD_ST.ST.ST_ToDoPCJPlaygroundRecord > 0) ? '1' : '0';
	flags2[12] = (SD.SD_ST.ST.ST_ToDoRCCarRecord > 0) ? '1' : '0';
	flags2[13] = (SD.SD_ST.ST.ST_ToDoRCHelicopterRecord > 0) ? '1' : '0';
	flags2[14] = (SD.SD_ST.ST.ST_ToDoRCPlaneRecord > 0) ? '1' : '0';
	flags2[15] = (SD.SD_ST.ST.ST_ToDoSunshineTrack1Record > 0) ? '1' : '0';
	flags2[16] = (SD.SD_ST.ST.ST_ToDoSunshineTrack2Record > 0) ? '1' : '0';
	flags2[17] = (SD.SD_ST.ST.ST_ToDoSunshineTrack3Record > 0) ? '1' : '0';
	flags2[18] = (SD.SD_ST.ST.ST_ToDoSunshineTrack4Record > 0) ? '1' : '0';
	flags2[19] = (SD.SD_ST.ST.ST_ToDoSunshineTrack5Record > 0) ? '1' : '0';
	flags2[20] = (SD.SD_ST.ST.ST_ToDoSunshineTrack6Record > 0) ? '1' : '0';
	flags2[21] = (SD.SD_ST.ST.ST_ToDoVicePointChopperRecord > 0) ? '1' : '0';
	flags2[22] = '\0';

	// Сборка и возврат
	sprintf (status, "%s%s%s", flags1, flags2, outofs1);
	return status;
	}

// Метод запроса ключа версии библиотеки
extern __declspec(dllexport) char* SaveData_GetLibVersionKeyEx (void)
	{
	static char key[] = "\x03\x01|\x18.\x10.\x16";
	
	return key;
	}
