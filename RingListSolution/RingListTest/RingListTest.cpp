#include "pch.h"
#include "CppUnitTest.h"
#include "../RingListLib/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RingListTest
{
	TEST_CLASS(RingListTest)
	{
	public:
		TEST_METHOD(TestCreationList)
		{
			//Проверка на ненулевой объект
			const auto result = new List();
			Assert::IsNotNull(result);
		}
		TEST_METHOD(TestAdd)
		{
			List ring;
			//Проверка на корректность добавленных данных
			ring.addItem(108);
			Assert::AreEqual(108, ring.readItem(1));
			ring.addItem(0);
			Assert::AreEqual(0, ring.readItem(2));
			ring.addItem(-2848);
			Assert::AreEqual(-2848, ring.readItem(3));
			//Проверка на корректный размер списка
			size_t expectedSize = 3;
			Assert::AreEqual(expectedSize, ring.size());
		}
		TEST_METHOD(TestSize)
		{
			List ring;
			//Проверка на количество элементов
			size_t expectedSize = 0;
			Assert::AreEqual(expectedSize, ring.size());
			ring.addItem(10);
			expectedSize = 1;
			Assert::AreEqual(expectedSize, ring.size());
		}

		TEST_METHOD(TestUpdateItem)
		{
			List ring;
			//Проверка на корректное изменение данных в списке
			ring.addItem(10);
			ring.addItem(-13);
			ring.addItem(103);
			ring.addItem(23);
			ring.addItem(66);
			ring.updateItem(1, 12);
			ring.updateItem(2, 0);
			ring.updateItem(3, -457);
			ring.updateItem(4, 123);
			ring.updateItem(5, 0);
			Assert::AreEqual(12, ring.readItem(1));
			Assert::AreEqual(0, ring.readItem(2));
			Assert::AreEqual(-457, ring.readItem(3));
			Assert::AreEqual(123, ring.readItem(4));
			Assert::AreEqual(0, ring.readItem(5));
			//Проверка на "цикличность" списка
			ring.updateItem(8, -10);
			Assert::AreEqual(-10, ring.readItem(3));

		}
		TEST_METHOD(TestSearchItem)
		{
			List ring;
			//Проверка на поиск элемента с значением 10 (3 шт)
			ring.addItem(10);
			ring.addItem(1);
			ring.addItem(10);
			ring.addItem(2);
			ring.addItem(-4);
			ring.addItem(10);
			size_t expectedSize = 3;
			const vector<int> numberItem = ring.searchItem(10);
			Assert::AreEqual(expectedSize, numberItem.size());
			//Проверка на поиск элемента с значением 20 (0 шт)
			expectedSize = 0;
			const vector<int> numberItemNull = ring.searchItem(20);
			Assert::AreEqual(expectedSize, numberItemNull.size());
		}
		TEST_METHOD(TestDeleteItem)
		{
			List ring;
			size_t expectedSize;
			

			//Удаление одного элемента - список пуст
			ring.addItem(10);
			ring.deleteItem(1);
			expectedSize = 0;
			Assert::AreEqual(expectedSize, ring.size());
			

			//Удаление первого элемента из нескольких
			ring.addItem(10);
			ring.addItem(12);
			ring.addItem(14);
			ring.deleteItem(1);
			expectedSize = 2;
			//Проверяем на декремент списка
			Assert::AreEqual(expectedSize, ring.size());
			/*Проверяем, что на первом месте не удаленная 10, а 12,
			которая была на втором месте*/
			Assert::AreNotEqual(10, ring.readItem(1));
			Assert::AreEqual(12, ring.readItem(1));


			//Удаление элемента из середины списка
			ring.addItem(16);
			ring.addItem(18);
			ring.deleteItem(3);
			expectedSize = 3;
			//Проверяем на декремент списка
			Assert::AreEqual(expectedSize, ring.size());
			/*Проверяем, что на третьем месте не удаленная 16, а 18,
			которая была на четвертом месте*/
			Assert::AreNotEqual(16, ring.readItem(3));
			Assert::AreEqual(18, ring.readItem(3));

			
			//Удаление элемента из конца списка
			ring.deleteItem(3);
			expectedSize = 2;
			//Проверяем на декремент списка
			Assert::AreEqual(expectedSize, ring.size());
			/*Проверяем, что на последнем месте не удаленная 18, а 14,
			которая была на третьем месте*/
			Assert::AreNotEqual(18, ring.readItem(3));
			Assert::AreEqual(14, ring.readItem(2));
		}
		TEST_METHOD(TestReadItem)
		{
			List ring;
			ring.addItem(10);
			ring.addItem(-3211);
			ring.addItem(11240);
			ring.addItem(342);
			ring.addItem(-634);
			ring.addItem(130);
			//Проверка чтения первого, 4-го, последнего элемента
			Assert::AreEqual(10, ring.readItem(1));
			Assert::AreEqual(342, ring.readItem(4));
			Assert::AreEqual(130, ring.readItem(6));
			//Проверка чтения несуществующих элементов
			Assert::AreNotEqual(0, ring.readItem(0));
			Assert::AreNotEqual(0, ring.readItem(7));
		}
	};
}
