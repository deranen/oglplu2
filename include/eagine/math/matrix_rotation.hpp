/**
 *  @file eagine/math/matrix_rotation.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_ROTATION_1509260923_HPP
#define EAGINE_MATH_MATRIX_ROTATION_1509260923_HPP

#include "../quantities.hpp"
#include "matrix_ctr.hpp"
#include <cmath>

namespace eagine {
namespace math {

// rotation_I
template <typename X, unsigned I>
struct rotation_I;

// is_matrix_constructor<rotation_I>
template <typename T, unsigned N, bool RM, bool V, unsigned I>
struct is_matrix_constructor<rotation_I<matrix<T,N,N,RM,V>, I>>
 : std::true_type
{ };

// scale matrix 4x4 row-major
template <typename T, bool RM, bool V, unsigned I>
struct rotation_I<matrix<T,4,4,RM,V>, I>
{
	radians_t<T> _v;

	constexpr
	rotation_I(radians_t<T> v)
	noexcept
	 : _v(v)
	{ }

	typedef unsigned_constant<0> _x;
	typedef unsigned_constant<1> _y;
	typedef unsigned_constant<2> _z;

	static constexpr inline
	matrix<T,4,4,RM,V> _make(T cx, T sx, _x)
	noexcept
	{
		return matrix<T,4,4,RM,V>{{
			{T(1),T(0),T(0),T(0)},
			{T(0),  cx, -sx,T(0)},
			{T(0),  sx,  cx,T(0)},
			{T(0),T(0),T(0),T(1)}
		}};
	}

	static constexpr inline
	matrix<T,4,4,RM,V> _make(T cx, T sx, _y)
	noexcept
	{
		return matrix<T,4,4,RM,V>{{
			{  cx,T(0),  sx,T(0)},
			{T(0),T(1),T(0),T(0)},
			{ -sx,T(0),  cx,T(0)},
			{T(0),T(0),T(0),T(1)}
		}};
	}

	static constexpr inline
	matrix<T,4,4,RM,V> _make(T cx, T sx, _z)
	noexcept
	{
		return matrix<T,4,4,RM,V>{{
			{  cx, -sx,T(0),T(0)},
			{  sx,  cx,T(0),T(0)},
			{T(0),T(0),T(1),T(0)},
			{T(0),T(0),T(0),T(1)}
		}};
	}

	constexpr inline
	matrix<T,4,4,RM,V> operator()(void) const
	{
		typedef unsigned_constant<I> _axis;
		return _make(cos(_v), sin(_v)*(RM?1:-1), _axis());
	}
};

// multiply
template <typename T, unsigned N, bool RM1, bool RM2, bool V, unsigned I>
static constexpr inline
rotation_I<matrix<T,N,N,RM1,V>, I>
multiply(
	const rotation_I<matrix<T,N,N,RM1,V>, I>& a,
	const rotation_I<matrix<T,N,N,RM2,V>, I>& b
) noexcept
{
	return {radians_t<T>{T(a._v)+T(b._v)}};
}

// reorder_mat_ctr(rotation_I)
template <typename T, unsigned N, bool RM, bool V, unsigned I>
static constexpr inline
rotation_I<matrix<T,N,N,!RM,V>, I>
reorder_mat_ctr(const rotation_I<matrix<T,N,N,RM,V>, I>& c)
noexcept
{
	return {c._v};
}

// rotation x
template <typename M>
using rotation_x = rotation_I<M, 0>;

// pitch
template <typename M>
using pitch = rotation_x<M>;

// rotation y
template <typename M>
using rotation_y = rotation_I<M, 1>;

// yaw
template <typename M>
using yaw = rotation_y<M>;

// rotation z
template <typename M>
using rotation_z = rotation_I<M, 2>;

// roll
template <typename M>
using roll = rotation_z<M>;

// matrix_*
template <typename T, bool V>
using matrix_rotation_x =
	convertible_matrix_constructor<rotation_x<matrix<T,4,4,true,V>>>;

template <typename T, bool V>
using matrix_rotation_y =
	convertible_matrix_constructor<rotation_y<matrix<T,4,4,true,V>>>;

template <typename T, bool V>
using matrix_rotation_z =
	convertible_matrix_constructor<rotation_z<matrix<T,4,4,true,V>>>;

} // namespace math
} // namespace eagine

#endif //include guard

