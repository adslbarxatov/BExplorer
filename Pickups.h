#define SD_PU_S_Count	336

union SD_Pickups
	{
	struct PU_Formatted
		{
		ulong PU_BlockSize;			// ������ ����� (0x4498)
		ulong PU_SubBlockSize;		// ������ �������� (0x4494)

		struct PU_Structure					// ��������� ���������� �������
			{
			float PU_S_X;					// ��������� �������
			float PU_S_Y;
			float PU_S_Z;
			float PU_S_CurrentAsset;		// ������� ��������� ���������� (��� ����� � ��������)
			ulong PU_S_PickupObjectEntity;
			ulong PU_S_PickupExtraObject;
			ulong PU_S_MaxAsset;			// ������������ �������� ���������� (��� �����, ��������� �� �������)
			ulong PU_S_AssetTimer;			// ��������� ������� ����������
			uint PU_S_AssetRate;			// ������� ���������� ��������
			uint PU_S_ModelNumber;			// ����� ������, �������������� ������
			uint PU_S_Unused1;
			uchar PU_S_HelpMessage[8];		// ����� �� gxt, ������������ ��� ����� (������� �����) �������
			uchar PU_S_PickupType;			// ��� �������
			// 0 - �� ����� (������ ��������)
			// 1 - �������� ���������� ����� 5 �
			// 2 - �������� ���������� ����� 20 � ��� �������, ��� ����� �� ���������� �� ����� 15 �
			// 3 - ���������� ���� ���, �� �����������������
			// 4 - ���������� ���� ���, �� �����������������, �������� ����� 20 �
			// 5 - ���������� ���� ���, �� �����������������, �������� ����� 120 �
			// 6 - ���������� ����� (���������� � 0 ��� �����)
			// 15 - �������� ���������� ����� 30 � ��� �������, ��� ����� �� ���������� �� ����� 15 �
			// 16 - �������� ���������� (�� ����������, ����� ������)
			// 17 - ����������� ������������� (�� ����������)
			// 18 - ��������� �������������
			uchar PU_S_HasBeenPickedUp;	// "������" �� ������
			uchar PU_S_Unused2[4];
			} PU_S[SD_PU_S_Count];

		uint PU_CollectedIndex;				// ������� ��������� ��������, �� �������
		uchar PU_Unused1[2];
		uint PU_CollectedIndices[40];
		} PU;

	uchar PU_Raw [sizeof (struct PU_Formatted)];
	};
