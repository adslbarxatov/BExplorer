union SD_ScriptBlock
	{
	struct SB_Formatted
		{
		ulong SB_ScriptBlockSize;		// Размер блока
		uchar SB_BlockName[4];			// Название блока (SCR)
		ulong SB_ScriptSubBlockSize;	// Размер субблока
		ulong SB_ASubblockSize;			// Размер субблока А
		} SB;

	uchar SB_Raw [sizeof (struct SB_Formatted)];
	};

union SD_ScriptBlockAUnit
	{
	ulong SBA_Variable[1];			// Одна переменная из блока переменных

	uchar SBA_Variable_Raw[1];
	};

#define SD_SBB_R_Count		25
#define SD_SBB_IO_Count		20

union SD_ScriptBlockB
	{
	struct SBB_Formatted
		{
		ulong SBB_BSubblockSize;			// Размер субблока Б
		ulong SBB_OnMissionFlagAddress;		// Адрес флага нахождения в миссии
		slong SBB_LastMissionPassTimeMs;	// Время завершения последней миссии в миллисекундах (-1, если миссий не было)

		struct SBB_Replacement
			{
			ulong SBB_R_Type;			// Тип замены: 0 - не объект, 1 - объект с прикреплённой трассой, 2 - здание
			ulong SBB_R_ObjectHandle;	// Указатель на заменяемый объект
			slong SBB_R_NewModelID;		// Модель, на которую выполняется замена (-1 - не задана)
			slong SBB_R_OldModelID;		// Заменяемая модель (-1 - не задана)
			} SBB_R[SD_SBB_R_Count];

		struct SBB_InvisibleObject
			{
			ulong SBB_IO_Type;		// Тип объекта; 0 - не объект, 1 - объект с прикреплённой трассой, 2 - здание,
									// 3 - загруженный динамический объект, 4 - выгруженный динамический объект
			ulong SBB_IO_Handle;	// Указатель на объект
			} SBB_IO[SD_SBB_IO_Count];

		uchar SBB_InMissionScriptRunning;	// Флаг активности скрипта миссии
		uchar SBB_CabsRadio;				// Состояние Cauffman cabs radio
		uchar SBB_Unused01[2];

		ulong SBB_SizeOfMain;				// Размер главного скрипта
		ulong SBB_SizeOfLargestMission;		// Размер самой большой миссии
		ulong SBB_MissionsCount;			// Число основных миссий
		} SBB;

	uchar SBB_Raw [sizeof (struct SBB_Formatted)];
	};
