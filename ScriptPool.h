// INCOMPLETED //

union SD_ScriptPool
	{
	struct SC_Formatted
		{
		ulong SC_ScriptsCount;	// Количество скриптов
		} SC;

	uchar SC_Raw [sizeof (struct SC_Formatted)];
	};

union SD_ScriptStructure
	{
	struct SS_Formatted
		{
		ulong SS_PointerToPrevScript;	// Указатель на предыдущий скрипт
		ulong SS_PointerToNextScript;	// Указатель на следующий скрипт
		uchar SS_ScriptName[8];			// Название скрипта
		ulong SS_CurrentInstructionPointer;	// Указатель на выполняемую команду
		ulong SS_ReturnStack[4];		// Стэк результатов
		ulong SS_Unknown1[2];			// ???
		ulong SS_StackCounter;			// Счётчик стека
		ulong SS_LocalVariables[16];	// Локальные переменные
		ulong SS_TimerA;				// Таймеры скриптов
		ulong SS_TimerB;
		uchar SS_IsActive;				// Скрипт активен
		uchar SS_IfStatementResult;		// Результат выполнения выражения If
		uchar SS_MissionCleanup;		// Сброс перед выполнением миссии
		uchar SS_SkipWakeTime;			// ???
		ulong SS_WakeTime;				// Время приостановки работы скрипта, мс
		uint SS_IfCheckResult;			// Результат проверки выражения If
		uchar SS_NotFlag;				// Флаг "не"
		uchar SS_DeathArrestState;		// Арест или смерть во время миссии
		uchar SS_DeathArrestExecuted;	// Тест на арест или смерть
		uchar SS_MissionFlag;			// Флаг миссии
		uchar SS_Unknown2[2];			// ???
		} SS;

	uchar SS_Raw[1];
	};
