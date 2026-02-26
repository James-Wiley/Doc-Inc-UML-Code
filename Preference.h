#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <string>

class Preference {

private:
	std::string deliveryMethod;
	Date effectiveDate;

public:
	void scheduleChange();
};

#endif
