/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/shader.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_shader_test_1(void)
{
	oglplus_object_name_test<shader_name>();
	oglplus_object_test<shader>(shader_type(GL_VERTEX_SHADER));
}

void oglplus_shader_test_ops1(void)
{
	oper::shader_ops gl;
	shader shdr(shader_type(GL_VERTEX_SHADER));
	shader_array<4> shdrs(shader_type(GL_FRAGMENT_SHADER));
	glsl_source_ref src(0, nullptr, nullptr);

	gl.shader_source(shdr, src);
	gl.compile_shader(shdr);
	gl.shader_source(shdrs[0], src);

	gl.shader_type(shdr);
	gl.shader_delete_status(shdr);
	gl.shader_compile_status(shdr);
	gl.shader_info_log_length(shdr);
	gl.shader_info_log(shdr, span<char>());

	shdr.type();
	shdr.source(src);
	shdr.compile();
	shdr.compile_status();
	shdr.delete_status();
	shdr.info_log_length();
	shdr.info_log(span<char>());
}

// TODO
