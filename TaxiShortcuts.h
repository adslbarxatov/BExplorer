#define SD_TS_SC_Count	16

union SD_TaxiShortcuts
	{
	struct TS_Formatted
		{
		ulong TS_BlockSize;				// ������ ����� (0x0108)
		ulong TS_SubBlockSize;			// ������ �������� (0x0104)
		ulong TS_TaxiShortcutsCount;	// ����� ����� �������� �����

		struct TS_Shortcut
			{
			float TS_SC_X;			// ���������
			float TS_SC_Y;
			float TS_SC_Z;
			float TS_SC_Rotation;	// �������
			} TS_SC[SD_TS_SC_Count];

		} TS;

	uchar TS_Raw [sizeof (struct TS_Formatted)];
	};
