using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace BExplorer
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
				FS = new FileStream (Application.StartupPath + "\\" + ColorsFile, FileMode.Open);
				}
			catch
				{
				MessageBox.Show ("Файл «" + ColorsFile + "», необходимый для работы программы, недоступен.\n" +
					"Скопируйте его из места установки GTA VC (папка data) и перенесите в папку с данным приложением",
					ProgramDescription.AssemblyTitle, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				Error = -1;
				return;
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
					string[] rgb = line.Split (splitters, System.StringSplitOptions.RemoveEmptyEntries);
					int r = int.Parse (rgb[0]);
					int g = int.Parse (rgb[1]);
					int b = int.Parse (rgb[2]);
					colors.Add (Color.FromArgb (r, g, b));
					}
				catch
					{
					}
				}

			// Завершение
			SR.Close ();
			FS.Close ();
			Error = 0;
			}
		}
	}
