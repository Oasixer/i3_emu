# notes

* I'm learning how to use hooks just for this project. And I needed somewhere to stick some research notes. So it goes here.
  
* Making a new thread/hook in AHK:
  * hooks.cpp, 4051 - AddRemoveHooks()
  * also: GetActiveHooks(), ChangeHookState()

  * theres some spicy stuff in script_gui.cpp:
ResultType GuiType::ParseOptions(LPTSTR aOptions, bool &aSetLastFoundWindow, ToggleValueType &aOwnDialogs, Var *&aHwndVar)
// This function is similar to ControlParseOptions() further below, so should be maintained alongside it.
// Caller must have already initialized aSetLastFoundWindow/, bool &aOwnDialogs with desired starting values.

    * check out aSetLastFoundWindow?

    
# Bug.n:

* manager.ahk, 442:

Manager_moveWindow() {
  Local aWndId, SC_MOVE, WM_SYSCOMMAND

  WinGet, aWndId, ID, A
  If InStr(Manager_managedWndIds, aWndId . ";") And Not Window_#%aWndId%_isFloating
    View_toggleFloatingWindow(aWndId)
  Window_set(aWndId, "Top", "")

  WM_SYSCOMMAND = 0x112
  SC_MOVE       = 0xF010
  SendMessage, WM_SYSCOMMAND, SC_MOVE, , , ahk_id %aWndId%
}

# back to AHK:
* script2.cpp -> 2340:
  * WinMove definition:

ResultType Line::WinMove(LPTSTR aTitle, LPTSTR aText, LPTSTR aX, LPTSTR aY
	, LPTSTR aWidth, LPTSTR aHeight, LPTSTR aExcludeTitle, LPTSTR aExcludeText)
{
	// So that compatibility is retained, don't set ErrorLevel for commands that are native to AutoIt2
	// but that AutoIt2 doesn't use ErrorLevel with (such as this one).
	HWND target_window = DetermineTargetWindow(aTitle, aText, aExcludeTitle, aExcludeText);
	if (!target_window)
		return OK;
	RECT rect;
	if (!GetWindowRect(target_window, &rect))
		return OK;  // Can't set errorlevel, see above.
	MoveWindow(target_window
		, *aX && _tcsicmp(aX, _T("default")) ? ATOI(aX) : rect.left  // X-position
		, *aY && _tcsicmp(aY, _T("default")) ? ATOI(aY) : rect.top   // Y-position
		, *aWidth && _tcsicmp(aWidth, _T("default")) ? ATOI(aWidth) : rect.right - rect.left
		, *aHeight && _tcsicmp(aHeight, _T("default")) ? ATOI(aHeight) : rect.bottom - rect.top
		, TRUE);  // Do repaint.
	DoWinDelay;
	return OK;
}

* MoveWindow is called above, so find MoveWindow definition:
https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-movewindow

