#pragma once

HWND window = nullptr;
WNDPROC originWndProcHandler = nullptr;
bool bPresentInitialized = false;
ID3D11Device* pDevice;
ID3D11DeviceContext* pDeviceContext;
ID3D11RenderTargetView* pTargetRT;
IDXGISwapChain* pSwapChain;
DWORD_PTR* pDeviceContextVTable = nullptr;
DWORD_PTR* pSwapChainVTable = nullptr;
typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* pSwapChain, UINT syncInterval, UINT flags);
typedef void(__stdcall* ID3D11DrawIndexed)(ID3D11DeviceContext* pDeviceContext, UINT indexCount, UINT startIndexLocation, INT baseVertexLocation);

IDXGISwapChainPresent fnIDXGISwapChainPresent;
HRESULT __fastcall onPresent(IDXGISwapChain* _chain, UINT syncInterval, UINT flags) noexcept;

#ifndef DXGIINDEXES_H
#define DXGIINDEXES_H

/* IDXGISwapChain virtuals (SC_ prefix for swapchain) */
#define SC_QUERYINTERFACE            0
#define SC_ADDREF                    1
#define SC_RELEASE                    2
#define SC_SETPRIVATEDATA            3
#define SC_SETPRIVATEDATAINTERFACE    4
#define SC_GETPRIVATEDATA            5
#define SC_GETPARENT                6
#define SC_GETDEVICE                7
#define SC_PRESENT                    8
#define SC_GETBUFFER                9
#define SC_SETFULLSCREENSTATE        10
#define SC_GETFULLSCREENSTATE        11
#define SC_GETDESC                    12
#define SC_RESIZEBUFFERS            13
#define SC_RESIZETARGET                14
#define SC_GETCONTAININGOUTPUT        15
#define SC_GETFRAMESTATISTICS        16
#define SC_GETLASTPRESENTCOUNT        17

/* ID3D11DeviceContext virtuals (DC_ prefix for device context) */
#define DC_QUERYINTERFACE                                0
#define DC_ADDREF                                        1
#define DC_RELEASE                                        2
#define DC_VSSETCONSTANTBUFFERS                            3
#define DC_PSSETSHADERRESOURCES                            4
#define DC_PSSETSHADER                                    5
#define DC_PSSETSAMPLERS                                6
#define DC_VSSETSHADER                                    7
#define DC_DRAWINDEXED                                    8
#define DC_DRAW                                            9
#define DC_MAP                                            10
#define DC_UNMAP                                        11
#define DC_PSSETCONSTANTBUFFERS                            12
#define DC_IASETINPUTLAYOUT                                13
#define DC_IASETVERTEXBUFFERS                            14
#define DC_IASETINDEXBUFFER                                15
#define DC_DRAWINDEXEDINSTANCED                            16
#define DC_DRAWINSTANCED                                17
#define DC_GSSETCONSTANTBUFFERS                            18
#define DC_GSSETSHADER                                    19    
#define DC_IASETPRIMITIVETOPOLOGY                        20
#define DC_VSSETSHADERRESOURCES                            21
#define DC_VSSETSAMPLERS                                22
#define DC_BEGIN                                        23
#define DC_END                                            24
#define DC_GETDATA                                        25
#define DC_SETPREDICATION                                26
#define DC_GSSETSHADERRESOURCES                            27
#define DC_GSSETSAMPLERS                                28      
#define DC_OMSETRENDERTARGETS                            29
#define DC_OMSETRENDERTARGETSANDUNORDEREDACCESSVIEWS    30
#define DC_OMSETBLENDSTATE                                31
#define DC_OMSETDEPTHSTENCILSTATE                        21
#define DC_SOSETTARGETS                                    22
#define DC_DRAWAUTO                                        34
#define DC_DRAWINDEXEDINSTANCEDINDIRECT                    35
#define DC_DRAWINSTANCEDINDIRECT                        36
#define DC_DISPATCH                                        37
#define DC_DISPATCHINDIRECT                                38
#define DC_RSSETSTATE                                    39
#define DC_RSSETVIEWPORTS                                40
#define DC_RSSETSCISSORRECTS                            41
#define DC_COPYSUBRESOURCEREGION                        42
#define DC_COPYRESOURCE                                    43
#define DC_UPDATESUBRESOURCE                            44
#define DC_COPYSTRUCTURECOUNT                            45
#define DC_CLEARRENDERTARGETVIEW                        46
#define DC_CLEARUNORDEREDACCESSVIEWUINT                    47
#define DC_CLEARUNORDEREDACCESSVIEWFLOAT                48
#define DC_CLEARDEPTHSTENCILVIEW                        49
#define DC_GENERATEMIPS                                    50
#define DC_SETSRESOURCEMINLOD                            51
#define DC_GETRESOURCEMINLOD                            52
#define DC_RESOLVESUBRESOURCE                            53
#define DC_EXECUTECOMMANDLIST                            54
#define DC_HSSETSHADERRESOURCES                            55
#define DC_HSSETSHADER                                    56
#define DC_HSSETSAMPLERS                                57
#define DC_HSSETCONSTANTBUFFERS                            58
#define DC_DSSETSHADERRESOURCES                            59
#define DC_DSSETSHADER                                    60
#define DC_DSSETSAMPLERS                                61
#define DC_DSSETCONSTANTBUFFERS                            62
#define DC_CSSETSHADERRESOURCES                            63
#define DC_CSSETUNORDEREDACCESSVIEWS                    64
#define DC_CSSETSHADER                                    65
#define DC_CSSETSAMPLERS                                66
#define DC_CSSETCONSTANTBUFFERS                            67
#define DC_VSGETCONSTANTBUFFERS                            68
#define DC_PSGETSHADERRESOURCES                            69
#define DC_PSGETSHADER                                    70
#define DC_PSGETSAMPLERS                                71
#define DC_VSGETSHADER                                    72
#define DC_PSGETCONSTANTBUFFERS                            73
#define DC_IAGETINPUTLAYOUT                                74
#define DC_IAGETVERTEXBUFFERS                            75
#define DC_IAGETINDEXBUFFER                                76
#define DC_GSGETCONSTANTBUFFERS                            77
#define DC_GSGETSHADER                                    78
#define DC_IAGETPRIMITIVETOPOLOGY                        79
#define DC_VSGETSHADERRESOURCES                            80
#define DC_VSGETSAMPLERS                                81
#define DC_GETPREDICATION                                82
#define DC_GSGETSHADERRESOURCES                            83
#define DC_GSGETSAMPLERS                                84
#define DC_OMGETRENDERTARGETS                            85
#define DC_OMGETRENDERTARGETSANDUNORDEREDACCESSVIEWS    86
#define DC_OMGETBLENDSTATE                                87
#define DC_OMGETDEPTHSTENCILSTATE                        88
#define DC_SOGETTARGETS                                    89
#define DC_RSGETSTATE                                    90
#define DC_RSGETVIEWPORTS                                91
#define DC_RSGETSCISSORRECTS                            92
#define DC_HSGETSHADERRESOURCES                            93
#define DC_HSGETSHADER                                    94
#define DC_HSGETSAMPLERS                                95
#define DC_HSGETCONSTANTBUFFERS                            96
#define DC_DSGETSHADERRESOURCES                            97
#define DC_DSGETSHADER                                    98
#define DC_DSGETSAMPLERS                                99
#define DC_DSGETCONSTANTBUFFERS                            100
#define DC_CSGETSHADERRESOURCES                            101
#define DC_CSGETUNORDEREDACCESSVIEWS                    102
#define DC_CSGETSHADER                                    103
#define DC_CSGETSAMPLERS                                104
#define DC_CSGETCONSTANTBUFFERS                            105
#define DC_CLEARSTATE                                    106
#define DC_FLUSH                                        107
#define DC_GETTYPE                                        108
#define DC_GETCONTEXTFLAGS                                109
#define DC_FINISHCOMMANDLIST                            110

/* ID3D11Device virtuals (D_ prefix for device) */
#define D_QUERYINTERFACE                            0
#define D_ADDREF                                    1
#define D_RELEASE                                    2
#define D_CREATEBUFFER                                3
#define D_CREATETEXTURE1D                            4
#define D_CREATETEXTURE2D                            5
#define D_CREATETEXTURE3D                            6
#define D_CREATESHADERRESOURCEVIEW                    7
#define D_CREATEUNORDEREDACCESSVIEW                    8
#define D_CREATERENDERTARGETVIEW                    9
#define D_CREATEDEPTHSTENCILVIEW                    10
#define D_CREATEINPUTLAYOUT                            11
#define D_CREATEVERTEXSHADER                        12
#define D_CREATEGEOMETRYSHADER                        13
#define D_CREATEGEOMETRYSHADERWITHSREAMOUTPUT        14
#define D_CREATEPIXELSHADER                            15
#define D_CREATEHULLSHADER                            16
#define D_CREATEDOMAINSHADER                        17
#define D_CREATECOMPUTESHADER                        18
#define D_CREATECLASSLINKAGE                        19
#define D_CREATEBLENDSTATE                            20
#define D_CREATEDEPTHSTENCILSTATE                    21
#define D_CREATERASTERIZERSTATE                        22
#define D_CREATESAMPLERSTATE                        23
#define D_CREATEQUERY                                24
#define D_CREATEPREDICATE                            25
#define D_CREATECOUNTER                                26
#define D_CREATEDERERREDCONTEXT                        27
#define D_OPENSHADERRESOURCE                        28
#define D_CHECKFORMATSUPPORT                        29
#define D_CHECKMULTISAMPLEQUALITYLEVELS                30
#define D_CHECKCOUNTERINFO                            31
#define D_CHECKCOUNTER                                32
#define D_CHECKFEATURESUPPORT                        33
#define D_GETPRIVATEDATA                            34
#define D_SETPRIVATEDATA                            35
#define D_SETPRIVATEDATAINTERFACE                    36
#define D_GETFEATURELEVEL                            37
#define D_GETCREATIONFLAGS                            38
#define D_GETDEVICEREMOVEDREASON                    39
#define D_GETIMMEDIATECONTEXT                        40
#define D_SETEXCEPTIONMODE                            41
#define D_GETEXCEPTIONMODE                            42   

#endif