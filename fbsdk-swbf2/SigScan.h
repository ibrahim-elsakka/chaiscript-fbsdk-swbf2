#include <Windows.h>

class SigScan
{
private:
	typedef void*(__fastcall * SCANOFFSET)();
	static HMODULE hMod;
	static HMODULE GetModule()
	{
		HMODULE outModule = NULL;
		while (true)
		{
			outModule = GetModuleHandleA("SigScan.dll");
			if (outModule) break;
			Sleep(50);
		}
		return outModule;
	}
public:
	static void* Get_OFFSET_LEGITBITBLT()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_LEGITBITBLT");
		return scanOffset();
	}
	static void* Get_OFFSET_MAIN()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_MAIN");
		return scanOffset();
	}
	static void* Get_OFFSET_VIEWANGLEFUNC()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_VIEWANGLEFUNC");
		return scanOffset();
	}
	static void* Get_OFFSET_FIRSTTYPEINFO()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_FIRSTTYPEINFO");
		return scanOffset();
	}
	static void* Get_OFFSET_CLIENTGAMECONTEXT()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_CLIENTGAMECONTEXT");
		return scanOffset();
	}
	static void* Get_OFFSET_RESOURCEMANAGER()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_RESOURCEMANAGER");
		return scanOffset();
	}
	static void* Get_OFFSET_DRAWOUTLINE()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_DRAWOUTLINE");
		return scanOffset();
	}
	static void* Get_OFFSET_MOUSEHOOK()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_MOUSEHOOK");
		return scanOffset();
	}
	static void* Get_OFFSET_CAMERAUPDATE()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_CAMERAUPDATE");
		return scanOffset();
	}
	static void* Get_OFFSET_GAMETIMESETTINGS()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_GAMETIMESETTINGS");
		return scanOffset();
	}
	static void* Get_OFFSET_WORLDRENDERER()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_WORLDRENDERER");
		return scanOffset();
	}
	static void* Get_OFFSET_GAMERENDERER()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_GAMERENDERER");
		return scanOffset();
	}
	static void* Get_OFFSET_DXRENDERER()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_DXRENDERER");
		return scanOffset();
	}
	
	static void* Get_OFFSET_DISPATCHMESSAGE()
	{
		SCANOFFSET scanOffset = (SCANOFFSET)GetProcAddress(SigScan::GetModule(), "Get_OFFSET_DISPATCHMESSAGE");
		return scanOffset();
	}
};