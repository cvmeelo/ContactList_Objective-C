#import "Contacts.h"

@interface ContactList: NSObject <NSCoding>
{
	NSMutableArray *list;
}
-(id) init;
-(void) addContact;
-(void) printContact: (NSString *)type: (NSString *)value;
-(void) printAll;
-(void) loadContacts;
-(void) saveContacts;

-(void) encodeWithCoder: (NSCoder *) encoder;
-(id) initWithCoder: (NSCoder *) decoder;

@end

@implementation ContactList

- (id)init 
{
    self = [super init];
    if (self) 
    {
        list = [[NSMutableArray alloc]initWithObjects: nil];
    }
    return self;
}

-(void) addContact
{
	
	//NSLog(@"List Count is: %i", [list count]);

	Contacts *contactTemp = [[Contacts alloc] init];
	char cFName[80], cLName[80], cSAddress[80], cZCode[80], cEmail[80], cPNumber[80], cNotes[80];
	NSString *fName;
	NSString *lName;
	NSString *sAddress;
	NSString *zCode;
	NSString *mail;
	NSString *pNumber;
	NSString *memo;
	
	NSLog(@"Enter First Name: ");
	scanf("%s", &cFName);
	NSLog(@"Enter Last Name: ");
	scanf("%s", &cLName);
	NSLog(@"Enter Street Address: ");
	scanf("%s", &cSAddress);
	NSLog(@"Enter Zip Code: ");
	scanf("%s", &cZCode);
	NSLog(@"Enter Email: ");
	scanf("%s", &cEmail);
	NSLog(@"Enter Phone Number: ");
	scanf("%s", &cPNumber);
	NSLog(@"Enter Notes: ");
	scanf("%s", &cNotes);
	
	fName = [NSString stringWithCString: cFName encoding: NSASCIIStringEncoding];
	lName = [NSString stringWithCString: cLName encoding: NSASCIIStringEncoding];
	sAddress = [NSString stringWithCString: cSAddress encoding: NSASCIIStringEncoding];
	zCode = [NSString stringWithCString: cZCode encoding: NSASCIIStringEncoding];
	mail = [NSString stringWithCString: cEmail encoding: NSASCIIStringEncoding];
	pNumber = [NSString stringWithCString: cPNumber encoding: NSASCIIStringEncoding];
	memo = [NSString stringWithCString: cNotes encoding: NSASCIIStringEncoding];
	
	[contactTemp setFirstName: fName];
	[contactTemp setLastName: lName]; 
	[contactTemp setStreetAddress: sAddress]; 	
	[contactTemp setZipCode: zCode]; 
	[contactTemp setEmail: mail]; 
	[contactTemp setPhoneNumber: pNumber]; 
	[contactTemp setNotes: memo]; 
	
	[list addObject:contactTemp]; 
	
	NSLog(@"List Count is: %i", [list count]);
}

-(void) printContact: (NSString *)type: (NSString *)value
{
	int i;
	NSString * cmpStr;
	for( i = 0; i < [list count]; i++ )
	{	
		Contacts *contactTemp = [[Contacts alloc] init];
		contactTemp = [list objectAtIndex: i];

		if( type == @"last" )
		{
			cmpStr = [contactTemp lastName]; 
			if( [cmpStr caseInsensitiveCompare: value] == NSOrderedSame )
			{
				[contactTemp print];
			}
		} else if( type == @"email" )
		{
			cmpStr = [contactTemp email]; 
			if( [cmpStr caseInsensitiveCompare: value] == NSOrderedSame )
			{
				[contactTemp print];
			}
		} else if( type == @"zip" )
		{
			cmpStr = [contactTemp zipCode]; 
			if( [cmpStr caseInsensitiveCompare: value] == NSOrderedSame )
			{
				[contactTemp print];
			}
		}
	}
}

-(void) printAll
{
	int i;
	
	for(  i = 0; i < [list count]; i++ )
	{
		Contacts *contactTemp = [[Contacts alloc] init];
		contactTemp = [list objectAtIndex: i];
		[contactTemp print];
			
	}
}

-(void) encodeWithCoder: (NSCoder *) encoder
{
	[encoder encodeObject:list forKey:@"ContactListList"];
}
-(id) initWithCoder: (NSCoder *) decoder
{
	list = [[decoder decodeObjectForKey:@"ContactListList"] retain];
	return self;
}

-(void) loadContacts
{
	NSFileManager *manager = [NSFileManager defaultManager];
	if( [manager fileExistsAtPath:@"contactList.dat"] )
		list = [NSKeyedUnarchiver unarchiveObjectWithFile:@"contactList.dat"];
}

-(void) saveContacts
{
	if( [NSKeyedArchiver archiveRootObject:list toFile:@"contactList.dat"] == NO)
		NSLog(@"Archiving Failed");
}


@end