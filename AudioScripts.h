union SD_AudioScripts
	{
	struct AU_Formatted
		{
		ulong AU_BlockSize;		// ������ �����
		ulong AU_SubBlockSize;	// ������ ��������
		uchar AU_BlockName[4];	// ��� ����� (AUD)
		ulong AU_SubBlock1Size;	// ������ ����������� ��������
		ulong AU_ScriptsCount;	// ���������� ��������
		} AU;

	uchar AU_Raw [sizeof (struct AU_Formatted)];
	};

union SD_AudioScriptStructure
	{
	struct AS_Formatted
		{
		uchar AS_Unused1[4];
		uint AS_AudioNumber;	// ����� ������������
		// 0 - alarm, 2 - police cell open/close, 4 - garage gate open/close, 6 - 'No escape' snore, 11 - shooting range target,
		// 36 - 'Alloy Wheels of Steel' bikes, 37 - 'Messing with the Man' bikes, 38 - 'Hog tied' bikes, 39 - unused bikes sound,
		// 40-42 - Malibu club, 43-45 - Pole position, 46 - Church, 51 - Fountain
		uchar AS_Unused2[2];
		float AS_PositionX;		// ���������� �������
		float AS_PositionY;
		float AS_PositionZ;
		uchar AS_Unused3[4];
		} AS;

	uchar AS_Raw[1];
	};
