#define SD_PI_PS_Count	50

union SD_PhoneInfo
	{
	struct PI_Formatted
		{
		ulong PI_BlockSize;			// ������ ����� (0x0A34)
		ulong PI_SubBlockSize;		// ������ �������� (0x0A30)
		ulong PI_PhonesCount;		// ���������� ���������
		ulong PI_ActivePhonesCount;	// ���������� �������� ���������

		struct PI_PhoneStructure
			{
			float PI_PS_X;							//  ������������
			float PI_PS_Y;
			float PI_PS_Z;
			ulong PI_PS_PhoneMessagePointers[6];	// ��������� gxt, ����������� �� ���������
			ulong PI_PS_GameTimerOnMsgEnd;			// ����� ���� ��� ��������� ���������
			ulong PI_PS_PhoneObjectIndex;			// ������ ������� ��������
			ulong PI_PS_Status;						// ���������
			// 3 - �� ������, 9 - ������, ��������� �� ������������
			// 4 = ringing, message just once; 5 = ringing, message repeated, phone was never picked up;
			// 6 = ringing, message repeated, phone was picked up before; 7 = no ringing, finished state of state 4;
			// 8 = no ringing, finished state of states 5 and 6
			uchar PI_PS_IsPlayerNearFrom;			// ���� �������� ������ (������ ������)
			uchar PI_PS_Unused1[3];
			} PI_PS[SD_PI_PS_Count];
		} PI;

	uchar PI_Raw [sizeof (struct PI_Formatted)];
	};
