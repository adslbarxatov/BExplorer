// INCOMPLETED //

union SD_ObjectPool
	{
	struct OP_Formatted
		{
		ulong OP_BlockSize;			// Размер блока
		ulong OP_SubBlockSize;		// Размер субблока
		ulong OP_ObjectsCount;		// Число объектов
		} OP;

	uchar OP_Raw [sizeof (struct OP_Formatted)];
	};

union SD_ObjectStructure
	{
	struct OS_Formatted
		{
		uint OS_ModelID;		// Модель объекта
		ulong OS_ObjectHandle;	// Указатель объекта
		float OS_X;				// Координаты объекта
		float OS_Y;
		float OS_Z;
		uchar OS_Unknown1[70];
		} OS;

	uchar OS_Raw[1];
	};
