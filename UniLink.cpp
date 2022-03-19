#include "UniLink.h"
UniLink::UniLink()
{
	ptr = nullptr;
	NoPosts = 0;
	

}
void UniLink::MenuPrint() {
	cout << "\n1. New event Post";
	cout << "\n2. New Sale Post";
	cout << "\n3. New Job Post";
	cout << "\n4. Reply to Post";
	cout << "\n5. Display My Posts";
	cout << "\n6. Display All Posts";
	cout << "\n7. Close Post";
	cout << "\n8. Delete Post";
	cout << "\n9. Log Out";
}
void UniLink::Regrow()
{
	if (NoPosts == 0)
	{
		ptr = new Post * [++NoPosts];
	}
	else
	{
		Post** temp = new Post * [NoPosts];
		temp = ptr;
		ptr = new Post * [++NoPosts];
		for (int i = 0;i < NoPosts - 1;i++)
			ptr[i] = temp[i];
	}
		

}
void UniLink::Menu() {
	int choice;
	cout << "**Unilink System **\n";
	cout << "\n1. Log in \n2. Quit";
	cout << "\nEnter your choice: ";
	cin >> choice;
	//if (choice == 1)
	//{
	//	//variable names
	//	string user,name,des,venue,date;
	//	int cap;
	//	double ap, mr;
	//	cout << "\nEnter username : ";
	//	cin >> user;
	//	do {
	//		cout << "** Student Menu **\n";
	//		MenuPrint();
	//		cin >> choice;
	//		switch (choice)
	//		{
	//		case 1:
	//			Regrow();
	//			cout << "\nEnter details of Event Below";
	//			cout << "\nName: ";
	//			cin >> name;
	//			cout << "\nDescription: ";
	//			cin >> des;
	//			cout << "\n Venue: ";
	//			cin >> venue;
	//			cout << "\nDate:";
	//			cin >> date;
	//			cout << "\nCapacity: ";
	//			cin >> cap;
	//			ptr[NoPosts - 1] = new Event(name,des,user,venue,date,cap);
	//			cout << "\nSucess: Your Event has been created with id " <<
	//				ptr[NoPosts - 1]->getiD();
	//			break;
	//		case 2:
	//			Regrow();
	//			cout << "\nEnter details of item to sale Below";
	//			cout << "\nName: ";
	//			cin >> name;
	//			cout << "\nDescription: ";
	//			cin >> des;
	//			cout << "\n Asking Price: ";
	//			cin >> ap;
	//			cout << "\nMin Raise: ";
	//			cin >> mr;
	//			ptr[NoPosts - 1] = new Sale(name, des, user, ap, mr);
	//			cout << "\nSucess: Your Event has been created with id " <<
	//				ptr[NoPosts - 1]->getiD();
	//			break;
	//		case 3:

	//			default:
	//				break;
	//		}//switch ends

	//	} while (choice != 9);
	//	

	//}//main if ends

}