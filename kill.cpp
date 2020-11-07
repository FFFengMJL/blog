#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <TlHelp32.h>
#include <vector>
#include <algorithm>

bool TraverseProcesses(std::map<std::wstring, int> &_mapProcess)
{
  PROCESSENTRY32 pe32;
  pe32.dwSize = sizeof(pe32);

  HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (hProcessSnap == INVALID_HANDLE_VALUE)
  {
    std::cout << "Create Toolhelp32Snapshot Error!" << std::endl;
    return false;
  }

  BOOL bResult = Process32First(hProcessSnap, &pe32); //开始遍历

  int num(0);

  while (bResult)
  {
    std::wstring name = pe32.szExeFile;
    int id = pe32.th32ProcessID;
    _mapProcess.insert(std::pair<std::wstring, int>(name, id)); //字典存储
    bResult = Process32Next(hProcessSnap, &pe32);               //返回值为false，表明进程遍历完
  }

  CloseHandle(hProcessSnap);
  return true;
}

int KillProcess(int id) //根据进程ID杀进程
{
  HANDLE hProcess = NULL;
  hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, id); //打开目标进程
  if (hProcess == NULL)
  {
    wprintf(L"\nOpen Process fAiled:%d\n", GetLastError());
    return -1;
  }
  DWORD ret = TerminateProcess(hProcess, 0); //结束目标进程
  if (ret == 0)
  {
    wprintf(L"%d", GetLastError());
  }
  return -1;
}

int Getprocessesid(std::wstring name, std::map<std::wstring, int> mapProcess)
{
  int id = mapProcess[name];
  return id;
}
bool get_running(std::map<std::wstring, int> &mapProcess, std::wstring processesname)
{
  std::map<std::wstring, int>::iterator map;
  map = mapProcess.begin();
  while (map != mapProcess.end())
  {
    std::wstring name = map->first;
    std::wstring processesneddkill = processesname;
    if (name == processesneddkill)
      return true;
    map++;
  }
  return false;
}

int main()
{
  while (1)
  {
  }
  std::map<std::wstring, int> mapProcess;
  DWORD start = ::GetTickCount(); //返回操作系统启动到现在经过的毫秒数
  TraverseProcesses(mapProcess);
  std::wstring LOL_1 = L"LeagueClientUxRender.exe";
  std::wstring LOL_2 = L"LeagueClientUxRender.exe";
  std::wstring LOL_3 = L"LeagueClientUx.exe";
  std::wstring LOL_4 = L"League of Legends.exe";
  std::wstring LOL_5 = L"CrossProxy.exe";
  std::wstring LOL_6 = L"TPHelper.exe";
  std::wstring LOL_7 = L"LeagueClient.exe";
  std::wstring namelist[64] = {LOL_1, LOL_2, LOL_3, LOL_4, LOL_5, LOL_6, LOL_7};
  int idneedkill[64];
  int index = 0;
  while (1)
  {
    while (get_running(mapProcess, LOL_4))
    {
      for (; namelist[index] != L""; index++)
      {
        idneedkill[index] = Getprocessesid(namelist[index], mapProcess);
        KillProcess(idneedkill[index]);
      }
    }
    for (; namelist[index] != L""; index++)
    {
      idneedkill[index] = Getprocessesid(namelist[index], mapProcess);
      KillProcess(idneedkill[index]);
    }
    if (get_running(mapProcess, LOL_4) == false)
    {
      std::wcout << "go to sleep" << std::endl;
      system("pause");
    }
  }

  return 0;
}