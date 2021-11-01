#include <fineftp/server.h>
#include <thread>
 
int main() {
  // Create an FTP Server on port 2121. We use 2121 instead of the default port
  // 21, as your application would need root privileges to open port 21.
  fineftp::FtpServer ftp_server(2121);
 
  // Add the well known anonymous user. Clients can log in using username
  // "anonymous" or "ftp" with any password. The user will be able to access
  // your C:\ drive and upload, download, create or delete files. On Linux just
  // replace "C:\\" with any valid path. FineFTP is designed to be cross-platform.
  ftp_server.addUserAnonymous("C:\\", fineftp::Permission::All);
  
  // Start the FTP Server with a thread-pool size of 4.
  ftp_server.start(4);
 
  // Prevent the application from exiting immediately
  for (;;) std::this_thread::sleep_for(std::chrono::milliseconds(100));
  return 0;
}
