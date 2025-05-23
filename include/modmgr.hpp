#ifndef MODMGR_HPP
#define MODMGR_HPP

#define MODMGR_VER 0x0105L
#define MOD_BEGIN(Module) namespace modmgr_ns::Module {
#define MOD_END() }
#define MOD_SCOPE(Module) modmgr_ns::Module
#define MOD_IMPORT(Module) using namespace MOD_SCOPE(Module)

#endif // #ifndef MODMGR_HPP
