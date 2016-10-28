union SD_ScriptPath
	{
	struct SP_Formatted
		{
		ulong SP_BlockSize;		// Размер блока
		ulong SP_SubBlockSize;	// Размер субблока
		ulong SP_PointsCount;	// Количество точек трассы (яхта полковника, spath0.dat)
		
		uchar SP_Unused1[4];
		float SP_TotalDistance;				// Общая длина трассы
		float SP_MoveSpeed;					// Скорость движения
		float SP_ObjectPlacementDistance;	// Отступ объекта от трассы
		float SP_ObjectOffset;				// Дистанция от начала трассы, на которой располагается объект
		uchar SP_Unused2[4];
		uchar SP_ObjectAttachments[128];	// Неизвестная структура
		} SP;

	uchar SP_Raw [sizeof (struct SP_Formatted)];
	};
