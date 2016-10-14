union SD_Streaming
	{
	struct SR_Formatted
		{
		ulong SR_BlockSize;		// Размер блока (0x0130)
		ulong SR_SubBlockSize;		// Размер субблока (0x012C)

		struct StreamingStructure
			{
			uchar SR_SS_Unknown1[20];
			} SR_SS[15];
		} SR;

	uchar SR_Raw [sizeof (struct SR_Formatted)];
	};
