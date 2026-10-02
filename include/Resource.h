#ifndef RESOURCE_H // header guard
#define RESOURCE_H

#include <string>
using namespace std;


class Resource
{
	//static vector<Resource> resources;
		
	private:
		// attributes
		string resourceID;
		string resourceName;
		string resourceType;
		string availabilityStatus;
		//vector<Resource> resources;
	public:
		// default constructor
		Resource();
		// parameterized constructor
		Resource(string resourceID, string resourceName, string resourceType, string availabilityStatus);
		
		// getters/accessors
		string getResourceID() const;
		string getResourceName() const;
		string getResourceType() const;
		string getAvailabilityStatus() const;
		
		// setters/mutators
		void setResourceID(string resourceID);
		void setResourceName(string resourceName);
		void setResourceType(string resourceType);
		void setAvailabilityStatus(string availabilityStatus);
		
		// // copy constructor
		// Resource(const Resource& obj);
		
		// // copy assignment
		// Resource& operator=(const Resource& obj);
};
//extern vector<Resource> resources;

#endif