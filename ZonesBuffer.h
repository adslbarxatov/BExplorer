// INCOMPLETED //

// Количество зон типа "navig"
#define SD_ZB_Navig_Count		20

// Количество зон типа "info"
#define SD_ZB_Info_Count		169

// Количество зон типа "peds, cars, gangs"
#define SD_ZB_PCG_Info_Count	338

// Количество зон типа "map"
#define SD_ZB_Map_Count			39

// Блок зон карты
union SD_ZonesBuffer
	{
	struct ZB_Formatted
		{
		ulong ZB_BlockSize;			// Размер блока (0x8BE4)
		ulong ZB_SubBlockSize;		// Размер субблока (0x8BE0)
		uchar ZB_BlockName[4];		// Название блока (ZNS)
		ulong ZB_SubBlock1Size;		// Размер оставшегося субблока (0x8BD8)
		ulong ZB_CurrentLevel;		// Суперзона: 1 - beach, 2 - mainland
		uchar ZB_Unused1[4];

		// Описатели зон типа "navig"
		struct ZB_Zone
			{
			uchar ZB_Z_Name[8];				// Название зоны
			float ZB_Z_X1;					// Крайние точки бокса зоны
			float ZB_Z_Y1;
			float ZB_Z_Z1;
			float ZB_Z_X2;
			float ZB_Z_Y2;
			float ZB_Z_Z2;
			ulong ZB_Z_Type;				// Тип зоны (0, 1 - navig, 2 - info, 3 - map)
			ulong ZB_Z_Level;				// Суперзона
			uint ZB_Z_ZoneInfoIDNight;		// ???
			uint ZB_Z_ZoneInfoIDDay;		// ???
			slong ZB_Z_ChildZoneIndex;		// Связанные зоны
			slong ZB_Z_ParentZoneIndex;
			uchar ZB_Z_Unused1[4];
			} ZB_NavigZones[SD_ZB_Navig_Count];	// navig.zon

		// Описатели зон типа "info"
		struct ZB_Zone ZB_InfoZones[SD_ZB_Info_Count];	// info.zon

		// Описатели зон типа "peds, cars, gangs"
		struct ZB_ZoneInfo
			{
			uchar ZB_ZI_Unknown1[0x44];
			} ZB_PedCarGangInfoZones[SD_ZB_PCG_Info_Count];

		uint ZB_NavigZonesCount;			// Количество зон navig
		uint ZB_InfoZonesCount;				// Количество зон info
		uint ZB_InfoZonesCountMul;			// Количество зон info * 2 + 1
		uchar ZB_Unused2[2];
		
		// Описатели зон типа "map"
		struct ZB_Zone ZB_MapZones[SD_ZB_Map_Count];	// map.zon

		sint ZB_CrimeReportAudioZones[14];	// Зоны, звучащие по радио при интересе полиции
		uint ZB_MapZonesCount;				// Количество зон map
		uint ZB_CrimeReportAudioZonesCount;	// Количество зон CrimeReport
		} ZB;

	uchar ZB_Raw [sizeof (struct ZB_Formatted)];
	};
