#ifndef NOTIFICATION_H
#define NOTIFICATION_H

class Notification {

private:
	String notificationId;
	Date sentDate;
	String type;

public:
	void sendEmail();
};

#endif
