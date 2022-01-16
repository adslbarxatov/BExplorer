using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace RD_AAOW
	{
	/// <summary>
	/// Класс обеспечивает доступ к списку цветов транспортных средств
	/// </summary>
	public class CarColors
		{
		/// <summary>
		/// Возвращает имя файла-списка цветов транспортных средств
		/// </summary>
		public const string ColorsFile = "carcols.dat";

		/// <summary>
		/// Возвращает список полученных цветов
		/// </summary>
		public List<Color> Colors
			{
			get
				{
				return colors;
				}
			}
		private List<Color> colors = new List<Color> ();

		/// <summary>
		/// Конструктор. Загружает список цветов из расположения приложения
		/// </summary>
		/// <param name="Error">Возвращает код ошибки или 0 в случае успеха</param>
		public CarColors (out int Error)
			{
			// Попытка открытия файла
			FileStream FS = null;
			try
				{
				FS = new FileStream (CarColorsPath, FileMode.Open);
				}
			catch
				{
				// Запрос имени файла
				SupportedLanguages al = Localization.CurrentLanguage;

				OpenFileDialog ofd = new OpenFileDialog ();
				ofd.Filter = string.Format (Localization.GetText ("CarColorsFilter", al), ColorsFile);
				ofd.Title = string.Format (Localization.GetText ("CarColorsTitle", al), ColorsFile);
				if (ofd.ShowDialog () != DialogResult.OK)
					{
					Error = -1;
					return;
					}

				CarColorsPath = ofd.FileName;
				ofd.Dispose ();

				// Повторная попытка
				try
					{
					FS = new FileStream (CarColorsPath, FileMode.Open);
					}
				catch
					{
					MessageBox.Show (string.Format (Localization.GetText ("CarColorsFileUnavailable", al), ColorsFile),
						ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
					Error = -1;
					return;
					}
				}
			StreamReader SR = new StreamReader (FS);

			// Загрузка цветовой схемы
			string line;
			char[] splitters = { ',', '\t', ' ' };

			do
				{
				line = SR.ReadLine ();
				} while (line != "col");

			while ((line = SR.ReadLine ()) != "end")
				{
				try
					{
					string[] rgb = line.Split (splitters, StringSplitOptions.RemoveEmptyEntries);
					int r = int.Parse (rgb[0]);
					int g = int.Parse (rgb[1]);
					int b = int.Parse (rgb[2]);
					colors.Add (Color.FromArgb (r, g, b));
					}
				catch { }
				}

			// Завершение
			SR.Close ();
			FS.Close ();
			Error = 0;
			}

		/// <summary>
		/// Возвращает или задаёт путь к файлу цветов авто
		/// </summary>
		private static string CarColorsPath
			{
			// Запрос
			get
				{
				string path = "";
				try
					{
					path = Registry.GetValue (RDGenerics.AssemblySettingsKey, "CarColorsPath", "").ToString ();
					}
				catch { }

				return path;
				}

			// Установка
			set
				{
				try
					{
					Registry.SetValue (RDGenerics.AssemblySettingsKey, "CarColorsPath", value.ToString ());
					}
				catch { }
				}
			}
		}
	}
