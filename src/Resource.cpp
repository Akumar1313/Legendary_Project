#include "Resource.h"
//#include <vector>
using namespace std;

//vector<Resource> resources;
// default constructor
Resource::Resource()
{
	resourceID = "";
	resourceName = "";
	resourceType = "";
	availabilityStatus = "";
}


// parameterized constructor
Resource::Resource(string resourceID, string resourceName, string resourceType, string availabilityStatus)
{
	this->resourceID = resourceID;
	this->resourceName = resourceName;
	this->resourceType = resourceType;
	this->availabilityStatus = availabilityStatus;
}

// accessors (getters)
string Resource::getResourceID() const
{
	return resourceID;
}

string Resource::getResourceName() const
{
	return resourceName;
}

string Resource::getResourceType() const
{
	return resourceType;
}

string Resource::getAvailabilityStatus() const
{
	return availabilityStatus;
}



// mutators (setters)
void Resource::setResourceID(string resourceID)
{
	this->resourceID = resourceID;
}

void Resource::setResourceName(string resourceName)
{
	this->resourceName = resourceName;
}

void Resource::setResourceType(string resourceType)
{
	this->resourceType = resourceType;
}

void Resource::setAvailabilityStatus(string availabilityStatus)
{
	this->availabilityStatus = availabilityStatus;
}