#pragma once

#include <json.hpp>

template <typename T>
class Point {
    const T mX;
    const T mY;

public:
    Point(T x, T y) : mX(x), mY(y) {

    }

    T x() const noexcept {
        return mX;
    }

    T y() const noexcept {
        return mY;
    }

    template <typename U>
    static Point<U> create(U x, U y) {
        return Point<U>(x, y);
    }
};

template <typename T>
void to_json(nlohmann::json& j, const Point<T>& p) {
    j = nlohmann::json{{"x", p.x()}, {"y", p.y()}};
}



