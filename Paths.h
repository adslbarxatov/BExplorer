// INCOMPLETED

union SD_Paths
	{
	struct PH_Formatted
		{
		ulong PH_BlockSize;		// ������ �����
		ulong PH_SubBlockSize;	// ������ ��������
		} PH;

	uchar PH_Raw [sizeof (struct PH_Formatted)];
	};

union SD_PathsDescription
	{
	uchar PHD_Unknown1[1];

	uchar PHD_Raw[1];
	};
