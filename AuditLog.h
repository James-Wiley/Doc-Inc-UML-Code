#ifndef AUDITLOG_H
#define AUDITLOG_H

#include <string>

class AuditLog {

private:
	std::string logId;
	DateTime timestamp;
	std::string action;

public:
	void recordAccess();
};

#endif
