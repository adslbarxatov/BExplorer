#define SD_TZ_S_Count	96

union SD_TriggerZones
	{
	struct TZ_Formatted
		{
		ulong TZ_BlockSize;			// ������ ����� (0x1508)
		ulong TZ_SubBlockSize;		// ������ �������� (0x1504)
		ulong TZ_ZonesCount;		// ����� ���

		struct TZ_Structure
			{
			ulong TZ_S_Type;		// ��� ����
			float TZ_S_Timer;
			float TZ_S_X1;			// ������� ����
			float TZ_S_Y2;
			float TZ_S_X2;
			float TZ_S_Y1;
			float TZ_S_PoliceSpawnA_X;	// ���� ����� �������
			float TZ_S_PoliceSpawnA_Y;
			float TZ_S_PoliceSpawnB_X;
			float TZ_S_PoliceSpawnB_Y;
			float TZ_S_PoliceHeadingA_X;	// ���� ������������ �������
			float TZ_S_PoliceHeadingA_Y;
			float TZ_S_PoliceHeadingB_X;
			float TZ_S_PoliceHeadingB_Y;
			} TZ_S [SD_TZ_S_Count];
		} TZ;

	uchar TZ_Raw [sizeof (struct TZ_Formatted)];
	};
