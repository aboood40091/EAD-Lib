#pragma once

#include <math/seadMathCalcCommon.h>
#include <math/seadQuat.h>

namespace sead {

template <typename T>
inline void
QuatCalcCommon<T>::makeUnit(Base& q)
{
    q = Quat<T>::unit;
}

template <typename T>
bool QuatCalcCommon<T>::makeVectorRotation(Base& q, const Vec3& from, const Vec3& to)
{
    Vector3<T> cross;
    cross.setCross(*static_cast<const Vector3<T>*>(&from),     *static_cast<const Vector3<T>*>(&to));
    const T dot =   static_cast<const Vector3<T>*>(&from)->dot(*static_cast<const Vector3<T>*>(&to)) + 1;

    if (dot <= std::numeric_limits<T>::epsilon())
    {
        makeUnit(q);
        return false;
    }
    else
    {
        T v1 = MathCalcCommon<T>::sqrt(2 * dot);
        T v2 = 1 / v1;
        set(q, v1 * 0.5f,
               cross.x * v2, cross.y * v2, cross.z * v2);
    }

    return true;
}

template <typename T>
inline void
QuatCalcCommon<T>::set(Base& q, T w, T x, T y, T z)
{
    q.w = w;
    q.x = x;
    q.y = y;
    q.z = z;
}

} // namespace sead