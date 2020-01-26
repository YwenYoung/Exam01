// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "pch.h"
#include "rxregsvc.h"
#include "aced.h"
#include "tchar.h"

void InitApplication();
void UnloadApplication();
void Hello();


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void *pkt)
{
	switch (msg)
	{
	case AcRx::kNullMsg:
		break;
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		InitApplication();
		break;
	case AcRx::kUnloadAppMsg:
		UnloadApplication();
		break;
	case AcRx::kLoadDwgMsg:
		break;
	case AcRx::kUnloadDwgMsg:
		break;
	case AcRx::kInvkSubrMsg:
		break;
	case AcRx::kCfgMsg:
		break;
	case AcRx::kEndMsg:
		break;
	case AcRx::kQuitMsg:
		break;
	case AcRx::kSaveMsg:
		break;
	case AcRx::kDependencyMsg:
		break;
	case AcRx::kNoDependencyMsg:
		break;
	case AcRx::kOleUnloadAppMsg:
		break;
	case AcRx::kPreQuitMsg:
		break;
	case AcRx::kInitDialogMsg:
		break;
	case AcRx::kEndDialogMsg:
		break;
	case AcRx::kSuspendMsg:
		break;
	case AcRx::kInitTabGroupMsg:
		break;
	case AcRx::kEndTabGroupMsg:
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}

void Hello()
{
	acedPrompt(_T("\nHello World"));
}

void InitApplication()
{
	acedRegCmds->addCommand(_T("Exam01"), _T("Hello"), _T("你好"), ACRX_CMD_MODAL, Hello);
}

void UnloadApplication()
{
	acedRegCmds->removeGroup(_T("Exam01"));
}