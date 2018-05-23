﻿//第1章 错误处理.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "第1章 错误处理.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	HANDLE hFile = CreateFile(TEXT("C:\\gongluck"), 0, 0, NULL, OPEN_EXISTING, 0, NULL);
	DWORD err = GetLastError();;
	HLOCAL hlocal = NULL;
	if (err != ERROR_SUCCESS)
	{
		//将错误码（可指定自然语言）格式化输出
		DWORD res = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER,
			NULL,
			err,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
			(LPTSTR)&hlocal,
			0,
			NULL);
		MessageBox(NULL, (PCTSTR)hlocal, TEXT("err"), MB_OK);
	}

	//FormatMessage的格式化输出功能
	int nYear = 2018, nMonth = 5, nDay = 22;
	TCHAR szYear[5], szMonth[3], szDay[3];
	wsprintf(szYear, TEXT("%d"), nYear);
	wsprintf(szMonth, TEXT("%d"), nMonth);
	wsprintf(szDay, TEXT("%d"), nDay);
	LPWSTR lpSource = (LPWSTR)TEXT("今天是:%1年%2月%3日");
	DWORD_PTR pArgs[] = { (DWORD_PTR)szYear, (DWORD_PTR)szMonth, (DWORD_PTR)szDay };
	const DWORD size = 100 + 1;
	WCHAR buffer[size];
	if (FormatMessage(FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_ARGUMENT_ARRAY,
		lpSource,
		NULL,
		NULL,
		buffer,
		size,
		(va_list*)pArgs))
	{
		MessageBox(NULL, buffer, TEXT("Date"), MB_ICONINFORMATION);
	}
	//
	system("pause");
	return 0;
}
