#include <cmath>
#include <memory>

#include <gtest/gtest.h>

#include "Figure.hpp"
#include "Array.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "ResultFunctions.hpp"
#include "Rombus.hpp"
#include "Trapez.hpp"

TEST(PointTest, ConstructorAndGetters) {
    Point<double> p(3.5, 4.2);
    EXPECT_DOUBLE_EQ(p.x(), 3.5);
    EXPECT_DOUBLE_EQ(p.y(), 4.2);
}

TEST(PointTest, EqualityOperator) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 2.0);
    Point<double> p3(1.5, 2.0);

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointTest, InequalityOperator) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.5, 2.0);

    EXPECT_TRUE(p1 != p2);
    EXPECT_FALSE(p1 != p1);
}

TEST(RectangleTest, ConstructorAndType) {
    Point<double> p1(0, 0);
    Point<double> p2(0, 2);
    Point<double> p3(3, 2);
    Point<double> p4(3, 0);

    Rectangle<double> rect(p1, p2, p3, p4);
    EXPECT_EQ(rect.type(), "Прямоугольник");
}

TEST(RectangleTest, AreaCalculation) {
    Point<double> p1(0, 0);
    Point<double> p2(0, 4);
    Point<double> p3(3, 4);
    Point<double> p4(3, 0);

    Rectangle<double> rect(p1, p2, p3, p4);
    EXPECT_DOUBLE_EQ(rect.area(), 12.0);
}

TEST(RectangleTest, CenterCalculation) {
    Point<double> p1(0, 0);
    Point<double> p2(0, 4);
    Point<double> p3(4, 4);
    Point<double> p4(4, 0);

    Rectangle<double> rect(p1, p2, p3, p4);
    Point<double> center = rect.center();
    EXPECT_DOUBLE_EQ(center.x(), 2.0);
    EXPECT_DOUBLE_EQ(center.y(), 2.0);
}

TEST(RectangleTest, EqualityOperator) {
    Point<double> p1(0, 0);
    Point<double> p2(0, 2);
    Point<double> p3(2, 2);
    Point<double> p4(2, 0);

    Rectangle<double> rect1(p1, p2, p3, p4);
    Rectangle<double> rect2(p1, p2, p3, p4);
    Rectangle<double> rect3(Point<double>(0, 0), Point<double>(0, 3), Point<double>(3, 3),
                            Point<double>(3, 0));

    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

TEST(RombusTest, ConstructorAndType) {
    Point<double> p1(0, 1);
    Point<double> p2(-1, 0);
    Point<double> p3(0, -1);
    Point<double> p4(1, 0);

    Rombus<double> rombus(p1, p2, p3, p4);
    EXPECT_EQ(rombus.type(), "Ромб");
}

TEST(RombusTest, AreaCalculation) {
    Point<double> p1(0, 2);
    Point<double> p2(-2, 0);
    Point<double> p3(0, -2);
    Point<double> p4(2, 0);

    Rombus<double> rombus(p1, p2, p3, p4);
    EXPECT_DOUBLE_EQ(rombus.area(), 8.0);
}

TEST(RombusTest, CenterCalculation) {
    Point<double> p1(0, 2);
    Point<double> p2(-2, 0);
    Point<double> p3(0, -2);
    Point<double> p4(2, 0);

    Rombus<double> rombus(p1, p2, p3, p4);
    Point<double> center = rombus.center();
    EXPECT_DOUBLE_EQ(center.x(), 0.0);
    EXPECT_DOUBLE_EQ(center.y(), 0.0);
}

TEST(RombusTest, EqualityOperator) {
    Point<double> p1(0, 2);
    Point<double> p2(-2, 0);
    Point<double> p3(0, -2);
    Point<double> p4(2, 0);

    Rombus<double> rombus1(p1, p2, p3, p4);
    Rombus<double> rombus2(p1, p2, p3, p4);

    EXPECT_TRUE(rombus1 == rombus2);
}

TEST(TrapezTest, ConstructorAndType) {
    Point<double> p1(0, 0);
    Point<double> p2(2, 0);
    Point<double> p3(3, 2);
    Point<double> p4(-1, 2);

    Trapez<double> trapez(p1, p2, p3, p4);
    EXPECT_EQ(trapez.type(), "Трапеция");
}

TEST(TrapezTest, AreaCalculation) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(3, 2);
    Point<double> p4(1, 2);

    Trapez<double> trapez(p1, p2, p3, p4);
    EXPECT_DOUBLE_EQ(trapez.area(), 6.0);
}

TEST(TrapezTest, CenterCalculation) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(3, 2);
    Point<double> p4(1, 2);

    Trapez<double> trapez(p1, p2, p3, p4);
    Point<double> center = trapez.center();
    EXPECT_DOUBLE_EQ(center.x(), 2.0);
    EXPECT_DOUBLE_EQ(center.y(), 1.0);
}

TEST(TrapezTest, EqualityOperator) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(3, 2);
    Point<double> p4(1, 2);

    Trapez<double> trapez1(p1, p2, p3, p4);
    Trapez<double> trapez2(p1, p2, p3, p4);

    EXPECT_TRUE(trapez1 == trapez2);
}

TEST(ArrayTest, DefaultConstructor) {
    Array<int> arr;
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, PushBackAndSize) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    EXPECT_EQ(arr.size(), 3);
}

TEST(ArrayTest, ElementAccess) {
    Array<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
}

TEST(ArrayTest, NegativeIndexAccess) {
    Array<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    EXPECT_EQ(arr[-1], 30);
    EXPECT_EQ(arr[-2], 20);
    EXPECT_EQ(arr[-3], 10);
}

TEST(ArrayTest, RemoveElement) {
    Array<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    arr.remove(1);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 30);
}

TEST(FigureTest, CrossTypeInequality) {
    Point<double> p1(0, 0);
    Point<double> p2(0, 2);
    Point<double> p3(2, 2);
    Point<double> p4(2, 0);

    Rectangle<double> rect(p1, p2, p3, p4);
    Rombus<double> rombus(p1, p2, p3, p4);

    EXPECT_FALSE(rect == rombus);
}

TEST(ValidationTest, IsRectValid) {
    Array<std::unique_ptr<Point<double>>> points;
    points.push_back(std::make_unique<Point<double>>(0, 0));
    points.push_back(std::make_unique<Point<double>>(0, 2));
    points.push_back(std::make_unique<Point<double>>(2, 2));
    points.push_back(std::make_unique<Point<double>>(2, 0));

    EXPECT_TRUE(isRect(points));
}

TEST(ValidationTest, IsRectInvalid) {
    Array<std::unique_ptr<Point<double>>> points;
    points.push_back(std::make_unique<Point<double>>(0, 0));
    points.push_back(std::make_unique<Point<double>>(1, 2));
    points.push_back(std::make_unique<Point<double>>(3, 3));
    points.push_back(std::make_unique<Point<double>>(2, 1));

    EXPECT_FALSE(isRect(points));
}

TEST(ValidationTest, IsRectNotEnoughPoints) {
    Array<std::unique_ptr<Point<double>>> points;
    points.push_back(std::make_unique<Point<double>>(0, 0));
    points.push_back(std::make_unique<Point<double>>(0, 2));
    points.push_back(std::make_unique<Point<double>>(2, 2));

    EXPECT_FALSE(isRect(points));
}
