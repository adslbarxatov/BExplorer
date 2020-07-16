using System;
using System.IO;
using System.Threading;
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
		public static void Main ()
			{
			// Проверка запуска единственной копии
			bool result;
			Mutex instance = new Mutex (true, ProgramDescription.AssemblyTitle, out result);
			if (!result)
				{
				MessageBox.Show (string.Format (Localization.GetText ("AlreadyStarted", Localization.CurrentLanguage),
					ProgramDescription.AssemblyTitle),
					ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				return;
				}

			// Проверка наличия компонентов программы
			if (!File.Exists (Application.StartupPath + "\\" + ProgramDescription.AssemblyLibName))
				{
				if (MessageBox.Show (string.Format (Localization.GetText ("ComponentMissing", Localization.CurrentLanguage),
					ProgramDescription.AssemblyLibName),
					ProgramDescription.AssemblyTitle, MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation) == DialogResult.Yes)
					{
					AboutForm af = new AboutForm (null);
					}

				return;
				}

			// Запуск
			Application.EnableVisualStyles ();
			Application.SetCompatibleTextRenderingDefault (false);
			Application.Run (new BExplorerForm ());
			}
		}
	}
