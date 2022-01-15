#include "pch.h"
#include "CppUnitTest.h"
#include "../RingListLib/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RingListTest
{
	TEST_CLASS(RingListTest)
	{
	public:
		TEST_METHOD(CreationList_Success)
		{
			//Проверка на ненулевой объект
			const auto result = new List();
			Assert::IsNotNull(result);
		}
		TEST_METHOD(Add_ValidDataPositiveValue_Succes)
		{
			//Проверка на корректность добавления положительного значения в список
			List ring;
			ring.addItem(108);
			Assert::AreEqual(108, ring.readItem(1));
		}
		TEST_METHOD(Add_ValidDataZeroValue_Succes)
		{
			//Проверка на корректность добавления нулевого значения в список
			List ring;
			ring.addItem(0);
			Assert::AreEqual(0, ring.readItem(1));
		}
		TEST_METHOD(Add_ValidDataNegativeValue_Succes)
		{
			//Проверка на корректность добавления отрицательного значения в список
			List ring;
			ring.addItem(-2848);
			Assert::AreEqual(-2848, ring.readItem(1));
		}
		TEST_METHOD(Add_InvalidData_Failure)
		{
			//Проверка на добавление дробного значения в список
			List ring;
			double value = 10.8;
			ring.addItem(value);
			double getValue = ring.readItem(1);
			Assert::AreNotEqual(value, getValue);
		}
		TEST_METHOD(Size_ZeroSize_Succes)
		{
			//Проверка метода размера списка на работоспособность при пустом списке
			List ring;
			size_t expectedSize = 0;
			Assert::AreEqual(expectedSize, ring.size());
		}
		TEST_METHOD(Size_NonZeroSize_Succes)
		{
			//Проверка на количество элементов непустого списка
			List ring;
			ring.addItem(10);
			ring.addItem(-10);
			ring.addItem(1240);
			ring.addItem(1230);
			size_t expectedSize = 4;
			Assert::AreEqual(expectedSize, ring.size());
		}

		TEST_METHOD(UpdateItem_UpdateSingleItem_Succes)
		{
			//Проверка на корректное изменение данных в списке, где только один элемент
			List ring;
			ring.addItem(10);
			ring.updateItem(1, 12);
			Assert::AreEqual(12, ring.readItem(1));
		}
		TEST_METHOD(UpdateItem_UpdateFirstItem_Succes)
		{
			//Проверка на корректное изменение данных в списке первого элемента из множества
			List ring;
			ring.addItem(10);
			ring.addItem(-10);
			ring.addItem(1230);
			ring.addItem(210);
			ring.updateItem(1, 12);
			Assert::AreEqual(12, ring.readItem(1));
		}
		TEST_METHOD(UpdateItem_UpdateMiddleItem_Succes)
		{
			//Проверка на корректное изменение данных в списке элемента, взятого из середины
			List ring;
			ring.addItem(10);
			ring.addItem(-10);
			ring.addItem(1230);
			ring.addItem(210);
			ring.updateItem(2, 12);
			Assert::AreEqual(12, ring.readItem(2));
		}
		TEST_METHOD(UpdateItem_UpdateLastItem_Succes)
		{
			//Проверка на корректное изменение данных в списке последнего элемента из множества
			List ring;
			ring.addItem(10);
			ring.addItem(-10);
			ring.addItem(1230);
			ring.addItem(210);
			ring.updateItem(4, 12);
			Assert::AreEqual(12, ring.readItem(4));
		}
		TEST_METHOD(UpdateItem_UpdateNotItem_Failure)
		{
			//Проверка на невозможность изменения несуществующего элемента в списке
			List ring;
			ring.addItem(10);
			ring.addItem(-10);
			ring.addItem(1230);
			ring.addItem(210);
			ring.updateItem(4, 12);
			Assert::AreNotEqual(100, ring.readItem(0));
		}
		TEST_METHOD(SearchItem_ItemNotFound_Succes)
		{
			//Проверка на поиск элемента с значением 20 (0 шт)
			List ring;
			ring.addItem(10);
			ring.addItem(1);
			ring.addItem(10);
			ring.addItem(2);
			ring.addItem(-4);
			ring.addItem(10);
			size_t expectedSize = 0;
			const vector<int> numberItemNull = ring.searchItem(20);
			Assert::AreEqual(expectedSize, numberItemNull.size());
		}
		TEST_METHOD(SearchItem_ItemFound_Succes)
		{
			//Проверка на поиск элемента с значением 10 (3 шт)
			List ring;
			ring.addItem(10);
			ring.addItem(1);
			ring.addItem(10);
			ring.addItem(2);
			ring.addItem(-4);
			ring.addItem(10);
			size_t expectedSize = 3;
			const vector<int> numberItem = ring.searchItem(10);
			Assert::AreEqual(expectedSize, numberItem.size());
		}
		
		TEST_METHOD(DeleteItem_DeleteSingleItem_Succes) 
		{
			//Удаление одного элемента - список пуст
			List ring;
			size_t expectedSize;
			ring.addItem(10);
			ring.deleteItem(1);
			expectedSize = 0;
			Assert::AreEqual(expectedSize, ring.size());
		}
		TEST_METHOD(DeleteItem_DeleteFirstItem_Succes) 
		{
			// Удаление первого элемента из нескольких
			List ring;
			size_t expectedSize;
			ring.addItem(10);
			ring.addItem(12);
			ring.addItem(14);
			ring.deleteItem(1);
			expectedSize = 2;
			Assert::AreEqual(expectedSize, ring.size());
		}
		TEST_METHOD(DeleteItem_DeleteMiddleItem_Succes) 
		{
			//Удаление элемента из середины списка
			List ring;
			size_t expectedSize;
			ring.addItem(10);
			ring.addItem(12);
			ring.addItem(14);
			ring.addItem(16);
			ring.addItem(18);
			ring.deleteItem(3);
			expectedSize = 4;
			Assert::AreEqual(expectedSize, ring.size());
		}
		TEST_METHOD(DeleteItem_DeleteLastItem_Succes) 
		{
			//Удаление элемента из конца списка
			List ring;
			size_t expectedSize;
			ring.addItem(10);
			ring.addItem(12);
			ring.addItem(14);
			ring.addItem(16);
			ring.addItem(18);
			ring.deleteItem(5);
			expectedSize = 4;
			Assert::AreEqual(expectedSize, ring.size());
		}
		
		TEST_METHOD(ReadItem_ReadFirstItem_Succes) 
		{
			//Проверка чтения первого элемента
			List ring;
			ring.addItem(10);
			ring.addItem(-3211);
			ring.addItem(11240);
			ring.addItem(342);
			ring.addItem(-634);
			ring.addItem(130);
			Assert::AreEqual(10, ring.readItem(1));
		}
		TEST_METHOD(ReadItem_ReadMiddleItem_Succes) 
		{
			//Проверка чтения второго элемента
			List ring;
			ring.addItem(10);
			ring.addItem(-3211);
			ring.addItem(11240);
			ring.addItem(342);
			ring.addItem(-634);
			ring.addItem(130);
			Assert::AreEqual(-3211, ring.readItem(2));
		}
		TEST_METHOD(ReadItem_ReadLastItem_Succes) 
		{
			//Проверка чтения последнего элемента
			List ring;
			ring.addItem(10);
			ring.addItem(-3211);
			ring.addItem(11240);
			ring.addItem(342);
			ring.addItem(-634);
			ring.addItem(130);
			Assert::AreEqual(130, ring.readItem(6));
		}
		TEST_METHOD(ReadItem_ReadItem_Failure) 
		{
			//Проверка чтения несуществующего элемента
			List ring;
			ring.addItem(10);
			ring.addItem(-3211);
			ring.addItem(11240);
			ring.addItem(342);
			ring.addItem(-634);
			ring.addItem(130);
			Assert::AreNotEqual(7, ring.readItem(0));
		}
	};
}
