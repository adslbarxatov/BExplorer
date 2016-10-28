union SD_Stats
	{
	struct ST_Formatted
		{
		ulong ST_BlockSize;				// ������ ����� (0x258)
		ulong ST_SubBlockSize;			// ������ �������� (0x253)
		ulong ST_TotalPeopleWasted;		// ����� ����� �����
		ulong ST_PeopleWastedByOthers;	// ����� �������
		ulong ST_CarsExploded;			// �������� �����
		ulong ST_BoatsExploded;			// �������� �����
		ulong ST_TiresPopped;			// ������� ���
		ulong ST_BulletsFired;			// ������������ ����

		ulong ST_Player1Wasted;			// ����� ����� (�� �������)
		ulong ST_Player2Wasted;
		ulong ST_Player3Wasted;
		ulong ST_Player4Wasted;
		ulong ST_MalesWasted;
		ulong ST_FemalesWasted;
		ulong ST_CopsWasted;
		ulong ST_CubansWasted;
		ulong ST_HaitiansWasted;
		ulong ST_StreetWannabesWasted;
		ulong ST_DiazGangMembersWasted;
		ulong ST_SecurityGuardsWasted;
		ulong ST_BikersWasted;
		ulong ST_VersettiGangMembersWasted;
		ulong ST_GolfersWasted;
		ulong ST_UnusedGangWasted;
		ulong ST_AmbulanceWasted;
		ulong ST_FirefightersWasted;
		ulong ST_CriminalsWasted;
		ulong ST_AdditionalPedsWasted;
		ulong ST_ProstitutesWasted;
		ulong ST_ReservedPedsWasted;
		ulong ST_UnusedPedsWasted;

		ulong ST_HelicoptersExploded;	// �������� ���������
		float ST_ProgressMade;			// ����������� ����
		float ST_TotalProgress;			// ����� ���������� ����
		ulong ST_ExplosivesKgsUsed;		// ������������ ����������� ����������
		ulong ST_BulletsThatHit;		// ����, �������� � ����
		ulong ST_HeadShotsCount;		// ���������� ��������� � ������
		ulong ST_WantedStarsGot;		// ���������� ����� �������
		ulong ST_WantedStarsAvoided;	// �����, ������� ������� ��������
		ulong ST_TimesBusted;			// �������
		ulong ST_TimesWasted;			// �������
		ulong ST_DaysPassedInGame;		// ���� � ����
		ulong ST_SafehousesVisits;		// ����������
		ulong ST_RespraysCount;			// ���������� ��������
		float ST_MaxInsaneJumpDistance;	// ������������ ��������� "������������ ������"
		float ST_MaxInsaneJumpHeight;	// ������������ ������ "������������ ������"
		ulong ST_MaxInsaneJumpFlips;	// ������������ ����� �������� � "����������� ������"
		ulong ST_MaxInsaneJumpRotation;	// ������������ ���� �������� "������������ ������"
		ulong ST_MaxInsaneJumpRating;	// ������� "������������ ������"
		ulong ST_ToDoUniqueJumpsPassed;	// ��������� ���������� �������
		ulong ST_UniqueJumpsCount;		// ���������� ���������� �������
		ulong ST_MissionAttempts;		// ������ � ������
		ulong ST_TaxiPassengers;		// ������������ ���������� � �����
		ulong ST_TaxiCash;				// ������� � �����
		uchar ST_Unused1[12];
		ulong ST_PornLeafletsVisible;	// ��������� ������������� ����� ������ Dildo dodo
		ulong ST_AllowSecondaryWeatherTable;	// ���������� ������� ����� timecyc
		float ST_DistanceOnFootM;		// �������� ������, ������
		float ST_DistanceOnCarM;		// ���������� �� �������, ������
		float ST_DistanceOnBikeM;		// ���������� �� ������, ������
		float ST_DistanceOnBoatM;		// ���������� �� ������, ������
		float ST_DistanceOnGolfCartM;	// ���������� �� ����������, ������
		float ST_DistanceOnHelicopterM;	// ���������� �� ���������, ������
		float ST_DistanceOnPlaneM;		// ���������� �� ��������, ������
		ulong ST_PeopleSavedInAmbulance;	// ������� ����� � ����������� ������
		ulong ST_CriminalsWastedInVigilante;	// ���������� ����� � ����������� ������
		ulong ST_FiresExtinguished;		// �������� �������
		ulong ST_ToDoHighestVigilanteLevel;	// ��������� ������� ����������� ������
		ulong ST_ToDoHighestAmbulanceLevel;	// ��������� ������� ����������� ������
		ulong ST_ToDoHighestFirefighterLevel;	// ��������� ������� �������� ������
		ulong ST_PhotosTaken;			// ������� ����������
		ulong ST_ToDoRampagesPassed;	// �������� ������
		ulong ST_RampagesCount;			// ����� ������
		ulong ST_MainMissionsCount;		// ���������� ������� ������
		ulong ST_FlightMs;				// ��������� ����� ������, � �������������
		ulong ST_TimesDrowned;			// ���������� ���������
		ulong ST_SeagullsSniped;		// ������ �����
		float ST_WeaponBudget;			// ������ ������
		float ST_FashionBudget;			// ������ ������
		float ST_LoanSharksVisits;		// ����� ������� ���������� ���������
		float ST_ToDoStoresKnockedOff;		// ����������� ��������
		float ST_MovieStunts;			// �������� �����
		float ST_ToDoAsassinationContractsDone;	// ��������� ���������� �� ��������
		float ST_PizzasDelivered;		// ���������� ����
		float ST_GarbagePickupsMade;	// �������� ������
		float ST_IceCreamSold;			// ������� �����������
		float ST_TopShootingRangeScore;	// ������������ ���� � ����
		float ST_ShootingAccuracy;		// ���������������� � ����
		ulong ST_LongestWheelieTime;	// ������������ ����� �� ������ ������
		ulong ST_LongestStopieTime;		// ������������ ����� �� �������� ������
		ulong ST_Longest2WheelsTime;	// ������������ ����� �� ���� ������
		ulong ST_LongestWheelieDistance;	// ������������ ��������� �� ������ ������
		ulong ST_LongestStopieDistance;		// ������������ ��������� �� �������� ������
		float ST_Longest2WheelsDistance;	// ������������ ��������� �� ���� ������
		float ST_PropertyBudget;		// ������ ������������
		float ST_AutoRepairBudget;		// ������ ������� ����
		ulong ST_PropertyDestroyed;		// ����� ����������� ���������
		ulong ST_ToDoOwnedPropertyCount;	// ���������� ������������ �������� ������������
		ulong ST_BloodringKills;		// ������� � Blood ring
		ulong ST_ToDoLongestTimeInBlooding;	// ������������ ����� � Blood ring
		uchar ST_OwnedProperties[15];	// �����, ����������� ������������ ������� ������������
		float ST_HighestMediaAttention;	// ������������ �������� ���
		ulong ST_BikersRaceRecord;		// ������ ������ � ������ ��������
		ulong ST_HilaryRaceRecord;		// ������ ������ � ������ � ������
		ulong ST_ToDoDirtringRecord;	// ����������� ����� � ������ Dirtring
		ulong ST_ToDoRCPlaneRecord;		// ����������� ����� � ������ � RCPlane
		ulong ST_ToDoRCCarRecord;		// ����������� ����� � ������ � RCCar
		ulong ST_ToDoRCHelicopterRecord;	// ����������� ����� � ������ � RCHelicopter
		ulong ST_ToDoSunshineTrack1Record;	// ����������� ����� � ������ �1 Sunshine
		ulong ST_ToDoSunshineTrack2Record;	// ����������� ����� � ������ �2 Sunshine
		ulong ST_ToDoSunshineTrack3Record;	// ����������� ����� � ������ �3 Sunshine
		ulong ST_ToDoSunshineTrack4Record;	// ����������� ����� � ������ �4 Sunshine
		ulong ST_ToDoSunshineTrack5Record;	// ����������� ����� � ������ �5 Sunshine
		ulong ST_ToDoSunshineTrack6Record;	// ����������� ����� � ������ �6 Sunshine
		ulong ST_ToDoDowntownChopperRecord;	// ����������� ����� � ������ Downtown chopper
		ulong ST_ToDoOceanBeachChopperRecord;	// ����������� ����� � ������ Ocean beach chopper
		ulong ST_ToDoVicePointChopperRecord;	// ����������� ����� � ������ Vice point chopper
		ulong ST_ToDoLittleHaitiChopperRecord;	// ����������� ����� � ������ Little Haiti chopper
		ulong ST_ToDoPCJPlaygroundRecord;	// ����������� ����� � ������ PCJ playground
		ulong ST_TrialByDirtRecord;		// ����������� ����� � ������ Trial by dirt
		ulong ST_TestTrackRecord;		// ����������� ����� � ������ Test track
		ulong ST_ToDoConeCrazyRecord;	// ����������� ����� � ������ Cone crazy
		ulong ST_ToDoHotringRecord;		// ����������� ����� � ������ Hotring
		ulong ST_HotringLapRecord;		// ����������� ����� ����� � ������ Hotring (� �������������)
		ulong ST_ToDoCheckpointCharlieRecord;	// ����������� ����� � ������ Checkpoint Charlie
		ulong ST_HighestScoreInShootist;	// ������������ ���� � Shootist
		ulong ST_BestPercentageInShootist;	// ������������ �������� � Shootist
		ulong ST_DrugDealsMade;			// ��������� �����������
		ulong ST_HighestScoreInBeachBall;	// ������������ ���� � ������� �������
		uchar ST_Unused2[4];
		ulong ST_HotringBestResult;		// ������ ��������� � Hotring
		ulong ST_PedsKilledInGame;		// ����� ����� �� ����� ���� (��� ���������� ������ 0)
		ulong ST_TotalPedsKilled;		// ����� ������� ???
		uchar ST_LastPassedMissionGXTEntry[8];	// ��������� ����� ����� � ���� ��������� �����
		ulong ST_CheatRating;			// ������� �����
		float ST_RadioListetingTimeMs[10];	// ����� ������������� ������������ (��� ������)
		uchar ST_Unused3;
		} ST;

	uchar ST_Raw [sizeof (struct ST_Formatted)];
	};
