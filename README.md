# fn-instant-performance-mode
A Fortnite C++ tool that allows the user to use Performance Mode/DirectX 11 instead of DirectX12 when launching Fortnite for the first time. This also skips the annoying trailers

# Explanation 
- Uses a randomly generated console title that changes every 0.25 seconds
- Has a built-in automatic updater that checks the version built into the software and then compares it with the version from the server (version.txt, use e.g. [netlify.app](https://www.netlify.com/) as a free hosting service)
- Gives the user the ability to choose between Performance Mode and DirectX 11. Selecting one of these options will create a temporary folder on your C drive and download a ZIP file to that location, which will be extracted to %localappdata% (the game reads the graphics settings from \FortniteGame).
- after that it delets all temporary files/ folders
