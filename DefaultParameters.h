union SD_DefaultParameters
	{
	struct DP_Formatted
		{
		ulong DP_BlockSize;			// ������ ����� (� ����� � SB, SBA, SBB)
		wchar_t DP_SaveName[24];	// �������� ����� ����������
		uint DP_Year;				// ���� ����������
		uint DP_Month;
		uint DP_DayOfWeek;
		uint DP_Day;
		uint DP_Hour;				// ����� ����������
		uint DP_Minute;
		uint DP_Second;
		uint DP_Millisecond;
		ulong DP_Unused01;			// ����������, ������ 12609
		ulong DP_CurrentIsland;		// ����� �������� �������
		float DP_CameraX;			// ������� ������ ������
		float DP_CameraY;
		float DP_CameraZ;
		ulong DP_IngameMinuteLengthMs;	// ������������ ������ � ���� (����� - 1000 ms)
		ulong DP_WeatherTimer;		// ������ ������
		uchar DP_GameHour;			// ����� � ����
		uchar DP_Unused02[3];
		uchar DP_GameMinute;
		uchar DP_Unused03[3];
		ulong DP_PadNumber;
		ulong DP_GlobalTimer;		// ���������� ������
		float DP_GameSpeed;			// �������� ���� (����� - 1.0)
		float DP_FrameDelta;
		float DP_TimeStep;
		ulong DP_TotalFramesCount;
		float DP_TimeStep2;			// ������ 1.0
		float DP_FramesPerUpdate;	// 1.0
		float DP_TimeScale;			// 1.0
		ulong DP_OldWeatherNumber;	// ������ ����� ������
		ulong DP_NewWeatherNumber;	// ����� ����� ������
		__int16 DP_StaticWeatherNumber;	// ������� ������������� ������ (0 - 63, -1 = ���������)
		uint DP_Unused06;
		float DP_WeatherInterpolation;
		ulong DP_CurrentWeatherNumber;	// ����� ������� ������ � ������ (0 - 63)
		float DP_CarCameraView;		// ��������� ������ � ���� (0 - 5)
		float DP_FootCameraView;	// ��������� ������ ��� ������ (0 - 5)
		ulong DP_InteriorNumber;	// ����� ��������� (0 - 17)
		uchar DP_TaxiBoost;			// ������ ����� (0/1)
		uchar DP_Unused07[3];
		uchar DP_InvertLook;
		uchar DP_Unused08[3];
		ulong DP_ExtraSkyColor;		// ���� ���� � ���������
		ulong DP_IsExtraSkyActive;	// �������/���������
		float DP_SkyOverlay;		// ������� �������� � ����� ��������� (0.0 - 1.0)
		ulong DP_Unused09[10];
		} DP;

	uchar DP_Raw [sizeof (struct DP_Formatted)];
	};
