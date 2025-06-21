#ifndef CPPMODMGR_MODMGR_HPP
#define CPPMODMGR_MODMGR_HPP

#define CPPMODMGR_VER 0x000200L
#define _MOD_BEGIN(M) 			namespace modmgr_ns {
#define _MOD_END(M)				}
#define _MOD_NS(M) 				::modmgr_ns::M
#define MOD_BEGIN(M) 			_MOD_BEGIN(M); namespace M {
#define MOD_END(M) 				} _MOD_END(M);
#define USE_MOD(M) 				namespace M = _MOD_NS(M)
#define ALL_FROM_MOD(M) 		using namespace _MOD_NS(M)
#define FROM_MOD(M)				using _MOD_NS(M)::

#endif // fprotect
