// test_serial_enum.cpp : main project file.

#include "stdafx.h"
#include <atlbase.h>
#include <winreg.h>
//#include <ostream>
//#include <iostream>
//#include <OAIdl.h>
//#include <WinReg.h>
using namespace System;
using namespace System::Runtime::InteropServices;


int main(array<System::String ^> ^args)
{
	CRegKey RegKey;
	int nCount = 0;
	//ϵͳCOM�˿ڵ�ע�����Ϣ���ڸ�Ŀ¼�¡�
	if(RegKey.Open(HKEY_LOCAL_MACHINE, (LPCTSTR)"Hardware\\DeviceMap\\SerialComm") 	== ERROR_SUCCESS)   
	{   
		while(true)   
		{   
			TCHAR ValueName[_MAX_PATH];		 //��¼����
			BYTE ValueData[_MAX_PATH];			//��¼��ֵ
			//TCHAR ValueData[_MAX_PATH];
			DWORD nValueSize = _MAX_PATH;   
			DWORD nDataSize = _MAX_PATH;   
			DWORD nType;   
			
			//RegKey.EnumKey(nCount,ValueName,nValueSize,NULL);
			//���ö�ٳ�ע���Ŀ¼�µļ����ͼ�ֵ��
			if(::RegEnumValue(HKEY(RegKey), nCount, ValueName, &nValueSize,NULL, &nType, ValueData, &nDataSize) == ERROR_NO_MORE_ITEMS)   
			{   
				break;   
			}   
			//cout<<ValueName<<", "<<ValueData<<endl;
		//	Console::WriteLine("{0} {1}",1,2);
			String ^ lstr1 = gcnew String(ValueName);
			//WideCharToMultiByte()
			//const char * p = "���";
			
			String ^lstr2 = Marshal::PtrToStringAnsi((IntPtr)(char *)ValueData);
			//String ^ MyStr = Marshal::PtrToStringAnsi(ValueData);
			//Console::WriteLine(MyStr);
			//String ^ lstr2  = gcnew String(ValueData);
		Console::WriteLine("{0} {1}",lstr1,lstr2);

			nCount++;   
		}   
	}  
    Console::WriteLine(L"Hello World");
    return 0;
}
