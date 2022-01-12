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
			//�������� �� ��������� ������
			const auto result = new List();
			Assert::IsNotNull(result);
		}
		TEST_METHOD(TestAdd)
		{
			List ring;
			//�������� �� ������������ ����������� ������
			ring.addItem(108);
			Assert::AreEqual(108, ring.readItem(1));
			ring.addItem(0);
			Assert::AreEqual(0, ring.readItem(2));
			ring.addItem(-2848);
			Assert::AreEqual(-2848, ring.readItem(3));
			//�������� �� ���������� ������ ������
			size_t expectedSize = 3;
			Assert::AreEqual(expectedSize, ring.size());
		}
		TEST_METHOD(TestSize)
		{
			List ring;
			//�������� �� ���������� ���������
			size_t expectedSize = 0;
			Assert::AreEqual(expectedSize, ring.size());
			ring.addItem(10);
			expectedSize = 1;
			Assert::AreEqual(expectedSize, ring.size());
		}

		TEST_METHOD(TestUpdateItem)
		{
			List ring;
			//�������� �� ���������� ��������� ������ � ������
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
			//�������� �� "�����������" ������
			ring.updateItem(8, -10);
			Assert::AreEqual(-10, ring.readItem(3));

		}
		TEST_METHOD(TestSearchItem)
		{
			List ring;
			//�������� �� ����� �������� � ��������� 10 (3 ��)
			ring.addItem(10);
			ring.addItem(1);
			ring.addItem(10);
			ring.addItem(2);
			ring.addItem(-4);
			ring.addItem(10);
			size_t expectedSize = 3;
			const vector<int> numberItem = ring.searchItem(10);
			Assert::AreEqual(expectedSize, numberItem.size());
			//�������� �� ����� �������� � ��������� 20 (0 ��)
			expectedSize = 0;
			const vector<int> numberItemNull = ring.searchItem(20);
			Assert::AreEqual(expectedSize, numberItemNull.size());
		}
		TEST_METHOD(TestDeleteItem)
		{
			List ring;
			size_t expectedSize;
			

			//�������� ������ �������� - ������ ����
			ring.addItem(10);
			ring.deleteItem(1);
			expectedSize = 0;
			Assert::AreEqual(expectedSize, ring.size());
			

			//�������� ������� �������� �� ����������
			ring.addItem(10);
			ring.addItem(12);
			ring.addItem(14);
			ring.deleteItem(1);
			expectedSize = 2;
			//��������� �� ��������� ������
			Assert::AreEqual(expectedSize, ring.size());
			/*���������, ��� �� ������ ����� �� ��������� 10, � 12,
			������� ���� �� ������ �����*/
			Assert::AreNotEqual(10, ring.readItem(1));
			Assert::AreEqual(12, ring.readItem(1));


			//�������� �������� �� �������� ������
			ring.addItem(16);
			ring.addItem(18);
			ring.deleteItem(3);
			expectedSize = 3;
			//��������� �� ��������� ������
			Assert::AreEqual(expectedSize, ring.size());
			/*���������, ��� �� ������� ����� �� ��������� 16, � 18,
			������� ���� �� ��������� �����*/
			Assert::AreNotEqual(16, ring.readItem(3));
			Assert::AreEqual(18, ring.readItem(3));

			
			//�������� �������� �� ����� ������
			ring.deleteItem(3);
			expectedSize = 2;
			//��������� �� ��������� ������
			Assert::AreEqual(expectedSize, ring.size());
			/*���������, ��� �� ��������� ����� �� ��������� 18, � 14,
			������� ���� �� ������� �����*/
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
			//�������� ������ �������, 4-��, ���������� ��������
			Assert::AreEqual(10, ring.readItem(1));
			Assert::AreEqual(342, ring.readItem(4));
			Assert::AreEqual(130, ring.readItem(6));
			//�������� ������ �������������� ���������
			Assert::AreNotEqual(0, ring.readItem(0));
			Assert::AreNotEqual(0, ring.readItem(7));
		}
	};
}
