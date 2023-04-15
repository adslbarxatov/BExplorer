using System;
using System.IO;
using System.Windows.Forms;

namespace RD_AAOW
	{
	/// <summary>
	/// Класс описывает точку входа приложения
	/// </summary>
	public static class BExplorerProgram
		{
		/// <summary>
		/// Главная точка входа для приложения
		/// </summary>
		[STAThread]
		public static void Main (string[] args)
			{
			// Инициализация
			Application.EnableVisualStyles ();
			Application.SetCompatibleTextRenderingDefault (false);

			// Язык интерфейса и контроль XPUN
			if (!Localization.IsXPUNClassAcceptable)
				return;

			// Проверка запуска единственной копии
			if (!RDGenerics.IsAppInstanceUnique (true))
				return;

			// Проверка наличия компонентов программы
			if (!File.Exists (RDGenerics.AppStartupPath + ProgramDescription.AssemblyLibName))
				{
				if (RDGenerics.MessageBox (RDMessageTypes.Question,
					string.Format (Localization.GetText ("ComponentMissing"), ProgramDescription.AssemblyLibName),
					Localization.GetDefaultText (LzDefaultTextValues.Button_Yes),
					Localization.GetDefaultText (LzDefaultTextValues.Button_No)) ==
					RDMessageButtons.ButtonOne)
					{
					AboutForm af = new AboutForm (null);
					}

				return;
				}

			// Отображение справки и запроса на принятие Политики
			if (!RDGenerics.AcceptEULA ())
				return;
			RDGenerics.ShowAbout (true);

			// Запуск
			string fileName = "";
			if (args.Length > 0)
				fileName = args[0];

			Application.Run (new BExplorerForm (fileName));
			}
		}
	}
