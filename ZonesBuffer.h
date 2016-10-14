// INCOMPLETED //

#define SD_ZB_Navig_Count		20
#define SD_ZB_Info_Count		169
#define SD_ZB_PCG_Info_Count	338
#define SD_ZB_Map_Count			39

union SD_ZonesBuffer
	{
	struct ZB_Formatted
		{
		ulong ZB_BlockSize;			// Размер блока (0x8BE4)
		ulong ZB_SubBlockSize;		// Размер субблока (0x8BE0)
		uchar ZB_BlockName[4];		// Название блока (ZNS)
		ulong ZB_SubBlock1Size;		// Размер оставшегося субблока (0x8BD8)
		ulong ZB_CurrentLevel;		// 1 - beach, 2 - mainland
		uchar ZB_Unused1[4];

		struct ZB_Zone
			{
			uchar ZB_Z_Name[8];		// Название зоны
			float ZB_Z_X1;			// Крайние точки бокса зоны
			float ZB_Z_Y1;
			float ZB_Z_Z1;
			float ZB_Z_X2;
			float ZB_Z_Y2;
			float ZB_Z_Z2;
			ulong ZB_Z_Type;
			ulong ZB_Z_Level;
			uint ZB_Z_ZoneInfoIDNight;
			uint ZB_Z_ZoneInfoIDDay;
			ulong ZB_Z_ChildZoneIndex;
			ulong ZB_Z_ParentZoneIndex;
			uchar ZB_Z_Unused1[4];
			} ZB_NavigZones[SD_ZB_Navig_Count];	// navig.zon

		struct ZB_Zone ZB_InfoZones[SD_ZB_Info_Count];	// info.zon

		struct ZB_ZoneInfo
			{
			uchar ZB_ZI_Unknown1[0x44];
			} ZB_PedCarGangInfoZones[SD_ZB_PCG_Info_Count];

		uint ZB_NavigZonesCount;
		uint ZB_InfoZonesCount;
		uint ZB_InfoZonesCountMul;
		uchar ZB_Unused2[2];
		struct ZB_Zone ZB_MapZones[SD_ZB_Map_Count];	// map.zon
		uint ZB_CrimeReportAudioZones[14];
		uint ZB_MapZonesCount;
		uint ZB_CrimeReportAudioZonesCount;

		} ZB;

	uchar ZB_Raw [sizeof (struct ZB_Formatted)];
	};
