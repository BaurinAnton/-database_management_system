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
			//�������� �� ��������� ������
			const auto result = new List();
			Assert::IsNotNull(result);
		}
		TEST_METHOD(Add_ValidDataPositiveValue_Succes)
		{
			//�������� �� ������������ ���������� �������������� �������� � ������
			List ring;
			ring.addItem(108);
			Assert::AreEqual(108, ring.readItem(1));
		}
		TEST_METHOD(Add_ValidDataZeroValue_Succes)
		{
			//�������� �� ������������ ���������� �������� �������� � ������
			List ring;
			ring.addItem(0);
			Assert::AreEqual(0, ring.readItem(1));
		}
		TEST_METHOD(Add_ValidDataNegativeValue_Succes)
		{
			//�������� �� ������������ ���������� �������������� �������� � ������
			List ring;
			ring.addItem(-2848);
			Assert::AreEqual(-2848, ring.readItem(1));
		}
		TEST_METHOD(Add_InvalidData_Failure)
		{
			//�������� �� ���������� �������� �������� � ������
			List ring;
			double value = 10.8;
			ring.addItem(value);
			double getValue = ring.readItem(1);
			Assert::AreNotEqual(value, getValue);
		}
		TEST_METHOD(Size_ZeroSize_Succes)
		{
			//�������� ������ ������� ������ �� ����������������� ��� ������ ������
			List ring;
			size_t expectedSize = 0;
			Assert::AreEqual(expectedSize, ring.size());
		}
		TEST_METHOD(Size_NonZeroSize_Succes)
		{
			//�������� �� ���������� ��������� ��������� ������
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
			//�������� �� ���������� ��������� ������ � ������, ��� ������ ���� �������
			List ring;
			ring.addItem(10);
			ring.updateItem(1, 12);
			Assert::AreEqual(12, ring.readItem(1));
		}
		TEST_METHOD(UpdateItem_UpdateFirstItem_Succes)
		{
			//�������� �� ���������� ��������� ������ � ������ ������� �������� �� ���������
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
			//�������� �� ���������� ��������� ������ � ������ ��������, ������� �� ��������
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
			//�������� �� ���������� ��������� ������ � ������ ���������� �������� �� ���������
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
			//�������� �� ������������� ��������� ��������������� �������� � ������
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
			//�������� �� ����� �������� � ��������� 20 (0 ��)
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
			//�������� �� ����� �������� � ��������� 10 (3 ��)
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
			//�������� ������ �������� - ������ ����
			List ring;
			size_t expectedSize;
			ring.addItem(10);
			ring.deleteItem(1);
			expectedSize = 0;
			Assert::AreEqual(expectedSize, ring.size());
		}
		TEST_METHOD(DeleteItem_DeleteFirstItem_Succes) 
		{
			// �������� ������� �������� �� ����������
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
			//�������� �������� �� �������� ������
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
			//�������� �������� �� ����� ������
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
			//�������� ������ ������� ��������
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
			//�������� ������ ������� ��������
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
			//�������� ������ ���������� ��������
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
			//�������� ������ ��������������� ��������
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
