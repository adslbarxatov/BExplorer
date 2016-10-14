#define SD_GD_S_Count	9

union SD_GangData
	{
	struct GD_Formatted
		{
		ulong GD_BlockSize;			// ������ ����� (0x00E4)
		ulong GD_SubBlockSize;		// ������ �������� (0x00E0)
		uchar GD_BlockName[4];		// �������� ����� (GNG)
		ulong GD_SubBlock1Size;		// ������ ����������� ����� (0x00D8)

		struct GD_Structure
			{
			__int32 GD_S_CarModel;	// ���� ����� (-1 = ��� ����)
			ulong GD_S_PedModel1;	// ������ ��� ������������� �����
			ulong GD_S_PedModel2;	// ������ ��� ������������� �����
			char GD_S_PedModelPreference;
			uchar GD_S_Unused1[3];
			ulong GD_S_WeaponNumber1;	// ������ 1
			ulong GD_S_WeaponNumber2;	// ������ 2
			} GD_S [SD_GD_S_Count];

		} GD;

	uchar GD_Raw [sizeof (struct GD_Formatted)];
	};
