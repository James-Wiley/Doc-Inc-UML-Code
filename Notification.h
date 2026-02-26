#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class Notification {

private:
	std::string notificationId;
	Date sentDate;
	std::string type;

public:
	void sendEmail();
};

#endif
