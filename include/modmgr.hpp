#ifndef CPPMODMGR_000101_MODMGR_HPP
#define CPPMODMGR_000101_MODMGR_HPP

#define MODMGR_VER 0x000101L
#define NS_BEG(NS) namespace NS {
#define NS_END(NS) }
#define MOD_BEG(MOD) NS_BEG(modmgr_ns); NS_BEG(CONT__##MOD); NS_BEG(MOD);
#define MOD_END(MOD) NS_END(MOD); NS_END(CONT__##MOD); NS_END(modmgr_ns); 
#define DET_BEG(MOD) MOD_BEG(MOD); NS_BEG(_det);
#define DET_END(MOD) NS_END(_det); MOD_END(MOD);
#define _MOD_CONT_NS(MOD) modmgr_ns::CONT__##MOD
#define _MOD_NS(MOD) _MOD_CONT_NS(MOD)::MOD
#define MOD_USE(MOD) using namespace _MOD_CONT_NS(MOD)
#define MOD_USE_ALL(MOD) using namespace _MOD_NS(MOD)
#define DET_USE() using namespace _det;

#endif // file protection
