/**
 *  @file oglplus/oper/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_DRAWING_1509260923_HPP
#define OGLPLUS_OPER_DRAWING_1509260923_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct drawing_ops
{
	static
	outcome<void>
	draw_arrays(primitive_type mode, GLint first, GLsizei count)
	noexcept;

	static
	outcome<void>
	draw_elements(primitive_type mode, GLsizei count, index_type type)
	noexcept;
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/drawing.inl>

#endif // include guard
