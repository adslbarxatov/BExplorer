union SD_ScriptPath
	{
	struct SP_Formatted
		{
		ulong SP_BlockSize;		// Размер блока
		ulong SP_SubBlockSize;	// Размер субблока
		ulong SP_PointsCount;	// Количество точек трассы (яхта полковника, spath0.dat)
		
		uchar SP_Unused1[4];
		float SP_TotalDistance;
		float SP_MoveSpeed;
		float SP_ObjectPlacementDistance;
		float SP_ObjectOffset;
		ulong SP_ObjectAttachments[33];
		} SP;

	uchar SP_Raw [sizeof (struct SP_Formatted)];
	};
