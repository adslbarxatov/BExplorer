using System.Collections.Generic;

namespace RD_AAOW
	{
	/// <summary>
	/// Класс обеспечивает получение ToDo-статуса сохранения (списка действий,
	/// необходимых для прохождения игры)
	/// </summary>
	public class ToDoStatus
		{
		/// <summary>
		/// Вспомогательный класс-описатель элемента ToDo-статуса
		/// </summary>
		public class ToDoStatusElement
			{
			/// <summary>
			/// Возвращает описание элемента ToDo-статуса (действия, необходимого для прохождения игры)
			/// </summary>
			public string ElementDescription
				{
				get
					{
					return elementDescription;
					}
				}
			private string elementDescription;

			/// <summary>
			/// Возвращает состояние элемента (завершён/не завершён)
			/// </summary>
			public bool Completed
				{
				get
					{
					return completed;
					}
				}
			private bool completed;

			/// <summary>
			/// Конструктор. Создаёт элемент ToDo-статуса
			/// </summary>
			/// <param name="Completed">Состояние элемента</param>
			/// <param name="ElementDescription">Описание элемента</param>
			public ToDoStatusElement (string ElementDescription, bool Completed)
				{
				elementDescription = ElementDescription;
				completed = Completed;
				}
			}

		/// <summary>
		/// Возвращает список полученных элементов ToDo-статуса
		/// </summary>
		public List<ToDoStatusElement> Elements
			{
			get
				{
				return elements;
				}
			}
		private List<ToDoStatusElement> elements = new List<ToDoStatusElement> ();

		/// <summary>
		/// Конструктор. Получает ToDo-статус сохранения
		/// </summary>
		public ToDoStatus ()
			{
			// Получение статуса
			string status = BExplorerLib.SaveData_ToDoStatus;
			if (status == null)
				return;

			// Разделение статуса на элементы
			SupportedLanguages al = Localization.CurrentLanguage;
			string count, all;

			count = status.Substring (40, 2).Trim ();
			all = status.Substring (42, 2);
			elements.Add (new ToDoStatusElement (string.Format (Localization.GetText ("ToDoStatus01", al),
				count, all), count == all));

			count = status.Substring (44, 2).Trim ();
			all = status.Substring (46, 2);
			elements.Add (new ToDoStatusElement (string.Format (Localization.GetText ("ToDoStatus02", al),
				count, all), count == all));

			count = status.Substring (48, 2).Trim ();
			all = status.Substring (50, 2);
			elements.Add (new ToDoStatusElement (string.Format (Localization.GetText ("ToDoStatus03", al),
				count, all), count == all));

			count = status.Substring (52, 3).Trim ();
			all = status.Substring (55, 3);
			elements.Add (new ToDoStatusElement (string.Format (Localization.GetText ("ToDoStatus04", al),
				count, all), count == all));

			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus05", al),
				status.Substring (3, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus06", al),
				status.Substring (4, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus07", al),
				status.Substring (13, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus08", al),
				status.Substring (19, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus09", al),
				status.Substring (21, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus10", al),
				status.Substring (14, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus11", al),
				status.Substring (23, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus12", al),
				status.Substring (24, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus13", al),
				status.Substring (25, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus14", al),
				status.Substring (26, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus15", al),
				status.Substring (15, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus16", al),
				status.Substring (20, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus17", al),
				status.Substring (22, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus18", al),
				status.Substring (33, 1) == "1"));

			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus19", al),
				status.Substring (16, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus20", al),
				status.Substring (17, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus21", al),
				status.Substring (18, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus22", al),
				status.Substring (1, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus23", al),
				status.Substring (2, 1) == "1"));

			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus24", al),
				status.Substring (12, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus25", al),
				status.Substring (5, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus26", al),
				status.Substring (6, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus27", al),
				status.Substring (7, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus28", al),
				status.Substring (8, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus29", al),
				status.Substring (9, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus30", al),
				status.Substring (10, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus31", al),
				status.Substring (11, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus32", al),
				status.Substring (27, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus33", al),
				status.Substring (28, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus34", al),
				status.Substring (29, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus35", al),
				status.Substring (30, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus36", al),
				status.Substring (31, 1) == "1"));
			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus37", al),
				status.Substring (32, 1) == "1"));

			count = status.Substring (34, 1);
			all = status.Substring (35, 1);
			elements.Add (new ToDoStatusElement (string.Format (Localization.GetText ("ToDoStatus38", al),
				count, all), count == all));

			count = status.Substring (36, 2).Trim ();
			all = status.Substring (38, 2);
			elements.Add (new ToDoStatusElement (string.Format (Localization.GetText ("ToDoStatus39", al),
				count, all), count == all));

			elements.Add (new ToDoStatusElement (Localization.GetText ("ToDoStatus40", al),
				status.Substring (0, 1) == "1"));
			}
		}
	}
