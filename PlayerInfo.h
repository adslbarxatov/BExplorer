// INCOMPLETED //

union SD_PlayerInfo
	{
	struct PL_Formatted
		{
		ulong PL_BlockSize;			// ������ ����� (0x0174)
		ulong PL_SubBlockSize;		// ������ �������� (0x0170)
		ulong PL_CurrentMoney;		// ������� ����� ��������
		uchar PL_WastedBustedStatus;
		uchar PL_Unused1[10];
		ulong PL_CurrentShowedMoney;		// ������� ������������ ��������
		ulong PL_CollectedHiddenPackages;	// ��������� ���������� ������
		ulong PL_HiddenPackagesCount;		// ���������� ���������� �������
		uchar PL_InfiniteRun;		// ���� ����������� ��� ����
		uchar PL_FastReload;		// ���� ������� ����������� ������
		uchar PL_Fireproof;			// ���� �������������
		uchar PL_MaxHealth;			// ������������ �������� ��������
		uchar PL_MaxArmor;			// ������������ �������� �����
		uchar PL_FreeBusted;		// ��������� �� ������ ������ ��� ������
		uchar PL_FreeWasted;		// ��������� �� ������ ������ � ������ ��� ������
		uchar PL_DriveByEnabled;	// �������� ����� �������� �� ������
		uchar PL_Unknown1[73];
		ulong PL_UF1UnitsCount;		// ����� ��������� � ��������� �������
		float PL_UnknownFlow1[64];
		} PL;

	uchar PL_Raw [sizeof (struct PL_Formatted)];
	};
