#import <Foundation/Foundation.h>

@interface Contacts: NSObject <NSCoding>
{
	NSString *firstName;
	NSString *lastName; 
	NSString *streetAddress; 
	NSString *zipCode; 
	NSString *email;
	NSString *phoneNumber;
	NSString *notes;
}

-(void) setFirstName: (NSString *) fName;
-(void) setLastName: (NSString *) lName; 
-(void) setStreetAddress: (NSString *) street; 
-(void) setZipCode: (NSString *) zip; 
-(void) setEmail: (NSString *) mail; 
-(void) setPhoneNumber: (NSString *) phone; 
-(void) setNotes: (NSString *) memo; 

-(void) encodeWithCoder: (NSCoder *) encoder;
-(id) initWithCoder: (NSCoder *) decoder;

-(NSString *) firstName;
-(NSString *) lastName;
-(NSString *) streetAddress;
-(NSString *) zipCode;
-(NSString *) email;
-(NSString *) phoneNumber;
-(NSString *) notes;

-(void) print;

@end

@implementation Contacts

- (id)init 
{
    self = [super init];
    if (self) 
    {
        firstName = [[NSString alloc] initWithString: @""];
		lastName = [[NSString alloc] initWithString: @""];
		streetAddress = [[NSString alloc] initWithString: @""];
		zipCode = [[NSString alloc] initWithString: @""];
		email = [[NSString alloc] initWithString: @""];
		phoneNumber = [[NSString alloc] initWithString: @""];
		notes = [[NSString alloc] initWithString: @""];
    }
    return self;
}

-(void) setFirstName: (NSString *) fName
{	
	firstName = fName;
}

-(void) setLastName: (NSString *) lName
{	
	lastName = lName;
}

-(void) setStreetAddress: (NSString *) street
{	
	streetAddress = street;
}

-(void) setZipCode: (NSString *) zip
{	
	zipCode = zip;
}

-(void) setEmail: (NSString *) mail
{	
	email = mail;
}

-(void) setPhoneNumber: (NSString *) phone
{	
	phoneNumber = phone;
}

-(void) setNotes: (NSString *) memo
{	
	notes = memo;
}

-(NSString *) firstName
{
	return firstName;
}

-(NSString *) lastName
{
	return lastName;
}

-(NSString *) streetAddress
{
	return streetAddress;
}
-(NSString *) zipCode
{
	return zipCode;
}
-(NSString *) email
{
	return email;
}
-(NSString *) phoneNumber
{
	return phoneNumber;
}
-(NSString *) notes
{
	return notes;
}

-(void) print
{
	NSLog (@"%@ %@", firstName, lastName);
	NSLog (@"%@, %@", streetAddress, zipCode);
	NSLog (@"%@, %@", email, phoneNumber);
	NSLog (@"%@\n\n", notes);
}

-(void) encodeWithCoder: (NSCoder *) encoder
{
	[encoder encodeObject:firstName forKey:@"ContactFirstName"]; 
	[encoder encodeObject:lastName forKey:@"ContactLastName"];
	[encoder encodeObject:streetAddress forKey:@"ContactStreetAddress"]; 
	[encoder encodeObject:zipCode forKey:@"ContactZipCode"]; 
	[encoder encodeObject:email forKey:@"ContactEmail"];
	[encoder encodeObject:phoneNumber forKey:@"ContactPhoneNumber"]; 
	[encoder encodeObject:notes forKey:@"ContactNotes"]; 	
}

-(id) initWithCoder: (NSCoder *) decoder
{
	firstName = [[decoder decodeObjectForKey:@"ContactFirstName"] retain];
	lastName = [[decoder decodeObjectForKey:@"ContactLastName"] retain];
	streetAddress = [[decoder decodeObjectForKey:@"ContactStreetAddress"] retain];
	zipCode = [[decoder decodeObjectForKey:@"ContactZipCode"] retain];
	email = [[decoder decodeObjectForKey:@"ContactEmail"] retain];
	phoneNumber = [[decoder decodeObjectForKey:@"ContactPhoneNumber"] retain];
	notes = [[decoder decodeObjectForKey:@"ContactNotes"] retain];
	
	return self;
}

@end