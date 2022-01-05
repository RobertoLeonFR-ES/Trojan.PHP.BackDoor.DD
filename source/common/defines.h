#pragma once

#if defined _WIN64
#define getModuleSize(module) ((PIMAGE_NT_HEADERS64)((LPBYTE)module + ((PIMAGE_DOS_HEADER)module)->e_lfanew))->OptionalHeader.SizeOfImage
#define getImageBase(module) ((PIMAGE_NT_HEADERS64)((LPBYTE)module + ((PIMAGE_DOS_HEADER)module)->e_lfanew))->OptionalHeader.ImageBase
#else
#define getModuleSize(module) ((PIMAGE_NT_HEADERS32)((LPBYTE)module + ((PIMAGE_DOS_HEADER)module)->e_lfanew))->OptionalHeader.SizeOfImage
#define getImageBase(module) ((PIMAGE_NT_HEADERS32)((LPBYTE)module + ((PIMAGE_DOS_HEADER)module)->e_lfanew))->OptionalHeader.ImageBase
#endif

//������������ � � �������� ������.
#define MAKE_VERSION(a, b, c, d) (((((DWORD)(a)) & 0xFF) << 24) | ((((DWORD)(b)) & 0xFF) << 16) | ((((DWORD)(c)) & 0xFF) << 8) | ((((DWORD)(d)) & 0xFF)))
#define VERSION_MAJOR(a)         ((BYTE)(((a) >> 24) & 0xFF))
#define VERSION_MINOR(b)         ((BYTE)(((b) >> 16) & 0xFF))
#define VERSION_SUBMINOR(c)      ((BYTE)(((c) >> 8) & 0xFF))
#define VERSION_BUILD(d)         ((BYTE)((d) & 0xFF))

//�������� ��� �������, ������� ������� �������� �� asm.
#if defined _WIN64
#  define ASM_INTERNAL_DEF
#  define ASM_INTERNAL
#else
#  define ASM_INTERNAL_DEF __stdcall
#  define ASM_INTERNAL     __declspec(naked) __stdcall
#endif

#define ROR(x,n) (((x) >> (n)) | ((x) << (32-(n))))
#define ROL(x,n) (((x) << (n)) | ((x) >> (32-(n))))
#define BSWAP(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24)) 

//����������� BIG_ENDIAN <=> LITTLE_ENDIAN 
#define SWAP_WORD(s) (((((WORD)(s)) >> 8) & 0x00FF) | ((((WORD)(s)) << 8) & 0xFF00))
#define SWAP_DWORD(l) (((((DWORD)(l)) >> 24) & 0x000000FFL) | ((((DWORD)(l)) >>  8) & 0x0000FF00L) | ((((DWORD)(l)) <<  8) & 0x00FF0000L) | ((((DWORD)(l)) << 24) & 0xFF000000L))

//�������� qword �� ���� dword
#define MAKEDWORD64(l, h) ((DWORD64)(((DWORD)((DWORD64)(l) & MAXDWORD)) | ((DWORD64)((DWORD)((DWORD64)(h) & MAXDWORD))) << 32))

//���������� ������� �����������.
#define WININET_CONNECT_RETRY_COUNT 5

//�������� ����� �������������.
#define WININET_CONNECT_RETRY_DELAY 5000

//����� �������� �������� � ������.
#define PATH_REGKEY L"SOFTWARE\\Microsoft"

//���������� ��� PE executable.
#define FILEEXTENSION_EXECUTABLE L".exe"

//���������� ��� ���������� �����.
#define FILEEXTENSION_TEMP L".tmp"

//���������� ��� ���������� �����.
#define FILEEXTENSION_TXT L".txt"

//�������� ��� ����� ����.
#define TESTLATENCY_URL "http://www.google.com/webhp"

//������ ������ ��� TCP-�������.
#define TCPSERVER_PORT_FIRST 10000
#define TCPSERVER_PORT_LAST  40000

//����� ������������ � ��������
#define FONT_DIALOG "MS Shell Dlg 2"

//������ ��������� ��� UserHook.
#define USERCLICK2IMAGE_LIMIT  40
#define USERCLICK2IMAGE_SIZE   500