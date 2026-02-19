#ifndef PREFERENCE_H
#define PREFERENCE_H

class Preference {

private:
	String deliveryMethod;
	Date effectiveDate;

public:
	void scheduleChange();
};

#endif
