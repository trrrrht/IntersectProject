#include "pch.h"
#include "CppUnitTest.h"
#include"..//src/CalIntersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Line l1;
			Line l2;
			IntersectPoint point;

			l1.a = 1;
			l1.b = 2;
			l1.c = 3;

			l2.a = 2;
			l2.b = 4;
			l2.c = 6;

			point = LineIntersectLine(l1, l2);
			Assert::AreEqual(point.exist, false);
		}

		TEST_METHOD(TestMethod2)
		{
			Line l1;
			Line l2;
			IntersectPoint point;

			l1.a = 1;
			l1.b = 1;
			l1.c = 2;

			l2.a = 2;
			l2.b = 1;
			l2.c = 4;

			point = LineIntersectLine(l1, l2);
			Assert::AreEqual(point.exist, true);
			Assert::AreEqual(point.x, -2.0);
			Assert::AreEqual(point.y, 0.0);
		}

		TEST_METHOD(TestMethod3)
		{
			Line l1;
			Line l2;
			IntersectPoint point;

			l1.a = 1;
			l1.b = 2;
			l1.c = 2;

			l2.a = 2;
			l2.b = 1;
			l2.c = 2;

			point = LineIntersectLine(l1, l2);
			Assert::AreEqual(point.exist, true);
			Assert::AreEqual(point.x, -2.0 / 3);
			Assert::AreEqual(point.y, -2.0 / 3);
		}

		TEST_METHOD(TestMethod4)
		{
			Cycle c1;
			Cycle c2;
			IntersectPoint points[2];

			c1.x = 0;
			c1.y = 0;
			c1.r = 2;

			c2.x = 5;
			c2.y = 0;
			c2.r = 2;

			CycleIntersectCycle(c1, c2, points);

			Assert::AreEqual(points[0].exist, false);
			Assert::AreEqual(points[1].exist, false);
		}

		TEST_METHOD(TestMethod5)
		{
			Cycle c1;
			Cycle c2;
			IntersectPoint points[2];

			c1.x = 0;
			c1.y = 0;
			c1.r = 2;

			c2.x = 4;
			c2.y = 0;
			c2.r = 2;

			CycleIntersectCycle(c1, c2, points);

			Assert::AreEqual(points[0].exist, true);
			Assert::AreEqual(points[0].x, 2.0);
			Assert::AreEqual(points[0].y, 0.0);
			Assert::AreEqual(points[1].exist, false);
		}

		TEST_METHOD(TestMethod6)
		{
			Cycle c1;
			Cycle c2;
			IntersectPoint points[2];

			c1.x = 0;
			c1.y = 0;
			c1.r = 2;

			c2.x = 2;
			c2.y = 0;
			c2.r = 2;

			CycleIntersectCycle(c1, c2, points);

			Assert::AreEqual(points[0].exist, true);
			Assert::AreEqual(points[0].x, 1.0);
			Assert::AreEqual(points[0].y, -sqrt(3));
			Assert::AreEqual(points[1].exist, true);
			Assert::AreEqual(points[1].x, 1.0);
			Assert::AreEqual(points[1].y, sqrt(3));
		}

		TEST_METHOD(TestMethod7)
		{
			Line l;
			Cycle c;
			IntersectPoint points[2];

			l.a = 1;
			l.b = 0;
			l.c = 3;

			c.x = 0;
			c.y = 0;
			c.r = 2;

			LineIntersectCycle(l, c, points);

			Assert::AreEqual(points[0].exist, false);
			Assert::AreEqual(points[1].exist, false);
		}

		TEST_METHOD(TestMethod8)
		{
			Line l;
			Cycle c;
			IntersectPoint points[2];

			l.a = 1;
			l.b = 0;
			l.c = -2;

			c.x = 0;
			c.y = 0;
			c.r = 2;

			LineIntersectCycle(l, c, points);

			Assert::AreEqual(points[0].exist, true);
			Assert::AreEqual(points[0].x, 2.0);
			Assert::AreEqual(points[0].y, 0.0);
			Assert::AreEqual(points[1].exist, false);
		}

		TEST_METHOD(TestMethod9)
		{
			Line l;
			Cycle c;
			IntersectPoint points[2];

			l.a = 1;
			l.b = 0;
			l.c = 0;

			c.x = 0;
			c.y = 0;
			c.r = 2;

			LineIntersectCycle(l, c, points);

			Assert::AreEqual(points[0].exist, true);
			Assert::AreEqual(points[0].x, 0.0);
			Assert::AreEqual(points[0].y, -2.0);
			Assert::AreEqual(points[1].exist, true);
			Assert::AreEqual(points[1].x, 0.0);
			Assert::AreEqual(points[1].y, 2.0);
		}

		TEST_METHOD(TestMethod10)
		{
			Cycle c1;
			Cycle c2;
			IntersectPoint points[2];

			c1.x = 0;
			c1.y = 0;
			c1.r = 2;

			c2.x = 0;
			c2.y = 0;
			c2.r = 4;

			CycleIntersectCycle(c1, c2, points);

			Assert::AreEqual(points[0].exist, false);
			Assert::AreEqual(points[1].exist, false);
		}
	};
}
