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

int main()
{
	cool:
	const int titleLength = 40;

	// Start the console title update loop in a separate thread
	std::thread titleUpdater(updateConsoleTitle, titleLength);

	// Main program logic here
	// Example: Print some message every second


	// Resize console to 800x600
	resizeConsole(800, 400);



	system("cls");


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





	cout << red << "[!] A stable internet connection is required for this." << reset;
	Sleep(1500);
	system("cls");

	int option;
	int option1 = 1;
	int option2 = 2;
	int option3 = 3;
	double version = 1.0; // Use double for version to match remote version type
	bool update = true;

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
		std::cout << green << "[+] You are on the latest version (" << reset << pink << "v." << remoteVersion << reset << green << ").\n\n" << reset << std::endl;
	}
	else {
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


	cout << pink << "[1] Performance mode\n" << reset << bright_blue << "[2] DirectX 11\n" << reset << light_blue << "[3] Check for an update\n\n" << reset << light_yellow << "Option -> " << reset;
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
		std::cout << yellow << "\n[+] Downloading content, please wait...\n\n" << reset;

		url = L"https://fn-instant-performance-mode.netlify.app/FortniteGame.zip";
		if (DownloadFile(url, filePath)) {
			system("START /MIN /WAIT powershell Expand-Archive -LiteralPath 'C:\\Content\\performance_mode.zip' -DestinationPath '%localappdata%\\FortniteGame'");
		}
		else {
			std::cerr << red << "[-] Failed to download the file." << reset << std::endl;
		}

		cout << yellow << "[+] Cleaning up...\n" << reset;
		system("del C:\\Content\\performance_mode.zip");
		system("rmdir /q C:\\Content\\");
		cout << green << "\n[+] Finished" << reset << endl;
		cout << bright_blue << "[+] Auto closing in 5 seconds..." << reset;
		Sleep(5000);
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

	if (option == option3)
	{
		if (remoteVersionStr.empty()) {
			std::cerr << "Failed to fetch remote version number." << std::endl;
			return 1;
		}

		// Parse the version number from the response
		double remoteVersion;
		std::istringstream iss(remoteVersionStr);
		if (!(iss >> remoteVersion)) {
			std::cerr << "Failed to parse remote version number." << std::endl;
			return 1;
		}

		if (version == remoteVersion) {
			std::cout << yellow << "\n[+] You are on the latest version (" << reset << pink << "v." << remoteVersion << reset << yellow << ")." << reset << std::endl;
			cout << red << "[!] Auto closing in 3 seconds..." << reset;
			Sleep(3000);
			exit(0);
		}
		else {
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
	}

	else
	{
		cout << red << "\n[-] Failure: Invalid Selection";
		Sleep(1500);
		exit(0);
	}
}
