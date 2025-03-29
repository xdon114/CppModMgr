#ifndef MODMGR_DEF_H_INC__
#define MODMGR_DEF_H_INC__

#define ModG_Ver() 0x0103L
#define ModG_ModBegin(M,NS) namespace XDLib_MC__ { namespace M::N { 
#define ModG_ModEnd() }}}
#define ModG_ModNS(M) ::ModMgr_MC__::M
#define ModG_Import(M) using namesapce ModG_ModNS(M)

#endif
