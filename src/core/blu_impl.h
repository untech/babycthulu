#ifndef P_U___
#define P_U___

#include "../../include/babycthulu.h"

struct logList{
char const* logLine;
logList* next;
};

class blu_impl: public bcthulu{
public:
virtual void Release();

virtual void 	 System_Start();
virtual void 	 System_SetFunc(bluCallback func, bluFunc fblu);
virtual void*	 System_ResourceFactory(void);
//virtual bluPack	 System_PackageResource(void* res, bluTypes bt);
virtual bluWrapper* System_GetWrapperHandle(void);
virtual void	 System_Msg(char const* str);
virtual void	 System_LnUp();
virtual void	 System_LnDn();

virtual void 	 GFX_Initiate();
virtual void 	 GFX_LDSprite(bluSprite* bsp);
virtual void 	 GFX_ULDSprite(bluSprite* bsp);
virtual void 	 GFX_BltSpr(bluSprite* bsp);
virtual void 	 GFX_PlayAnimation(bluSprite* bsp, bluAnimation* ban);
virtual int 	 GFX_AddAnimationFrame(bluAnimation* ban, u16 index, const u32* tile, const u16* pal, u32 tlength, u32 plength);
virtual void 	 GFX_InitAnimationFrames(bluAnimation* ban, u16 frames);
virtual void 	 GFX_ReleaseAnimationFrames(bluAnimation* ban);
virtual void 	 GFX_Init3DDevice();

virtual void	 Input_Init();
virtual bluVent  Input_PumpQueue();
virtual int	 Input_KeysPressed();
virtual int	 Input_KeysHeld();
virtual void	 Input_PushEvent(bluVent bvent);


//impl 
//specific 
//funcs

//Engine init
static blu_impl* InterfaceGet();

//System
void PrintLines(int x, int y);
void PushToPalBuffs(u16* palData, int chunks);

//Input
void StashQueue();
void AddToTailQueue(bluVent pBV);

//members
//function pointers
bool (*bluFrameFunc)(bluVent aVent);
bool (*bluRenderFunc)(bluVent aVent);

//types
//  &
//things

//input queue
u16	 qCount;
bluVent* headpV;
bluVent* tailpV;

//resource wrapper
bluWrapper* bWrap;
u16*        palBuf;
int         palBrk;

//log control
int	 logSz;
int	 curLn;
logList* blog;
logList* logTP;


private:
inline blu_impl();
};

extern blu_impl* pblu;

#endif
