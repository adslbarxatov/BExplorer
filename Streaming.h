// Количество описателей потоков
#define	SD_SR_SS_Count 15

// Блок стримминга
union SD_Streaming
	{
	struct SR_Formatted
		{
		ulong SR_BlockSize;			// Размер блока (0x0130)
		ulong SR_SubBlockSize;		// Размер субблока (0x012C)

		// Описатели потоков
		struct StreamingStructure
			{
			uchar SR_SS_Unknown1[20];
			} SR_SS[SD_SR_SS_Count];
		} SR;

	uchar SR_Raw [sizeof (struct SR_Formatted)];
	};
