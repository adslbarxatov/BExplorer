#define SD_CR_S_Count	8

union SD_Cranes
	{
	struct CR_Formatted
		{
		ulong CR_BlockSize;			// Размер блока (0x03EC)
		ulong CR_SubBlockSize;		// Размер субблока (0x03E8)
		ulong CR_CranesCount;		// Число кранов
		ulong CR_CarsCollected;		// Не используется

		struct CR_Structure
			{
			ulong CR_S_CraneObjectPointer;		// Объект-кран
			ulong CR_S_MagnetObjectPointer;		// Объект-магнит
			float CR_S_PickupZoneX1;
			float CR_S_PickupZoneX2;
			float CR_S_PickupZoneY1;
			float CR_S_PickupZoneY2;
			float CR_S_DropOffZoneX;
			float CR_S_DropOffZoneY;
			float CR_S_DropOffZoneZ;
			float CR_S_DropOffAngle;
			float CR_S_CraneArmPickupAngle;
			float CR_S_CraneArmDropOffAngle;
			float CR_S_CraneArmPickupDistance;
			float CR_S_CraneArmDropOffDistance;
			float CR_S_CraneArmPickupHeight;
			float CR_S_CraneArmDropOffHeight;
			float CR_S_CraneArmCurrentAngle;
			float CR_S_CraneArmCurrentDistance;
			float CR_S_CraneArmCurrentHeight;
			float CR_S_CraneHookInitialX;
			float CR_S_CraneHookInitialY;
			float CR_S_CraneHookInitialZ;
			float CR_S_CraneHookCurrentX;
			float CR_S_CraneHookCurrentY;
			float CR_S_CraneHookCurrentZ;
			uchar CR_S_Unused1[8];
			uchar *CR_S_TargettedCar;
			ulong CR_S_GameTimerOnLiftFinish;
			uchar CR_S_CraneActivity;	// 0 - idle, 1 - active, 2 - inactive
			uchar CR_S_CraneStatus;		// 0 - idle, 1 - move to pickup, 3 - upward from pickup, 2 - move to destination,
										// 4 - move to drop off, 5 - move from drop off
			uchar CR_S_CollectedCarsCount;
			uchar CR_S_IsCrusherCrane;
			uchar CR_S_IsMilitaryCrane;
			uchar CR_S_Unused2;
			uchar CR_S_IsNot_doc_crane_cab0;
			uchar CR_S_Unused3;
			} CR_S[SD_CR_S_Count];

		} CR;

	uchar CR_Raw [sizeof (struct CR_Formatted)];
	};
