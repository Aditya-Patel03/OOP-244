#ifndef SDDS_FIGHTER_H
#define SDDS_FIGHTER_H
namespace sdds {
	const int MAX_NAME = 50;

	struct Fighter {
		char name[MAX_NAME+1];
		int power;
	};

	struct Competition {
		Fighter* fighters;
		int numfighters;
	};

	//TODO: Declare the prototypes for the functions required as per the lab instructions

}
#endif /* FIGHTER_H */



