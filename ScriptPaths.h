union SD_ScriptPath
	{
	struct SP_Formatted
		{
		ulong SP_BlockSize;		// ������ �����
		ulong SP_SubBlockSize;	// ������ ��������
		ulong SP_PointsCount;	// ���������� ����� ������ (���� ����������, spath0.dat)
		
		uchar SP_Unused1[4];
		float SP_TotalDistance;				// ����� ����� ������
		float SP_MoveSpeed;					// �������� ��������
		float SP_ObjectPlacementDistance;	// ������ ������� �� ������
		float SP_ObjectOffset;				// ��������� �� ������ ������, �� ������� ������������� ������
		uchar SP_Unused2[4];
		uchar SP_ObjectAttachments[128];	// ����������� ���������
		} SP;

	uchar SP_Raw [sizeof (struct SP_Formatted)];
	};
