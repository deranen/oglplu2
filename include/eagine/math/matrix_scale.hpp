/**
 *  @file eagine/math/matrix_scale.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_SCALE_1509260923_HPP
#define EAGINE_MATH_MATRIX_SCALE_1509260923_HPP

#include "matrix_ctr.hpp"

namespace eagine {
namespace math {

// scale
template <typename X>
struct scale;

// is_matrix_constructor<scale>
template <typename T, unsigned N, bool RM, bool V>
struct is_matrix_constructor<scale<matrix<T,N,N,RM,V>>>
 : std::true_type
{ };

// scale matrix 4x4 row-major
template <typename T, bool RM, bool V>
struct scale<matrix<T,4,4,RM,V>>
{
	vect::data_t<T, 3, V> _v;

	constexpr
	scale(vect::data_t<T, 3, V> v)
	noexcept
	 : _v(v)
	{ }

	constexpr
	scale(T vx, T vy, T vz)
	noexcept
	 : _v{vx, vy, vz}
	{ }

	constexpr inline
	matrix<T,4,4,RM,V> operator()(void) const
	noexcept
	{
		return matrix<T,4,4,RM,V>{{
			{_v[0], T(0), T(0), T(0)},
			{ T(0),_v[1], T(0), T(0)},
			{ T(0), T(0),_v[2], T(0)},
			{ T(0), T(0), T(0), T(1)}
		}};
	}
};

// multiply
template <typename T, unsigned N, bool RM1, bool RM2, bool V>
static constexpr inline
scale<matrix<T,N,N,RM1,V>>
multiply(
	const scale<matrix<T,N,N,RM1,V>>& a,
	const scale<matrix<T,N,N,RM2,V>>& b
) noexcept
{
	return {a._v*b._v};
}

// reorder_mat_ctr(scale)
template <typename T, unsigned N, bool RM, bool V>
static constexpr inline
scale<matrix<T,N,N,!RM,V>>
reorder_mat_ctr(const scale<matrix<T,N,N,RM,V>>& t)
noexcept
{
	return {t._v};
}

} // namespace math
} // namespace eagine

#endif //include guard
