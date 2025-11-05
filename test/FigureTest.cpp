#include <cmath>
#include <memory>
#include <gtest/gtest.h>

#include "Array.hpp"
#include "Figure.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
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
    
    EXPECT_TRUE(rect1 == rect2);
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

TEST(ArrayTest, OutOfRangeAccess) {
    Array<int> arr;
    arr.push_back(10);
    
    EXPECT_THROW(arr[5], std::out_of_range);
    EXPECT_THROW(arr[-5], std::out_of_range);
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

TEST(ArrayTest, RemoveNegativeIndex) {
    Array<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    
    arr.remove(-1); 
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(ArrayTest, MoveConstructor) {
    Array<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    
    Array<int> arr2(std::move(arr1));
    EXPECT_EQ(arr2.size(), 2);
    EXPECT_EQ(arr1.size(), 0);
}

TEST(ArrayTest, MoveAssignment) {
    Array<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    
    Array<int> arr2;
    arr2 = std::move(arr1);
    EXPECT_EQ(arr2.size(), 2);
    EXPECT_EQ(arr1.size(), 0);
}

TEST(IntegrationTest, ArrayOfFigures) {
    Array<std::unique_ptr<Figure<double>>> figures;

    Point<double> p1(0, 0);
    Point<double> p2(0, 2);
    Point<double> p3(2, 2);
    Point<double> p4(2, 0);
    
    figures.push_back(std::make_unique<Rectangle<double>>(p1, p2, p3, p4));
    
    Point<double> p5(0, 1);
    Point<double> p6(-1, 0);
    Point<double> p7(0, -1);
    Point<double> p8(1, 0);
    
    figures.push_back(std::make_unique<Rombus<double>>(p5, p6, p7, p8));
    
    EXPECT_EQ(figures.size(), 2);
    EXPECT_EQ(figures[0]->type(), "Прямоугольник");
    EXPECT_EQ(figures[1]->type(), "Ромб");
}

TEST(IntegrationTest, FigureAreaAndCenter) {
    Point<double> p1(0, 0);
    Point<double> p2(0, 2);
    Point<double> p3(2, 2);
    Point<double> p4(2, 0);
    
    Rectangle<double> rect(p1, p2, p3, p4);
    
    EXPECT_GT(rect.area(), 0);
    Point<double> center = rect.center();
    EXPECT_DOUBLE_EQ(center.x(), 1.0);
    EXPECT_DOUBLE_EQ(center.y(), 1.0);
}

TEST(IntegrationTest, TotalAreaCalculation) {
    Array<std::unique_ptr<Figure<double>>> figures;

    figures.push_back(std::make_unique<Rectangle<double>>(
        Point<double>(0, 0), Point<double>(0, 2), 
        Point<double>(2, 2), Point<double>(2, 0)
    ));

    figures.push_back(std::make_unique<Rombus<double>>(
        Point<double>(0, 1), Point<double>(-1, 0), 
        Point<double>(0, -1), Point<double>(1, 0)
    ));
    
    double total = 0;
    for(size_t i = 0; i < figures.size(); ++i) {
        total += figures[i]->area();
    }
    
    EXPECT_DOUBLE_EQ(total, 6.0);
}

TEST(FigureTest, DoubleConversion) {
    Point<double> p1(0, 0);
    Point<double> p2(0, 2);
    Point<double> p3(2, 2);
    Point<double> p4(2, 0);
    
    Rectangle<double> rect(p1, p2, p3, p4);
    double area = static_cast<double>(rect);
    
    EXPECT_DOUBLE_EQ(area, 4.0);
}