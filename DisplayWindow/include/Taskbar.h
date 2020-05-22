#pragma once
#include "pch.h"
#include "framework.h"

#include "str_utils.h"

namespace i3{
inline void gShowHideTaskBar(BOOL bHide /*=FALSE*/)
{
 CRect rectWorkArea = CRect(0,0,0,0);
 CRect rectTaskBar = CRect(0,0,0,0);

 CWnd* pWnd = CWnd::FindWindow(L"Shell_TrayWnd", L"");
 
 if( bHide )
 {
  // Code to Hide the System Task Bar
  SystemParametersInfo(SPI_GETWORKAREA, 0, (LPVOID)&rectWorkArea, 0);
 
  if( pWnd )
  {
   pWnd->GetWindowRect(rectTaskBar);
   rectWorkArea.bottom += rectTaskBar.Height();
  SystemParametersInfo(SPI_SETWORKAREA, 0, (LPVOID)&rectWorkArea, 0);
   // SystemParametersInfo(SPI_SETWORKAREA,
                        // 0,
                        // LPVOID)&rectWorkArea,
                        // 0);
 
   pWnd->ShowWindow(SW_HIDE);
  }
 }
 else
 {
  // Code to Show the System Task Bar
  SystemParametersInfo(SPI_GETWORKAREA, 0, (LPVOID)&rectWorkArea, 0);
  // SystemParametersInfo(SPI_GETWORKAREA,
                       // 0,
                       // (LPVOID)&rectWorkArea,
                       // 0);
  if( pWnd )
  {
   pWnd->GetWindowRect(rectTaskBar);
   rectWorkArea.bottom -= rectTaskBar.Height();
  SystemParametersInfo(SPI_SETWORKAREA, 0, (LPVOID)&rectWorkArea, 0);
   // SystemParametersInfo(SPI_SETWORKAREA,
                        // 0,
                        // (LPVOID)&rectWorkArea,
                        // 0);
 
   pWnd->ShowWindow(SW_SHOW);
  }
 }
}
 
