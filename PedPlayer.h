// INCOMPLETED //

#define SD_PPL_WD_Count	10

union SD_PedPlayer
	{
	struct PPL_Formatted
		{
		ulong PPL_BlockSize;		// Размер блока (0x0708)
		ulong PPL_SubBlock1Size;	// Размер субблока 1 (0x0703)
		ulong PPL_NumberOfPlayers;	// Число игроков (1)

		// По идее, дальнейшие данные нужно обрабатывать как массив. Но в нём сейчас всего 1 элемент
		uchar PPL_Unused1[6];
		ulong PPL_PlayerIndex;						// Номер игрока
		uchar PPL_PlayerPedStructureDump1[52];		// Фрагмент дампа структуры игрока
		float PPL_X;								// Положение игрока
		float PPL_Y;
		float PPL_Z;
		uchar PPL_PlayerPedStructureDump2[788];		// Фрагмент дампа структуры игрока
		float PPL_CurrentHealth;					// Текущее здоровье (не изменяется вне игры)
		float PPL_CurrentArmor;						// Текущее состояние брони
		uchar PPL_PlayerPedStructureDump3[172];		// Фрагмент дампа структуры игрока

		// Структура описателя оружия
		struct PPL_WeaponData
			{
			ulong PPL_WD_WeaponNumber;	// Номер оружия по порядку
			uchar PPL_WD_Unused1[4];
			ulong PPL_WD_HolderSize;	// Размер обоймы
			ulong PPL_WD_BulletsCount;	// Число пуль
			uchar PPL_WD_Unused2[8];
			} PPL_WD[SD_PPL_WD_Count];

		uchar PPL_PlayerPedStructureDump4[12];	// Фрагмент дампа структуры игрока
		uchar PPL_SelectedWeapon;				// Текущее выьранное оружие
		uchar PPL_PlayerPedStructureDump5[255];	// Фрагмент дампа структуры игрока
		float PPL_MaxStamina;					// Максимальная устойчивость
		uchar PPL_PlayerPedStructureDump6[28];	// Фрагмент дампа структуры игрока
		slong PPL_TargettableObjects[4];		// Объекты, на которых работает автоприцел
		uchar PPL_PlayerPedStructureDump7[164];	// Фрагмент дампа структуры игрока
		ulong PPL_MaxWantedLevel;				// Максимальный уровень розыска (рекомендуется 4)
		ulong PPL_MaxCriminalPoints;			// Максимальная величина интереса полиции (рекомендуется 1800)
		uchar PPL_SuitName[22];					// Текущий костюм
		} PPL;

	uchar PPL_Raw [sizeof (struct PPL_Formatted)];
	};
