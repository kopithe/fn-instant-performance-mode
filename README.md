# fn-instant-performance-mode
![Screenshot 2024-06-15 012812](https://github.com/kopithe/fn-instant-performance-mode/assets/166122699/b764d806-f82f-4e6f-af35-95abb30c94dd)

A Fortnite C++ tool that allows the user to use Performance Mode/DirectX 11 instead of DirectX12 when launching Fortnite for the first time. This also skips the annoying trailers

# Explanation 
- Uses a randomly generated console title that changes every 0.25 seconds
- Has a built-in automatic updater that checks the version built into the software and then compares it with the version from the server (version.txt, use e.g. [netlify.app](https://www.netlify.com/) as a free hosting service)
- Gives the user the ability to choose between Performance Mode and DirectX 11. Selecting one of these options will create a temporary folder on your C drive and download a ZIP file to that location, which will be extracted to %localappdata% (the game reads the graphics settings from \FortniteGame).
- after that it delets all temporary files/ folders

# Auto Updater
- It checks the version of a text document on a server (by using an HTTP GET request to get the version number from the URL) with the integrated document. If the version does not match, the user is notified
- If the version does not match and the user wants to download the file, the file will be downloaded and run from the path where the user ran the old, outdated file and then the old file will be deleted
  
![Screenshot 2024-06-15 013516](https://github.com/kopithe/fn-instant-performance-mode/assets/166122699/68ee292e-a705-4d8c-9cca-da7a9dc0857f)
