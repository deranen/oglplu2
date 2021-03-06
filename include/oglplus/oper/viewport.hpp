/**
 *  @file oglplus/oper/viewport.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_VIEWPORT_1509260923_HPP
#define OGLPLUS_OPER_VIEWPORT_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct viewport_state
{
	static
	outcome<void>
	viewport(GLint x, GLint y, GLsizei w, GLsizei h)
	noexcept
	{
		OGLPLUS_GLFUNC(Viewport)(x, y, w, h);
		OGLPLUS_VERIFY_SIMPLE(Viewport,always);
		return {};
	}

	static
	outcome<void>
	viewport(GLsizei w, GLsizei h)
	noexcept
	{
		OGLPLUS_GLFUNC(Viewport)(0, 0, w, h);
		OGLPLUS_VERIFY_SIMPLE(Viewport,always);
		return {};
	}
};

} // namespace oper
} // namespace oglplus

#endif // include guard
