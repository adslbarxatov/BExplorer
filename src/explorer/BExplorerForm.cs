﻿using System;
using System.ComponentModel;
using System.Drawing;
using System.Globalization;
using System.Windows.Forms;

namespace RD_AAOW
	{
	/// <summary>
	/// Главная форма приложения
	/// </summary>
	public partial class BExplorerForm:Form
		{
		// Переменные
		private bool loading = false;		// Флаг состояния загрузки данных; блокирует события обновления значений
		private int error;					// Код ошибки

		private CarColors cc;				// Экземпляр-загрузчик цветов авто
		private CarGenerators cg;			// Экземпляр-обработчик списка парковок
		private Pickups pu;					// Экземпляр-обработчик списка денежных накопителей
		private CoordsPicker cp;			// Форма выбора координат на карте
		private ToDoStatus tds;				// Экземпляр-обработчик ToDo-статуса

		private CultureInfo cie = new CultureInfo ("en-us");	// Дробные числа с использованием точки вместо запятой
		private SupportedLanguages al = Localization.CurrentLanguage;	// Язык интерфейса

		private string savesDefaultPath = Environment.GetFolderPath (Environment.SpecialFolder.MyDocuments) +
			"\\GTA Vice City User Files\\GTAVCsf";
		private const string savesExtension = ".b";

		/// <summary>
		/// Метод инициализирует форму
		/// </summary>
		public BExplorerForm ()
			{
			// Инициализация формы
			InitializeComponent ();

			Application.CurrentCulture = cie;
			this.Text = ProgramDescription.AssemblyTitle;
			}

		// Запуск формы
		private void MainForm_Load (object sender, EventArgs e)
			{
			// Контроль корректности связи с библиотекой функций
			if (BExplorerLib.Check () != 0)
				{
				if (MessageBox.Show (string.Format (Localization.GetText ("IncorrectLibVersion", al),
					ProgramDescription.AssemblyLibName),
					ProgramDescription.AssemblyTitle, MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation) == DialogResult.Yes)
					{
					AboutForm af = new AboutForm (null);
					}

				error = -1;
				this.Close ();
				return;
				}

			// Проверка наличия файла цветовой схемы
			cc = new CarColors (out error);
			if (error != 0)
				{
				this.Close ();
				return;
				}

			// Загрузка ограничений и списков
			loading = true;

			DP_Date.MaxDate = new System.DateTime ((int)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.SaveYear, 0, true),
				(int)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.SaveMonth, 0, true),
				(int)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.SaveDay, 0, true));
			DP_Date.MinDate = new System.DateTime ((int)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.SaveYear, 0, false),
				(int)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.SaveMonth, 0, false),
				(int)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.SaveDay, 0, false));

			DP_IML.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.InGameMinuteLength, 0, true);
			DP_IML.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.InGameMinuteLength, 0, false);

			DP_GameSpeed.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.GameSpeed, 0, true);
			DP_GameSpeed.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.GameSpeed, 0, false);

			PL_MaxHealth.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.MaxHealth, 0, true);
			PL_MaxHealth.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.MaxHealth, 0, false);

			PL_MaxArmor.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.MaxArmor, 0, true);
			PL_MaxArmor.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.MaxArmor, 0, false);

			PL_CurArmor.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.CurrentArmor, 0, true);
			PL_CurArmor.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.CurrentArmor, 0, false);

			for (int i = 0; i <= 6; i++)
				PL_MWL.Items.Add (i.ToString ());

			PL_CurMoney.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.CurrentMoney, 0, true);
			PL_CurMoney.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.CurrentMoney, 0, false);

			PL_Bullets.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.PlayerWeapons_Base,
				(UInt16)BExplorerLib.WeaponsParCodes.WeaponAmmo, true);
			PL_Bullets.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.PlayerWeapons_Base,
				(UInt16)BExplorerLib.WeaponsParCodes.WeaponAmmo, false);

			GR_CarModel.DataSource = ParametersValues.CarsForGarages;
			GR_CarModel.DisplayMember = GR_CarModel.ValueMember = "Name";

			GR_CarColor1.Maximum = cc.Colors.Count - 1;
			GR_CarColor2.Maximum = cc.Colors.Count - 1;

			GR_Radio.DataSource = ParametersValues.Radios;
			GR_Radio.DisplayMember = GR_Radio.ValueMember = "Name";

			PU_AssetValue.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Pickups_Base,
				(UInt16)BExplorerLib.PickupsParCodes.ObjectAsset, true);
			PU_AssetValue.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Pickups_Base,
				(UInt16)BExplorerLib.PickupsParCodes.ObjectAsset, false);

			GD_CarModel.DataSource = ParametersValues.CarsForGangs;
			GD_CarModel.DisplayMember = GD_CarModel.ValueMember = "Name";

			GD_PedModel1.Maximum = GD_PedModel2.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Gangs_Base,
				(UInt16)BExplorerLib.GangsParCodes.PrimaryPedModel, true);
			GD_PedModel1.Minimum = GD_PedModel2.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Gangs_Base,
				(UInt16)BExplorerLib.GangsParCodes.PrimaryPedModel, false);

			CarGenList.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.ActiveGenerators, 0, true);
			CarGenList.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.ActiveGenerators, 0, false);

			CG_CarModel.DataSource = ParametersValues.CarsForCG;
			CG_CarModel.DisplayMember = CG_CarModel.ValueMember = "Name";

			CG_X.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.CarX, true);
			CG_X.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.CarX, false);

			CG_Y.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.CarY, true);
			CG_Y.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.CarY, false);

			CG_Z.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.CarZ, true);
			CG_Z.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.CarZ, false);

			CG_Rotation.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.CarAngle, true);
			CG_Rotation.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.CarAngle, false);

			CG_CarColor1.Maximum = cc.Colors.Count - 1;
			CG_CarColor1.Minimum = -1;
			CG_CarColor2.Maximum = cc.Colors.Count - 1;
			CG_CarColor2.Minimum = -1;

			CG_AlarmProb.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.AlarmProbability, true);
			CG_AlarmProb.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.AlarmProbability, false);

			CG_LockProb.Maximum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.LockProbability, true);
			CG_LockProb.Minimum = (decimal)BExplorerLib.SaveData_GetParameterLimit ((UInt16)BExplorerLib.OpCodes.Generators_Base,
				(UInt16)BExplorerLib.GeneratorsParCodes.LockProbability, false);

			cp = new CoordsPicker (CG_X.Minimum, CG_X.Maximum, CG_Y.Minimum, CG_Y.Maximum, CG_Z.Minimum, CG_Z.Maximum,
				CG_Rotation.Minimum, CG_Rotation.Maximum);

			// Окончательная настройка
			SetState (false);	// Начальная блокировка

			LanguageCombo.Items.AddRange (Localization.LanguagesNames);
			try
				{
				LanguageCombo.SelectedIndex = (int)al;
				}
			catch
				{
				LanguageCombo.SelectedIndex = 0;
				}

			loading = false;
			}

		// Выбор файла сохранения для загрузки
		private void OpenFile_Click (object sender, EventArgs e)
			{
			OFDialog.FileName = "";
			OFDialog.ShowDialog ();
			}

		private void DefaultFileButton_Click (object sender, EventArgs e)
			{
			// Пробуем открыть файл из стандартного расположения
			OFDialog.FileName = savesDefaultPath + ((uint)OpenFileNumber.Value).ToString () + savesExtension;

			OFDialog_FileOk (null, null);
			}

		// Файл выбран
		private void OFDialog_FileOk (object sender, CancelEventArgs e)
			{
			// Загрузка файла сохранения
			Int16 errCode;

			// В случае ошибки вывести сообщение и прекратить исполнение программы
			SetState (false);	// Блокировать заранее
			if ((errCode = BExplorerLib.SaveData_LoadEx (OFDialog.FileName)) != 1)
				{
				MessageBox.Show (Localization.GetText ("SaveLoadingError", al) + BExplorerLib.SaveData_ErrorPromptEx (errCode),
					ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				SaveInfoLabel.Text = Localization.GetText ("SaveNotSpecified", al);

				return;
				}

			// В случае успеха
			SaveInfoLabel.Text = Localization.GetText ("CurrentSave", al) + BExplorerLib.SaveData_GetSaveInfoEx ();
			SetState (true);

			// Загрузка начальных параметров в поля формы
			LoadParameters ();
			}

		// Метод отвечает за получение одного параметра из структуры
		private bool GetParameterValue (UInt16 OpCode, UInt16 ParCode, out string Result)
			{
			Result = BExplorerLib.SaveData_GetParameterValue (OpCode, ParCode);
			if (!BExplorerLib.IsResultSuccessful (Result))
				{
				MessageBox.Show (Result, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				return false;
				}

			return true;
			}

		// Метод отвечает за установку нового значения параметра
		private void SetParameterValue (UInt16 OpCode, UInt16 ParCode, string NewValue)
			{
			string Result = BExplorerLib.SaveData_SetParameterValue (OpCode, ParCode, NewValue);

			if (!BExplorerLib.IsResultSuccessful (Result))
				MessageBox.Show (Result, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
			}

		// Загрузчик параметров
		private void LoadParameters ()
			{
			string s1, s2, s3;

			// Переход в режим загрузки
			loading = true;

			// Получение даты
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveYear, 0, out s1) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveMonth, 0, out s2) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveDay, 0, out s3))
				{
				loading = false;
				return;
				}

			DP_Date.Value = new System.DateTime ((int)decimal.Parse (s1), (int)decimal.Parse (s2), (int)decimal.Parse (s3));

			// Получение времени
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveHour, 0, out s1) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveMinute, 0, out s2) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveSecond, 0, out s3))
				{
				loading = false;
				return;
				}

			DP_Time.Value = new DateTime (2000, 1, 1, (int)decimal.Parse (s1), (int)decimal.Parse (s2), (int)decimal.Parse (s3));

			// Получение длины минуты
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.InGameMinuteLength, 0, out s1))
				{
				loading = false;
				return;
				}

			DP_IML.Value = decimal.Parse (s1);

			// Получение времени внутри игры
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.InGameHour, 0, out s1) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.InGameMinute, 0, out s2))
				{
				loading = false;
				return;
				}

			DP_GameTime.Value = new System.DateTime (2000, 1, 1, (decimal.Parse (s1) > 23) ? 23 : (int)decimal.Parse (s1),
				(decimal.Parse (s2) > 59) ? 59 : (int)decimal.Parse (s2), 0);

			// Получение скорости игры
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.GameSpeed, 0, out s1))
				{
				loading = false;
				return;
				}

			DP_GameSpeed.Value = decimal.Parse (s1);

			// Получение погоды
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.CurrentWeather, 0, out s1))
				{
				loading = false;
				return;
				}

			decimal d = decimal.Parse (s1);
			for (int i = 0; i < ParametersValues.Weathers.Length; i++)
				{
				if (d == ParametersValues.Weathers[i].ID)
					{
					DP_Weather.SelectedIndex = i;
					break;
					}
				}

			// Получение положения камеры
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.CarOverview, 0, out s1))
				{
				loading = false;
				return;
				}

			float f = float.Parse (s1);
			for (int i = 0; i < ParametersValues.CameraPositions.Length; i++)
				{
				if (f == (float)ParametersValues.CameraPositions[i].ID)
					{
					DP_CameraPos.SelectedIndex = i;
					break;
					}
				}

			// Получение состояния радио Cauffman cabs
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.CabsRadio, 0, out s1))
				{
				loading = false;
				return;
				}

			SBB_CabsRadio.Checked = (decimal.Parse (s1) != 0);

			// Получение величин здоровья и брони
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.MaxHealth, 0, out s1) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.MaxArmor, 0, out s2) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.CurrentArmor, 0, out s3))
				{
				loading = false;
				return;
				}

			PL_MaxHealth.Value = (decimal.Parse (s1) > PL_MaxHealth.Maximum) ? PL_MaxHealth.Maximum : decimal.Parse (s1);
			PL_MaxArmor.Value = (decimal.Parse (s2) > PL_MaxArmor.Maximum) ? PL_MaxArmor.Maximum : decimal.Parse (s2);
			PL_CurArmor.Value = decimal.Parse (s3);

			// Получение максимума звёзд розыска
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.MaxPoliceStars, 0, out s1))
				{
				loading = false;
				return;
				}

			PL_MWL.SelectedIndex = (int)decimal.Parse (s1);

			// Получение наличных
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.CurrentMoney, 0, out s1))
				{
				loading = false;
				return;
				}

			PL_CurMoney.Value = ((decimal.Parse (s1) > PL_CurMoney.Maximum) ? PL_CurMoney.Maximum : decimal.Parse (s1));

			// Получение костюма
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.PlayerSuit, 0, out s1))
				{
				loading = false;
				return;
				}

			for (int i = 0; i < ParametersValues.Suits.Length; i++)
				{
				if (s1 == ParametersValues.Suits[i].CodeName)
					{
					PL_Suit.SelectedIndex = i;
					break;
					}
				}

			// Получение флагов несгораемости, вечного бега и быстрой перезарядки
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.InfiniteRun, 0, out s1) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.FastReload, 0, out s2) ||
				!GetParameterValue ((UInt16)BExplorerLib.OpCodes.Fireproof, 0, out s3))
				{
				loading = false;
				return;
				}

			PL_InfRun.Checked = (decimal.Parse (s1) != 0);
			PL_FastReload.Checked = (decimal.Parse (s2) != 0);
			PL_Fireproof.Checked = (decimal.Parse (s3) != 0);

			// Получение флага бесконечных патронов
			if (!GetParameterValue ((UInt16)BExplorerLib.OpCodes.InfiniteAmmo, 0, out s1))
				{
				loading = false;
				return;
				}

			ST_InfBullets.Checked = (decimal.Parse (s1) != 0);

			// Завершение загрузки
			loading = false;

			// Выбор слота оружия (вызывает событие запроса имени оружия и числа патронов)
			WeaponsList.SelectedIndex = 0;
			WeaponsList_SelectedIndexChanged (null, null);

			// Выбор слота гаража (вызывает событие запроса параметров гаража)
			GaragesList.SelectedIndex = 0;
			GaragesList_SelectedIndexChanged (null, null);

			// Выбор слота накопителя (вызывает событие запроса параметров накопителя)
			pu = new Pickups ();
			AssetList.Items.Clear ();
			for (int i = 0; i < pu.ActiveAssetsCount; i++)
				AssetList.Items.Add (Localization.GetText ("AssetNumber", al) + (i + 1).ToString ());

			if (pu.ActiveAssetsCount > 0)
				{
				AssetList.Text = AssetList.Items[0].ToString ();
				AssetList.Enabled = PU_AssetValue.Enabled = PickupViewCoords.Enabled = true;
				}
			else
				{
				AssetList.Enabled = PU_AssetValue.Enabled = PickupViewCoords.Enabled = false;
				}
			AssetList_SelectedIndexChanged (null, null);

			// Выбор слота банды (вызывает событие запроса параметров банды)
			GangsList.SelectedIndex = 0;
			GangsList_SelectedIndexChanged (null, null);

			// Загрузка списка парковок и выбор слота
			cg = new CarGenerators ();
			CGCountLabel.Text = Localization.GetText ("CGLoaded", al) + cg.ActiveGeneratorsCount.ToString ();
			CarGenList.Value = 1;
			CarGenList_ValueChanged (null, null);

			// Загрузка ToDo-статуса
			tds = new ToDoStatus ();
			ToDoStatusView.Items.Clear ();

			for (int i = 0; i < tds.Elements.Count; i++)
				{
				if (!tds.Elements[i].Completed)
					{
					ToDoStatusView.Items.Add (tds.Elements[i].ElementDescription);
					}
				}

			if (ToDoStatusView.Items.Count == 0)
				{
				ToDoStatusView.Items.Add (Localization.GetText ("SaveCompleted", al));
				DangerousReset.Enabled = AbortSorting.Enabled = ST_InfBullets.Enabled = true;	// Только при полном прохождении
				}
			}

		// Выбор места сохранения файла
		private void SaveFileButton_Click (object sender, EventArgs e)
			{
			// Запись данных генераторов авто
			cg.SaveGenerators (!AbortSorting.Checked);
			CGCountLabel.Text = Localization.GetText ("CGSaved", al) + cg.ActiveGeneratorsCount.ToString ();

			// Отображение диалога
			SFDialog.FileName = "";
			SFDialog.ShowDialog ();
			}

		private void UpdateDefaultButton_Click (object sender, EventArgs e)
			{
			// Запись данных генераторов авто
			cg.SaveGenerators (!AbortSorting.Checked);
			CGCountLabel.Text = Localization.GetText ("CGSaved", al) + cg.ActiveGeneratorsCount.ToString ();

			// Пробуем сохранить файл в стандартном расположении
			SFDialog.FileName = savesDefaultPath + ((uint)OpenFileNumber.Value).ToString () + savesExtension;

			SFDialog_FileOk (null, null);
			}

		// Место выбрано
		private void SFDialog_FileOk (object sender, CancelEventArgs e)
			{
			string msg = BExplorerLib.SaveData_SaveParametersFile (BExplorerLib.SaveableParameters.SaveFile, SFDialog.FileName);

			if (BExplorerLib.IsResultSuccessful (msg))
				{
				MessageBox.Show (msg, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Information);

				// Перезагрузка файла
				LoadParameters ();
				}
			else
				{
				MessageBox.Show (Localization.GetText ("SaveSavingError", al) + msg, ProgramDescription.AssemblyTitle,
					MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				}
			}

		// Кнопка выхода
		private void ExitButton_Click (object sender, EventArgs e)
			{
			this.Close ();
			}

		private void MainForm_FormClosing (object sender, FormClosingEventArgs e)
			{
			e.Cancel = (error == 0) && (MessageBox.Show (Localization.GetText ("ChangesSaved", al),
				ProgramDescription.AssemblyTitle, MessageBoxButtons.YesNo, MessageBoxIcon.Question,
				MessageBoxDefaultButton.Button2) == DialogResult.No);
			}

		// Установка всех настроечных контролов в состояние доступен/недоступен
		private void SetState (bool State)
			{
			SaveFileButton.Enabled =
				UpdateDefaultFileButton.Enabled =
				RecommendedSettings.Enabled = State;

			/*DP_Date.Enabled =
				DP_Time.Enabled =
				DP_IML.Enabled =
				DP_GameTime.Enabled =
				DP_GameSpeed.Enabled =
				DP_Weather.Enabled =
				DP_CameraPos.Enabled =
				SBB_CabsRadio.Enabled = State;*/
			DPTab.Enabled = State;

			/*PL_MaxHealth.Enabled =
				PL_MaxArmor.Enabled =
				PL_CurArmor.Enabled =
				PL_MWL.Enabled =
				PL_CurMoney.Enabled =
				PL_Suit.Enabled =
				PL_InfRun.Enabled =
				PL_FastReload.Enabled =
				PL_Fireproof.Enabled =
				PL_Bullets.Enabled =
				PL_Weapon.Enabled =
				WeaponsList.Enabled = State;*/
			PLTab.Enabled = State;

			/*GaragesList.Enabled =
				GR_CarModel.Enabled =
				GR_CarColor1.Enabled =
				GR_CarColor2.Enabled =
				GR_Radio.Enabled =
				GR_Bomb.Enabled =
				GR_BulletsProof.Enabled =
				GR_DamageProof.Enabled =
				GR_ExplProof.Enabled =
				GR_FireProof.Enabled =
				LoadGarages.Enabled =
				SaveGarages.Enabled = State;*/
			GRTab.Enabled = State;

			PUTab.Enabled = State;

			/*GangsList.Enabled =
				GD_CarModel.Enabled =
				GD_PedModel1.Enabled =
				GD_PedModel2.Enabled =
				GD_Weapon1.Enabled =
				GD_Weapon2.Enabled =

				SaveStats.Enabled =
				LoadStats.Enabled =
				ToDoStatusView.Enabled = State;*/

			GDTab.Enabled = STTab.Enabled = State;

			/*CarGenList.Enabled =
				CG_AlarmProb.Enabled =
				CG_AllowSpawn.Enabled =
				CG_CarColor1.Enabled =
				CG_CarColor2.Enabled =
				CG_CarModel.Enabled =
				CG_ForceSpawn.Enabled =
				CG_LockProb.Enabled =
				CG_Rotation.Enabled =
				CG_X.Enabled =
				CG_Y.Enabled =
				CG_Z.Enabled = State;

			CarGenGetCoords.Enabled =
				LoadCG.Enabled =
				SaveCG.Enabled = State;*/
			CGTab.Enabled = State;

			// Для этих элементов в общем порядке допустима только блокировка
			if (State == false)
				AbortSorting.Enabled = ST_InfBullets.Enabled = DangerousReset.Enabled = State;
			}

		// Изменена дата
		private void DP_Date_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveYear, 0, DP_Date.Value.Year.ToString ());
			SetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveMonth, 0, DP_Date.Value.Month.ToString ());
			SetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveDay, 0, DP_Date.Value.Day.ToString ());
			}

		// Изменено время
		private void DP_Time_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveHour, 0, DP_Time.Value.Hour.ToString ());
			SetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveMinute, 0, DP_Time.Value.Minute.ToString ());
			SetParameterValue ((UInt16)BExplorerLib.OpCodes.SaveSecond, 0, DP_Time.Value.Second.ToString ());
			}

		// Изменена длительность минуты в игре
		private void DP_IML_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.InGameMinuteLength, 0, DP_IML.Value.ToString ());
			}

		// Изменено время в игре
		private void DP_GameTime_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.InGameHour, 0, DP_GameTime.Value.Hour.ToString ());
			SetParameterValue ((UInt16)BExplorerLib.OpCodes.InGameMinute, 0, DP_GameTime.Value.Minute.ToString ());
			}

		// Изменена скорость игры
		private void DP_GameSpeed_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.GameSpeed, 0, DP_GameSpeed.Value.ToString ());
			}

		// Изменена текущая погода
		private void DP_Weather_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.CurrentWeather, 0,
				ParametersValues.Weathers[DP_Weather.SelectedIndex].ID.ToString ());
			}

		// Изменено положение камеры
		private void DP_CameraPos_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.CarOverview, 0,
				ParametersValues.CameraPositions[DP_CameraPos.SelectedIndex].ID.ToString ());
			}

		// Изменено состояние радио Caufman cabs
		private void SBB_CabsRadio_CheckedChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.CabsRadio, 0, SBB_CabsRadio.Checked ? "1" : "0");
			}

		// Изменена величина максимального здоровья
		private void PL_MaxHealth_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.MaxHealth, 0, PL_MaxHealth.Value.ToString ());
			}

		// Изменена величина максимальной брони
		private void PL_MaxArmor_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.MaxArmor, 0, PL_MaxArmor.Value.ToString ());
			}

		// Изменена величина текущей брони
		private void PL_CurArmor_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.CurrentArmor, 0, PL_CurArmor.Value.ToString ());
			}

		// Изменён максимум звёзд розыска
		private void PL_MWL_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.MaxPoliceStars, 0, PL_MWL.SelectedIndex.ToString ());
			}

		// Изменена сумма наличных
		private void PL_CurMoney_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.CurrentMoney, 0, PL_CurMoney.Value.ToString ());
			}

		// Изменён костюм
		private void PL_Suit_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.PlayerSuit, 0, ParametersValues.Suits[PL_Suit.SelectedIndex].CodeName);
			}

		// Изменён флаг вечного бега
		private void PL_InfRun_CheckedChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.InfiniteRun, 0, PL_InfRun.Checked ? "1" : "0");
			}

		// Изменён флаг быстрой перезарядки
		private void PL_FastReload_CheckedChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.FastReload, 0, PL_FastReload.Checked ? "1" : "0");
			}

		// Изменён флаг несгораемости
		private void PL_Fireproof_CheckedChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.Fireproof, 0, PL_Fireproof.Checked ? "1" : "0");
			}

		// Выбран слот оружия
		private void WeaponsList_SelectedIndexChanged (object sender, EventArgs e)
			{
			loading = true;

			string s1, s2;
			if (!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.PlayerWeapons_Base + WeaponsList.SelectedIndex),
				(UInt16)BExplorerLib.WeaponsParCodes.WeaponType, out s1) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.PlayerWeapons_Base + WeaponsList.SelectedIndex),
				(UInt16)BExplorerLib.WeaponsParCodes.WeaponAmmo, out s2))
				{
				loading = false;
				return;
				}

			decimal d = decimal.Parse (s1);
			for (int i = 0; i < ParametersValues.Weapons.Length; i++)
				{
				if (d == ParametersValues.Weapons[i].ID)
					{
					PL_Weapon.SelectedIndex = i;
					break;
					}
				}

			PL_Bullets.Value = (decimal.Parse (s2) > PL_Bullets.Maximum) ? PL_Bullets.Maximum : decimal.Parse (s2);

			loading = false;
			}

		// Изменён тип оружия
		private void PL_Weapon_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.PlayerWeapons_Base + WeaponsList.SelectedIndex),
				(UInt16)BExplorerLib.WeaponsParCodes.WeaponType, ParametersValues.Weapons[PL_Weapon.SelectedIndex].ID.ToString ());
			}

		// Изменено число патронов
		private void PL_Bullets_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.PlayerWeapons_Base + WeaponsList.SelectedIndex),
				(UInt16)BExplorerLib.WeaponsParCodes.WeaponAmmo, PL_Bullets.Value.ToString ());
			}

		// Загрузка статистики
		private void LoadStats_Click (object sender, EventArgs e)
			{
			OStatsDialog.FileName = "";
			OStatsDialog.ShowDialog ();
			}

		// Файл выбран
		private void OStatsDialog_FileOk (object sender, CancelEventArgs e)
			{
			// Загрузка файла статистики
			string msg = BExplorerLib.SaveData_LoadParametersFile (BExplorerLib.LoadableParameters.Stats, OStatsDialog.FileName);

			// В случае ошибки вывести сообщение
			if (BExplorerLib.IsResultSuccessful (msg))
				{
				MessageBox.Show (msg, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Information);
				}
			// В противном случае
			else
				{
				MessageBox.Show (Localization.GetText ("StatsLoadingError", al) + msg, ProgramDescription.AssemblyTitle,
					MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				}
			}

		// Выгрузка статистики
		private void SaveStats_Click (object sender, EventArgs e)
			{
			SStatsDialog.FileName = "";
			SStatsDialog.ShowDialog ();
			}

		// Файл выбран
		private void SStatsDialog_FileOk (object sender, CancelEventArgs e)
			{
			// Загрузка файла статистики
			string msg = BExplorerLib.SaveData_SaveParametersFile (BExplorerLib.SaveableParameters.Stats, SStatsDialog.FileName);

			// В случае ошибки вывести сообщение
			if (BExplorerLib.IsResultSuccessful (msg))
				{
				MessageBox.Show (msg, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Information);
				}
			// В противном случае
			else
				{
				MessageBox.Show (Localization.GetText ("StatsSavingError", al) + msg, ProgramDescription.AssemblyTitle,
					MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				}
			}

		// Выбран слот гаража
		private void GaragesList_SelectedIndexChanged (object sender, EventArgs e)
			{
			loading = true;

			string model, imm, c1, c2, radio, bomb;
			if (!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.CarModel, out model) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.Immunity, out imm) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.PrimaryColor, out c1) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.SecondaryColor, out c2) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.RadioStation, out radio) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.BombType, out bomb))
				{
				loading = false;
				return;
				}

			decimal d = decimal.Parse (model);
			for (int i = 0; i < ParametersValues.CarsForGarages.Length; i++)
				{
				if (d == ParametersValues.CarsForGarages[i].ID)
					{
					GR_CarModel.SelectedIndex = i;
					break;
					}
				}

			GR_CarColor1.Value = (decimal.Parse (c1) > GR_CarColor1.Maximum) ? GR_CarColor1.Maximum : decimal.Parse (c1);
			GR_CarColor2.Value = (decimal.Parse (c2) > GR_CarColor1.Maximum) ? GR_CarColor2.Maximum : decimal.Parse (c2);

			d = decimal.Parse (radio);
			for (int i = 0; i < ParametersValues.Radios.Length; i++)
				{
				if (d == ParametersValues.Radios[i].ID)
					{
					GR_Radio.SelectedIndex = i;
					break;
					}
				}

			d = decimal.Parse (bomb);
			for (int i = 0; i < ParametersValues.Bombs.Length; i++)
				{
				if (d == ParametersValues.Bombs[i].ID)
					{
					GR_Bomb.SelectedIndex = i;
					break;
					}
				}

			d = decimal.Parse (imm);
			GR_BulletsProof.Checked = (((int)d & 0x1) != 0);
			GR_FireProof.Checked = (((int)d & 0x2) != 0);
			GR_ExplProof.Checked = (((int)d & 0x4) != 0);
			GR_DamageProof.Checked = (((int)d & 0x8) != 0);

			loading = false;
			}

		// Изменена модель авто
		private void GR_CarModel_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.CarModel, ParametersValues.CarsForGarages[GR_CarModel.SelectedIndex].ID.ToString ());
			}

		// Изменены цвета авто
		private void GR_CarColor1_ValueChanged (object sender, EventArgs e)
			{
			GDColorLabel1.ForeColor = cc.Colors[(int)GR_CarColor1.Value];

			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.PrimaryColor, GR_CarColor1.Value.ToString ());
			}

		private void GR_CarColor2_ValueChanged (object sender, EventArgs e)
			{
			GDColorLabel2.ForeColor = cc.Colors[(int)GR_CarColor2.Value];

			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.SecondaryColor, GR_CarColor2.Value.ToString ());
			}

		// Изменена радиостанция
		private void GR_Radio_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.RadioStation, ParametersValues.Radios[GR_Radio.SelectedIndex].ID.ToString ());
			}

		// Изменён вид минирования
		private void GR_Bomb_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.BombType, ParametersValues.Bombs[GR_Bomb.SelectedIndex].ID.ToString ());
			}

		// Изменены флаги защиты
		private void GR_FireProof_CheckedChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			int f = 0;
			if (GR_BulletsProof.Checked)
				f |= 0x1;

			if (GR_FireProof.Checked)
				f |= 0x2;

			if (GR_ExplProof.Checked)
				f |= 0x4;

			if (GR_DamageProof.Checked)
				f |= 0x8;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Garages_Base + GaragesList.SelectedIndex),
				(UInt16)BExplorerLib.GaragesParCodes.Immunity, f.ToString ());
			}

		// Выбран денежный накопитель
		private void AssetList_SelectedIndexChanged (object sender, EventArgs e)
			{
			loading = true;

			if (AssetList.SelectedIndex >= 0)
				PU_AssetValue.Value = pu.GetAssetMaximum (AssetList.SelectedIndex);

			loading = false;
			}

		// Изменено значение накопителя
		private void PU_AssetValue_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			if (AssetList.SelectedIndex >= 0)
				pu.SetAssetMaximum (AssetList.SelectedIndex, (uint)PU_AssetValue.Value);
			}

		// Кнопка позволяет посмотреть, где находится накопитель
		private void PickupViewCoords_Click (object sender, EventArgs e)
			{
			if (AssetList.SelectedIndex >= 0)
				cp.PickCoords ((decimal)pu.GetAssetX (AssetList.SelectedIndex), (decimal)pu.GetAssetY (AssetList.SelectedIndex),
					(decimal)pu.GetAssetZ (AssetList.SelectedIndex), 0, true, al);
			}

		// Выбрана банда для редактирования
		private void GangsList_SelectedIndexChanged (object sender, EventArgs e)
			{
			loading = true;

			string car, p1, p2, w1, w2;
			if (!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.CarModel, out car) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.PrimaryPedModel, out p1) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.SecondaryPedModel, out p2) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.PrimaryWeapon, out w1) ||
				!GetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.SecondaryWeapon, out w2))
				{
				loading = false;
				return;
				}

			decimal d1 = decimal.Parse (car);
			for (int i = 0; i < ParametersValues.CarsForGangs.Length; i++)
				{
				if (d1 == ParametersValues.CarsForGangs[i].ID)
					{
					GD_CarModel.SelectedIndex = i;
					break;
					}
				}

			GD_PedModel1.Value = (decimal.Parse (p1) > GD_PedModel1.Maximum) ? GD_PedModel1.Maximum : decimal.Parse (p1);
			GD_PedModel2.Value = (decimal.Parse (p2) > GD_PedModel2.Maximum) ? GD_PedModel2.Maximum : decimal.Parse (p2);

			d1 = decimal.Parse (w1);
			decimal d2 = decimal.Parse (w2);
			for (int i = 0; i < ParametersValues.Weapons.Length; i++)
				{
				if (d1 == ParametersValues.Weapons[i].ID)
					GD_Weapon1.SelectedIndex = i;

				if (d2 == ParametersValues.Weapons[i].ID)
					GD_Weapon2.SelectedIndex = i;
				}

			loading = false;
			}

		// Выбрана модель авто
		private void GD_CarModel_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.CarModel, ParametersValues.CarsForGangs[GD_CarModel.SelectedIndex].ID.ToString ());
			}

		// Изменён скин
		private void GD_PedModel1_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.PrimaryPedModel, GD_PedModel1.Value.ToString ());
			}

		private void GD_PedModel2_ValueChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.SecondaryPedModel, GD_PedModel2.Value.ToString ());
			}

		// Выбрано оружие
		private void GD_Weapon1_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.PrimaryWeapon, ParametersValues.Weapons[GD_Weapon1.SelectedIndex].ID.ToString ());
			}

		private void GD_Weapon2_SelectedIndexChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)((int)BExplorerLib.OpCodes.Gangs_Base + GangsList.SelectedIndex),
				(UInt16)BExplorerLib.GangsParCodes.SecondaryWeapon, ParametersValues.Weapons[GD_Weapon2.SelectedIndex].ID.ToString ());
			}

		// Выбор слота парковки
		private void CarGenList_ValueChanged (object sender, EventArgs e)
			{
			loading = true;

			for (int i = 0; i < ParametersValues.CarsForCG.Length; i++)
				{
				if (cg.GetGeneratorData ((int)CarGenList.Value).CarModel == ParametersValues.CarsForCG[i].ID)
					{
					CG_CarModel.Text = ParametersValues.CarsForCG[i].Name;
					break;
					}
				}

			CG_X.Value = (decimal)cg.GetGeneratorData ((int)CarGenList.Value).X;
			CG_Y.Value = (decimal)cg.GetGeneratorData ((int)CarGenList.Value).Y;
			CG_Z.Value = (decimal)cg.GetGeneratorData ((int)CarGenList.Value).Z;
			CG_Rotation.Value = (decimal)cg.GetGeneratorData ((int)CarGenList.Value).Rotation;

			CG_AllowSpawn.Checked = (cg.GetGeneratorData ((int)CarGenList.Value).AllowSpawn < 0);
			CG_ForceSpawn.Checked = (cg.GetGeneratorData ((int)CarGenList.Value).ForceSpawn > 0);

			CG_CarColor1.Value = (cg.GetGeneratorData ((int)CarGenList.Value).Color1 > CG_CarColor1.Maximum) ?
				CG_CarColor1.Maximum : cg.GetGeneratorData ((int)CarGenList.Value).Color1;
			CG_CarColor2.Value = (cg.GetGeneratorData ((int)CarGenList.Value).Color2 > CG_CarColor2.Maximum) ?
				CG_CarColor2.Maximum : cg.GetGeneratorData ((int)CarGenList.Value).Color2;

			CG_AlarmProb.Value = cg.GetGeneratorData ((int)CarGenList.Value).AlarmProbability;
			CG_LockProb.Value = cg.GetGeneratorData ((int)CarGenList.Value).LockProbability;

			loading = false;

			CGColorLabel1.ForeColor = (CG_CarColor1.Value >= 0) ? cc.Colors[(int)CG_CarColor1.Value] : Color.FromName ("ControlDark");
			CGColorLabel2.ForeColor = (CG_CarColor2.Value >= 0) ? cc.Colors[(int)CG_CarColor2.Value] : Color.FromName ("ControlDark");
			}

		// Изменены настройки авто
		private void CG_CarModel_SelectedIndexChanged (object sender, EventArgs e)
			{
			CGColorLabel1.ForeColor = (CG_CarColor1.Value >= 0) ? cc.Colors[(int)CG_CarColor1.Value] : Color.FromName ("ControlDark");
			CGColorLabel2.ForeColor = (CG_CarColor2.Value >= 0) ? cc.Colors[(int)CG_CarColor2.Value] : Color.FromName ("ControlDark");

			if (loading)
				return;

			cg.SetGeneratorData ((int)CarGenList.Value, new CarGenerators.CGData ((Int32)ParametersValues.CarsForCG[CG_CarModel.SelectedIndex].ID,
				(float)CG_X.Value, (float)CG_Y.Value, (float)CG_Z.Value, (float)CG_Rotation.Value, (Int16)(CG_AllowSpawn.Checked ? -1 : 0),
				(short)CG_CarColor1.Value, (short)CG_CarColor2.Value, (uint)CG_AlarmProb.Value, (uint)CG_LockProb.Value,
				CG_ForceSpawn.Checked ? 1U : 0U));
			}

		// Выбор координат
		private void CarGenGetCoords_Click (object sender, EventArgs e)
			{
			// Запуск выбора
			cp.PickCoords (CG_X.Value, CG_Y.Value, CG_Z.Value, CG_Rotation.Value, false, al);

			// Получение результатов
			loading = true;		// Чтобы не выполнять одно и то же 4 раза
			CG_X.Value = cp.PickedX;
			CG_Y.Value = cp.PickedY;
			CG_Z.Value = cp.PickedZ;
			loading = false;
			CG_Rotation.Value = cp.PickedRot;
			}

		// Загрузка параметров парковок
		private void LoadCG_Click (object sender, EventArgs e)
			{
			OCGDialog.FileName = "";
			OCGDialog.ShowDialog ();
			}

		// Файл выбран
		private void OCGDialog_FileOk (object sender, CancelEventArgs e)
			{
			// Загрузка файла статистики
			string msg = BExplorerLib.SaveData_LoadParametersFile (BExplorerLib.LoadableParameters.Generators, OCGDialog.FileName);

			// В случае ошибки вывести сообщение
			if (BExplorerLib.IsResultSuccessful (msg))
				{
				MessageBox.Show (msg, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Information);
				}
			// В противном случае
			else
				{
				MessageBox.Show (Localization.GetText ("CGLoadingError", al) + msg, ProgramDescription.AssemblyTitle,
					MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				}

			// Обновление загруженных данных сохранения
			LoadParameters ();
			}

		// Выгрузка параметров парковок
		private void SaveCG_Click (object sender, EventArgs e)
			{
			// Запись параметров
			cg.SaveGenerators (!AbortSorting.Checked);
			CGCountLabel.Text = Localization.GetText ("CGSaved", al) + cg.ActiveGeneratorsCount.ToString ();

			// Вызов окна
			SCGDialog.FileName = "";
			SCGDialog.ShowDialog ();
			}

		// Файл выбран
		private void SCGDialog_FileOk (object sender, CancelEventArgs e)
			{
			// Загрузка файла статистики
			string msg = BExplorerLib.SaveData_SaveParametersFile (BExplorerLib.SaveableParameters.Generators, SCGDialog.FileName);

			// В случае ошибки вывести сообщение
			if (BExplorerLib.IsResultSuccessful (msg))
				{
				MessageBox.Show (msg, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Information);
				}
			// В противном случае
			else
				{
				MessageBox.Show (Localization.GetText ("CGSavingError", al) + msg, ProgramDescription.AssemblyTitle,
					MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				}
			}

		// Установка флага бесконечных патронов
		private void ST_InfBullets_CheckedChanged (object sender, EventArgs e)
			{
			if (loading)
				return;

			SetParameterValue ((UInt16)BExplorerLib.OpCodes.InfiniteAmmo, 0, ST_InfBullets.Checked ? "1" : "0");
			}

		// Сброс потенциально опасных параметров
		private void DangerousReset_Click (object sender, EventArgs e)
			{
			// Контроль
			if (MessageBox.Show (Localization.GetText ("DangerousResetMessage", al), ProgramDescription.AssemblyTitle,
				MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.No)
				return;

			// Выполнение
			string msg = BExplorerLib.SaveData_FixFile ();
			MessageBox.Show (msg, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Information);
			}

		// Загрузка параметров гаражей
		private void LoadGarages_Click (object sender, EventArgs e)
			{
			OGDialog.FileName = "";
			OGDialog.ShowDialog ();
			}

		// Файл выбран
		private void OGDialog_FileOk (object sender, CancelEventArgs e)
			{
			// Загрузка файла статистики
			string msg = BExplorerLib.SaveData_LoadParametersFile (BExplorerLib.LoadableParameters.Garages, OGDialog.FileName);

			// В случае ошибки вывести сообщение
			if (BExplorerLib.IsResultSuccessful (msg))
				{
				MessageBox.Show (msg, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Information);
				}
			// В противном случае
			else
				{
				MessageBox.Show (Localization.GetText ("GRLoadingError", al) + msg, ProgramDescription.AssemblyTitle,
					MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				}

			// Обновление загруженных данных сохранения
			LoadParameters ();
			}

		// Выгрузка параметров парковок
		private void SaveGarages_Click (object sender, EventArgs e)
			{
			// Вызов окна
			SGDialog.FileName = "";
			SGDialog.ShowDialog ();
			}

		// Файл выбран
		private void SGDialog_FileOk (object sender, CancelEventArgs e)
			{
			// Загрузка файла статистики
			string msg = BExplorerLib.SaveData_SaveParametersFile (BExplorerLib.SaveableParameters.Garages, SGDialog.FileName);

			// В случае ошибки вывести сообщение
			if (BExplorerLib.IsResultSuccessful (msg))
				{
				MessageBox.Show (msg, ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Information);
				}
			// В противном случае
			else
				{
				MessageBox.Show (Localization.GetText ("GRSavingError", al) + msg, ProgramDescription.AssemblyTitle,
					MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				}
			}

		// Применение рекомендуемых настроек
		private void RecommendedSettings_Click (object sender, EventArgs e)
			{
			DP_Date.Value = DP_Time.Value = DateTime.Now;
			DP_GameTime.Value = new DateTime (2000, 1, 1, 5, 1, 0);
			DP_Weather.SelectedIndex = 0;
			PL_CurArmor.Value = PL_CurArmor.Maximum;
			PL_MWL.SelectedIndex = 0;
			}

		// Отображение сведений о программе
		private void BExplorerForm_HelpButtonClicked (object sender, CancelEventArgs e)
			{
			e.Cancel = true;

			ProgramDescription.ShowAbout (false);
			}

		// Выбор языка интерфейса
		private void LanguageCombo_SelectedIndexChanged (object sender, EventArgs e)
			{
			// Сохранение языка
			Localization.CurrentLanguage = al = (SupportedLanguages)LanguageCombo.SelectedIndex;

			// Настройка списков
			string s;

			for (int i = 0; i < ParametersValues.Weathers.Length; i++)
				{
				s = Localization.GetText ("Weathers_" + ParametersValues.Weathers[i].Name, al);
				if (DP_Weather.Items.Count < ParametersValues.Weathers.Length)
					DP_Weather.Items.Add (s);
				else
					DP_Weather.Items[i] = s;
				}

			for (int i = 0; i < ParametersValues.CameraPositions.Length; i++)
				{
				s = Localization.GetText ("CameraPositions_" + ParametersValues.CameraPositions[i].Name, al);
				if (DP_CameraPos.Items.Count < ParametersValues.CameraPositions.Length)
					DP_CameraPos.Items.Add (s);
				else
					DP_CameraPos.Items[i] = s;
				}

			for (int i = 0; i < ParametersValues.Suits.Length; i++)
				{
				s = Localization.GetText ("Suits_" + ParametersValues.Suits[i].Name, al);
				if (PL_Suit.Items.Count < ParametersValues.Suits.Length)
					PL_Suit.Items.Add (s);
				else
					PL_Suit.Items[i] = s;
				}

			for (int i = 0; i < BExplorerLib.WeaponsCount; i++)
				{
				s = Localization.GetText ("WeaponSlot", al) + (i + 1).ToString ();
				if (WeaponsList.Items.Count < BExplorerLib.WeaponsCount)
					WeaponsList.Items.Add (s);
				else
					WeaponsList.Items[i] = s;
				}

			for (int i = 0; i < ParametersValues.Weapons.Length; i++)
				{
				s = Localization.GetText ("Weapons_" + ParametersValues.Weapons[i].Name, al);
				if (PL_Weapon.Items.Count < ParametersValues.Weapons.Length)
					{
					PL_Weapon.Items.Add (s);
					GD_Weapon1.Items.Add (s);
					GD_Weapon2.Items.Add (s);
					}
				else
					{
					PL_Weapon.Items[i] = s;
					GD_Weapon1.Items[i] = s;
					GD_Weapon2.Items[i] = s;
					}
				}

			for (int i = 0; i < BExplorerLib.GaragesCount; i++)
				{
				s = Localization.GetText ("Garages_" + (i + 1).ToString (), al);
				if (GaragesList.Items.Count < BExplorerLib.GaragesCount)
					GaragesList.Items.Add (s);
				else
					GaragesList.Items[i] = s;
				}

			for (int i = 0; i < ParametersValues.Bombs.Length; i++)
				{
				s = Localization.GetText ("Bombs_" + ParametersValues.Bombs[i].Name, al);
				if (GR_Bomb.Items.Count < ParametersValues.Bombs.Length)
					GR_Bomb.Items.Add (s);
				else
					GR_Bomb.Items[i] = s;
				}

			for (int i = 0; i < BExplorerLib.GangsCount; i++)
				{
				s = Localization.GetText ("Gangs_" + (i + 1).ToString (), al);
				if (GangsList.Items.Count < BExplorerLib.GangsCount)
					GangsList.Items.Add (s);
				else
					GangsList.Items[i] = s;
				}

			// Настройка диалогов
			OFDialog.Filter = SFDialog.Filter = string.Format (Localization.GetText ("OFDialogFilter", al), savesExtension);
			OStatsDialog.Filter = SStatsDialog.Filter = Localization.GetText ("OStatsDialogFilter", al);
			OCGDialog.Filter = SCGDialog.Filter = Localization.GetText ("OCGDialogFilter", al);
			OGDialog.Filter = SGDialog.Filter = Localization.GetText ("OGDialogFilter", al);

			OFDialog.Title = OStatsDialog.Title = OCGDialog.Title = OGDialog.Title = Localization.GetText ("OFDialogTitle", al);
			SFDialog.Title = SStatsDialog.Title = SCGDialog.Title = SGDialog.Title = Localization.GetText ("SFDialogTitle", al);

			// Настройка контролов
			Localization.SetControlsText (FileTab, al);
			Localization.SetControlsText (DPTab, al);
			Localization.SetControlsText (PLTab, al);
			Localization.SetControlsText (GRTab, al);
			LoadGarages.Text = Localization.GetText ("LoadParameters", al);
			SaveGarages.Text = Localization.GetText ("SaveParameters", al);
			Localization.SetControlsText (PUTab, al);
			Localization.SetControlsText (GDTab, al);
			Localization.SetControlsText (CGTab, al);
			LoadCG.Text = Localization.GetText ("LoadParameters", al);
			SaveCG.Text = Localization.GetText ("SaveParameters", al);
			Localization.SetControlsText (STTab, al);

			FileTab.Text = Localization.GetText ("MainTab_FileTab", al);
			DPTab.Text = Localization.GetText ("MainTab_DPTab", al);
			PLTab.Text = Localization.GetText ("MainTab_PLTab", al);
			GRTab.Text = Localization.GetText ("MainTab_GRTab", al);
			PUTab.Text = Localization.GetText ("MainTab_PUTab", al);
			GDTab.Text = Localization.GetText ("MainTab_GDTab", al);
			CGTab.Text = Localization.GetText ("MainTab_CGTab", al);
			STTab.Text = Localization.GetText ("MainTab_STTab", al);

			if (DPTab.Enabled)
				SaveInfoLabel.Text = Localization.GetText ("CurrentSave", al) + BExplorerLib.SaveData_GetSaveInfoEx ();
			else
				SaveInfoLabel.Text = Localization.GetText ("SaveNotSpecified", al);
			}
		}
	}
