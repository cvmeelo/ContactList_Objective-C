#import "ContactList.h"
#import <Foundation/Foundation.h>

int main( int argc, const char *argv[] )
{
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
		
	ContactList *contacts = [[ContactList alloc] init];
	[contacts loadContacts];
	bool exit = NO;
	int option = 0;
	
	NSLog(@"Welcome to the Contact List App");
	
	do 
	{	
		NSLog(@"Please choose from the following options: ");
		NSLog(@"1 to Add a Contact");
		NSLog(@"2 to Print a Full List");
		NSLog(@"3 to Search for a Last Name");
		NSLog(@"4 to Search for an Email");
		NSLog(@"5 to Search for a Zip Code");
		NSLog(@"6 to Save & Exit");
		
		option = 0;

		do 
		{
			NSLog(@"What would you like to do? ");
			scanf("%i", &option);
			
		} while( option < 1 || option > 6 );
		
	char cTemp[80];
	NSString *temp;

	switch ( option )
	{
		case 1: 
			[contacts addContact];
			break;
		case 2: 
			[contacts printAll];
			break;
		case 3: 
			NSLog(@"Enter Last Name: ");
			scanf("%s", &cTemp);
			temp = [NSString stringWithCString: cTemp encoding: NSASCIIStringEncoding];
			[contacts printContact: @"last": temp];
			temp = @"";
			break;
		case 4:
			NSLog(@"Enter Email: ");
			scanf("%s", &cTemp);
			temp = [NSString stringWithCString: cTemp encoding: NSASCIIStringEncoding];
			[contacts printContact: @"email": temp];
			temp = @"";
			break;
		case 5: 
			NSLog(@"Enter Zip Code: ");
			scanf("%s", &cTemp);
			temp = [NSString stringWithCString: cTemp encoding: NSASCIIStringEncoding];
			[contacts printContact: @"zip": temp];
			temp = @"";
			break;
		case 6: 
			[contacts saveContacts];
			exit = YES;
			break;			
	}	
		
	} while( exit == NO );
	
	[contacts release];
	[pool drain];

	return 0;
}
	