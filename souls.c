#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/**
 * The formula for calculating soul levels above SL 15 is given by
 * y= 0.02x³ + 3.06x² + 105.6x - 895
 *
 * To calculate the award for killing a host or phantom you multiply that value by 4%. Below, I calculate both
 * the total souls required to level up for a single level, as well as the soul reward for killing a host or phantom
 * at that level. 
 */
int main(int level) {

	if (level < 15) {
		level = 15;
	}

	int maxLevel = 802;


	//printf("Looking from level %d to %d\n", level, maxLevel);

	//printf("header:\n");
	//printf("sl\t total \t 2%\n");
	for (int a = level; a <=maxLevel; a++) {


		float soulCount1 = ( (float)a * (float)a * (float)a) * 0.02 ;
		float soulCount2 = ( (float)a * (float)a ) * 3.06;
		float soulCount3 = (105.6 * (float)a) ;

		float totalSouls = soulCount1 + soulCount2 + soulCount3 - 895;


		float invasionReward = (.04 * totalSouls);
		//printf("soulCount1 = %f\n", soulCount1);
		//printf("soulCount2 = %f\n", soulCount2);
		//printf("soulCount3 = %f\n", soulCount3);

		printf("%d\t %f\t %f\t\n", a, round(totalSouls),  round(invasionReward));
	}

	return 0;

}

