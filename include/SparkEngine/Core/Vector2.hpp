#pragma once

#include <SparkEngine/Core/Export.hpp>

#include <cassert>

template <typename T>
class CORE_API Vector2
{
public:
    constexpr Vector2();
    constexpr Vector2(T x, T y);

    constexpr Vector2<T> operator+(const Vector2<T> other);
    constexpr Vector2<T> operator-(const Vector2<T> other);
    constexpr Vector2<T> operator*(const Vector2<T> other);
    constexpr Vector2<T> operator/(const Vector2<T> other);

    constexpr Vector2<T> operator*(const T other);
    constexpr Vector2<T> operator/(const T other);

    constexpr Vector2<T>& operator+=(const Vector2<T> other);
    constexpr Vector2<T>& operator-=(const Vector2<T> other);
    constexpr Vector2<T>& operator*=(const Vector2<T> other);
    constexpr Vector2<T>& operator/=(const Vector2<T> other);

    constexpr Vector2<T>& operator*=(const T other);
    constexpr Vector2<T>& operator/=(const T other);

    constexpr bool operator==(const Vector2<T> other);
    constexpr bool operator!=(const Vector2<T> other);

    T x;
    T y;
};

#include <SparkEngine/Core/Vector2.inl>

using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned int>;
using Vector2f = Vector2<float>;