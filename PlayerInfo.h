// INCOMPLETED //

union SD_PlayerInfo
	{
	struct PL_Formatted
		{
		ulong PL_BlockSize;			// Размер блока (0x0174)
		ulong PL_SubBlockSize;		// Размер субблока (0x0170)
		ulong PL_CurrentMoney;		// Текущая сумма наличных
		uchar PL_WastedBustedStatus;
		uchar PL_Unused1[10];
		ulong PL_CurrentShowedMoney;		// Текущие отображаемые средства
		ulong PL_CollectedHiddenPackages;	// Найденные спрятанные пакеты
		ulong PL_HiddenPackagesCount;		// Количество спрятанных пакетов
		uchar PL_InfiniteRun;		// Флаг неуставания при беге
		uchar PL_FastReload;		// Флаг быстрой перезарядки оружия
		uchar PL_Fireproof;			// Флаг несгораемости
		uchar PL_MaxHealth;			// Максимальная величина здоровья
		uchar PL_MaxArmor;			// Максимальная величина брони
		uchar PL_FreeBusted;		// Позволяет не терять деньги при аресте
		uchar PL_FreeWasted;		// Позволяет не терять оружие и деньги при гибели
		uchar PL_DriveByEnabled;	// Включает режим стрельбы из машины
		uchar PL_Unknown1[73];
		ulong PL_UF1UnitsCount;		// Число элементов в следующем массиве
		float PL_UnknownFlow1[64];
		} PL;

	uchar PL_Raw [sizeof (struct PL_Formatted)];
	};
