// INCOMPLETED //

union SD_ObjectPool
	{
	struct OP_Formatted
		{
		ulong OP_BlockSize;			// ������ �����
		ulong OP_SubBlockSize;		// ������ ��������
		ulong OP_ObjectsCount;		// ����� ��������
		} OP;

	uchar OP_Raw [sizeof (struct OP_Formatted)];
	};

union SD_ObjectStructure
	{
	struct OS_Formatted
		{
		uint OS_ModelID;		// ������ �������
		ulong OS_ObjectHandle;	// ��������� �������
		float OS_X;				// ���������� �������
		float OS_Y;
		float OS_Z;
		uchar OS_Unknown1[70];
		} OS;

	uchar OS_Raw[1];
	};
