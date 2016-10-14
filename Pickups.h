#define SD_PU_S_Count	336

union SD_Pickups
	{
	struct PU_Formatted
		{
		ulong PU_BlockSize;			// Размер блока (0x4498)
		ulong PU_SubBlockSize;		// Размер субблока (0x4494)

		struct PU_Structure
			{
			float PU_S_X;			// Положение объекта
			float PU_S_Y;
			float PU_S_Z;
			float PU_S_CurrentAsset;		// Текущее состояние накопителя денег
			ulong PU_S_PickupObjectEntity;
			ulong PU_S_PickupExtraObject;
			ulong PU_S_MaxAsset;	// Максимальное количество выдаваемых патронов или денег
			ulong PU_S_AssetTimer;
			uint PU_S_AssetRate;
			uint PU_S_ModelNumber;	// Номер модели, олицетворяющей pickup
			uint PU_S_Unused1;
			uchar PU_S_HelpMessage[8];
			uchar PU_S_PickupType;
			uchar PU_S_HaveBeenPickedUp;	// "Собран" ли объект
			uchar PU_S_Unused2[4];
			} PU_S[SD_PU_S_Count];

		uint PU_CollectedIndex;
		uchar PU_Unused1[2];
		uchar *PU_CollectedIndices[20];
		} PU;

	uchar PU_Raw [sizeof (struct PU_Formatted)];
	};
