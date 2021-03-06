/**
 *  @file oglplus/renderbuffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_RENDERBUFFER_1509260923_HPP
#define OGLPLUS_RENDERBUFFER_1509260923_HPP

#include "renderbuffer_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

#if defined(GL_VERSION_4_5) ||\
	defined(GL_ARB_direct_state_access) ||\
	defined(GL_EXT_direct_state_access)
#define OGLPLUS_DSA_RENDERBUFFER 1
#endif

namespace oglplus {

binding_query
get_binding_query(renderbuffer_target tgt)
noexcept;

namespace oper {

struct renderbuffer_ops
{
	static
	outcome<void>
	bind_renderbuffer(renderbuffer_target target, renderbuffer_name rbo)
	noexcept;

	static
	outcome<renderbuffer_name>
	renderbuffer_binding(renderbuffer_target target)
	noexcept;

	static
	outcome<void>
	renderbuffer_storage(
		renderbuffer_target tgt,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	) noexcept;

#ifdef OGLPLUS_DSA_RENDERBUFFER
	static
	outcome<void>
	renderbuffer_storage(
		renderbuffer_name rbo,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	) noexcept;
#endif
	static
	outcome<void>
	renderbuffer_storage_multisample(
		renderbuffer_target tgt,
		GLsizei samples,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	) noexcept;

#ifdef OGLPLUS_DSA_RENDERBUFFER
	static
	outcome<void>
	renderbuffer_storage_multisample(
		renderbuffer_name rbo,
		GLsizei samples,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	) noexcept;
#endif

	static
	outcome<void>
	get_renderbuffer_parameter_iv(
		renderbuffer_target tgt,
		oglplus::renderbuffer_parameter param,
		span<GLint> values
	) noexcept;

#ifdef OGLPLUS_DSA_RENDERBUFFER
	static
	outcome<void>
	get_renderbuffer_parameter_iv(
		renderbuffer_name buf,
		oglplus::renderbuffer_parameter param,
		span<GLint> values
	) noexcept;
#endif

	template <typename R, typename T, typename RNT>
	static
	outcome<R>
	return_renderbuffer_parameter_i(
		const RNT& rnt,
		oglplus::renderbuffer_parameter parameter
	) noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_width(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_height(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_red_size(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_green_size(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_blue_size(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_alpha_size(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_depth_size(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_stencil_size(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_samples(const RNT& rnt)
	noexcept;

	template <typename RNT>
	static 
	outcome<pixel_data_internal_format>
	renderbuffer_internal_format(const RNT& rnt)
	noexcept;
};

} // namespace oper

template <typename Derived, typename Base>
struct obj_member_ops<tag::renderbuffer, Derived, Base>
 : Base
{
private:
	Derived& _self()
	noexcept
	{
		return *static_cast<Derived*>(this);
	}

	typedef oper::renderbuffer_ops _ops;
protected:
	using Base::Base;
public:
	outcome<Derived&>
	storage(
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	)
	noexcept
	{
		return {_ops::renderbuffer_storage(
			*this,
			ifmt,
			width, height
		), _self()};
	}

	outcome<Derived&>
	storage_multisample(
		GLsizei samples,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	)
	noexcept
	{
		return {_ops::renderbuffer_storage_multisample(
			*this,
			samples,
			ifmt,
			width, height
		), _self()};
	}

	outcome<GLsizei>
	width(void) const
	noexcept
	{
		return _ops::renderbuffer_width(*this);
	}

	outcome<GLsizei>
	height(void) const
	noexcept
	{
		return _ops::renderbuffer_height(*this);
	}

	outcome<GLsizei>
	red_size(void) const
	noexcept
	{
		return _ops::renderbuffer_red_size(*this);
	}

	outcome<GLsizei>
	green_size(void) const
	noexcept
	{
		return _ops::renderbuffer_green_size(*this);
	}

	outcome<GLsizei>
	blue_size(void) const
	noexcept
	{
		return _ops::renderbuffer_blue_size(*this);
	}

	outcome<GLsizei>
	alpha_size(void) const
	noexcept
	{
		return _ops::renderbuffer_alpha_size(*this);
	}

	outcome<GLsizei>
	depth_size(void) const
	noexcept
	{
		return _ops::renderbuffer_depth_size(*this);
	}

	outcome<GLsizei>
	stencil_size(void) const
	noexcept
	{
		return _ops::renderbuffer_stencil_size(*this);
	}

	outcome<GLsizei>
	samples(void) const
	noexcept
	{
		return _ops::renderbuffer_samples(*this);
	}

	outcome<pixel_data_internal_format>
	internal_format(void) const
	noexcept
	{
		return _ops::renderbuffer_internal_format(*this);
	}
};

template <>
struct object_binding<tag::renderbuffer>
 : obj_member_ops<
	tag::renderbuffer,
	object_binding<tag::renderbuffer>,
	renderbuffer_target
>
{
	using obj_member_ops<
		tag::renderbuffer,
		object_binding<tag::renderbuffer>,
		renderbuffer_target
	>::obj_member_ops;
};

#ifdef OGLPLUS_DSA_RENDERBUFFER
template <>
struct obj_dsa_ops<tag::renderbuffer>
 : obj_member_ops<
	tag::renderbuffer,
	obj_dsa_ops<tag::renderbuffer>,
	obj_zero_dsa_ops<tag::renderbuffer>
>
{
	using obj_member_ops<
		tag::renderbuffer,
		obj_dsa_ops<tag::renderbuffer>,
		obj_zero_dsa_ops<tag::renderbuffer>
	>::obj_member_ops;
};
#endif

template <>
struct obj_gen_del_ops<tag::renderbuffer>
{
	static
	deferred_error_handler
	_gen(span<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(span<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using renderbuffer = object_owner<tag::renderbuffer>;
using bound_renderbuffer = object_binding<tag::renderbuffer>;
template <std::size_t N>
using renderbuffer_array = object_array_owner<tag::renderbuffer, N>;

static const object_zero_and_ops<tag::renderbuffer>
	no_renderbuffer = {};

} // namespace oglplus

#include <oglplus/renderbuffer.inl>

#ifdef OGLPLUS_DSA_RENDERBUFFER
#undef OGLPLUS_DSA_RENDERBUFFER
#endif

#endif // include guard
