// INCOMPLETED //

union SD_ScriptPool
	{
	struct SC_Formatted
		{
		ulong SC_ScriptsCount;	// ���������� ��������
		} SC;

	uchar SC_Raw [sizeof (struct SC_Formatted)];
	};

union SD_ScriptStructure
	{
	struct SS_Formatted
		{
		ulong SS_PointerToPrevScript;	// ��������� �� ���������� ������
		ulong SS_PointerToNextScript;	// ��������� �� ��������� ������
		uchar SS_ScriptName[8];			// �������� �������
		ulong SS_CurrentInstructionPointer;	// ��������� �� ����������� �������
		ulong SS_ReturnStack[4];		// ���� �����������
		ulong SS_Unknown1[2];			// ???
		ulong SS_StackCounter;			// ������� �����
		ulong SS_LocalVariables[16];	// ��������� ����������
		ulong SS_TimerA;				// ������� ��������
		ulong SS_TimerB;
		uchar SS_IsActive;				// ������ �������
		uchar SS_IfStatementResult;		// ��������� ���������� ��������� If
		uchar SS_MissionCleanup;		// ����� ����� ����������� ������
		uchar SS_SkipWakeTime;			// ???
		ulong SS_WakeTime;				// ����� ������������ ������ �������, ��
		uint SS_IfCheckResult;			// ��������� �������� ��������� If
		uchar SS_NotFlag;				// ���� "��"
		uchar SS_DeathArrestState;		// ����� ��� ������ �� ����� ������
		uchar SS_DeathArrestExecuted;	// ���� �� ����� ��� ������
		uchar SS_MissionFlag;			// ���� ������
		uchar SS_Unknown2[2];			// ???
		} SS;

	uchar SS_Raw[1];
	};
