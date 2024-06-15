#include <iostream>
#include <string>
#include <Windows.h>
#include <WinINet.h>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <wchar.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <iostream>
#include <vector> // Added this line to include the vector header
#include <filesystem>
#include <iostream>
#include <windows.h>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "Wininet.lib") // Link with WinINet library
#include <string> // Include string header for std::wstring
#include <Wininet.h> // Include WinINet header for Internet functions
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib> // For system()



#include <Windows.h>
#include <string>

#include "UtilLib.h"

#pragma comment(lib, "Wininet.lib") // Link with WinINet library



#pragma comment(lib, "wininet.lib")


#include <iostream>
#include <string>
#include <Windows.h>
#include <WinINet.h>
#include <fstream>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"
#define YELLOW_TEXT "\033[1;33m"



#pragma comment(lib, "wininet.lib")
using namespace std;
namespace fs = std::filesystem;




bool DownloadFile(const std::wstring& url, const std::wstring& filePath) {
	HINTERNET hInternet = InternetOpenA("Download", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (hInternet == NULL) {
		std::cerr << "Failed to initialize WinINet." << std::endl;
		return false;
	}

	// Convert wide string URL to ANSI string
	std::string urlA(url.begin(), url.end());

	HINTERNET hUrl = InternetOpenUrlA(hInternet, urlA.c_str(), NULL, 0, 0, 0);
	if (hUrl == NULL) {
		std::cerr << "Failed to open URL." << std::endl;
		InternetCloseHandle(hInternet);
		return false;
	}

	std::ofstream file(filePath, std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "Failed to create file." << std::endl;
		InternetCloseHandle(hUrl);
		InternetCloseHandle(hInternet);
		return false;
	}

	DWORD bytesRead = 0;
	char buffer[1024];
	while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
		file.write(buffer, bytesRead);
	}

	file.close();
	InternetCloseHandle(hUrl);
	InternetCloseHandle(hInternet);
	return true;
}


namespace fs = std::filesystem;

bool checkFilesExist(const std::string& path, const std::vector<std::string>& filenames) {
	for (const auto& filename : filenames) {
		if (!fs::exists(path + "/" + filename)) {
			return false;
		}
	}
	return true;
}

bool fileExists(const std::wstring& filePath) {
	DWORD fileAttributes = GetFileAttributes(filePath.c_str());
	return (fileAttributes != INVALID_FILE_ATTRIBUTES && !(fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}

#include <iostream>
#include <string>
#include <windows.h>
#include <wininet.h>
#include <urlmon.h>
#include <filesystem>
#pragma comment(lib, "urlmon.lib")
#include <random>
#include <string>
#include <random>  // Include <random> for C++11 random utilities
#include <thread>  // Include <thread> for std::this_thread::sleep_for
#include <chrono>

std::string random_string(size_t length) {
	std::string GeneratedString;
	static const char Alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!?-_*&%$";
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, sizeof(Alphabet) - 2); // -2 to exclude '\0'
	for (size_t i = 0; i < length; i++)
		GeneratedString += Alphabet[dis(gen)];
	return GeneratedString;
}

// Function to download file from URL
bool download_file(const std::string& url, const std::string& dest) {
	HRESULT hr = URLDownloadToFileA(NULL, url.c_str(), dest.c_str(), 0, NULL);
	return hr == S_OK;
}

// Function to get the executable path
std::string get_executable_path() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	return std::string(buffer);
}

// Function to delete the current executable
void delete_current_executable() {
	std::string current_path = get_executable_path();
	std::string command = "/C choice /C Y /N /D Y /T 3 & Del \"" + current_path + "\"";
	ShellExecuteA(NULL, "open", "cmd.exe", command.c_str(), NULL, SW_HIDE);
}

void auto_update(const std::string& downloadLink) {
	std::string current_path = get_executable_path();
	std::string new_path = current_path.substr(0, current_path.find_last_of("\\/") + 1); // Get directory path

	std::string random_str = random_string(6); // Generate random string

	new_path += random_str + ".exe"; // Create new executable path with just the random string

	if (download_file(downloadLink, new_path)) {
		ShellExecuteA(0, 0, new_path.c_str(), 0, 0, SW_SHOW);
		delete_current_executable();
		exit(0);
	}
}




void resizeConsole(int width, int height) {
	// Get the handle to the standard output device (the console)
	HWND console = GetConsoleWindow();
	RECT r;
	// Get the current window size and position
	GetWindowRect(console, &r);
	// Move and resize the window
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

#include <random>  // Include <random> for C++11 random utilities
#include <thread>  // Include <thread> for std::this_thread::sleep_for
#include <chrono>  // Include <chrono> for std::chrono::milliseconds

std::string gen_string(const int length)
{
	std::string GeneratedString;
	static const char Alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!?-_*&%$";
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, sizeof(Alphabet) - 2); // -2 to exclude '\0'
	for (int i = 0; i < length; i++)
		GeneratedString += Alphabet[dis(gen)];
	return GeneratedString;
}

void updateConsoleTitle(const int titleLength)
{
	while (true)
	{
		std::string newTitle = gen_string(titleLength);
		SetConsoleTitleA(newTitle.c_str());

		// Sleep for 0.25 seconds
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <wininet.h> // Include for Windows Internet functions
#pragma comment(lib, "wininet.lib") // Link with wininet library



// Function to perform HTTP GET request using Windows Internet functions
std::string httpGet(const std::string& url) {
	HINTERNET hInternet = InternetOpenA("HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (!hInternet) {
		return "";
	}

	HINTERNET hConnect = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
	if (!hConnect) {
		InternetCloseHandle(hInternet);
		return "";
	}

	std::stringstream response;
	char buffer[1024];
	DWORD bytesRead;
	while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
		response.write(buffer, bytesRead);
	}

	InternetCloseHandle(hConnect);
	InternetCloseHandle(hInternet);

	return response.str();
}


// Function to compute the SHA-256 hash of a file
std::string computeFileHash(const std::string& filePath) {
	HCRYPTPROV hProv = 0;
	HCRYPTHASH hHash = 0;
	HANDLE hFile = CreateFileA(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		return "";
	}

	if (!CryptAcquireContextA(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
		CloseHandle(hFile);
		return "";
	}

	if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) {
		CryptReleaseContext(hProv, 0);
		CloseHandle(hFile);
		return "";
	}

	BYTE buffer[1024];
	DWORD bytesRead;
	while (ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
		if (!CryptHashData(hHash, buffer, bytesRead, 0)) {
			CryptDestroyHash(hHash);
			CryptReleaseContext(hProv, 0);
			CloseHandle(hFile);
			return "";
		}
	}

	BYTE hash[32];
	DWORD hashLen = sizeof(hash);
	if (!CryptGetHashParam(hHash, HP_HASHVAL, hash, &hashLen, 0)) {
		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);
		CloseHandle(hFile);
		return "";
	}

	std::stringstream ss;
	for (DWORD i = 0; i < hashLen; ++i) {
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	}

	CryptDestroyHash(hHash);
	CryptReleaseContext(hProv, 0);
	CloseHandle(hFile);

	return ss.str();
}

// Function to get the path of the current executable
std::string getExecutablePath() {
	char path[MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	return std::string(path);
}

// Function to trim whitespace from both ends of a string
std::string trim(const std::string& str) {
	size_t start = str.find_first_not_of(" \t\n\r");
	size_t end = str.find_last_not_of(" \t\n\r");
	return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

const std::vector<std::string> blacklistedTools = {
		"ollydbg.exe", "idaq.exe", "idaq64.exe", "idag.exe", "idag64.exe",
		"ida.exe", "ida64.exe", "idaq.exe", "idaq64.exe", "ImmunityDebugger.exe",
		"Wireshark.exe", "dumpcap.exe", "HookExplorer.exe", "ImportREC.exe",
		"PETools.exe", "LordPE.exe", "SysInspector.exe", "Procmon.exe", "Procexp.exe",
		"idaq64.exe", "idaq.exe", "ollydbg.exe", "x64dbg.exe", "x32dbg.exe",
		"scylla.exe", "scylla_x64.exe", "scylla_x86.exe", "scylla.dll",
		"scylla_x64.dll", "scylla_x86.dll", "windbg.exe", "reshacker.exe",
		"ImportREC.exe", "IMMUNITYDEBUGGER.EXE", "MegaDumper.exe", "MegaDumper_x64.exe"
	"ollydbg.exe",
	"idaq.exe",
	"idaq64.exe",
	"idag.exe",
	"idag64.exe",
	"idaw.exe",
	"idaw64.exe",
	"ida.exe",
	"ida64.exe",
	"ImmunityDebugger.exe",
	"Wireshark.exe",
	"dumpcap.exe",
	"HookExplorer.exe",
	"ImportREC.exe",
};

#include <psapi.h>


bool isBlacklistedToolRunning() {
	DWORD processIds[1024], cbNeeded, cProcesses;
	if (!EnumProcesses(processIds, sizeof(processIds), &cbNeeded))
		return false;

	cProcesses = cbNeeded / sizeof(DWORD);

	for (unsigned int i = 0; i < cProcesses; i++) {
		if (processIds[i] != 0) {
			char szProcessName[MAX_PATH] = "<unknown>";
			HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processIds[i]);

			if (hProcess != NULL) {
				HMODULE hMod;
				DWORD cbNeeded;

				if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
					GetModuleBaseNameA(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(char));

					for (const auto& blacklisted : blacklistedTools) {
						if (_stricmp(szProcessName, blacklisted.c_str()) == 0) {
							//std::cerr << "Blacklisted tool detected: " << szProcessName << std::endl;
							CloseHandle(hProcess);
							return true;
						}
					}
				}
				CloseHandle(hProcess);
			}
		}
	}
	return false;
}


std::string generateRandomString121(int length) {
	const std::string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::string result;
	result.reserve(length);
	for (int i = 0; i < length; ++i) {
		result += charset[rand() % charset.length()];
	}
	return result;
}

// Function to generate a random error message
std::string generateRandomErrorMessage() {
	std::string errorCode = generateRandomString121(7); // Generating a random code
	return "[!] Error: FlX -> (" + errorCode + ")";
}

// Function to check if a software is blacklisted (dummy implementation)
bool isSoftwareBlacklisted() {
	// Simulate checking for blacklisted software (replace with actual logic)
	static bool blacklisted = false;
	blacklisted = !blacklisted; // Toggle for testing
	return blacklisted;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <WinINet.h>
const std::string changelogUrl = "https://fn-instant-performance-mode.netlify.app/changelog.txt";
const std::string changelogFilePath = "C:\\Temp\\changelog.txt";
bool fetchChangelog() {
	HINTERNET hInternet = InternetOpenA("FetchChangelog", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (hInternet == NULL) {
		std::cerr << "Failed to initialize WinINet." << std::endl;
		return false;
	}

	HINTERNET hUrl = InternetOpenUrlA(hInternet, changelogUrl.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
	if (hUrl == NULL) {
		std::cerr << "Failed to open URL." << std::endl;
		InternetCloseHandle(hInternet);
		return false;
	}

	std::ofstream file(changelogFilePath, std::ios::out);
	if (!file.is_open()) {
		std::cerr << "Failed to create file." << std::endl;
		InternetCloseHandle(hUrl);
		InternetCloseHandle(hInternet);
		return false;
	}

	char buffer[1024];
	DWORD bytesRead = 0;
	while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
		file.write(buffer, bytesRead);
	}

	file.close();
	InternetCloseHandle(hUrl);
	InternetCloseHandle(hInternet);
	return true;
}

const std::string black = "\033[30m";
const std::string red = "\033[31m";
const std::string green = "\033[32m";
const std::string yellow = "\033[33m";
const std::string blue = "\033[34m";
const std::string magenta = "\033[35m";
const std::string cyan = "\033[36m";
const std::string white = "\033[37m";

const std::string bright_black = "\033[90m";
const std::string bright_red = "\033[91m";
const std::string bright_green = "\033[92m";
const std::string bright_yellow = "\033[93m";
const std::string bright_blue = "\033[94m";
const std::string bright_magenta = "\033[95m";
const std::string bright_cyan = "\033[96m";
const std::string bright_white = "\033[97m";

const std::string bg_black = "\033[40m";
const std::string bg_red = "\033[41m";
const std::string bg_green = "\033[42m";
const std::string bg_yellow = "\033[43m";
const std::string bg_blue = "\033[44m";
const std::string bg_magenta = "\033[45m";
const std::string bg_cyan = "\033[46m";
const std::string bg_white = "\033[47m";

const std::string bg_bright_black = "\033[100m";
const std::string bg_bright_red = "\033[101m";
const std::string bg_bright_green = "\033[102m";
const std::string bg_bright_yellow = "\033[103m";
const std::string bg_bright_blue = "\033[104m";
const std::string bg_bright_magenta = "\033[105m";
const std::string bg_bright_cyan = "\033[106m";
const std::string bg_bright_white = "\033[107m";

const std::string light_yellow = "\033[93m"; // Light yellow
const std::string light_blue = "\033[96m"; // Light blue
const std::string pink = "\033[95m";

const std::string reset = "\033[0m";

void viewChangelogs() {
	std::string changelogUrl = "https://fn-instant-performance-mode.netlify.app/changelog.txt";
	std::string changelogContent = httpGet(changelogUrl);

	if (changelogContent.empty()) {
		std::cerr << "[!] Failed to fetch changelog." << std::endl;
	}
	else {
		std::cout << "\n--- Changelog ---\n";

		std::istringstream iss(changelogContent);
		std::string line;
		while (std::getline(iss, line)) {
			if (line.empty()) {
				continue; // Skip empty lines
			}

			char prefix = line[0];
			const std::string* color = &reset; // Default color

			switch (prefix) {
			case '+':
				color = &green;
				break;
			case '-':
				color = &red;
				break;
			case '?':
				color = &yellow;
				break;
			case 'V':
				color = &pink;
				break;
			default:
				break;
			}

			std::cout << *color << line << reset << std::endl;
		}

		std::cout << "-----------------\n";
	}
}


int main()
{


	cool:

			const int titleLength = 40;

			// Start the console title update loop in a separate thread
			std::thread titleUpdater(updateConsoleTitle, titleLength);


			// Resize console to 800x600
			resizeConsole(800, 400);



			system("cls");




			cout << red << "[!] A stable internet connection is required for this." << reset;
			Sleep(1500);
			system("cls");

			double version = 1.3; // Use double for version to match remote version type
			bool update = true;

			// URL of the text file containing the latest version number
			std::string versionUrl = "https://fn-instant-performance-mode.netlify.app/version.txt";
			std::string hashUrl = "https://fn-instant-performance-mode.netlify.app/hash.txt";

			// Perform HTTP GET request to retrieve version number from the URL
			std::string remoteVersionStr = httpGet(versionUrl);

			if (remoteVersionStr.empty()) {
				std::cerr << red << "[!] Failed to fetch remote version number." << reset << std::endl;
				return 1;
			}

			// Parse the version number from the response
			double remoteVersion;
			std::istringstream iss(remoteVersionStr);
			if (!(iss >> remoteVersion)) {
				std::cerr << red << "[!] Failed to parse remote version number." << reset << std::endl;
				return 1;
			}
			// Compare local version with remote version
			if (version >= remoteVersion) {
				update = false;
			}
			else {
				update = true;
			}

			//Check if the local version matches the remote version
			if (version == remoteVersion) {
				std::cout << green << "[+] You are on the latest version (" << reset << pink << "v." << remoteVersion << reset << green << ")." << reset << std::endl;
			}
			else {

				/*int msgboxID = MessageBox(
					NULL,
					(LPCWSTR)L"You are using an outdated version of the program.\nWe recommend using the built-in automatic updater.",
					(LPCWSTR)L"Outdated Version",
					MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
				); */

				std::cout << red << "\n[!] You are using an outdated version of the program." << reset;

				string check;
				string yes = "Y";
				string yes3 = "y";
				string yes2 = "yes";
				string yes4 = "Yes";
				cout << light_yellow << "\n\n[?] Would you like to try the latest version (Y/N) -> " << reset;
				cin >> check;

				if (check == yes || check == yes2 || check == yes3 || check == yes4)
				{
					// Simulated KeyAuth response and app_data for demonstration
					std::string downloadLink = "https://fn-instant-performance-mode.netlify.app/fn-instant-performance-mode.exe";

					std::cout << yellow << "\n[/] Downloading update.." << std::endl;
					std::cout << green << "[/] New file will be opened shortly.." << std::endl;

					if (!downloadLink.empty()) {
						auto_update(downloadLink);
					}
				}
				else
				{
					cout << red << "[-] Auto closing in 3 seconds..." << reset;
					Sleep(3000);
					exit(0);
				}

			}

			// Perform HTTP GET request to retrieve the allowed hash from the URL
			std::string remoteHash = httpGet(hashUrl);

			if (remoteHash.empty()) {
				std::cerr << "Failed to fetch remote hash." << std::endl;
				return 1;
			}

			// Trim any extraneous whitespace or newlines from the remote hash
			remoteHash = trim(remoteHash);

			// Get the path of the current executable
			std::string executablePath = getExecutablePath();

			// Compute the hash of the local executable
			std::string localHash = computeFileHash(executablePath);

			if (localHash.empty()) {
				std::cerr << "Failed to compute local hash." << std::endl;
				return 1;
			}

			// Convert both hashes to lowercase for comparison
			std::transform(remoteHash.begin(), remoteHash.end(), remoteHash.begin(), ::tolower);
			std::transform(localHash.begin(), localHash.end(), localHash.begin(), ::tolower);

			// Compare the local hash with the remote hash
			if (localHash == remoteHash) {
				std::cout << green << "[+] Local hash matches remote hash.\n" << reset << std::endl;
				cout << pink << "[1] Performance mode\n" << reset << bright_blue << "[2] DirectX 11\n" << reset << light_blue << "[3] DirectX 12\n" << reset << yellow << "[4] Update\n" << reset << green << "[5] View Changelogs\n" << reset << pink << "[6] Exit\n\n" << reset << light_yellow << "Option -> " << reset;
			}
			else {
				std::cout << red << "[!] Local hash does not match remote hash!" << reset << std::endl;


				cout << pink << "\n[1] Performance mode\n" << reset << bright_blue << "[2] DirectX 11\n" << reset << light_blue << "[3] DirectX 12\n" << reset;
				cout << red << "[4] Update (recommended)\n" << reset << green << "[5] View Changelogs\n" << reset << pink << "[6] Exit\n\n" << reset << light_yellow << "Option -> " << reset;

			}

			int option;
			int option1 = 1;
			int option2 = 2;
			int option3 = 3;
			int option4 = 4;
			int option5 = 5;
			int option6 = 6;

			cin >> option;

			if (option == option1)
			{
				// Path of the directory to create
				const wchar_t* path = L"C:\\Content";

				// Create the directory
				if (CreateDirectory(path, NULL) || ERROR_ALREADY_EXISTS == GetLastError()) {
					//std::wcout << L"Directory created successfully: " << path << std::endl;
				}
				else {
					std::cerr << red << "[-] Failed to create directory: " << path << std::endl;
				}

				std::wstring url;
				std::wstring filePath = L"C:\\Content\\performance_mode.zip";
				std::cout << yellow << "\n[-] Downloading content, please wait...\n\n" << reset;

				url = L"https://fn-instant-performance-mode.netlify.app/FortniteGame.zip";
				if (DownloadFile(url, filePath)) {
					system("START /MIN /WAIT powershell -windowstyle hidden Expand-Archive -LiteralPath 'C:\\Content\\performance_mode.zip' -DestinationPath '%localappdata%\\FortniteGame'");
				}
				else {
					std::cerr << red << "[-] Failed to download the file." << reset << std::endl;
				}

				cout << yellow << "[-] Cleaning up...\n" << reset;
				system("del C:\\Content\\performance_mode.zip");
				system("rmdir /q C:\\Content\\");
				cout << green << "\n[+] Finished" << reset << endl;
				cout << bright_blue << "[+] Auto closing in 3 seconds..." << reset;
				Sleep(3000);
				exit(0);

			}

			if (option == option2)
			{
				string check;
				string yes = "Y";
				string yes3 = "y";
				string yes2 = "yes";
				string yes4 = "Yes";
				cout << red << "\n[-] We're sorry, but this is not available on your current version (" << reset << pink << "Version " << version << reset << red << ")." << reset << yellow << "\n[/] This feature may be available in later versions (" << light_blue << "Version " << version + 0.1 << " or higher" << yellow << ")." << reset;
				cout << light_yellow << "\n\n[?] Want to check if updates are available? (Y/N) -> " << reset;
				cin >> check;

				if (check == yes || check == yes2 || check == yes3 || check == yes4)
				{



					// URL of the text file containing the latest version number
					std::string versionUrl = "https://fn-instant-performance-mode.netlify.app/version.txt";


					// Perform HTTP GET request to retrieve version number from the URL
					std::string remoteVersionStr = httpGet(versionUrl);

					if (remoteVersionStr.empty()) {
						std::cerr << red << "[!] Failed to fetch remote version number." << reset << std::endl;
						return 1;
					}

					// Parse the version number from the response
					double remoteVersion;
					std::istringstream iss(remoteVersionStr);
					if (!(iss >> remoteVersion)) {
						std::cerr << red << "[!] Failed to parse remote version number." << reset << std::endl;
						return 1;
					}
					// Compare local version with remote version
					if (version >= remoteVersion) {
						update = false;
					}
					else {
						update = true;
					}

					//Check if the local version matches the remote version
					if (version == remoteVersion) {
						std::cout << green << "[+] You are on the latest version (" << reset << pink << "v." << remoteVersion << reset << green << ")." << reset << std::endl;
						cout << magenta << "\n[!] It is possible that there are some hotfixes on the server without version changes.\n[?] Do you want to download the latest version (Y/N) -> ";

						string instupdate;
						string yes = "Y";
						string yes3 = "y";
						string yes2 = "yes";
						string yes4 = "Yes";
						cin >> instupdate;

						if (instupdate == yes || instupdate == yes2 || instupdate == yes3 || instupdate == yes4)
						{
							// Simulated KeyAuth response and app_data for demonstration
							std::string downloadLink = "https://fn-instant-performance-mode.netlify.app/fn-instant-performance-mode.exe";

							std::cout << yellow << "\n[/] Downloading update.." << std::endl;
							std::cout << green << "[/] New file will be opened shortly.." << std::endl;

							if (!downloadLink.empty()) {
								auto_update(downloadLink);
							}
							cout << red << "[-] Auto closing in 3 seconds..." << reset;
							Sleep(3000);
							exit(0);
						}

						else
						{
							cout << red << "[-] Auto closing in 3 seconds..." << reset;
							Sleep(3000);
							exit(0);
						}

					}

				}
				if (update == true) {

					/*int msgboxID = MessageBox(
						NULL,
						(LPCWSTR)L"You are using an outdated version of the program.\nWe recommend using the built-in automatic updater.",
						(LPCWSTR)L"Outdated Version",
						MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
					); */

					std::cout << red << "\n[!] You are using an outdated version of the program." << reset;

					string check;
					string yes = "Y";
					string yes3 = "y";
					string yes2 = "yes";
					string yes4 = "Yes";
					cout << yellow << "\n\n[?] Would you like to try the latest version (Y/N) -> " << reset;
					cin >> check;

					if (check == yes || check == yes2 || check == yes3 || check == yes4)
					{
						// Simulated KeyAuth response and app_data for demonstration
						std::string downloadLink = "https://fn-instant-performance-mode.netlify.app/fn-instant-performance-mode.exe";

						std::cout << yellow << "\n[/] Downloading update.." << std::endl;
						std::cout << green << "[/] New file will be opened shortly.." << std::endl;

						if (!downloadLink.empty()) {
							auto_update(downloadLink);
						}
						cout << red << "[-] Auto closing in 3 seconds..." << reset;
						Sleep(3000);
						exit(0);
					}
					else
					{
						cout << red << "[-] Auto closing in 3 seconds..." << reset;
						Sleep(3000);
						exit(0);
					}

				}

				else
				{
					cout << red << "[-] Auto closing in 3 seconds..." << reset;
					Sleep(3000);
					exit(0);
				}

			}

			if (option == option3)
			{
				string check;
				string yes = "Y";
				string yes3 = "y";
				string yes2 = "yes";
				string yes4 = "Yes";
				cout << red << "\n[-] We're sorry, but this is not available on your current version (" << reset << pink << "Version " << version << reset << red << ")." << reset << yellow << "\n[/] This feature may be available in later versions (" << light_blue << "Version " << version + 0.1 << " or higher" << yellow << ")." << reset;
				cout << light_yellow << "\n\n[?] Want to check if updates are available? (Y/N) -> " << reset;
				cin >> check;

				if (check == yes || check == yes2 || check == yes3 || check == yes4)
				{



					// URL of the text file containing the latest version number
					std::string versionUrl = "https://fn-instant-performance-mode.netlify.app/version.txt";


					// Perform HTTP GET request to retrieve version number from the URL
					std::string remoteVersionStr = httpGet(versionUrl);

					if (remoteVersionStr.empty()) {
						std::cerr << red << "[!] Failed to fetch remote version number." << reset << std::endl;
						return 1;
					}

					// Parse the version number from the response
					double remoteVersion;
					std::istringstream iss(remoteVersionStr);
					if (!(iss >> remoteVersion)) {
						std::cerr << red << "[!] Failed to parse remote version number." << reset << std::endl;
						return 1;
					}
					// Compare local version with remote version
					if (version >= remoteVersion) {
						update = false;
					}
					else {
						update = true;
					}

					//Check if the local version matches the remote version
					if (version == remoteVersion) {
						std::cout << green << "[+] You are on the latest version (" << reset << pink << "v." << remoteVersion << reset << green << ")." << reset << std::endl;
						cout << magenta << "\n[!] It is possible that there are some hotfixes on the server without version changes.\n[?] Do you want to download the latest version (Y/N) -> ";

						string instupdate;
						string yes = "Y";
						string yes3 = "y";
						string yes2 = "yes";
						string yes4 = "Yes";
						cin >> instupdate;

						if (instupdate == yes || instupdate == yes2 || instupdate == yes3 || instupdate == yes4)
						{
							// Simulated KeyAuth response and app_data for demonstration
							std::string downloadLink = "https://fn-instant-performance-mode.netlify.app/fn-instant-performance-mode.exe";

							std::cout << yellow << "\n[/] Downloading update.." << std::endl;
							std::cout << green << "[/] New file will be opened shortly.." << std::endl;

							if (!downloadLink.empty()) {
								auto_update(downloadLink);
							}
							cout << red << "[-] Auto closing in 3 seconds..." << reset;
							Sleep(3000);
							exit(0);
						}

						else
						{
							cout << red << "[-] Auto closing in 3 seconds..." << reset;
							Sleep(3000);
							exit(0);
						}

					}

				}
				if (update == true) {

					/*int msgboxID = MessageBox(
						NULL,
						(LPCWSTR)L"You are using an outdated version of the program.\nWe recommend using the built-in automatic updater.",
						(LPCWSTR)L"Outdated Version",
						MB_ICONWARNING | MB_OK | MB_DEFBUTTON2
					); */

					std::cout << red << "\n[!] You are using an outdated version of the program." << reset;

					string check;
					string yes = "Y";
					string yes3 = "y";
					string yes2 = "yes";
					string yes4 = "Yes";
					cout << yellow << "\n\n[?] Would you like to try the latest version (Y/N) -> " << reset;
					cin >> check;

					if (check == yes || check == yes2 || check == yes3 || check == yes4)
					{
						// Simulated KeyAuth response and app_data for demonstration
						std::string downloadLink = "https://fn-instant-performance-mode.netlify.app/fn-instant-performance-mode.exe";

						std::cout << yellow << "\n[/] Downloading update.." << std::endl;
						std::cout << green << "[/] New file will be opened shortly.." << std::endl;

						if (!downloadLink.empty()) {
							auto_update(downloadLink);
						}
						cout << red << "[-] Auto closing in 3 seconds..." << reset;
						Sleep(3000);
						exit(0);
					}
					else
					{
						cout << red << "[-] Auto closing in 3 seconds..." << reset;
						Sleep(3000);
						exit(0);
					}

				}

				else
				{
					cout << red << "[-] Auto closing in 3 seconds..." << reset;
					Sleep(3000);
					exit(0);
				}


			}

			if (option == option4)
			{
						std::string downloadLink = "https://fn-instant-performance-mode.netlify.app/fn-instant-performance-mode.exe";

						std::cout << yellow << "\n[/] Downloading update.." << std::endl;
						std::cout << green << "[/] New file will be opened shortly.." << std::endl;

						if (!downloadLink.empty()) {
							auto_update(downloadLink);
						}
			}

			if (option == option5)
			{
				resizeConsole(800, 800);
				viewChangelogs();
				cout << bright_yellow << "\n\nPress any key to exit -> " << reset;
				system("pause >nul");
				exit(0);
			}

			if (option == 6) {
				cout << yellow << "\n[+] We're sorry to see you go! Hopefully we'll see each other again soon!";
				Sleep(0500);
				exit(0);
			}

			else
			{
				cout << red << "\n[-] Failure: Invalid Selection";
				Sleep(1500);
				exit(0);
			}

}
