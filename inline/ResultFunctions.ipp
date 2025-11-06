template <scalar T>
void printFigureInfo(const Array<std::unique_ptr<Figure<T>>>& figures) {
    size_t i = 0;
    if(figures.size() == 0)
    {
        std::cout << "Фигур нет" << std::endl;
        return;
    }
    for (i = 0; i < figures.size(); ++i) {
        std::cout << figures[i]->type() << " под номером " << i << " с вершинами: " << std::endl;
        figures[i]->printVershins();
        std::cout << "Геометрический центр: " << figures[i]->center() << std::endl;
        std::cout << "Площадь: " << figures[i]->area() << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
}

template <scalar T>
bool isRect(const Array<std::unique_ptr<Point<T>>>& points) {
    if (points.size() != 4)
        return false;

    Point<T> v1 = *points[1] - *points[0];
    Point<T> v2 = *points[2] - *points[1];
    Point<T> v3 = *points[3] - *points[2];
    Point<T> v4 = *points[0] - *points[3];

    bool a1 = std::abs(dot_prod(v1, v2)) < 1e-9;
    bool a2 = std::abs(dot_prod(v2, v3)) < 1e-9;
    bool a3 = std::abs(dot_prod(v3, v4)) < 1e-9;
    bool a4 = std::abs(dot_prod(v4, v1)) < 1e-9;

    return a1 && a2 && a3 && a4;
}

template <scalar T>
bool isTrapez(const Array<std::unique_ptr<Point<T>>>& points) {
    if (points.size() != 4)
        return false;

    Point<T> v1 = *points[1] - *points[0];
    Point<T> v2 = *points[2] - *points[1];
    Point<T> v3 = *points[3] - *points[2];
    Point<T> v4 = *points[0] - *points[3];

    double mod_v1 = std::sqrt(dot_prod(v1, v1));
    double mod_v2 = std::sqrt(dot_prod(v2, v2));
    double mod_v3 = std::sqrt(dot_prod(v3, v3));
    double mod_v4 = std::sqrt(dot_prod(v4, v4));

    bool v1_parallel_v3 = std::abs(cross(v1, v3)) < 1e-9;
    bool v2_paralell_v4 = std::abs(cross(v2, v4)) < 1e-9;

    if(v1_parallel_v3 && !v2_paralell_v4)
    {
        return std::abs(mod_v2 - mod_v4) < 1e-9;
    }
    else if(!v1_parallel_v3 && v2_paralell_v4)
    {
        return std::abs(mod_v1 - mod_v3) < 1e-9;
    }

    return false;
}

template <scalar T>
double totalArea(const Array<std::unique_ptr<Figure<T>>>& figures) {
    double result = 0;
    size_t i = 0;
    for (i = 0; i < figures.size(); ++i) {
        result += figures[i]->area();
    }

    return result;
}

template <scalar T>
std::unique_ptr<Figure<T>> input_rectangle() {
    std::cout << "Введите 4 точки прямогульника в формате x1 y1 x2 y2 x3 y3 x4 y4: ";
    T x1, x2, x3, x4, y1, y2, y3, y4;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Array<std::unique_ptr<Point<T>>> points;
    points.push_back(std::make_unique<Point<T>>(x1, y1));
    points.push_back(std::make_unique<Point<T>>(x2, y2));
    points.push_back(std::make_unique<Point<T>>(x3, y3));
    points.push_back(std::make_unique<Point<T>>(x4, y4));

    if (isRect(points)) {
        return std::make_unique<Rectangle<T>>(Point<T>(x1, y1), Point<T>(x2, y2), Point<T>(x3, y3),
                                              Point<T>(x4, y4));
    } else {
        return nullptr;
    }
}

template <scalar T>
std::unique_ptr<Figure<T>> input_trapez() {
    std::cout << "Введите 4 точки трапеции в формате x1 y1 x2 y2 x3 y3 x4 y4: ";
    T x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Array<std::unique_ptr<Point<T>>> points;
    points.push_back(std::make_unique<Point<T>>(x1, y1));
    points.push_back(std::make_unique<Point<T>>(x2, y2));
    points.push_back(std::make_unique<Point<T>>(x3, y3));
    points.push_back(std::make_unique<Point<T>>(x4, y4));

    if (isTrapez(points)) {
        return std::make_unique<Trapez<T>>(Point<T>(x1, y1), Point<T>(x2, y2), Point<T>(x3, y3),
                                           Point<T>(x4, y4));
    } else {
        return nullptr;
    }
}

template <scalar T>
bool isRombus(const Array<std::unique_ptr<Point<T>>>& points) {
    if (points.size() != 4)
        return false;

    Point<T> v1 = *points[1] - *points[0];
    Point<T> v2 = *points[2] - *points[1];
    Point<T> v3 = *points[3] - *points[2];
    Point<T> v4 = *points[0] - *points[3];

    double v1_v2 = std::sqrt(std::pow(v1.x() - v2.x(), 2) + std::pow(v1.y() - v2.y(), 2));
    double v2_v3 = std::sqrt(std::pow(v2.x() - v3.x(), 2) + std::pow(v2.y() - v3.y(), 2));
    double v3_v4 = std::sqrt(std::pow(v3.x() - v4.x(), 2) + std::pow(v3.y() - v4.y(), 2));
    double v4_v1 = std::sqrt(std::pow(v4.x() - v1.x(), 2) + std::pow(v4.y() - v1.y(), 2));

    bool a1 = std::abs(v1_v2 - v2_v3) < 1e-9;
    bool a2 = std::abs(v2_v3 - v3_v4) < 1e-9;
    bool a3 = std::abs(v3_v4 - v1_v2) < 1e-9;

    return a1 && a2 && a3;
}

template <scalar T>
std::unique_ptr<Figure<T>> input_rombus() {
    std::cout << "Введите 4 точки ромба в формате x1 y1 x2 y2 x3 y3 x4 y4: ";
    T x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Array<std::unique_ptr<Point<T>>> points;
    points.push_back(std::make_unique<Point<T>>(x1, y1));
    points.push_back(std::make_unique<Point<T>>(x2, y2));
    points.push_back(std::make_unique<Point<T>>(x3, y3));
    points.push_back(std::make_unique<Point<T>>(x4, y4));

    if (isRombus(points)) {
        return std::make_unique<Rombus<T>>(Point<T>(x1, y1), Point<T>(x2, y2), Point<T>(x3, y3),
                                           Point<T>(x4, y4));
    } else {
        return nullptr;
    }
}