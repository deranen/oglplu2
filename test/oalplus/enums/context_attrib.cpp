//  File test/oalplus/enums/context_attrib.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oalplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OALPLUS_context_attrib

#include <boost/test/unit_test.hpp>
#include "common_alc.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_context_attrib)

BOOST_AUTO_TEST_CASE(enum_context_attrib_values)
{
	using namespace oalplus;
	enum_values_alc ev;
	(void)ev;
	context_attrib x;
	(void)x;

#ifdef ALC_FREQUENCY
	x = ev.frequency;
	BOOST_CHECK(x == ev.frequency);
# ifdef ALC_MONO_SOURCES
	BOOST_CHECK(x != ev.mono_sources);
# endif
# ifdef ALC_REFRESH
	BOOST_CHECK(x != ev.refresh);
# endif
# ifdef ALC_STEREO_SOURCES
	BOOST_CHECK(x != ev.stereo_sources);
# endif
# ifdef ALC_SYNC
	BOOST_CHECK(x != ev.sync);
# endif
#endif

#ifdef ALC_MONO_SOURCES
	x = ev.mono_sources;
# ifdef ALC_FREQUENCY
	BOOST_CHECK(x != ev.frequency);
# endif
	BOOST_CHECK(x == ev.mono_sources);
# ifdef ALC_REFRESH
	BOOST_CHECK(x != ev.refresh);
# endif
# ifdef ALC_STEREO_SOURCES
	BOOST_CHECK(x != ev.stereo_sources);
# endif
# ifdef ALC_SYNC
	BOOST_CHECK(x != ev.sync);
# endif
#endif

#ifdef ALC_REFRESH
	x = ev.refresh;
# ifdef ALC_FREQUENCY
	BOOST_CHECK(x != ev.frequency);
# endif
# ifdef ALC_MONO_SOURCES
	BOOST_CHECK(x != ev.mono_sources);
# endif
	BOOST_CHECK(x == ev.refresh);
# ifdef ALC_STEREO_SOURCES
	BOOST_CHECK(x != ev.stereo_sources);
# endif
# ifdef ALC_SYNC
	BOOST_CHECK(x != ev.sync);
# endif
#endif

#ifdef ALC_STEREO_SOURCES
	x = ev.stereo_sources;
# ifdef ALC_FREQUENCY
	BOOST_CHECK(x != ev.frequency);
# endif
# ifdef ALC_MONO_SOURCES
	BOOST_CHECK(x != ev.mono_sources);
# endif
# ifdef ALC_REFRESH
	BOOST_CHECK(x != ev.refresh);
# endif
	BOOST_CHECK(x == ev.stereo_sources);
# ifdef ALC_SYNC
	BOOST_CHECK(x != ev.sync);
# endif
#endif

#ifdef ALC_SYNC
	x = ev.sync;
# ifdef ALC_FREQUENCY
	BOOST_CHECK(x != ev.frequency);
# endif
# ifdef ALC_MONO_SOURCES
	BOOST_CHECK(x != ev.mono_sources);
# endif
# ifdef ALC_REFRESH
	BOOST_CHECK(x != ev.refresh);
# endif
# ifdef ALC_STEREO_SOURCES
	BOOST_CHECK(x != ev.stereo_sources);
# endif
	BOOST_CHECK(x == ev.sync);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_attrib_names)
{
	using namespace oalplus;
	enum_values_alc ev;
	(void)ev;
	context_attrib x;
	(void)x;

#ifdef ALC_FREQUENCY
	x = ev.frequency;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FREQUENCY"
	) == 0);
#endif

#ifdef ALC_MONO_SOURCES
	x = ev.mono_sources;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MONO_SOURCES"
	) == 0);
#endif

#ifdef ALC_REFRESH
	x = ev.refresh;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REFRESH"
	) == 0);
#endif

#ifdef ALC_STEREO_SOURCES
	x = ev.stereo_sources;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STEREO_SOURCES"
	) == 0);
#endif

#ifdef ALC_SYNC
	x = ev.sync;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SYNC"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_attrib_range)
{
	using namespace oalplus;
	context_attrib x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef ALC_FREQUENCY
{
	--count;
	array_view<const ALCenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		ALC_FREQUENCY
	) != r.end());
}
#endif

#ifdef ALC_MONO_SOURCES
{
	--count;
	array_view<const ALCenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		ALC_MONO_SOURCES
	) != r.end());
}
#endif

#ifdef ALC_REFRESH
{
	--count;
	array_view<const ALCenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		ALC_REFRESH
	) != r.end());
}
#endif

#ifdef ALC_STEREO_SOURCES
{
	--count;
	array_view<const ALCenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		ALC_STEREO_SOURCES
	) != r.end());
}
#endif

#ifdef ALC_SYNC
{
	--count;
	array_view<const ALCenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		ALC_SYNC
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_context_attrib_any)
{
	using namespace oalplus;
	enum_values_alc ev;
	(void)ev;
	context_attrib x, y;
	(void)x;
	(void)y;
	any_enum_value_alc a;
	(void)a;

#ifdef ALC_FREQUENCY
	x = ev.frequency;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.frequency);
#endif

#ifdef ALC_MONO_SOURCES
	x = ev.mono_sources;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.mono_sources);
#endif

#ifdef ALC_REFRESH
	x = ev.refresh;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.refresh);
#endif

#ifdef ALC_STEREO_SOURCES
	x = ev.stereo_sources;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stereo_sources);
#endif

#ifdef ALC_SYNC
	x = ev.sync;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sync);
#endif
}

BOOST_AUTO_TEST_SUITE_END()