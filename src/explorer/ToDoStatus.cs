using System.Collections.Generic;

namespace BExplorer
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
			string status = BExplorerLib.SaveData_GetToDoStatusEx ();

			if (status == null)
				{
				return;
				}

			// Разделение статуса на элементы
			string count, all;

			count = status.Substring (40, 2).Trim ();
			all = status.Substring (42, 2);
			elements.Add (new ToDoStatusElement ("Выполнить все буйства (выполнено " + count + " из " + all + ")", count == all));

			count = status.Substring (44, 2).Trim ();
			all = status.Substring (46, 2);
			elements.Add (new ToDoStatusElement ("Ограбить все магазины (ограблено " + count + " из " + all + ")", count == all));

			count = status.Substring (48, 2).Trim ();
			all = status.Substring (50, 2);
			elements.Add (new ToDoStatusElement ("Выполнить все уникальные прыжки (выполнено " + count + " из " + all + ")", count == all));

			count = status.Substring (52, 3).Trim ();
			all = status.Substring (55, 3);
			elements.Add (new ToDoStatusElement ("Найти все спрятанные пакеты (найдено " + count + " из " + all + ")", count == all));

			elements.Add (new ToDoStatusElement ("Пройти миссию «Trial by dirt» (трасса на севере западной части города, внедорожник)", status.Substring (3, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Test track» (трасса на севере западной части города, мотоцикл)", status.Substring (4, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Cone crazy» (верхний уровень парковки на Ocean beach, авто в углу)", status.Substring (13, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Hotring» (городской стадион, с 20:00 до 0:00)", status.Substring (19, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Bloodring» (городской стадион, с 20:00 до 0:00)", status.Substring (21, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Dirtring» (городской стадион, с 20:00 до 0:00)", status.Substring (14, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «PCJ playground» (мотоцикл возле большого отеля на выезде с Ocean drive)", status.Substring (23, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию с радиоуправляемыми машинками (трасса на севере пляжа, фургон TopFun)", status.Substring (24, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию с радиоуправляемым вертолётом (въезд на ВПП со стороны доков, фургон TopFun)", status.Substring (25, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию с радиоуправляемыми самолётами (парковка North mall point, фургон TopFun)", status.Substring (26, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти вертолётную миссию на северо-западе (вертолёт на входе в офис в небоскрёбе)", status.Substring (15, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти вертолётную миссию в Малом Гаити (вертолёт на крыше при въезде)", status.Substring (20, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти вертолётную миссию на юго-востоке (вертолёт на крыше розового отеля)", status.Substring (22, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти вертолётную миссию на северо-востоке (вертолёт в большом дворе)", status.Substring (33, 1) == "1"));

			elements.Add (new ToDoStatusElement ("Пройти миссию «Paramedic» (любой автомобиль скорой помощи)", status.Substring (16, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Firefighter» (любой автомобиль пожарной службы)", status.Substring (17, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Vigilante» (любой автомобиль полицейских, включая танк)", status.Substring (18, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Подвезти 100 (в сумме) пассажиров в миссии «Taxi driver»", status.Substring (1, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию разносчика пиццы", status.Substring (2, 1) == "1"));

			elements.Add (new ToDoStatusElement ("Пройти миссию «Checkpoint Charlie» (лодочная станция, любая лодка)", status.Substring (12, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Shooting range» (тир; доступна после миссии «Shootist» клуба Малибу)", status.Substring (5, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Пройти миссию «Distribution» (продать не менее 50 «мороженых» за один раз)", status.Substring (6, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Потратить 300 долларов в клубе Pole position", status.Substring (7, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Доставить в Sunshine auto все авто из первого списка", status.Substring (8, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Доставить в Sunshine auto все авто из второго списка", status.Substring (9, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Доставить в Sunshine auto все авто из третьего списка", status.Substring (10, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Доставить в Sunshine auto все авто из четвёртого списка", status.Substring (11, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Выиграть гонку №1 в Sunshine auto", status.Substring (27, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Выиграть гонку №2 в Sunshine auto", status.Substring (28, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Выиграть гонку №3 в Sunshine auto", status.Substring (29, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Выиграть гонку №4 в Sunshine auto", status.Substring (30, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Выиграть гонку №5 в Sunshine auto", status.Substring (31, 1) == "1"));
			elements.Add (new ToDoStatusElement ("Выиграть гонку №6 в Sunshine auto", status.Substring (32, 1) == "1"));

			count = status.Substring (34, 1);
			all = status.Substring (35, 1);
			elements.Add (new ToDoStatusElement ("Завершить телефонные миссии (выполнено " + count + " из " + all + ")", count == all));

			count = status.Substring (36, 2).Trim ();
			all = status.Substring (38, 2);
			elements.Add (new ToDoStatusElement ("Скупить всю доступную собственность (куплено " + count + " из " + all + ")", count == all));

			elements.Add (new ToDoStatusElement ("Завершить основные сюжетные миссии", status.Substring (0, 1) == "1"));
			}
		}
	}
