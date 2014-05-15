#include "HookD3D9.h"
#include <detours.h>

std::function<void (void)> OnFrameBeginRender = [](){};
std::function<void (void)> OnFrameEndRender = [](){};

typedef IDirect3D9* (__stdcall *D3D9Creator)(UINT);
D3D9Creator OLD_Direct3DCreate9;
IDirect3D9* __stdcall MyDirect3DCreate9(UINT SDKVersion)
{
	auto d3d9 = OLD_Direct3DCreate9(SDKVersion);
	auto myD3D9 = new MyDirect3D9;
	myD3D9->handle = d3d9;
	return myD3D9;
}

void HookD3D9()
{
	OLD_Direct3DCreate9 = (D3D9Creator)DetourFindFunction("d3d9.dll", "Direct3DCreate9");
	DetourAttach((void**)&OLD_Direct3DCreate9, MyDirect3DCreate9);
}

void DehookD3D9()
{
	DetourDetach((void**)&OLD_Direct3DCreate9, MyDirect3DCreate9);
}

#undef STDMETHOD
#undef STDMETHOD_

#define STDMETHOD(func) HRESULT MyDirect3D9::func
#define STDMETHOD_(ret, func) ret MyDirect3D9::func

STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj)
{
	return handle->QueryInterface(riid, ppvObj);
}

STDMETHOD_(ULONG,AddRef)(THIS)
{
	return handle->AddRef();
}

STDMETHOD_(ULONG,Release)(THIS)
{
	ULONG ret = handle->Release();
	if(!ret) delete this;
	return ret;
}

/*** IDirect3D9 methods ***/
STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction)
{
	return handle->RegisterSoftwareDevice(pInitializeFunction);
}

STDMETHOD_(UINT, GetAdapterCount)(THIS)
{
	return handle->GetAdapterCount();
}

STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier)
{
	return handle->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter,D3DFORMAT Format)
{
	return handle->GetAdapterModeCount(Adapter, Format);
}

STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode)
{
	return handle->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter,D3DDISPLAYMODE* pMode)
{
	return handle->GetAdapterDisplayMode(Adapter, pMode);
}

STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter,D3DDEVTYPE DevType,D3DFORMAT AdapterFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed)
{
	return handle->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
}

STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat)
{
	return handle->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels)
{
	return handle->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat)
{
	return handle->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

STDMETHOD(CheckDeviceFormatConversion)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat)
{
	return handle->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}

STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps)
{
	return handle->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter)
{
	return handle->GetAdapterMonitor(Adapter);
}

STDMETHOD(CreateDevice)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface)
{
	HRESULT ret = handle->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
	if(ret != D3D_OK) return ret;

	auto dev = new MyDirect3DDevice9(*ppReturnedDeviceInterface);
	*ppReturnedDeviceInterface = dev;
	return D3D_OK;
}

MyDirect3DDevice9::MyDirect3DDevice9(IDirect3DDevice9* device)
{
	handle = device;
	updateState = 0;
}

MyDirect3DDevice9::~MyDirect3DDevice9(void)
{
}

#undef STDMETHOD
#undef STDMETHOD_

#define STDMETHOD(func) HRESULT MyDirect3DDevice9::func
#define STDMETHOD_(ret, func) ret MyDirect3DDevice9::func

STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj)
{
	return handle->QueryInterface(riid, ppvObj);
}

STDMETHOD_(ULONG,AddRef)(THIS)
{
	return handle->AddRef();
}

STDMETHOD_(ULONG,Release)(THIS)
{
	ULONG ret = handle->Release();
	if(!ret) delete this;
	return ret;
}

/*** IDirect3DDevice9 methods ***/
STDMETHOD(TestCooperativeLevel)(THIS)
{
	return handle->TestCooperativeLevel();
}

STDMETHOD_(UINT, GetAvailableTextureMem)(THIS)
{
	return handle->GetAvailableTextureMem();
}

STDMETHOD(EvictManagedResources)(THIS)
{
	return handle->EvictManagedResources();
}

STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9)
{
	return handle->GetDirect3D(ppD3D9);
}

STDMETHOD(GetDeviceCaps)(THIS_ D3DCAPS9* pCaps)
{
	return handle->GetDeviceCaps(pCaps);
}

STDMETHOD(GetDisplayMode)(THIS_ UINT iSwapChain,D3DDISPLAYMODE* pMode)
{
	return handle->GetDisplayMode(iSwapChain, pMode);
}

STDMETHOD(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
	return handle->GetCreationParameters(pParameters);
}

STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap)
{
	return handle->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

STDMETHOD_(void, SetCursorPosition)(THIS_ int X,int Y,DWORD Flags)
{
	handle->SetCursorPosition(X, Y, Flags);
}

STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow)
{
	return handle->ShowCursor(bShow);
}

STDMETHOD(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain)
{
	return handle->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

STDMETHOD(GetSwapChain)(THIS_ UINT iSwapChain,IDirect3DSwapChain9** pSwapChain)
{
	return handle->GetSwapChain(iSwapChain, pSwapChain);
}

STDMETHOD_(UINT, GetNumberOfSwapChains)(THIS)
{
	return handle->GetNumberOfSwapChains();
}

STDMETHOD(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	return handle->Reset(pPresentationParameters);
}

STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{
	auto ret = handle->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
	return ret;
}

STDMETHOD(GetBackBuffer)(THIS_ UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer)
{
	return handle->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

STDMETHOD(GetRasterStatus)(THIS_ UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus)
{
	return handle->GetRasterStatus(iSwapChain, pRasterStatus);
}

STDMETHOD(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs)
{
	return handle->SetDialogBoxMode(bEnableDialogs);
}

STDMETHOD_(void, SetGammaRamp)(THIS_ UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp)
{
	handle->SetGammaRamp(iSwapChain, Flags, pRamp);
}

STDMETHOD_(void, GetGammaRamp)(THIS_ UINT iSwapChain,D3DGAMMARAMP* pRamp)
{
	handle->GetGammaRamp(iSwapChain, pRamp);
}

STDMETHOD(CreateTexture)(THIS_ UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle)
{
	return handle->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle)
{
	return handle->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle)
{
	return handle->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

STDMETHOD(CreateVertexBuffer)(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle)
{
	return handle->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

STDMETHOD(CreateIndexBuffer)(THIS_ UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle)
{
	return handle->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

STDMETHOD(CreateRenderTarget)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
	return handle->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

STDMETHOD(CreateDepthStencilSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
	return handle->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

STDMETHOD(UpdateSurface)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint)
{
	return handle->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

STDMETHOD(UpdateTexture)(THIS_ IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture)
{
	return handle->UpdateTexture(pSourceTexture, pDestinationTexture);
}

STDMETHOD(GetRenderTargetData)(THIS_ IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface)
{
	return handle->GetRenderTargetData(pRenderTarget, pDestSurface);
}

STDMETHOD(GetFrontBufferData)(THIS_ UINT iSwapChain,IDirect3DSurface9* pDestSurface)
{
	return handle->GetFrontBufferData(iSwapChain, pDestSurface);
}

STDMETHOD(StretchRect)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter)
{
	return handle->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

STDMETHOD(ColorFill)(THIS_ IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color)
{
	return handle->ColorFill(pSurface, pRect, color);
}

STDMETHOD(CreateOffscreenPlainSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
	return handle->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

STDMETHOD(SetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget)
{
	return handle->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

STDMETHOD(GetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget)
{
	return handle->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

STDMETHOD(SetDepthStencilSurface)(THIS_ IDirect3DSurface9* pNewZStencil)
{
	return handle->SetDepthStencilSurface(pNewZStencil);
}

STDMETHOD(GetDepthStencilSurface)(THIS_ IDirect3DSurface9** ppZStencilSurface)
{
	return handle->GetDepthStencilSurface(ppZStencilSurface);
}
STDMETHOD(BeginScene)(THIS)
{
	return handle->BeginScene();
}

STDMETHOD(EndScene)(THIS)
{
	return handle->EndScene();
}

STDMETHOD(Clear)(THIS_ DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil)
{
	return handle->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
{
	return handle->SetTransform(State, pMatrix);
}

STDMETHOD(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix)
{
	return handle->GetTransform(State, pMatrix);
}

STDMETHOD(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
{
	return handle->MultiplyTransform(State, pMatrix);
}

STDMETHOD(SetViewport)(THIS_ CONST D3DVIEWPORT9* pViewport)
{
	return handle->SetViewport(pViewport);
}

STDMETHOD(GetViewport)(THIS_ D3DVIEWPORT9* pViewport)
{
	return handle->GetViewport(pViewport);
}

STDMETHOD(SetMaterial)(THIS_ CONST D3DMATERIAL9* pMaterial)
{
	return handle->SetMaterial(pMaterial);
}

STDMETHOD(GetMaterial)(THIS_ D3DMATERIAL9* pMaterial)
{
	return handle->GetMaterial(pMaterial);
}

STDMETHOD(SetLight)(THIS_ DWORD Index,CONST D3DLIGHT9* pLight)
{
	return handle->SetLight(Index, pLight);
}

STDMETHOD(GetLight)(THIS_ DWORD Index,D3DLIGHT9* pLight)
{
	return handle->GetLight(Index, pLight);
}

STDMETHOD(LightEnable)(THIS_ DWORD Index,BOOL Enable)
{
	return handle->LightEnable(Index, Enable);
}

STDMETHOD(GetLightEnable)(THIS_ DWORD Index,BOOL* pEnable)
{
	return handle->GetLightEnable(Index, pEnable);
}

STDMETHOD(SetClipPlane)(THIS_ DWORD Index,CONST float* pPlane)
{
	return handle->SetClipPlane(Index, pPlane);
}

STDMETHOD(GetClipPlane)(THIS_ DWORD Index,float* pPlane)
{
	return handle->GetClipPlane(Index, pPlane);
}

STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD Value)
{
	return handle->SetRenderState(State, Value);
}

STDMETHOD(GetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD* pValue)
{
	return handle->GetRenderState(State, pValue);
}

STDMETHOD(CreateStateBlock)(THIS_ D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB)
{
	return handle->CreateStateBlock(Type, ppSB);
}

STDMETHOD(BeginStateBlock)(THIS)
{
	return handle->BeginStateBlock();
}

STDMETHOD(EndStateBlock)(THIS_ IDirect3DStateBlock9** ppSB)
{
	return handle->EndStateBlock(ppSB);
}

STDMETHOD(SetClipStatus)(THIS_ CONST D3DCLIPSTATUS9* pClipStatus)
{
	return handle->SetClipStatus(pClipStatus);
}

STDMETHOD(GetClipStatus)(THIS_ D3DCLIPSTATUS9* pClipStatus)
{
	return handle->GetClipStatus(pClipStatus);
}

STDMETHOD(GetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9** ppTexture)
{
	return handle->GetTexture(Stage, ppTexture);
}

STDMETHOD(SetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9* pTexture)
{
	return handle->SetTexture(Stage, pTexture);
}

STDMETHOD(GetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue)
{
	return handle->GetTextureStageState(Stage, Type, pValue);
}

STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value)
{
	return handle->SetTextureStageState(Stage, Type, Value);
}

STDMETHOD(GetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue)
{
	return handle->GetSamplerState(Sampler, Type, pValue);
}

STDMETHOD(SetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value)
{
	return handle->SetSamplerState(Sampler, Type, Value);
}

STDMETHOD(ValidateDevice)(THIS_ DWORD* pNumPasses)
{
	return handle->ValidateDevice(pNumPasses);
}

STDMETHOD(SetPaletteEntries)(THIS_ UINT PaletteNumber,CONST PALETTEENTRY* pEntries)
{
	return handle->SetPaletteEntries(PaletteNumber, pEntries);
}

STDMETHOD(GetPaletteEntries)(THIS_ UINT PaletteNumber,PALETTEENTRY* pEntries)
{
	return handle->GetPaletteEntries(PaletteNumber, pEntries);
}

STDMETHOD(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber)
{
	return handle->SetCurrentTexturePalette(PaletteNumber);
}

STDMETHOD(GetCurrentTexturePalette)(THIS_ UINT *PaletteNumber)
{
	return handle->GetCurrentTexturePalette(PaletteNumber);
}

STDMETHOD(SetScissorRect)(THIS_ CONST RECT* pRect)
{
	return handle->SetScissorRect(pRect);
}

STDMETHOD(GetScissorRect)(THIS_ RECT* pRect)
{
	return handle->GetScissorRect(pRect);
}

STDMETHOD(SetSoftwareVertexProcessing)(THIS_ BOOL bSoftware)
{
	return handle->SetSoftwareVertexProcessing(bSoftware);
}

STDMETHOD_(BOOL, GetSoftwareVertexProcessing)(THIS)
{
	return handle->GetSoftwareVertexProcessing();
}

STDMETHOD(SetNPatchMode)(THIS_ float nSegments)
{
	return handle->SetNPatchMode(nSegments);
}

STDMETHOD_(float, GetNPatchMode)(THIS)
{
	return handle->GetNPatchMode();
}

STDMETHOD(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)
{	
	return handle->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE Type,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{
	return handle->DrawIndexedPrimitive(Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

STDMETHOD(DrawPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
	return handle->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
	return handle->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags)
{
	return handle->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl)
{
	return handle->CreateVertexDeclaration(pVertexElements, ppDecl);
}

STDMETHOD(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl)
{
	return handle->SetVertexDeclaration(pDecl);
}

STDMETHOD(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl)
{
	return handle->GetVertexDeclaration(ppDecl);
}

STDMETHOD(SetFVF)(THIS_ DWORD FVF)
{
	return handle->SetFVF(FVF);
}

STDMETHOD(GetFVF)(THIS_ DWORD* pFVF)
{
	return handle->GetFVF(pFVF);
}

STDMETHOD(CreateVertexShader)(THIS_ CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader)
{
	return handle->CreateVertexShader(pFunction, ppShader);
}

STDMETHOD(SetVertexShader)(THIS_ IDirect3DVertexShader9* pShader)
{
	return handle->SetVertexShader(pShader);
}

STDMETHOD(GetVertexShader)(THIS_ IDirect3DVertexShader9** ppShader)
{
	return handle->GetVertexShader(ppShader);
}

STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
{
	return handle->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

STDMETHOD(GetVertexShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount)
{
	return handle->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

STDMETHOD(SetVertexShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
{
	return handle->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

STDMETHOD(GetVertexShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount)
{
	return handle->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

STDMETHOD(SetVertexShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
{
	return handle->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

STDMETHOD(GetVertexShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
{
	return handle->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

STDMETHOD(SetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride)
{
	return handle->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

STDMETHOD(GetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride)
{
	return handle->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
}

STDMETHOD(SetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT Setting)
{
	return handle->SetStreamSourceFreq(StreamNumber, Setting);
}

STDMETHOD(GetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT* pSetting)
{
	return handle->GetStreamSourceFreq(StreamNumber, pSetting);
}

STDMETHOD(SetIndices)(THIS_ IDirect3DIndexBuffer9* pIndexData)
{
	return handle->SetIndices(pIndexData);
}

STDMETHOD(GetIndices)(THIS_ IDirect3DIndexBuffer9** ppIndexData)
{
	return handle->GetIndices(ppIndexData);
}

STDMETHOD(CreatePixelShader)(THIS_ CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader)
{
	return handle->CreatePixelShader(pFunction, ppShader);
}

STDMETHOD(SetPixelShader)(THIS_ IDirect3DPixelShader9* pShader)
{
	return handle->SetPixelShader(pShader);
}

STDMETHOD(GetPixelShader)(THIS_ IDirect3DPixelShader9** ppShader)
{
	return handle->GetPixelShader(ppShader);
}

STDMETHOD(SetPixelShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
{
	return handle->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

STDMETHOD(GetPixelShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount)
{
	return handle->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

STDMETHOD(SetPixelShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
{
	return handle->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

STDMETHOD(GetPixelShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount)
{
	return handle->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

STDMETHOD(SetPixelShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
{
	return handle->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

STDMETHOD(GetPixelShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
{
	return handle->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

STDMETHOD(DrawRectPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
	return handle->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

STDMETHOD(DrawTriPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
	return handle->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

STDMETHOD(DeletePatch)(THIS_ UINT Handle)
{
	return handle->DeletePatch(Handle);
}

STDMETHOD(CreateQuery)(THIS_ D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery)
{
	return handle->CreateQuery(Type, ppQuery);
}

