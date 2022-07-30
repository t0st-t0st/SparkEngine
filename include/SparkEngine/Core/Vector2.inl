template <typename T>
constexpr Vector2<T>::Vector2() : x(0), y(0)
{
}

template <typename T>
constexpr Vector2<T>::Vector2(T x, T y) : x(x), y(y)
{
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator+(const Vector2<T> other)
{
    return Vector2<T>(x + other.x, y + other.y);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator-(const Vector2<T> other)
{
    return Vector2<T>(x - other.x, y - other.y);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator*(const Vector2<T> other)
{
    return Vector2<T>(x * other.x, y * other.y);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator/(const Vector2<T> other)
{
    assert(other.x != 0 && other.y != 0);
    return Vector2<T>(x / other.x, y / other.y);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator*(const T other)
{
    return Vector2<T>(x * other, y * other);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator/(const T other)
{
    assert(other != 0);
    return Vector2<T>(x / other, y / other);
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator+=(const Vector2<T> other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator-=(const Vector2<T> other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator*=(const Vector2<T> other)
{
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

template <typename T>
constexpr inline Vector2<T>& Vector2<T>::operator/=(const Vector2<T> other)
{
    assert(other.x != 0 && other.y != 0);
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator*=(const T other)
{
    x *= other;
    y *= other;
    return *this;
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator/=(const T other)
{
    assert(other != 0);
    x /= other;
    y /= other;
    return *this;
}

template <typename T>
constexpr bool Vector2<T>::operator==(const Vector2<T> other)
{
    return (x == other.x) && (y == other.y);
}

template <typename T>
constexpr bool Vector2<T>::operator!=(const Vector2<T> other)
{
    return (x != other.x) || (y != other.y);
}
