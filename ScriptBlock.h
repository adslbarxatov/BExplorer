union SD_ScriptBlock
	{
	struct SB_Formatted
		{
		ulong SB_ScriptBlockSize;		// ������ �����
		uchar SB_BlockName[4];			// �������� ����� (SCR)
		ulong SB_ScriptSubBlockSize;	// ������ ��������
		ulong SB_ASubblockSize;			// ������ �������� �
		} SB;

	uchar SB_Raw [sizeof (struct SB_Formatted)];
	};

union SD_ScriptBlockAUnit
	{
	ulong SBA_Variable[1];			// ���� ���������� �� ����� ����������

	uchar SBA_Variable_Raw[1];
	};

#define SD_SBB_R_Count		25
#define SD_SBB_IO_Count		20

union SD_ScriptBlockB
	{
	struct SBB_Formatted
		{
		ulong SBB_BSubblockSize;			// ������ �������� �
		ulong SBB_OnMissionFlagAddress;		// ����� ����� ���������� � ������
		slong SBB_LastMissionPassTimeMs;	// ����� ���������� ��������� ������ � ������������� (-1, ���� ������ �� ����)

		struct SBB_Replacement
			{
			ulong SBB_R_Type;			// ��� ������: 0 - �� ������, 1 - ������ � ������������ �������, 2 - ������
			ulong SBB_R_ObjectHandle;	// ��������� �� ���������� ������
			slong SBB_R_NewModelID;		// ������, �� ������� ����������� ������ (-1 - �� ������)
			slong SBB_R_OldModelID;		// ���������� ������ (-1 - �� ������)
			} SBB_R[SD_SBB_R_Count];

		struct SBB_InvisibleObject
			{
			ulong SBB_IO_Type;		// ��� �������; 0 - �� ������, 1 - ������ � ������������ �������, 2 - ������,
									// 3 - ����������� ������������ ������, 4 - ����������� ������������ ������
			ulong SBB_IO_Handle;	// ��������� �� ������
			} SBB_IO[SD_SBB_IO_Count];

		uchar SBB_InMissionScriptRunning;	// ���� ���������� ������� ������
		uchar SBB_CabsRadio;				// ��������� Cauffman cabs radio
		uchar SBB_Unused01[2];

		ulong SBB_SizeOfMain;				// ������ �������� �������
		ulong SBB_SizeOfLargestMission;		// ������ ����� ������� ������
		ulong SBB_MissionsCount;			// ����� �������� ������
		} SBB;

	uchar SBB_Raw [sizeof (struct SBB_Formatted)];
	};
