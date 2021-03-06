/**
 *  @file oglplus/oper/rasterization.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_RASTERIZATION_1509260923_HPP
#define OGLPLUS_OPER_RASTERIZATION_1509260923_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct rasterization_state
{
	static
	outcome<void>
	front_face(face_orientation orientation)
	noexcept;

	static
	outcome<face_orientation>
	front_face(void)
	noexcept;

	static
	outcome<void>
	cull_face(face mode)
	noexcept;

	static
	outcome<face>
	cull_face_mode(void)
	noexcept;

#if defined(GL_VERSION_3_0)
	static
	outcome<void>
	polygon_mode(face side, oglplus::polygon_mode mode)
	noexcept;

	// TODO getter
#endif

	static
	outcome<void>
	polygon_offset(GLfloat factor, GLfloat units)
	noexcept;

	static
	outcome<GLfloat>
	polygon_offset_factor(void)
	noexcept;

	static
	outcome<GLfloat>
	polygon_offset_units(void)
	noexcept;

	static
	outcome<void>
	line_width(GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	line_width(void)
	noexcept;

#if defined(GL_VERSION_3_0)
	static
	outcome<void>
	point_size(GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	point_size(void)
	noexcept;

	static
	outcome<void>
	point_parameter(oglplus::point_parameter param, GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	point_parameter(oglplus::point_parameter param)
	noexcept;
#endif

#if defined(GL_VERSION_3_2) || defined(GL_ARB_provoking_vertex)
	static
	outcome<void>
	provoking_vertex(provoke_mode mode)
	noexcept;

	static
	outcome<provoke_mode>
	provoking_vertex(void)
	noexcept;
#endif

#if defined(GL_VERSION_4_0)
	static
	outcome<void>
	min_sample_shading(GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	min_stample_shading_value(void)
	noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/rasterization.inl>

#endif // include guard
