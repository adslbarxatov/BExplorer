// INCOMPLETED //

// Количество описаний оружия игрока
#define SD_PPS_WD_Count	10

// Общие параметры массива игроков
union SD_PedPlayer
	{
	struct PPL_Formatted
		{
		ulong PPL_BlockSize;		// Размер блока (0x0708)
		ulong PPL_SubBlock1Size;	// Размер субблока 1 (0x0703)
		ulong PPL_NumberOfPlayers;	// Число игроков (1)
		} PPL;

	uchar PPL_Raw [sizeof (struct PPL_Formatted)];
	};

// Массив игроков
union SD_PedPlayerStructure
	{
	struct PPS_Formatted
		{
		uchar PPS_Unused1[6];
		ulong PPS_PlayerIndex;						// Номер игрока
		uchar PPS_Unknown1[52];
		float PPS_X;								// Положение игрока
		float PPS_Y;
		float PPS_Z;
		uchar PPS_Unknown2[788];
		float PPS_CurrentHealth;					// Текущее здоровье (не изменяется вне игры)
		float PPS_CurrentArmor;						// Текущее состояние брони
		uchar PPS_Unknown3[172];

		// Структура описателя оружия
		struct PPS_WeaponData
			{
			ulong PPS_WD_WeaponNumber;	// Номер оружия по порядку
			uchar PPS_WD_Unused1[4];
			ulong PPS_WD_HolderSize;	// Размер обоймы
			ulong PPS_WD_BulletsCount;	// Число пуль
			uchar PPS_WD_Unused2[8];
			} PPS_WD[SD_PPS_WD_Count];

		uchar PPS_PlayerPedStructureDump4[12];	// Фрагмент дампа структуры игрока
		uchar PPS_SelectedWeapon;				// Текущее выьранное оружие
		uchar PPS_PlayerPedStructureDump5[255];	// Фрагмент дампа структуры игрока
		float PPS_MaxStamina;					// Максимальная устойчивость
		uchar PPS_PlayerPedStructureDump6[28];	// Фрагмент дампа структуры игрока
		slong PPS_TargettableObjects[4];		// Объекты, на которых работает автоприцел
		uchar PPS_PlayerPedStructureDump7[164];	// Фрагмент дампа структуры игрока
		ulong PPS_MaxWantedLevel;				// Максимальный уровень розыска (рекомендуется 4)
		ulong PPS_MaxCriminalPoints;			// Максимальная величина интереса полиции (рекомендуется 1800)
		uchar PPS_SuitName[22];					// Текущий костюм
		} PPS;

	uchar PPS_Raw [1];
	};
