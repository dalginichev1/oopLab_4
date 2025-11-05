template<scalar T>
void printFigureInfo(const Array<std::unique_ptr<Figure<T>>>& figures)
{
    size_t i = 0;
    for (i = 0; i < figures.size(); ++i)
    {
        std::cout << figures[i]->type() << " под номером " << i << " с вершинами: " << std::endl;
        figures[i]->printVershins();
        std::cout << std::endl;
        std::cout << "Геометрический центр: " << figures[i]->center() << std::endl;
        std::cout << "Площадь: " << figures[i]->area() << std::endl;
        std::cout << "---------------------------------------------" << std::endl; 
    }
}

template<scalar T>
double totalArea(const Array<std::unique_ptr<Figure<T>>>& figures)
{
    double result = 0;
    size_t i = 0;
    for(i = 0; i <= figures.size(); ++i)
    {
        result += figures[i]->area();
    }

    return result;
}

template<scalar T>
std::unique_ptr<Figure<T>> input_rectangle()
{
    std::cout << "Введите 4 точки прямогульника в формате x1 y1 x2 y2 x3 y3 x4 y4: ";
    T x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    return std::make_unique<Rectangle<T>>(Point<T>(x1, y1), Point<T>(x2, y2), Point<T>(x3, y3), Point<T>(x4, y4));
}

template<scalar T>
std::unique_ptr<Figure<T>> input_trapez()
{
    std::cout << "Введите 4 точки трапеции в формате x1 y1 x2 y2 x3 y3 x4 y4: ";
    T x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    return std::make_unique<Trapez<T>>(Point<T>(x1, y1), Point<T>(x2, y2), Point<T>(x3, y3), Point<T>(x4, y4));
}

template<scalar T>
std::unique_ptr<Figure<T>> input_rombus()
{
    std::cout << "Введите 4 точки ромба в формате x1 y1 x2 y2 x3 y3 x4 y4: ";
    T x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    return std::make_unique<Rombus<T>>(Point<T>(x1, y1), Point<T>(x2, y2), Point<T>(x3, y3), Point<T>(x4, y4));
}