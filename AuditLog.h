#ifndef AUDITLOG_H
#define AUDITLOG_H

class AuditLog {

private:
	Srring logId;
	DateTime timestamp;
	String action;

public:
	void recordAccess();
};

#endif
