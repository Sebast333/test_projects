
#include <iostream>
#include <syslog.h>
#include <fstream>


int main(){

	int counter = 0;

	//creating log file
	ofstream logs ("log_file.txt");
	
	// Opens the file where the system logs are
	int syslogFile = open("/var/log/syslog", O_RDONLY);

	char buffer[4096];
	
	while (read(syslogfile, buffer, size of(buffer)) > 0) {
		cout << buffer << endl;
	}

	close(syslogfile);

	return 0;
}
