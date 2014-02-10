#include <base/lua/state.h>
#include <cstring>
#include "runtime.h"

namespace base { namespace warcraft3 { namespace lua_engine {

	namespace runtime
	{
		int error_handle = 0;

		void set_function(int& result, lua_State* L, int index)
		{
			if (lua_isfunction(L, index))
			{
				if (result != 0)
				{
					luaL_unref(L, LUA_REGISTRYINDEX, result);
				}

				lua_pushvalue(L, index);
				result = luaL_ref(L, LUA_REGISTRYINDEX);
			}
			else if (lua_isnil(L, index))
			{
				if (result != 0)
				{
					luaL_unref(L, LUA_REGISTRYINDEX, result);
				}

				result = 0;
			}
		}

		void get_function(int result, lua_State* L)
		{
			lua_rawgeti(L, LUA_REGISTRYINDEX, result);
		}
	}

	int jass_runtime_set(lua_State* L)
	{
		lua::state* ls = (lua::state*)L;
		const char* name = ls->tostring(2);

		if (strcmp("error_handle", name) == 0)
		{
			runtime::set_function(runtime::error_handle, ls->self(), 3);
		}

		return 0;
	}

	int jass_runtime_get(lua_State* L)
	{
		lua::state* ls = (lua::state*)L;
		const char* name = ls->tostring(2);

		if (strcmp("error_handle", name) == 0)
		{
			runtime::get_function(runtime::error_handle, ls->self());
			return 1;
		}

		return 0;
	}
}}}
