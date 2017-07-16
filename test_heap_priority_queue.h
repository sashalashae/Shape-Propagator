#include <cxxtest/TestSuite.h>

#include "heap_priority_queue.h"

template class HeapPriorityQueue<int>;

class HeapTests : public CxxTest::TestSuite
{
public:
	/*
	These set of tests test whether the Queue is empty by not adding any items
	*/
	void testempty(void)
	{
		HeapPriorityQueue<int> b;
		TS_ASSERT(b.isEmpty() == true);
	}
	/*
	*/
	void testisnotempty(void)
	{

		HeapPriorityQueue<int> b;
		b.add(1);
		TS_ASSERT(b.isEmpty() == false);
	}

	void testadd1(void)
	{
		HeapPriorityQueue<int> b;
		b.add(1);
		b.add(2);
		b.add(5);
		b.add(3);
		b.add(4);
		TS_ASSERT(b.peek() == 5);
	}
	void testadd2(void)
	{
		HeapPriorityQueue<int> b;
		for (int a = 0; a < 200; a++)
		{
			b.add(a);
		}
		TS_ASSERT(b.peek() == 199);
	}
	void testadd3(void)
	{
		HeapPriorityQueue<int> b;
		for (int a = 199; a != 0; a--)
		{
			b.add(a);
		}
		TS_ASSERT(b.peek() == 199);
	}
	void testremove1(void)
	{
		HeapPriorityQueue<int> b;
		for (int a = 199; a != 0; a--)
		{
			b.add(a);

		}
		b.remove();
		TS_ASSERT_EQUALS(b.peek(), 198);
	}
	void testremove2(void)
	{
		HeapPriorityQueue<int> b;
		for (int a = 199; a != 0; a--)
		{
			b.add(a);
			b.remove();
		}
		
		TS_ASSERT_EQUALS(b.isEmpty(), true);
	}

};
