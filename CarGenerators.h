#define SD_CG_S_Count	185

union SD_CarGenerators
	{
	struct CG_Formatted
		{
		ulong CG_BlockSize;			// ������ ����� (0x1FEC)
		ulong CG_SubBlockSize;		// ������ �������� (0x1FE8)
		uchar CG_BlockName[4];		// �������� ����� (CGN)
		ulong CG_SubBlock2Size;		// ������ ��������� ����� �����
		ulong CG_CountsBlockSize;	// ������ ����� ��������� ����
		ulong CG_CarsCount;			// ���������� �����������
		ulong CG_ActiveCarCount;	// ���������� �������� �����������
		uchar CG_GeneratorCounter;	// ��������� �������� ���������
		uchar CG_GenerateWhenCounterClosed;
		uchar CG_Unused1[2];
		ulong CG_SubBlock3Size;		// ������ ��������� ����� �����

		struct CG_Structure
			{
			slong CG_S_ModelID;			// ������ ���� (-1 = ���������)
			float CG_S_X;				// ���������
			float CG_S_Y;
			float CG_S_Z;
			float CG_S_Rotation;		// �������
			sint CG_S_PrimaryColor;		// �����
			sint CG_S_SecondaryColor;
			uchar CG_S_ForceSpawn;		// ������������ ���������
			uchar CG_S_Alarm;			// ����������� ������������ ������������
			uchar CG_S_Lock;			// ����������� ����������
			uchar CG_S_Unused1;
			uint CG_S_MinDelay;			// �������� ������� ���������
			uint CG_S_MaxDelay;
			ulong CG_S_GameTimerWhenGenerated;	// ����� ���� � ������ ���������
			slong CG_S_CarIndex;
			sint CG_S_AllowSpawn;		// ����������� (-1 - ��������, 0 - ����������)
			uchar CG_S_HasBeenStolen;	// ��� �������� ��� ���
			uchar CG_S_Unused2;
			} CG_S[SD_CG_S_Count];
		} CG;

	uchar CG_Raw [sizeof (struct CG_Formatted)];
	};
