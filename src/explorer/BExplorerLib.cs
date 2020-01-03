using System;
using System.Runtime.InteropServices;

namespace BExplorer
	{
	/// <summary>
	/// Класс обеспечивает доступ к методам библиотеки BExplorerLib
	/// </summary>
	public static class BExplorerLib
		{
		#region Импортированные функции

		/// <summary>
		/// Imported from C/C++ DLL
		/// Метод формирует сообщение ошибки по её коду
		/// </summary>
		/// <param name="ErrorCode">Код ошибки</param>
		/// <returns>Возвращает сообщение об ошибке</returns>
		[DllImport ("B_explorerLib.dll")]
		public static extern string SaveData_ErrorPromptEx (Int16 ErrorCode);

		/// <summary>
		/// Imported from C/C++ DLL
		/// Метод получает краткую информацию о файле сохранения
		/// </summary>
		/// <returns>Возвращает строку информации</returns>
		[DllImport ("B_explorerLib.dll")]
		public static extern string SaveData_GetSaveInfoEx ();

		/// <summary>
		/// Imported from C/C++ DLL
		/// Метод получает ToDo-статус сохранения
		/// </summary>
		/// <returns>Возвращает строку статуса</returns>
		[DllImport ("B_explorerLib.dll")]
		public static extern string SaveData_GetToDoStatusEx ();

		/// <summary>
		/// Imported from C/C++ DLL
		/// Метод возвращает ключ сверки версии библиотеки. Позволяет избегать рассогласования
		/// протоколов взаимодействия библиотеки и приложения
		/// </summary>
		/// <returns>Ключ сверки</returns>
		[DllImport ("B_explorerLib.dll")]
		private static extern string SaveData_GetLibVersionKeyEx ();
		private const string AppVersionKey = "\x03\x01|\x18.\x10.\x16";

		/// <summary>
		/// Imported from C/C++ DLL
		/// Метод выполняет загрузку файла сохранения из указанного расположения. Начинает
		/// сеанс взаимодействия со структурой данных сохранения
		/// </summary>
		/// <param name="FilePath">Путь к загружаемому файлу</param>
		/// <returns>Возвращает код ошибки или 0 в случае успеха</returns>
		[DllImport ("B_explorerLib.dll")]
		public static extern Int16 SaveData_LoadEx (string FilePath);

		/// <summary>
		/// Imported from C/C++ DLL
		/// Командный интерпретатор. Возвращает сообщение с результатом выполнения команды или сообщение об ошибке
		/// </summary>
		/// <param name="Mode">Режим интерпретации</param>
		/// <param name="OpCode">Код операции</param>
		/// <param name="ParCode">Код параметра</param>
		/// <param name="Value">Новое значение параметра</param>
		/// <returns>Возвращает сообщение с результатом выполнения команды или сообщение об ошибке</returns>
		[DllImport ("B_explorerLib.dll")]
		private static extern string SaveData_CommandInterpreterEx (UInt16 Mode, UInt16 OpCode, UInt16 ParCode, string Value);

		#endregion

		#region Оболочка

		/// <summary>
		/// Функция применяет рекомендуемые исправления в файле сохранения
		/// </summary>
		/// <returns>Возвращает сообщение о результате выполнения</returns>
		public static string SaveData_FixFile ()
			{
			string res = SaveData_CommandInterpreterEx (5, 0, 0, "0");
			res += ("\r\n" + SaveData_CommandInterpreterEx (5, 1, 0, "0"));
			return res;
			}

		// Коды операций для следующих трёх функций
		public enum OpCodes
			{
			SaveYear = 0,
			SaveMonth = 1,
			SaveDay = 2,
			SaveHour = 3,
			SaveMinute = 4,
			SaveSecond = 5,
			InGameMinuteLength = 6,
			InGameHour = 7,
			InGameMinute = 8,
			GameSpeed = 9,
			CurrentWeather = 10,
			CarOverview = 11,
			CabsRadio = 100,
			PlayerWeapons_Base = 200,	// Этот и следующие [количество определено далее] кодов отвечают за оружие
			CurrentArmor = 210,
			MaxPoliceStars = 211,
			PlayerSuit = 212,
			Garages_Base = 300,
			Gangs_Base = 400,
			CurrentMoney = 500,
			InfiniteRun = 501,
			FastReload = 502,
			Fireproof = 503,
			MaxHealth = 504,
			MaxArmor = 505,
			InfiniteAmmo = 506,
			Pickups_Base = 1000,
			ActiveGenerators = 2000,
			Generators_Base = 2001
			}
		public const uint WeaponsCount = 10;
		public const uint GaragesCount = 21;
		public const uint GangsCount = 8;
		public const uint PickupsCount = 336;
		public const uint GeneratorsCount = 185;
		public enum WeaponsParCodes
			{
			WeaponType = 0,
			WeaponAmmo = 1
			}
		public enum GaragesParCodes
			{
			CarModel = 0,
			Immunity = 1,
			PrimaryColor = 2,
			SecondaryColor = 3,
			RadioStation = 4,
			BombType = 5
			}
		public enum GangsParCodes
			{
			CarModel = 0,
			PrimaryPedModel = 1,
			SecondaryPedModel = 2,
			PrimaryWeapon = 3,
			SecondaryWeapon = 4
			}
		public enum PickupsParCodes
			{
			ObjectModel = 0,
			ObjectX = 1,
			ObjectY = 2,
			ObjectZ = 3,
			ObjectType = 4,
			ObjectAsset = 5,		// Устанавливать можно только это значение
			HasBeenPickedUp = 6
			}
		public enum GeneratorsParCodes
			{
			CarModel = 0,
			CarX = 1,
			CarY = 2,
			CarZ = 3,
			CarAngle = 4,
			AllowSpawn = 5,
			PrimaryColor = 6,
			SecondaryColor = 7,
			AlarmProbability = 8,
			LockProbability = 9,
			ForceSpawn = 10
			}

		/// <summary>
		/// Функция получает значение указанного параметра
		/// </summary>
		/// <param name="OpCode">Код параметра</param>
		/// <param name="ParCode">Код субпараметра</param>
		/// <returns>Возвращает сообщение с результатом выполнения команды или сообщение об ошибке</returns>
		public static string SaveData_GetParameterValue (UInt16 OpCode, UInt16 ParCode)
			{
			return SaveData_CommandInterpreterEx (0, OpCode, ParCode, "0");
			}

		/// <summary>
		/// Функция устанавливает значение указанного параметра
		/// </summary>
		/// <param name="OpCode">Код параметра</param>
		/// <param name="ParCode">Код субпараметра</param>
		/// <param name="NewValue">Новое значение параметра</param>
		/// <returns>Возвращает сообщение с результатом выполнения команды или сообщение об ошибке</returns>
		public static string SaveData_SetParameterValue (UInt16 OpCode, UInt16 ParCode, string NewValue)
			{
			if (NewValue == null)
				{
				return SaveData_ErrorPromptEx (-1002);	// Код ошибки "значение вне диапазона"
				}
			return SaveData_CommandInterpreterEx (1, OpCode, ParCode, NewValue.Replace (',', '.'));
			}

		/// <summary>
		/// Функция получает допустимый диапазон значений указанного параметра
		/// </summary>
		/// <param name="OpCode">Код параметра</param>
		/// <param name="ParCode">Код субпараметра</param>
		/// <param name="Max">Указывает, что следует вернуть максимум вместо минимума</param>
		/// <returns>Возвращает запрошенное значение</returns>
		public static float SaveData_GetParameterLimit (UInt16 OpCode, UInt16 ParCode, bool Max)
			{
			// Извлечение значений границ
			string v = SaveData_CommandInterpreterEx (4, OpCode, ParCode, "");
			if (!IsResultSuccessful (v))
				{
				return 0.0f;
				}

			char[] splitters = new char[] { ';' };
			string[] values = v.Split (splitters, StringSplitOptions.RemoveEmptyEntries);
			if (values.Length != 2)
				{
				return 0.0f;
				}

			float min = 0.0f, max = 0.0f;
			try
				{
				min = float.Parse (values[0]);
				max = float.Parse (values[1]);
				}
			catch
				{
				}

			// Возврат
			if (Max)
				{
				return max;
				}
			else
				{
				return min;
				}
			}

		// Варианты загружаемых файлов
		public enum LoadableParameters
			{
			Garages = 1,
			Stats = 2,
			Generators = 3
			}

		/// <summary>
		/// Функция загружает указанный файл параметров в файл сохранения
		/// </summary>
		/// <param name="ParametersType">Тип файла параметров</param>
		/// <param name="FileName">Имя файла параметров</param>
		/// <returns>Возвращает сообщение с результатом выполнения команды или сообщение об ошибке</returns>
		public static string SaveData_LoadParametersFile (LoadableParameters ParametersType, string FileName)
			{
			if (FileName == null)
				{
				return SaveData_CommandInterpreterEx (2, (UInt16)ParametersType, 0, "<");
				}
			return SaveData_CommandInterpreterEx (2, (UInt16)ParametersType, 0, FileName);
			}

		// Варианты загружаемых файлов
		public enum SaveableParameters
			{
			SaveFile = 0,
			Garages = 1,
			Stats = 2,
			Generators = 3
			}

		/// <summary>
		/// Функция сохраняет указанный файл параметров в файл сохранения или сам файл сохранения
		/// </summary>
		/// <param name="ParametersType">Тип файла параметров</param>
		/// <param name="FileName">Имя файла параметров</param>
		/// <returns>Возвращает сообщение с результатом выполнения команды или сообщение об ошибке</returns>
		public static string SaveData_SaveParametersFile (SaveableParameters ParametersType, string FileName)
			{
			if (FileName == null)
				{
				return SaveData_CommandInterpreterEx (3, (UInt16)ParametersType, 0, "<");
				}
			return SaveData_CommandInterpreterEx (3, (UInt16)ParametersType, 0, FileName);
			}

		/// <summary>
		/// Метод выполняет проверку методов на доступность и корректность взаимодействия с программой
		/// </summary>
		/// <returns>Возвращает номер метода, в котором произошёл сбой, или 0 в случае успеха. -1 означает несовпадение версий приложения и библиотеки</returns>
		public static int Check ()
			{
			#region SaveData_GetLibVersionKey
			try
				{
				if (SaveData_GetLibVersionKeyEx () != AppVersionKey)
					{
					return -1;
					}
				}
			catch
				{
				return 1;
				}
			#endregion

			#region SaveData_LoadEx
			try
				{
				int e = SaveData_LoadEx ("<");
				}
			catch
				{
				return 2;
				}
			#endregion

			#region SaveData_CommandInterpreterEx
			try
				{
				string s = SaveData_CommandInterpreterEx (0, 0, 0, "0");
				}
			catch
				{
				return 3;
				}
			#endregion

			#region SaveData_ErrorPromptEx
			try
				{
				string m = SaveData_ErrorPromptEx (0);
				}
			catch
				{
				return 4;
				}
			#endregion

			#region SaveData_GetSaveInfoEx
			try
				{
				string i = SaveData_GetSaveInfoEx ();
				}
			catch
				{
				return 5;
				}
			#endregion

			#region SaveData_GetToDoStatusEx
			try
				{
				string s = SaveData_GetToDoStatusEx ();
				}
			catch
				{
				return 6;
				}
			#endregion

			return 0;
			}

		/// <summary>
		/// Метод проверяет успешность выполнения команды интерпретатором
		/// </summary>
		/// <param name="InterpreterReturnedResult">Ответ командного интерпретатора</param>
		/// <returns>Успешно/неуспешно выполнена команда</returns>
		public static bool IsResultSuccessful (string InterpreterReturnedResult)
			{
			return (InterpreterReturnedResult.IndexOf ("\x13") == -1);
			}

		#endregion
		}
	}
